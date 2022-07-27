// EXEMPLO DE UM Pisca Pisca que usa a Lampada do kit
// para compilar:  
//                    make
// para gravar na placa (usando o bootloader): 
//                   lpc21isp -control -bin main.bin /dev/ttyUSB0 115200 12000
//
// para gravar na placa (usando o JTAG)
//                   openocd -f lpc1768.cfg
// abrir outro shell
// telnet localhost 4444
// > reset halt
// > flash write_image erase main.bin 0x0 bin
#include "LPC17xx.h"
#include <stdio.h>
#include <inttypes.h>
#include "uart.h"
#include "radio.h"
#include <string.h>
#include "delay.h"





#define modo_receptor 1

int main(void)
{
	SystemInit();

	uint8_t buffer[10];
	
	UART0_Init(9600);
	printf("Testando\n");

	radio.configura();

	// modo receptor	
	
	if (modo_receptor)
	{
		radio.modoRX();
		int qtd;
		while (1)
		{
			if (radio.temMensagem(BLOQ) )
			{
				qtd=radio.leMensagem(buffer);
				buffer[8] = 0;
				printf("buffer=%s\n",buffer);
			}
		}
		
	}
	else
	{
		while (1)
		{
			strcpy((char *) buffer,"oi mundo");
			radio.enviaMensagem(buffer, 8);
			delay_ms(2000);
		}
	}
	


	return 0;
}
