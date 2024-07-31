#ifndef  ULTRASONIC_INTERFACE_H
#define  ULTRASONIC_INTERFACE_H

/*@ref  Copy_UltraNo*/

#define ULTRA_1        1
#define ULTRA_2        2
#define ULTRA_3        3
#define ULTRA_4        4
#define ULTRA_5        5
#define ULTRA_6        6
#define ULTRA_7        7
#define ULTRA_8        8


#define ULTRA_1_X4_TIMER_NO_COPY   0
#define ULTRA_2_X4_TIMER_NO_COPY   1

//#define TRIG_PIN		2
//#define ECHO_PIN		1

void HUltrasonic_voidInitIndividual(uint8 Copy_UltraNo);
void HUltrasonic_voidInitX4(uint8 Copy_uint8TIMERNO);

uint32 HUltrasonic_uint32GetDisIndividual(uint8 Copy_UltraNo);
void HUltrasonic_uint32GetDisX4(uint8 Copy_uint8TIMERNO,uint32 *Copy_uint32DisArray);
//void HUltasonic_voidGetx4Dis(uint32 *Copy_uint32DisArray);
void HCallBack_voidsystickfinish();

#endif
