#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>


#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"


int main (void) 
{
	timer_init();
	uart_init();
    button_init();
    sei();
	while (1) 
	{
	    button_func();
	    print_func();

	}
	return 0;
}

