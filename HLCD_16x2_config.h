#ifndef _HLCD_16x2_CONFIG_H
#define _HLCD_16x2_CONFIG_H

/* Enable for Latching 
LOW - HIGH - LOW pulse 
_____________---___ min:450nS*/
#define LCD_u8EN_PORT MGPIO_GPIOB
#define LCD_u8EN_PIN  0

#define LCD_u8RW_PORT MGPIO_GPIOB
#define LCD_u8RW_PIN  1

/* Register Select 
1 -> Data 
0 -> Command 
*/
#define LCD_u8RS_PORT MGPIO_GPIOB
#define LCD_u8RS_PIN  2

#define LCD_u8D4_PORT MGPIO_GPIOB
#define LCD_u8D4_PIN  3

#define LCD_u8D5_PORT MGPIO_GPIOB
#define LCD_u8D5_PIN  4

#define LCD_u8D6_PORT MGPIO_GPIOB
#define LCD_u8D6_PIN  5

#define LCD_u8D7_PORT MGPIO_GPIOD
#define LCD_u8D7_PIN  3


#endif