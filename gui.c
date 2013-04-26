#include "gui.h"
#include "main.h"
#include "Font_david6.h"

static uint8_t fullUpdate;
static GUI_Object *focus;

#define SLIDER_KNOB_WIDTH 7

void gui_UpdateSlider(GUI_Slider *slider)
{

  if(fullUpdate || (slider->_oldValue != slider->value)) {
      pixcoord_t x = (((slider->obj.w - SLIDER_KNOB_WIDTH - 4) * slider->_oldValue) / 256) + 2;
      gfx_RectFill(x, 2, SLIDER_KNOB_WIDTH, slider->obj.h - 4, 0);

      x = (((slider->obj.w - SLIDER_KNOB_WIDTH - 4) * slider->value) / 256) + 2;
      gfx_Box(x, 2, SLIDER_KNOB_WIDTH, slider->obj.h - 4, GFX_BOX_FILL);
      
      gfx_ClearPixel(x, 2);
      gfx_ClearPixel(x + SLIDER_KNOB_WIDTH - 1, 2);
      gfx_ClearPixel(x, slider->obj.h - 3);
      gfx_ClearPixel(x + SLIDER_KNOB_WIDTH - 1, slider->obj.h - 3);
      
      slider->_oldValue = slider->value;
    }
}

void gui_ProcessSlider(GUI_Slider *slider, KBDEvent *evt)
{
}

void gui_UpdateMenu(GUI_Menu *menu)
{
  pixcoord_t yoffset = ((menu->obj.h - (menu->size * 11)) / 2) + 10;
  pixcoord_t x, tw, y;
  
  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 1);
  
  if(fullUpdate) {
    y = yoffset;
    
    menu->_oldSelection = 0xff;
    
    uint8_t i;
  
    for(i = 0; i < menu->size; ++i) {
        
        if(i != menu->_currentSelection && i != menu->_oldSelection) {

            tw = gfx_TextLen(&david6, pgm_read_ptr(&menu->entries_P[i].title));
            
            x = (menu->obj.w - tw) / 2;

            gfx_DrawText(&david6, x, y, pgm_read_ptr(&menu->entries_P[i].title));
          }

        y += 11;
      }
    }
  
  if(menu->_oldSelection != menu->_currentSelection) {

      if(menu->_oldSelection != 0xff) {
          tw = gfx_TextLen(&david6, pgm_read_ptr(&menu->entries_P[menu->_oldSelection].title));
        
          x = (menu->obj.w - tw) / 2;
      
          y = yoffset + (menu->_oldSelection * 11);

//          gfx_RectFill(x - 5, y - 9, tw + 10, 11, 0);
          gfx_RectFill(1, y - 9, menu->obj.w - 2, 11, 0);// full width 
          gfx_DrawText(&david6, x, y, pgm_read_ptr(&menu->entries_P[menu->_oldSelection].title));
        }

      if(menu->_currentSelection != 0xff) {
          tw = gfx_TextLen(&david6, pgm_read_ptr(&menu->entries_P[menu->_currentSelection].title));

          x = (menu->obj.w - tw) / 2;

          y = yoffset + (menu->_currentSelection * 11);

//          gfx_Box(x - 5, y - 9, tw + 10, 11, GFX_BOX_ROUND | GFX_BOX_FILL);
          gfx_Box(1, y - 9, menu->obj.w - 2, 11, GFX_BOX_ROUND | GFX_BOX_FILL);
          gfx_TextMode(GFX_TEXTMODE_INVERSE, 1);
          gfx_DrawText(&david6, x, y, pgm_read_ptr(&menu->entries_P[menu->_currentSelection].title));
          gfx_TextMode(GFX_TEXTMODE_INVERSE, 0);
        }

      menu->_oldSelection = menu->_currentSelection;
    }

  gfx_TextMode(GFX_TEXTMODE_PGMSPACE, 0);
}

void gui_ProcessMenu(GUI_Menu *menu, KBDEvent *evt)
{
  if(evt->type == KBDEVENT_TYPE_DOWN) {
      switch(evt->key) {
          case KEY_UP:
            if(menu->_currentSelection > 0) {
                --menu->_currentSelection;
              }
            break;
          case KEY_DOWN:
            if(menu->_currentSelection < (menu->size - 1)) {
                ++menu->_currentSelection;
              }
            break;
          case KEY_ENTER:
            {
              uint8_t i;
              uint8_t tmpsel = menu->_currentSelection;
              
              for(i = 0; i < 2; ++i) {
                  menu->_currentSelection = 0xff;
                  menu->_oldSelection = tmpsel;
                  gui_ObjectUpdate((GUI_Object *) menu);
                  delay_ms(100);
                  menu->_currentSelection = tmpsel;
                  gui_ObjectUpdate((GUI_Object *) menu);
                  delay_ms(100);
                }
                
            }
            
            uint8_t action = pgm_read_byte(&menu->entries_P[menu->_currentSelection].action);
            
            if(action & 0x80) // stage
              pushStage(action & 0x7f);
            else
              menu->clicked = action;

            break;
        }
      
      
    }
}


////////////// public


void gui_FullUpdate(uint8_t flag)
{
  fullUpdate = flag;
}

void gui_ObjectUpdate(GUI_Object *obj)
{
  gfx_PushActiveWindow(obj->x, obj->y);
  
  if(fullUpdate) {
      gfx_RectFill(0, 0, obj->w, obj->h, 0);

      if(obj->flags & GUIF_HAS_FRAME)
        gfx_Box(0, 0, obj->w, obj->h, GFX_BOX_ROUND);
    }


  switch(obj->type) {
      case GUI_TYPE_SLIDER:
        gui_UpdateSlider((GUI_Slider *) obj);
        break;
      case GUI_TYPE_MENU:
        gui_UpdateMenu((GUI_Menu *) obj);
        break;
    }

  gfx_PopActiveWindow();
}

void gui_ObjectSetFocus(GUI_Object *obj)
{
  focus = obj;
}

void gui_ProcessEvent(KBDEvent *evt)
{
  if(!focus)
    return;
  
  switch(focus->type) {
      case GUI_TYPE_SLIDER:
        gui_ProcessSlider((GUI_Slider *) focus, evt);
        break;
      case GUI_TYPE_MENU:
        gui_ProcessMenu((GUI_Menu *) focus, evt);
        break;
    }
}
