/*
 * STEPPER_program.c
 *
 *  Created on: Jul 8, 2024
 *      Author: Legasov
 */
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

#include "../Inc/HAL/STEPPER/STEPPER_interface.h"
#include "../Inc/HAL/STEPPER/STEPPER_private.h"
#include "../Inc/HAL/STEPPER/STEPPER_config.h"

#include "../Inc/MCAL/SYSTIC/MSYSTICK_interface.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAL/RCC/RCC_interface.h"

void HSTEPPER_voidinit(){
	MRCC_voidInitClock();

	MDIO_INIT(PORTA);
	MSYSTICK_voidInit();

	MDIO_voidSetDirection(STEPPER_STEP_PORT,STEPPER_STEP_PIN, OUTPUT_10MHZ_PUSH_PULL);
	MDIO_voidSetDirection(STEPPER_DIR_PORT,STEPPER_DIR_PIN, OUTPUT_10MHZ_PUSH_PULL);
	MDIO_voidSetDirection(STEPPER_EN_PORT,STEPPER_EN_PIN, OUTPUT_10MHZ_PUSH_PULL);
	MDIO_voidWrite_D_pin(STEPPER_EN_PORT, STEPPER_EN_PIN, LOW);
}
void HSTEPPER_voidmove(uint32 Copy_uint32steps,uint8 Copy_uint8Direction){
	uint32 index;
	MDIO_voidWrite_D_pin(STEPPER_DIR_PORT, STEPPER_DIR_PIN, Copy_uint8Direction);

	for(index=0;index<=Copy_uint32steps;index++){
			MDIO_voidWrite_D_pin(STEPPER_STEP_PORT, STEPPER_STEP_PIN, HIGH);
			MSYSTICK_voidDelay_uS(STEP_TIME);
			MDIO_voidWrite_D_pin(STEPPER_STEP_PORT, STEPPER_STEP_PIN, LOW);
			MSYSTICK_voidDelay_uS(STEP_TIME);
	}
}
void HSTEPPER_void_move_1_step(uint8 Copy_uint8Direction){
	MDIO_voidWrite_D_pin(STEPPER_DIR_PORT, STEPPER_DIR_PIN, Copy_uint8Direction);
	MDIO_voidWrite_D_pin(STEPPER_STEP_PORT, STEPPER_STEP_PIN, HIGH);
	MSYSTICK_voidDelay_uS(STEP_TIME);
	MDIO_voidWrite_D_pin(STEPPER_STEP_PORT, STEPPER_STEP_PIN, LOW);
	MSYSTICK_voidDelay_uS(STEP_TIME);
}







