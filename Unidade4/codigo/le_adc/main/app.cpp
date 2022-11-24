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
#include "driver/adc.h"
#include <inttypes.h> 
#include "serial.h"



 
extern "C" void app_main() ;

void app_main()
{
	uint16_t valor;
	adc_config_t configuracao_ADC;
	
	configuracao_ADC.mode = ADC_READ_TOUT_MODE;
	configuracao_ADC.clk_div = 8;
	
	ESP_ERROR_CHECK(adc_init(&configuracao_ADC));

	serial.begin(9600);
	float temperatura;
	int inteira;
	int frac;

	int32_t somador=0;

	int cont=0;
	while(1)
    	{

			adc_read(&valor);
			somador+=valor;
			cont++;

			if (cont==10)
			{
				
					valor = somador/10;
					somador=0;
					cont=0;
					temperatura = (valor * 330.0)/1023.0;
					inteira = temperatura;
					frac = (temperatura - inteira) * 100.0;
					printf("valor = %d  temperatura =%d.%d \n",valor,inteira,frac);
			}

		
	}

}
