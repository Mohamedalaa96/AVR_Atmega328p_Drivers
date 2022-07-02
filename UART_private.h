/**
 * @file UART_private.h
 * @author Mohamed Alaa (MohamedAlaaSultan7@Gmail.com)
 * @brief MCAL Uart driver private file
 * @version 0.2
 * @date 2021-05-08
 * 0.2 -> changed the register access to struct 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define NULL 0


typedef struct 
{
    u8 UCPOL   :1;    /** \brief Clock Polarity (Sync Mode Only)  */
    u8 UCSZ00  :1;    /** \brief Character(Frame) Size bit 0 */
    u8 UCSZ01  :1;    /** \brief Character(Frame) Size bit 1 */
    u8 USBS0   :1;    /** \brief Stop bits selection (0) -> 1 stop bit , (1) -> 2 Stop bits */
    u8 UPM00   :1;    /** \brief Parity Mode Bit 0 */
    u8 UPM01   :1;    /** \brief Parity Mode Bit 1 */
    u8 UMSEL00 :1;    /** \brief Mode Select (Async - Sync) Bit 0 */
    u8 UMSEL01 :1;    /** \brief Mode Select (Async - Sync) Bit 1 */
}USSR0C_Reg;

typedef struct 
{
    u8 TXB80    :1;   /** \brief  Transmit MSB 8th Bit when using 9 bits Frame */
    u8 RXB80    :1;   /** \brief  Received MSB 8th Bit when using 9 bits Frame */
    u8 UCSZ02   :1;   /** \brief  Character(Frame) Size bit 2                  */
    u8 TXEN0    :1;   /** \brief  UART0 TX Enable                              */
    u8 RXEN0    :1;   /** \brief  UART0 RX Enable                              */
    u8 UDRIE0   :1;   /** \brief  Data Register Empty Interrupt Enable         */
    u8 TXCIE0   :1;   /** \brief  Tx Complete Interrupt Enable                 */
    u8 RXCIE0   :1;   /** \brief  Rx Complete Interrupt Enable                 */

}USSR0B_Reg;

typedef struct 
{
    u8 MPCM0    :1;   /** \brief  Multi-Processor Transmission Mode     */
    u8 U2X0     :1;   /** \brief  UART Double Transmission Speed Mode   */
    u8 UPE0     :1;   /** \brief  UART Parity Error (Flag)              */
    u8 DOR0     :1;   /** \brief  UART Data OverRun (Flag)              */
    u8 FE0      :1;   /** \brief  UART Frame Error  (Flag)              */
    u8 UDRE0    :1;   /** \brief  UART Data Register Empty (Flag)       */
    u8 TXC0     :1;   /** \brief  UART Transmit Complete (Flag)         */
    u8 RXC0     :1;   /** \brief  UART Receive Complete (Flag)          */

}USSR0A_Reg;

/* Register Definition */
#define UCSR0A              ( (volatile USSR0A_Reg *) (0xC0))    /** \brief  UART Control and Status Register A */
#define UCSR0B              ( (volatile USSR0B_Reg *) (0xC1))    /** \brief  UART Control and Status Register B */  
#define UCSR0C              ( (volatile USSR0C_Reg *) (0xC2))    /** \brief  UART Control and Status Register C */  
#define UBRR0L              ( *(volatile u8 *) (0xC4))           /** \brief  Baud Rate Register (LOW)   */
#define UBRR0H              ( *(volatile u8 *) (0xC5))           /** \brief  Baud Rate Register (HIGH)   */
#define UDR0                ( *(volatile u8 *) (0xC6))           /** \brief  I/O Data Register  */

/* Configuration Paramitters */


#define ASYNCHRONOUS	        1
#define SYNCHRONOUS             3


#define SIGNLE_SPEED_MODE       1
#define DOUBLE_SPEED_MODE       3



#define ONE_BIT                 1
#define TWO_BITS                3

#define DISABLED                1
#define EVEN                    3
#define ODD                     5


#define BITS_5                  1
#define BITS_6                  3
#define BITS_7                  5
#define BITS_8                  7
#define BITS_9                  9
                                        

#define RX_RISING_EDGE          1 
#define RX_FALLING_EDGE         3
 


#endif
