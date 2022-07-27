
#ifndef _SPI_
#define _SPI_

#include <inttypes.h>

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__)

#define OUTPUT 1
#include "Arduino.h"

#endif


void    spi_habilita (void);
void    spi_desabilita();
void    spi_configura (uint8_t pino_cs, uint8_t pino_miso, uint8_t pino_mosi, uint8_t pino_sck); 
uint8_t spi_write (uint8_t dado);

#endif
