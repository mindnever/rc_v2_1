#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/window.h>
#include <gtkmm/main.h>

#include "guilock.h"
#include "kbd.h"

#include <list>

#define NUM_KEYS 4

volatile uint8_t kbd_eventCounter;

Conditional initSignal;
volatile bool initialized = false;
volatile unsigned int state;

pthread_mutex_t queueLock = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
std::list<KBDEvent> queue;

class MyButton: public Gtk::Button {
    public:
      MyButton(int id, const char *t): Gtk::Button(t), _id(id) {
          set_size_request(10, 10);
        }
      
      void on_pressed()
      {
        pthread_mutex_lock(&queueLock);
        state |= (1 << _id);
        KBDEvent event;
        event.type = KBDEVENT_TYPE_DOWN;
        event.key = _id;
        queue.push_back(event);
        pthread_mutex_unlock(&queueLock);
        Gtk::Button::on_pressed();
      }
      
      void on_released()
      {
        pthread_mutex_lock(&queueLock);
        state &= ~(1 << _id);
        KBDEvent event;
        event.type = KBDEVENT_TYPE_UP;
        event.key = _id;
        queue.push_back(event);
        pthread_mutex_unlock(&queueLock);

        Gtk::Button::on_released();
      }

    private:
      int _id;
  };

static int autoRepeat[NUM_KEYS] = { 0 };
static int autoRepeatQueued;


static void kbdemu_CheckRepeat() // this can be called from timer interrupt ?
{          
  
  for(int i = 0; i < NUM_KEYS; ++i) {
      if(state & (1 << i)) {

          if(autoRepeat[i] < 100) {

              ++autoRepeat[i];

            } else {
            
              if(!(autoRepeatQueued & (1 << i))) {
                  pthread_mutex_lock(&queueLock);
                  KBDEvent event;
                  event.type = KBDEVENT_TYPE_REPEAT;
                  event.key = i;
                  queue.push_back(event);
                  pthread_mutex_unlock(&queueLock);
                  
                  autoRepeatQueued |= (1 << i);
                }
            }

        } else {

          autoRepeat[i] = 0;

        }
    }
}


static void *kbdemu_main(void *ptr)
{
  try {
      
      char name[] = "kbdemu";
      char *namep = &name[0];
      char **fakeArgv = &namep;
      int fakeArgc = 1;
    
      Gtk::Main *gm = Gtk::Main::instance();
      if(!gm)
        gm = new Gtk::Main(fakeArgc, fakeArgv);

      
      Gtk::Window *win = new Gtk::Window();
      
      win->set_title("kbdemu");
      win->set_resizable(false);
      win->set_default_size(700, 40);
      win->set_size_request(700, 40);
      
      
      Gtk::HButtonBox *hbox = new Gtk::HButtonBox;
      win->add(*hbox);
      

      MyButton *buttons[NUM_KEYS];
      
      buttons[0] = new MyButton(KEY_MENU, "MENU/EXIT");
      buttons[1] = new MyButton(KEY_UP, "UP/REVERSE");
      buttons[2] = new MyButton(KEY_DOWN, "DOWN/PAUSE");
      buttons[3] = new MyButton(KEY_ENTER, "ENTER/SPLIT");
      
      
      for(int i = 0; i < NUM_KEYS; ++i) {
          hbox->add(*buttons[i]);
        }
      
      win->show_all();
      
      
      initialized = true;
      initSignal.wakeup();

      struct timespec ts;

      while(true) {
          guilock_Lock();
          
          if(gm->events_pending())
            gm->iteration(false);
          
          guilock_Unlock();

          ts.tv_sec = 0;
          ts.tv_nsec = 1;
          
          nanosleep(&ts, 0);
          
          kbdemu_CheckRepeat();

        }

    } catch(const std::exception &e) {
      printf("kbdemu_main: exception: %s", e.what());
      exit(1);
    }

  return 0;
}

void kbd_init()
{
  pthread_t thr;
  pthread_create(&thr, 0, kbdemu_main, 0);

  while(!initialized)
    initSignal.sleep();
}

KBDEvent *kbd_getEvent()
{
  static KBDEvent currentEvent;
  
  KBDEvent *ret = 0;
  pthread_mutex_lock(&queueLock);
  
  if(queue.empty()) {

      autoRepeatQueued = 0;
      
    } else {

      currentEvent = *queue.begin();
      ret = &currentEvent;

      queue.pop_front();
    }
  
  pthread_mutex_unlock(&queueLock);
  
  return ret;
}

