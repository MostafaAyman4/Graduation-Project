/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 18 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/

#ifndef   DIO_INTERFACE_H
#define   DIO_INTERFACE_H

/*					      PORTS                           */
#define		 PORTA                                      0
#define 	 PORTB					                    1
#define      PORTC                  					2
/*					      PINS                           */
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

/*				     	       VALUES                             */
#define     HIGH											1
#define     LOW												0

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


void  MDIO_INIT(uint8 copy_uint8Port);
void  MDIO_voidSetDirection(uint8 copy_uint8Port,uint8 copy_uint8Pin, uint8 copy_uint8Mode);
void  MDIO_voidWrite_D_pin(uint8 copy_uint8Port,uint8 copy_uint8Pin, uint8 copy_uint8Value);
uint8 MDIO_uint8Read_D_pin(uint8 copy_uint8Port,uint8 copy_uint8Pin);
void  MDIO_voidSET_NRMR_pin(uint8 copy_uint8Port,uint32 copy_uint32pin);
void  MDIO_voidCLR_NRMR_pin(uint8 copy_uint8Port,uint32 copy_uint32pin);

#endif
