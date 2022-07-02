/**
 * @file TIMER_interface.h
 * @author Mohamed Alaa (Mohamedalaasultan7@Gmail.com)
 * @brief   Timer driver
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Convert Seconds to ticks for timer APIs
 * 
 */
#define SECOND_TO_TICK(ticks)       (ticks*10)

/**
 * @brief Set Timer to Call this function Periodically
 * 
 * @param Callback ptr to function to be called (void args, and return)
 * @param copy_u16TicksCont     number of ticks per period
 */
void MTIMER_voidSetTimerPeriodic(void (*Callback) (void), uint16_t copy_u16TicksCont);

/**
 * @brief Enable Interrupt of timer
 * 
 */
void MTIMER_voidEnableInterrupt();

/**
 * @brief Disable Interrupt of timer
 * 
 */
void MTIMER_voidDisableInterrupt();

/**
 * @brief Delay number of millis 
 * 
 * @param copy_u16Delay_Millis 
 */
void MTIMER_voidDelay_ms (u16 copy_u16Delay_Millis);
