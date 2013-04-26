#include <drivers/twi.h>

#include "i2cmaster.h"

void twi_init()
{
  i2c_init();
}

int twi_read_bytes(uint8_t base, uint8_t addr, int len, uint8_t *buf)
{
  int ret = len;
  
  i2c_start_wait( base | I2C_WRITE ); // deadlock? timeout?
  
  if( i2c_write( addr ) )
  {
    return -1;
  }
  
  if( i2c_rep_start( base | I2C_READ ) )
  {
    return -1;
  }
  
  while(len > 1)
  {
    *buf = i2c_readAck();

    ++buf;
    --len;
  }
  
  *buf = i2c_readNak();
  
  i2c_stop();
  
  return ret;
}

int twi_write_bytes(uint8_t base, uint8_t addr, int len, const uint8_t *buf)
{
  int ret = len;
  
  if( i2c_start( base | I2C_WRITE ) )
  {
    i2c_stop();
    return -1;
  }
  
  i2c_write( addr );

  while(len > 0)
  {
    if( i2c_write( *buf ) )
    {
      return -1;
    }
    
    --len;
    ++buf;
  }

  i2c_stop();
  
  return ret;
}


