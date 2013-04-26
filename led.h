#ifndef _LED_H_
#define _LED_H_

#include <drivers/board.h>

#if (BOARD == BOARD_PROMICRO)

#define LED_A_PORT PORTB
#define LED_A_DDR  DDRB
#define LED_A_PIN  PB0

#define LED_B_PORT PORTD
#define LED_B_DDR  DDRD
#define LED_B_PIN  PD5

#define LED_INIT(x) x ## _DDR |= _BV( x ## _PIN ); LED_OFF(x)
#define LED_OFF(x) x ## _PORT |= _BV( x ## _PIN )
#define LED_ON(x) x ## _PORT &= ~_BV( x ## _PIN )


#endif


#endif /* _LED_H_ */
