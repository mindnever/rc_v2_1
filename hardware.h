//
//  hardware.h
//  rc_v5
//
//  Created by Vladimir Zidar on 11/05/2015.
//  Copyright (c) 2015 mindnever.org. All rights reserved.
//

#ifndef rc_v5_hardware_h
#define rc_v5_hardware_h

#include <avr/io.h>

#define DBG_PORT F
#define DBG_PIN  7


#define LCD_CD_PORT F
#define LCD_CD_PIN  4

//#define LCD_CE_PORT F
//#define LCD_CE_PIN  5

#define LCD_WR_PORT F
#define LCD_WR_PIN  6

#define LCD_RD_PORT F
#define LCD_RD_PIN  5

//#define LCD_RST_PORT D
//#define LCD_RST_PIN  3

#define LCD_PWM_PORT C
#define LCD_PWM_PIN  6


#define LCD_STA0_PORT E
#define LCD_STA0_PIN  6

#define LCD_STA1_PORT B
#define LCD_STA1_PIN  1


#define LCD_PWM_START() { TCCR3A = _BV( WGM30 ) | _BV( COM3A1 ); TCCR3B = _BV( WGM32 ) | _BV( CS31 );  }  /* fast PWM, clear OC at match, prescaler_8 */
#define LCD_PWM_STOP() { TCCR3A &= ~( _BV( COM3A0 ) | _BV( COM3A1 ) ); IO_PIN_LOW( LCD_PWM ); } /* normal port operation, OC pin disconnected */
#define LCD_PWM_SET(x)  { OCR3A = x; }

#define LCD_DATA_B_MASK ( _BV( PB1 ) | _BV( PB2 ) | _BV( PB3 ) | _BV( PB4 ) | _BV( PB5 ) | _BV( PB6 ) )
#define LCD_DATA_E_MASK ( _BV( PE6 ) )
#define LCD_DATA_D_MASK ( _BV( PD7 ) )

#define LCD_DATA_DIR_IN() { \
  DDRB &= ~LCD_DATA_B_MASK ; \
  DDRE &= ~LCD_DATA_E_MASK ; /* D0 */ \
  DDRD &= ~LCD_DATA_D_MASK ; /* D7 */ \
}

#define LCD_DATA_DIR_OUT() { \
  DDRB |= LCD_DATA_B_MASK ; \
  DDRE |= LCD_DATA_E_MASK ; /* D0 */ \
  DDRD |= LCD_DATA_D_MASK ; /* D7 */ \
}

#define LCD_DATA_OUT(d) { \
  PORTB = (PORTB & ~LCD_DATA_B_MASK) | ( d & LCD_DATA_B_MASK ); \
  PORTE = (PORTE & ~LCD_DATA_E_MASK) | ( (d << 6) & LCD_DATA_E_MASK ); \
  PORTD = (PORTD & ~LCD_DATA_D_MASK) | ( d & LCD_DATA_D_MASK ); \
}

#define LCD_DATA_IN() ( ( PINB & LCD_DATA_B_MASK ) | ( ( PINE & LCD_DATA_E_MASK ) >> 6 ) | ( PIND & LCD_DATA_D_MASK ) )


/////

#define _CONCAT(a,b) a ## b
#define _CONCAT3(a,b,c) a ## b ## c

#define IO_PIN_NAME(n) _CONCAT(n, _PIN)
#define IO_PORT_NAME(n) _CONCAT(n, _PORT)

#define IO_PORT_OUT(p) _CONCAT(PORT, p)
#define IO_PORT_IN(p) _CONCAT(PIN, p)
#define IO_DDR(p)  _CONCAT(DDR, p)

#define IO_PIN_HIGH( n )  { IO_PORT_OUT( IO_PORT_NAME( n ) ) |= _BV( IO_PIN_NAME( n ) ); }

#define IO_PIN_LOW( n )   { IO_PORT_OUT( IO_PORT_NAME( n ) ) &= ~_BV( IO_PIN_NAME( n ) ); }
#define IO_PIN_READ( n ) ( IO_PORT_IN( IO_PORT_NAME( n ) ) & _BV( IO_PIN_NAME( n ) ) )

#define IO_DIR_IN( n ) { IO_DDR( IO_PORT_NAME( n ) ) &= ~_BV( IO_PIN_NAME( n ) ); }
#define IO_DIR_OUT( n ) { IO_DDR( IO_PORT_NAME( n ) ) |= _BV( IO_PIN_NAME( n ) ); }

#endif
