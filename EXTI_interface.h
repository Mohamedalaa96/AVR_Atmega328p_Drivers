/**
 * @file EXTI_interface.h
 * @author Mohamed Alaa (MohamedAlaaSultan7@gmail.com)
 * @brief interface file (prototypes)
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H



/**
 * @brief Attach interrupt to call back function
 * 
 * @param copy_u8InterruptSource select interrupt source 
 * Options: ON_CHANGE,RISING_EDGE, FALLING_EDGE, ON_LOW
 * @param copy_u8TrigMode Trigger mode 
 * Options : EXTI0, EXTI1
 * @param copy_ptrCallBack Call back function address
 */
void MEXTI_u8AttachInterrupt(u8 copy_u8InterruptSource, u8 copy_u8TrigMode , void(* copy_ptrCallBack)(void));
/**
 * @brief De-attach the interrupt from the call back and disable it
 * 
 * @param copy_u8InterruptSource select interrupt source
 */
void MEXTI_u8DetachInterrupt(u8 copy_u8InterruptSource);





#endif  /* END of File */