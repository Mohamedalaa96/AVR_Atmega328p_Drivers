/**
 * @file ADC_interface.h
 * @author Mohamed Alaa (MohamedAlaaSultan7@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief File Gaurd
 */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"


/**
 * @brief Initialize the ADC and Prescaler
 * @param void
 * @return  void 
 */
void MADC_voidInit(void);

/**
 * @brief Read the channel 
 * 
 * @param copy_u8ChannelNumber channel to read
 * @return u16 analog reading of channel
 */

u16 MADC_u16PoolingRead(u8 copy_u8ChannelNumber);
/**
 * Addons for future work
 * 1- ADC_Asynch
 * 2- Request Temp (via interrupt) 
 * 3- Autotrigger , trigger on interval
 */





/**
 * @brief End of the file
 * 
 */
#endif  