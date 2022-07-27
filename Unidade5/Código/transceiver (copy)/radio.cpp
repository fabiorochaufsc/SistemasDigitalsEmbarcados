#include "radio.h"
#include "digital.h"
#include "spi.h"
#include "delay.h"

void RADIO::configura (void)
{
	uint8_t buffer[10];
	
	delay_ms(1000);
	spi.init(PIN1_25, PIN1_24, PIN1_23, PIN1_26);
	digital.pinMode(PIN1_22, OUTPUT);
	
	
	
	buffer[0]=0;
	escreveRegistrador (EN_AA, buffer, 1 );
	
	buffer[0]=1;
	escreveRegistrador (EN_RXADDR, buffer, 1 );
	
	
	buffer[0]=1;
	escreveRegistrador (SETUP_AW, buffer, 1 );
	
	buffer[0]=0;
	escreveRegistrador (SETUP_RETR, buffer, 1 );
	
	buffer[0]=0x27;
	escreveRegistrador (RF_SETUP, buffer, 1 );
	
	buffer[0]=1;
	buffer[1]=1;
	buffer[2]=1;	
	escreveRegistrador (RX_ADDR_P0, buffer, 3 );
	escreveRegistrador (TX_ADDR,    buffer, 3 );
	
	buffer[0]=TAM_MSG;
	escreveRegistrador (RX_PW_P0, buffer, 1 );
	
	buffer[0]=0x73;
	escreveRegistrador (CONFIG, buffer, 1 );
	delay_ms(10);
	
}
void RADIO::modoRX(void)
{
	uint8_t buffer[10];
	buffer[0]=0x72;
	escreveRegistrador (CONFIG, buffer, 1 );

}

void RADIO::modoTX(void)
{
uint8_t buffer[10];
	buffer[0]=0x7a;
	escreveRegistrador (CONFIG, buffer, 1 );
	digital.digitalWrite(PIN1_22, LOW);
}

void RADIO::carregaMensagem(uint8_t buffer[], int tam)
{
	spi.start();
		spi.write(0xa0);
		for (int x=0;x<TAM_MSG;x++) spi.write(buffer[0]);
	spi.stop();
}
void RADIO::enviaMensagem(uint8_t buffer[], int tam)
{
	carregaMensagem(buffer,tam);
	modoTX();
	digital.digitalWrite(PIN1_22, HIGH);
	delay_us(12);
	digital.digitalWrite(PIN1_22, LOW);
	delay_ms(10);
	modoRX();
	
}

int RADIO::temMensagem(int modo)
{
	uint8_t lido[5];
	while (1)
	{
		leRegistrador (STATUS, lido, 1);
		if ((lido[0]>>6) & 1)
		{
			return 1;
		}
		if (modo == N_BLOQ) return 0;
		delay_ms(1);
	}
}
int RADIO::leMensagem(uint8_t buffer[])
{
	spi.start();
		spi.write(0x61);
		for (int x=0;x<TAM_MSG;x++) buffer[x] = spi.write(0);
		return TAM_MSG;
	spi.stop();
}

void RADIO::escreveRegistrador(uint8_t reg, uint8_t buffer[], uint8_t tam)
{
	spi.start();
		spi.write(0x20 | reg);
		for (int x=0;x<tam;x++) spi.write(buffer[x]);
	spi.stop();
}

void RADIO::leRegistrador(uint8_t reg, uint8_t buffer[], uint8_t tam)
{
	spi.start();
		spi.write(0x00 | reg);
		for (int x=0;x<tam;x++) buffer[x] = spi.write(0);
	spi.stop();
}

RADIO radio;
