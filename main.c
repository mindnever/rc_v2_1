
#include "Font_david6.h"
#include "Font_digits23c.h"
#include "Font_digits6x13.h"

#include <drivers/nvram.h>
#include <drivers/pcf8583-rtc.h>
#include <drivers/vss.h>
#include <drivers/eeprom.h>
#include "ra6963.h"

#include <LUFA/Drivers/USB/USB.h>

#include "oddebug.h"
#include "menu.h"
#include "usb.h"
#include "screensaver.h"
#include "kbd.h"
#include "console.h"
#include "main.h"
#include "gui.h"
#include "led.h"

// #include "usart.h"


#include <stdio.h>
#include <string.h>

#ifdef __AVR__
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/wdt.h>
#else
#include <sched.h>
#include <time.h>
#endif

#ifdef MCUCSR
#define MCUSR MCUCSR
#endif



#define LCD_RAMSIZE 8192

uint8_t debug_mode = 0;

static void mainscreen_Start();
static void mainscreen_Process();

static void showLogo();
static void logoInit();
static void powerOff() __attribute__((noreturn));
static void reset() __attribute__((noreturn));

uint8_t stageRequested, currentStage;
uint8_t logoCountdown;
uint8_t logoLight;
int8_t logoDelta;

uint8_t stageStack[8];
uint8_t stagePtr;
uint8_t poweroff = 0;

  static unsigned updSpeed = 0;

uint8_t cdSel = 0;

#define RUNLOOP_APPF _BV( 0 )
#define RUNLOOP_USBF _BV( 1 )

static uint8_t runloop = RUNLOOP_APPF | RUNLOOP_USBF;

typedef struct {
    funcptr_t begin;
    funcptr_t process;
  } StageFunc;

static StageFunc stageTable[] = {
    { &powerOff, &powerOff }, // STAGE_POWEROFF
    { &mainscreen_Start, &mainscreen_Process }, // STAGE_MAIN
    { &menu_StartMain, &menu_ProcessMain }, // STAGE_MENU
    { &screensaver_Start, &screensaver_DrawFrame }, // STAGE_SCREENSAVER
    { &menu_StartSplitManagement, &menu_ProcessSplitManagement },
    { &menu_StartDateTime, &menu_ProcessDateTime },
    { &menu_StartCalibration, &menu_ProcessCalibration },
    { &menu_StartDisplaySettings, &menu_ProcessDisplaySettings },
    { &menu_StartMasterReset, &menu_ProcessMasterReset },
    { &menu_StartConfigMenu, &menu_ProcessConfigMenu },
  };

void pushStage(uint8_t stage)
{
  if(stage == STAGE_NOP)
    return;
  
  if(stage == STAGE_POP) {
      popStage();
      return;
    }

  stageStack[stagePtr] = stageRequested; // old current stage
  if(stagePtr < sizeof(stageStack) - 1)
    ++stagePtr;

  stageRequested = stage;
  currentStage = 0xff;
}

void popStage()
{
  if(stagePtr > 0) {
      stageRequested = stageStack[--stagePtr];
      currentStage = 0xff;
    } else {
      pushStage(STAGE_MAIN);
    }
}


void delay_ms(int ms)
{
#ifdef __AVR__
  ms /= 2;
  
  while(ms-- > 0) {
      _delay_ms(2);
    __asm("wdr;");
    }
#else
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = ms * 1000000;
  nanosleep(&ts, 0);
#endif
}

extern BitMap EVW_137_bw_gif_bm;


static void logoInit()
{
  BitMap bm;
  memcpy_P(&bm, &EVW_137_bw_gif_bm, sizeof(bm));

  gfx_RectFill(0, 0, LCD_WIDTH, LCD_HEIGHT, 0);
  gfx_BltBitMap(20, 0, &bm);
  
  logoCountdown = 200;
  logoLight = 0;
  logoDelta = 5;
}


static void showLogo()
{
  logoCountdown--;

  if(logoCountdown == 0) {
      RA6963_Backlight(eeconfig.gfx_Brightness);

      popStage();

    } else {
      
      RA6963_Backlight(logoLight);
      
      logoLight += logoDelta;

      if((logoLight > 250) || (logoLight == 0))
        logoDelta = -logoDelta;

    }
  
  delay_ms(10);
}

static void reset()
{
  while(1) { }
}

void powerOff()
{
#ifdef __AVR__
 uint8_t sleeping = 1;

 RA6963_Backlight(0); 

// SMCR |= _BV(SE) | _BV(SM2) | _BV(SM1); // StandBy mode

//  __asm("sleep;");
  
  while(sleeping && vss_Idle)
  {

    KBDEvent *evt;

    kbd_scan();

    while(evt = kbd_getEvent())
    {
        if(evt->type == KBDEVENT_TYPE_REPEAT)
        {
            sleeping = 0;
        }
    }
    
    __asm("wdr;");
  }

//SMCR &= ~_BV(SE);
RA6963_Backlight(255);

reset();

  
#endif
}

static void idle_tick() // 100hz
{
  static uint16_t idler = 0;
  static uint8_t myKBD = 0;

  ++idler;
  
  if(!vss_Idle || (kbd_eventCounter != myKBD)) {
    idler = 0;
    myKBD = kbd_eventCounter;
  }

  if(idler > 60000) { // 10 minutes
    poweroff = 1;
  }

}

void sys_halt()
{
  runloop = RUNLOOP_USBF;
}

void sys_resume()
{
  runloop = RUNLOOP_APPF | RUNLOOP_USBF;
}


int main(void)
{
  int8_t stageScroll = 0;
  pixcoord_t displayY = LCD_HEIGHT;

  odDebugInit();

  LED_INIT( LED_A );
  LED_INIT( LED_B );


  USB_Init();
  
  { // init block
    uint8_t needLogo = 0;
    
    cli();
    

#ifdef __AVR__
    wdt_enable( WDTO_500MS );

    if( MCUSR & _BV( PORF ) )
      needLogo = 1;

    // check reset conditions
    
    // clear reset conditions


    MCUSR &= ~( _BV( PORF ) | _BV( WDRF ) | _BV( BORF ) | _BV( EXTRF ) );
    
    
#else
    needLogo = 1;
#endif


    gfx_Init(LCD_WIDTH, LCD_HEIGHT, LCD_WIDTH, LCD_HEIGHT * 2, LCD_RAMSIZE);

    gfx_RectFill(0, 0, LCD_WIDTH, LCD_HEIGHT * 3, 0);
    
    gfx_SetActiveWindow(0, displayY);
    gfx_SetVisibleWindow(0, displayY);
    
    console_init();


    EE_Init(); // init/load settings from eeprom

    RA6963_Backlight(eeconfig.gfx_Brightness);
//    lc7981hw_contrast(128); // middle

    printf_P(PSTR("Initializing: "));

    nvram_Init();

    rtctimer_init();

    vss_init();
    kbd_init();
    
//    mpu6050_basic_init();

    rtctimer_register(&idle_tick);

    printf_P(PSTR("\nEntering main loop\n"));
  
#ifdef __AVR__
  sei();
#endif

    currentStage = stageRequested = STAGE_MAIN;

#if 0
    if(needLogo) {
        pushStage(STAGE_LOGO);
      } else {
        mainscreen_Start();
      }
#endif
        mainscreen_Start();
  }
  
  poweroff = 0;
  
  while(!poweroff) { // main loop

      if( runloop & RUNLOOP_USBF )
      {
        USB_USBTask();
      }

      if( runloop & RUNLOOP_APPF )
      {
          if(currentStage != stageRequested) {
              currentStage = stageRequested;
              stageScroll = -4;
            }
                
          if(stageScroll) {
              displayY += stageScroll;

              gfx_SetVisibleWindow(0, displayY);
              delay_ms(10);

              if(displayY == 0) { // 

                  stageScroll = -stageScroll;
                  
                  if(stageTable[currentStage - 2].begin) {
                      stageTable[currentStage - 2].begin();
                    }

                } else if(displayY == LCD_HEIGHT) {

                  stageScroll = 0;

                }

            } else {

              stageTable[currentStage - 2].process();

            }
          
          
          // do some general things that need to be done outside interrupt
          
          vss_snapshot(0);
          rtctimer_snapshot(0);
          gui_FullUpdate(0);

      }
#ifdef __AVR__
      wdt_reset();
#else
      sched_yield();
#endif
    }

    powerOff();
}



void draw_Time( const Font *font_P, pixcoord_t x, pixcoord_t y, struct Time *tm )
{
  char buf[ 9 ];

  snprintf_P( buf, sizeof( buf ), PSTR( "%02u:%02u:%02u" ), tm->hours, tm->minutes, tm->seconds );
  gfx_DrawText(font_P, x, y, buf);
}

void draw_SysTime( const Font *font_P, pixcoord_t x, pixcoord_t y, uint32_t t )
{
  struct Time tm;

  tm.seconds = t % 60;
  t /= 60;
  
  tm.minutes = t % 60;
  t /= 60;
  
  tm.hours = t % 60;
  
  draw_Time( font_P, x, y, &tm );
}

void mainscreen_SetDistanceMode(const char *mode)
{
  static uint8_t m;
  
  uint8_t newM = mode ? mode[0] : 0;

  if(m != newM) {
    if(mode) {
      gfx_RectFill(136, 43, 15, 8, 0);
      gfx_DrawText(&david6, 136, 51, mode);
    }
    gfx_RectFill(23, 28, 112, 23, 0);
    m = newM;
  }
  
}

void mainscreen_Draw()
{  
  char buf[32];
  
  uint16_t speed = vss_getSpeed();
  uint32_t distance = vss_getDistance(cdSel + 1) % 1000000L;
  uint32_t tdist = vss_getDistance(0);

//  uint32_t vss = vss_getICR();
//  uint32_t pl = vss_getPulseLength();
//  uint32_t pc = vss_getPulseCount(0);
  
  struct Time tm;
  struct Date dt;
  
  rtctimer_getTimeOfDay(&tm);
  rtctimer_getDate(&dt);
  
  draw_Time( &digits6x13, 0, 11, &tm );

//  snprintf_P(buf, sizeof(buf), PSTR("%05u"), rtctimer_getCalibration());
//  gfx_DrawText(&digits6x13, 0, 32, buf);

  
  snprintf_P(buf, sizeof(buf), PSTR("%u"), cdSel + 1);
  gfx_RectFill(155, 27, 6, 10, 0);
  gfx_DrawText(&david6, 155, 36, buf);

  
  if(updSpeed != tm.seconds)
  {
    snprintf_P(buf, sizeof(buf), PSTR("%3u"), (unsigned) speed);
    gfx_DrawText(&digits23c, 88, 23, buf);
    updSpeed = tm.seconds;

    if(distance < 5000) {
      snprintf_P(buf, sizeof(buf), PSTR("%7u"), (unsigned) distance);
      mainscreen_SetDistanceMode("m");
    } else {
      snprintf_P(buf, sizeof(buf), PSTR("%4u.%02u"), (unsigned) (distance / 1000), (unsigned) (distance % 1000) / 10);
      mainscreen_SetDistanceMode("km");
    }

    pixcoord_t l = gfx_TextLen(&digits23c, buf);
    gfx_DrawText(&digits23c, 136 - l, 51, buf);
  
    snprintf_P(buf, sizeof(buf), PSTR("%6lu.%02u"), (uint32_t) (tdist / 1000), (unsigned)(tdist % 1000)/10);
    gfx_DrawText(&digits6x13, 164, 24, buf);
  }
//  int16_t mputemp = mpu6050_temperature();
//  int16_t m1 = mputemp / 100;
//  uint16_t m2 = abs( mputemp - ( m1 * 100 ) );
  
//  snprintf_P(buf, sizeof(buf), PSTR("%d.%02u %6d"), m1, m2, mpu6050_temperature_raw() );
//  gfx_DrawText( &digits6x13, 0, 63, buf );

  if(debug_mode) {
    snprintf_P(buf, sizeof(buf), PSTR("vss_Idle:%d vss_ICR:%lu"), vss_Idle, vss_getICR());
    gfx_DrawText( &david6, 0, 62, buf );
  }

  uint32_t lap = rtctimer_getTimer(cdSel) / 100;
  uint32_t run = rtctimer_getRunning(cdSel) / 100;
  
  draw_SysTime( &digits6x13, 193, 38, lap);
  draw_SysTime( &digits6x13, 193, 49, run);
  draw_SysTime( &digits6x13, 193, 60, (lap - run));

#ifndef __AVR__
        sched_yield();
#endif
}

void mainscreen_Start()
{
//  char buf[32];

  gfx_RectFill(0, 0, LCD_WIDTH, LCD_HEIGHT, 0);  

  
  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 1);


  gfx_DrawText(&david6, 136, 36, PSTR("Trip"));  
  gfx_DrawText(&david6, 136, 8, PSTR("Speed"));
  gfx_DrawText(&david6, 136, 23, PSTR("km/h"));
  
  mainscreen_SetDistanceMode(0);

  gfx_HorizontalLine(57, 24, 103);
  gfx_VerticalLine(57, 14, 10);
//  gfx_VerticalLine(159, 19, 5);

  gfx_HorizontalLine(22, 52, 138);
  gfx_VerticalLine(22, 42, 10);

  gfx_VerticalLine(161, 0, 64);

  gfx_DrawText( &david6, 173, 38, PSTR("Lap:") );
  gfx_DrawText( &david6, 173, 49, PSTR("Run:") );
  gfx_DrawText( &david6, 169, 60, PSTR("Stop:") );

//  gfx_DrawText(&david6, 40, 62, PSTR("adc:"));
  
  gfx_DrawText(&david6, 164, 12, PSTR("Total dist."));

//  gfx_DrawText(&david6, 68, 78, "Total", 0);

  gfx_DrawText(&david6, 228, 24, PSTR("km"));
  
//  gfx_VerticalLine(79, 52, 28);

//  gfx_HorizontalLine(65, 79, 95);
//  gfx_VerticalLine(65, 74, 5);
//  gfx_VerticalLine(159, 74, 5);

  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 0);

  mainscreen_Draw();
}


void mainscreen_Process()
{
  mainscreen_Draw();
  
  KBDEvent *evt;

  while(evt = kbd_getEvent()) {
      if(evt->type == KBDEVENT_TYPE_DOWN) {
          switch(evt->key) {
              case KEY_MENU:
                pushStage(STAGE_MENU);
                break;
              case KEY_SPLIT:
                rtctimer_resetTimer(cdSel);
                vss_resetDistance(cdSel + 1);
                vss_snapshot(cdSel + 1); // force snapshot
                rtctimer_snapshot( cdSel );
odPrintf("KEY_SPLIT, distance reset: raw=%lu, dist=%lu\n", vss_getPulseCount( cdSel + 1 ), vss_getDistance( cdSel + 1 ) );
                updSpeed = 0; // force spd/distance refresh
                break;
              case KEY_UP:
                if(cdSel == 0) {
                  cdSel = RTCTIMER_NUM_TIMERS - 1;
                } else {
                  --cdSel;
                }
                updSpeed = 0;
                break;
              case KEY_DOWN:
                cdSel++;
                if(cdSel >= RTCTIMER_NUM_TIMERS) {
                  cdSel = 0;
                }
                updSpeed = 0; // force spd/distance refresh
                break;
                
            }
        }
    }
}

