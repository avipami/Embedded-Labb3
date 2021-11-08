#include "button.h"

bool pushed= false;
bool released= false;
bool button_interrupted = false;
bool timer_interrupted = false;

void button_init()
{
    DDRB |= (1<< PB0);
    PCICR |= (1<<PCIE0);
    PCMSK0 |= (1<<PCINT0);
}
ISR(PCINT0_vect)
{ //Interrupt ISR
    button_interrupted = true;
}

ISR(TIMER0_COMPA_vect)
{ //Interrupt Timer0 ISR
    timer_interrupted = true;
}

void button_func()
{
    if(button_interrupted)
    {
        if (PINB & (1 << PB0)) 
        {
            pushed = true;
        }
        else if(!(PINB & (1 << PB0)))
        {
            released = true;
        }
        TCNT0 = 0;
        button_interrupted = false;
    }
}

void print_func()
{
    if(timer_interrupted)
    {
        if(pushed){
            if(PINB & _BV(PB0))
            {
                printf_P(PSTR("Pushed\r\n"));
            }
            pushed = false;
        }
        else if(released)
        {
            if(!(PINB & _BV(PB0)))
            {
                printf_P(PSTR("Released\r\n"));
            }
            released = false;
        }
    }
}