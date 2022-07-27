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

#define TRANSMISSOR 1
#define RECEPTOR 0

int modo=RECEPTOR;

int main(void)
{
	SystemInit();

	uint8_t buffer[10];
	uint8_t bufferRecepcao[10];
	
	UART0_Init(9600);
	printf("Testando\n");

	radio.configura();
	printf("Retorno = %d\n ",radio.testa());

	if (modo==TRANSMISSOR)
	{
		sprintf((char *)buffer,"UFSC   ");
		radio.enviaMensagem(buffer,8);
	}
	else
	{
		uint8_t tamanho = radio.leMensagem(bufferRecepcao);

		bufferRecepcao[tamanho]=0;
		printf("Recebido= %s\n",(char *)bufferRecepcao
		);

	}
	while(1);

	return 0;
}
