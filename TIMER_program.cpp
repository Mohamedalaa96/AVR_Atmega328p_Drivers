#include <stdint.h>
#include <Arduino.h>

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*Ptr_Callback) (void);
static uint16_t u16Ticks ;

void MTIMER_voidSetTimerPeriodic(void (*Callback) (void), uint16_t copy_u16TicksCont){
  cli();
  TCCR1A = 0;               // Disable operation on match 
  TCCR1B = 0;  
  u16Ticks = copy_u16TicksCont;
  Ptr_Callback = Callback;
  TCNT1 = copy_u16TicksCont;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  sei();     // And put SREG back to what is was with the I bit however it was.
}

void MTIMER_voidEnableInterrupt(){
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
}
void MTIMER_voidDisableInterrupt(){
  TIMSK1 &= (~(1 << TOIE1));
}

 ISR(TIMER1_OVF_vect)        // interrupt service routine - tick every 0.1sec
{
  TCNT1 = u16Ticks;   // set timer
  Ptr_Callback();

}
