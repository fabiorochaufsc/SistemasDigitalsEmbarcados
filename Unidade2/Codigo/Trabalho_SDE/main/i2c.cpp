
#include "i2c.h"
#include "digital.h"
#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "digital.h"

gpio_num_t PIN_DADOS;
gpio_num_t PIN_CLK;

#define delay_us(A) ets_delay_us(2*A)
#define delay_ms(A) vTaskDelay(500/portTICK_PERIOD_MS)



void I2C::dados_baixo (void)
{
     digital.pinMode(PIN_DADOS, OUTPUT);
     digital.digitalWrite(PIN_DADOS,LOW);
}

void I2C::dados_alto (void)
{
     digital.pinMode(PIN_DADOS, INPUT);
}

void I2C::clk_alto (void)
{
    digital.pinMode(PIN_CLK, INPUT);
}

void  I2C::clk_baixo (void)
{
     digital.pinMode(PIN_CLK, OUTPUT);
     digital.digitalWrite(PIN_CLK,LOW);
}

void  I2C::configura (gpio_num_t pino_dados, gpio_num_t pino_clk)
{
    PIN_DADOS = pino_dados;
    PIN_CLK   = pino_clk;

    // configura como entrada/saida
    clk_alto();
    dados_alto();
	delay_ms(1);
}
void  I2C::start (void)
{
     clk_alto();
     delay_us(10);
     dados_alto();
     delay_us(10);
     dados_baixo();
 	 delay_us(10);
     clk_baixo();
 	 delay_us(10);  
}

void  I2C::bit (uint8_t valor_bit)
{
    if (valor_bit) dados_alto();
    else dados_baixo();
    delay_us(10);
    clk_alto();
    delay_us(10);
    clk_baixo();
    dados_alto();
}

uint8_t I2C::le_bit (void)
{
    uint8_t valor;

    dados_alto();
    delay_us(10);
    clk_alto();
    valor=digital.digitalRead(PIN_DADOS);
    delay_us(10);
    clk_baixo();
    return valor;
}

uint8_t I2C::write (uint8_t valor_byte)
{
    uint8_t a,x;
    for (x=0;x<8;x++) bit(1&(valor_byte>>(7-x)));
	a=le_bit();

	delay_us(10);
    return a;
}

uint8_t I2C::read (void)
{
	uint8_t valor=0,x;
	
	for (x = 0; x < 8; x++) 
		valor = (valor << 1) | le_bit();
   return valor;
}

uint8_t I2C::read_ACK (uint8_t v)
{
	uint8_t valor=0,x;
	
	for (x = 0; x < 8; x++) valor = (valor << 1) | le_bit();
	bit(v);
   return valor;
}

void I2C::stop (void)
{     
      dados_baixo();
	  delay_us(5);
      clk_baixo();
      delay_us(5);
	  clk_alto();
	  delay_us(5);
      dados_alto();
	  delay_us(5);
}
