/**
 * @file EXTI_private.h
 * @author Mohamed Alaa (MohamedAlaaSultan7@gmail.com)
 * @brief Private File (registers definitions)
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//to reduce time only in writing register names
#include <avr/io.h>
 
/**
 * @brief Selection for when the interrupt is triggered
 * 
 */
enum MEXTI_InterruptTriggerModes {
    ON_CHANGE,
    RISING_EDGE,
    FALLING_EDGE,
    ON_LOW
};
/**
 * @brief Select Interrupt source for external Interrupt 
 * 
 */
enum MEXTI_InterruptSource{
    /* External Interrupt 0 -> Pin 2 */
    EXTI0,
    /* External Interrupt 0 -> Pin 2 */
    EXTI1,
};










#endif  /* END of File */