
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"
#include "UART_interface.h"
#include "TWI_interface.h"
void setup() {
    
    MTWI_voidInit();  //Set buad rate.
    MUART_voidInit();

 }
 uint8_t x=0;
// the loop function runs over and over again forever
void loop() {

  MTWI_u8BeginTransmission(0x20);
  MTWI_u8TransmitByte(0x40);        // sends five bytes
  MTWI_u8TransmitByte(x);              // sends one byte
  MTWI_voidEndTransmission();    // stop transmitting
    delay(500);

  x++;
}
