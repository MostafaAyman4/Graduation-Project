/*
 * LIDAR_program.c
 *
 *  Created on: Jul 8, 2024
 *      Author: Legasov
 */
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

#include "../Inc/APP/LIDAR_3D/LIDAR_interface.h"
#include "../Inc/APP/LIDAR_3D/LIDAR_private.h"
#include "../Inc/APP/LIDAR_3D/LIDAR_config.h"

#include "../Inc/HAL/STEPPER/STEPPER_interface.h"
#include "../Inc/HAL/LIMIT_SWITCH/LIMIT_SWITCH_interface.h"
#include "../Inc/MCAL/SYSTIC/MSYSTICK_interface.h"
#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"

uint8 GLOBAL_REQ_VALUE=0;
void HLIDAR_void_init(void){

	MRCC_voidInitClock();
	MDIO_INIT(PORTA);

	MDIO_voidSetDirection(ANGLE_REQ_P1_PORT,ANGLE_REQ_P1,INPUT_PULL_DOWN);
	MDIO_voidSetDirection(ANGLE_REQ_P2_PORT,ANGLE_REQ_P2,INPUT_PULL_DOWN);
	MDIO_voidSetDirection(ANGLE_REQ_P3_PORT,ANGLE_REQ_P3,INPUT_PULL_DOWN);
	MDIO_voidSetDirection(ANGLE_REQ_P4_PORT,ANGLE_REQ_P4,INPUT_PULL_DOWN);

	MDIO_voidSetDirection(ANGLE_FLAG_PIN_PORT,ANGLE_FLAG_PIN,OUTPUT_10MHZ_PUSH_PULL);

	MDIO_voidSetDirection(ANGLE_FLAG_ACK_PORT,ANGLE_FLAG_ACK_PIN,INPUT_PULL_DOWN);

	HSTEPPER_voidinit();
	HLIMIT_SW_init();

}

void HLIDAR_HOME_voidCALIBRATION(void){
	set_base_function();
	refine_base_calibration();
}

uint8 HLIDAR_uint8READ_DESIRED_ANGLE(void){
	GLOBAL_REQ_VALUE =0;
	GLOBAL_REQ_VALUE |= MDIO_uint8Read_D_pin(ANGLE_REQ_P1_PORT,ANGLE_REQ_P1);
	GLOBAL_REQ_VALUE |= (MDIO_uint8Read_D_pin(ANGLE_REQ_P1_PORT,ANGLE_REQ_P2)<<1);
	GLOBAL_REQ_VALUE |= (MDIO_uint8Read_D_pin(ANGLE_REQ_P1_PORT,ANGLE_REQ_P3)<<2);
	GLOBAL_REQ_VALUE |= (MDIO_uint8Read_D_pin(ANGLE_REQ_P1_PORT,ANGLE_REQ_P4)<<3);
}
void HLIDAR_void_SET_ANGLE(uint32 Copy_uint32ANGLEINDEX){
	HLIDAR_uint8READ_DESIRED_ANGLE();
	sint32 differance=Global_STEPPER_ANGLES[GLOBAL_REQ_VALUE]-Global_STEPPER_REAL_POSITION;
	if(differance >0){
		HSTEPPER_voidmove(differance,ANTI_CLOCKWISE);
		HLIDAR_void_ANGLE_READY_FLAG_RISE();
		while(MDIO_uint8Read_D_pin(ANGLE_FLAG_ACK_PORT,ANGLE_FLAG_ACK_PIN)==0);
		HLIDAR_void_ANGLE_READY_FLAG_DOWN();
	}
	else if(differance<0){
		differance = (-1)*differance;
		HSTEPPER_voidmove(differance,CLOCKWISE);
		HLIDAR_void_ANGLE_READY_FLAG_RISE();
		while(MDIO_uint8Read_D_pin(ANGLE_FLAG_ACK_PORT,ANGLE_FLAG_ACK_PIN)==0);
		HLIDAR_void_ANGLE_READY_FLAG_DOWN();
	}
	Global_STEPPER_REAL_POSITION =Global_STEPPER_ANGLES[GLOBAL_REQ_VALUE];
}
void HLIDAR_void_ANGLE_READY_FLAG_RISE(void){
	MDIO_voidWrite_D_pin(ANGLE_FLAG_PIN_PORT,ANGLE_FLAG_PIN,HIGH);
}
void HLIDAR_void_ANGLE_READY_FLAG_DOWN(void){
	MDIO_voidWrite_D_pin(ANGLE_FLAG_PIN_PORT,ANGLE_FLAG_PIN,LOW);
}

void set_base_function(void){
  for(Global_STEPPER_CALI_ZERO_POSTION=0;Global_STEPPER_CALI_ZERO_POSTION<=2000;Global_STEPPER_CALI_ZERO_POSTION++){
	  HSTEPPER_void_move_1_step(CLOCKWISE);
	  MSYSTICK_voidDelay_uS(950);
      if(HLIMIT_SW_uint8read()==0){
     Global_STEPPER_REAL_POSITION=0;
      break;
    }
  }
}
void refine_base_calibration(void){
  for(uint8 x = 0; x < 100; x++) {
	  HSTEPPER_void_move_1_step(ANTI_CLOCKWISE);
	  MSYSTICK_voidDelay_uS(950);
  }
  for(uint8 x = 0; x < 110; x++) {
	  HSTEPPER_void_move_1_step(CLOCKWISE);
	  MSYSTICK_voidDelay_uS(5000);
    if(HLIMIT_SW_uint8read()==0){
      Global_STEPPER_REAL_POSITION=0;
      break;
    }
  }

}

