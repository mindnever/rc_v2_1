#include "rtctimer.h"
#include "hwdep.h"
#include <time.h>
#include <sys/time.h>

static struct timeval tv;

#define LEAP_YEAR_DAYS 366
#define NORMAL_YEAR_DAYS 365

#define LEAP_MONTH_DAYS 29
#define NORMAL_MONTH_DAYS 28


static const char *mname[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };

static uint8_t mlen[] = { 31,
                   28,
                   31,
                   30,
                   31,
                   30,
                   31,
                   31,
                   30,
                   31,
                   30,
                   31 };


uint8_t  rtctimer_getMonthNumberOfDays(uint8_t year, uint8_t month)
{
  uint16_t i = year + 1900;
  
  mlen[1] = (i % 4 ? NORMAL_MONTH_DAYS : (i % 100 ? LEAP_MONTH_DAYS : (i % 400 ? NORMAL_MONTH_DAYS : LEAP_MONTH_DAYS)));
  
  return mlen[month];
}

const char *rtctimer_getMonthName(uint8_t month)
{
  return mname[month];
}


void rtctimer_init()
{
  gettimeofday(&tv, 0);
}

uint32_t rtctimer_getTimer(uint8_t ix)
{
  struct timeval now;
  
  gettimeofday(&now, 0);

  uint32_t ret = ((now.tv_sec - tv.tv_sec) * 100) + ((now.tv_usec - tv.tv_usec) / 10000);
  
  return ret;
}

void rtctimer_resetTimer(uint8_t ix)
{
  gettimeofday(&tv, 0);
}


int8_t rtctimer_getDate(struct Date *dt)
{
  struct tm *tm;
  time_t t = time(0);
  
  tm = localtime(&t);
  
  dt->wday = tm->tm_wday;
  dt->mday = tm->tm_mday;
  dt->month = tm->tm_mon + 1;
  dt->year = (tm->tm_year - 100);

  return 0;
}

int8_t rtctimer_setDate(struct Date *dt)
{
  return -1;
}

int8_t rtctimer_getTimeOfDay(struct Time *tx)
{
  struct tm *tm;
  time_t t = time(0);
  
  tm = localtime(&t);
  
  tx->seconds = tm->tm_sec;
  tx->minutes = tm->tm_min;
  tx->hours = tm->tm_hour;

  return 0;
}

int8_t rtctimer_setTimeOfDay(struct Time *t)
{
  return -1;
}

uint16_t rtctimer_getCalibration()
{
  return 500;
}

void rtctimer_register(isrfunc_t func)
{
}
