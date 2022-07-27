#include "spi.h"
#include "digital.h"
#include "delay.h"




uint8_t PINO_CS, PINO_MISO, PINO_MOSI, PINO_SCK;

// configura os pinos de cs, miso, mosi, sck
void spi_configura (uint8_t pino_cs, uint8_t pino_miso, uint8_t pino_mosi, uint8_t pino_sck)
{
	PINO_CS   = pino_cs;
	PINO_MISO = pino_miso;
	PINO_MOSI = pino_mosi;
	PINO_SCK  = pino_sck;
	pinMode(PINO_CS, OUTPUT);
	pinMode(PINO_MISO, INPUT);
	pinMode(PINO_MOSI, OUTPUT);
	pinMode(PINO_SCK, OUTPUT);

	digitalWrite(PINO_SCK, LOW);
	digitalWrite(PINO_CS, HIGH);
}
void spi_habilita (void)
{
    digitalWrite(PINO_CS, LOW);
}

void spi_desabilita(void)
{
	digitalWrite(PINO_CS, HIGH);
}

// escreve um byte e retorna a resposta do escravo
uint8_t spi_write (uint8_t dado)
{
	uint8_t valor = 0, x, bit;

		// transmite....
		for (x=0;x<8;x++)
		{
			bit = (dado >> (7-x)) & 1;
			digitalWrite(PINO_MOSI, bit);
			digitalWrite(PINO_SCK, HIGH);
			delay_us(5);
			valor = (valor << 1 ) | digitalRead(PINO_MISO);
			digitalWrite(PINO_SCK, LOW);
			delay_us(5);
		}

		return valor;
}
