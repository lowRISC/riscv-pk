#ifndef _RISCV_UART_H
#define _RISCV_UART_H

#include <stdint.h>

extern volatile uint64_t* uart;

void uart_putchar(uint8_t ch);
int uart_getchar();
void query_uart(uintptr_t dtb);

#endif
