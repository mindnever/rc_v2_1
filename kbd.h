#ifndef _KBD_H_
#define _KBD_H_

#include <drivers/hwdep.h>

#ifdef __cplusplus
extern "C" {
#endif

#define KBD_NUM_KEYS 4

enum {
    KEY_1 = 0,
    KEY_2 = 1,
    KEY_3 = 2,
    KEY_4 = 3,

  // functions
    KEY_MENU = KEY_3,
    KEY_REVERSE = KEY_2,
    KEY_PAUSE = KEY_1,
    KEY_SPLIT = KEY_4,
    
  // alternate
    KEY_EXIT = KEY_4,
    KEY_UP = KEY_1,
    KEY_DOWN = KEY_2,
    KEY_ENTER = KEY_3
  };

enum {
    KBDEVENT_TYPE_NOP,
    KBDEVENT_TYPE_DOWN,
    KBDEVENT_TYPE_UP,
    KBDEVENT_TYPE_REPEAT,
  };

typedef struct {
    uint8_t type;
    uint8_t key;
  } KBDEvent;

#define IS_EXIT(e) ((e->type == KBDEVENT_TYPE_DOWN) && (e->key == KEY_EXIT))

void kbd_init();
void kbd_scan();

KBDEvent *kbd_getEvent();

extern volatile uint8_t kbd_eventCounter;

#ifdef __cplusplus
  }; /* extern "C" */
#endif


#endif /* _KBD_H_ */
