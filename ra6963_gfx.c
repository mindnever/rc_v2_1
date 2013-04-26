#include <stdint.h>
#include <stdio.h>

#include "ra6963.h"
#include <gfx/gfx.h>

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
    RA6963_Init();

    RA6963_AddressCommand( T6963_SET_GRAPHIC_HOME_ADDRESS, 0 );
    RA6963_Command( T6963_DISPLAY_MODE | T6963_GRAPHIC_DISPLAY_ON );
    RA6963_Command( T6963_MODE_SET | T6963_MODE_OR | T6963_CG_INT );
    
    physicalWidth = phyW;
    physicalHeight = phyH;

    virtualWidth = virtualW;
    virtualHeight = virtualH;

    bytesPerLine = (virtualWidth / 8);

    virtualWidth = (bytesPerLine * 8);

    RA6963_DataCommand2( T6963_SET_GRAPHIC_AREA, bytesPerLine, 0 );

    gfx_SetVisibleWindow(0,0);
    gfx_SetActiveWindow(0,0);
}

void gfx_SetVisibleWindow(pixcoord_t x, pixcoord_t y)
{
    if((x + physicalWidth) > virtualWidth)
    {
        x = virtualWidth - physicalWidth;
    }

    unsigned short addr = (y * bytesPerLine) + (x / 8);
    RA6963_AddressCommand( T6963_SET_GRAPHIC_HOME_ADDRESS, addr );
}

void gfx_PushActiveWindow(pixcoord_t deltax, pixcoord_t deltay)
{
  if(windowStackTop < (WINDOW_STACK_SIZE - 1))
  {
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
  {
    return;
  }
    
  unsigned short addr = (y * bytesPerLine) + (x / 8);
  
  RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, addr );
  RA6963_Command( T6963_BIT_SET | (7 - (x % 8)) );
}

void gfx_ClearPixel(pixcoord_t x, pixcoord_t y)
{
  // direct approach
  x += windowStack[windowStackTop].x;
  y += windowStack[windowStackTop].y;

  if(x >= virtualWidth || y >= virtualHeight)
    return;

  unsigned short addr = (y * bytesPerLine) + (x / 8);

  RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, addr );
  
  RA6963_Command( T6963_BIT_CLEAR | (7 - (x % 8)) );
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
  unsigned char firstByteMask = (uint8_t) ~((uint8_t) 0xff >> xmod);
  unsigned short addr = (x / 8) + (y * bytesPerLine);
  
  BitMapFile f;

  f.dptr_P = bm->data_P;
  f.inverse = bm->inverse;
  f.compressed = bm->compressed;
  f.ccount = 0;

  xmod += bm->w;

  unsigned char numBytes = xmod / 8;

  xmod = xmod % 8;
  
  unsigned char lastByteMask = 0xff >> xmod;
  
  unsigned char numSourceBytesPerRow = ((bm->w - 1) / 8) + 1;
  unsigned char i;

  if(numBytes == 0) {
      lastByteMask |= firstByteMask;
      firstByteMask = lastByteMask;
    }

  xmod = x % 8;
  unsigned char rxmod = 8 - xmod; // is this correct? maybe
  
//  printf("x = %d, xmod = %d, rxmod = %d, firstByteMask = 0x%02x, lastByteMask = 0x%02x\n", x, xmod, rxmod, firstByteMask, lastByteMask);
  
  
//  firstByteMask = 0;
//  lastByteMask = 0;
  
  for(i = 0; i < bm->h; ++i)
  {
//printf("line %d addr = %d\n", i, addr);
      uint8_t lastByte = 0;
    
      if(numBytes > 0)
      {
          RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, addr + numBytes );
        
          lastByte = RA6963_DataReadCommand( T6963_DATA | T6963_READ | T6963_ADP_KEEP ) & lastByteMask;
      }
      
      RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, addr );

      // _KEEP
      uint8_t firstByte = RA6963_DataReadCommand( T6963_DATA | T6963_READ | T6963_ADP_KEEP ) & firstByteMask;
      
      RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, addr );

      unsigned char nsbpr = numSourceBytesPerRow;
      
      unsigned char data = bitmap_getData(&f); // DATA_OP(pgm_read_byte(dptr_P++));
// TODO: check shift direction
      unsigned char hi = data << rxmod;
      data >>= xmod;
      
      // _INC
      RA6963_DataCommand( T6963_DATA | T6963_WRITE | T6963_ADP_INC, (data & ~firstByteMask) | firstByte );

      nsbpr--;
      
      if(numBytes > 0)
      {
          unsigned char k;
 
          for(k = 1; k < numBytes; ++k)
          {
              data = bitmap_getData(&f); // DATA_OP(pgm_read_byte(dptr_P++));
// TODO: check shift direction
              unsigned char nhi = data << rxmod;
              data = (data >> xmod) | hi;

              // _INC
              RA6963_DataCommand( T6963_DATA | T6963_WRITE | T6963_ADP_INC, data );
              hi = nhi;

              nsbpr--;
          }
          
          if(nsbpr)
          {
            data = bitmap_getData(&f); // DATA_OP(pgm_read_byte(dptr_P++));
          }
          else
          {
            data = 0;
          }
          
          // TODO: check shift direction
          data = (data >> xmod) | hi;
          
          // _INC
          RA6963_DataCommand( T6963_DATA | T6963_WRITE | T6963_ADP_INC, ((data & ~lastByteMask) | lastByte) );
        }

      addr += bytesPerLine;
    }
}

void gfx_RectFill(pixcoord_t x, pixcoord_t y, pixcoord_t w, pixcoord_t h, unsigned char data)
{
  x += windowStack[windowStackTop].x;
  y += windowStack[windowStackTop].y;
  
  unsigned char xmod = x % 8;
  unsigned char firstByteMask = ~(0xff >> xmod);
  unsigned short addr = (x / 8) + (y * bytesPerLine);

  xmod += w;

  unsigned char numBytes = xmod / 8;

  xmod = xmod % 8;

  unsigned char lastByteMask = 0xff >> xmod;

  unsigned char numSourceBytesPerRow = ((w - 1) / 8) + 1;
  unsigned char i;

  if(numBytes == 0)
  {
      lastByteMask |= firstByteMask;
      firstByteMask = lastByteMask;
  }

//printf( "RectFill: addr: %04x\n", addr );

  for(i = 0; i < h; ++i)
  {
//printf("line %d addr = %d\n", i, addr);
      uint8_t lastByte = 0;
    
      if(numBytes > 0)
      {
          RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, addr + numBytes );
        
          lastByte = RA6963_DataReadCommand( T6963_DATA | T6963_READ | T6963_ADP_KEEP ) & lastByteMask;
      }
      
      RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, addr );

      // _KEEP
      uint8_t firstByte = RA6963_DataReadCommand( T6963_DATA | T6963_READ | T6963_ADP_KEEP ) & firstByteMask;

      unsigned char nsbpr = numSourceBytesPerRow;

      RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, addr );
      
      // _INC
      RA6963_DataCommand( T6963_DATA | T6963_WRITE | T6963_ADP_INC, ((data & ~firstByteMask) | firstByte) );
      nsbpr--;
      
      if(numBytes > 0)
      {
          unsigned char k;
 
          for(k = 1; k < numBytes; ++k)
          {
              // _INC
              RA6963_DataCommand( T6963_DATA | T6963_WRITE | T6963_ADP_INC, data );

              nsbpr--;
            }
          
          // _INC
          RA6963_DataCommand( T6963_DATA | T6963_WRITE | T6963_ADP_INC, ((data & ~lastByteMask) | lastByte) );
        }

      addr += bytesPerLine;
    }
}
