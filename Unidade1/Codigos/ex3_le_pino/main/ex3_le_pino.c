
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"


#define BOTAO     GPIO_NUM_5

void app_main()
{
    
    uart_config_t uart_config = {
        .baud_rate = 921600,                      //Bluetooth baud rate 
        .data_bits = UART_DATA_8_BITS,          //8 data bits 
        .parity    = UART_PARITY_DISABLE,       //No parity 
        .stop_bits = UART_STOP_BITS_1,          //1 stop bit 
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE   //No hardware flow 
    };
    
    uart_param_config(UART_NUM_0, &uart_config); 
    printf(" Le o valor de um botao \n");
   
    gpio_set_direction(BOTAO, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BOTAO, GPIO_PULLUP_ONLY);


    int statusBotao=1, statusAnteriorBotao=1;
    while(1)
    {

        vTaskDelay(1);
        statusBotao = gpio_get_level(BOTAO);
        if (statusBotao != statusAnteriorBotao)
        {
            statusAnteriorBotao = statusBotao;
            if (statusBotao==0) printf("Botao Pressionado\n");
            else printf("Botao liberado\n");
        }
        
    

    }
    
}
