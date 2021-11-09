
#ifndef BUTTON_H
#define BUTTON_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdbool.h>

void button_init();
void button_func();
void print_func();

#endif 