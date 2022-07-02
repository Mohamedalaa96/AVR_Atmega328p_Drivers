/* Service Layer */
#include "01_SERVICS/STD_TYPES.h"
#include "01_SERVICS/BIT_MATH.h"

#include "HLCD_16x2_interface.h"
#include "HLCD_16x2_config.h"
#include "HLCD_16x2_private.h"


/* Public user usable functions */
void HLCD_voidInit()
{
    /* Pins Initialization */
    MGPIO_voidSetPinMode( LCD_u8EN_PORT ,LCD_u8EN_PIN, MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode( LCD_u8RW_PORT ,LCD_u8RW_PIN, MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode( LCD_u8RS_PORT ,LCD_u8RS_PIN, MGPIO_MODE_OUTPUT );
	
    MGPIO_voidSetPinMode( LCD_u8D4_PORT ,LCD_u8D4_PIN, MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode( LCD_u8D5_PORT ,LCD_u8D5_PIN, MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode( LCD_u8D6_PORT ,LCD_u8D6_PIN, MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode( LCD_u8D7_PORT ,LCD_u8D7_PIN, MGPIO_MODE_OUTPUT );
	
    MTIMER_voidDelay_ms(20);

	/*  function set */

	HLCD_voidSendCommand(0x33);
    MTIMER_voidDelay_ms(1);

	HLCD_voidSendCommand(0x32);
    MTIMER_voidDelay_ms(1);

	HLCD_voidSendCommand(LCD_COMMAND_4_BIT_MODE);
	/* wait 1 */
	MTIMER_voidDelay_ms(1);

	/*  function set (on/off) */
	HLCD_voidSendCommand(LCD_COMMAND_DSPLY_ON_CUSR_BLINK);
	/* wait 1 */
	MTIMER_voidDelay_ms(1);

	/*  function set (Clear  Display) */
	HLCD_voidClearDisplay();

	/*  function set (Entry mode set - cursor increase or decrease ) */
	HLCD_voidSendCommand(LCD_COMMAND_CURSOR_RIGHT);
	/* wait 2 */
	MTIMER_voidDelay_ms(2);

	/* latch = 0 */
	MGPIO_voidSetPinValue(LCD_u8EN_PORT,LCD_u8EN_PIN,LOW);


}
void HLCD_voidSendString(u8 * ptr_u8String)
{
    u8 local_u8Counter;
    u8 local_u8tempChar = ptr_u8String[local_u8Counter];
    while (local_u8tempChar != '\0')
    {
        HLCD_voidSendCharcter(local_u8tempChar);
        local_u8tempChar = ptr_u8String[++local_u8Counter];
    }
    
}
void HLCD_voidSendCharcter(u8 cpy_u8Char)
{
	/* wait 2 */
    HLCD_voidSendData(cpy_u8Char);
    MTIMER_voidDelay_ms(1);

}
void HLCD_voidClearDisplay()
{

}
void HLCD_voidGoToColRow(u8 cpy_u8Col, u8 cpy_u8Row)
{
    HLCD_voidSendCommand(LCD_COMMAND_CLEAR);
}

/* Private Functions for internal usage */
void HLCD_voidSendCommand(u8 cpy_u8Command)
{
	/** to send command  ( RS = 0 and R/W = 0 ) =====> (write instruction) */

	/* RS  0 CMD */  
    MGPIO_voidSetPinValue(LCD_u8RS_PORT,LCD_u8RS_PIN,LOW);
	/* write 0 CMD*/
    MGPIO_voidSetPinValue(LCD_u8RW_PORT,LCD_u8RW_PIN,LOW);

    voidPutDataOnBus(cpy_u8Command);

}
void HLCD_voidSendData(u8 cpy_Byte)
{
    /** to send command  ( RS = 0 and R/W = 0 ) =====> (write instruction) */

	/* RS  1 DATA */  
    MGPIO_voidSetPinValue(LCD_u8RS_PORT,LCD_u8RS_PIN,HIGH);
	/* R/W 0 Write*/
    MGPIO_voidSetPinValue(LCD_u8RW_PORT,LCD_u8RW_PIN,LOW);

    voidPutDataOnBus(cpy_Byte);
	
}

void voidPutDataOnBus(u8 u8Data_cpy)
{
    /* High Order Nibble */
	MGPIO_voidSetPinValue(LCD_u8D4_PORT,LCD_u8D4_PIN,GET_BIT(u8Data_cpy,4));
	MGPIO_voidSetPinValue(LCD_u8D5_PORT,LCD_u8D5_PIN,GET_BIT(u8Data_cpy,5));
	MGPIO_voidSetPinValue(LCD_u8D6_PORT,LCD_u8D6_PIN,GET_BIT(u8Data_cpy,6));
	MGPIO_voidSetPinValue(LCD_u8D7_PORT,LCD_u8D7_PIN,GET_BIT(u8Data_cpy,7));
    
    /* Enable Pulse */
    MGPIO_voidSetPinValue(LCD_u8EN_PORT,LCD_u8EN_PIN,HIGH);
	MTIMER_voidDelay_ms(1);
    MGPIO_voidSetPinValue(LCD_u8EN_PORT,LCD_u8EN_PIN,LOW);
	MTIMER_voidDelay_ms(1);

    /* Low Order Nibble */
	MGPIO_voidSetPinValue(LCD_u8D4_PORT,LCD_u8D4_PIN,GET_BIT(u8Data_cpy,0));
	MGPIO_voidSetPinValue(LCD_u8D5_PORT,LCD_u8D5_PIN,GET_BIT(u8Data_cpy,1));
	MGPIO_voidSetPinValue(LCD_u8D6_PORT,LCD_u8D6_PIN,GET_BIT(u8Data_cpy,2));
	MGPIO_voidSetPinValue(LCD_u8D7_PORT,LCD_u8D7_PIN,GET_BIT(u8Data_cpy,3));
    
    /* Enable Pulse */
    MGPIO_voidSetPinValue(LCD_u8EN_PORT,LCD_u8EN_PIN,HIGH);
	MTIMER_voidDelay_ms(1);
    MGPIO_voidSetPinValue(LCD_u8EN_PORT,LCD_u8EN_PIN,LOW);
	MTIMER_voidDelay_ms(1);
}