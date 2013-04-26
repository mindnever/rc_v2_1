/* Name: oddebug.c
 * Project: AVR library
 * Author: Christian Starkjohann
 * Creation Date: 2005-01-16
 * Tabsize: 4
 * Copyright: (c) 2005 by OBJECTIVE DEVELOPMENT Software GmbH
 * License: GNU GPL v2 (see License.txt), GNU GPL v3 or proprietary (CommercialLicense.txt)
 */

#ifdef __AVR__
#include <util/delay.h> 
#else
#include <stdio.h>
#endif

#include "oddebug.h"



#if DEBUG_LEVEL > 0

#warning "Never compile production devices with debugging enabled"

void odHexDump( const char *prefix, const uint8_t *data, uint8_t len )
{
  odPrintf( "%s:", prefix );

  while( len-- > 0 )
  {
    odPrintf( " %02X", *data++ );
  }
  
  odPrintf( "\n" );
}

#ifdef __AVR__
void odPutCh(uchar c)
{
    if(c == '\r')
    {
      return;
    }

    if(c == '\n')
    {
      while(!(ODDBG_USR & (1 << ODDBG_UDRE)));    /* wait for data register empty */
      ODDBG_UDR = '\r';
    }
    
    while(!(ODDBG_USR & (1 << ODDBG_UDRE)));    /* wait for data register empty */
    ODDBG_UDR = c;

}

#if 0
void odPutCh(uchar txData)
{
     //txData = ~txData; 
     UART_SOFT_PORT &= ~(1<<UART_SOFT_PIN); 

     for (char i=0; i<8; i++) 
     { 
       _delay_us(UART_SOFT_DELAY_US); 

       if( txData & 1 ) 
            UART_SOFT_PORT |= (1<<UART_SOFT_PIN); 
       else 
            UART_SOFT_PORT &= ~(1<<UART_SOFT_PIN); 

       txData >>= 1; 
    } 
   _delay_us(UART_SOFT_DELAY_US); 
   UART_SOFT_PORT |= (1<<UART_SOFT_PIN); 
   _delay_us(UART_SOFT_DELAY_US); 

}
#endif

#else

void odPutCh(uchar txData)
{
  fputc( txData, stdout );
}

#endif


static uchar    hexAscii(uchar h)
{
    h &= 0xf;
    if(h >= 10)
        h += 'a' - (uchar)10 - '0';
    h += '0';
    return h;
}

static void printHex(uchar c)
{
    odPutCh(hexAscii(c >> 4));
    odPutCh(hexAscii(c));
}

void    odDebug(uchar prefix, uchar *data, uchar len)
{
    printHex(prefix);
    odPutCh(':');
    while(len--){
        odPutCh(' ');
        printHex(*data++);
    }
    odPutCh('\r');
    odPutCh('\n');
}

#include <stdarg.h>

static void printchar(char **str, int c)
{
	if (str) {
		**str = c;
		++(*str);
	}
	else 
	{
		odPutCh(c);
	}
}

#define PAD_RIGHT 1
#define PAD_ZERO 2

static int prints(char **out, const char *string, int width, int pad)
{
	register int pc = 0, padchar = ' ';

	if (width > 0) {
		register int len = 0;
		register const char *ptr;
		for (ptr = string; *ptr; ++ptr) ++len;
		if (len >= width) width = 0;
		else width -= len;
		if (pad & PAD_ZERO) padchar = '0';
	}
	if (!(pad & PAD_RIGHT)) {
		for ( ; width > 0; --width) {
			printchar (out, padchar);
			++pc;
		}
	}
	for ( ; *string ; ++string) {
		printchar (out, *string);
		++pc;
	}
	for ( ; width > 0; --width) {
		printchar (out, padchar);
		++pc;
	}

	return pc;
}

/* the following should be enough for 32 bit int */
#define PRINT_BUF_LEN 12

static int printi(char **out, int32_t i, int b, int sg, int width, int pad, int letbase)
{
	char print_buf[PRINT_BUF_LEN];
	register char *s;
	register int t, neg = 0, pc = 0;
	register uint32_t u = i;

	if (i == 0) {
		print_buf[0] = '0';
		print_buf[1] = '\0';
		return prints (out, print_buf, width, pad);
	}

	if (sg && b == 10 && i < 0) {
		neg = 1;
		u = -i;
	}

	s = print_buf + PRINT_BUF_LEN-1;
	*s = '\0';

	while (u) {
		t = u % b;
		if( t >= 10 )
			t += letbase - '0' - 10;
		*--s = t + '0';
		u /= b;
	}

	if (neg) {
		if( width && (pad & PAD_ZERO) ) {
			printchar (out, '-');
			++pc;
			--width;
		}
		else {
			*--s = '-';
		}
	}

	return pc + prints (out, s, width, pad);
}

static int print(char **out, const char *format, va_list args )
{
	register int width, pad;
	register int pc = 0;
	register uint32_t v;
	char scr[2];

	for (; *format != 0; ++format) {
		if (*format == '%') {
			++format;
			width = pad = 0;
			if (*format == '\0') break;
			if (*format == '%') goto out;
			if (*format == '-') {
				++format;
				pad = PAD_RIGHT;
			}
			while (*format == '0') {
				++format;
				pad |= PAD_ZERO;
			}
			for ( ; *format >= '0' && *format <= '9'; ++format) {
				width *= 10;
				width += *format - '0';
			}
			if( *format == 's' ) {
				register char *s = (char *)va_arg( args, char * );
				pc += prints (out, s?s:"(null)", width, pad);
				continue;
			}
			if( *format == 'l' ) {
			  ++format;
			  v = va_arg( args, uint32_t );
			} else {
			  v = va_arg( args, int );
			}
			
			if( *format == 'd' ) {
				pc += printi (out, v, 10, 1, width, pad, 'a');
				continue;
			}
			if( *format == 'x' ) {
				pc += printi (out, v, 16, 0, width, pad, 'a');
				continue;
			}
			if( *format == 'X' ) {
				pc += printi (out, v, 16, 0, width, pad, 'A');
				continue;
			}
			if( *format == 'u' ) {
				pc += printi (out, v, 10, 0, width, pad, 'a');
				continue;
			}
			if( *format == 'c' ) {
				/* char are converted to int then pushed on the stack */
				scr[0] = (char) v;
				scr[1] = '\0';
				pc += prints (out, scr, width, pad);
				continue;
			}
		}
		else {
		out:
			printchar (out, *format);
			++pc;
		}
	}
	if (out) **out = '\0';
	va_end( args );
	return pc;
}

void odPrintf(const char *fmt, ...)
{
  va_list ap;
  va_start(ap,fmt);
  
  print(0, fmt, ap);
  
  va_end(ap);
}

#endif
