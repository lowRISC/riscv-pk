#include <string.h>
#include "mtrap.h"
#include "uart.h"
#include "fdt.h"

volatile uint32_t* uart;

void uart_putchar(uint8_t ch)
{
  volatile uint32_t *tx = (volatile uint32_t *)uart_base_addr;
  *tx = ch;
}

int uart_getchar()
{
  volatile uint32_t *rx = (volatile uint32_t *)uart_base_addr;
  int32_t ch = *rx;
  if (ch < 0) return -1;
  return ch;
}
