/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 20 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef    MNVIC_INTERFACE_H
#define    MNVIC_INTERFACE_H

/*                   Interrupt No Options                   */
#define   WWDG_INT_NO                               0
#define   PVD_INT_NO                                1
#define   TAMPER_INT_NO                             2
#define   RTC_INT_NO                                3
#define   FLASH_INT_NO                              4
#define   RCC_INT_NO                                5
#define   EXTI0_INT_NO                              6
#define   EXTI1_INT_NO                              7
#define   EXTI2_INT_NO                              8
#define   EXTI3_INT_NO                              9
#define   EXTI4_INT_NO                              10
#define   DMA1_Channel1_INT_NO                      11
#define   DMA1_Channel2_INT_NO                      12
#define   DMA1_Channel3_INT_NO                      13
#define   DMA1_Channel4_INT_NO                      14
#define   DMA1_Channel5_INT_NO                      15
#define   DMA1_Channel6_INT_NO                      16
#define   DMA1_Channel7_INT_NO                      17
#define   ADC1_2_INT_NO                             18
#define   USB_HP_CAN_TX_INT_NO                      19
#define   USB_LP_CAN_RX0_INT_NO                     20
#define   CAN_RX1_INT_NO                            21
#define   CAN_SCE_INT_NO                            22
#define   EXTI9_5_INT_NO                            23
#define   TIM1_BRK_INT_NO                           24
#define   TIM1_UP_INT_NO                            25
#define   TIM1_TRG_COM_INT_NO                       26
#define   TIM1_CC_INT_NO                            27
#define   TIM2_INT_NO                               28
#define   TIM3_INT_NO                               29
#define   TIM4_INT_NO                               30
#define   I2C1_EV_INT_NO                            31
#define   I2C1_ER_INT_NO                            32
#define   I2C2_EV_INT_NO                            33
#define   I2C2_ER_INT_NO                            34
#define   SPI1_INT_NO                               35
#define   SPI2_INT_NO                               36
#define   USART1_INT_NO                             37
#define   USART2_INT_NO                             38
#define   USART3_INT_NO                             39
#define   EXTI15_10_INT_NO                          40
#define   RTCAlarm_INT_NO                           41
#define   USBWakeup_INT_NO                          42
#define   TIM8_BRK_INT_NO                           43
#define   TIM8_UP_INT_NO                            44
#define   TIM8_TRG_COM_INT_NO                       45
#define   TIM8_CC_INT_NO                            46
#define   ADC3_INT_NO                               47
#define   FSMC_INT_NO                               48
#define   SDIO_INT_NO                               49
#define   TIM5_INT_NO                               50
#define   SPI3_INT_NO                               51
#define   UART4_INT_NO                              52
#define   UART5_INT_NO                              53
#define   TIM6_INT_NO                               54
#define   TIM7_INT_NO                               55
#define   DMA2_Channel1_INT_NO                      56
#define   DMA2_Channel2_INT_NO                      57
#define   DMA2_Channel3_INT_NO                      58
#define   DMA2_Channel4_5_INT_NO                    59

void MNVIC_voidEnableInterrupt(uint8 Copy_uint8IntNumber);
void MNVIC_voidDisableInterrupt(uint8 Copy_uint8IntNumber);
void MNVIC_voidSetPendingFlag(uint8 Copy_uint8IntNumber);
void MNVIC_voidClearPendingFlag(uint8 Copy_uint8IntNumber);
uint8 MNVIC_uint8GetActiveFlag(uint8 Copy_uint8IntNumber);
void MNVIC_voidSetPeriorty(uint8 Copy_uint8IdInt,uint8 Copy_uint8group_periorty, uint8 Copy__uint8sub_perioty);




#endif
