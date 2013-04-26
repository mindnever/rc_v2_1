#ifndef _USBASP_USART_H_
#define _USBASP_USART_H_


uint8_t usartGetReadBufferSize();
uint8_t usartGetWriteBufferSize();
uint8_t usartWrite(const uint8_t *data, uint8_t len);
uint8_t usartRead(uint8_t *data, uint8_t len);
void usartSetBaudRate(uint8_t rate);
void usartInit();

#endif /* _USBASP_USART_H_ */
