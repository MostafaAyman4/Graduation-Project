#ifndef  BKMOTORS_INTERFACE_H
#define  BKMOTORS_INTERFACE_H

#define MOTOR_RIGHT				0
#define MOTOR_LEFT				1
#define RIGHT				2
#define LEFT				3

void HBKMOTORS_voidinit(uint8 Copy_uint8MotorNO);
void HBKMOTORS_voidRUN(uint8 Copy_uint8MotorNO,uint8 Copy_uint8MotorDir);
void HBKMOTORS_voidSTOP(uint8 Copy_uint8MotorNO);
void HBMOTORS_voidSetSpeed(uint8 Copy_uint8MotorNO,uint8 Copy_uint8Speed);

uint32 HBMOTORS_uint32GetSpeed(uint8 Copy_uint8MotorNO);

#endif
