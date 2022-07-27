
#include "digital.h"



LPC_GPIO_TypeDef      * vet[5]={LPC_GPIO0,LPC_GPIO1,LPC_GPIO2,LPC_GPIO3,LPC_GPIO4};


void pinMode (uint8_t pb, uint8_t tipo)
{

	
	uint8_t porta = pb >> 5;
	uint8_t bit = pb & 31;
	if (tipo == OUTPUT) vet[porta]->FIODIR |= (1 << bit);
	else vet[porta]->FIODIR &= (~(1 << bit));
	
}
void digitalWrite( uint8_t pb, uint8_t valor)
{
	uint8_t porta = pb >> 5;
	uint8_t bit = pb & 31;
	
	if (valor==HIGH)
		    vet[porta]->FIOSET = (1 << bit);
	else 
		    vet[porta]->FIOCLR = (1 << bit);
}


uint8_t digitalRead (uint8_t pb)
{
	uint8_t porta = pb >> 5;
	uint8_t bit = pb & 31;
	 return ( (   ((vet[porta]->FIOPIN) >>  bit)  & 1)) ;
	
}






