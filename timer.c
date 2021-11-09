#include <avr/io.h>
#include "timer.h"

void timer_init() {
    //Timer 0
    TCCR0A |= (1 << WGM01) | (1 << WGM00);
  
    
    TCCR0B |= (1 << CS01) | (1 << CS00);
    

    TCCR0A |= (1 << COM0A1);

    //Second Timer (Timer 2) as you see in the regname
    TCCR2A |= (1 << WGM21);

    TCNT2 = 0; // timer2 counter

    TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22);
  
    OCR2A = 155; // prescaler

    TIMSK2 |= (1 << OCIE2A); // Enable interrupt when Timer reaches OCRA
}

