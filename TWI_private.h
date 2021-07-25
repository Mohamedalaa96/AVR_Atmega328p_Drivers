/**************************************************************/
/* TWI PRIVATE FILE                                           */
/* Author   : Mohamed Alaa                                    */                    
/* Date     : 24 July 2021                                    */
/* Version  : V001                                            */
/**************************************************************/

#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

#define NULL                    0

/**************************************************************/
/******************* Status Code Defintion  *******************/
/**************************************************************/
#define START_SENT_CODE         0x08    /* Start Condition Sent     */
#define REBETED_START_CODE      0x10    /* Repeted Start Sent       */

#define SLA_ACK_CODE            0x18    /* Slave Address Ack Sent   */
#define SLA_NACK_CODE           0x20    /* Slave Address NACK sent  */

#define DATA_ACK_CODE           0x28    /*  Data ACK from Slave     */
#define DATA_NACK_CODE          0x30    /*  Data NACK from Slave    */

#define ARBT_LOST_CODE          0x38    /*  lost Control arbtration */

#define SLAVE_ST1_CODE          0x68
#define SLAVE_ST1_CODE          0x78
#define SLAVE_ST1_CODE          0xB0


/**************************************************************/
/******************* Register Defintion     *******************/
/**************************************************************/
#define TWBR    (* (volatile u8 * )(0xB8 ))  /* Baud rate Register   */
#define TWCR    (* (volatile u8 * )(0xBC ))  /* Control Register     */

#define TWSR    (* (volatile u8 * )(0xB9 ))  /* Status Register      */

#define TWDR    (* (volatile u8 * )(0xBB ))  /* Data Register        */
#define TWAR    (* (volatile u8 * )(0xBA ))  /* Address Register     */
#define TWAMR   (* (volatile u8 * )(0xBD ))  /* Slave Mask Register  */


/**************************************************************/
/*******************    Bits Defintion      *******************/
/**************************************************************/
    
/*            (TWCR ) TW Control Register             */

#define TWINT       7       /* Interrupt Flag (Cleared by writing 1)        */
#define TWEA        6       /* Enable(Generate) Acknowladge                 */
#define TWSTA       5       /* Insert Start Condition                       */
#define TWSTO       4       /* Insert Stop Condtion                         */
#define TWWC        3       /* Write Collision Flag                         */
#define TWEN        2       /* Enable TW interface                          */
#define TWIE        0       /* Interrupt Enbale Bit                         */

/* Status Register      */

#define STATES_MASK 0xF8    /* mask bits from 7: 3 to read the status code  */

#define TWPS0       0       /* Prescaler Bit0                               */
#define TWPS1       1       /* Prescaler Bit1                               */

/* Address Register     */
#define TWGCE       0       /* TW General Call Recogintion Enable Bit       */ 

#endif
