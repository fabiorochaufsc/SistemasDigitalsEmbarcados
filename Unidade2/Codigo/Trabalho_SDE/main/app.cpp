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

  char leitura[100];

  serial.begin(9600);
  printf("Entre com o nome: ");
  
  serial.readString((uint8_t *)leitura,10);
  printf("%s\n",leitura);
  
  printf("Entre com o Endereco: ");
  serial.readString((uint8_t *)leitura,10);
  printf("%s\n",leitura);
  
  printf("Entre com o telefone: ");
  serial.readString((uint8_t *)leitura,10);
  printf("%s\n",leitura);
  
  printf("Entre com opcao\n");
  printf("[0] - faz algo\n");
  printf("[1] - faz outro\n");
  char opcao = serial.readChar();
  switch (opcao)
  {
  	case '0':
  		printf("Opcao 0 selecionada\n");
  		break;
  	case '1':
  		printf("Opcao 1 selecionada\n");
  		break;
  }
  

  


}
