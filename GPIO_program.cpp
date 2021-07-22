/**************************************************************/
/* GPIO Prog FILE                                             */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 8 May 2021                                      */
/* Version  : V001                                            */
/**************************************************************/

//LOWER LAYERS INCLUDE
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"

/* Driver Header Files Include */
#include "GPIO_interface.h"
#include "GPIO_private.h"
//#include "GPIO_config.h"

void MGPIO_voidSetPinMode(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin , uint8_t copy_uint8_tMode)
{
    
    if      (copy_uint8_tMode == MGPIO_MODE_INPUT)       {CLR_BIT(MGPIOx_tPort->DDRx,copy_uint8_tPin);}
    else if (copy_uint8_tMode == MGPIO_MODE_INPUT_PUPD)  {CLR_BIT(MGPIOx_tPort->DDRx,copy_uint8_tPin); 
                                                         SET_BIT(MGPIOx_tPort->PORTx,copy_uint8_tPin);}
    else if (copy_uint8_tMode == MGPIO_MODE_OUTPUT)      {SET_BIT(MGPIOx_tPort->DDRx,copy_uint8_tPin);}        
    
}
void MGPIO_voidSetPinValue(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin , uint8_t copy_uint8_tValue)
{
    if      (copy_uint8_tValue == 0)       {CLR_BIT(MGPIOx_tPort->PORTx,copy_uint8_tPin);}
    else                              {SET_BIT(MGPIOx_tPort->PORTx,copy_uint8_tPin);}        
        
}

uint8_t MGPIO_uint8_tGetPinValue(MGPIOx_t * MGPIOx_tPort, uint8_t copy_uint8_tPin )
{
    uint8_t Local_uint8_tValue = 0;
    Local_uint8_tValue = GET_BIT(MGPIOx_tPort->PINx,copy_uint8_tPin);
    return Local_uint8_tValue; 
}
