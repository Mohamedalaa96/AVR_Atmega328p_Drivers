/**************************************************************/
/* UART Prog FILE                                             */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 21 Jul 2021                                     */
/* Version  : V001                                            */
/**************************************************************/

//LOWER LAYERS INCLUDE
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver Header Files Include */
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void MUART_voidInit(void){
    
  //UCSR0A = 
  /* Set the Baud Rate to 9600 with FOSC 16Mhz */
  UBRR0L = 103;
  UCSR0B = 1<< RXEN0 | 1<< TXEN0 ; 
  UCSR0C = 1 <<UCSZ01 | 1 <<UCSZ00; //7 bits

}

void MUART_voidTransmitByte(u8 copy_u8TransmittedByte);

u8  MUART_u8ReceiveByte(void);
