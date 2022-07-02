
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"
#include "UART_interface.h"
#include "ADC_interface.h"
#include "EXTI_interface.h"
#include "GPIO_interface.h"
#include "HLCD_16x2_interface.h"
#include <stdlib.h>

void ToggleLED(){
  MGPIO_voidTogglePin(MGPIO_GPIOB,5);
}
void setup() {
    
    MUART_voidInit();
    MADC_voidInit();

    MGPIO_voidSetPinMode(MGPIO_GPIOB,5,MGPIO_MODE_OUTPUT);
    MTIMER_voidEnableInterrupt();
    MTIMER_voidSetTimerPeriodic(ToggleLED,SECOND_TO_TICK(1));
 }
// the loop function runs over and over again forever
void loop() {
  static uint8_t i = 0;
  char buffer[10]={0}; 
  intToString(MADC_u16PoolingRead(6),buffer);
  MUART_voidTransmitString(buffer);
  MUART_voidTransmitString(" ,Hello\n\r");
  MTIMER_voidDelay_ms(1000);
}

void intToString(u16 copy_int , char * ptr_u8String){
  u16 local_temp = (copy_int / 1000);
  if (local_temp != 0){
    ptr_u8String[0] = local_temp+'0';
    copy_int-= local_temp*1000;

    local_temp = (copy_int / 100);
    ptr_u8String[1] = local_temp+'0';
    copy_int-= local_temp*100;

    local_temp = (copy_int / 10);
    ptr_u8String[2] = local_temp+'0';
    copy_int-= local_temp*10;

    ptr_u8String[3] = copy_int+'0';
    ptr_u8String[4] = 0;
  }
  else if ((copy_int / 100) != 0){
    local_temp = (copy_int / 100);
    ptr_u8String[0] = local_temp+'0';
    copy_int-= local_temp*100;

    local_temp = (copy_int / 10);
    ptr_u8String[1] = local_temp +'0' ;
    copy_int-= local_temp*10;

    ptr_u8String[2] = copy_int + '0';
    ptr_u8String[3] = 0;

  }
  else if ((copy_int / 10) != 0){

    local_temp = (copy_int / 10);
    ptr_u8String[0] = local_temp+'0';
    copy_int-= local_temp*10;

    ptr_u8String[1] = copy_int+'0';
    ptr_u8String[2] = 0;
  }
  else {
    ptr_u8String[0] = copy_int+'0';
    ptr_u8String[1] = 0;

  }
}
