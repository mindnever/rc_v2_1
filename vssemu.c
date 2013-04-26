#include "vss.h"

uint32_t count = 0;

volatile uint8_t vss_Wakeup = 0;

void vss_init()
{
}

uint16_t vss_getPulseLength()
{
  return 400;
}

uint32_t vss_getPulseCount(uint8_t ix)
{
  count += 1;
  return count;
}

uint32_t vss_getDistance(uint8_t ix)
{
  count += 1;
  return (count * 100) / 3600;
}

void     vss_resetDistance(uint8_t ix)
{
  count = 0;
}

void vss_calibrationStart()
{
  
}
void vss_calibrationEnd()
{
}

void vss_calibrationSet(u_int32_t distance)
{
  debugf("vss_calibrationSet: %u\n", distance);
}



u_int32_t vss_calibrationDistance()
{
  return vss_getDistance(0);
}



uint16_t vss_getSpeed()
{
  return 1200;
}

void vss_snapshot(uint8_t force)
{
}

