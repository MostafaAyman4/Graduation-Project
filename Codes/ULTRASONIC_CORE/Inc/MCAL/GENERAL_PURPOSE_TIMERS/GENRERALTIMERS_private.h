/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 10 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef GENRERALTIMERS_PRIVATE_H
#define GENRERALTIMERS_PRIVATE_H

/*  APB1  */
#define TIMER2_BASE_ADDRESS         0x40000000
#define TIMER3_BASE_ADDRESS         0x40000400
#define TIMER4_BASE_ADDRESS         0x40000800

/*CR1*/
#define ARPE   7
#define CMS1   6
#define CMS0   5
#define DIR    4
#define CEN    0
/*EGR*/
#define UG     0

/*CCER*/
#define CC1E   0
#define CC2E   4
#define CC3E   8
#define CC4E   12

/*DIER*/
#define CC1IE   1
#define CC2IE   2
#define CC3IE   3
#define CC4IE   4

/*CCMR1 and CCMR2*/
#define OC1PE  3
#define OC2PE  11
#define OC3PE  3
#define OC4PE  11
#define OC1M   4
#define OC2M   12
#define OC3M   4
#define OC4M   12

#define FALLING     0
#define RISING      1

#define ENABLE     1
#define DISABLE    0

typedef struct{
    volatile uint32 CR1;
    volatile uint32 CR2;
    volatile uint32 SMCR;
    volatile uint32 DIER;
    volatile uint32 SR;
    volatile uint32 EGR;

    volatile uint32 CCMR1;
    volatile uint32 CCMR2;
    volatile uint32 CCER;
    volatile uint32 CNT;
    volatile uint32 PSC;
    volatile uint32 ARR;

    volatile uint32 RESERVED;
    volatile uint32 CCR1;
    volatile uint32 CCR2;
    volatile uint32 CCR3;
    volatile uint32 CCR4;
    volatile uint32 DCR;

    volatile uint32 DMAR;

}TIMER_t;

#define             TIMER2         ((volatile TIMER_t*)TIMER2_BASE_ADDRESS)
#define             TIMER3         ((volatile TIMER_t*)TIMER3_BASE_ADDRESS)
#define             TIMER4         ((volatile TIMER_t*)TIMER4_BASE_ADDRESS)


#endif
