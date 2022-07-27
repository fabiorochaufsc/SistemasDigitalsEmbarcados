
#include "digital.h"
#include <stdint.h>
#include <stdio.h>

#include "spi.h"
#include "delay.h"





void SPI::init (uint8_t MISO, uint8_t MOSI, uint8_t SCK, uint8_t CS)
{
	miso = MISO;
	mosi = MOSI;
	sck  = SCK;
	cs   = CS;
	digital.pinMode(cs,   OUTPUT);
	digital.pinMode(mosi, OUTPUT);
	digital.pinMode(sck,  OUTPUT);
	digital.pinMode(miso, INPUT);
	digital.digitalWrite(mosi, LOW);
	digital.digitalWrite(sck,  LOW);
	digital.digitalWrite(cs,   HIGH);
}

void SPI::start (void)
{
	digital.digitalWrite(cs, LOW);
}

void SPI::stop (void)
{
	digital.digitalWrite(cs, HIGH);
}

uint8_t SPI::write (uint8_t valor)
{
	uint8_t bit, recebido = 0, bit_resposta;
	for (int x=0;x<8;x++)
	{
		bit = (valor>>(7-x)) & 1;
		digital.digitalWrite(mosi, bit);
		digital.digitalWrite(sck, HIGH);
		bit_resposta  = digital.digitalRead(miso);
		delay_us(50);
		digital.digitalWrite(sck, LOW);
		//bit_resposta  = digital.digitalRead(miso);
		
		recebido = (recebido << 1) | bit_resposta; 
		delay_us(50);
	}
	return recebido;
}

SPI spi;

