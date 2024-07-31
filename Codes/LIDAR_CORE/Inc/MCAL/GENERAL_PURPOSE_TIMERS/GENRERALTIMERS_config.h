/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 10 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef GENRERALTIMERS_CONFIG_H
#define GENRERALTIMERS_CONFIG_H

/* options
    APB1 Frequency*/
#define GENERAL_TIMRS_FREQUENCY          1000000

/* options
            from 1 to 65,535
            16-bit
*/
/*PSC= TIMER2_PRESCALER+1;*/
#define TIMER2_PRESCALER                 7
#define TIMER3_PRESCALER                 7
#define TIMER4_PRESCALER                 7
/* options:
            up
            down  
            */
#define TIMER2_DIRECTION      UP
#define TIMER3_DIRECTION      UP
#define TIMER4_DIRECTION      UP

/*
    options:
        0x0000 -> 0xFFFF*/
/*ARR=PWM2_WIDTH+1*/
#define PWM2_WIDTH                 0xFE
#define PWM3_WIDTH                 0xFE
#define PWM4_WIDTH                 0x4E1F

#define PWM2_CH1_WIDTH             0xFE
#define PWM2_CH2_WIDTH             0xFE
#define PWM2_CH3_WIDTH             0xFE
#define PWM2_CH4_WIDTH             0xFE

#define PWM3_CH1_WIDTH             0xFE
#define PWM3_CH2_WIDTH             0xFE
#define PWM3_CH3_WIDTH             0xFE
#define PWM3_CH4_WIDTH             0xFE

#define PWM4_CH1_WIDTH             0x4E1F
#define PWM4_CH2_WIDTH             0xFE
#define PWM4_CH3_WIDTH             0xFE
#define PWM4_CH4_WIDTH             0xFE

/* options
0000: No filter, sampling is done at fDTS
0001: fSAMPLING=fCK_INT, N=2
0010: fSAMPLING=fCK_INT, N=4
0011: fSAMPLING=fCK_INT, N=8
0100: fSAMPLING=fDTS/2, N=6
0101: fSAMPLING=fDTS/2, N=8
0110: fSAMPLING=fDTS/4, N=6
0111: fSAMPLING=fDTS/4, N=8
1000: fSAMPLING=fDTS/8, N=6
1001: fSAMPLING=fDTS/8, N=8
1010: fSAMPLING=fDTS/16, N=5
1011: fSAMPLING=fDTS/16, N=6
1100: fSAMPLING=fDTS/16, N=8
1101: fSAMPLING=fDTS/32, N=5
1110: fSAMPLING=fDTS/32, N=6
1111: fSAMPLING=fDTS/32, N=8
*/
#define INPUT_CHECK_DURATION            0b0010

/*
    OPTIONS:
            RISING
            FALLING
            */
#define TIMER2_CHANNEL_1_CAPTURE_EDGE  FALLING
#define TIMER2_CHANNEL_2_CAPTURE_EDGE  FALLING
#define TIMER2_CHANNEL_3_CAPTURE_EDGE  FALLING
#define TIMER2_CHANNEL_4_CAPTURE_EDGE  FALLING

#define TIMER3_CHANNEL_1_CAPTURE_EDGE  FALLING
#define TIMER3_CHANNEL_2_CAPTURE_EDGE  FALLING
#define TIMER3_CHANNEL_3_CAPTURE_EDGE  FALLING
#define TIMER3_CHANNEL_4_CAPTURE_EDGE  FALLING

#define TIMER4_CHANNEL_1_CAPTURE_EDGE  RISING
#define TIMER4_CHANNEL_2_CAPTURE_EDGE  RISING
#define TIMER4_CHANNEL_3_CAPTURE_EDGE  RISING
#define TIMER4_CHANNEL_4_CAPTURE_EDGE  RISING
/*
    OPTIONS:
    00: no prescaler, capture is done each time an edge is detected on the capture input
    01: capture is done once every 2 events
    10: capture is done once every 4 events
    11: capture is done once every 8 events
*/
#define INPUT_CAPTURE_CHANNEL_1_PRESCALLER   0b00
#define INPUT_CAPTURE_CHANNEL_2_PRESCALLER   0b00
#define INPUT_CAPTURE_CHANNEL_3_PRESCALLER   0b00
#define INPUT_CAPTURE_CHANNEL_4_PRESCALLER   0b00

/*
 * options:
 * 			ENABLE
 * 			DISABLE
 */
#define TIMER_2_INPULSE_OVERFLOW_INT        DISABLE
#define TIMER_3_INPULSE_OVERFLOW_INT        DISABLE
#define TIMER_4_INPULSE_OVERFLOW_INT        DISABLE

#endif
