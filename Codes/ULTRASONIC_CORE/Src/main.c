/*
 * @file   		main.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @MC          STM32F103x
 * @brief       this file has the main program for the ultrasonic layer
 */
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAL/SYSTIC/MSYSTICK_interface.h"
#include "../Inc/MCAL/USART/UART_interface.h"
#include "../Inc/MCAl/GENERAL_PURPOSE_TIMERS/GENRERALTIMERS_interface.h"
#include "../Inc/MCAL/NVIC/MNVIC_interface.h"
#include "../Inc/HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "../Inc/HAL/ULTRASONIC/ULTRASONIC_config.h"
#include "../Inc/MCAL/AFIO/AFIO_interface.h"
#include "../Inc/MCAL/CAN/CAN_interface.h"

#if !defined(_SOFT_FP_) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define TX_PIN			9
#define RX_PIN			10


#define first_three_ultrsonic_ID     0x51
#define second_three_ultrasonic_ID   0x52
#define third_two_ultrasonic_Id      0x50

#define Tx_header_F_ID  			0x56
#define Tx_header_B_ID				0x57
#define Tx_header_F_R_ID			0x58
#define Tx_header_F_L_ID			0x59
#define Tx_header_B_R_ID			0x60
#define Tx_header_B_L_ID			0x61

#define Tx_header_F_INDEX  			1
#define Tx_header_B_INDEX			2
#define Tx_header_F_R_INDEX			4
#define Tx_header_F_L_INDEX			6
#define Tx_header_B_R_INDEX			3
#define Tx_header_B_L_INDEX			5

#define Tx_header_F_Identifier  			'O'
#define Tx_header_B_Identifier				'Q'
#define Tx_header_F_R_Identifier			'R'
#define Tx_header_F_L_Identifier			'S'
#define Tx_header_B_R_Identifier			'T'
#define Tx_header_B_L_Identifier			'U'



#define CAN_first_three_identifer     'D'
#define CAN_second_three_identifer    'E'
#define CAN_third_two_identifer       'C'


#define   top_ultra_index_H             1
#define   top_ultra_index_L             2
#define   back_ultra_index_H         	3
#define   back_ultra_index_L         	4

#define   top_right_ultra_index_H       1
#define   top_right_ultra_index_L       2
#define   middle_right_ultra_index_H    3
#define   middle_right_ultra_index_L    4
#define   back_right_ultra_index_H      5
#define   back_right_ultra_index_L      6

#define   top_left_ultra_index_H       1
#define   top_left_ultra_index_L       2
#define   middle_left_ultra_index_H    3
#define   middle_left_ultra_index_L    4
#define   back_left_ultra_index_H      5
#define   back_left_ultra_index_L      6

#define   P0_PIN		4
#define   P1_PIN		5
#define   P2_PIN		8
#define   P3_PIN		15

#define   REQ_PINS_PORT 			PORTA


uint32 Local_uint32UltrasonicData[4];
uint32 Copy_uint32DisArray_1[4],Copy_uint32DisArray_2[4];
uint32 Global_ULTRA_8X_DISTANCE[8];

uint8 Global_can_first_three[7];
uint8 global_can_second_three[7];
uint8 global_can_third_two[5];

uint8 GLobal_CAN_Send_DATA_array[7];

uint32 Local_uint32UltrasonicData[4];
uint32 Copy_uint32DisArray[4];

uint8 GLOBAL_REQ_PINS_VALUE=0;

CAN_TxHeaderTypeDef Tx_header_first_three;
CAN_TxHeaderTypeDef Tx_header_second_three;
CAN_TxHeaderTypeDef Tx_header_third_two;

CAN_TxHeaderTypeDef Tx_header_F;
CAN_TxHeaderTypeDef Tx_header_B;
CAN_TxHeaderTypeDef Tx_header_F_R;
CAN_TxHeaderTypeDef Tx_header_F_L;
CAN_TxHeaderTypeDef Tx_header_B_R;
CAN_TxHeaderTypeDef Tx_header_B_L;

/*SEND
(char)((WATER_1_PER)>>8), (char)(WATER_1_PER)
*/
/*RECEIVE
 * ((buf[0]<<8)|buf[1])
 */
/******* CAN Transmit Actual Speed *****************/

void REQ_PIN_init(void){
	MDIO_INIT(PORTA);
	MDIO_voidSetDirection(REQ_PINS_PORT ,P0_PIN ,INPUT_PULL_DOWN);
	MDIO_voidSetDirection(REQ_PINS_PORT ,P1_PIN ,INPUT_PULL_DOWN);
	MDIO_voidSetDirection(REQ_PINS_PORT ,P2_PIN ,INPUT_PULL_DOWN);
	//MDIO_voidSetDirection(REQ_PINS_PORT ,P3_PIN ,INPUT_PULL_DOWN);
	MUSART_voidSendWord(USART_1,"REQ_init");
}
void REQ_PIN_READ(void){
	GLOBAL_REQ_PINS_VALUE=0;
	if(MDIO_uint8Read_D_pin(REQ_PINS_PORT,P0_PIN)==1){
		SET_BIT(GLOBAL_REQ_PINS_VALUE,0);
	}
	if(MDIO_uint8Read_D_pin(REQ_PINS_PORT,P1_PIN)==1){
		SET_BIT(GLOBAL_REQ_PINS_VALUE,1);
	}
	if(MDIO_uint8Read_D_pin(REQ_PINS_PORT,P2_PIN)==1){
		SET_BIT(GLOBAL_REQ_PINS_VALUE,2);
	}
	/*if(MDIO_uint8Read_D_pin(REQ_PINS_PORT,P3_PIN)==1){
		SET_BIT(GLOBAL_REQ_PINS_VALUE,3);
	}*/
	/*
	 MUSART_voidSendWord(USART_1,"REQ_VALUE= ");
	 MUSART_voidSendInt(USART_1,GLOBAL_REQ_PINS_VALUE);
	 MUSART_voidSendWord(USART_1,"\n");

*/
}
void ULTRA_SEND_DIS_REQ(void){
	switch(GLOBAL_REQ_PINS_VALUE){
	case Tx_header_F_INDEX :
		GLobal_CAN_Send_DATA_array[0]=Tx_header_F_Identifier;
		GLobal_CAN_Send_DATA_array[1]=Global_ULTRA_8X_DISTANCE[0]>>8;
		GLobal_CAN_Send_DATA_array[2]=Global_ULTRA_8X_DISTANCE[0];
		GLobal_CAN_Send_DATA_array[3]=Global_ULTRA_8X_DISTANCE[4]>>8;
		GLobal_CAN_Send_DATA_array[4]=Global_ULTRA_8X_DISTANCE[4];
		GLobal_CAN_Send_DATA_array[5]=Global_ULTRA_8X_DISTANCE[5]>>8;
		GLobal_CAN_Send_DATA_array[6]=Global_ULTRA_8X_DISTANCE[5];
		CAN_voidAddTxMsg(&Tx_header_F,GLobal_CAN_Send_DATA_array);
		break;
	case Tx_header_B_INDEX:
		GLobal_CAN_Send_DATA_array[0]=Tx_header_B_Identifier;
		GLobal_CAN_Send_DATA_array[1]=Global_ULTRA_8X_DISTANCE[2]>>8;
		GLobal_CAN_Send_DATA_array[2]=Global_ULTRA_8X_DISTANCE[2];
		GLobal_CAN_Send_DATA_array[3]=Global_ULTRA_8X_DISTANCE[7]>>8;
		GLobal_CAN_Send_DATA_array[4]=Global_ULTRA_8X_DISTANCE[7];
		GLobal_CAN_Send_DATA_array[5]=Global_ULTRA_8X_DISTANCE[6]>>8;
		GLobal_CAN_Send_DATA_array[6]=Global_ULTRA_8X_DISTANCE[6];
		CAN_voidAddTxMsg(&Tx_header_B,GLobal_CAN_Send_DATA_array);
		break;
	case Tx_header_F_R_INDEX:
		GLobal_CAN_Send_DATA_array[0]=Tx_header_F_R_Identifier;
		GLobal_CAN_Send_DATA_array[1]=Global_ULTRA_8X_DISTANCE[4]>>8;
		GLobal_CAN_Send_DATA_array[2]=Global_ULTRA_8X_DISTANCE[4];
		GLobal_CAN_Send_DATA_array[3]=Global_ULTRA_8X_DISTANCE[3]>>8;
		GLobal_CAN_Send_DATA_array[4]=Global_ULTRA_8X_DISTANCE[3];
		CAN_voidAddTxMsg(&Tx_header_F_R,GLobal_CAN_Send_DATA_array);
		break;
	case Tx_header_F_L_INDEX:
		GLobal_CAN_Send_DATA_array[0]=Tx_header_F_L_Identifier;
		GLobal_CAN_Send_DATA_array[1]=Global_ULTRA_8X_DISTANCE[5]>>8;
		GLobal_CAN_Send_DATA_array[2]=Global_ULTRA_8X_DISTANCE[5];
		GLobal_CAN_Send_DATA_array[3]=Global_ULTRA_8X_DISTANCE[1]>>8;
		GLobal_CAN_Send_DATA_array[4]=Global_ULTRA_8X_DISTANCE[1];
		CAN_voidAddTxMsg(&Tx_header_F_L,GLobal_CAN_Send_DATA_array);
		break;
	case Tx_header_B_R_INDEX:
		GLobal_CAN_Send_DATA_array[0]=Tx_header_B_R_Identifier;
		GLobal_CAN_Send_DATA_array[1]=Global_ULTRA_8X_DISTANCE[7]>>8;
		GLobal_CAN_Send_DATA_array[2]=Global_ULTRA_8X_DISTANCE[7];
		GLobal_CAN_Send_DATA_array[3]=Global_ULTRA_8X_DISTANCE[3]>>8;
		GLobal_CAN_Send_DATA_array[4]=Global_ULTRA_8X_DISTANCE[3];
		CAN_voidAddTxMsg(&Tx_header_B_R,GLobal_CAN_Send_DATA_array);
		break;
	case Tx_header_B_L_INDEX:
		GLobal_CAN_Send_DATA_array[0]=Tx_header_B_L_Identifier;
		GLobal_CAN_Send_DATA_array[1]=Global_ULTRA_8X_DISTANCE[6]>>8;
		GLobal_CAN_Send_DATA_array[2]=Global_ULTRA_8X_DISTANCE[6];
		GLobal_CAN_Send_DATA_array[3]=Global_ULTRA_8X_DISTANCE[1]>>8;
		GLobal_CAN_Send_DATA_array[4]=Global_ULTRA_8X_DISTANCE[1];
		CAN_voidAddTxMsg(&Tx_header_B_L,GLobal_CAN_Send_DATA_array);
		break;
	}
}
void ULTRA_READ_8X(void){
    HUltrasonic_uint32GetDisX4(ULTRA_2_X4_TIMER_NO_COPY,Copy_uint32DisArray_1);
    HUltrasonic_uint32GetDisX4(ULTRA_1_X4_TIMER_NO_COPY,Copy_uint32DisArray_2);
    uint8 i=0;
    for(i=0;i<=3;i++){
    	Global_ULTRA_8X_DISTANCE[i]=Copy_uint32DisArray_1[i];
    }
    for(i=0;i<=3;i++){
    	Global_ULTRA_8X_DISTANCE[i+4]=Copy_uint32DisArray_1[7-i];
    }
   // MUSART_voidSendWord(USART_1,"read ultrasonic");
}
void CAN_TX(void)
{
	global_can_third_two[0]=CAN_third_two_identifer;
	global_can_third_two[top_ultra_index_H]=(char)((Copy_uint32DisArray_1[0])>>8);
	global_can_third_two[top_ultra_index_L]=(char)(Copy_uint32DisArray_1[0]);
	global_can_third_two[back_ultra_index_H]=(char)((Copy_uint32DisArray_1[1])>>8);
	global_can_third_two[back_ultra_index_L]=(char)(Copy_uint32DisArray_1[1]);

	Global_can_first_three[0]=CAN_first_three_identifer;
	Global_can_first_three[top_right_ultra_index_H]=(char)((Copy_uint32DisArray_2[0])>>8);
	Global_can_first_three[top_right_ultra_index_L]=(char)(Copy_uint32DisArray_2[0]);
	Global_can_first_three[middle_right_ultra_index_H]=(char)((Copy_uint32DisArray_1[2])>>8);
	Global_can_first_three[middle_right_ultra_index_L]=(char)(Copy_uint32DisArray_1[2]);
	Global_can_first_three[back_right_ultra_index_H]=(char)((Copy_uint32DisArray_2[2])>>8);
	Global_can_first_three[back_right_ultra_index_L]=(char)(Copy_uint32DisArray_2[2]);

	global_can_second_three[0]=CAN_second_three_identifer;
	global_can_second_three[top_left_ultra_index_H]=(char)((Copy_uint32DisArray_2[1])>>8);
	global_can_second_three[top_left_ultra_index_L]=(char)(Copy_uint32DisArray_2[1]);
	global_can_second_three[middle_left_ultra_index_H]=(char)((Copy_uint32DisArray_1[3])>>8);
	global_can_second_three[middle_left_ultra_index_L]=(char)(Copy_uint32DisArray_1[3]);
	global_can_second_three[back_left_ultra_index_H]=(char)((Copy_uint32DisArray_2[3])>>8);
	global_can_second_three[back_left_ultra_index_L]=(char)(Copy_uint32DisArray_2[3]);

	CAN_voidAddTxMsg(&Tx_header_third_two,global_can_third_two);
	CAN_voidAddTxMsg(&Tx_header_first_three,Global_can_first_three);
	CAN_voidAddTxMsg(&Tx_header_second_three,global_can_second_three);
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


void CAN_header_init(){

	Tx_header_first_three.StdId = first_three_ultrsonic_ID;
	Tx_header_first_three.IDE = CAN_ID_STD;
	Tx_header_first_three.RTR = CAN_RTR_DATA;
	Tx_header_first_three.DLC = 7;
	Tx_header_first_three.TransmitGlobalTime=DISABLE;

	Tx_header_second_three.StdId = second_three_ultrasonic_ID;
	Tx_header_second_three.IDE = CAN_ID_STD;
	Tx_header_second_three.RTR = CAN_RTR_DATA;
	Tx_header_second_three.DLC = 7;
	Tx_header_second_three.TransmitGlobalTime=DISABLE;

	Tx_header_third_two.StdId = third_two_ultrasonic_Id;
	Tx_header_third_two.IDE = CAN_ID_STD;
	Tx_header_third_two.RTR = CAN_RTR_DATA;
	Tx_header_third_two.DLC = 5;
	Tx_header_third_two.TransmitGlobalTime=DISABLE;

	Tx_header_F.StdId = Tx_header_F_ID;
	Tx_header_F.IDE = CAN_ID_STD;
	Tx_header_F.RTR = CAN_RTR_DATA;
	Tx_header_F.DLC = 7;
	Tx_header_F.TransmitGlobalTime=DISABLE;

	Tx_header_B.StdId = Tx_header_B_ID;
	Tx_header_B.IDE = CAN_ID_STD;
	Tx_header_B.RTR = CAN_RTR_DATA;
	Tx_header_B.DLC = 7;
	Tx_header_B.TransmitGlobalTime=DISABLE;

	Tx_header_F_R.StdId = Tx_header_F_R_ID;
	Tx_header_F_R.IDE = CAN_ID_STD;
	Tx_header_F_R.RTR = CAN_RTR_DATA;
	Tx_header_F_R.DLC = 5;
	Tx_header_F_R.TransmitGlobalTime=DISABLE;

	Tx_header_F_L.StdId = Tx_header_F_L_ID;
	Tx_header_F_L.IDE = CAN_ID_STD;
	Tx_header_F_L.RTR = CAN_RTR_DATA;
	Tx_header_F_L.DLC = 5;
	Tx_header_F_L.TransmitGlobalTime=DISABLE;

	Tx_header_B_R.StdId = Tx_header_B_R_ID;
	Tx_header_B_R.IDE = CAN_ID_STD;
	Tx_header_B_R.RTR = CAN_RTR_DATA;
	Tx_header_B_R.DLC = 5;
	Tx_header_B_R.TransmitGlobalTime=DISABLE;

	Tx_header_B_L.StdId = Tx_header_B_L_ID;
	Tx_header_B_L.IDE = CAN_ID_STD;
	Tx_header_B_L.RTR = CAN_RTR_DATA;
	Tx_header_B_L.DLC = 5;
	Tx_header_B_L.TransmitGlobalTime=DISABLE;

}



int main(void)
{
	MRCC_voidInitClock();
	HUltrasonic_voidInitX4(ULTRA_1_X4_TIMER_NO_COPY);
	HUltrasonic_voidInitX4(ULTRA_2_X4_TIMER_NO_COPY);
	MAFIO_voidInitAFIO();

	HUltrasonic_voidInitX4(ULTRA_1_X4_TIMER_NO_COPY);
	HUltrasonic_voidInitX4(ULTRA_2_X4_TIMER_NO_COPY);
	MRCC_voidInitClock();
	MDIO_INIT(PORTA);
	Mdisable_JTAG();

	MDIO_voidSetDirection(PORTA ,TX_PIN ,AF_2MHZ_PUSH_PULL);
	MDIO_voidSetDirection(PORTA ,RX_PIN ,INPUT_FLOATING);


	MRCC_voidEnableClock(RCC_APB2,USART1_EN);
	MUSART_voidInit(USART_1);

	MSYSTICK_voidInit();
	MUSART_voidSendWord(USART_1,"success");
	REQ_PIN_init();
	CAN_voidInit();
		CAN_header_init();
		CAN_FilterConfig();
		CAN_voidStart();

	for(;;){
		REQ_PIN_READ();
		ULTRA_READ_8X();
		if(GLOBAL_REQ_PINS_VALUE==0){
			continue;
		}
		else{
			ULTRA_SEND_DIS_REQ();
			//for(int g=1;g<=5;g++){
			/*MUSART_voidSendInt(USART_1,((GLobal_CAN_Send_DATA_array[g]<<8)|GLobal_CAN_Send_DATA_array[g+1]));

			MUSART_voidSendWord(USART_1,"---");
			g++;*/
		//}
			//MUSART_voidSendWord(USART_1,"\n");
		}

	}
}
