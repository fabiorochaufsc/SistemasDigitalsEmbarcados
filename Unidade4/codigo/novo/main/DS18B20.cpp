#ifndef __DS18B20__
#define __DS18B20__

#include "DS18B20.h"
#include "delay.h"

void DS18B20::init (void)
{
	uint8_t serial[6],crc;
	delay_ms(500);

	printf("INIT\n");
	if (onewire->reset()==0) printf("Detectou escravo na linha\n");
	else printf("Nao detectou escravo\n");

	onewire->writeByte(READ_ROM);
	printf("Codigo da Familia: %d\n",onewire->readByte());
	for (uint8_t x=0;x<6;x++) serial[x] = onewire->readByte();

    printf("Numero de Serie  : %d %d %d %d %d %d\n",serial[0],serial[1],serial[2],serial[3],serial[4],serial[5]);

 	crc = onewire->readByte();
 	printf("CRC=             : %d\n",crc);

 	delay_ms(1000);


}


// Usa o pino GPIO16 para fazer a comunicacao
DS18B20::DS18B20 (gpio_num_t pino)
{
	DEBUG("DS18B20:Construtor\n");
	onewire = new ONEWIRE(pino);
}


float DS18B20::readTemp (void)
{
	float temperatura;

	uint8_t a,b,inteira;
	float frac;

	onewire->reset();
	onewire->writeByte(SKIP_ROM);
	onewire->writeByte(INICIA_CONVERSAO_TEMP);
	delay_ms(1000);
	onewire->reset();
	onewire->writeByte(SKIP_ROM);
	onewire->writeByte(READ_TEMP_MEMORY);
	a = onewire->readByte();
    b = onewire->readByte();
    inteira = (b<<4)|(a >> 4);


    	frac=((a & 1)*(0.0625))+ (((a>>1) & 1)*(0.125)) + (((a>>2) & 1)*(0.25)) + (((a>>3) & 1)*(0.5));
     
            temperatura = inteira + frac;
  return temperatura;     


	
}

#endif