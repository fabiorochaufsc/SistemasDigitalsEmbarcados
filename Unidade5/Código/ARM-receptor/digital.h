#ifndef __DIGITAL__
#define __DIGITAL__
#include <stdint.h>


#include "LPC17xx.h"


#define PIN(P,B) ((P<<5)|B)
#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0

void pinMode( uint8_t portbit, uint8_t bitVal );
void digitalWrite( uint8_t portbit, uint8_t valor );
uint8_t digitalRead (uint8_t portbit);





#endif
