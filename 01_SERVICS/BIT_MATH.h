/************************************************************/
/* Bit math tested on AVR-GCC Compiler                      */
/************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H


#define TOG_BIT(REG,BIT)        ( REG ^=  (1 << BIT) )
#define SET_BIT(REG,BIT)        ( REG |=  (1 << BIT) )
#define CLR_BIT(REG,BIT)        ( REG &= (~(1 << BIT)) )

#define GET_BIT(REG,BIT)        ( REG &   (1 << BIT) )      /* Return 0 or 1 */









#endif
