#include "memoria.h"
#include "i2c.h"
#include "digital.h"

 Memoria::Memoria (void)
{
	printf("Chama o construtor\n");
	meuI2c = I2C();
}

void Memoria::testa_eeprom_disponivel (void)
{
	uint8_t dev = 0x50 | dispositivoAlvo;

    for (;;)
    {
      meuI2c.start();
      int ack = meuI2c.write ((dev << 1));
      if (ack==0)  return;
    }
   
  
}
void Memoria::init (uint8_t device)
{
		dispositivoAlvo = device;
		meuI2c.configura (PIN16,PIN5);


}

void Memoria::escreve (uint16_t end, uint8_t b[], uint16_t tam)
{

	uint8_t dev = 0x50 | dispositivoAlvo;
	uint16_t endAtual = end; 
	for (int a=0;a< tam;a++)
	{
		 testa_eeprom_disponivel();
		 meuI2c.start();
    		meuI2c.write ( (dev << 1) | 0);
    		meuI2c.write (endAtual>>8);
    		meuI2c.write (endAtual);
    		meuI2c.write (b[a]);
  		meuI2c.stop();
  		endAtual++;
	}
}

void Memoria::le (uint16_t end, uint8_t b[], uint16_t tam)
{
	uint8_t dev = 0x50 | dispositivoAlvo;
	uint16_t endAtual = end;
	testa_eeprom_disponivel(); 

	for (int a=0;a< tam;a++)
	{
		 
		 meuI2c.start();
    		meuI2c.write ( (dev << 1) | 0);
    		meuI2c.write (endAtual>>8);
    		meuI2c.write (endAtual);
    	 meuI2c.start();
    	 meuI2c.write ((dev << 1)|1);
    	 b[a] = meuI2c.read();
         meuI2c.stop();
  		endAtual++;
	}

}