/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 10 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef GENRERALTIMERS_INTERFACE_H
#define GENRERALTIMERS_INTERFACE_H

#define TIMER_2             0
#define TIMER_3             1
#define TIMER_4             2

#define CHANNEL_1           0
#define CHANNEL_2           1
#define CHANNEL_3           2
#define CHANNEL_4           3

#define ENABLE              1
#define DISAABLE            0

#define UP                  0
#define DOWN                1

/*      TIMER Modes     */
#define UP_DOWN_TIMER       0
#define UP_DOWN_COUNTER     1
#define PWM                 3
#define INPUT_CAPTURE_MODE  4

/*
 * READ
 *  TIMER 2
 *  	CHANNEL 1->	A0
 *  	CHANNEL 2->	A1
 *  	CHANNEL 3->	A2
 *  	CHANNEL 4-> A3
 *  TIMER 3
 *  	CHANNEL 1->	A6
 *  	CHANNEL 2->	A7
 *  	CHANNEL 3->	B0
 *  	CHANNEL 4-> B1
 *  TIMER 4
 *  	CHANNEL 1->	B6
 *  	CHANNEL 2->	B7
 *  	CHANNEL 3->	B8
 *  	CHANNEL 4-> B9
 */

void MTimer_voidInitMode(uint8 Copy_uint8TimerNo,uint8 Copy_uint8Mode);
void MTimer_voidIntiateuSDelayHold(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue);
void MTimer_voidIntiatemSDelayHold(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue);
void MTimer_voidEnableuSDelayInterrupt_once(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue);
void MTimer_voidmSEnableDelayInterrupt_once(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue);
//here you will need to get function address and in the end disable timer
void MTimer_voidEnableuSDelayInterrupt_repeat(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue);
void MTimer_voidmSEnableDelayInterrupt_repeat(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue);
void MTimer_voidEnable(uint8 Copy_uint8TimerNo);
void MTimer_voidDisable(uint8 Copy_uint8TimerNo);

void MTIMER_SetPwm_CH_DutyCycle(uint32 Copy_uint32DutyCycle,uint8 Copy_uint8TimerNo,uint8 Copy_uint8TimerChannel);
void MTIMER_DISABLEPwm_CH_DutyCycle(uint8 Copy_uint8TimerNo,uint8 Copy_uint8TimerChannel);

void MTimer_voidInitInputCapture(uint8 Copy_uint8TimerNo,uint8 Copy_uint8ChannelNo);
#endif
