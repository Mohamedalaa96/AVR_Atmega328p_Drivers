/**************************************************************/
/* GPIO Interface FILE                                        */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 8 May 2021                                      */
/* Version  : V001                                            */
/**************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_private.h"


#define MGPIO_MODE_INPUT        0
#define MGPIO_MODE_INPUT_PUPD   1
#define MGPIO_MODE_OUTPUT       2

/**
 * @brief Set GPIO Pin Direction
 * 
 * @param MGPIOx_tPort      Select Port MGPIO_GPIOx, where x is Port Name (A,B,C,D)
 * @param copy_uint8_tPin   Select the Pin 0-7
 * @param copy_uint8_tMode  Select Direction MGPIO_MODE_INPUT,MGPIO_MODE_INPUT_PUPD, MGPIO_MODE_OUTPUT
 */
void MGPIO_voidSetPinMode(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin , uint8_t copy_uint8_tMode);

/**
 * @brief Set Pin Value in the OUTPUT Mode
 * 
 * @param MGPIOx_tPort          Select Port MGPIO_GPIOx, where x is Port Name (A,B,C,D)
 * @param copy_uint8_tPin       Select the Pin [0-7]
 * @param copy_uint8_tValue     Select the Output value [0,1]
 */
void MGPIO_voidSetPinValue(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin , uint8_t copy_uint8_tValue);

/**
 * @brief Read pin value at INPUT or OUTPUT mode
 * 
 * @param MGPIOx_tPort      Select Port MGPIO_GPIOx, where x is Port Name (A,B,C,D)
 * @param copy_uint8_tPin   Select the Pin [0-7
 * @return uint8_t          value of this Pin [0,1]
 */
uint8_t MGPIO_uint8_tGetPinValue(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin );


#endif
