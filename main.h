#ifndef _RC_MAIN_H_
#define _RC_MAIN_H_

#define LCD_WIDTH 240
#define LCD_HEIGHT 64

#include <inttypes.h>

enum {
    STAGE_POP = 0,
    STAGE_NOP,
    STAGE_POWEROFF,
    STAGE_MAIN,
    STAGE_MENU,
    STAGE_SCREENSAVER,
    STAGE_SPLITMANAGEMENT,
    STAGE_DATETIME,
    STAGE_CALIBRATION,
    STAGE_DISPLAYSETTINGS,
    STAGE_MASTERRESET,
    STAGE_CONFIGMENU,
  };

void pushStage(uint8_t stage);
void popStage();

typedef void (* funcptr_t)();

void delay_ms(int ms);

void sys_halt();
void sys_resume();

extern uint8_t debug_mode;

#endif /* _RC_MAIN_H_ */
