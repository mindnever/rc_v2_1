#include <drivers/hwdep.h>

#include <drivers/lc7981hw.h>

#include <gfx/gfx.h>

#include <stdio.h>

#define WINDOW_STACK_SIZE 16

static pixcoord_t virtualWidth;
static pixcoord_t virtualHeight;
static pixcoord_t physicalWidth;
static pixcoord_t physicalHeight;
static unsigned char bytesPerLine;

static struct {
    pixcoord_t x, y;
  } windowStack[WINDOW_STACK_SIZE];

static uint8_t windowStackTop;

void gfx_Init(pixcoord_t phyW, pixcoord_t phyH, pixcoord_t virtualW, pixcoord_t virtualH, unsigned short ramSize)
{
  lc7981hw_init(phyW, phyH, ramSize);

  lc7981Cmd(LC7981_MODE_CONTROL, 0x32); // graphics mode, display ON, master mode

//  lc7981Cmd(LC7981_MODE_CONTROL, 0x12); // graphics mode, display OFF, master mode
  
  physicalWidth = phyW;
  physicalHeight = phyH;
  
  virtualWidth = virtualW;
  virtualHeight = virtualH;
  
  bytesPerLine = (virtualWidth / 8);

  virtualWidth = (bytesPerLine * 8);

  lc7981Cmd(LC7981_NUMCHARS, bytesPerLine - 1);
  lc7981Cmd(LC7981_CHARACTER_PITCH, 7); // 8 bits
  lc7981Cmd(LC7981_DISPLAY_DUTY, 80);
  
  gfx_SetVisibleWindow(0,0);
  gfx_SetActiveWindow(0,0);
  
}

void gfx_SetVisibleWindow(pixcoord_t x, pixcoord_t y)
{
  if((x + physicalWidth) > virtualWidth)
    x = virtualWidth - physicalWidth;
  
  unsigned short addr = (y * bytesPerLine) + (x / 8);
  
  lc7981Cmd(LC7981_DISPLAY_ADDRESS_LO, addr & 0xff);
  lc7981Cmd(LC7981_DISPLAY_ADDRESS_HI, addr >> 8);
}

void gfx_PushActiveWindow(pixcoord_t deltax, pixcoord_t deltay)
{
  if(windowStackTop < (WINDOW_STACK_SIZE - 1)) {
      deltax += windowStack[windowStackTop].x;
      deltay += windowStack[windowStackTop].y;
      
      ++windowStackTop;
      
    }

  windowStack[windowStackTop].x = deltax;
  windowStack[windowStackTop].y = deltay;
}

void gfx_PopActiveWindow()
{
  if(windowStackTop > 0)
    --windowStackTop;
}

void gfx_SetActiveWindow(pixcoord_t x, pixcoord_t y)
{
  if((x + physicalWidth) > virtualWidth)
    x = virtualWidth - physicalWidth;
  
  windowStack[windowStackTop].x = x;
  windowStack[windowStackTop].y = y;
}


void gfx_SetPixel(pixcoord_t x, pixcoord_t y)
{
  // direct approach
  x += windowStack[windowStackTop].x;
  y += windowStack[windowStackTop].y;

  if(x >= virtualWidth || y >= virtualHeight)
    return;
    
  unsigned short addr = (y * bytesPerLine) + (x / 8);
  
  lc7981Cmd(LC7981_CURSOR_ADDRESS_LO, addr & 0xff);
  lc7981Cmd(LC7981_CURSOR_ADDRESS_HI, addr >> 8);
  
  lc7981Cmd(LC7981_BIT_SET, (x % 8));
}

void gfx_ClearPixel(pixcoord_t x, pixcoord_t y)
{
  // direct approach
  x += windowStack[windowStackTop].x;
  y += windowStack[windowStackTop].y;

  if(x >= virtualWidth || y >= virtualHeight)
    return;

  unsigned short addr = (y * bytesPerLine) + (x / 8);
  
  lc7981Cmd(LC7981_CURSOR_ADDRESS_LO, addr & 0xff);
  lc7981Cmd(LC7981_CURSOR_ADDRESS_HI, addr >> 8);
  
  lc7981Cmd(LC7981_BIT_CLEAR, (x % 8));
}

void gfx_HorizontalLine(pixcoord_t x, pixcoord_t y, pixcoord_t len)
{
  gfx_RectFill(x, y, len, 1, 0xff);
}

void gfx_VerticalLine(pixcoord_t x, pixcoord_t y, pixcoord_t len)
{
  while(len-- > 0) {
      gfx_SetPixel(x, y);
      ++y;
    }
}

void gfx_Line(pixcoord_t x1, pixcoord_t y1, pixcoord_t x2, pixcoord_t y2)
{
  unsigned char tmpX, tmpY, x, y; 

  if(x2 < x1) {
      tmpX = x1; 
      tmpY = y1; 
      x1 = x2; 
      y1 = y2; 
      x2 = tmpX; 
      y2 = tmpY;  
    } 

  if(x1 == x2) { // vertical line

      for(y = y1; y <= y2; y++) { 
          gfx_SetPixel(x1, y); 
        }

    } else if(y1 == y2) {

      gfx_HorizontalLine(x1, y1, x2 - x1);

    } else { 

      for(x = x1; x <= x2; x++) {
          if(y1>=y2){ 
              y = y1 - (x-x1) * (y1-y2)/(x2-x1); 
            } else { 
              y = y1 + (x-x1) * (y2-y1)/(x2-x1); 
            } 
          gfx_SetPixel(x, y); 
        }
    }
}

typedef struct {
    const unsigned char *dptr_P;
    unsigned char inverse;
    unsigned char compressed;
    unsigned char ccount;
  } BitMapFile;

unsigned char bitmap_getData(BitMapFile *f)
{
  unsigned char ret = 0;
  
  if(f->compressed) {

      if(f->ccount) {
          f->ccount--;
          return 0;
        }

      ret = pgm_read_byte(f->dptr_P++);

      if(ret == 0) {
          f->ccount = pgm_read_byte(f->dptr_P++) - 1;
        }

    } else {
      ret = pgm_read_byte(f->dptr_P++);
      if(f->inverse)
        ret = ~ret;
    }

  return ret;
}

void gfx_BltBitMap(pixcoord_t x, pixcoord_t y, BitMap *bm)
{
  x += windowStack[windowStackTop].x;
  y += windowStack[windowStackTop].y;

  unsigned char xmod = x % 8;
  unsigned char firstByteMask = (uint8_t) ~((uint8_t) 0xff << xmod);
  unsigned short addr = (x / 8) + (y * bytesPerLine);
  
  BitMapFile f;

  f.dptr_P = bm->data_P;
  f.inverse = bm->inverse;
  f.compressed = bm->compressed;
  f.ccount = 0;

  xmod += bm->w;

  unsigned char numBytes = xmod / 8;

  xmod = xmod % 8;
  
  unsigned char lastByteMask = 0xff << xmod;
  
  unsigned char numSourceBytesPerRow = ((bm->w - 1) / 8) + 1;
  unsigned char i;

  if(numBytes == 0) {
      lastByteMask |= firstByteMask;
      firstByteMask = lastByteMask;
    }

  xmod = x % 8;
  unsigned char rxmod = 8 - xmod;
  
//  printf("x = %d, xmod = %d, rxmod = %d, firstByteMask = 0x%02x, lastByteMask = 0x%02x\n", x, xmod, rxmod, firstByteMask, lastByteMask);
  
  
//  firstByteMask = 0;
//  lastByteMask = 0;
  
  for(i = 0; i < bm->h; ++i) {
//printf("line %d addr = %d\n", i, addr);
      lc7981Cmd(LC7981_CURSOR_ADDRESS_LO, addr & 0xff);
      lc7981Cmd(LC7981_CURSOR_ADDRESS_HI, addr >> 8);
      lc7981Cmd(LC7981_READ_DISPLAY_DATA, 0); // dummy read

      unsigned char firstByte = lc7981Cmd(LC7981_READ_DISPLAY_DATA, 0) & firstByteMask;
      unsigned char lastByte = 0;

      if(numBytes > 0) {
          if(numBytes > 1) {
              unsigned short addr2 = addr + numBytes;
              lc7981Cmd(LC7981_CURSOR_ADDRESS_LO, addr2 & 0xff);
              lc7981Cmd(LC7981_CURSOR_ADDRESS_HI, addr2 >> 8);
              lc7981Cmd(LC7981_READ_DISPLAY_DATA, 0); // dummy read
            }
          
          lastByte = lc7981Cmd(LC7981_READ_DISPLAY_DATA, 0) & lastByteMask;
        }

      lc7981Cmd(LC7981_CURSOR_ADDRESS_LO, addr & 0xff);
      lc7981Cmd(LC7981_CURSOR_ADDRESS_HI, addr >> 8);
      
      
      unsigned char nsbpr = numSourceBytesPerRow;
      
      unsigned char data = bitmap_getData(&f); // DATA_OP(pgm_read_byte(dptr_P++));
      unsigned char hi = data >> rxmod;
      data <<= xmod;
      
      lc7981Cmd(LC7981_WRITE_DISPLAY_DATA, (data & ~firstByteMask) | firstByte);
      nsbpr--;
      
      if(numBytes > 0) {
          unsigned char k;
 
          for(k = 1; k < numBytes; ++k) {
              data = bitmap_getData(&f); // DATA_OP(pgm_read_byte(dptr_P++));
              unsigned char nhi = data >> rxmod;
              data = (data << xmod) | hi;

              
              lc7981Cmd(LC7981_WRITE_DISPLAY_DATA, data);
              hi = nhi;

              nsbpr--;
            }
          
          if(nsbpr)
            data = bitmap_getData(&f); // DATA_OP(pgm_read_byte(dptr_P++));
          else
            data = 0;
          
          data = (data << xmod) | hi;
          
          lc7981Cmd(LC7981_WRITE_DISPLAY_DATA, ((data & ~lastByteMask) | lastByte));
        }

      addr += bytesPerLine;
    }
}

void gfx_RectFill(pixcoord_t x, pixcoord_t y, pixcoord_t w, pixcoord_t h, unsigned char data)
{
  x += windowStack[windowStackTop].x;
  y += windowStack[windowStackTop].y;
  
  unsigned char xmod = x % 8;
  unsigned char firstByteMask = ~(0xff << xmod);
  unsigned short addr = (x / 8) + (y * bytesPerLine);

  xmod += w;

  unsigned char numBytes = xmod / 8;

  xmod = xmod % 8;
  
  unsigned char lastByteMask = 0xff << xmod;
  
  unsigned char numSourceBytesPerRow = ((w - 1) / 8) + 1;
  unsigned char i;

  if(numBytes == 0) {
      lastByteMask |= firstByteMask;
      firstByteMask = lastByteMask;
    }

  xmod = x % 8;
//  unsigned char rxmod = 8 - xmod;
  
//  printf("x = %d, xmod = %d, rxmod = %d, firstByteMask = 0x%02x, lastByteMask = 0x%02x\n", x, xmod, rxmod, firstByteMask, lastByteMask);
  
  
//  firstByteMask = 0;
//  lastByteMask = 0;
  
  for(i = 0; i < h; ++i) {
//printf("line %d addr = %d\n", i, addr);
      lc7981Cmd(LC7981_CURSOR_ADDRESS_LO, addr & 0xff);
      lc7981Cmd(LC7981_CURSOR_ADDRESS_HI, addr >> 8);
      lc7981Cmd(LC7981_READ_DISPLAY_DATA, 0); // dummy read

      unsigned char firstByte = lc7981Cmd(LC7981_READ_DISPLAY_DATA, 0) & firstByteMask;
      unsigned char lastByte = 0;

      if(numBytes > 0) {
          if(numBytes > 1) {
              unsigned short addr2 = addr + numBytes;
              lc7981Cmd(LC7981_CURSOR_ADDRESS_LO, addr2 & 0xff);
              lc7981Cmd(LC7981_CURSOR_ADDRESS_HI, addr2 >> 8);
              lc7981Cmd(LC7981_READ_DISPLAY_DATA, 0); // dummy read
            }
          
          lastByte = lc7981Cmd(LC7981_READ_DISPLAY_DATA, 0) & lastByteMask;
        }

      lc7981Cmd(LC7981_CURSOR_ADDRESS_LO, addr & 0xff);
      lc7981Cmd(LC7981_CURSOR_ADDRESS_HI, addr >> 8);
      
      
      unsigned char nsbpr = numSourceBytesPerRow;
      
      lc7981Cmd(LC7981_WRITE_DISPLAY_DATA, ((data & ~firstByteMask) | firstByte));
      nsbpr--;
      
      if(numBytes > 0) {
          unsigned char k;
 
          for(k = 1; k < numBytes; ++k) {
              
              lc7981Cmd(LC7981_WRITE_DISPLAY_DATA, data);

              nsbpr--;
            }
          
          lc7981Cmd(LC7981_WRITE_DISPLAY_DATA, ((data & ~lastByteMask) | lastByte));
        }

      addr += bytesPerLine;
    }
}
