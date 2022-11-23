
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUZINA     GPIO_NUM_16

volatile uint32 x;

void meu_delay (void)
{
    volatile uint32_t a;
     
    for (a=0; a< 100000;a++)
    {
        x = x + a;
    }
}

void app_main()
{
    
  
    printf(" Pinos digitais \n");
   
    gpio_set_direction(BUZINA, GPIO_MODE_OUTPUT);

    unsigned char v=0;
    while(1)
    {

        vTaskDelay(500 / portTICK_PERIOD_MS);
        v = !v;
        gpio_set_level(BUZINA, v);

    }
    
}
