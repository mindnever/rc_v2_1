#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "kbd.h"
#include <drivers/pcf8583-rtc.h>

#if (BOARD == BOARD_PROMICRO)

static void _kbd_init()
{
// setup ADC, ADMUX input to ADC6, Vref = AVcc, start , 125khz clock
// free running mode

  ADMUX = _BV( REFS0 ) | _BV( ADLAR ) | 7;
  ADCSRA = _BV( ADEN ) | _BV( ADSC ) | _BV( ADPS0 ) | _BV( ADPS1 ) | _BV( ADPS2 ) | _BV( ADATE );
  DIDR0 = _BV( ADC7D ); // disable digital input
}

#define ADC_STEP ( 0xff / KBD_NUM_KEYS )

// Voltages:
// Vcc - no key pressed
// 0   - D
// 1/4 - C
// 2/4 - B
// 3/4 - A


static uint8_t _kbd_read()
{
  // maybe not free runing mode...

  uint8_t val = ADCH;
  
  uint8_t cmp = ADC_STEP / 2;
  uint8_t i;
  
  for( i = 0; i < KBD_NUM_KEYS; ++i )
  {
    if( val <= cmp )
    {
      return ~_BV( i );
    }
    
    cmp += ADC_STEP;
  }
  
  return 0xff;
}

#define KBD_INIT() _kbd_init()
#define KBD_READ() _kbd_read()

#elif (BOARD == BOARD_with_serial_kbd)

#define KBD_CLOCK PB3
#define KBD_LOAD  PB2
#define KBD_DATA  PC7

#define KBD_CONTROL_PORT PORTB

static void _kbd_init()
{
  DDRC &= ~_BV(KBD_DATA); // input
  DDRB |= _BV(KBD_CLOCK) | _BV(KBD_LOAD); // output
  
}

static uint8_t _kbd_read()
{
  uint8_t data;
  
  KBD_CONTROL_PORT |= _BV(KBD_CLOCK);
  KBD_CONTROL_PORT &= ~_BV(KBD_LOAD); // load data
  __asm("nop;"); __asm("nop;"); __asm("nop;");
  KBD_CONTROL_PORT |= _BV(KBD_LOAD);

  for( i = 0; i < KBD_NUM_KEYS; ++i )
  {
    if( PINC & _BV( KBD_DATA ) )
    {
      data |= _BV( i );
    }

    KBD_CONTROL_PORT &= ~_BV(KBD_CLOCK); // clock down
    KBD_CONTROL_PORT |= _BV(KBD_CLOCK); // clock up
  }

  return data;
}

#define KBD_INIT() _kbd_init()
#define KBD_READ() _kbd_read()

#else

#define KBD_INIT() { \
  PORTD |= 0x0f; /* pullups are on */ \
  DDRD &= ~0x0f; /* bits 0-3 are inputs */ \
}

#define KBD_READ() PIND

#endif


#define DEBOUNCE_COUNTER 4 /* 40 msec */
#define REPEAT_COUNTER 30 /* 1000 msec */



//#define KBD_TYPE SERIAL
//#
#define KBD_TYPE ANALOG

volatile uint8_t kbd_eventCounter;

static KBDEvent events[KBD_NUM_KEYS];
static uint8_t counter[KBD_NUM_KEYS];
static volatile uint8_t pendingDown; // bitmap
static volatile uint8_t pendingRepeat;
static volatile uint8_t pendingUp;
static volatile uint8_t scanEnabled;

void kbd_scan() // called from rtctimer, every 10ms
{
  if(!scanEnabled)
    return;

  uint8_t data = KBD_READ();

  uint8_t i;

  for(i = 0; i < KBD_NUM_KEYS; ++i)
  {
      if( data & _BV( i ) )
      {
          // key is up
          // was it down ?
          if(counter[i] > DEBOUNCE_COUNTER) { // yes
              // make KEY_UP event
              pendingUp |= _BV(i);
              counter[i] = 0;
              kbd_eventCounter++;
            }
          
      }
      else
      {
          // key is down

          if(counter[i] > REPEAT_COUNTER)
          {

              pendingRepeat |= _BV(i);
              kbd_eventCounter++;

          }
          else if(counter[i] == DEBOUNCE_COUNTER)
          {

              ++counter[i];

              pendingDown |= _BV(i);
              kbd_eventCounter++;

          }
          else
          { // debouncing

              ++counter[i];

          }
      }
    }
}

void kbd_init()
{
  printf("KBD\n");
  
  KBD_INIT();
  
  uint8_t i;

  for(i = 0; i < KBD_NUM_KEYS; ++i)
  {
      events[i].type = KBDEVENT_TYPE_NOP;
      events[i].key = i;
  }
  
  rtctimer_register(&kbd_scan);
  
  scanEnabled = 1;
}


KBDEvent *kbd_getEvent()
{
  if(scanEnabled && !(pendingDown | pendingUp | pendingRepeat))
  {
    return 0; // shortcut
  }

  scanEnabled = 0;

  uint8_t i;

  for(i = 0; i < KBD_NUM_KEYS; ++i)
  {

      if(pendingDown & _BV(i))
      {
          pendingDown &= ~_BV(i);
          events[i].type = KBDEVENT_TYPE_DOWN;

          return &events[i];
      }

      if(pendingRepeat & _BV(i))
      {
          pendingRepeat &= ~_BV(i);
          events[i].type = KBDEVENT_TYPE_REPEAT;

          return &events[i];
      }
      

      if(pendingUp & _BV(i))
      {
          pendingUp &= ~_BV(i);
          events[i].type = KBDEVENT_TYPE_UP;

          return &events[i];
      }

  }

  scanEnabled = 1;

  return 0;
}
