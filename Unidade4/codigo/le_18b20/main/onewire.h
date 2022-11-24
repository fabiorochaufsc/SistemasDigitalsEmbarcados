#ifndef __ONE_WIRE__
#define __ONE_WIRE__
#include <inttypes.h> 
#include "digital.h"
#include "debug.h"



#define INICIA_CONVERSAO_TEMP 0x44
#define READ_TEMP_MEMORY 0xBE
#define SKIP_ROM 0xCC
#define READ_ROM 0x33

class ONEWIRE {

private:

	uint8_t tmp;
	gpio_num_t PIN_DADOS;
	void low (void);
	void high (void);
	void escreve_bit(uint8_t);

public:
	ONEWIRE(gpio_num_t p);
	void writeByte (uint8_t v);
	uint8_t readByte(void);
	void config (gpio_num_t pino);
	uint8_t reset (void);

};

#endif