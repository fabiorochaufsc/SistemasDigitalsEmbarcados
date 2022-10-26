#ifndef __I2C_SOFTWARE_
#define __I2C_SOFTWARE_
#include "driver/gpio.h"
#include <inttypes.h> 


void     i2c_configura        (gpio_num_t pino_dados, gpio_num_t pino_clk);
void     i2c_start(void);
void     i2c_stop(void);


uint8_t i2c_write (uint8_t valor_byte);
uint8_t i2c_read (void);


// Le e escreve apenas 1 byte
void     i2c_escreve_byte     (uint8_t dispositivo, uint16_t end, uint8_t valor);
uint8_t  i2c_le_byte          (uint8_t dispositivo, uint16_t end);


// le e escreve um vetor de bytes
uint16_t i2c_sequencial_read  (uint8_t dispositivo, uint16_t end, uint8_t b[], uint16_t qtd);
uint16_t i2c_sequencial_write (uint8_t dispositivo, uint16_t end, uint8_t b[], uint16_t qtd);

#endif