
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"


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

    printf("Primeiro teste com o ESP8266\n");
   
    gpio_set_direction(GPIO_NUM_1, GPIO_MODE_OUTPUT);

    unsigned char v=0;
    for (int i = 10; i >= 0; i--) {
        printf("Contagem regressiva %d ...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        v = !v;
        gpio_set_level(GPIO_NUM_1, v);


    }
    printf("FIM\n");
}
