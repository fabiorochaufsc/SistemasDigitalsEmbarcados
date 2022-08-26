
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <freertos/semphr.h>
#include "driver/gpio.h"
#include "driver/uart.h"

SemaphoreHandle_t xSemaphore;//Objeto de semaforo



void t1(void *pvParameter)
{
	while(1)
	{
        xSemaphoreTake( xSemaphore, portMAX_DELAY );
        printf("Entra regiao critica\n");

        vTaskDelay(5000 / portTICK_RATE_MS);
	}
}



void app_main()
{
	xSemaphore = xSemaphoreCreateCounting(10, 10); 

    uart_config_t uart_config = {
        .baud_rate = 115200,                      //Bluetooth baud rate 
        .data_bits = UART_DATA_8_BITS,          //8 data bits 
        .parity    = UART_PARITY_DISABLE,       //No parity 
        .stop_bits = UART_STOP_BITS_1,          //1 stop bit 
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE   //No hardware flow 
    };
    
    uart_param_config(UART_NUM_0, &uart_config); 

    printf("Codigo rodando\n");

    printf("Cria tarefas \n");
    xTaskCreate(&t1, "t1", 2048, NULL, 5, NULL);
    
}
