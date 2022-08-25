
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <freertos/semphr.h>
#include "driver/gpio.h"
#include "driver/uart.h"

SemaphoreHandle_t xMutex;//Objeto de semaforo


int dadosProduzidos=0;
int vetor[100];

void le(void *pvParameter)
{
	while(1)
	{
        xSemaphoreTake( xMutex, portMAX_DELAY );
        printf("Entra regiao critica\n");

        if (dadosProduzidos>0)
        {
            printf("Consumiu um dado na posicao %d\n",dadosProduzidos-1);
            dadosProduzidos--;
            vTaskDelay(1000 / portTICK_RATE_MS);

        }

        xSemaphoreGive( xMutex );
        vTaskDelay(7000 / portTICK_RATE_MS);

	}
}

void escreve(void *pvParameter)
{
	while(1)
	{
        xSemaphoreTake( xMutex, portMAX_DELAY );
                printf("Entra regiao critica\n");

                if (dadosProduzidos==100)
                {
                    printf("nao existe espaco para inserir dados\n");
                    printf("Espera o consumidor consumir o que existe");
                }
                else {
                            vTaskDelay(2000 / portTICK_RATE_MS);
                            printf("Produziu um dado na posicao %d\n",dadosProduzidos);
                            //simula algum processamento demorado
                            vetor[dadosProduzidos]=10;
                            dadosProduzidos++;
                }

        
	       
        xSemaphoreGive( xMutex );
        vTaskDelay(2000 / portTICK_RATE_MS);


	}
}

void app_main()
{
    xMutex = xSemaphoreCreateMutex();


    uart_config_t uart_config = {
        .baud_rate = 115200,                      //Bluetooth baud rate 
        .data_bits = UART_DATA_8_BITS,          //8 data bits 
        .parity    = UART_PARITY_DISABLE,       //No parity 
        .stop_bits = UART_STOP_BITS_1,          //1 stop bit 
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE   //No hardware flow 
    };
    
    uart_param_config(UART_NUM_0, &uart_config); 

    printf("Codigo rodando\n");

    printf("Cria tarefas \n");
    xTaskCreate(&escreve, "escreve", 2048, NULL, 5, NULL);
    xTaskCreate(&le, "escreve", 2048, NULL, 5, NULL);


	vTaskDelay(10000 / portTICK_RATE_MS);
    // espera 10 segundos e libera o semaforo. Neste momento a tarefa 1 roda
    // apenas 1 vez e fica bloqueada
    xSemaphoreGive( xMutex );

    
}
