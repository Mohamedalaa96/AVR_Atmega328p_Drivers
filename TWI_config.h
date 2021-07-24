/****************************************************************/
/* TWI CONFIG FILE                                              */
/* Author   : Mohamed Alaa                                      */                    
/* Date     : 24 July 2021                                      */
/* Version  : V001.1                                            */
/****************************************************************/

/****************************************************************/
/* New Features : 
/*          - Interrupt Handling 
/*          - ISR function 
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/
#ifndef TWI_CONFIG_H
#define TWI_CONFIG_H


/****************************************************************/
/* Description   : Define the CPU Frequency used to set the buad*/
/*                 rate generator values (in Hz)                */
/****************************************************************/
#define F_CPU				16000000U

/****************************************************************/
/** !comment : Please Enter the Select Operation Mode 			*/
/** 		   MODE_OF_OPERATION can be : 						*/
/*					    					ASYNCHRONOUS 		*/
/*						    				SYNCHRONOUS 		*/
/****************************************************************/

#define MODE_OF_OPERATION	ASYNCHRONOUS

/****************************************************************/
/* Description   : Define the Transmission speed symbol/seconds */
/*                 in USART symbol is (1 bit)                   */
/****************************************************************/
/** !comment : Select the trasmission speed (integer value) 	*/
/****************************************************************/

#define BUADRATE 9600U


/****************************************************************/
/* Description   : Buad rate generator run in two modes         */
/*                 single speed or double speed to get          */
/*                 an acceptable error in the buad rate         */
/****************************************************************/
/* SPEED_MODE Options :                                         */
/*            SIGNLE_SPEED_MODE                                 */
/*            DOUBLE_SPEED_MODE                                 */
/****************************************************************/

#define SPEED_MODE SIGNLE_SPEED_MODE


/****************************************************************/
/* Description   : #No of Stop bits in the end of frame         */
/****************************************************************/
/* Options :                                                    */
/*            ONE_BIT                                           */
/*            TWO_BITS 	                                        */      
/****************************************************************/


#define STOP_BITS ONE_BIT


/****************************************************************/
/* Description   : Parity Bit (Error Detection Technique)       */
/****************************************************************/
/* Options :                                                    */
/*            DISABLED                                          */
/*            EVEN 	                                            */      
/*            ODD    	                                        */      
/****************************************************************/

#define PARITY_MODE DISABLED

/****************************************************************/
/* Description   : #No of data bits in the frame                */
/****************************************************************/
/* Options :                                                    */
/*            BITS_5                                            */
/*            BITS_6                                            */
/*            BITS_7                                            */
/*            BITS_8                                            */
/*            BITS_9                                            */
/****************************************************************/

#define DATA_BITS_PER_FRAME BITS_8

/****************************************************************/
/* Description   : Clock Polarity (Edge triggering)             */
/*                 available in Synchrouns Mode Only            */
/****************************************************************/
/* Options :                                                    */
/*            RX_RISING_EDGE                                    */
/*            RX_FALLING_EDGE                                   */
/****************************************************************/

#define CLK_POLARITY RX_RISING_EDGE




#endif  /* [EOF] GAURD TWI_CONFIG_H */