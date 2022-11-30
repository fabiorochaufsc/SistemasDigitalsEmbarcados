#include "digital.h"
#include <stdio.h>

int Digital::digitalRead(gpio_num_t pino)
{
    return gpio_get_level(pino);
    
}


void Digital::pinMode (gpio_num_t pino, int config)
{
   unsigned char c = config & 1;
    if (c==INPUT)
        gpio_set_direction(pino, GPIO_MODE_INPUT);
    else 
        gpio_set_direction(pino, GPIO_MODE_OUTPUT);

    if (config & 2)
    {
       // tem que habilitar o pullup
        gpio_set_pull_mode(pino, GPIO_PULLUP_ONLY);
 
    }
}
void Digital::digitalWrite(gpio_num_t pino, int valor)
{
    gpio_set_level(pino, valor);
}

Digital digital = Digital();
