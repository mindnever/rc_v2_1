#include <unistd.h>
#include <fcntl.h>

#include "nvram.h"
#include "eeprom.h"

EEConfig eeconfig;

void nvram_Init()
{
}


uint8_t nvram_TimerSlotRead(NVTimerSlot *slot)
{
  memset(slot, 0, sizeof(*slot));
  return 1;
}

uint8_t nvram_DistanceSlotRead(NVDistanceSlot *slot)
{
  memset(slot, 0, sizeof(*slot));
  return 1;
}

uint8_t nvram_TimerSlotWrite(const NVTimerSlot *slot)
{
  return 1;
}

uint8_t nvram_DistanceSlotWrite(const NVDistanceSlot *slot)
{
  return 1;
}

void EE_Init()
{
}


void EE_ReadConfig()
{
  int fd = open("eeprom.dat", O_RDONLY);
  if(fd >= 0) {
       read(fd, &eeconfig, sizeof(eeconfig));
       close(fd);
     }
}

void EE_SaveConfig()
{
  int fd = open("eeprom.dat", O_WRONLY|O_CREAT|O_TRUNC, 0600);
  if(fd >= 0) {
      write(fd, &eeconfig, sizeof(eeconfig));
      close(fd);
    }
}

