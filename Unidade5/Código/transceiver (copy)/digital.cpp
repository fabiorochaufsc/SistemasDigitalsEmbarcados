
#include "digital.h"

 DIGITAL digital;

void DIGITAL::digitalWrite(uint8_t portabit, uint8_t valor)
{
	uint8_t porta = portabit >> 5;
    uint8_t bit   = portabit & 31;

	if (valor == HIGH)
	{
		switch (porta)
		{
			case 0:
				 LPC_GPIO0->FIOSET |= (1 << bit); 
				break;
			case 1:
				LPC_GPIO1->FIOSET |= (1 << bit);
				break;
			case 2:
				 LPC_GPIO2->FIOSET |= (1 << bit);
				break;
			case 3:
				 LPC_GPIO3->FIOSET |= (1 << bit);
				break;
			case 4:
				 LPC_GPIO4->FIOSET |= (1 << bit);    
				break;
		}
	}
	else
	{
		switch (porta)
		{
			case 0:
				 LPC_GPIO0->FIOCLR |= (1 << bit); 
				break;
			case 1:
				LPC_GPIO1->FIOCLR |= (1 << bit);
				break;
			case 2:
				 LPC_GPIO2->FIOCLR |= (1 << bit);
				break;
			case 3:
				 LPC_GPIO3->FIOCLR |= (1 << bit);
				break;
			case 4:
				 LPC_GPIO4->FIOCLR |= (1 << bit);    
				break;
		}
	}






}

uint8_t DIGITAL::digitalRead(uint8_t portabit )
{
     uint8_t porta = portabit >> 5;
     uint8_t bit   = portabit & 31;

     switch (porta)
		{
			case 0:
				 return (((LPC_GPIO0->FIOPIN) >> bit) & 1); 
				break;
			case 1:
				 return (((LPC_GPIO1->FIOPIN) >> bit) & 1); 
				break;
			case 2:
				 return (((LPC_GPIO2->FIOPIN) >> bit) & 1); 
				break;
			case 3:
				 return (((LPC_GPIO3->FIOPIN) >> bit) & 1); 
				break;
			case 4:
				 return (((LPC_GPIO4->FIOPIN) >> bit) & 1);     
				break;
			default:return 0;
		}

}



void DIGITAL::pinMode(uint8_t portabit, uint8_t modo)
{

	uint8_t porta = portabit >> 5;
    uint8_t bit   = portabit & 31;

	if (modo == OUTPUT)
	{
		switch (porta)
		{
			case 0:
				 LPC_GPIO0->FIODIR |= (1 << bit); 
				break;
			case 1:
				LPC_GPIO1->FIODIR |= (1 << bit);
				break;
			case 2:
				 LPC_GPIO2->FIODIR |= (1 << bit);
				break;
			case 3:
				 LPC_GPIO3->FIODIR |= (1 << bit);
				break;
			case 4:
				 LPC_GPIO4->FIODIR |= (1 << bit);    
				break;
		}
	}
	else 
	{
		switch (porta)
		{
			case 0:
				 LPC_GPIO0->FIODIR &= ~(1 << bit); 
				break;
			case 1:
				 LPC_GPIO1->FIODIR &= ~(1 << bit); 
				break;
			case 2:
				 LPC_GPIO2->FIODIR &= ~(1 << bit); 
				break;
			case 3:
				 LPC_GPIO3->FIODIR &= ~(1 << bit); 
				break;
			case 4:
				 LPC_GPIO4->FIODIR &= ~(1 << bit); 
				break;
		}
	}


}















