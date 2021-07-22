/**************************************************************/
/* UART Interface FILE                                        */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 8 May 2021                                      */
/* Version  : V001                                            */
/**************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


#define MUART_BUADRATE      (9600)

void MUART_voidInit(void);

void MUART_voidTransmitByte(u8 copy_u8TransmittedByte);

u8  MUART_u8ReceiveByte(void);


#endif