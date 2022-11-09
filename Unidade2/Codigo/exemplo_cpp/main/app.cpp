/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "serial.h"
#include "memoria.h"
#include <inttypes.h> 


 
extern "C" void app_main() ;
int v=0;

void app_main()
{
  char buffer[100];
  char leitura[100];

  serial.begin(9600);
  printf("Funcionando....\n");

  // pinos de dados eh o 16 e pino de clock eh o 5
  strcpy(buffer,"Engenharia de Computacao");
  Memoria memoria_i2c = Memoria();

  memoria_i2c.init(0);
  memoria_i2c.escreve(100, (uint8_t *)buffer,strlen(buffer)+1);
  memoria_i2c.le(100,(uint8_t *)leitura,25);

  printf("VALOR LIDO=%s\n",leitura);


}
