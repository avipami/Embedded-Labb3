#include "adc.h"

 void adc_init(void) {
    /*
    The ADMUX(ADC Multiplexer Selection Register) controls the reference voltage, 
    the presentation of the ADC conversion(left adjust or right adjust) and analog channel
    
    
    Set ADEN bit in ADCSRA to enable ADC
    Set ADIE bit in ADCSRA to enable ADC interrupt
    */

    DDRC &= ~(1 << PC0);
    ADMUX |= (1 << ADLAR) | (1 << REFS0);
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1);
    ADCSRA |= (1 << ADEN) | (1 << ADIE);
}