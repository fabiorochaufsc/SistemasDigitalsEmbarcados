/* Detectou escravo na linha
Codigo da Familia: 40
Numero de Serie  : 63 161 4 5 0 0
CRC=             : 18
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "serial.h"
#include "delay.h"
#include <inttypes.h> 
#include "digital.h"
#include "esp_task_wdt.h"
extern "C" void app_main() ;


static inline uint32_t asm_ccount(void) {

    uint32_t r;

    asm volatile ("rsr %0, ccount" : "=r"(r));
    return r;
}

static inline void zera(void)
{
    uint32_t r;
    asm volatile(
            "wsr    %0, ccount\n"
            :
            : "a"(0)
            : "memory"
    );
    asm volatile ("rsr %0, ccount" : "=r"(r));
}

void app_main()
{
  delay_ms(2000);
  serial.begin(9600);
  printf("\n\nRODANDO\n\n");

  
  
uint32_t valor1, valor2,diferenca;
   while (1)
   {
   	zera();
   	valor1 = asm_ccount();
	delay_us(58);  
   	valor2 = asm_ccount();
   	diferenca =(valor2-valor1);
   	printf("t1 = %d  t2 = %d Diferenca vale %d\n",valor1, valor2, diferenca/80);
   	
   	vTaskDelay(1/portTICK_PERIOD_MS);
   	

   }
  
  
 }

