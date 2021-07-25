/**************************************************************/
/* TWI Interface FILE                                        */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 8 May 2021                                      */
/* Version  : V001                                            */
/**************************************************************/
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H



void MTWI_voidInit();
u8 MTWI_u8BeginTransmission(u8 copy_u8Address);
u8 MTWI_u8TransmitByte(u8 copy_u8TransmittedByte);
u8 MTWI_u8TransmitString(char * ptr_u8TransmittedString);
void MTWI_voidEndTransmission();


#endif