#include <avr/io.h>
#include "timer.h"

/* Initialise timer.  */
void timer_init (void)
{
    /* TODO */
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCCR1C = 0x00;

}


/* Wait for the specified length of time.  */
void timer_delay_ms (uint16_t milliseconds)
{

    /* TODO: Calculate the timer/counter value needed
       for the given number of milliseconds. */
    float value = milliseconds * 0.001/0.000128;
    TCNT1 = 0;
    while (TCNT1 < value) {
        continue;
    }

    /* TODO: Wait for the timer/couter to reach the
       value calculated above.  */

}
