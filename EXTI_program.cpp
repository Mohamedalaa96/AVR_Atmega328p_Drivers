/**
 * @file EXTI_program.cpp
 * @author Mohamed Alaa (MohamedAlaaSultan7@gmail.com)
 * @brief External Interrupt driver
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * Upcomming features : 
 * ON change interrupt on digital pins
 * 
 */
#include "01_SERVICS/BIT_MATH.h"
#include "01_SERVICS/STD_TYPES.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include <avr/interrupt.h>

/**
 * @brief Call back pointer to functions
 * 
 */
static void( * EXTI0_CALLBACK)(void) = 0;
static void( * EXTI1_CALLBACK)(void) = 0;


void MEXTI_u8AttachInterrupt(u8 copy_u8InterruptSource, u8 copy_u8TrigMode , void(* copy_ptrCallBack)(void)){
    u8 Loc_u8InterruptTrigMode = 0;
    switch (copy_u8TrigMode)
    {
    case ON_CHANGE:
        Loc_u8InterruptTrigMode = 1;
        break;
    case FALLING_EDGE:
        Loc_u8InterruptTrigMode = 2;
        break;
    case RISING_EDGE:
        Loc_u8InterruptTrigMode = 3;
        break;
    case ON_LOW:
        Loc_u8InterruptTrigMode = 0; 
        break;
    default:
        break;
    } 
    if (copy_u8InterruptSource == EXTI0){
        //set the trig mode 
        EICRA |= Loc_u8InterruptTrigMode;
        // unmask the interrupt pin
        SET_BIT(EIMSK,INT0); 
        //assign pointer to the call back function
        EXTI0_CALLBACK = copy_ptrCallBack;
    }
    else if (copy_u8InterruptSource == EXTI1){
        //set the trig mode 
        EICRA |= (Loc_u8InterruptTrigMode << 2);
        // unmask the interrupt pin
        SET_BIT(EIMSK,INT1);
        //assign pointer to the call back function
        EXTI1_CALLBACK = copy_ptrCallBack;

    }
    /* Enable Global Interrupt */
    //asm("SEI"); test swaping them
    sei();

}

void MEXTI_u8DetachInterrupt(u8 copy_u8InterruptSource){
    if (copy_u8InterruptSource == EXTI0){
        // mask the interrupt pin
        CLR_BIT(EIMSK,INT0); 
    }
    else if (copy_u8InterruptSource == EXTI1){
        // mask the interrupt pin
        CLR_BIT(EIMSK,INT1);

    }
}


ISR(INT0_vect){
    EXTI0_CALLBACK();
}
ISR(INT1_vect){
    EXTI1_CALLBACK();

}

