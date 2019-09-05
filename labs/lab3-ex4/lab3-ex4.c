#include "system.h"
#include "button.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font3x5_1.h"


static bool run;

static void button_task ()
{
    button_update ();

    if (button_push_event_p (BUTTON1))
    {
        run = !run;
    }
}

static void display_task ()
{
    tinygl_update ();
}



static void timer_task ()
{
    static uint16_t time;
    char str[3];

    if (!run)
    {
        time = 0;
        return;
    }

    str[0] = ((time / 10) % 10) + '0';
    str[1] = (time % 10) + '0';
    str[2] = 0;

    tinygl_text (str);

    time++;
}


int main (void)
{
    system_init();

    /* TODO: Initialise the button driver, tinygl, and the pacer.  */
    button_init();
    pacer_init(1000);
    tinygl_init(250);
    tinygl_font_set (&font3x5_1);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    tinygl_text ("00");

    uint16_t counter = 0;

    while(1)
    {
        pacer_wait();
          /* TODO: Implement the functionality of the tasks in the
           stopwatch1 program.  */
        if (counter % 10 == 0) {

            timer_task();
            button_task();
        }
        if (counter % 4 == 0) {
            display_task();
        }




    counter ++;

    }
    return 0;
}
