#include "LPC17xx.h"
#include "delay.h"

#define ST_CTRL     (*((volatile unsigned long*)0xE000E010)) //page 783
volatile unsigned long sysTickCounter;

extern "C"
void SysTick_Handler (void);


//tratador de interrupcao

extern "C"
void SysTick_Handler(void) {
	if (sysTickCounter != 0x00) sysTickCounter--;
}


void habilita_timer()
{
	ST_CTRL |= 1<<1; // enable IRQ interrupt
    ST_CTRL |= 1; // enable systick	
}
void desabilita_timer()
{
	ST_CTRL &= 0xFFFFFFFC; // enable IRQ interrupt
}
 
void delay_us(uint32_t n) {

	desabilita_timer();

	SysTick_Config(SystemCoreClock / 1000000);
	sysTickCounter = n;
	habilita_timer();
	while (sysTickCounter != 0);
}
 

 
void delay_ms(uint32_t n) {
	desabilita_timer();
	SysTick_Config(SystemCoreClock / 1000);
	sysTickCounter = n;
	habilita_timer(); 
	while (sysTickCounter != 0);
}


