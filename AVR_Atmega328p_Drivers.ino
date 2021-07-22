
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

// the setup function runs once when you press reset or power the board

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  MGPIO_voidSetPinMode(MGPIO_GPIOB,5,MGPIO_MODE_OUTPUT);
  MGPIO_voidSetPinMode(MGPIO_GPIOD,6,MGPIO_MODE_INPUT_PUPD);
}

// the loop function runs over and over again forever
void loop() {
  uint8_t temp = MGPIO_uint8_tGetPinValue(MGPIO_GPIOD, 6 );

   if (temp == 0 )
      MGPIO_voidSetPinValue(MGPIO_GPIOB, 5 , 0);
  else 
      MGPIO_voidSetPinValue(MGPIO_GPIOB, 5 , 1);
}
