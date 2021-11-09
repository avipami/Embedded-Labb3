#include <avr/io.h>
#include "led.h"

void led_init() 
{
    DDRD |= (1 << PD6);
}
