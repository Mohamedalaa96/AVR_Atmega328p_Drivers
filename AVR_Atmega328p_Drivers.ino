
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"
#include "UART_interface.h"
#include "ADC_interface.h"

void setup() {
    
    MUART_voidInit();
    MADC_voidInit();
    pinMode(13,OUTPUT);
 }
// the loop function runs over and over again forever
void loop() {
  u16 reading = MADC_u16PoolingRead(0);
  if (reading > 512 )
    digitalWrite(13,HIGH);
  else
    digitalWrite(13,LOW);

  
}
