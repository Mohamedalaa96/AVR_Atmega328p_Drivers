#ifndef _HLCD_16x2_PRIVATE_H
#define _HLCD_16x2_PRIVATE_H


/* Commands */
#define LCD_COMMAND_CLEAR                   0x01
#define LCD_COMMAND_HOME                    0x02
#define LCD_COMMAND_CURSOR_LEFT             0x04
#define LCD_COMMAND_CURSOR_RIGHT            0x06
#define LCD_COMMAND_SHIFT_RIGHT             0x05
#define LCD_COMMAND_SHIFT_LEFT              0x07
#define LCD_COMMAND_DSPLY_OFF_CUSR_OFF      0x08
#define LCD_COMMAND_DSPLY_OFF_CUSR_ON       0x0A
#define LCD_COMMAND_DSPLY_ON_CUSR_OFF       0x0C
#define LCD_COMMAND_DSPLY_ON_CUSR_BLINK     0x0E


#define LCD_COMMAND_LINE_0                  0x80
#define LCD_COMMAND_LINE_1                  0xC0

#define LCD_COMMAND_4_BIT_MODE              0x28
#define LCD_COMMAND_8_BIT_MODE              0x38

void voidPutDataOnBus(u8 u8Data_cpy);



#endif