
#include <inttypes.h>

#ifndef __SPI__
#define __SPI__

class SPI {

	private:
		uint8_t cs, miso, mosi, sck;
		void delay (void);
		
	public:
		void     init ( uint8_t MISO, uint8_t MOSI, uint8_t SCK, uint8_t CS); 
		uint8_t  write (uint8_t valor);
		void     start (void);
		void     stop (void);

};

extern SPI spi;



#endif
