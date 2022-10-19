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

  // pinos de dados eh o 16 e pino de clock eh o 5
  i2c_configura (PIN16,PIN5)   ;

  // faz uma operacao de escrita na eeprom
  // endereco do dispositivo eh 1010000 ou seja 0x50
  // escreve o valor 100 no endereco 0
  i2c_start();
    i2c_escreve_byte (0x50 << 1 | 0);
    i2c_escreve_byte (0);
    i2c_escreve_byte (0);
    i2c_escreve_byte (100);
  i2c_stop();
}
