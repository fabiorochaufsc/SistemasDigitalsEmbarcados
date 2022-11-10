
#include "serial.h"

void Serial::begin (int v){
    uart_config_t uart_config = {
        .baud_rate = v,                      //Bluetooth baud rate 
        .data_bits = UART_DATA_8_BITS,          //8 data bits 
        .parity    = UART_PARITY_DISABLE,       //No parity 
        .stop_bits = UART_STOP_BITS_1,          //1 stop bit 
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE   //No hardware flow 
    };
    
    uart_param_config(UART_NUM_0, &uart_config); 
}
char Serial::readChar(void)
{
	int c;
	while (getchar() != EOF) vTaskDelay(pdMS_TO_TICKS(50)); //ticks para ms
	c = EOF;
	while (c == EOF) c = getchar();
	return c;
}
void Serial::readString( uint8_t *buf, uint32_t l) {

	int lidos=0,c;
	while (getchar() != EOF) vTaskDelay(pdMS_TO_TICKS(50)); //ticks para ms
	while (lidos < l)
	{
		c = getchar();
		if (c != EOF) 
		{
			buf[lidos]=c;
			lidos++;
		}
		if (c=='\n') break;
  	      vTaskDelay(pdMS_TO_TICKS(50)); //ticks para ms
	}
	buf[lidos]=0;
}

Serial serial = Serial();
