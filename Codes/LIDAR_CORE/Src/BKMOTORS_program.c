/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 9 DEC 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAL/SYSTIC/MSYSTICK_interface.h"
#include "../Inc/MCAl/GENERAL_PURPOSE_TIMERS/GENRERALTIMERS_interface.h"

#include "../Inc/HAL/BACK_MOTORS/BKMOTORS_interface.h"
#include "../Inc/HAL/BACK_MOTORS/BKMOTORS_config.h"
#include "../Inc/HAL/BACK_MOTORS/BKMOTORS_private.h"

void HBKMOTORS_voidinit(uint8 Copy_uint8MotorNO){

	MRCC_voidInitClock();
	MRCC_voidEnableClock(RCC_APB1,TIMER_3);

	MTimer_voidInitMode(TIMER_3,PWM);

	//MRCC_voidEnableClock(RCC_APB1,TIMER_3);
	//MTimer_voidInitInputCapture(TIMER_2,CHANNEL_1);

	//MDIO_voidSetDirection(PORTA,0,INPUT_FLOATING);

	switch(Copy_uint8MotorNO){
	case MOTOR_RIGHT:
		MDIO_INIT(RIGHT_MOTOR_PORT);
		MDIO_voidSetDirection(RIGHT_MOTOR_PORT,RIGHT_MOTOR_A_PIN, OUTPUT_10MHZ_PUSH_PULL);
		MDIO_voidSetDirection(RIGHT_MOTOR_PORT,RIGHT_MOTOR_B_PIN, OUTPUT_10MHZ_PUSH_PULL);
		MDIO_voidSetDirection(PORTA,RIGHT_MOTOR_PWM_PIN, AF_10MHZ_PUSH_PULL);

		break;
	case MOTOR_LEFT:
		MDIO_INIT(LEFT_MOTOR_PORT);
		MDIO_voidSetDirection(LEFT_MOTOR_PORT,LEFT_MOTOR_A_PIN, OUTPUT_10MHZ_PUSH_PULL);
		MDIO_voidSetDirection(LEFT_MOTOR_PORT,LEFT_MOTOR_B_PIN, OUTPUT_10MHZ_PUSH_PULL);
		MDIO_voidSetDirection(PORTA,LEFT_MOTOR_PWM_PIN, AF_10MHZ_PUSH_PULL);
		break;
	}

}
void HBKMOTORS_voidRUN(uint8 Copy_uint8MotorNO,uint8 Copy_uint8MotorDir){
	switch(Copy_uint8MotorNO){

	case MOTOR_RIGHT:

		switch(Copy_uint8MotorDir){
		case RIGHT:
			MDIO_voidWrite_D_pin(RIGHT_MOTOR_PORT,RIGHT_MOTOR_A_PIN,HIGH);
			MDIO_voidWrite_D_pin(RIGHT_MOTOR_PORT,RIGHT_MOTOR_B_PIN,LOW);
			break;
		case LEFT:
			MDIO_voidWrite_D_pin(RIGHT_MOTOR_PORT,RIGHT_MOTOR_A_PIN,LOW);
			MDIO_voidWrite_D_pin(RIGHT_MOTOR_PORT,RIGHT_MOTOR_B_PIN,HIGH);
			break;
		}
		break;

	case MOTOR_LEFT:
		switch(Copy_uint8MotorDir){
				case RIGHT:
					MDIO_voidWrite_D_pin(LEFT_MOTOR_PORT,LEFT_MOTOR_A_PIN,HIGH);
					MDIO_voidWrite_D_pin(LEFT_MOTOR_PORT,LEFT_MOTOR_B_PIN,LOW);
					break;
				case LEFT:
					MDIO_voidWrite_D_pin(LEFT_MOTOR_PORT,LEFT_MOTOR_A_PIN,LOW);
					MDIO_voidWrite_D_pin(LEFT_MOTOR_PORT,LEFT_MOTOR_B_PIN,HIGH);
					break;
				}
		break;
	}

}
void HBKMOTORS_voidSTOP(uint8 Copy_uint8MotorNO){
	switch(Copy_uint8MotorNO){

		case MOTOR_RIGHT:
			MDIO_voidWrite_D_pin(RIGHT_MOTOR_PORT,RIGHT_MOTOR_A_PIN,LOW);
			MDIO_voidWrite_D_pin(RIGHT_MOTOR_PORT,RIGHT_MOTOR_B_PIN,LOW);
			break;

		case MOTOR_LEFT:
			MDIO_voidWrite_D_pin(LEFT_MOTOR_PORT,LEFT_MOTOR_A_PIN,LOW);
			MDIO_voidWrite_D_pin(LEFT_MOTOR_PORT,LEFT_MOTOR_B_PIN,LOW);
			break;
		}
}

void HBMOTORS_voidSetSpeed(uint8 Copy_uint8MotorNO,uint8 Copy_uint8Speed){
	switch(Copy_uint8MotorNO){
	case MOTOR_RIGHT:
		MTIMER_SetPwm_CH_DutyCycle(Copy_uint8Speed,TIMER_3,CHANNEL_1);
		break;
	case MOTOR_LEFT:
		MTIMER_SetPwm_CH_DutyCycle(Copy_uint8Speed,TIMER_3,CHANNEL_2);
		break;
	}

}


uint32 HBMOTORS_uint32GetSpeed(uint8 Copy_uint8MotorNO){
	uint32 Local_uint32FirstReading,Local_uint32SecondReading;
	switch(Copy_uint8MotorNO){
		case MOTOR_RIGHT:
			Local_uint32FirstReading=MTimer_uint32GetPulseTime(TIMER_2,CHANNEL_1);
			Local_uint32SecondReading=MTimer_uint32GetPulseTime(TIMER_2,CHANNEL_1);
			return Local_uint32SecondReading;
			break;
		case MOTOR_LEFT:
			Local_uint32FirstReading=MTimer_uint32GetPulseTime(TIMER_2,CHANNEL_2);
			Local_uint32SecondReading=MTimer_uint32GetPulseTime(TIMER_2,CHANNEL_2);
			return (1/((Local_uint32FirstReading-Local_uint32SecondReading)*(0.000001)));
			break;
		}
}
