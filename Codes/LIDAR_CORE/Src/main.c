
/*
 * @file   		main.c
 * @author 		Mostafa Ayman
 * @version		V1.0
 * @MC          STM32F103x
 * @brief       this file has the main program for the 3D lidar program
 */
#include <math.h>
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAL/SYSTIC/MSYSTICK_interface.h"
#include "../Inc/MCAL/STK/STK_interface.h"

#include "../Inc/MCAL/USART/UART_interface.h"
#include "../Inc/MCAL/CAN/CAN_interface.h"
#include "../Inc/MCAl/GENERAL_PURPOSE_TIMERS/GENRERALTIMERS_interface.h"

#include "../Inc/MCAL/NVIC/MNVIC_interface.h"

#include "../Inc/HAL/BACK_MOTORS/BKMOTORS_interface.h"
#include "../Inc/MCAL/EXTI/EXTI_interface.h"
#include "../Inc/HAL/SERVO/SERVO_interface.h"

#include "../Inc/HAL/STEPPER/STEPPER_interface.h"
#include "../Inc/HAL/LIMIT_SWITCH/LIMIT_SWITCH_interface.h"
#include "../Inc/APP/LIDAR_3D/LIDAR_interface.h"

#if !defined(_SOFT_FP_) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
/**************************************************************
 * ************ * Macros* ************************
 **************************************************************/
#define TX_PIN			10
#define RX_PIN			11

#define LIL_STEP_PIN		4
#define LIL_DIR_PIN			5
#define LIL_EN              6

#define LIL_STEP_PORT		PORTA
#define LIL_DIR_PORT		PORTA
#define LIL_EN				PORTA

int main(void)
{
	/*
	MRCC_voidInitClock();

	MRCC_voidEnableClock(RCC_APB1,UASRT3_EN);
	MUSART_voidInit(USART_3);

	MDIO_INIT(PORTA);
	MDIO_INIT(PORTB);

	MDIO_voidSetDirection(LIL_STEP_PORT,LIL_STEP_PIN, OUTPUT_10MHZ_PUSH_PULL);
	MDIO_voidSetDirection(LIL_DIR_PORT,LIL_DIR_PIN, OUTPUT_10MHZ_PUSH_PULL);

	MDIO_voidSetDirection(PORTB ,TX_PIN ,AF_2MHZ_PUSH_PULL);
	MDIO_voidSetDirection(PORTB ,RX_PIN ,INPUT_FLOATING);
	MSYSTICK_voidInit();

	MUSART_voidSendWord(USART_3,"node start\n");


*/
	HSTEPPER_voidinit();
	HSTEPPER_voidmove(200,CLOCKWISE);
	for(;;){
		HSTEPPER_voidmove(200,CLOCKWISE);
		//MSYSTICK_voidDelay_uS(1000000);
		HSTEPPER_voidmove(200,ANTI_CLOCKWISE);
		//MSYSTICK_voidDelay_uS(1000000);
		/*
		MDIO_voidWrite_D_pin(LIL_DIR_PORT, LIL_DIR_PIN, HIGH);
		for(uint32 g=0;g<=400;g++){
			MDIO_voidWrite_D_pin(LIL_STEP_PORT, LIL_STEP_PIN, HIGH);
			MSYSTICK_voidDelay_uS(1000);
			MDIO_voidWrite_D_pin(LIL_STEP_PORT, LIL_STEP_PIN, LOW);
			MSYSTICK_voidDelay_uS(1000);
		}
		MDIO_voidWrite_D_pin(LIL_DIR_PORT, LIL_DIR_PIN, LOW);
		for(uint32 g=0;g<=400;g++){
			MDIO_voidWrite_D_pin(LIL_STEP_PORT, LIL_STEP_PIN, HIGH);
			MSYSTICK_voidDelay_uS(1000);
			MDIO_voidWrite_D_pin(LIL_STEP_PORT, LIL_STEP_PIN, LOW);
			MSYSTICK_voidDelay_uS(1000);
		}

*/
	}

}
