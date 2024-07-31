/*
 * @file   		RCC_interface.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		13 AUG 2023
 * @MC          STM32F103x
 * @brief       this file be used for user interface
 */

/*define to prevent recursive inclusion*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*####################### HOW TO USE THIS DRIVER ##########################
 * 		-configure the clock source
 * 		-configure system clock and each bus prescaler
 * 		-initiate the RCC
 * 		-enable the peripheral u want to use
 * ########################################################################
 */

/*
 * @ref copy_uint8BusId
 */

#define RCC_AHB             0
#define RCC_APB1            1
#define RCC_APB2            2

/*
 * @ref copy_uint32PeriId
 *                   		RCC_APB1_EN_BITS
 */
#define    TIM2_EN          0
#define    TIM3_EN          1
#define    TIM4_EN          2
#define    TIM5_EN          3
#define    TIM6_EN          4
#define    TIM7_EN          5
#define    TIM12_EN         6
#define    TIM13_EN         7
#define    TIM14_EN         8
#define    WWDG_EN          11
#define    SPI2_EN          14
#define    SPI3_EN          15
#define    UASRT2_EN        17
#define    UASRT3_EN        18
#define    UASRT4_EN        19
#define    UASRT5_EN        20
#define    I2C1_EN          21
#define    I2C2_EN          22
#define    USB_EN           23
#define    CAN_EN           25
#define    BKP_EN           27
#define    PWR_EN           28
#define    DAC_EN           29

/*
 * @ref copy_uint32PeriId
 *                   		RCC_APB2_EN_BITS
 */
#define    AFIO_EN          0
#define    PORTA_EN         2
#define    PORTB_EN         4
#define    PORTC_EN         5
#define    PORTD_EN         5
#define    PORTE_EN         6
#define    PORTF_EN         7
#define    PORTG_EN         8
#define    ADC1_EN          9
#define    ADC2_EN          10
#define    TIM1_EN          11
#define    SPI1_EN          12
#define    TIM8_EN          13
#define    USART1_EN        14
#define    ADC3_EN          15
#define    TIM9_EN          19
#define    TIM10_EN         20
#define    TIM11_EN         21

 /*
  * @ref copy_uint32PeriId
  *                   		RCC_AHB_EN_BITS
  */
#define    DMA1_EN          0
#define    DMA2_EN          1
#define    SRAM_EN          2
#define    FLITF_EN         4
#define    CRC_EN           6
#define    FSMC_EN          8
#define    SDIO_EN          10

/*
 * @brief	this function initiate RCC and set configurations
 * @param   NONE
 * @retval	NONE
 */
void MRCC_voidInitClock(void);
 /*
  * @brief	this function is used to enable a specific peripheral
  * @param   -copy_uint8BusId
  * 				this variable for select bus which the peripheral connected to, can be a value of @ref copy_uint8BusId
  * 			-copy_uint32PeriId
  * 				this variable for select select the peripheral u want to enable, can be a value of @ref copy_uint32PeriId
  * @retval	NONE
  */
void MRCC_voidEnableClock(uint8  copy_uint8BusId,uint32 copy_uint32PeriId );
/*
 * @brief	this function is used to disable a specific peripheral
 * @param   -copy_uint8BusId
 * 				this variable for select bus which the peripheral connected to, can be a value of @ref copy_uint8BusId
 * 			-copy_uint32PeriId
 * 				this variable for select select the peripheral u want to enable, can be a value of @ref copy_uint32PeriId
 * @retval	NONE
 */
void MRCC_voidDisableClock(uint8  copy_uint8BusId,uint32 copy_uint32PeriId );


#endif
