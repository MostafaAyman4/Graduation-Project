/*
 * @file   		RCC_private.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		13 AUG 2023
 * @MC          STM32F103x
 * @brief       this file is used to store RCC private data
 */

/*define to prevent recursive inclusion*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*                  Register Definitions -assign addresses         */

#define RCC_CR              *((uint32*)0x40021000)
#define RCC_CFGR            *((uint32*)0x40021004)
#define RCC_CIR             *((uint32*)0x40021008)
#define RCC_APB2RSTR        *((uint32*)0x4002100C)
#define RCC_APB1RSTR        *((uint32*)0x40021010)
#define RCC_AHBENR          *((uint32*)0x40021014)
#define RCC_APB2ENR         *((uint32*)0x40021018)
#define RCC_APB1ENR         *((uint32*)0x4002101C)
#define RCC_BDCR            *((uint32*)0x40021020)
#define RCC_CSR             *((uint32*)0x40021024)

/*       MACROS         */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

#define         MUL_BY_2        0
#define         MUL_BY_3        1
#define         MUL_BY_4        2
#define         MUL_BY_5        3
#define         MUL_BY_6        4
#define         MUL_BY_7        5
#define         MUL_BY_8        6
#define         MUL_BY_9        7
#define         MUL_BY_10       8
#define         MUL_BY_11       9
#define         MUL_BY_12       10
#define         MUL_BY_13       11
#define         MUL_BY_14       12
#define         MUL_BY_15       13
#define         MUL_BY_16       14

#define         PLL_IN_HSI_BY_2     0
#define         PLL_IN_HSE          1

#define         HSE_BY_2            0
#define         HSE_BY_0            1

#define 		SYSTEM_CLOCK_HSI          0
#define   	  	SYSTEM_CLOCK_HSE          1
#define 	  	SYSTEM_CLOCK_PLL          2
#define 	  	SYSTEM_CLOCK_NOT_SOURCE   3

#define     BCLK_NOT_DEVIDED            0b000
#define     BCLK_BY_2                   0b100
#define     BCLK_BY_4                   0b101
#define     BCLK_BY_8                   0b110
#define     BCLK_BY_16                  0b111

#define     HCLK_NOT_DEVIDED            0b0000
#define     HCLK_BY_2                   0b1000
#define     HCLK_BY_4                   0b1001
#define     HCLK_BY_8                   0b1010
#define     HCLK_BY_16                  0b1011
#define     HCLK_BY_64                  0b1100
#define     HCLK_BY_128                 0b1101
#define     HCLK_BY_256                 0b1110
#define     HCLK_BY_512                 0b1111
#endif
