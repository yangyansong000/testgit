/*
*********************************************************************************************************
*                                              HT6XXXX
*                                           Library Function
*
*                                   Copyright 2013, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6xxx_iic.c
* By           : Hitrendtech_SocTeam
* Version      : V1.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_IIC_C
#include <stdio.h>
#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                            Local Macro/Structure
*********************************************************************************************************
*/
/* I2C PE mask */
#define CON_PE_Set              ((uint32_t)0x0040)
#define CON_PE_Reset            ((uint32_t)0xFFBF)

/* I2C START mask */
#define CON_START_Set           ((uint32_t)0x0020)
#define CON_START_Reset         ((uint32_t)0xFFDF)

/* I2C STOP mask */
#define CON_STOP_Set            ((uint32_t)0x0010)
#define CON_STOP_Reset          ((uint32_t)0xFFEF)

/* I2C ACK mask */
#define CON_ACK_Set             ((uint32_t)0x0004)
#define CON_ACK_Reset           ((uint32_t)0xFFFB)

/* I2C ENGC mask */
#define CR1_ENGC_Set            ((uint16_t)0x0001)
#define CR1_ENGC_Reset          ((uint16_t)0xFFFE)

//////////////////////////////////////////////////
/* I2C registers Masks */
#define CR1_CLEAR_Mask          ((uint16_t)0xFFFE)

/* I2C ADD0 mask */
#define OAR1_ADD0_Set           ((uint16_t)0x0001)
#define OAR1_ADD0_Reset         ((uint16_t)0xFFFE)

/* I2C F/S mask */
#define CCR_FS_Set              ((uint16_t)0x8000)

/* I2C CCR mask */
#define CCR_CCR_Set             ((uint16_t)0x0FFF)

/* I2C Flag mask */
#define Flag_Mask               ((uint32_t)0x00FFFFFF)

/* I2C Interrupt Enable mask */
#define ITEN_Mask               ((uint32_t)0x07000000)

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

/*
*********************************************************************************************************
*                                             Local Variable
*********************************************************************************************************
*/
  uint8_t                    *pBuffTx;  /*!< Pointer to I2C transfer buffer */

  uint16_t                   XferSize;   /*!< I2C transfer size              */

  __IO uint16_t              XferCount;  /*!< I2C transfer counter           */
	
  uint8_t                    *pBuffRx;  /*!< Pointer to I2C Receive buffer */

  uint16_t                   RcvSize;   /*!< I2C receive size              */

  __IO uint16_t              RcvCount;  /*!< I2C receive counter           */

/*
*********************************************************************************************************
*                                           Local Function Declare
*********************************************************************************************************
*/


/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Init(HT_I2C_TypeDef *I2Cx,I2C_InitTypeDef *I2C_Init)
{
	uint32_t pclk1 = 0;
	uint32_t clkcr = 0;
    /*  assert_param  */
	assert_param(IS_HT_I2C_ALL_PERIPH(I2Cx));
	assert_param(IS_I2C_SPEED(I2C_Init->I2C_ClockSpeed));
	assert_param(IS_I2C_SPEED(I2C_Init->I2C_OwnAddress));
	assert_param(IS_I2C_SPEED(I2C_Init->GeneralCallMode));
	
	pclk1 = HT_CMU_SysClkGet()>>2;
	clkcr = I2C_SPEED(pclk1,I2C_Init->I2C_ClockSpeed);
	I2Cx->I2CCON =  (I2Cx->I2CCON&I2C_I2CCON_CR)|I2C_CR(clkcr);
	I2Cx->I2CADR = (I2C_Init->I2C_OwnAddress <<1) + I2C_Init->GeneralCallMode;
	
	I2Cx->I2CCON |= I2C_I2CCON_ENS1;				/* Enable selected I2C peripheral*/
	
}

/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
ITStatus HT_I2C_ITFlagStatusGet(void)
{
	if(HT_I2C->I2CCON & I2C_I2CCON_SI)
	{
		return SET;
		
	}
	else
	{
		return RESET;
	}
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_ClearITPendingBit(void)
{
	HT_I2C->I2CCON &= ~I2C_I2CCON_SI;
	return;
}

#if (USE_HT_I2C_REGISTER_CALLBACKS == 1U)
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_IRQHandler(I2C_InitTypeDef *I2C_InitStruct)
{
	/*Call register ECC callback*/
	I2C_InitStruct->I2CCallback(I2C_InitStruct);
	
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void I2C_InitCallbackToDefault(I2C_InitTypeDef *I2C_InitStruct)
{
	/*Init the I2C Callback setting*/
	I2C_InitStruct->I2CCallback = HT_I2C_Callback;
	
}

/**
*********************************************************************************************************
*                            I2C Interrupt Callback
*
* @brief  I2C interrupt callback function 
*
* @param  I2C_InitStruct: Pointer to I2C_InitTypeDef structure that contains
*                               the configuration of ECC module
* @retval None
*
* Note: None
*********************************************************************************************************
*/
__weak void HT_I2C_Callback(I2C_InitTypeDef* I2C_InitStruct)
{   
	UNUSED(I2C_InitStruct);
}
#endif

/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/

void HT_I2C_Start(void)
{
	HT_I2C->I2CCON |= I2C_I2CCON_STA;
	return;
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/

void HT_I2C_Stop()
{
	return;
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Master_Transmit(uint8_t DevAddress, uint8_t *pData, uint16_t Size)
{
	/* Send Slave address */
	HT_I2C_Start();
	while(HT_I2C_ITFlagStatusGet()== RESET){;}
	if(HT_I2C->I2CSTA == I2C_START)			/* start condition transmutted  */
	{
		HT_I2C->I2CDAT = I2C_ADD_WRITE(DevAddress);
		HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
	}
	else return;
	while(HT_I2C_ITFlagStatusGet()== RESET){;}
    if(HT_I2C->I2CSTA != I2C_MASTER_TRANS_ADDR_ACK)
	{
		return;
	}
	else
	{
		
		while(Size >0)							/* send data to slave */
		{
			HT_I2C->I2CDAT = *(pData++);
			HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
			while(HT_I2C_ITFlagStatusGet()== RESET){;}
			if(HT_I2C->I2CSTA != I2C_MASTER_TRANS_DATA_ACK)
			{
				return;
			}
			
		}
	}
	
	HT_I2C->I2CCON |= I2C_I2CCON_STO;		/*Generate STOP condition*/
	HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Master_Receive(uint8_t DevAddress, uint8_t *pData, uint16_t Size)
{	
	HT_I2C_Start();									/*Generate start condition*/
	while(HT_I2C_ITFlagStatusGet()== RESET){;}
	if(HT_I2C->I2CSTA == I2C_START)					/* start condition transmitted  */
	{
		HT_I2C->I2CDAT = I2C_ADD_READ(DevAddress);	/* Send Slave address */
		HT_I2C->I2CCON &= ~I2C_I2CCON_SI;			/* Clear the SI bit*/
	}
	else return;
	while(HT_I2C_ITFlagStatusGet()== RESET){;}
    if(HT_I2C->I2CSTA != I2C_MASTER_RCV_ADDR_ACK)
	{
		return;
	}
	else
	{
		
		while(Size >0)							/* send data to slave */
		{
			*(pData++) = HT_I2C->I2CDAT ;
			HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
			while(HT_I2C_ITFlagStatusGet()== RESET){;}
			if(HT_I2C->I2CSTA != I2C_MASTER_RCV_DATA_ACK)
			{
				return;
			}
			
		}
	}
	
	HT_I2C->I2CCON |= I2C_I2CCON_STO;		/*Generate STOP condition*/
	HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Slave_Transmit(uint8_t *pData, uint16_t Size)
{
	HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
	while(HT_I2C_ITFlagStatusGet()== RESET){;}
	if(HT_I2C->I2CSTA == I2C_SLAVE_TRANS_ADDR_ACK)	/*Own address + R has been received;ACK hanse been returned */
	{
		while(Size >0)							/* send data to slave */
		{
			HT_I2C->I2CDAT  = *(pData++);
			HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
			while(HT_I2C_ITFlagStatusGet()== RESET){;}
			if(HT_I2C->I2CSTA != I2C_SLAVE_TRANS_DATA_ACK)
			{
				return;
			}
			
		}
	}
	else return;		
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Slave_Receive(uint8_t *pData, uint16_t Size)
{
	HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
	while(HT_I2C_ITFlagStatusGet()== RESET){;}
	if(HT_I2C->I2CSTA == I2C_SLAVE_RCV_ADDR_ACK)	/*Own address + R has been received;ACK hanse been returned */
	{
		while(Size >0)							/* send data to slave */
		{
			*(pData++) = HT_I2C->I2CDAT ;
			HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
			while(HT_I2C_ITFlagStatusGet()== RESET){;}
			if(HT_I2C->I2CSTA != I2C_SLAVE_RCV_DATA_ACK)
			{
				return;
			}
			
		}
	}
	else return;	
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Master_Transmit_IT(uint8_t DevAddress, uint8_t *pData, uint16_t Size)
{
	NVIC_EnableIRQ(I2C_IRQn);   					/* Disable the intterupt*/
	HT_I2C_Start();									/*Generate start bit*/
	while(HT_I2C_ITFlagStatusGet()== RESET){;}	
	if(HT_I2C->I2CSTA == I2C_START || HT_I2C->I2CSTA == I2C_RESTART)				/* start condition transmutted  */
	{
		HT_I2C->I2CDAT = I2C_ADD_WRITE(DevAddress);
		HT_I2C->I2CCON &= ~I2C_I2CCON_SI;			/* Clear the SI bit*/
		NVIC_EnableIRQ(I2C_IRQn);   				/* Enable the intterupt*/
	}
	else return;
	return;
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Master_Receive_IT(uint8_t DevAddress, uint8_t *pData, uint16_t Size)
{
	HT_I2C->I2CCON &= ~I2C_I2CCON_SI;	/* Clear the SI bit*/
	return;
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Slave_Transmit_IT(uint8_t *pData, uint16_t Size)
{
	return;
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_Slave_Receive_IT(uint8_t *pData, uint16_t Size)
{
	return;
}
/**
*********************************************************************************************************
*                                     INITIAL IIC MODULE
*
* @brief  Initializ parameters of iic 
*
* @param  None
*
* @retval  None
*
* Note: Enable CMU clock enable before iic configuration, refer to HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
void HT_I2C_IRQHandler_Default(void)
{
	
}

