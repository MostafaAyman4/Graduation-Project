/*
 * LIMIT_SWITCH_program.c
 *
 *  Created on: Jul 8, 2024
 *      Author: Legasov
 */
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"


#include "../Inc/HAL/LIMIT_SWITCH/LIMIT_SWITCH_interface.h"
#include "../Inc/HAL/LIMIT_SWITCH/LIMIT_SWITCH_private.h"
#include "../Inc/HAL/LIMIT_SWITCH/LIMIT_SWITCH_config.h"

#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"

void HLIMIT_SW_init(void){
	MRCC_voidInitClock();
	MDIO_INIT(PORTA);

	MDIO_voidSetDirection(LIMIT_SW_PORT,LIMIT_SW_PIN,INPUT_PULL_DOWN);
}
uint8 HLIMIT_SW_uint8read(void){
	return MDIO_uint8Read_D_pin(LIMIT_SW_PORT,LIMIT_SW_PIN);
}
