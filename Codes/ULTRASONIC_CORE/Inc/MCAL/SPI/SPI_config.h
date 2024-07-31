/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F103C8T6                              */
/***********************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*
        options:
                MASTER
                SLAVE
                */

#define SPI1_MODE      MASTER
#define SPI2_MODE      MASTER

/*MSB-LSB*/
#define SPI1_DATA_DIRECTION		MSB
#define SPI2_DATA_DIRECTION     MSB


/*
        options
                ONE_BYTE
                TWO_BYTES
                */
#define SPI1_DATA_FRAME_SIZE      ONE_BYTES
#define SPI2_DATA_FRAME_SIZE      TWO_BYTES
/*
        options:
                F_CLK_BY_2
                F_CLK_BY_4
                F_CLK_BY_8
                F_CLK_BY_16
                F_CLK_BY_32
                F_CLK_BY_64
                F_CLK_BY_128
                F_CLK_BY_256
                */
#define SPI1_BAUDRATE               F_CLK_BY_2
#define SPI2_BAUDRATE               F_CLK_BY_2

#endif
