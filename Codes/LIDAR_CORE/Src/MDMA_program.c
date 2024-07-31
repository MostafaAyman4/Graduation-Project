/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 28 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/

#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/DMA/MDMA_interface.h"
#include "../Inc/MCAL/DMA/MDMA_private.h"
#include "../Inc/MCAL/DMA/MDMA_config.h"

void MDMA_voidInitChannel(uint8 Copy_uint8channelNum,uint32 Copy_uint32PeripheralAddress,uint32 Copy_uint32MemoryAddress,uint32 Copy_uint32DataNum,uint8 Copy_uint8Periory,uint8 Copy_uint8Direction,uint8 Copy_uint8CircularMode,uint8 Copy_uint8PeripheralIncMode,uint8 Copy_uint8MemoryIncMode,uint8 Copy_uint8PeripheralSize,uint8 Copy_uint8MemorySize,uint8 Copy_uint8Enable_C_Event,uint8 Copy_uint8Enable_H_Event,uint8 Copy_uint8Enable_E_Event){

        /*Make sure that the channel is disabled*/
        CLR_BIT(DMA->Channel[Copy_uint8channelNum].CCR,0);
        /*assign peripheral and memory addresses */
        DMA -> Channel[Copy_uint8channelNum].CPAR = Copy_uint32PeripheralAddress;
        DMA -> Channel[Copy_uint8channelNum].CMAR = Copy_uint32MemoryAddress;
        /*assign number of data send*/
        DMA -> Channel[Copy_uint8channelNum].CNDTR = Copy_uint32DataNum;
        //Set Configuration
        /*Assign periority*/
        DMA ->Channel[Copy_uint8channelNum].CCR &= 0xFFFFCFFF;  //Clear the periory field
        DMA -> Channel[Copy_uint8channelNum].CCR |= Copy_uint8Periory;

        /* Assign Data Transfer Direction*/
        switch (Copy_uint8Direction){
        case READ_FROM_MEMORY:
            SET_BIT(DMA -> Channel[Copy_uint8channelNum].CCR,4);
            break;
        case READ_FROM_PERIPHERAL:
            CLR_BIT(DMA -> Channel[Copy_uint8channelNum].CCR,4);
            break;
        }
        /*Assign circular mode */
        if(Copy_uint8CircularMode ==  CIRCULAR_ENABLE){
            SET_BIT(DMA -> Channel[Copy_uint8channelNum].CCR,5);
        }
        else if(Copy_uint8CircularMode ==  CIRCULAR_DISABLE){
            CLR_BIT(DMA -> Channel[Copy_uint8channelNum].CCR,5);
        }
        else{
            /*Error choosing circular mode*/
        }
        /*Assign Reripheral Increment Mode*/
        if(Copy_uint8PeripheralIncMode == INC_ENABLE){
            SET_BIT(DMA -> Channel[Copy_uint8channelNum].CCR,6);
        }
        else if(Copy_uint8PeripheralIncMode == INC_DISABLE){
            CLR_BIT(DMA -> Channel[Copy_uint8channelNum].CCR,6);
        }
        else{
            //error wrong chose of peripheral increment mode
        }
        /*Assign Memory Increment Mode*/
        if(Copy_uint8MemoryIncMode == INC_ENABLE){
            SET_BIT(DMA -> Channel[Copy_uint8channelNum].CCR,7);
        }
        else if(Copy_uint8MemoryIncMode == INC_DISABLE){
            CLR_BIT(DMA -> Channel[Copy_uint8channelNum].CCR,7);
        }
        else{
            //error wrong chode of Memory increment mode
        }

        /*Assign Peripheral and memory Size*/
        /*clear peripheraland memory size field*/
        DMA ->Channel[Copy_uint8channelNum].CCR &= 0xFFFFF0FF;
        /*assign peripheral size field*/
        DMA -> Channel[Copy_uint8channelNum].CCR |= Copy_uint8PeripheralSize;
        /*Assign Memory Size    */
        DMA -> Channel[Copy_uint8channelNum].CCR |= Copy_uint8MemorySize;
        /*Assign Interrupt Event enable*/
        /*Complete interrupt*/
        if(Copy_uint8Enable_C_Event == INT_ENABLE){
            SET_BIT(DMA->Channel[Copy_uint8channelNum].CCR,1);
        }
        else if(Copy_uint8Enable_C_Event == INT_DISABLE){
            CLR_BIT(DMA->Channel[Copy_uint8channelNum].CCR,1);
        }
        else{
            /*error choosing complete interrupt enable & disable*/
        }
        /*half word interrpt*/
        if(Copy_uint8Enable_H_Event == INT_ENABLE){
            SET_BIT(DMA->Channel[Copy_uint8channelNum].CCR,2);
        }
        else if(Copy_uint8Enable_H_Event == INT_DISABLE){
            CLR_BIT(DMA->Channel[Copy_uint8channelNum].CCR,2);
        }
        else{
            /*error choosing transmit half interrupt enable & disable*/
        }
        /*Error interrput*/
        if(Copy_uint8Enable_E_Event == INT_ENABLE){
            SET_BIT(DMA->Channel[Copy_uint8channelNum].CCR,3);
        }
        else if(Copy_uint8Enable_E_Event == INT_DISABLE){
            CLR_BIT(DMA->Channel[Copy_uint8channelNum].CCR,3);
        }
        else{
            /*error choosing error transmittion interrupt enable & disable*/
}
}
void MDMA_voidEnableChannel(uint8 Copy_uint8ChannelNum){
    SET_BIT(DMA ->Channel[Copy_uint8ChannelNum].CCR,0);
}
void MDMA_voidDisableChannel(uint8 Copy_uint8ChannelNum){
    CLR_BIT(DMA ->Channel[Copy_uint8ChannelNum].CCR,0);
}
