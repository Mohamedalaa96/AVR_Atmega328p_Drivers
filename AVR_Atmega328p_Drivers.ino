
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"
#include "UART_interface.h"

// the setup function runs once when you press reset or power the board

void setup() {
    MUART_voidInit();
 }

// the loop function runs over and over again forever
void loop() {
  MUART_voidTransmitByte('a');
  MUART_voidTransmitByte('\n');

  delay(100);
  }
