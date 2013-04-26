#include <drivers/hwdep.h>
#include "screensaver.h"
#include <gfx/gfx.h>
#include <drivers/pcf8583-rtc.h>
#include "Font_digits15c.h"

#include <stdio.h>

// #define USE_SCREENSAVER

#ifdef USE_SCREENSAVER

extern BitMap jeepframe_1_bmp_bm;
extern BitMap jeepframe_2_bmp_bm;
extern BitMap jeepframe_3_bmp_bm;
extern BitMap jeepframe_4_bmp_bm;
extern BitMap jeepframe_5_bmp_bm;
extern BitMap jeepframe_6_bmp_bm;
extern BitMap jeepframe_7_bmp_bm;
extern BitMap jeepframe_8_bmp_bm;
extern BitMap jeepframe_9_bmp_bm;
extern BitMap jeepframe_10_bmp_bm;
extern BitMap jeepframe_11_bmp_bm;
extern BitMap jeepframe_12_bmp_bm;
extern BitMap jeepframe_13_bmp_bm;
extern BitMap jeepframe_14_bmp_bm;
extern BitMap jeepframe_15_bmp_bm;
extern BitMap jeepframe_16_bmp_bm;
extern BitMap jeepframe_17_bmp_bm;
extern BitMap jeepframe_18_bmp_bm;
extern BitMap jeepframe_19_bmp_bm;
extern BitMap jeepframe_20_bmp_bm;
extern BitMap jeepframe_21_bmp_bm;
extern BitMap jeepframe_22_bmp_bm;
extern BitMap jeepframe_23_bmp_bm;
extern BitMap jeepframe_24_bmp_bm;
extern BitMap jeepframe_25_bmp_bm;


static BitMap * const anim[] PROGMEM = {

    &jeepframe_1_bmp_bm,
    &jeepframe_2_bmp_bm,
    &jeepframe_3_bmp_bm,
    &jeepframe_4_bmp_bm,
    &jeepframe_5_bmp_bm,
    &jeepframe_6_bmp_bm,
    &jeepframe_7_bmp_bm,
    &jeepframe_8_bmp_bm,
    &jeepframe_9_bmp_bm,
    &jeepframe_10_bmp_bm,
    &jeepframe_11_bmp_bm,
    &jeepframe_12_bmp_bm,
    &jeepframe_13_bmp_bm,
    &jeepframe_14_bmp_bm,
    &jeepframe_15_bmp_bm,
    &jeepframe_16_bmp_bm,
    &jeepframe_17_bmp_bm,
    &jeepframe_18_bmp_bm,
    &jeepframe_19_bmp_bm,
    &jeepframe_20_bmp_bm,
    &jeepframe_21_bmp_bm,
    &jeepframe_22_bmp_bm,
    &jeepframe_23_bmp_bm,
    &jeepframe_24_bmp_bm,
    &jeepframe_25_bmp_bm,

  };
#endif


void screensaver_Start()
{

}

void screensaver_DrawFrame()
{
#ifdef USE_SCREENSAVER
  static uint8_t currentFrame = 0;
  static uint8_t clockUpdate = 1;
  static uint8_t colons = 1;

  BitMap bm;

  memcpy_P(&bm, (void *) pgm_read_word(&anim[currentFrame]), sizeof(bm));
      
  gfx_BltBitMap(0, 0, &bm);

  ++currentFrame;
  if(currentFrame >= 25)
    currentFrame = 0;
  
  --clockUpdate;
  if(clockUpdate == 0) {
      clockUpdate = 2;

      struct Time t;
      
      rtctimer_getTimeOfDay(&t);
      
      char buf[16];

      colons ^= 1;
      
      if(colons)
        snprintf(buf, sizeof(buf), "%02d:%02d:%02d", t.hours, t.minutes, t.seconds);
      else
        snprintf(buf, sizeof(buf), "%02d %02d %02d", t.hours, t.minutes, t.seconds);
      
      gfx_DrawText(&digits15c, 50, 60, buf);
    }
#endif
}
