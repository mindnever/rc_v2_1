#ifndef _RC2_GUI_H_
#define _RC2_GUI_H_

#include <gfx/gfx.h>
#include "kbd.h"

enum {
    GUI_TYPE_SLIDER,
    GUI_TYPE_MENU,
  };

enum {
    GUIF_HAS_FRAME = (1 << 0),
  };

typedef struct {
    uint8_t type;
    uint8_t flags;
    pixcoord_t x, y;
    pixcoord_t w, h;
  } GUI_Object;


typedef struct {
    GUI_Object obj;
    uint8_t value; // 0 - 255
    uint8_t _oldValue;
  } GUI_Slider;

#define GUI_ACTION_STAGE(x) (0x80 | (x))
#define GUI_ACTION_EVENT(x) (x)

typedef struct {
    const char *title;
    uint8_t action;
  } GUI_MenuEntry;

typedef struct {
    GUI_Object obj;
    const GUI_MenuEntry *entries_P; // in progmem!
    uint8_t size;
    uint8_t clicked;

    uint8_t _currentSelection;
    uint8_t _oldSelection;
    
  } GUI_Menu;

void gui_FullUpdate(uint8_t flag);

void gui_ObjectSetFocus(GUI_Object *obj);
void gui_ObjectUpdate(GUI_Object *obj);

void gui_ProcessEvent(KBDEvent *evt);

#endif /* _RC2_GUI_H_ */
