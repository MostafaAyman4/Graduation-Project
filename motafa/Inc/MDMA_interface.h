/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 28 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef    MDMA_INTERFACE_H
#define    MDMA_INTERFACE_H

#define             CHANNEL_1       0
#define             CHANNEL_2       1
#define             CHANNEL_3       2
#define             CHANNEL_4       3
#define             CHANNEL_5       4
#define             CHANNEL_6       5
#define             CHANNEL_7       6

#define            VERY_HIGH   0x00003000
#define            HIGH        0x00002000
#define            MEDUIM      0x00001000
#define            LOW         0x00000000

#define             READ_FROM_MEMORY         1
#define             READ_FROM_PERIPHERAL     0

#define             CIRCULAR_ENABLE          0
#define             CIRCULAR_DISABLE         1

#define             INC_ENABLE               0
#define             INC_DISABLE              1

#define             PER_BITS_8                   0x00000000
#define             PER_BITS_16                  0x00000100
#define             PER_BITS_32                  0x00000200

#define             MEM_BITS_8                   0x00000000
#define             MEM_BITS_16                  0x00000400
#define             MEM_BITS_32                  0x00000800

#define             INT_ENABLE                   0
#define            INT_DISABLE                   1

/*
    Copy_uint8channelNum
            options:
                    CHANNEL_1       0
                    CHANNEL_2       1
                    CHANNEL_3       2
                    CHANNEL_4       3
                    CHANNEL_5       4
                    CHANNEL_6       5
                    CHANNEL_7       6

    Copy_uint32PeripheralAddress
    Copy_uint32MemoryAddress
    Copy_uint32DataNum

    Copy_uint8Periory
            options:
                    VERY_HIGH   0x0000 3000
                    HIGH        0x0000 2000
                    MEDUIM      0x0000 1000
                    LOW         0x0000 0000
    Copy_uint8Direction
            options: 
                    READ_FROM_MEMORY         1
                    READ_FROM_PERIPHERAL     0
    Copy_uint8CircularMode
            options:
                    CIRCULAR_ENABLE          0
                    CIRCULAR_DISABLE         1
    Copy_uint8PeripheralIncMode
            options:
                    INC_ENABLE               0
                    INC_DISABLE              1
    Copy_uint8MemoryIncMode
            options:
                    INC_ENABLE               0
                    INC_DISABLE              1
    Copy_uint8PeripheralSize
            options:
                    PER_BITS_8                   0x0000 0000
                    PER_BITS_16                  0x0000 0100
                    PER_BITS_32                  0x0000 0200
    Copy_uint8MemorySize
            options:
                    MEM_BITS_8                   0x0000 0000
                    MEM_BITS_16                  0x0000 0400
                    MEM_BITS_32                  0x0000 0800
    Copy_uint8Enable_C_Event
            options:
                    INT_ENABLE                   0
                    INT_DISABLE                  1
    Copy_uint8Enable_H_Event
            options:
                    INT_ENABLE                   0
                    INT_DISABLE                  1
    Copy_uint8Enable_E_Event
            options:
                    INT_ENABLE                   0
                    INT_DISABLE                  1
    */
   
void MDMA_voidInitChannel(uint8 Copy_uint8channelNum,uint32 Copy_uint32PeripheralAddress,uint32 Copy_uint32MemoryAddress,uint32 Copy_uint32DataNum,uint8 Copy_uint8Periory,uint8 Copy_uint8Direction,uint8 Copy_uint8CircularMode,uint8 Copy_uint8PeripheralIncMode,uint8 Copy_uint8MemoryIncMode,uint8 Copy_uint8PeripheralSize,uint8 Copy_uint8MemorySize,uint8 Copy_uint8Enable_C_Event,uint8 Copy_uint8Enable_H_Event,uint8 Copy_uint8Enable_E_Event);
void MDMA_voidEnableChannel(uint8 Copy_uint8ChannelNum);
void MDMA_voidDisableChannel(uint8 Copy_uint8ChannelNum);

#endif