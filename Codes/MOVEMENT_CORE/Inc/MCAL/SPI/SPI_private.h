/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F103C8T6                              */
/***********************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*** CR1 ****/
#define    CPHA       0
#define    CPOL       1
#define    MSTR       2
#define    BR0        3
#define    SPE        6
#define    LSBFIRST   7
#define    SS1        8
#define    SSM        9
#define    RXONLY     10
#define    DFF        11

/*** CR2 ***/
#define    TXEIE      7
#define    RXNEIE     6
#define    ERRIE      5
#define    SSOE       2

/*** SR ***/
#define    RXNE       0
#define    TXE        1
#define    CHSIDE     2
#define    UDR        3
#define    CRCERR     4
#define    MODF       5
#define    OVR        6
#define    BSY        7

#define   MSB        0
#define   LSB        1

typedef struct{
    volatile uint32 CR1;
    volatile uint32 CR2;
    volatile uint32 SR;
    volatile uint32 DR;
    volatile uint32 CRCPR;
    volatile uint32 RXCRCR;
    volatile uint32 TXCRCR;
    volatile uint32 I2SCFGR;
    volatile uint32 I2SSPR;
}SPI_t;

//APB2
#define SPI1     ((volatile SPI_t*)(0x40013000))
//APB1
#define SPI2     ((volatile SPI_t*)(0x40003800))


#define  MASTER                 0
#define  SLAVE                  1

#define  ONE_BYTE               0
#define  TWO_BYTES              1

/*peripheral clock*/
#define  F_CLK_BY_2             0b000
#define  F_CLK_BY_4             0b001
#define  F_CLK_BY_8             0b010
#define  F_CLK_BY_16            0b011
#define  F_CLK_BY_32            0b100
#define  F_CLK_BY_64            0b101
#define  F_CLK_BY_128           0b110
#define  F_CLK_BY_256           0b111

#endif
