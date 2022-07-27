#ifndef __RADIO__
#define __RADIO__

#include <inttypes.h>




#define CONFIG 0
#define EN_AA  1
#define EN_RXADDR 2
#define SETUP_AW 3
#define SETUP_RETR 4
#define RF_CH 5
#define RF_SETUP 6
#define STATUS 7
#define RX_ADDR_P0 0x0A
#define TX_ADDR 0x10
#define RX_PW_P0 0x11


#define TAM_MSG 8
#define N_BLOQ 1
#define BLOQ 0


class RADIO {

	private:
		void escreveRegistrador(uint8_t reg, uint8_t buffer[], uint8_t tam);
		void leRegistrador(uint8_t reg, uint8_t buffer[], uint8_t tam);
		void carregaMensagem(uint8_t buffer[], int tam);
	public:
		uint8_t testa(void);
		void configura (void);
		void modoRX();
		void modoTX();
		int  temMensagem(int modo);
		int leMensagem(uint8_t buffer[]);
		void enviaMensagem(uint8_t buffer[], int tam);
};

extern RADIO radio;

#endif
