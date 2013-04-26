#include <stdio.h>

#ifdef __AVR__

#include <gfx/gfx.h>

#include "Font_david6.h"
#include "ra6963.h"

static pixcoord_t con_x;
static pixcoord_t con_y;

static char con_buffer[32];
static uint8_t con_size;


static void con_scrollup(uint8_t lines)
{
  char line[20];
  uint8_t i, ycounter = 81 - lines;
  uint16_t src = 20 * lines, dst = 0;
  
  pixcoord_t cy = 0;
  
  while(ycounter-- > 0)
  {

      RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, src );
      
      for(i = 0; i < 20; ++i)
      {
          line[i] = RA6963_DataReadCommand( T6963_DATA | T6963_READ | T6963_ADP_INC );
      }
    
      RA6963_AddressCommand( T6963_SET_ADDRESS_POINTER, dst );
      
      for(i = 0; i < 20; ++i)
      {
          RA6963_DataCommand(T6963_DATA | T6963_WRITE | T6963_ADP_INC, line[ i ] );
      }
      
      src += 20;
      dst += 20;

      ++cy;
  }
}


static void con_flush()
{
  con_buffer[con_size] = 0;

  con_x += gfx_DrawText(&david6, con_x, con_y, con_buffer);
  
  con_size = 0;
}


static int con_putchar(char ch)
{
  odPutCh( ch );
  
  char tmp[2];

  tmp[0] = ch;
  tmp[1] = 0;

  if(ch == '\n') {

      con_flush();
      
      con_x = 0;
      
      if(con_y < 71) {
          con_y += 9;
        } else {
          con_scrollup(9);
        }

    } else {
      
      con_buffer[con_size++] = ch;
      
      if(con_size == (sizeof(con_buffer) - 1))
        con_flush();
    }

  return 0;
}

static FILE con = FDEV_SETUP_STREAM(con_putchar, 0, _FDEV_SETUP_WRITE);

void console_init()
{
  stderr = stdout = &con;
  con_x = 0;
  con_y = 9;
}

#else /* !__AVR__ */

void console_init()
{
}


#endif
