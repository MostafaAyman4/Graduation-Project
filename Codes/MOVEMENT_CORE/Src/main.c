
/*
 * @file   		main.c
 * @author 		Mostafa Ayman
 * @version		V4.0
 * @MC          STM32F103x
 * @brief       this file has the main program for the motors layer
 */

#include <math.h>
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/MCAL/RCC/RCC_interface.h"

//#include "../Inc/MCAL/RCC/RCC_private.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAL/SYSTIC/MSYSTICK_interface.h"
#include "../Inc/MCAL/STK/STK_interface.h"

#include "../Inc/MCAL/USART/UART_interface.h"
#include "../Inc/MCAL/CAN/CAN_interface.h"
#include "../Inc/MCAl/GENERAL_PURPOSE_TIMERS/GENRERALTIMERS_interface.h"
//#include "../Inc/MCAl/GENERAL_PURPOSE_TIMERS/GENRERALTIMERS_private.h"
#include "../Inc/MCAL/NVIC/MNVIC_interface.h"

//#include "../Inc/HAL/ULTRASONIC/ULTRASONIC_interface.h"
//#include "../Inc/HAL/ULTRASONIC/ULTRASONIC_config.h"

#include "../Inc/HAL/BACK_MOTORS/BKMOTORS_interface.h"
#include "../Inc/MCAL/EXTI/EXTI_interface.h"
#include "../Inc/HAL/SERVO/SERVO_interface.h"
#if !defined(_SOFT_FP_) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
/**************************************************************
 * ************ * Macros* ************************
 **************************************************************/
#define TX_PIN			10
#define RX_PIN			11

#define MOTOR_ENCODER_PIN  PA0
///////////////////used in motor movement///////////////////////
#define FORWARD       2
#define BACKWARD      3

#define speed_level_1        130
#define speed_level_2        170
#define speed_level_3		 210
#define speed_level_4		 255

/**************************************************************
 * ************ * Variables* ************************
 **************************************************************/
float init_time=0;
float final_time=0;
float duration_time=0;
float freq;
float average=0;
int index=0;
float deltaT=0;
float v1Filt = 0;
float v1Prev = 0;
float eintegral = 0;
float kp = 4;
float ki = 50;
int desired_speed=100;
int pwr=255;
volatile uint32 DIS_TOTAL_PULSES =0;
volatile long double desired_distance=0;
volatile long double Distance=0;
volatile uint8 move_flag =0;
volatile int counter_pulses=0;

/////////////////can variables/////////////////////////////
uint8 GLOBAL_CAN_data_RX[8];

////////////////back motors variables//////////////////////
uint8 GLOBAL_MOTOR_SPEED_LOOKUP_T[4]={speed_level_1,speed_level_2,speed_level_3,speed_level_4};

///////////////Servo variables/////////////////////////////
uint8 GLOBAL_Servo_angles_LOOKUP_T[7] ={0,30,60,90,120,150,180};

/**************************************************************
 * ************ * function definition* ************************
 **************************************************************/
void CAN_TX(void);
void CAN_RX(void);
uint16 Std_id_High(uint16 local_u16Std_Id);
void CAN_FilterConfig(void);
void CAN_TxMailbox0CompleteCallback();
void CAN_RxFifo0MsgPendingCallback();

double convertAToB(double A);
void speed_measure(void);
void PID_controller_Velocity(void);
void move_distance(long double copy_float64dis,uint8 copy_uint8Direction,uint8 copy_uint8speed);
void Encoder_INT_POSITION(void);
void Encoder_INT_SPEED(void);
void BACK_MOTORS_INIT(void);
void BACK_MOTORS_MOVE(uint8 copy_uint8_M_R_speed,uint8 copy_uint8_M_L_speed,uint8 copy_uint8_M_R_DIR, uint8 copy_uint8_M_L_DIR);
void BACK_MOTORS_STOP(void);
/**************************************************************
 * ************ * main function* ************************
 **************************************************************/
int main(void)
{
	MRCC_voidInitClock();

	MRCC_voidEnableClock(RCC_APB1,UASRT3_EN);
	MUSART_voidInit(USART_3);
	MDIO_INIT(PORTA);
	MDIO_INIT(PORTB);
	MEXTI_voidInit(MOTOR_ENCODER_PIN,RISING_ENGE);
	MEXTI_voidSetCallback(0,Encoder_INT_POSITION);


	MDIO_voidSetDirection(PORTA,MOTOR_ENCODER_PIN, INPUT_FLOATING);
	//INPUT_PULL_DOWN

	MDIO_voidSetDirection(PORTB ,TX_PIN ,AF_2MHZ_PUSH_PULL);
	MDIO_voidSetDirection(PORTB ,RX_PIN ,INPUT_FLOATING);
	MDIO_voidSetDirection(PORTB,0, OUTPUT_10MHZ_PUSH_PULL);
	MDIO_voidWrite_D_pin(PORTB,0,HIGH);

	/************************
	 * can initiation
	 * /* CAN init */
	CAN_voidInit();
	/* CAN Filter set */
	CAN_FilterConfig();
	//CAN_Interrupt();
	/* CAN Start */
	CAN_voidStart();

	MUSART_voidSendWord(USART_3,"node start\n");

	//MEXTI_voidInit(PA6,RISING_ENGE);
	HBKMOTORS_voidinit(MOTOR_LEFT);
	//HBMOTORS_voidSetSpeed(MOTOR_LEFT,255);


	//MSYSTICK_voidInit();
	//STK_voidInit();
	//STK_voidStartMicros();

	//MEXTI_voidEnable(MOTOR_ENCODER_PIN);
	//move_distance(0.20420352248,RIGHT,255);
	//HBKMOTORS_voidRUN(MOTOR_LEFT,RIGHT);
	BACK_MOTORS_INIT();
	HSERVO_VOIDINIT();
	//BACK_MOTORS_MOVE(125,125,FORWARD, FORWARD);
	for(;;){
		CAN_RX();
		MUSART_voidSendWord(USART_3,"CAN FINISH\n");
		if(GLOBAL_CAN_data_RX[0]=='A'){
			HSERVO_VOID_SETANGLE(GLOBAL_Servo_angles_LOOKUP_T[GLOBAL_CAN_data_RX[1]]);
			BACK_MOTORS_MOVE(GLOBAL_CAN_data_RX[2],GLOBAL_CAN_data_RX[2],GLOBAL_CAN_data_RX[4],GLOBAL_CAN_data_RX[4]);
			MUSART_voidSendWord(USART_3,"CAN RECEIVE A \n");
			MUSART_voidSendByte(USART_3,GLOBAL_CAN_data_RX[0]);
			MUSART_voidSendByte(USART_3,'-');
			MUSART_voidSendInt(USART_3,GLOBAL_Servo_angles_LOOKUP_T[GLOBAL_CAN_data_RX[1]]);
			MUSART_voidSendByte(USART_3,'-');
			MUSART_voidSendInt(USART_3,GLOBAL_CAN_data_RX[4]);
			MUSART_voidSendByte(USART_3,'-');
			MUSART_voidSendInt(USART_3,GLOBAL_CAN_data_RX[2]);
			MUSART_voidSendByte(USART_3,'\n');
		}



		/****************
		 * can send and receive
		 * CAN_TX();
    		//CAN_RX();
		 */
		//MEXTI_voidEnable(MOTOR_ENCODER_PIN);
		//speed_measure();
		//PID_controller_Velocity();


		//STK_voidDelay_ms(500);
		//MEXTI_voidEnable(PA6);
		//MEXTI_voiddisable(PA6);
		//MUSART_voidSendInt(USART_1,counter);
		//counter=0;
	}
}
/**************************************************************
 * ************ * function declaration * **********************
 **************************************************************/
void CAN_TX(void)
{
	CAN_TxHeaderTypeDef tx_header;
	tx_header.StdId = 0x6;
	tx_header.IDE = CAN_ID_STD;
	tx_header.RTR = CAN_RTR_DATA;
	tx_header.DLC = 8;
	tx_header.TransmitGlobalTime=DISABLE;
	uint8 DATA[5] = {'N','O','D','E'};

	CAN_TxHeaderTypeDef tx_header1;
	tx_header1.StdId = 0x7;
	tx_header1.IDE = CAN_ID_STD;
	tx_header1.RTR = CAN_RTR_DATA;
	tx_header1.DLC = 8;
	uint8 DATA1[6] = {'T','W','O'};

	CAN_voidAddTxMsg(&tx_header,DATA);
	CAN_voidAddTxMsg(&tx_header1,DATA1);
}
void CAN_RX(void)
{
	MUSART_voidSendWord(USART_3, "/////////////");
	CAN_RxHeaderTypeDef Rx_header;
	while(CAN_voidRXPending(CAN_RX_FIFO0) == 0);
	//MUSART_voidSendInt(USART_3,Rx_header.StdId);

	CAN_voidGetRxMsg(CAN_RX_FIFO0,&Rx_header,GLOBAL_CAN_data_RX);
	/*MUSART_voidSendByte(USART_3,GLOBAL_CAN_data_RX[0]);
	MUSART_voidSendByte(USART_3,'-');
	MUSART_voidSendInt(USART_3,GLOBAL_Servo_angles_LOOKUP_T[GLOBAL_CAN_data_RX[1]]);
	MUSART_voidSendByte(USART_3,'-');
	MUSART_voidSendInt(USART_3,GLOBAL_CAN_data_RX[4]);
	MUSART_voidSendByte(USART_3,'-');
	MUSART_voidSendInt(USART_3,GLOBAL_CAN_data_RX[2]);
	MUSART_voidSendByte(USART_3,'\n');
*/
	//MUSART_voidSendWord(USART_3, GLOBAL_CAN_data_RX);
	//MUSART_voidSendWord(USART_3, "\n");
}
uint16 Std_id_High(uint16 local_u16Std_Id)
{
	return (local_u16Std_Id << 5);
}
void CAN_FilterConfig(void)
{
	CAN_FilterTypeDef CAN_FilterInit;
	CAN_FilterInit.FilterActivation = ENABLE;
	CAN_FilterInit.FilterBank = 0;
	CAN_FilterInit.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	CAN_FilterInit.FilterIdHigh = Std_id_High(0x65d);
	CAN_FilterInit.FilterIdLow = 0x0000;
	CAN_FilterInit.FilterMaskIdHigh = 0x0000;
	CAN_FilterInit.FilterMaskIdLow = 0x0000;
	CAN_FilterInit.FilterMode = CAN_FILTERMODE_IDMASK;
	CAN_FilterInit.FilterScale = CAN_FILTERSCALE_32BIT;

	CAN_voidConfigFilter(&CAN_FilterInit);
}
/*
void CAN_Interrupt(void)
{
	CAN_voidInitInterput(CAN_TX_IRQn);
	CAN_voidInitInterput(CAN_RX0_IRQn);
	CAN_voidInitInterput(CAN_RX1_IRQn);
	CAN_voidInitInterput(CAN_SCE_IRQn);

	CAN_voidEnableInterrupt(CAN_IER_TX_MAILBOX_EMPTY | CAN_IER_RX_FIFO0_MSG_PENDING | CAN_IER_ERROR | CAN_IER_LAST_ERROR_CODE | CAN_IER_BUSOFF);
}
*/
void CAN_TxMailbox0CompleteCallback()
{
	/* print MSG on UART1 */
	char MSG[50] = " MSG TRANSMITED m0 \n";
	MUSART_voidSendWord(USART_1, MSG);
	//NVIC_voidSetPendingFlag(CAN_TX_IRQn);
}
void CAN_RxFifo0MsgPendingCallback()
{
	CAN_RX();
	//NVIC_voidSetPendingFlag(CAN_RX0_IRQn);
}
/*
void CAN_ErrorCallback()
{
	/* print MSG on UART1 */
	/*char MSG[50] = "Error Code \n";
	u32 x= CAN_voidGetErrorCode();
	MUSART_voidSendInt(USART_1,&x);
	MUSART_voidSendWord(USART_1, "\n");

}
*/
double convertAToB(double A) {
    // Coefficients of the quadratic equation
    double a = -6.47e-4;
    double b = 0.98;
    double c = 0.48;

    // Calculate B using the quadratic equation
    double B = a * A * A + b * A + c;
    return B;
}
void speed_measure(void){
	average=0;
	while(index<1){

			if(MDIO_uint8Read_D_pin(PORTA,MOTOR_ENCODER_PIN)==1){
			  init_time=Micros();
			  while(MDIO_uint8Read_D_pin(PORTA,MOTOR_ENCODER_PIN)==1);
			  while(MDIO_uint8Read_D_pin(PORTA,MOTOR_ENCODER_PIN)==0);
			  final_time=Micros();
			  duration_time=(final_time-init_time);
			  deltaT = (float)duration_time*0.000001;
			  freq=(1.0/((float)duration_time*0.000001)*60.0)/(458);
			  average+=freq;
			  index++;
			}

			}
			average =average;
			average=convertAToB(average);
			/*if(average==desired_speed){

			}
			else if(average<desired_speed){
				pwr++;
			}
			else if(average>desired_speed){
				pwr--;
			}
			if(pwr<0){
				pwr=0;
			}
			else if (pwr>255){
				pwr=255;
			}*/
			   //HBMOTORS_voidSetSpeed(MOTOR_LEFT,pwr);
			   //MUSART_voidSendInt(USART_3,desired_speed);
			   //MUSART_voidSendByte(USART_3,' ');
			   //MUSART_voidSendInt(USART_3,average);
			   //MUSART_voidSendByte(USART_3,'\n');

			index=0;

}
void PID_controller_Velocity(void){

	float v1 = average;
	 v1Filt = 0.854*v1Filt + 0.0728*v1 + 0.0728*v1Prev;
	 v1Prev = v1;
	 float vt = desired_speed;
	 // Compute the control signal u

	   float e = vt-v1Filt;
	   eintegral = eintegral + e*deltaT;

	   float u = kp*e + ki*eintegral;
	   // Set the motor speed and direction

	   int pwr = (int) fabs(u);
	   HBMOTORS_voidSetSpeed(MOTOR_LEFT,pwr);
		//MUSART_voidSendInt(USART_3,desired_speed);
		//MUSART_voidSendByte(USART_3,' ');
		//MUSART_voidSendInt(USART_3,average);
		//MUSART_voidSendByte(USART_3,'\n');
}
void move_distance(long double copy_float64dis,uint8 copy_uint8Direction,uint8 copy_uint8speed){

	desired_distance= Distance+copy_float64dis;
	move_flag =1;
	//run motor just to start interrupt
	HBMOTORS_voidSetSpeed(MOTOR_LEFT,copy_uint8speed);
	HBKMOTORS_voidRUN(MOTOR_LEFT,copy_uint8Direction);

}

void Encoder_INT_POSITION(void){
	/*counter_pulses++;
	if(counter_pulses >= 458){
		HBKMOTORS_voidSTOP(MOTOR_LEFT);
		MUSART_voidSendInt(USART_3,counter_pulses);
	}*/

	if(Distance>=desired_distance){
		HBKMOTORS_voidSTOP(MOTOR_LEFT);
		move_flag =0;
	}
	else{
	move_flag =1;
	DIS_TOTAL_PULSES++;
	Distance = (long double)DIS_TOTAL_PULSES * 0.00044585922;
	//MUSART_voidSendByte(USART_3,'H');
	//MUSART_voidSendByte(USART_3,'\n');
	}

}
void Encoder_INT_SPEED(void){

}


void BACK_MOTORS_INIT(void){
	MDIO_INIT(PORTA);
	MDIO_INIT(PORTB);
	HBKMOTORS_voidinit(MOTOR_RIGHT);
	HBKMOTORS_voidinit(MOTOR_LEFT);
}
void BACK_MOTORS_MOVE(uint8 copy_uint8_M_R_speed,uint8 copy_uint8_M_L_speed,uint8 copy_uint8_M_R_DIR, uint8 copy_uint8_M_L_DIR){
	HBKMOTORS_voidRUN(MOTOR_RIGHT,copy_uint8_M_R_DIR);
	HBKMOTORS_voidRUN(MOTOR_LEFT,copy_uint8_M_L_DIR);
	HBMOTORS_voidSetSpeed(MOTOR_RIGHT,copy_uint8_M_R_speed);
	HBMOTORS_voidSetSpeed(MOTOR_LEFT,copy_uint8_M_L_speed);
}
void BACK_MOTORS_STOP(void){
	HBKMOTORS_voidSTOP(MOTOR_RIGHT);
	HBKMOTORS_voidSTOP(MOTOR_LEFT);
}

