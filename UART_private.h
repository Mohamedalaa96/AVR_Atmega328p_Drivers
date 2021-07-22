/**************************************************************/
/* UART PRIVATE FILE                                          */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 8 May 2021                                      */
/* Version  : V001                                            */
/**************************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/*  USSR0A  Bits    */
#define RXC0        7   /* UART Receive Complete (Flag) */
#define TXC0        6   /* UART Transmit Complete (Flag) */
#define UDRE0       5   /* UART Data Register Empty (Flag) */
#define FE0         4   /* UART Frame Error  (Flag) */
#define DOR0        3   /* UART Data OverRun (Flag) */
#define UPE0        2   /* UART Parity Error (Flag) */
#define U2X0        1   /* UART Double Transmission Speed Mode */
#define MPCM0       0   /* Multi-Processor Transmission Mode */

/*  USSR0B  Bits    */
#define RXCIE0      7   /* Rx Complete Interrupt Enable */
#define TXCIE0      6   /* Tx Complete Interrupt Enable */
#define UDRIE0      5   /* Data Register Empty Interrupt Enable */ 
#define RXEN0       4   /* UART0 RX Enable */
#define TXEN0       3   /* UART0 TX Enable */
#define UCSZ02      2   /* Character(Frame) Size bit 2 */
#define RXB80       1   /* Received MSB 8th Bit when using 9 bits Frame */
#define TXB80       0   /* Transmit MSB 8th Bit when using 9 bits Frame */

/*  USSR0C  Bits    */
#define UMSEL01     7   /* Mode Select (Async - Sync) Bit 1 */
#define UMSEL00     6   /* Mode Select (Async - Sync) Bit 0 */
#define UPM01       5   /* Parity Mode Bit 1 */
#define UPM00       4   /* Parity Mode Bit 0 */
#define USBS0       3   /* Stop bits selection (0) -> 1 stop bit , (1) -> 2 Stop bits */
#define UCSZ01      2   /* Character(Frame) Size bit 1 */
#define UCSZ00      1   /* Character(Frame) Size bit 0 */
#define UCPOL       0   /* Clock Polarity (Sync Mode Only)  */

/* Register Definition */
#define UCSR0A              ( *(volatile u8 *) (0xC0))    /* UART Control and Status Register A */  
#define UCSR0B              ( *(volatile u8 *) (0xC1))    /* UART Control and Status Register B */  
#define UCSR0C              ( *(volatile u8 *) (0xC2))    /* UART Control and Status Register C */  
#define UBRR0L              ( *(volatile u8 *) (0xC4))    /* Baud Rate Register (LOW)   */
#define UBRR0H              ( *(volatile u8 *) (0xC5))    /* Baud Rate Register (HIGH)   */
#define UDR0                ( *(volatile u8 *) (0xC6))    /* I/O Data Register  */


#endif