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

/* OPTIONS : 
    1-  PORT 
        - MGPIO_GPIOB
        - MGPIO_GPIOC
        - MGPIO_GPIOD
    2- Pin 
        - 0 to 7 
    3- Mode 
        - MGPIO_MODE_INPUT
        - MGPIO_MODE_INPUT_PUPD
        - MGPIO_MODE_OUTPUT
*/ 

void MGPIO_voidSetPinMode(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin , uint8_t copy_uint8_tMode);

/* OPTIONS : 
    1-  PORT 
        - MGPIO_GPIOB
        - MGPIO_GPIOC
        - MGPIO_GPIOD
    2- Pin 
        - 0 to 7 
    3- Value 
        - 0 or 1
*/ 

void MGPIO_voidSetPinValue(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin , uint8_t copy_uint8_tValue);

uint8_t MGPIO_uint8_tGetPinValue(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin );


#endif
