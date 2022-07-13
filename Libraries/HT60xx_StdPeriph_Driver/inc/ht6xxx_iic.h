/*
*********************************************************************************************************
*                                              HT6XXX
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6xxx_iic.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_IIC_H__
#define __HT6XXX_IIC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/
typedef struct __I2C_InitTypeDef
{
  uint32_t I2C_ClockSpeed;          /*!< Specifies the clock frequency.
                                         This parameter must be set to a value lower than 400kHz */

  uint32_t I2C_OwnAddress;         /*!< Specifies the first device own address.
                                         This parameter can be a 7-bit or 10-bit address. */

  uint32_t GeneralCallMode;        /*!< Specifies if 7-bit or 10-bit address is acknowledged.
                                         This parameter can be a value of @ref I2C_acknowledged_address */
#if(USE_HT_I2C_REGISTER_CALLBACKS == 1U)
	HT_I2C_TypeDef	*Instance;        									/*!< UART registers base address        */
    __IO uint32_t	ErrorCode;        									/*!< UART Error code                    */
	void (* I2CCallback)(struct __I2C_InitTypeDef                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           *UART_InitStruct);            /*!< UART Tx Complete Callback             */
	
#endif
}I2C_InitTypeDef;

#define I2C_START 		         	((uint32_t)0x00000008)		/* Start condition has beeen transmited								*/
#define I2C_RESTART			        ((uint32_t)0x00000010)		/* Repeat Start condition has beeen transmited						*/
#define I2C_MASTER_TRANS_ADDR_ACK 	((uint32_t)0x00000018)   	/* Slave address + W has been transmitted; ACK has been received 	*/
#define I2C_MASTER_TRANS_ADDR_NACK 	((uint32_t)0x00000020)   	/* Slave address + W has been transmitted; NACK has been received	*/
#define I2C_MASTER_TRANS_DATA_ACK 	((uint32_t)0x00000028)   	/* Data byte in I2CDAT has been transmitted; ACK has been received	*/
#define I2C_MASTER_TRANS_DATA_NACK 	((uint32_t)0x00000030)   	/* Data byte in I2CDAT has been transmitted; ACK has been received	*/
#define I2C_ARBI_LOST				((uint32_t)0x00000038) 		/* Arbitation lost */

#define I2C_MASTER_RCV_ADDR_ACK 	((uint32_t)0x00000040)   	/* Slave address + R has been transmitted; ACK has been received*/
#define I2C_MASTER_RCV_ADDR_NACK 	((uint32_t)0x00000048)   	/* Slave address + R has been transmitted; ACK has been received*/
#define I2C_MASTER_RCV_DATA_ACK 	((uint32_t)0x00000050)   	/* Data byte has been received; ACK has been returned*/
#define I2C_MASTER_RCV_DATA_NACK 	((uint32_t)0x00000058)   	/* Data byte has been received; ACK has been returned*/

#define I2C_SLAVE_TRANS_ADDR_ACK 	((uint32_t)0x000000A8)   	/* Own address + R has been received;ACK hanse been returned */
#define I2C_ARLO_SLAVE_TRANS_ACK    ((uint32_t)0x000000B0)   	/* Own address + R has been received;ACK hanse been returned */
#define I2C_SLAVE_TRANS_DATA_ACK 	((uint32_t)0x000000B8)   	/* Data byte in I2CDAT has been transmitted; ACK has been received*/
#define I2C_SLAVE_TRANS_DATA_NACK 	((uint32_t)0x000000C0)   	/* Data byte in I2CDAT has been transmitted; ACK has been received*/
#define I2C_SLAVE_TRANS_DATA_LAST 	((uint32_t)0x000000C8)   	/* Last data byte has been trasmitted; ACK has been received*/

#define I2C_SLAVE_RCV_ADDR_ACK 	    ((uint32_t)0x00000060)   	/**/
#define I2C_ARLO_SLAVE_RCV_ACK      ((uint32_t)0x00000068)
#define I2C_SLAVE_RCV_GELADDR_ACK 	((uint32_t)0x00000070)   	/**/
#define I2C_ARLO_GEL_RCV_ACK 	    ((uint32_t)0x00000078)   	/**/

#define I2C_SLAVE_RCV_DATA_ACK 	    ((uint32_t)0x00000080)   	/**/
#define I2C_SLAVE_RCV_DATA_NACK 	((uint32_t)0x00000088)   	/**/
#define I2C_SLAVE_RCV_GELDATA_ACK 	((uint32_t)0x00000090)   	/**/
#define I2C_SLAVE_RCV_GELDATA_NACK 	((uint32_t)0x00000098)   	/**/
#define I2C_SLAVE_RCV_STOP 	        ((uint32_t)0x000000A0)   	/**/

#define I2C_NOINFO 	                ((uint32_t)0x000000F8)   	/**/
#define I2C_BUS_ERR	                ((uint32_t)0x000000F8)   	/**/

#define I2C_MASTER_ABT 	((uint32_t)0x000000C0)

#define I2C_WR      				    ((uint32_t)0x00000001)

#define IS_HT_I2C_ALL_PERIPH(I2CX)  	((I2CX) == HT_I2C )
#define IS_I2C_SPEED(SPEED) 			((SPEED)>0 || (SPEED) < 400000)
#define IS_I2C_ADDR(ADDR)				((ADDR)>0 || (ADDR)<0x3F)
#define IS_I2C_GELEN(GELEN)				((GELEN) ==0 || (GELEN) ==1)

#define I2C_SPEED(__PCLK__,__SPEED__)   (__PCLK__)/(__SPEED__)
#define I2C_CR(__CLKCR__)				((__CLKCR__)&0x3) + (((__CLKCR__)&(~0x3))<<5)
#define I2C_ADD_WRITE(__ADDRESS__)		((uint8_t)((__ADDRESS__)<<1) & (~I2C_WR))
#define I2C_ADD_READ(__ADDRESS__)		((uint8_t)((__ADDRESS__)<<1) | (I2C_WR))
/*
*********************************************************************************************************
*                                             Global Vriable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
void HT_I2C_Callback(I2C_InitTypeDef* I2C_InitStruct);
void HT_I2C_IRQHandler_Default(void);




#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_IIC_H__ */
