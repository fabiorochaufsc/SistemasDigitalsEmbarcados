#ifndef _DIGITAL_
#define _DIGITAL_

#include "LPC17xx.h"
#include <stdint.h>

 
#define PIN0_00  0
#define PIN0_01  1
#define PIN0_02  2
#define PIN0_03  3
#define PIN0_04  4
#define PIN0_05  5
#define PIN0_06  6
#define PIN0_07  7
#define PIN0_08  8
#define PIN0_09  9
#define PIN0_10  10
#define PIN0_11  11
#define PIN0_12  12
#define PIN0_13  13
#define PIN0_14  14
#define PIN0_15  15
#define PIN0_16  16
#define PIN0_17  17
#define PIN0_18  18
#define PIN0_19  19
#define PIN0_20  20
#define PIN0_21  21
#define PIN0_22  22
#define PIN0_23  23
#define PIN0_24  24
#define PIN0_25  25
#define PIN0_26  26
#define PIN0_27  27
#define PIN0_28  28
#define PIN0_29  29
#define PIN0_30  30
#define PIN0_31  31

// Definicoes para porta 1
#define PIN1_00  ((1<<5)|0)
#define PIN1_01  ((1<<5)|1)
#define PIN1_02  ((1<<5)|2)
#define PIN1_03  ((1<<5)|3)
#define PIN1_04  ((1<<5)|4)
#define PIN1_05  ((1<<5)|5)
#define PIN1_06  ((1<<5)|6)
#define PIN1_07  ((1<<5)|7)
#define PIN1_08  ((1<<5)|8)
#define PIN1_09  ((1<<5)|9)
#define PIN1_10  ((1<<5)|0)
#define PIN1_11  ((1<<5)|11)
#define PIN1_12  ((1<<5)|12)
#define PIN1_13  ((1<<5)|13)
#define PIN1_14  ((1<<5)|14)
#define PIN1_15  ((1<<5)|15)
#define PIN1_16  ((1<<5)|16)
#define PIN1_17  ((1<<5)|17)
#define PIN1_18  ((1<<5)|18)
#define PIN1_19  ((1<<5)|19)
#define PIN1_20  ((1<<5)|20)
#define PIN1_21  ((1<<5)|21)
#define PIN1_22  ((1<<5)|22)
#define PIN1_23  ((1<<5)|23)
#define PIN1_24  ((1<<5)|24)
#define PIN1_25  ((1<<5)|25)
#define PIN1_26  ((1<<5)|26)
#define PIN1_27  ((1<<5)|27)
#define PIN1_28  ((1<<5)|28)
#define PIN1_29  ((1<<5)|29)
#define PIN1_30  ((1<<5)|30)
#define PIN1_31  ((1<<5)|31)

// Definicoes para porta 2
#define PIN2_00  ((2<<5)|0)
#define PIN2_01  ((2<<5)|1)
#define PIN2_02  ((2<<5)|2)
#define PIN2_03  ((2<<5)|3)
#define PIN2_04  ((2<<5)|4)
#define PIN2_05  ((2<<5)|5)
#define PIN2_06  ((2<<5)|6)
#define PIN2_07  ((2<<5)|7)
#define PIN2_08  ((2<<5)|8)
#define PIN2_09  ((2<<5)|9)
#define PIN2_10  ((2<<5)|10)
#define PIN2_11  ((2<<5)|11)
#define PIN2_12  ((2<<5)|12)
#define PIN2_13  ((2<<5)|13)
#define PIN2_14  ((2<<5)|14)
#define PIN2_15  ((2<<5)|15)
#define PIN2_16  ((2<<5)|16)
#define PIN2_17  ((2<<5)|17)
#define PIN2_18  ((2<<5)|18)
#define PIN2_19  ((2<<5)|19)
#define PIN2_20  ((2<<5)|20)
#define PIN2_21  ((2<<5)|21)
#define PIN2_22  ((2<<5)|22)
#define PIN2_23  ((2<<5)|23)
#define PIN2_24  ((2<<5)|24)
#define PIN2_25  ((2<<5)|25)
#define PIN2_26  ((2<<5)|26)
#define PIN2_27  ((2<<5)|27)
#define PIN2_28  ((2<<5)|28)
#define PIN2_29  ((2<<5)|29)
#define PIN2_30  ((2<<5)|30)
#define PIN2_31  ((2<<5)|31)

// Definicoes para porta 3
#define PIN3_00  ((3<<5)|0)
#define PIN3_01  ((3<<5)|1)
#define PIN3_02  ((3<<5)|2)
#define PIN3_03  ((3<<5)|3)
#define PIN3_04  ((3<<5)|4)
#define PIN3_05  ((3<<5)|5)
#define PIN3_06  ((3<<5)|6)
#define PIN3_07  ((3<<5)|7)
#define PIN3_08  ((3<<5)|8)
#define PIN3_09  ((3<<5)|9)
#define PIN3_10  ((3<<5)|10)
#define PIN3_11  ((3<<5)|11)
#define PIN3_12  ((3<<5)|12)
#define PIN3_13  ((3<<5)|13)
#define PIN3_14  ((3<<5)|14)
#define PIN3_15  ((3<<5)|15)
#define PIN3_16  ((3<<5)|16)
#define PIN3_17  ((3<<5)|17)
#define PIN3_18  ((3<<5)|18)
#define PIN3_19  ((3<<5)|19)
#define PIN3_20  ((3<<5)|20)
#define PIN3_21  ((3<<5)|21)
#define PIN3_22  ((3<<5)|22)
#define PIN3_23  ((3<<5)|23)
#define PIN3_24  ((3<<5)|24)
#define PIN3_25  ((3<<5)|25)
#define PIN3_26  ((3<<5)|26)
#define PIN3_27  ((3<<5)|27)
#define PIN3_28  ((3<<5)|28)
#define PIN3_29  ((3<<5)|29)
#define PIN3_30  ((3<<5)|30)
#define PIN3_31  ((3<<5)|31)

// Definicoes para porta 4
#define PIN4_00  ((4<<5)|0)
#define PIN4_01  ((4<<5)|1)
#define PIN4_02  ((4<<5)|2)
#define PIN4_03  ((4<<5)|3)
#define PIN4_04  ((4<<5)|4)
#define PIN4_05  ((4<<5)|5)
#define PIN4_06  ((4<<5)|6)
#define PIN4_07  ((4<<5)|7)
#define PIN4_08  ((4<<5)|8)
#define PIN4_09  ((4<<5)|9)
#define PIN4_10  ((4<<5)|10)
#define PIN4_11  ((4<<5)|11)
#define PIN4_12  ((4<<5)|12)
#define PIN4_13  ((4<<5)|13)
#define PIN4_14  ((4<<5)|14)
#define PIN4_15  ((4<<5)|15)
#define PIN4_16  ((4<<5)|16)
#define PIN4_17  ((4<<5)|17)
#define PIN4_18  ((4<<5)|18)
#define PIN4_19  ((4<<5)|19)
#define PIN4_20  ((4<<5)|20)
#define PIN4_21  ((4<<5)|21)
#define PIN4_22  ((4<<5)|22)
#define PIN4_23  ((4<<5)|23)
#define PIN4_24  ((4<<5)|24)
#define PIN4_25  ((4<<5)|25)
#define PIN4_26  ((4<<5)|26)
#define PIN4_27  ((4<<5)|27)
#define PIN4_28  ((4<<5)|28)
#define PIN4_29  ((4<<5)|29)
#define PIN4_30  ((4<<5)|30)
#define PIN4_31  ((4<<5)|31)

#define OUTPUT 1
#define INPUT  0

#define HIGH 1
#define LOW 0



#define DISPLAY0 PIN3_25


#define LED0  PIN3_26
#define SW0   PIN1_23
#define SEG_A   PIN0_04
#define SEG_B   PIN0_05
#define SEG_C   PIN0_06
#define SEG_D   PIN0_07
#define SEG_E   PIN0_08
#define SEG_F   PIN0_09
#define SEG_G   PIN0_10



class DIGITAL {

	public:
		void pinMode(uint8_t portabit, uint8_t modo);
		uint8_t digitalRead(uint8_t portabit );
		void digitalWrite(uint8_t portabit, uint8_t valor);

};

extern DIGITAL digital;
#endif


