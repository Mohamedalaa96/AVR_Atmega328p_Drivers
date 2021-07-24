/**************************************************************/
/* TWI Prog FILE                                             */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 21 Jul 2021                                     */
/* Version  : V001                                            */
/**************************************************************/

//LOWER LAYERS INCLUDE
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"
/* Driver Header Files Include */
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"


void MTWI_voidInit(void){
  /* Hold the calculated buadrate register value   */
  u16 LOCAL_u16BuadEquation = 0;
  /* Hold the value of the UCSR0C Register to      */
  /* avoid Multiple (Unnecessry Write operations)  */
  u8  LOCAL_u8UCSR0C_Temp = 0 ; 

  /*    BuadRate Calculations & Set Operation Mode  */
  #if (MODE_OF_OPERATION == ASYNCHRONOUS)
      #if(SPEED_MODE == SIGNLE_SPEED_MODE)
        LOCAL_u16BuadEquation = (( F_CPU/16/BUADRATE ) -1 );      
      #elif(SPEED_MODE == DOUBLE_SPEED_MODE)
        LOCAL_u16BuadEquation = (( F_CPU/8/BUADRATE ) -1 );
      #endif

      /*    Set ASYNCHRONOUS Mode     */
      CLR_BIT(LOCAL_u8UCSR0C_Temp,UMSEL01);
      CLR_BIT(LOCAL_u8UCSR0C_Temp,UMSEL00);

      /*  SELECT Double/Single Tx Rate */
      #if (SPEED_MODE == SIGNLE_SPEED_MODE)
        CLR_BIT(UCSR0A,U2X0);
      #elif (SPEED_MODE == DOUBLE_SPEED_MODE)
        SET_BIT(UCSR0A,U2X0);
      #endif

  #elif(MODE_OF_OPERATION == SYNCHRONOUS)
      LOCAL_u16BuadEquation = (( F_CPU/2/BUADRATE ) -1 );
      
      /*    Set SYNCHRONOUS Mode      */
      CLR_BIT(LOCAL_u8UCSR0C_Temp,UMSEL01);
      SET_BIT(LOCAL_u8UCSR0C_Temp,UMSEL00);

      /*  AT SYNCHRONOUS MODE no double speed  */
      CLR_BIT(UCSR0A,U2X0);

      /*  CLOCK Polarity Edge Selction   */
      #if (CLK_POLARITY == RX_RISING_EDGE)
        SET_BIT(LOCAL_u8UCSR0C_Temp,UCPOL);
      #else
        CLR_BIT(LOCAL_u8UCSR0C_Temp,UCPOL);
      #endif

  #endif

  UBRR0H = 8 >>LOCAL_u16BuadEquation;
  UBRR0L = (u8)LOCAL_u16BuadEquation;

  /*    No of Stop Bits Selection    */
  #if (STOP_BITS == TWO_BITS)
    SET_BIT(LOCAL_u8UCSR0C_Temp,USBS0);
  #else
    CLR_BIT(LOCAL_u8UCSR0C_Temp,USBS0);
  #endif
  
  /*      Parity Bit Settings     */
  #if ( PARITY_MODE == DISABLED)
    CLR_BIT(LOCAL_u8UCSR0C_Temp,UPM01);
    CLR_BIT(LOCAL_u8UCSR0C_Temp,UPM00);
    
  #elif (PARITY_MODE == EVEN)
    SET_BIT(LOCAL_u8UCSR0C_Temp,UPM01);
    CLR_BIT(LOCAL_u8UCSR0C_Temp,UPM00);

  #elif (PARITY_MODE == ODD)
    SET_BIT(LOCAL_u8UCSR0C_Temp,UPM01);
    SET_BIT(LOCAL_u8UCSR0C_Temp,UPM00);

  #endif

  #if DATA_BITS_PER_FRAME == BITS_5
    CLR_BIT(LOCAL_u8UCSR0C_Temp,UCSZ00);
    CLR_BIT(LOCAL_u8UCSR0C_Temp,UCSZ01);
    CLR_BIT(LOCAL_u8UCSR0C_Temp,UCSZ02);
  
  #elif DATA_BITS_PER_FRAME == BITS_6
    SET_BIT(LOCAL_u8UCSR0C_Temp,UCSZ00);
    CLR_BIT(LOCAL_u8UCSR0C_Temp,UCSZ01);
    CLR_BIT(UCSR0B,UCSZ02);

  #elif DATA_BITS_PER_FRAME == BITS_7
    CLR_BIT(LOCAL_u8UCSR0C_Temp,UCSZ00);
    SET_BIT(LOCAL_u8UCSR0C_Temp,UCSZ01);
    CLR_BIT(UCSR0B,UCSZ02);

  #elif DATA_BITS_PER_FRAME == BITS_8
    SET_BIT(LOCAL_u8UCSR0C_Temp,UCSZ00);
    SET_BIT(LOCAL_u8UCSR0C_Temp,UCSZ01);
    CLR_BIT(UCSR0B,UCSZ02);
  
  #elif DATA_BITS_PER_FRAME == BITS_9
    SET_BIT(LOCAL_u8UCSR0C_Temp,UCSZ00);
    SET_BIT(LOCAL_u8UCSR0C_Temp,UCSZ01);
    SET_BIT(UCSR0B,UCSZ02);

  #endif

  /*          Enable TX, RX         */
  UCSR0B = (1<< RXEN0) | (1<< TXEN0) ; 
  UCSR0C = LOCAL_u8UCSR0C_Temp; 

}

void MTWI_voidTransmitByte(u8 copy_u8TransmittedByte){
    
    /* Wait for empty transmit buffer */
    while (!GET_BIT(UCSR0A,UDRE0)); 
    /* Put data into buffer, sends the data */
    UDR0 = copy_u8TransmittedByte;
}
void MTWI_voidTransmitString(char * ptr_u8TransmittedString){
    u8 LOCAL_u8CharCounter = 0;
    u8 LOCAL_u8Char = ptr_u8TransmittedString[LOCAL_u8CharCounter];
    while (LOCAL_u8Char != NULL){  //Null Character
      /* Wait for empty transmit buffer */
      while (!GET_BIT(UCSR0A,UDRE0)); 
      /* Transmit the charcter */
      UDR0 = LOCAL_u8Char;
      LOCAL_u8CharCounter++;
      LOCAL_u8Char = ptr_u8TransmittedString[LOCAL_u8CharCounter];
    }
}
u8  MTWI_u8isAvailable(void){
  u8 LOCAL_u8ReturnFlag = 0;
  /* Read the Rx Complete Flag */
  LOCAL_u8ReturnFlag = GET_BIT(UCSR0A,RXC0);
  return LOCAL_u8ReturnFlag;
}
u8  MTWI_u8ReceiveByte(void){
  u8 LOCAL_u8ReceivedByte = UDR0;
  return LOCAL_u8ReceivedByte;


}
