/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "digital.h"
#include "serial.h"
 
extern "C" void app_main() ;
int v=0;
void app_main()
{

  serial.begin(9600);
  printf("Funcionando....\n");
  digital.pinMode(PIN16,OUTPUT);

    while (1) {
        digital.digitalWrite(PIN16,v);
        v = !v;
        
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}
