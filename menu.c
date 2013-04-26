#include <stdio.h>

#include "main.h"
#include "menu.h"
#include <gfx/gfx.h>
#include "kbd.h"
#include "gui.h"
#include <drivers/pcf8583-rtc.h>
#include <drivers/vss.h>
#include <drivers/eeprom.h>
#include "Font_david6.h"
#include "Font_digits6x13.h"
#include "Font_digits23c.h"
#include "ra6963.h"

enum {
    SUBMENU_CALIBRATION_ADJUST = 1,
    SUBMENU_CALIBRATION_RESTART,
    SUBMENU_CALIBRATION_CONFIRM,
  };

enum {
    SUBMENU_MASTERRESET_DISTANCE = 1,
    SUBMENU_MASTERRESET_TIMER = 2,
  };

const char back_to_main_txt[] PROGMEM = "Back To Main Menu";
const char exit_calibration_txt[] PROGMEM = "Exit";
const char master_reset_txt[] PROGMEM = "Master Reset";
const char split_management_txt[] PROGMEM = "Split Management";
const char configuration_txt[] PROGMEM = "Configuration";
const char poweroff_txt[] PROGMEM = "Power Off";
const char exit_menu_txt[] PROGMEM = "Exit Menu";
const char calibrate_device_txt[] PROGMEM = "Calibrate Device";
const char set_date_time_txt[] PROGMEM = "Set Date & Time";
const char display_txt[] PROGMEM = "Configure Display";
const char dummy_txt[] PROGMEM = "dummy";
const char adjust_distance_txt[] PROGMEM = "Adjust Distance";
const char restart_calibration_txt[] PROGMEM = "Restart Calibration";
const char accept_new_calibration_txt[] PROGMEM = "Accept";
const char reset_master_distance_txt[] PROGMEM = "Reset Master Distance";
const char reset_master_timer_txt[] PROGMEM = "Reset Master Timer";

static const GUI_MenuEntry mainMenuEntries[] PROGMEM = {
    { master_reset_txt, GUI_ACTION_STAGE(STAGE_MASTERRESET) },
//    { split_management_txt, GUI_ACTION_STAGE(STAGE_SPLITMANAGEMENT) },
    { configuration_txt, GUI_ACTION_STAGE(STAGE_CONFIGMENU) },
    { poweroff_txt, GUI_ACTION_STAGE(STAGE_POWEROFF) },
    { exit_menu_txt, GUI_ACTION_STAGE(STAGE_POP) }
  };

static const GUI_MenuEntry configMenuEntries[] PROGMEM = {
    { calibrate_device_txt, GUI_ACTION_STAGE(STAGE_CALIBRATION) },
    { set_date_time_txt, GUI_ACTION_STAGE(STAGE_DATETIME) },
    { display_txt, GUI_ACTION_STAGE(STAGE_DISPLAYSETTINGS) },
    { back_to_main_txt, GUI_ACTION_STAGE(STAGE_POP) }
  };

static const GUI_MenuEntry splitMenuEntries[] PROGMEM = {
    { dummy_txt, GUI_ACTION_STAGE(STAGE_SCREENSAVER) },
    { back_to_main_txt, GUI_ACTION_STAGE(STAGE_POP) }
  };

static const GUI_MenuEntry calibrationMenu[] PROGMEM = {
    { adjust_distance_txt, GUI_ACTION_EVENT(SUBMENU_CALIBRATION_ADJUST) },
    { restart_calibration_txt, GUI_ACTION_EVENT(SUBMENU_CALIBRATION_RESTART) },
    { exit_calibration_txt, GUI_ACTION_STAGE(STAGE_POP) },
  };

static const GUI_MenuEntry calibrationConfirmationMenu[] PROGMEM = { 
    { accept_new_calibration_txt, GUI_ACTION_EVENT(SUBMENU_CALIBRATION_CONFIRM) },
    { exit_calibration_txt, GUI_ACTION_STAGE(STAGE_POP) }
  };

static const GUI_MenuEntry masterResetEntries[] PROGMEM = {
    { reset_master_distance_txt, GUI_ACTION_EVENT(SUBMENU_MASTERRESET_DISTANCE) },
    { reset_master_timer_txt, GUI_ACTION_EVENT(SUBMENU_MASTERRESET_TIMER) },
    { back_to_main_txt, GUI_ACTION_STAGE(STAGE_POP) }
  };


static const GUI_Slider dsBrightness PROGMEM = {
    { GUI_TYPE_SLIDER, GUIF_HAS_FRAME, 60, 20, 90, 14 },
  };

static const GUI_Slider dsContrast PROGMEM = {
    { GUI_TYPE_SLIDER, GUIF_HAS_FRAME, 60, 40, 90, 14 },
  };

static const GUI_Menu caMainMenu PROGMEM = {
    { GUI_TYPE_MENU, 0, 150, 16, 88, LCD_HEIGHT - 16 - 2 },
  };

static const GUI_Menu caConfirmMenu PROGMEM = {
    { GUI_TYPE_MENU, 0, 150, 16, 88, LCD_HEIGHT - 16 - 2 },
  };

static const GUI_Menu mDefaultMenu PROGMEM = {
    { GUI_TYPE_MENU, 0, 2, 16, LCD_WIDTH - 4, LCD_HEIGHT - 16 - 2 },
  };

static union {

  struct {
      GUI_Menu menu;
    } simpleMenu;

  struct {
      GUI_Slider slBrightness;
      GUI_Slider slContrast;
      uint8_t selector;
      GUI_Slider *slPtr;
    } displaySettings;

  struct {
      GUI_Menu main;
      GUI_Menu confirm;
      GUI_Menu *current;
      uint32_t distance;

    } calibrationSettings;
  
  struct { // date & time setup
      uint8_t selectedItem;
      uint8_t editing;
    };
  
  struct {
      GUI_Menu masterResetMenu;
    };
  
  struct {
      GUI_Menu menu;
    } splitMenu;
  
  } data;

#define NUM_ENTRIES(x) sizeof(x) / sizeof(x[0])

static void menu_TitleBar(const char *title, uint8_t pgm)
{
  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, pgm);
  
  pixcoord_t tw = gfx_TextLen(&david6, title);

  gfx_Box(0, 0, LCD_WIDTH, 13, GFX_BOX_FILL | GFX_BOX_ROUND);
  gfx_TextMode(GFX_TEXTMODE_INVERSE, 1);
  gfx_DrawText(&david6, (LCD_WIDTH - tw) / 2, 10, title);
  gfx_TextMode(GFX_TEXTMODE_INVERSE, 0);
  
  gfx_Box(0, 14, LCD_WIDTH, LCD_HEIGHT - 14, GFX_BOX_ROUND);
  
  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 0);
}

void menu_DrawSimpleMenu()
{
  gui_ObjectUpdate((GUI_Object *) &data.simpleMenu.menu);
}

static void menu_StartSimpleMenu(const char *title, const GUI_MenuEntry *entries, uint8_t size)
{
  gfx_RectFill(0, 0, LCD_WIDTH, LCD_HEIGHT, 0);
  menu_TitleBar(title, 1);
  
  memcpy_P(&data.simpleMenu.menu, &mDefaultMenu, sizeof(GUI_Menu));
  
  data.simpleMenu.menu.entries_P = entries;
  data.simpleMenu.menu.size = size;
  
  gui_FullUpdate(1);
  gui_ObjectSetFocus((GUI_Object *)&data.simpleMenu.menu);
  
  menu_DrawSimpleMenu();
}

void menu_ProcessSimpleMenu()
{
  KBDEvent *evt;

  while(evt = kbd_getEvent()) {
          gui_ProcessEvent(evt);
/*
      if(IS_EXIT(evt)) {
          popStage();
        } else {
          gui_ProcessEvent(evt);
        }
*/
    }
  
  menu_DrawSimpleMenu();
}


////  main menu

void menu_DrawMain()
{
  menu_DrawSimpleMenu();
}

void menu_ProcessMain()
{
  menu_ProcessSimpleMenu();
}

void menu_StartMain()
{
  menu_StartSimpleMenu(PSTR("Main Menu"), mainMenuEntries, NUM_ENTRIES(mainMenuEntries));
}


////

void menu_DrawSplitManagement()
{
  menu_DrawSimpleMenu();
}

void menu_ProcessSplitManagement()
{
  menu_ProcessSimpleMenu();
}

void menu_StartSplitManagement()
{
  menu_StartSimpleMenu(PSTR("Split Log"), splitMenuEntries, NUM_ENTRIES(splitMenuEntries));
}


////
void menu_DrawMasterReset()
{
  menu_DrawSimpleMenu();
}

void menu_StartMasterReset()
{
  menu_StartSimpleMenu(PSTR("Master Reset Menu"), masterResetEntries, NUM_ENTRIES(masterResetEntries));
}

void menu_ProcessMasterReset()
{
  KBDEvent *evt;
  
  data.masterResetMenu.clicked = 0;

  while(evt = kbd_getEvent()) {
          gui_ProcessEvent(evt);
/*
      if(IS_EXIT(evt)) {
          popStage();
        } else {
          gui_ProcessEvent(evt);
        }
*/

    }
  
  switch(data.masterResetMenu.clicked) {
      case SUBMENU_MASTERRESET_DISTANCE:
        vss_resetDistance(0);
        vss_snapshot(0);
        break;
      case SUBMENU_MASTERRESET_TIMER:
        break;
    }
  
  menu_DrawSimpleMenu();

}

////
void menu_DrawConfigMenu()
{
  menu_DrawSimpleMenu();
}

void menu_StartConfigMenu()
{
  menu_StartSimpleMenu(PSTR("Configuration Menu"), configMenuEntries, NUM_ENTRIES(configMenuEntries));
}

void menu_ProcessConfigMenu()
{
  menu_ProcessSimpleMenu();
}



void displayRow(const Font *font_p,
                pixcoord_t x,
                pixcoord_t y,
                pixcoord_t colwidth,
                const char **row,
                const char *separator,
                uint8_t cols,
                int8_t selected)
{
  uint8_t i;
  pixcoord_t tw;
  uint8_t fontHeight = pgm_read_byte(&font_p->maxHeight);
  
  for(i = 0; i < cols; ++i) {
      if(i > 0) {
          x += 3;
          x += gfx_DrawText(font_p, x, y + fontHeight + 4, separator);
          x += 3;
        }

      tw = gfx_TextLen(font_p, row[i]);
      
      if(i == selected) {
          gfx_Box(x, y, colwidth, fontHeight + 8, data.editing ? (GFX_BOX_ROUND|GFX_BOX_FILL) : GFX_BOX_ROUND );

          if(data.editing)
            gfx_TextMode(GFX_TEXTMODE_INVERSE, 1);

        } else {
          gfx_RectFill(x, y, colwidth, fontHeight + 8, 0);
        }


      gfx_DrawText(font_p, x + (colwidth - tw) / 2, y + fontHeight + 4, row[i]);
      
      x += colwidth;
      
      gfx_TextMode(GFX_TEXTMODE_INVERSE, 0);
    }

}

void menu_DrawDateTime()
{
  struct Date d;
  struct Time t;

  rtctimer_getTimeOfDay(&t);
  rtctimer_getDate(&d);
  
  char c1[10];
  char c2[10];
  char c3[10];
  
  const char *row[3] = { c1, c2, c3 };
  
  snprintf(c1, sizeof(c1), "%02d", t.hours);
  snprintf(c2, sizeof(c2), "%02d", t.minutes);
  snprintf(c3, sizeof(c3), "%02d", t.seconds);

  displayRow(&digits6x13, 30, 20, 30, row, ":", 3, data.selectedItem);
  
  snprintf(c1, sizeof(c1), "%02d", d.mday);
  snprintf(c2, sizeof(c2), "%s", rtctimer_getMonthName(d.month));
  snprintf(c3, sizeof(c3), "%d", d.year + 1900);
  
  displayRow(&david6, 30, 45, 26, row, "-", 3, data.selectedItem - 3);

//  snprintf(buf, sizeof(buf), "%02d-%s-%d", d.mday, rtctimer_getMonthName(d.month), d.year + 1900);
//  gfx_DrawText(&david6, 70, 40, buf);

}

void menu_StartDateTime()
{
  gfx_RectFill(0, 0, LCD_WIDTH, LCD_HEIGHT, 0);

  menu_TitleBar(PSTR("Date & Time Setup"), 1);

  menu_DrawDateTime();
  
  data.selectedItem = 0;
  data.editing = 0;
}

static uint8_t menu_ChangeDateTimeValue(uint8_t item, int8_t delta, uint8_t range)
{
  int8_t ret = item + delta;
  if(ret < 0)
    ret = range + ret;
  else
    ret %= range;

  return ret;
}

static void menu_ChangeDateTime(uint8_t item, int8_t delta)
{
  if(item < 3) {
      struct Time t;
      rtctimer_getTimeOfDay(&t);

      if(item == 0) {
          t.hours = menu_ChangeDateTimeValue(t.hours, delta, 24);
        } else if(item == 1) {
          t.minutes = menu_ChangeDateTimeValue(t.minutes, delta, 60);
        } else if(item == 2) {
          t.seconds = menu_ChangeDateTimeValue(t.seconds, delta, 60);
        }
      
      rtctimer_setTimeOfDay(&t);

    } else {
      struct Date d;
      rtctimer_getDate(&d);
      
      if(item == 3) {
          d.mday = menu_ChangeDateTimeValue(d.mday - 1, delta, rtctimer_getMonthNumberOfDays(d.year, d.month)) + 1;
        } else if(item == 4) {
          d.month = menu_ChangeDateTimeValue(d.month, delta, 12);
          uint8_t maxdays = rtctimer_getMonthNumberOfDays(d.year, d.month);
          if(d.mday > maxdays)
            d.mday = maxdays;
        } else if(item == 5) {
          d.year = menu_ChangeDateTimeValue(d.year, delta, 200);
        }
      
      rtctimer_setDate(&d);
    }
    
}


void menu_ProcessDateTime()
{
  KBDEvent *evt;
  
  while(evt = kbd_getEvent()) {
      if((evt->type == KBDEVENT_TYPE_REPEAT) && data.editing) {
          if(evt->key == KEY_DOWN)
            menu_ChangeDateTime(data.selectedItem, 1);
          else if(evt->key == KEY_UP)
            menu_ChangeDateTime(data.selectedItem, -1);
        }
      
      if(IS_EXIT(evt)) {
          popStage();
        }

      if(evt->type != KBDEVENT_TYPE_DOWN)
        continue;
      
      switch(evt->key) {
          case KEY_DOWN:
            if(data.editing) {

                menu_ChangeDateTime(data.selectedItem, 1);

              } else {
                if(data.selectedItem < 5)
                  ++data.selectedItem;
                else
                  data.selectedItem = 0;
              }
            break;
          case KEY_UP:
            if(data.editing) {

                menu_ChangeDateTime(data.selectedItem, -1);

              } else {
                if(data.selectedItem > 0)
                  --data.selectedItem;
                else
                  data.selectedItem = 5;
              }
            break;
          case KEY_ENTER:
            data.editing ^= 1;
            break;
        }
    }

  menu_DrawDateTime();
  
}

void menu_DrawCalibration(uint32_t distance)
{
  char buf[32];
  
  snprintf(buf, sizeof(buf), "%3d.%02d", (int) (distance / 1000) % 1000, (int) (distance % 1000) / 10);
  
  gfx_DrawText(&digits23c, 45, 48, buf);
  
  if(data.calibrationSettings.current)
    gui_ObjectUpdate((GUI_Object *) data.calibrationSettings.current);
}

void menu_StartCalibration()
{
  gfx_RectFill(0, 0, LCD_WIDTH, LCD_HEIGHT, 0);
  menu_TitleBar(PSTR("Vehicle Speed Sensor Calibration"), 1);
  
  data.calibrationSettings.distance = 0xffffffff;
  
  memcpy_P(&data.calibrationSettings.main, &caMainMenu, sizeof(GUI_Menu));
  data.calibrationSettings.main.entries_P = calibrationMenu;
  data.calibrationSettings.main.size = NUM_ENTRIES(calibrationMenu);

  memcpy_P(&data.calibrationSettings.confirm, &caConfirmMenu, sizeof(GUI_Menu));
  data.calibrationSettings.confirm.entries_P = calibrationConfirmationMenu;
  data.calibrationSettings.confirm.size = NUM_ENTRIES(calibrationConfirmationMenu);
  
  gui_FullUpdate(1);
  
  gui_ObjectSetFocus((GUI_Object *) &data.calibrationSettings.main);
  
  data.calibrationSettings.current = &data.calibrationSettings.main;
  
  
  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 1);
  gfx_DrawText(&david6, 3, 40, PSTR("Distance"));
  gfx_DrawText(&david6, 135, 48, PSTR("km"));
  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 0);

  char buf[32];
  snprintf(buf, sizeof(buf), "%lu", eeconfig.vss_distanceCalibrationData);
  
  gfx_DrawText(&david6, 3, 30, buf);
  
  vss_calibrationStart();
  
  menu_DrawCalibration(vss_calibrationDistance());
}

void menu_ProcessCalibration()
{
  KBDEvent *evt;
  
  if(data.calibrationSettings.current) {

      data.calibrationSettings.current->clicked = 0;

      while(evt = kbd_getEvent()) {
          if(IS_EXIT(evt))
            popStage();
          else
            gui_ProcessEvent(evt);
        }
        
      switch(data.calibrationSettings.current->clicked) {
          case SUBMENU_CALIBRATION_ADJUST:

            gfx_RectFill(data.calibrationSettings.current->obj.x, 
                         data.calibrationSettings.current->obj.y, 
                         data.calibrationSettings.current->obj.w, 
                         data.calibrationSettings.current->obj.h, 0);
            
            gfx_DrawText(&david6, 160, 25, "Adjust distance");
            gfx_DrawText(&david6, 160, 36, "using UP/DOWN");
            gfx_DrawText(&david6, 160, 47, "buttons and press");
            gfx_DrawText(&david6, 160, 58, "enter when done.");

            data.calibrationSettings.current = 0;
            gui_ObjectSetFocus(0);
            data.calibrationSettings.distance = vss_calibrationDistance();

            break;
          case SUBMENU_CALIBRATION_RESTART:
            vss_calibrationStart();
            break;

          case SUBMENU_CALIBRATION_CONFIRM:
            vss_calibrationSet(data.calibrationSettings.distance);
            popStage();
            break;
        }
      

    
    
    } else { // editing
    
      while(evt = kbd_getEvent()) {
          if(IS_EXIT(evt)) {

              popStage();

            } else if((evt->type == KBDEVENT_TYPE_DOWN) && (evt->key == KEY_ENTER)) {
            
              vss_calibrationEnd();
            
              data.calibrationSettings.current = &data.calibrationSettings.confirm;
              gui_ObjectSetFocus((GUI_Object *) data.calibrationSettings.current);

              gui_FullUpdate(1);

            } else if((evt->type == KBDEVENT_TYPE_DOWN) || (evt->type == KBDEVENT_TYPE_REPEAT)) {
              if(evt->key == KEY_DOWN) {
                  data.calibrationSettings.distance += 10;
                } else if(evt->key == KEY_UP) {
                  if(data.calibrationSettings.distance > 0) {
                      data.calibrationSettings.distance -= 10;
                    }
                }
            }
        }
    }
  
  menu_DrawCalibration((data.calibrationSettings.distance == 0xffffffff) ? vss_calibrationDistance() : data.calibrationSettings.distance);
}


void menu_DrawDisplaySettingsSelector()
{
  uint8_t ybox, yerase;
  
  if(data.displaySettings.selector) {
      ybox = data.displaySettings.slContrast.obj.y;
      yerase = data.displaySettings.slBrightness.obj.y;
    } else {
      yerase = data.displaySettings.slContrast.obj.y;
      ybox = data.displaySettings.slBrightness.obj.y;
    }
  
  gfx_Box(5, ybox, 50, 14, GFX_BOX_ROUND);
  gfx_RectFill(5, yerase, 50, 14, 0);
  
  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 1);
  gfx_DrawText(&david6, 9, 30, PSTR("Brightness"));
  gfx_DrawText(&david6, 12, 50, PSTR("Contrast"));
  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 0);
}


void menu_DrawDisplaySettings()
{
  gui_ObjectUpdate((GUI_Object *) &data.displaySettings.slBrightness);
  gui_ObjectUpdate((GUI_Object *) &data.displaySettings.slContrast);
}

void menu_StartDisplaySettings()
{
  gfx_RectFill(0, 0, LCD_WIDTH, LCD_HEIGHT, 0);
  menu_TitleBar(PSTR("Display Settings"), 1);

  memcpy_P(&data.displaySettings.slBrightness, &dsBrightness, sizeof(GUI_Slider));
  memcpy_P(&data.displaySettings.slContrast, &dsContrast, sizeof(GUI_Slider));
  
  data.displaySettings.slBrightness.value = eeconfig.gfx_Brightness;
  data.displaySettings.slContrast.value = eeconfig.gfx_Contrast;
  
  gui_FullUpdate(1);
  
  data.displaySettings.selector = 0;
  data.displaySettings.slPtr = &data.displaySettings.slBrightness;

  menu_DrawDisplaySettingsSelector();
  
  menu_DrawDisplaySettings();
}

void menu_ProcessDisplaySettings()
{
  KBDEvent *evt;
  
  while(evt = kbd_getEvent()) {
      if(IS_EXIT(evt)) {
          if((data.displaySettings.slBrightness.value != eeconfig.gfx_Brightness)
           || (data.displaySettings.slContrast.value != eeconfig.gfx_Contrast)) {
              eeconfig.gfx_Brightness = data.displaySettings.slBrightness.value;
              eeconfig.gfx_Contrast = data.displaySettings.slContrast.value;
              EE_SaveConfig();
            }
          popStage();
        }
        
      if((evt->type == KBDEVENT_TYPE_DOWN) || (evt->type == KBDEVENT_TYPE_REPEAT)) {
          if(evt->key == KEY_DOWN) {
              if(data.displaySettings.slPtr->value <= 250)
                data.displaySettings.slPtr->value += 5;
              
              
            } else if(evt->key == KEY_UP) {

              if(data.displaySettings.slPtr->value >= 5)
                data.displaySettings.slPtr->value -= 5;
            
            }
          
          RA6963_Backlight(data.displaySettings.slBrightness.value);
//          lc7981hw_contrast(data.displaySettings.slContrast.value);
          
          menu_DrawDisplaySettings();
        }
      
      if((evt->type == KBDEVENT_TYPE_DOWN) && (evt->key == KEY_ENTER)) {
          data.displaySettings.selector ^= 1;
          data.displaySettings.slPtr = data.displaySettings.selector ? &data.displaySettings.slContrast :
                                                                       &data.displaySettings.slBrightness;
          menu_DrawDisplaySettingsSelector();
        }

    }
  
  
}

