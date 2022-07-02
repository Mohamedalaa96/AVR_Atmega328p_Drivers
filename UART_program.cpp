/**
 * @file UART_program.cpp
 * @author Mohamed Alaa (MohamedAlaaSultan7@Gmail.com)
 * @brief 
 * @version 0.2
 * @date 2022-07-02
 * 0.2 -> changed the register access to struct 
 * @copyright Copyright (c) 2022
 * 
 */
//LOWER LAYERS INCLUDE
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"
/* Driver Header Files Include */
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void MUART_voidInit(void){
  /// Hold the calculated buadrate register value   
  u16 LOCAL_u16BuadEquation = 0;
  /// Hold the value of the UCSR0C Register to      
  /// avoid Multiple (Unnecessry Write operations)  

  ///    BuadRate Calculations & Set Operation Mode 
  #if (MODE_OF_OPERATION == ASYNCHRONOUS)
      #if(SPEED_MODE == SIGNLE_SPEED_MODE)
        LOCAL_u16BuadEquation = (( F_CPU/16/BUADRATE ) -1 );      
      #elif(SPEED_MODE == DOUBLE_SPEED_MODE)
        LOCAL_u16BuadEquation = (( F_CPU/8/BUADRATE ) -1 );
      #endif

      ///    Set ASYNCHRONOUS Mode     
      UCSR0C->UMSEL01 = 0;
      UCSR0C->UMSEL00 = 0 ;

      ///  SELECT Double/Single Tx Rate 
      #if (SPEED_MODE == SIGNLE_SPEED_MODE)
        UCSR0A->U2X0 = 0;
      #elif (SPEED_MODE == DOUBLE_SPEED_MODE)
        UCSR0A->U2X0 = 1;
      #endif

  #elif(MODE_OF_OPERATION == SYNCHRONOUS)
      LOCAL_u16BuadEquation = (( F_CPU/2/BUADRATE ) -1 );
      
      ///    Set SYNCHRONOUS Mode      
      UCSR0C->UMSEL01 = 0;
      UCSR0C->UMSEL00 = 1;

      ///  AT SYNCHRONOUS MODE no double speed  
      UCSR0A->U2X0 = 0;

      ///  CLOCK Polarity Edge Selction   */
      #if (CLK_POLARITY == RX_RISING_EDGE)
        UCSR0C->UCPOL = 1;
      #else
        UCSR0C->UCPOL = 0;
      #endif

  #endif

  UBRR0H = 8 >>LOCAL_u16BuadEquation;
  UBRR0L = (u8)LOCAL_u16BuadEquation;

  ///    No of Stop Bits Selection    
  #if (STOP_BITS == TWO_BITS)
    UCSR0C->USBS0 = 1;
  #else
    UCSR0C->USBS0 = 0;
  #endif
  
  /*      Parity Bit Settings     */
  #if ( PARITY_MODE == DISABLED)
    UCSR0C->UPM01 = 0;
    UCSR0C->UPM00 = 0;
    
  #elif (PARITY_MODE == EVEN)
    UCSR0C->UPM01 = 1;
    UCSR0C->UPM00 = 0;

  #elif (PARITY_MODE == ODD)
    UCSR0C->UPM01 = 1;
    UCSR0C->UPM00 = 1;

  #endif

  #if DATA_BITS_PER_FRAME == BITS_5
    UCSR0C->UCSZ00 = 0;
    UCSR0C->UCSZ01 = 0;
    UCSR0B->UCSZ02 = 0;
  
  #elif DATA_BITS_PER_FRAME == BITS_6
    UCSR0C->UCSZ00 = 1;
    UCSR0C->UCSZ01 = 0;
    UCSR0B->UCSZ02 = 0;

  #elif DATA_BITS_PER_FRAME == BITS_7
    UCSR0C->UCSZ00 = 0;
    UCSR0C->UCSZ01 = 1;
    UCSR0B->UCSZ02 = 0;

  #elif DATA_BITS_PER_FRAME == BITS_8
    UCSR0C->UCSZ00 = 1;
    UCSR0C->UCSZ01 = 1;
    UCSR0B->UCSZ02 = 0;
  
  #elif DATA_BITS_PER_FRAME == BITS_9
    UCSR0C->UCSZ00 = 1;
    UCSR0C->UCSZ01 = 1;
    UCSR0B->UCSZ02 = 1;

  #endif

  /*          Enable TX, RX         */
  UCSR0B->RXEN0 = 1;
  UCSR0B->TXEN0 = 1; 

}

void MUART_voidTransmitByte(u8 copy_u8TransmittedByte){
    
    /* Wait for empty transmit buffer */
    while (!(UCSR0A->UDRE0)); 
    /* Put data into buffer, sends the data */
    UDR0 = copy_u8TransmittedByte;
}
void MUART_voidTransmitString(char * ptr_u8TransmittedString){
    u8 LOCAL_u8CharCounter = 0;
    u8 LOCAL_u8Char = ptr_u8TransmittedString[LOCAL_u8CharCounter];
    while (LOCAL_u8Char != NULL){  //Null Character
      /* Wait for empty transmit buffer */
      while (!(UCSR0A->UDRE0)); 
      /* Transmit the charcter */
      UDR0 = LOCAL_u8Char;
      LOCAL_u8CharCounter++;
      LOCAL_u8Char = ptr_u8TransmittedString[LOCAL_u8CharCounter];
    }
}
u8  MUART_u8isAvailable(void){
  u8 LOCAL_u8ReturnFlag = 0;
  /* Read the Rx Complete Flag */
  LOCAL_u8ReturnFlag = UCSR0A->RXC0;
  return LOCAL_u8ReturnFlag;
}
u8  MUART_u8ReceiveByte(void){
  u8 LOCAL_u8ReceivedByte = UDR0;
  return LOCAL_u8ReceivedByte;


}
