
#ifndef __SERIAL__
#define __SERIAL__


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"


class Serial {
    public:
        void begin(int v);
        void readString( uint8_t *buf, uint32_t length);
        char readChar(void);

};

extern Serial serial;
#endif
