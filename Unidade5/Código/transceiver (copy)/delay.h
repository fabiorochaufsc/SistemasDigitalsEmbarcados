#ifndef _DELAY_
#define _DELAY_

#include <stdint.h>

#define _delay_ms(A) delay_ms(A)
#define _delay_us(A) delay_us(A)
 

void delay_ms(uint32_t n);
void delay_us(uint32_t n);


#endif
