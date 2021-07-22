/**************************************************************/
/* UART Prog FILE                                             */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 21 Jul 2021                                     */
/* Version  : V001                                            */
/**************************************************************/

//LOWER LAYERS INCLUDE
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"
/* Driver Header Files Include */
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void MUART_voidInit(void){
    
  /* Set the Baud Rate to 9600 with FOSC 16Mhz */
  UBRR0L = 103;
  UCSR0B = 1<< RXEN0 | 1<< TXEN0 ; 
  UCSR0C = 1 <<UCSZ01 | 1 <<UCSZ00; //7 bits

}

void MUART_voidTransmitByte(u8 copy_u8TransmittedByte){
    
    /* Wait for empty transmit buffer */
    while (!GET_BIT(UCSR0A,UDRE0)); 
    /* Put data into buffer, sends the data */
    UDR0 = copy_u8TransmittedByte;
}

u8  MUART_u8ReceiveByte(void);
