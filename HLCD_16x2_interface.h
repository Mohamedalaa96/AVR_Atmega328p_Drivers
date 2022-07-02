 #ifndef _HLCD_16x2_INTERFACE_H
 #define _HLCD_16x2_INTERFACE_H


#include "HLCD_16x2_Private.h"
#include "HLCD_16x2_Config.h"
#include "GPIO_interface.h"
#include "TIMER_interface.h"

/* Public user usable functions */
void HLCD_voidInit();
void HLCD_voidSendString(u8 * prt_u8String);
void HLCD_voidSendCharcter(u8 prt_u8Char);
void HLCD_voidClearDisplay();
void HLCD_voidGoToColRow(u8 cpy_u8Col, u8 cpy_u8Row);

/* Private Functions for internal usage */
void HLCD_voidSendCommand(u8 cpy_u8Command);
void HLCD_voidSendData(u8 cpy_Byte);


 #endif