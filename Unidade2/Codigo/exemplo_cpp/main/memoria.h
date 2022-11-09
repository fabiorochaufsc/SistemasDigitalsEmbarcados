#ifndef __MEMORIA__
#define __MEMORIA__
#include <inttypes.h> 
#include "i2c.h"


class Memoria {

	public:
		Memoria(void);
		void init (uint8_t device);
		void escreve (uint16_t end, uint8_t b[], uint16_t tam);
		void le(uint16_t end, uint8_t b[], uint16_t tam);

	private:
		uint8_t dispositivoAlvo;
		void testa_eeprom_disponivel(void);
		I2C meuI2c;

};

#endif