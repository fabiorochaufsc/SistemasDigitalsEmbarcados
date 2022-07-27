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

#include <stdio.h>

#include "LPC17xx.h"
#include <stdint.h>
#include "delay.h"
#include "uart.h"
#include "nrf24.h"



int main() {
  
  SystemInit();
  UART0_Init(9600);

  

uint8_t buffer[50];

	nrf24_init();

	
	printf("Rodando receptor...\n");


	while(1)
	{
		

		//codigo para o receptor
		nrf24_recebe(buffer);
		buffer[TAMANHO_MSG]=0;
		printf("recebido=%s\n",(char *)buffer);
		
	}

}














