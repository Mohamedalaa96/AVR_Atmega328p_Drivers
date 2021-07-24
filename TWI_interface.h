/**************************************************************/
/* TWI Interface FILE                                        */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 8 May 2021                                      */
/* Version  : V001                                            */
/**************************************************************/
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H


#define MTWI_BUADRATE      (9600)

void MTWI_voidInit(void);

void MTWI_voidTransmitByte(u8 copy_u8TransmittedByte);
void MTWI_voidTransmitString(char * ptr_u8TransmittedString);
u8  MTWI_u8isAvailable(void);
u8  MTWI_u8ReceiveByte(void);


#endif