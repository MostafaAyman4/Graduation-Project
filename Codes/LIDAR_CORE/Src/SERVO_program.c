/*
 * SERVO_program.c
 *
 *  Created on: Apr 12, 2024
 *      Author: Legasov
 */
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAl/GENERAL_PURPOSE_TIMERS/GENRERALTIMERS_interface.h"

#include "../Inc/HAL/SERVO/SERVO_interface.h"
#include "../Inc/HAL/SERVO/SERVO_config.h"
#include "../Inc/HAL/SERVO/SERVO_private.h"

void HSERVO_VOIDINIT(void){

	MRCC_voidInitClock();

	MRCC_voidEnableClock(RCC_APB1,TIMER_4);

	MTimer_voidInitMode(TIMER_4,PWM);

	MDIO_voidSetDirection(SERVO_PWM_PORT,SERVO_PWM_PIN, AF_10MHZ_PUSH_PULL);

}
void HSERVO_VOID_SETANGLE(uint16 copy_uint8angle){
	copy_uint8angle =((copy_uint8angle*1900)/180);
	copy_uint8angle += 500;
	MTIMER_SetPwm_CH_DutyCycle(copy_uint8angle,TIMER_4,CHANNEL_1);
}
