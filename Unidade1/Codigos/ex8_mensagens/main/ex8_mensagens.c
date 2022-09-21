
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/uart.h"


#define BOTAO     GPIO_NUM_5




static xQueueHandle gpio_evt_queue = NULL;



static void tarefa(void* arg)
{
    uint32_t io_num;
    for(;;) {
        if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
            printf("tarefa recebeu mensagem\n");
        }
    }
}


void app_main()
{
    
    // configura porta serial
    uart_config_t uart_config = {
        .baud_rate = 115200,                      //Bluetooth baud rate 
        .data_bits = UART_DATA_8_BITS,          //8 data bits 
        .parity    = UART_PARITY_DISABLE,       //No parity 
        .stop_bits = UART_STOP_BITS_1,          //1 stop bit 
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE   //No hardware flow 
    };
    uart_param_config(UART_NUM_0, &uart_config);
    
    
     
    // configura pino de Entrada
    gpio_set_direction(BOTAO, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BOTAO, GPIO_PULLUP_ONLY);


    // cria um fifo fila de comunicação
    gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
    
    
    // cria uma tarefa
    xTaskCreate(tarefa, "minha_tarefa", 2048, NULL, 10, NULL);
    
    
    printf("Programa rodando\n");
    
    int statusBotao=1, statusAnteriorBotao=1;
    int contador=0;
    while(1)
    {

        vTaskDelay(1);
        statusBotao = gpio_get_level(BOTAO);
        if (statusBotao != statusAnteriorBotao)
        {
            statusAnteriorBotao = statusBotao;
            if (statusBotao==0) {
            	// manda mensagem
            	printf("BOTAO\n");
            	xQueueSend(gpio_evt_queue, ( void * ) &contador, ( TickType_t ) 0);
            }

        }
        
    

    }
    
}

