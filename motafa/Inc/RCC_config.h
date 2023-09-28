/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 13 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/****************************************************************
 *	 important notes
 * 											SYS_CLK->40MHZ
 * 											AHB_CLK->40MHZ
 * 											APB1_CLK->20MHZ
 * 											APB2_CLK->40MHZ
 *****************************************************************/
/* options:     RCC_HSE_CRYSTAL
                RCC_HSE_RC
                RCC_HSI
                RCC_PLL
*/
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL
/*
    options: 
                MUL_BY_2
                MUL_BY_3
                MUL_BY_4
                MUL_BY_5
                MUL_BY_6
                MUL_BY_7
                MUL_BY_8
                MUL_BY_9
                MUL_BY_10
                MUL_BY_11
                MUL_BY_12
                MUL_BY_13
                MUL_BY_14
                MUL_BY_15
                MUL_BY_16   */
#define RCC_PLL_MUL    MUL_BY_5
/*
    options:   
                  PLL_IN_HSI_BY_2
                  PLL_IN_HSE  */
#define RCC_PLL_SOURCE    PLL_IN_HSE
/*
    options:     
                HSE_BY_2
                HSE_BY_0     */
#define RCC_PLL_HSE_PRESCALLER   HSE_BY_0
/*
 * options:   SYSTEM_CLOCK_HSI
 * 			  SYSTEM_CLOCK_HSE
 * 			  SYSTEM_CLOCK_PLL
 * 			  SYSTEM_CLOCK_NOT_SOURCE*/
#define SYSTEM_CLOCK_SOURCE    SYSTEM_CLOCK_HSE
/*
    options:
        HCLK_NOT_DEVIDED
        HCLK_BY_2
        HCLK_BY_4
        HCLK_BY_8
        HCLK_BY_16
        HCLK_BY_64
        HCLK_BY_128
        HCLK_BY_256
        HCLK_BY_512
    */
#define RCC_AHB_PRESCALLER  HCLK_NOT_DEVIDED
/*
    options:
        BCLK_NOT_DEVIDED
        BCLK_BY_2
        BCLK_BY_4
        BCLK_BY_8
        BCLK_BY_16
    */
#define RCC_APB1_PRESCALLER     BCLK_NOT_DEVIDED
#define RCC_APB2_PRESCALLER     BCLK_NOT_DEVIDED
#endif
