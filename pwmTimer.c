#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "leds.h"

void initPWMTimer()
{
    TCCR2A |= (1 << WGM20) | (1 << WGM21) | (1 << COM2A1);//NonInvert mode and fast pwm active
    TCCR2B |= (1 << CS22); // prescale 64

}
void initTimer()
{
    TCCR0A |= (1 << WGM01);
    TCCR0B |= (1 << CS00) | (1 << CS02);
    OCR0A = 249; // ((CPU_HZ) / ( prescale * hz) -1)    16000000 / (1024 * 100)-1 = 249 
                //                                      15625 * 0.0160 = 250 -1 = 249
    TCNT0 = 0; // Counts until OCR0A is reached and then interrupts
}

int interruptCalculator(int mhz, int prescale, int interruptMs)
{
    return interruptMs*1000/16;
}


void setPWMOutput(int duty)
{
    OCR2A = duty;
}