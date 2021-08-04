/**
 * @file ADC_program.cpp
 * @author Mohamed Alaa (MohamedAlaaSultan7@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "01_SERVICS/BIT_MATH.h"
#include "01_SERVICS/STD_TYPES.h"

#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"

/**
 * @brief Initialize the ADC and Prescaler
 * 
 */
void MADC_voidInit(void){
    //local variable to hold register value to avoid multiple mem access.
    u8 LOC_u8ADCSRA = 0;
    //SET V Referance to external AVCC
    SET_BIT(ADMUX,REFS0);
    //Enable ADC 
    SET_BIT(LOC_u8ADCSRA,ADEN);
    // Select Prescaler automatically

    //if prescaler = 2 in the range of 50 to 200KHz 
    #if F_CPU/2 >= ADC_MIN_FREQ && F_CPU/2 <= ADC_MAX_FREQ
        LOC_u8ADCSRA |= (1 << ADPS0); 

    #elif F_CPU/4 >= ADC_MIN_FREQ && F_CPU/4 <= ADC_MAX_FREQ
        LOC_u8ADCSRA |= (1 << ADPS1); 

    #elif F_CPU/8 >= ADC_MIN_FREQ && F_CPU/8 <= ADC_MAX_FREQ
        LOC_u8ADCSRA |= (1 << ADPS1) | (1 << ADPS0); 

    #elif F_CPU/16 >= ADC_MIN_FREQ && F_CPU/16 <= ADC_MAX_FREQ
        LOC_u8ADCSRA |= (1 << ADPS2) ; 

    #elif F_CPU/32 >= ADC_MIN_FREQ && F_CPU/32 <= ADC_MAX_FREQ
        LOC_u8ADCSRA |= (1 << ADPS2) | (1 << ADPS0) ;

    #elif F_CPU/64 >= ADC_MIN_FREQ && F_CPU/64 <= ADC_MAX_FREQ
        LOC_u8ADCSRA |= (1 << ADPS2) | (1 << ADPS1) ; 

    #elif F_CPU/128 >= ADC_MIN_FREQ && F_CPU/128 <= ADC_MAX_FREQ
        LOC_u8ADCSRA |= (1 << ADPS2) | (1 << ADPS1)  | (1 << ADPS0) ; 
    #else
        #error "No valid ADC_PRESCALER found!"
    #endif

    //Clear Interrupt flag 
    SET_BIT(LOC_u8ADCSRA,ADIF);

    //assign the value to the register
    ADCSRA = LOC_u8ADCSRA;

}
/**
 * @brief 
 * 
 * @param copy_u8ChannelNumber channel to scan
 * @return u16 
 */

u16 MADC_u16PoolingRead(u8 copy_u8ChannelNumber){
    //Disable Digital Input buffer from the pin
    //Reduces power consumption 
    SET_BIT(DIDR0,copy_u8ChannelNumber);

    //select channel (0:7)
    ADMUX |= copy_u8ChannelNumber ;

    // ADSC set start conversation 
    SET_BIT(ADCSRA,ADSC);

    // wait untill it gets low aka conversation completed
    while(GET_BIT(ADCSRA,ADSC) == 1);

    u16 Loc_u16Reading;
    //Read ADCL
    Loc_u16Reading = ADCL;
    //Read ADCH
    Loc_u16Reading |= (ADCH << 8 );

    //Enable back Digital Input buffer from the pin 
    CLR_BIT(DIDR0,copy_u8ChannelNumber);

    //Clear Interrupt Flag
    SET_BIT(ADCSRA,ADIF);
    
    return Loc_u16Reading;

}