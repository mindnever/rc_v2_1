#include <avr/interrupt.h>

#include "usart.h"

#define DEFAULT_BAUD 9600
#define BUFFER_SIZE 16

typedef struct {
    uint8_t data[BUFFER_SIZE];
    uint8_t start, used;
  } Buffer;

static Buffer rxBuffer, txBuffer;

uint8_t bufferWrite(Buffer *buf, const uint8_t *data, uint8_t len)
{
  uint8_t ret;
  
  for(ret = 0; (ret < len) && (buf->used < BUFFER_SIZE); ++ret) {

      buf->data[(buf->start + buf->used) % BUFFER_SIZE] = *data++;
      
      ++buf->used;
    }
  

  
  return ret;
}

uint8_t bufferRead(Buffer *buf, uint8_t *data, uint8_t len)
{
  uint8_t ret;
  
  for(ret = 0; (ret < len) && (buf->used > 0); ++ret) {
      *data++ = buf->data[buf->start];
      buf->used--;
      buf->start = (buf->start + 1) % BUFFER_SIZE;
    }

  return ret;
}
#if 1
ISR (USART_UDRE_vect)
{
  UDR = 'X';
  return;
  
  uint8_t b;

  if(bufferRead(&txBuffer, &b, 1) == 1) {

      UDR = b;

    } else {

      UCSRB &= ~_BV(UDRIE); // disable UDR interrupts

    }
}

ISR (USART_RXC_vect)
{
  uint8_t udr = UDR;
  return;
  
  if(rxBuffer.used == BUFFER_SIZE) {

      UCSRB &= ~_BV(RXCIE);

    } else {
      uint8_t data = UDR;
      
      bufferWrite(&rxBuffer, &data, 1);
    }
}
#endif

void usartInit()
{
  uint16_t ubrr = ((F_CPU / (16L * DEFAULT_BAUD)) - 1);
  
  UBRRL = ubrr & 0xff;
  UBRRH = (ubrr >> 8) & 0x7f;
  
//  UCSRB = _BV(RXEN) | _BV(TXEN)  | _BV(RXCIE);

  UCSRB = 0x00; // everything disabled
  
  UCSRC = _BV(URSEL) | _BV(UCSZ0) | _BV(UCSZ1); // check this need to be 8N1
}


uint8_t usartGetReadBufferSize()
{
  return rxBuffer.used;
}

uint8_t usartGetWriteBufferSize()
{
  return BUFFER_SIZE - txBuffer.used;
}

uint8_t usartWrite(const uint8_t *data, uint8_t len)
{
  UCSRB &= ~_BV(UDRIE); // disable UDR interrupt

  uint8_t ret = bufferWrite(&txBuffer, data, len);

  if(txBuffer.used > 0)
    UCSRB |= _BV(UDRIE); // enable UDR interrupt
  
  return ret;
}

uint8_t usartRead(uint8_t *data, uint8_t len)
{
  UCSRB &= ~_BV(RXCIE); // disable RXC interrupt

  uint8_t ret = bufferRead(&rxBuffer, data, len);

  if(rxBuffer.used < BUFFER_SIZE)
    UCSRB |= _BV(RXCIE);

  return ret;
}

void usartSetBaudRate(uint8_t rate)
{

}
