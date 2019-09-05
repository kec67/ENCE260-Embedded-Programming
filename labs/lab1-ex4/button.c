#include "pio.h"
#include "button.h"

/** Return non-zero if button pressed.  */
int button_pressed_p (void)
{
    /* TODO.  */
    return PIND & (1 << 7);
}


/** Initialise button1.  */
void button_init (void)
{
    /* TODO.  */
    DDRD &= ~(1 << 7);
}
