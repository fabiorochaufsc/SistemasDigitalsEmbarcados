#ifndef __DIGITAL__
#define __DIGITAL__
#include "driver/gpio.h"

#define INPUT 1
#define OUTPUT 0
#define PULLUP 2
#define HIGH 1 
#define LOW 0

#define PIN0 GPIO_NUM_0
#define PIN1 GPIO_NUM_1
#define PIN2 GPIO_NUM_2
#define PIN3 GPIO_NUM_3
#define PIN4 GPIO_NUM_4
#define PIN5 GPIO_NUM_5
#define PIN6 GPIO_NUM_6
#define PIN7 GPIO_NUM_7
#define PIN8 GPIO_NUM_8
#define PIN9 GPIO_NUM_9
#define PIN10 GPIO_NUM_10
#define PIN11 GPIO_NUM_11
#define PIN12 GPIO_NUM_12
#define PIN13 GPIO_NUM_13
#define PIN14 GPIO_NUM_14
#define PIN15 GPIO_NUM_15
#define PIN16 GPIO_NUM_16









class Digital {
    public:
        int  digitalRead (gpio_num_t pino);
        void digitalWrite (gpio_num_t pino, int valor);
        void pinMode (gpio_num_t pino, int config);

};

extern Digital digital;


#endif