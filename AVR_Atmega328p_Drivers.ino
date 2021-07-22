
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"
#include "UART_interface.h"


void setup() {
    MUART_voidInit();
    MUART_voidTransmitString("Hello, World\n");
    


 }

// the loop function runs over and over again forever
void loop() {
  if (MUART_u8isAvailable()){
    char x = MUART_u8ReceiveByte();
    if (x != 10)
      MUART_voidTransmitByte(x+3);
  }

  delay(100);
  }
