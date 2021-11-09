#include <avr/io.h>
#include "timer.h"

/*
Pins 5 and 6: controlled by Timer 0 in fast PWM mode (cycle length = 256)
Setting 	Divisor 	Frequency
0x01 	 	1 	 	62500
0x02  		8 	 	7812.5
0x03  		64 	 	976.5625   <--DEFAULT
0x04 	 	256 	 	244.140625
0x05 	 	1024 	 	61.03515625

TCCR0B = (TCCR0B & 0b11111000) | <setting>;

Pins 9 and 10: controlled by timer 1 in phase-correct PWM mode (cycle length = 510)
Setting 	Divisor 	Frequency
0x01 	 	1 	 	31372.55
0x02 	 	8 	 	3921.16
0x03  		64 	 	490.20   <--DEFAULT
0x04  		256 	 	122.55
0x05 	 	1024 	 	30.64

TCCR1B = (TCCR1B & 0b11111000) | <setting>;

Pins 11 and 3: controlled by timer 2 in phase-correct PWM mode (cycle length = 510)
Setting 	Divisor 	Frequency
0x01 	 	1  		31372.55
0x02 	 	8 	 	3921.16
0x03  		32  		980.39
0x04 	 	64 	 	490.20   <--DEFAULT
0x05 	 	128  		245.10
0x06  		256  		122.55
0x07 	 	1024  		30.64

TCCR2B = (TCCR2B & 0b11111000) | <setting>;

All frequencies are in Hz and assume a 16000000 Hz system clock.


*/

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

