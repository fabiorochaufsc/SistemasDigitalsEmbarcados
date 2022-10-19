
#include "i2c_software.h"
#include "digital.h"
#include "delay.h"
#include <stdio.h>
#include "uart.h"
#include "delay.h"

uint8_t PIN_DADOS;
uint8_t PIN_CLK;


void i2c_dados_baixo (void)
{
     pinMode(PIN_DADOS, OUTPUT);
     digitalWrite(PIN_DADOS,LOW);
}

void i2c_dados_alto (void)
{
     pinMode(PIN_DADOS, INPUT);
}

void i2c_clk_alto (void)
{
    pinMode(PIN_CLK, INPUT);
}

void i2c_clk_baixo (void)
{
     pinMode(PIN_CLK, OUTPUT);
     digitalWrite(PIN_CLK,LOW);
}

void i2c_configura (uint8_t pino_dados, uint8_t pino_clk)
{
    PIN_DADOS = pino_dados;
    PIN_CLK   = pino_clk;

    // configura como entrada/saida
    i2c_clk_alto();
    i2c_dados_alto();
	delay_ms(1);
}
void i2c_start (void)
{
     i2c_clk_alto();
     delay_us(10);
     i2c_dados_alto();
     delay_us(10);
     i2c_dados_baixo();
 	 delay_us(10);
     i2c_clk_baixo();
 	 delay_us(10);  
}

void i2c_bit (uint8_t valor_bit)
{
    if (valor_bit) i2c_dados_alto();
    else i2c_dados_baixo();
    _delay_us(10);
    i2c_clk_alto();
    _delay_us(10);
    i2c_clk_baixo();
    i2c_dados_alto();
}

uint8_t i2c_le_bit (void)
{
    uint8_t valor;

    i2c_dados_alto();
    delay_us(10);
    i2c_clk_alto();
    valor=digitalRead(PIN_DADOS);
    delay_us(10);
    i2c_clk_baixo();
    return valor;
}

uint8_t i2c_write (uint8_t valor_byte)
{
    uint8_t a,x;
    for (x=0;x<8;x++) i2c_bit(1&(valor_byte>>(7-x)));
	a=i2c_le_bit();

	delay_us(10);
    return a;
}

uint8_t i2c_read (void)
{
	uint8_t valor=0,x;
	
	for (x = 0; x < 8; x++) 
		valor = (valor << 1) | i2c_le_bit();
   return valor;
}

uint8_t i2c_read_ACK (uint8_t v)
{
	uint8_t valor=0,x;
	
	for (x = 0; x < 8; x++) valor = (valor << 1) | i2c_le_bit();
	i2c_bit(v);
   return valor;
}

void i2c_stop (void)
{     
      i2c_dados_baixo();
	  delay_us(5);
      i2c_clk_baixo();
      delay_us(5);
	  i2c_clk_alto();
	  delay_us(5);
      i2c_dados_alto();
	  delay_us(5);
}

void i2c_escreve_byte (uint8_t dispositivo, uint8_t end, uint8_t valor)
{
	
	i2c_start();
	    i2c_write (dispositivo);
	    i2c_write (end);
	    i2c_write (valor);
    i2c_stop();

	while (1)
    {
       i2c_start();
       if (i2c_write (dispositivo)==0) break;
    }
	i2c_stop();
}

uint8_t i2c_le_byte (uint8_t dispositivo, uint8_t end)
{
    uint8_t valor;

    i2c_start();
 	   i2c_write (dispositivo);
 	   i2c_write (end);
   i2c_start();
    i2c_write (dispositivo|1);
    valor = i2c_read();
    i2c_stop();
    return valor;
}