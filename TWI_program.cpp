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
#include "GPIO_interface.h"


void MTWI_voidInit(){ 
  /* Prepare GPIO pins as Input */

  MGPIO_voidSetPinMode(MGPIO_GPIOC, 4 , MGPIO_MODE_INPUT_PUPD);   //SDA
  MGPIO_voidSetPinMode(MGPIO_GPIOC, 5 , MGPIO_MODE_INPUT_PUPD);   //SCL

  
  /* Set the Baudrate from equation           */     
  /* CPU_F / [16 + (2*(TWBR) * PRE_SCALER )]  */
  
  /* TWBR = 0 & Prescaler = x  ==> 1Mbps   I2C speed */
  /* TWBR = 1 & Prescaler = 16  ==> 333Kbps I2C speed */
  TWBR  = 1;  
  /* Set Prescaler to (10) ==> Prescaler = 16 */ 
  CLR_BIT(TWCR,TWPS0);
  SET_BIT(TWCR,TWPS1);


}
u8 MTWI_u8BeginTransmission(u8 copy_u8Address){   /* Enable, send start condition then Send SLA+W */
  
  /* Clear Interrupt Flag, Send Start Bit , Enable TWI */
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
  /* Wait untill flag rised , so the start sent successfully */
  while (!(TWCR & (1<<TWINT)));
  /* Mask the Status register to get the only status bits 7:3 */
  /* check the error code if isn't matches status code for start */
  if ((TWSR & STATES_MASK) != START_SENT_CODE)
  /* return 0 to indicate error happend in start */   
    return 0;
  /* Load the Address in the MSB 7 bits & (0) for WRITE operation */
  TWDR = copy_u8Address << 1; 
  /* Clear Interrupt flag , Start Transmission */ 
  TWCR = (1<<TWINT) |(1<<TWEN); 
  /* Wait untill flag rised , so the address sent finished */
  while (!(TWCR & (1<<TWINT)));
  /* Check the status code if not equal ACK of Address sent from slave */
  /* return error , else continue */
  if ( (TWSR & STATES_MASK) != SLA_ACK_CODE)
  /* return 0 to indicate error happend address transmission */ 
    return 0;
  /* return 1, if there's no error happend and address sent */
  /* (1) indicate successfull operation */
  return 1;
}
u8 MTWI_u8TransmitByte(u8 copy_u8TransmittedByte){  /* Transmitt data, wait for ACK */
  TWDR = copy_u8TransmittedByte;
  /* Clear the flag, and start the transmission   */
  TWCR = (1 << TWINT ) | (1 << TWEN ); 
  /* Wait untill flag rised , so the data sent finished */
  while (!(TWCR & (1<<TWINT)));
  /* the status code doesn't match the data ack return error */ 
  if ((TWSR & STATES_MASK) != DATA_ACK_CODE )
  /* return error so data not sent */
    return 0;
  /* if there's no error happend, return 1 */
  return 1;
}

/* Transmitt data, wait for ACK */
u8 MTWI_u8TransmitString(char * ptr_u8TransmittedString){
  
  u8 Local_CharCounter = 0;
  
  while (ptr_u8TransmittedString[Local_CharCounter] != 0)
  {
    TWDR = ptr_u8TransmittedString[Local_CharCounter];
    /* Clear the flag, and start the transmission   */
    TWCR = (1 << TWINT ) | (1 << TWEN ); 
    /* Wait untill flag rised , so the data sent finished */
    while (!(TWCR & (1<<TWINT)));
    /* the status code doesn't match the data ack return error */ 
    if ((TWSR & STATES_MASK) != DATA_ACK_CODE )
    /* return error so data not sent */
      return 0;
    Local_CharCounter++;
  }
  
  /* if there's no error happend, return 1 */
  return 1;

}

/* Send stop condition */
void MTWI_voidEndTransmission(){
  /* Send stop bit, enable transmission and clear flag */
  TWCR = (1<< TWINT) | (1 << TWEN) | (1<< TWSTO);
}


