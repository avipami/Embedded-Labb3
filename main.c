#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>


#include "adc.h"
#include "led.h"
#include "timer.h"
#include "serial.h"
#include "button.h"


volatile uint8_t adc_value = 0; //volatile is a keyword that must be applied when 
                                //declaring any variable that will reference a device register.
ISR(ADC_vect)
{
    adc_value = ADCH;//adch data register
}
ISR(TIMER2_COMPA_vect)
{
    ADCSRA |= (1 << ADSC);
    OCR0A = adc_value;
}

int main (void) 
{
    adc_init(); 
	led_init();
	uart_init();
	timer_init();
    button_init();
    sei();

	while (true) 
    {
	}
	return 0;
}



