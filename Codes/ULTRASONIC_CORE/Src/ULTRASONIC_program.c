#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAL/SYSTIC/MSYSTICK_interface.h"
#include "../Inc/MCAl/GENERAL_PURPOSE_TIMERS/GENRERALTIMERS_interface.h"


#include "../Inc/HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "../Inc/HAL/ULTRASONIC/ULTRASONIC_private.h"
#include "../Inc/HAL/ULTRASONIC/ULTRASONIC_config.h"

uint8 Local_uint8Systick_overflow_flag;

void HUltrasonic_voidInitIndividual(uint8 Copy_UltraNo){
		MRCC_voidInitClock();
		MSYSTICK_voidInit();
		switch(Copy_UltraNo){
		case ULTRA_1 :
					MRCC_voidEnableClock(RCC_APB1,ULTRA1_TIMER_NO);
					MTimer_voidInitInputCapture(ULTRA1_TIMER_NO,ULTRA1_CHANNEL_NO);

					MDIO_INIT(ULTRA1_PORT_NO);

					MDIO_voidSetDirection(ULTRA1_PORT_NO ,ULTRA1_ECHO_PIN ,INPUT_FLOATING);
					MDIO_voidSetDirection(ULTRA1_PORT_NO ,ULTRA1_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

					MDIO_voidWrite_D_pin(ULTRA1_PORT_NO , ULTRA1_TRIG_PIN ,LOW);
			break;
		case ULTRA_2 :

			MRCC_voidEnableClock(RCC_APB1,ULTRA2_TIMER_NO);
			MTimer_voidInitInputCapture(ULTRA2_TIMER_NO,ULTRA2_CHANNEL_NO);

			MDIO_INIT(ULTRA2_PORT_NO);

			MDIO_voidSetDirection(ULTRA2_PORT_NO ,ULTRA2_ECHO_PIN ,INPUT_FLOATING);
			MDIO_voidSetDirection(ULTRA2_PORT_NO ,ULTRA2_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

			MDIO_voidWrite_D_pin(ULTRA2_PORT_NO , ULTRA2_TRIG_PIN ,LOW);

			break;
		case ULTRA_3 :

			MRCC_voidEnableClock(RCC_APB1,ULTRA3_TIMER_NO);
			MTimer_voidInitInputCapture(ULTRA3_TIMER_NO,ULTRA3_CHANNEL_NO);

			MDIO_INIT(ULTRA3_PORT_NO);

			MDIO_voidSetDirection(ULTRA3_PORT_NO ,ULTRA3_ECHO_PIN ,INPUT_FLOATING);
			MDIO_voidSetDirection(ULTRA3_PORT_NO ,ULTRA3_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

			MDIO_voidWrite_D_pin(ULTRA3_PORT_NO , ULTRA3_TRIG_PIN ,LOW);

			break;
		case ULTRA_4 :
			MRCC_voidEnableClock(RCC_APB1,ULTRA4_TIMER_NO);
			MTimer_voidInitInputCapture(ULTRA4_TIMER_NO,ULTRA4_CHANNEL_NO);

			MDIO_INIT(ULTRA4_PORT_NO);

			MDIO_voidSetDirection(ULTRA4_PORT_NO ,ULTRA4_ECHO_PIN ,INPUT_FLOATING);
			MDIO_voidSetDirection(ULTRA4_PORT_NO ,ULTRA4_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

			MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA4_TRIG_PIN ,LOW);
			break;


		case ULTRA_5 :
					MRCC_voidEnableClock(RCC_APB1,ULTRA5_TIMER_NO);
					MTimer_voidInitInputCapture(ULTRA5_TIMER_NO,ULTRA5_CHANNEL_NO);

					MDIO_INIT(ULTRA5_PORT_NO);

					MDIO_voidSetDirection(ULTRA5_PORT_NO ,ULTRA5_ECHO_PIN ,INPUT_FLOATING);
					MDIO_voidSetDirection(ULTRA5_PORT_NO ,ULTRA5_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

					MDIO_voidWrite_D_pin(ULTRA5_PORT_NO , ULTRA5_TRIG_PIN ,LOW);
					break;


		case ULTRA_6 :
					MRCC_voidEnableClock(RCC_APB1,ULTRA6_TIMER_NO);
					MTimer_voidInitInputCapture(ULTRA6_TIMER_NO,ULTRA6_CHANNEL_NO);

					MDIO_INIT(ULTRA6_PORT_NO);

					MDIO_voidSetDirection(ULTRA6_PORT_NO ,ULTRA6_ECHO_PIN ,INPUT_FLOATING);
					MDIO_voidSetDirection(ULTRA6_PORT_NO ,ULTRA6_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

					MDIO_voidWrite_D_pin(ULTRA6_PORT_NO , ULTRA6_TRIG_PIN ,LOW);
					break;


		case ULTRA_7 :
					MRCC_voidEnableClock(RCC_APB1,ULTRA7_TIMER_NO);
					MTimer_voidInitInputCapture(ULTRA7_TIMER_NO,ULTRA7_CHANNEL_NO);

					MDIO_INIT(ULTRA7_PORT_NO);

					MDIO_voidSetDirection(ULTRA7_PORT_NO ,ULTRA7_ECHO_PIN ,INPUT_FLOATING);
					MDIO_voidSetDirection(ULTRA7_PORT_NO ,ULTRA7_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

					MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA7_TRIG_PIN ,LOW);
					break;


		case ULTRA_8 :
					MRCC_voidEnableClock(RCC_APB1,ULTRA8_TIMER_NO);
					MTimer_voidInitInputCapture(ULTRA8_TIMER_NO,ULTRA8_CHANNEL_NO);

					MDIO_INIT(ULTRA4_PORT_NO);

					MDIO_voidSetDirection(ULTRA8_PORT_NO ,ULTRA8_ECHO_PIN ,INPUT_FLOATING);
					MDIO_voidSetDirection(ULTRA8_PORT_NO ,ULTRA8_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

					MDIO_voidWrite_D_pin(ULTRA8_PORT_NO , ULTRA8_TRIG_PIN ,LOW);
					break;

		}


}
void HUltrasonic_voidInitX4(uint8 Copy_uint8TIMERNO){
	MRCC_voidInitClock();
	MSYSTICK_voidInit();
	switch(Copy_uint8TIMERNO){

	case ULTRA_1_X4_TIMER_NO_COPY:

		MRCC_voidEnableClock(RCC_APB1,ULTRA_1_X4_TIMER_NO );

		MTimer_voidInitInputCapture(ULTRA_1_X4_TIMER_NO,ULTRA1_CHANNEL_NO);
		MTimer_voidInitInputCapture(ULTRA_1_X4_TIMER_NO,ULTRA2_CHANNEL_NO);
		MTimer_voidInitInputCapture(ULTRA_1_X4_TIMER_NO,ULTRA3_CHANNEL_NO);
		MTimer_voidInitInputCapture(ULTRA_1_X4_TIMER_NO,ULTRA4_CHANNEL_NO);

		MDIO_INIT(PORTA);
		MDIO_INIT(PORTB);
		//MDIO_INIT(ULTRA_1_X4_TRIG_PORT);


		MDIO_voidSetDirection(ULTRA1_PORT_NO ,ULTRA1_ECHO_PIN ,INPUT_FLOATING);
		MDIO_voidSetDirection(ULTRA2_PORT_NO ,ULTRA2_ECHO_PIN ,INPUT_FLOATING);
		MDIO_voidSetDirection(ULTRA3_PORT_NO ,ULTRA3_ECHO_PIN ,INPUT_FLOATING);
		MDIO_voidSetDirection(ULTRA4_PORT_NO ,ULTRA4_ECHO_PIN ,INPUT_FLOATING);

		MDIO_voidSetDirection(ULTRA_1_X4_TRIG_PORT ,ULTRA_1_X4_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

		MDIO_voidWrite_D_pin(ULTRA_1_X4_TRIG_PORT , ULTRA_1_X4_TRIG_PIN ,LOW);
		break;

	case ULTRA_2_X4_TIMER_NO_COPY:

				MRCC_voidEnableClock(RCC_APB1,ULTRA_2_X4_TIMER_NO );

				MTimer_voidInitInputCapture(ULTRA_2_X4_TIMER_NO,ULTRA5_CHANNEL_NO);
				MTimer_voidInitInputCapture(ULTRA_2_X4_TIMER_NO,ULTRA6_CHANNEL_NO);
				MTimer_voidInitInputCapture(ULTRA_2_X4_TIMER_NO,ULTRA7_CHANNEL_NO);
				MTimer_voidInitInputCapture(ULTRA_2_X4_TIMER_NO,ULTRA8_CHANNEL_NO);

				MDIO_INIT(PORTA);
				MDIO_INIT(PORTB);

				//MDIO_INIT(ULTRA_2_X4_TRIG_PORT);


				MDIO_voidSetDirection(ULTRA5_PORT_NO ,ULTRA5_ECHO_PIN ,INPUT_FLOATING);
				MDIO_voidSetDirection(ULTRA6_PORT_NO ,ULTRA6_ECHO_PIN ,INPUT_FLOATING);
				MDIO_voidSetDirection(ULTRA7_PORT_NO ,ULTRA7_ECHO_PIN ,INPUT_FLOATING);
				MDIO_voidSetDirection(ULTRA8_PORT_NO ,ULTRA8_ECHO_PIN ,INPUT_FLOATING);

				MDIO_voidSetDirection(ULTRA_2_X4_TRIG_PORT ,ULTRA_2_X4_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

				MDIO_voidWrite_D_pin(ULTRA_2_X4_TRIG_PORT , ULTRA_2_X4_TRIG_PIN ,LOW);
		break;
	}
}

uint32 HUltrasonic_uint32GetDisIndividual(uint8 Copy_UltraNo){

		static	uint32 Local_uint32pulsenew_1;
		static 	uint32  Local_uint32pulseold_1;
		static	uint32  Local_uint32Realpulse_1;

		static	uint32 Local_uint32pulsenew_2;
		static 	uint32  Local_uint32pulseold_2;
		static	uint32  Local_uint32Realpulse_2;

		static	uint32 Local_uint32pulsenew_3;
		static 	uint32  Local_uint32pulseold_3;
		static	uint32  Local_uint32Realpulse_3;

		static	uint32 Local_uint32pulsenew_4;
		static 	uint32  Local_uint32pulseold_4;
		static	uint32  Local_uint32Realpulse_4;

		sint32 cm;

		switch(Copy_UltraNo){

			case ULTRA_1 :

				MDIO_voidWrite_D_pin(ULTRA1_PORT_NO , ULTRA1_TRIG_PIN ,LOW);
				MSYSTICK_voidDelay_uS(5);
				MDIO_voidWrite_D_pin(ULTRA1_PORT_NO , ULTRA1_TRIG_PIN ,HIGH);
				MSYSTICK_voidDelay_uS(10);
				MDIO_voidWrite_D_pin(ULTRA1_PORT_NO , ULTRA1_TRIG_PIN ,LOW);

				Local_uint32pulsenew_1=MTimer_uint32GetPulseTime(ULTRA1_TIMER_NO,ULTRA1_CHANNEL_NO)-126;
				Local_uint32Realpulse_1=Local_uint32pulsenew_1-Local_uint32pulseold_1-125-1;
				Local_uint32pulseold_1=Local_uint32pulsenew_1;
				cm = (Local_uint32pulsenew_1/2) / 29.1;
				return cm;

				break;
			case ULTRA_2 :
				MDIO_voidWrite_D_pin(ULTRA2_PORT_NO , ULTRA2_TRIG_PIN ,LOW);
				MSYSTICK_voidDelay_uS(5);
				MDIO_voidWrite_D_pin(ULTRA2_PORT_NO , ULTRA2_TRIG_PIN ,HIGH);
				MSYSTICK_voidDelay_uS(10);
				MDIO_voidWrite_D_pin(ULTRA2_PORT_NO , ULTRA2_TRIG_PIN ,LOW);

				Local_uint32pulsenew_2=MTimer_uint32GetPulseTime(ULTRA2_TIMER_NO,ULTRA2_CHANNEL_NO)-126;
				Local_uint32Realpulse_2=Local_uint32pulsenew_2-Local_uint32pulseold_2-125-1;
				Local_uint32pulseold_2=Local_uint32pulsenew_2;
				cm = (Local_uint32pulsenew_2/2) / 29.1;
				return cm;
				break;
			case ULTRA_3 :
				MDIO_voidWrite_D_pin(ULTRA3_PORT_NO , ULTRA3_TRIG_PIN ,LOW);
				MSYSTICK_voidDelay_uS(5);
				MDIO_voidWrite_D_pin(ULTRA3_PORT_NO , ULTRA3_TRIG_PIN ,HIGH);
				MSYSTICK_voidDelay_uS(10);
				MDIO_voidWrite_D_pin(ULTRA3_PORT_NO , ULTRA3_TRIG_PIN ,LOW);

				Local_uint32pulsenew_3=MTimer_uint32GetPulseTime(ULTRA3_TIMER_NO,ULTRA3_CHANNEL_NO)-126;
				Local_uint32Realpulse_3=Local_uint32pulsenew_3-Local_uint32pulseold_3-125-1;
				Local_uint32pulseold_3=Local_uint32pulsenew_3;
				cm = (Local_uint32pulsenew_3/2) / 29.1;
				return cm;
				break;
			case ULTRA_4 :
				MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA4_TRIG_PIN ,LOW);
				MSYSTICK_voidDelay_uS(5);
				MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA4_TRIG_PIN ,HIGH);
				MSYSTICK_voidDelay_uS(10);
				MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA4_TRIG_PIN ,LOW);

				Local_uint32pulsenew_4=MTimer_uint32GetPulseTime(ULTRA4_TIMER_NO,ULTRA4_CHANNEL_NO)-126;
				Local_uint32Realpulse_4=Local_uint32pulsenew_4-Local_uint32pulseold_4-125-1;
				Local_uint32pulseold_4=Local_uint32pulsenew_4;
				cm = (Local_uint32pulsenew_4/2) / 29.1;
				return cm;
				break;

			}
}
void HUltrasonic_uint32GetDisX4(uint8 Copy_uint8TIMERNO,uint32 *Copy_uint32DisArray){
	uint32 Local_uint32UltrasonicData[4];
	switch(Copy_uint8TIMERNO){
	case ULTRA_1_X4_TIMER_NO_COPY:
				MDIO_voidWrite_D_pin(PORTB ,ULTRA_1_X4_TRIG_PIN ,LOW);
				MSYSTICK_voidDelay_uS(5);
				MDIO_voidWrite_D_pin(PORTB ,ULTRA_1_X4_TRIG_PIN ,HIGH);
				MSYSTICK_voidDelay_uS(10);
				MDIO_voidWrite_D_pin(PORTB,ULTRA_1_X4_TRIG_PIN ,LOW);

				MTimer_voidGetPulseFullTimer(TIMER_2,Local_uint32UltrasonicData);

				Copy_uint32DisArray[0] = (Local_uint32UltrasonicData[0]/2) / 29.1;
				Copy_uint32DisArray[1] = (Local_uint32UltrasonicData[1]/2) / 29.1;
				Copy_uint32DisArray[2] = (Local_uint32UltrasonicData[2]/2) / 29.1;
				Copy_uint32DisArray[3] = (Local_uint32UltrasonicData[3]/2) / 29.1;

				if(Local_uint32UltrasonicData[0]==0xFFFF){
					Copy_uint32DisArray[0]=0xFFFF;
					 }
				if(Local_uint32UltrasonicData[1]==0xFFFF){
					Copy_uint32DisArray[1]=0xFFFF;
									 }
				if(Local_uint32UltrasonicData[2]==0xFFFF){
					Copy_uint32DisArray[2]=0xFFFF;
									 }
				if(Local_uint32UltrasonicData[3]==0xFFFF){
					Copy_uint32DisArray[3]=0xFFFF;
									 }
		break;
	case ULTRA_2_X4_TIMER_NO_COPY:

		MDIO_voidWrite_D_pin(PORTB ,ULTRA_2_X4_TRIG_PIN ,LOW);
		MSYSTICK_voidDelay_uS(5);
		MDIO_voidWrite_D_pin(PORTB ,ULTRA_2_X4_TRIG_PIN ,HIGH);
		MSYSTICK_voidDelay_uS(10);
		MDIO_voidWrite_D_pin(PORTB,ULTRA_2_X4_TRIG_PIN ,LOW);

		MTimer_voidGetPulseFullTimer(TIMER_3,Local_uint32UltrasonicData);

		Copy_uint32DisArray[0] = (Local_uint32UltrasonicData[0]/2) / 29.1;
		Copy_uint32DisArray[1] = (Local_uint32UltrasonicData[1]/2) / 29.1;
		Copy_uint32DisArray[2] = (Local_uint32UltrasonicData[2]/2) / 29.1;
		Copy_uint32DisArray[3] = (Local_uint32UltrasonicData[3]/2) / 29.1;

		if(Local_uint32UltrasonicData[0]==0xFFFF){
			Copy_uint32DisArray[0]=0xFFFF;
			 }
		if(Local_uint32UltrasonicData[1]==0xFFFF){
			Copy_uint32DisArray[1]=0xFFFF;
							 }
		if(Local_uint32UltrasonicData[2]==0xFFFF){
			Copy_uint32DisArray[2]=0xFFFF;
							 }
		if(Local_uint32UltrasonicData[3]==0xFFFF){
			Copy_uint32DisArray[3]=0xFFFF;
							 }
		break;
	}

}

/*
void HUltrasonic_voidInit(uint8 Copy_UltraNo){
	MRCC_voidInitClock();
	MSYSTICK_voidInit();
	switch(Copy_UltraNo){
	case ULTRA_1 :
				MRCC_voidEnableClock(RCC_APB1,ULTRA1_TIMER_NO);
				MTimer_voidInitInputCapture(ULTRA1_TIMER_NO,ULTRA1_CHANNEL_NO);

				MDIO_INIT(ULTRA1_PORT_NO);

				MDIO_voidSetDirection(ULTRA1_PORT_NO ,ULTRA1_ECHO_PIN ,INPUT_FLOATING);
				MDIO_voidSetDirection(ULTRA1_PORT_NO ,ULTRA1_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

				MDIO_voidWrite_D_pin(ULTRA1_PORT_NO , ULTRA1_TRIG_PIN ,LOW);
		break;
	case ULTRA_2 :

		MRCC_voidEnableClock(RCC_APB1,ULTRA2_TIMER_NO);
		MTimer_voidInitInputCapture(ULTRA2_TIMER_NO,ULTRA2_CHANNEL_NO);

		MDIO_INIT(ULTRA2_PORT_NO);

		MDIO_voidSetDirection(ULTRA2_PORT_NO ,ULTRA2_ECHO_PIN ,INPUT_FLOATING);
		MDIO_voidSetDirection(ULTRA2_PORT_NO ,ULTRA2_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

		MDIO_voidWrite_D_pin(ULTRA2_PORT_NO , ULTRA2_TRIG_PIN ,LOW);

		break;
	case ULTRA_3 :

		MRCC_voidEnableClock(RCC_APB1,ULTRA3_TIMER_NO);
		MTimer_voidInitInputCapture(ULTRA3_TIMER_NO,ULTRA3_CHANNEL_NO);

		MDIO_INIT(ULTRA3_PORT_NO);

		MDIO_voidSetDirection(ULTRA3_PORT_NO ,ULTRA3_ECHO_PIN ,INPUT_FLOATING);
		MDIO_voidSetDirection(ULTRA3_PORT_NO ,ULTRA3_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

		MDIO_voidWrite_D_pin(ULTRA3_PORT_NO , ULTRA3_TRIG_PIN ,LOW);

		break;
	case ULTRA_4 :
		MRCC_voidEnableClock(RCC_APB1,ULTRA4_TIMER_NO);
		MTimer_voidInitInputCapture(ULTRA4_TIMER_NO,ULTRA4_CHANNEL_NO);

		MDIO_INIT(ULTRA4_PORT_NO);

		MDIO_voidSetDirection(ULTRA4_PORT_NO ,ULTRA4_ECHO_PIN ,INPUT_FLOATING);
		MDIO_voidSetDirection(ULTRA4_PORT_NO ,ULTRA4_TRIG_PIN ,OUTPUT_10MHZ_PUSH_PULL);

		MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA4_TRIG_PIN ,LOW);
		break;

	}

}
uint32 HUltrasonic_uint32GetDis(uint8 Copy_UltraNo){

	static	uint32 Local_uint32pulsenew_1;
	static 	uint32  Local_uint32pulseold_1;
	static	uint32  Local_uint32Realpulse_1;

	static	uint32 Local_uint32pulsenew_2;
	static 	uint32  Local_uint32pulseold_2;
	static	uint32  Local_uint32Realpulse_2;

	static	uint32 Local_uint32pulsenew_3;
	static 	uint32  Local_uint32pulseold_3;
	static	uint32  Local_uint32Realpulse_3;

	static	uint32 Local_uint32pulsenew_4;
	static 	uint32  Local_uint32pulseold_4;
	static	uint32  Local_uint32Realpulse_4;

	sint32 cm;

	switch(Copy_UltraNo){

		case ULTRA_1 :

			MDIO_voidWrite_D_pin(ULTRA1_PORT_NO , ULTRA1_TRIG_PIN ,LOW);
			MSYSTICK_voidDelay_uS(5);
			MDIO_voidWrite_D_pin(ULTRA1_PORT_NO , ULTRA1_TRIG_PIN ,HIGH);
			MSYSTICK_voidDelay_uS(10);
			MDIO_voidWrite_D_pin(ULTRA1_PORT_NO , ULTRA1_TRIG_PIN ,LOW);

			Local_uint32pulsenew_1=MTimer_uint32GetPulseTime(ULTRA1_TIMER_NO,ULTRA1_CHANNEL_NO)-126;
			Local_uint32Realpulse_1=Local_uint32pulsenew_1-Local_uint32pulseold_1-125-1;
			Local_uint32pulseold_1=Local_uint32pulsenew_1;
			cm = (Local_uint32pulsenew_1/2) / 29.1;
			return cm;

			break;
		case ULTRA_2 :
			MDIO_voidWrite_D_pin(ULTRA2_PORT_NO , ULTRA2_TRIG_PIN ,LOW);
			MSYSTICK_voidDelay_uS(5);
			MDIO_voidWrite_D_pin(ULTRA2_PORT_NO , ULTRA2_TRIG_PIN ,HIGH);
			MSYSTICK_voidDelay_uS(10);
			MDIO_voidWrite_D_pin(ULTRA2_PORT_NO , ULTRA2_TRIG_PIN ,LOW);

			Local_uint32pulsenew_2=MTimer_uint32GetPulseTime(ULTRA2_TIMER_NO,ULTRA2_CHANNEL_NO)-126;
			Local_uint32Realpulse_2=Local_uint32pulsenew_2-Local_uint32pulseold_2-125-1;
			Local_uint32pulseold_2=Local_uint32pulsenew_2;
			cm = (Local_uint32pulsenew_2/2) / 29.1;
			return cm;
			break;
		case ULTRA_3 :
			MDIO_voidWrite_D_pin(ULTRA3_PORT_NO , ULTRA3_TRIG_PIN ,LOW);
			MSYSTICK_voidDelay_uS(5);
			MDIO_voidWrite_D_pin(ULTRA3_PORT_NO , ULTRA3_TRIG_PIN ,HIGH);
			MSYSTICK_voidDelay_uS(10);
			MDIO_voidWrite_D_pin(ULTRA3_PORT_NO , ULTRA3_TRIG_PIN ,LOW);

			Local_uint32pulsenew_3=MTimer_uint32GetPulseTime(ULTRA3_TIMER_NO,ULTRA3_CHANNEL_NO)-126;
			Local_uint32Realpulse_3=Local_uint32pulsenew_3-Local_uint32pulseold_3-125-1;
			Local_uint32pulseold_3=Local_uint32pulsenew_3;
			cm = (Local_uint32pulsenew_3/2) / 29.1;
			return cm;
			break;
		case ULTRA_4 :
			MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA4_TRIG_PIN ,LOW);
			MSYSTICK_voidDelay_uS(5);
			MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA4_TRIG_PIN ,HIGH);
			MSYSTICK_voidDelay_uS(10);
			MDIO_voidWrite_D_pin(ULTRA4_PORT_NO , ULTRA4_TRIG_PIN ,LOW);

			Local_uint32pulsenew_4=MTimer_uint32GetPulseTime(ULTRA4_TIMER_NO,ULTRA4_CHANNEL_NO)-126;
			Local_uint32Realpulse_4=Local_uint32pulsenew_4-Local_uint32pulseold_4-125-1;
			Local_uint32pulseold_4=Local_uint32pulsenew_4;
			cm = (Local_uint32pulsenew_4/2) / 29.1;
			return cm;
			break;

		}

}
/*
	uint8 counter=0;

	while(counter<60){
				counter++;
				MDIO_voidWrite_D_pin(PORTA , TRIG_PIN ,LOW);
						MSYSTICK_voidDelay_uS(5);
						MDIO_voidWrite_D_pin(PORTA , TRIG_PIN ,HIGH);
						MSYSTICK_voidDelay_uS(10);
						MDIO_voidWrite_D_pin(PORTA , TRIG_PIN ,LOW);

					    /*	read inpulse time*/
				/*	pulse_new=MTimer_uint32GetPulseTime(TIMER_2,CHANNEL_2)-126;
						Real_pulse=pulse_new-pulse_old-125-1;
						pulse_old=pulse_new;
						uint32 cm = (Real_pulse/2) / 29.1;
			}*/

/*
void HUltasonic_voidGetx4Dis(uint32 *Copy_uint32DisArray){

				uint32 Local_uint32UltrasonicData[4];


				MDIO_voidWrite_D_pin(ULTRA_x4_PORT_NO , ULTRA_x4_TRIG_PIN ,LOW);
				MSYSTICK_voidDelay_uS(5);
				MDIO_voidWrite_D_pin(ULTRA_x4_PORT_NO , ULTRA_x4_TRIG_PIN ,HIGH);
				MSYSTICK_voidDelay_uS(10);
				MDIO_voidWrite_D_pin(ULTRA_x4_PORT_NO , ULTRA_x4_TRIG_PIN ,LOW);

				MTimer_voidGetPulseFullTimer(ULTRA_x4_TIMER_NO,Local_uint32UltrasonicData);

				Copy_uint32DisArray[0] = (Local_uint32UltrasonicData[0]/2) / 29.1;
				Copy_uint32DisArray[1] = (Local_uint32UltrasonicData[1]/2) / 29.1;
				Copy_uint32DisArray[2] = (Local_uint32UltrasonicData[2]/2) / 29.1;
				Copy_uint32DisArray[3] = (Local_uint32UltrasonicData[3]/2) / 29.1;

				if(Local_uint32UltrasonicData[0]==0xFFFF){
					Copy_uint32DisArray[0]=0xFFFF;
					 }
				if(Local_uint32UltrasonicData[1]==0xFFFF){
					Copy_uint32DisArray[1]=0xFFFF;
									 }
				if(Local_uint32UltrasonicData[2]==0xFFFF){
					Copy_uint32DisArray[2]=0xFFFF;
									 }
				if(Local_uint32UltrasonicData[3]==0xFFFF){
					Copy_uint32DisArray[3]=0xFFFF;
									 }

}

*/
