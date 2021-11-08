#include <avr/io.h>
#include "timer.h"

void timer_init() 
{

    TCCR0A |= (1<<WGM01);
    TCCR0B |= (1<<CS02);
    TCCR0B |= (1<<CS00);
    OCR0A = 155;
    TIMSK0 |= _BV(OCIE0A); //Interrupt if a compare match in Timer/Counter0 occur
}

