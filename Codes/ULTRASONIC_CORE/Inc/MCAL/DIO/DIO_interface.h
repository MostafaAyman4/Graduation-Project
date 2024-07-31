/*
 * @file   		DIO_interface.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		18 AUG 2023
 * @MC          STM32F103x
 * @brief       this file be used for user interface
 */

/*define to prevent recursive inclusion*/
#ifndef   DIO_INTERFACE_H
#define   DIO_INTERFACE_H
/*####################### HOW TO USE THIS DRIVER ##########################
 * 		-enable the GPIO CLOCK from RCC (already initiated in this driver)
 * 		-set the direction of pin even in DIO OR AF
 * 		-output OR red digital values to pins
 * ########################################################################
 */
/*
 * @ref copy_uint8Port
 */
#define		 PORTA                                      0
#define 	 PORTB					                    1
#define      PORTC                  					2
/*
 * @ref copy_uint8Pin
 */
#define      PIN0										0
#define      PIN1										1
#define      PIN2										2
#define      PIN3										3
#define      PIN4										4
#define      PIN5										5
#define      PIN6										6
#define      PIN7										7
#define      PIN8										8
#define      PIN9										9
#define      PIN10										10
#define      PIN11										11
#define      PIN12										12
#define      PIN13										13
#define      PIN14										14
#define      PIN15										15

/*
 * @ref copy_uint8Mode
 */
/*					      OUTPUT MODES                           */
#define      OUTPUT_10MHZ_PUSH_PULL							0b0001
#define      OUTPUT_10MHZ_OPEN_DRAIN                        0b0101
#define      AF_10MHZ_PUSH_PULL								0b1001
#define      AF_10MHZ_OPEN_DRAIN							0b1101

#define      OUTPUT_2MHZ_PUSH_PULL							0b0010
#define      OUTPUT_2MHZ_OPEN_DRAIN							0b0110
#define      AF_2MHZ_PUSH_PULL								0b1010
#define      AF_2MHZ_OPEN_DRAIN								0b1110

#define      OUTPUT_50MHZ_PUSH_PULL                         0b0011
#define      OUTPUT_50MHZ_OPEN_DRAIN						0b0111
#define      AF_50MHZ_PUSH_PULL                             0b1011
#define      AF_50MHZ_OPEN_DRAIN							0b1111

/*					       INPUT MODES                           */
#define 	INPUT_ANALOG									0b0000
#define    	INPUT_FLOATING									0b0100
#define 	INPUT_PULL_DOWN									0b1000
#define		INPUT_PULL_UP								    0b1000
/*
 * @ref copy_uint8Value
 */
#define     HIGH											1
#define     LOW												0

/*
 * @ref copy_uint32pin
 */
/*				           NRMR PINS                             */
#define  	PIN0_NRMR                                      0b000000000000000000000000000000001
#define  	PIN1_NRMR                                      0b000000000000000000000000000000010
#define  	PIN2_NRMR                                      0b000000000000000000000000000000100
#define  	PIN3_NRMR                                      0b000000000000000000000000000001000
#define  	PIN4_NRMR                                      0b000000000000000000000000000010000
#define  	PIN5_NRMR                                      0b000000000000000000000000000100000
#define  	PIN6_NRMR                                      0b000000000000000000000000001000000
#define  	PIN7_NRMR                                      0b000000000000000000000000010000000
#define  	PIN8_NRMR                                      0b000000000000000000000000100000000
#define  	PIN9_NRMR                                      0b000000000000000000000001000000000
#define  	PIN10_NRMR                                     0b000000000000000000000010000000000
#define  	PIN11_NRMR                                     0b000000000000000000000100000000000
#define  	PIN12_NRMR                                     0b000000000000000000001000000000000
#define  	PIN13_NRMR                                     0b000000000000000000010000000000000
#define  	PIN14_NRMR                                     0b000000000000000000100000000000000
#define  	PIN15_NRMR                                     0b000000000000000001000000000000000

/*
 * @FUNC_name	MDIO_INIT(uint8 copy_uint8Port)
 * @brief	this function initiate DIO and set configurations
 * @param   -copy_uint8Port
 * 				this variable is used to select the port you want to initiate, can be a value of @ref copy_uint8Port
 * @retval	NONE
 */
/*
 * @FUNC_name	MDIO_voidSetDirection(uint8 copy_uint8Port,uint8 copy_uint8Pin, uint8 copy_uint8Mode)
 * @brief	this function is used to set the direction of ports
 * @param   -copy_uint8Port
 * 				this variable is used to select the port you want to initiate, can be a value of @ref copy_uint8Port
 * 			-copy_uint8Pin
 * 				this variable is used to select the pin u want to use, can be a value of @ref copy_uint8Pin
 * 			-copy_uint8Mode
 * 				this variable is used to select mode, can be a value of @ref copy_uint8Mode
 * @retval	NONE
 */
/*
 * @FUNC_name	MDIO_voidWrite_D_pin(uint8 copy_uint8Port,uint8 copy_uint8Pin, uint8 copy_uint8Value)
 * @brief	this function is used to output an digital value to a specific pin
 * @param   -copy_uint8Port
 * 				this variable is used to select the port you want to initiate, can be a value of @ref copy_uint8Port
 * 			-copy_uint8Pin
 * 				this variable is used to select the pin u want to use, can be a value of @ref copy_uint8Pin
 * 			-copy_uint8Value
 * 				this variable is used to select value u want to write it, can be a value of @ref copy_uint8Value
 * @retval	NONE
 */
/*
 * @FUNC_name	MDIO_uint8Read_D_pin(uint8 copy_uint8Port,uint8 copy_uint8Pin)
 * @brief	this function is used to read a specific pin digital value
 * @param   -copy_uint8Port
 * 				this variable is used to select the port you want to initiate, can be a value of @ref copy_uint8Port
 * 			-copy_uint8Pin
 * 				this variable is used to select the pin u want to use, can be a value of @ref copy_uint8Pin
 * @retval	it return a pin value
 */
/*
 * @FUNC_name	MDIO_voidSET_NRMR_pin(uint8 copy_uint8Port,uint32 copy_uint32pin)
 * @brief	this function is used to set a specific pin value directly without read modify write
 * @param   -copy_uint8Port
 * 				this variable is used to select the port you want to initiate, can be a value of @ref copy_uint8Port
 * 			-copy_uint8Pin
 * 				this variable is used to select the pin u want to use, can be a value of @ref copy_uint8Pin
 * @retval	NONE
 */
/*
 * @FUNC_name	MDIO_voidCLR_NRMR_pin(uint8 copy_uint8Port,uint32 copy_uint32pin)
 * @brief	this function is used to clear a specific pin value directly without read modify write
 * @param   -copy_uint8Port
 * 				this variable is used to select the port you want to initiate, can be a value of @ref copy_uint8Port
 * 			-copy_uint8Pin
 * 				this variable is used to select the pin u want to use, can be a value of @ref copy_uint8Pin
 * @retval	NONE
 */

void  MDIO_INIT(uint8 copy_uint8Port);
void  MDIO_voidSetDirection(uint8 copy_uint8Port,uint8 copy_uint8Pin, uint8 copy_uint8Mode);
void  MDIO_voidWrite_D_pin(uint8 copy_uint8Port,uint8 copy_uint8Pin, uint8 copy_uint8Value);
uint8 MDIO_uint8Read_D_pin(uint8 copy_uint8Port,uint8 copy_uint8Pin);
void  MDIO_voidSET_NRMR_pin(uint8 copy_uint8Port,uint32 copy_uint32pin);
void  MDIO_voidCLR_NRMR_pin(uint8 copy_uint8Port,uint32 copy_uint32pin);

#endif
