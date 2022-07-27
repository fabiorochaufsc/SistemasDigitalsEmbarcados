#ifndef _NRF24_
#define _NRF24_
#include <inttypes.h>

#define TAMANHO_MSG 32
// COMANDOS
#define FLUSH_TX     0xE1
#define FLUSH_RX      0xE2
#define W_TX_PAYLOAD 0xA0
#define R_RX_PAYLOAD 0x61

#define FIFO_STATUS 0x17

// definicoes dos comandos
#define R_REGISTER 0x00
#define W_REGISTER 0x20
#define EN_AA      0x01
#define SETUP_AW   0x03
#define RF_CH      0x05
#define SETUP_RETR  0x04
#define RF_SETUP   0x06
#define RX_ADDR_P0 0x0A
#define TX_ADDR    0x10
#define RX_PW_P0   0x11
#define EN_RXADDR  0x02
#define FEATURE    0x1D
#define DYNPD      0x1C
#define EN_RX_ADDR 0x02


#define MASK_RX_DR  6
#define MASK_TX_DS  5
#define MASK_MAX_RT 4
#define EN_CRC      3
#define CRCO        2
#define PWR_UP      1
#define PRIM_RX     0
#define ENAA_P5     5
#define ENAA_P4     4
#define ENAA_P3     3
#define ENAA_P2     2
#define ENAA_P1     1
#define ENAA_P0     0
#define ERX_P5      5
#define ERX_P4      4
#define ERX_P3      3
#define ERX_P2      2
#define ERX_P1      1
#define ERX_P0      0
#define AW          0
#define ARD         4
#define ARC         0
#define PLL_LOCK    4
#define RF_DR       3
#define RF_PWR      1
#define LNA_HCURR   0        
#define RX_DR       6
#define TX_DS       5
#define MAX_RT      4
#define RX_P_NO     1
#define TX_FULL     0
#define PLOS_CNT    4
#define ARC_CNT     0
#define TX_REUSE    6
#define FIFO_FULL   5
#define TX_EMPTY    4
#define RX_FULL     1
#define RX_EMPTY    0


void    nrf24_init (void);
uint8_t le_registrador (uint8_t reg);
void    nrf24_le_registrador (uint8_t reg, uint8_t qtd, uint8_t vet[]);
void    nrf24_escreve_registrador (uint8_t reg, uint8_t qtd, uint8_t vet[]);
void    nrf24_transmite(uint8_t buffer[]);
void    nrf24_recebe(uint8_t buffer[]);

// definicoes dos registradores
#define STATUS 7
#define CONFIG 0

#endif
