/**************************************************************/
/* GPIO PRIVATE FILE                                          */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 8 May 2021                                      */
/* Version  : V001                                            */
/**************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

typedef struct 
{
    volatile uint8_t PINx;
    volatile uint8_t DDRx;
    volatile uint8_t PORTx;
}MGPIOx_t;

#define MGPIO_GPIOB       ( ( (volatile MGPIOx_t * ) 0x23) )
#define MGPIO_GPIOC       ( ( (volatile MGPIOx_t * ) 0x26) )
#define MGPIO_GPIOD       ( ( (volatile MGPIOx_t * ) 0x29) )



#endif
