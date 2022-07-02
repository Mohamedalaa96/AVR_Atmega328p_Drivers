/**
 * @file UART_interface.h
 * @author Mohamed Alaa (MohamedAlaaSultan7@Gmail.com)
 * @brief MCAL Uart driver interface file
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


#define MUART_BUADRATE      (9600)
/**
 * @brief Initialize UART with defined Buadrare wuth MUART_BAUDRATE
 * 
 */
void MUART_voidInit(void);
/**
 * @brief Transmitt one byte via UART
 * 
 * @param copy_u8TransmittedByte byte to be transmitted
 */
void MUART_voidTransmitByte(u8 copy_u8TransmittedByte);

/**
 * @brief Trasnmitt string via UART
 * 
 * @param ptr_u8TransmittedString Ptr to string to transmit 
 */
void MUART_voidTransmitString(char * ptr_u8TransmittedString);

/**
 * @brief is UART data available ?
 * 
 * @return u8 1-> data available to read, 0-> no data available
 */
u8  MUART_u8isAvailable(void);

/**
 * @brief Read single byte from UART
 * 
 * @return u8 byte from the buffer
 */
u8  MUART_u8ReceiveByte(void);


#endif