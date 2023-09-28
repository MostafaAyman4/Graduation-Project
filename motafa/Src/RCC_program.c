/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 13 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidEnableClock(uint8  copy_uint8BusId,uint32 copy_uint32PeriId ){
    if(copy_uint32PeriId<32){
        switch(copy_uint8BusId){
            case RCC_AHB: SET_BIT(RCC_AHBENR,copy_uint32PeriId);     break;
            case RCC_APB1: SET_BIT(RCC_APB1ENR,copy_uint32PeriId);     break;
            case RCC_APB2: SET_BIT(RCC_APB2ENR,copy_uint32PeriId);     break;
        }
    }
    else{
        /*return error*/
    }
}
void MRCC_voidDisableClock(uint8  copy_uint8BusId,uint32 copy_uint32PeriId ){
    if(copy_uint32PeriId<32){
        switch(copy_uint8BusId){
            case RCC_AHB: CLR_BIT(RCC_AHBENR,copy_uint32PeriId);     break;
            case RCC_APB1: CLR_BIT(RCC_APB1ENR,copy_uint32PeriId);     break;
            case RCC_APB2: CLR_BIT(RCC_APB2ENR,copy_uint32PeriId);     break;
        }
    }
    else{
        /*return error*/
    }
}
void MRCC_voidInitClock(void){
    #if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
    RCC_CR = 0x00010000;     //Enable HSE With Crystal no bybass
    #elif   RCC_CLOCK_TYPE == RCC_HSE_RC
    RCC_CR = 0x00050000;    //Enable HSE With RC With bybass
    #elif   RCC_CLOCK_TYPE == RCC_HSI
    RCC_CR = 0x00000081;   //Enable HSI With 0 Trimming 
    #elif   RCC_CLOCK_TYPE == RCC_PLL
    //SET PLL MUL FACTOR
    #if     RCC_PLL_MUL  == MUL_BY_2
        RCC_CFGR |= 0x00000000;
    #elif   RCC_PLL_MUL  == MUL_BY_3
        RCC_CFGR |= 0x00040000;
    #elif   RCC_PLL_MUL  == MUL_BY_4
        RCC_CFGR |= 0x0008000;
    #elif   RCC_PLL_MUL  == MUL_BY_5
        RCC_CFGR |= 0x000C0000;
    #elif   RCC_PLL_MUL  == MUL_BY_6
        RCC_CFGR |= 0x00100000;
    #elif   RCC_PLL_MUL  == MUL_BY_7
        RCC_CFGR |= 0x00140000;
    #elif   RCC_PLL_MUL  == MUL_BY_8
        RCC_CFGR |= 0x00180000;
    #else
        #error("You chosed wrong PLL MUL")
    #endif
    //SET PLL INPUT CLOCK
    #if     RCC_PLL_SOURCE  == PLL_IN_HSI_BY_2
                RCC_CFGR |= 0x00000000;
    #elif   RCC_PLL_SOURCE  == PLL_IN_HSE
            #if     RCC_PLL_HSE_PRESCALLER == HSE_BY_2
                RCC_CFGR |= 0x00030000;
            #elif   RCC_PLL_HSE_PRESCALLER == HSE_BY_0
                RCC_CFGR |= 0x00010000;
            #else
                    #error("You chosed wrong HSE prescaler")
    #endif
    #else
            #error("You chosed wrong PLL SOURCE")
    #endif
    RCC_CR = 0x01000000;   //Enable PLL
    #else
    		#error("You chosed wrong clock type")
    #endif 

    #if         SYSTEM_CLOCK_SOURCE == SYSTEM_CLOCK_HSI
                RCC_CFGR |= 0x00000000;
    #elif       SYSTEM_CLOCK_SOURCE == SYSTEM_CLOCK_HSE
                RCC_CFGR |= 0x00000001;
    #elif       SYSTEM_CLOCK_SOURCE == SYSTEM_CLOCK_PLL
                RCC_CFGR |= 0x00000002;
    #elif       SYSTEM_CLOCK_SOURCE == SYSTEM_CLOCK_NOT_SOURCE
                RCC_CFGR |= 0x00000003;
    #else 
                #error("You chosed wrong SYSTEM INPUT CLOCK")
    #endif
                /*SET APB1 , APB2, AHB PRESCALLERS*/
                RCC_CFGR |= ( RCC_AHB_PRESCALLER<< 4);
                RCC_CFGR |= ( RCC_APB1_PRESCALLER<< 8);
                RCC_CFGR |= ( RCC_APB2_PRESCALLER<< 11);
}
