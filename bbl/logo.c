#include <string.h>
#include "mtrap.h"

extern const char logo[];

// LowRISC VGA-compatible display base address
static volatile uint16_t *const hid_vga_ptr = (uint16_t *)vga_base_addr;

static int addr_int;

static void logo_putchar(unsigned char ch)
{
  enum {colour=0xC00};
  int lmt, blank = ' '|colour;
  if (ch==10)
    {
      int lmt = (addr_int|127)+1; while (addr_int < lmt) hid_vga_ptr[(addr_int++)] = blank;
    }
  else if (ch != 13)
    hid_vga_ptr[addr_int++] = ch|colour;
}

void print_logo()
{
  const char *ptr = logo;
  addr_int = 0;
  while (*ptr) logo_putchar(*ptr++);
}
