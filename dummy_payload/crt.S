# See LICENSE for license details.

#include "mcall.h"

#ifdef __riscv64
# define LREG ld
# define SREG sd
# define REGBYTES 8
#else
# define LREG lw
# define SREG sw
# define REGBYTES 4
#endif

  .section ".text.init"
  .globl _start
_start:
  la s0, str
1:
  lbu a0, (s0)
  beqz a0, 1f
  li a7, SBI_CONSOLE_PUTCHAR
  ecall
  add s0, s0, 1
  j 1b

1:
  li a1, 0x88000000
  add sp, a1, -8
  j main
  li a7, SBI_SHUTDOWN
  ecall

  .data
str:
  .asciz "This is bbl's dummy_payload.  To boot a real kernel, reconfigure\n\
bbl with the flag --with-payload=PATH, then rebuild bbl.\n"
