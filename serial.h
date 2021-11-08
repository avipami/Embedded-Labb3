#ifndef SERIAL_H
#define SERIAL_H

#define BAUDRATE 38400
#define UBRR (F_CPU/16/BAUDRATE-1)

void uart_init(void);
int uart_putchar(char chr, FILE *stream);
char uart_getchar(void);

#endif

