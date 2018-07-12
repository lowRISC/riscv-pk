#include <string.h>
#include "mtrap.h"
#include "uart.h"
#include "fdt.h"

// LowRISC simple UART base address
volatile uint64_t *uart;

void uart_putchar(uint8_t ch)
{
  while (*uart & 0x400)
    ;
  *uart = ch;
}

int uart_getchar()
{
  return -1;
}

void query_uart(uintptr_t fdt)
{
  uart = (uint64_t *)uart_base_addr;
}
