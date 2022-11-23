#ifndef __I2C_SOFTWARE_
#define __I2C_SOFTWARE_
#include "driver/gpio.h"
#include <inttypes.h> 

class I2C {
	public:
		void configura   (gpio_num_t pino_dados, gpio_num_t pino_clk);
		void start(void);
		void stop(void);
		uint8_t write (uint8_t valor_byte);
		uint8_t read (void);
	private:
		void dados_baixo (void);
		void dados_alto (void);
		void clk_alto (void);
		void clk_baixo (void);
		void bit (uint8_t valor_bit);
		uint8_t le_bit (void);
		uint8_t read_ACK (uint8_t v);
;

};







#endif