
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"

void tarefa_1(void *pvParameter)
{
	while(1)
	{
	    printf("Tarefa 1 - 10 segundos\n");
	    vTaskDelay(10000 / portTICK_RATE_MS);
	}
}

void tarefa_2(void *pvParameter)
{
	while(1)
	{
	    printf("Tarefa 2 - 5 segundos\n");
	    vTaskDelay(5000 / portTICK_RATE_MS);
	}
}

void app_main()
{
    
    uart_config_t uart_config = {
        .baud_rate = 115200,                      //Bluetooth baud rate 
        .data_bits = UART_DATA_8_BITS,          //8 data bits 
        .parity    = UART_PARITY_DISABLE,       //No parity 
        .stop_bits = UART_STOP_BITS_1,          //1 stop bit 
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE   //No hardware flow 
    };
    
    uart_param_config(UART_NUM_0, &uart_config); 
    xTaskCreate(&tarefa_1, "tarefa_1", 2048, NULL, 5, NULL);
    xTaskCreate(&tarefa_2, "tarefa_2", 2048, NULL, 5, NULL);

    
}
