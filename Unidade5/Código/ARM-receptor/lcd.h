#ifndef __LCD__
#define __LCD__
#include <stdint.h>
#include <stddef.h>

#include "LPC17xx.h"

#define RS PIN(2,12)
#define E  PIN(2,13)
#define D0 PIN(0,4)
#define D1 PIN(0,5)
#define D2 PIN(0,6)
#define D3 PIN(0,7)
#define D4 PIN(0,8)
#define D5 PIN(0,9)
#define D6 PIN(0,10)
#define D7 PIN(0,11)
void lcd_init (void);
void lcd_msg( const char *s);
void lcd_clear(void);

#endif
