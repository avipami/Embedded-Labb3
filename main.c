#define F_CPU                          16000000UL
#define YouSpinMeRoundRoundBabyRoundRound 1
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "serial.h"
#include "leds.h"
#include "pwmTimer.h"


uint8_t simpleRamp(int *direction, int *pwm)
{
    if (*pwm == 0x00 || *pwm == 0xFF)
    {
        *direction *= -1;
    }
    *pwm += *direction;
    return *pwm; // but why ?
}


int main() 
{
    int direction = -1;
    uint8_t pwm = 0;
    leds_init();
    initTimer();
    initPWMTimer();

    while(YouSpinMeRoundRoundBabyRoundRound)
    {
        if (TIFR0 & (1 << OCF0A)) //increment every time the timer raises a flag
        {
			TIFR0 |= (1 << OCF0A); // clears the flag and resets
            pwm = simpleRamp(&direction, &pwm);
            setPWMOutput(pwm);
		}
    }
    return 0;
}
