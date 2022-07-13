/*
*********************************************************************************************************
*                                              HT6XXX
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6xxx_uart&7816.c
* By           : Hitrendtech_SD
* Version      : V2.0.6
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_UART7816_C

#include <stdio.h>
#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                             Local Variables
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
static void UART_InitCallbacksToDefault(UART_InitTypeDef *UART_InitStruct);
static void UART_Receive_IT(UART_InitTypeDef *UART_InitStruct);
static void UART_Transmit_IT(UART_InitTypeDef *UART_InitStruct);
#if defined  USE_UART_IRQ 
static void UART_PRD_IT(UART_InitTypeDef *UART_InitStruct);
#endif
static void ISO7816_InitCallbacksToDefault(ISO7816_InitTypeDef *ISO7816_InitStruct);
static void ISO7816_ERROR_IT(ISO7816_InitTypeDef *ISO7816_InitStruct);
static void ISO7816_Receive_IT(ISO7816_InitTypeDef *ISO7816_InitStruct);
static void ISO7816_Transmit_IT(ISO7816_InitTypeDef *ISO7816_InitStruct);
#endif /* USE_HT_UART_REGISTER_CALLBACKS */


/**
*********************************************************************************************************
*                                         INITIAL UART MODULE
*
* @brief: Initializes the UARTx peripheral according to the specified
*         parameters in the USART_InitStruct .
*
* @param: UARTx: Select the USART or the UART peripheral. 
*   This parameter can be one of the following values:
*                                 @arg HT_UART0
*                                 @arg HT_UART1
*                                 @arg HT_UART2
*                                 @arg HT_UART3
*                                 @arg HT_UART4
*                                 @arg HT_UART5
*                                 @arg HT_UART6 (If support)
*
* @param: UART_InitStruct: pointer to a UART_InitTypeDef structure
*   that contains the configuration information for the specified USART 
*   peripheral.which consists of severn parameters:
*                               1) UART_Logic      : UART communication logic setting
*                               2) UART_StopBits   : UART communication stop bit setting
*                               3) UART_WordLength : UART comunication data bit length setting
*                               4) UART_Parity     : UART communication parity setting
*                               5) UART_BaudRate   : UART communication baudrate setting
*                               6) ReceiveEN       : UART receive enable
*                               7) SendEN          : UART send enable
*
* @retval: None
*
* @Note: 1) HT_UART3/HT_UART4 and ISO7816 are functional alternation，Only one of them can be used 
*   at any one time，Here's how they correspond：
*              HT_UART3 <----->HT_ISO7816_1
*              HT_UART4 <----->HT_ISO7816_0
*        2) The system clock should be configured first, otherwise the Baudrate configuration will fail
*        3) The UART module should be enabled before the UART register is configured，for details please
*   refer to HT_CMU_ClkCtrl1Config()
*********************************************************************************************************
*/
void HT_UART_Init(HT_UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct)
{
    uint32_t sysclk;
    uint32_t tempreg;
	 uint32_t setVal;
	 double tmpVal;
		/*  assert_param  */
	assert_param(IS_HT_UART_ALL_PERIPH(UARTx));
	assert_param(IS_HT_UART_BAUDRATE(UART_InitStruct->UART_BaudRate));  
	assert_param(IS_HT_UART_WORD_LENGTH(UART_InitStruct->UART_WordLength));
	assert_param(IS_HT_UART_STOPBITS(UART_InitStruct->UART_StopBits));
	
    UARTx->MODESEL = UART_MODESEL_UART;                                   /*!< Select UART function                      */
                                                                          /*!< Only valid for Uart3/4                    */
    tempreg = UARTx->UARTCON & (UART_UARTCON_TXIE | UART_UARTCON_RXIE);   /*!< Leave TXIE, RXIE unchanged                */
    if(UART_InitStruct->UART_Parity != UartParity_Disable)
    {
	    assert_param(IS_HT_UART_PARITY(UART_InitStruct->UART_Parity));
        tempreg |= UART_UARTCON_PARITYEN;
        tempreg |= UART_InitStruct->UART_Parity;                          /*!< Configure parity bits                     */
    }
    tempreg |= (uint32_t)UART_InitStruct->UART_Logic;                               /*!< Configure the UART communication logic    */
    tempreg |= (uint32_t)UART_InitStruct->UART_StopBits;                            /*!< Configure the stop bit                    */
    tempreg |= UART_InitStruct->UART_WordLength;                          /*!< Configure the data bit length             */
    if(UART_InitStruct->ReceiveEN != DISABLE)
    {
        tempreg |= UART_UARTCON_RXEN;                                     /*!< Receive enable                            */
	}
    if(UART_InitStruct->SendEN != DISABLE)
    {
        tempreg |= UART_UARTCON_TXEN;                                     /*!< Send enable                               */
	}
    UARTx->UARTCON = tempreg;                                             /*!< Configure the register                    */

	  sysclk = HT_CMU_SysClkGet();                                       /*!< Gets the current system clock frequency/2 */
	  tmpVal = ((sysclk/2.0)/UART_InitStruct->UART_BaudRate-1.0);
    setVal = (uint32_t)tmpVal;
	  if((tmpVal-setVal)>=0.5)
	  {
		  setVal=setVal+1;
	  }    
    UARTx->SREL = setVal;		
    UARTx->IRCON &= ~UART_IRCON_IRTX;                                     /*!< Turn off the infrared modulation output   */

#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
    UART_InitStruct->Instance = UARTx;
    UART_InitCallbacksToDefault(UART_InitStruct);
#endif
} 

/**
*********************************************************************************************************
*                                         INITIAL IR MODULE
*
* @brief: Initializes the USART's IrDA interface
*
* @param: UARTx: Select the UART peripheral. 
*   This parameter can be one of the following values:
*                                 @arg HT_UART0
*                                 @arg HT_UART1
*                                 @arg HT_UART2
*                                 @arg HT_UART3
*                                 @arg HT_UART4
*                                 @arg HT_UART5
*                                 @arg HT_UART6 (If support)
*
* @param: IR_InitStruct:the structure pointer of The IR module initializes which consists of three main parameters:
*                               1) UARTModule   : The UART communication module is initialized as a UART_InitTypeDef type structure
*                               2) IRClkSrc     : Infrared clock source selection(for HT6x2x/HT6x2xK and HT6x3x)
*                               3) IRPolarity   : Infrared modulation output polarity configuration
*                               4) IRDuty       : Infrared modulating waveform duty ratio setting
*                               5) IRClkDiv16   : Infrared clock source pre-dividing setting(0~127,for HT6x3x)
*                                                 0   -> Firclk = Fsysclk / 16
*                                                 1   -> Firclk = Fsysclk / 32
*                                                      ......
*                                                 127 -> Firclk = Fsysclk / 2048
*
* @retval: None
*
* @Note: 1) HT_UART3/HT_UART4 and ISO7816 are functional alternation，Only one of them can be used 
*   at any one time，Here's how they correspond：
*              HT_UART3 <----->HT_ISO7816_1
*              HT_UART4 <----->HT_ISO7816_0
*           2) The system clock should be configured first, otherwise the Baudrate configuration will fail
*           3) The UART module should be enabled before the UART register is configured，for details please
*   refer to HT_CMU_ClkCtrl1Config()
*           4) Before using the IrDA module, turn on the corresponding clock source, otherwise the modulation 
*   signal cannot be generated；The HT501x and HT6x1x need to turn on the PLL module；HT502x, HT6x2x/HT6x2xK 
*   and HT6x3x need to turn on the corresponding clock module (PLL or HRC).
*********************************************************************************************************
*/
void HT_IR_Init(HT_UART_TypeDef *UARTx, IR_InitTypeDef *IR_InitStruct)
{
    /*  assert_param  */
	assert_param(IS_HT_UART_ALL_PERIPH(UARTx));
	assert_param(IS_HT_IR_DUTY(IR_InitStruct->IRDuty));
		
    HT_UART_Init(UARTx, &IR_InitStruct->UARTModule);                    /*!< Initialize the Uart module */
    UARTx->IRCON = ((IR_InitStruct->IRPolarity & UART_IRCON_IRLVL) 
                    | UART_IRCON_IRTX);                                 /*!< Enable IrDA as well as modulation polarity configurations */
#if defined  USE_UART_IRCON_IRCLKSRC && defined USE_UART_IRCON_IR38KSOURCE
    UARTx->IRCON |= (IR_InitStruct->IRClkSrc & UART_IRCON_IR38KSOURCE); /*!< IrDA clock source selection */
#elif defined USE_UART_IRCLKSRC && defined USE_UART_IR38KSOURCE
    UARTx->IRCON |= (IR_InitStruct->IRCLKSRC & UART_IRCON_IR38KSOURCE); /*!< IrDA clock source selection */
#endif
    UARTx->IRDUTY = IR_InitStruct->IRDuty;                              /*!< Configure the duty-on ratio */
#if  defined  USE_UART_IRCLKDIV 
	assert_param(IS_HT_IR_CLKDIV(IR_InitStruct->IRClkDiv16));
    UARTx->IRCLKDIV = IR_InitStruct->IRClkDiv16 & UART_IRCLKDIV;               /*!< The clock source pre-divider setting */
#endif
    
#if  defined  USE_UART_IR38KDIV 
	assert_param(IS_HT_IR_CLKDIV(IR_InitStruct->IRClkDiv16));
    UARTx->IR38KDIV = IR_InitStruct->IRClkDiv16 & UART_IR38KDIV;               /*!< The clock source pre-divider setting */
#endif    

}

/**
*********************************************************************************************************
*                                      INITIAL ISO7816 MODULE
*
* @brief: Initializes ISO7816 module
*
* @param: ISO7816x: Only one of the following ISO7816x can be selected.
*
*
*           ISO7816_InitStruct  the structure pointer of The ISO7816 module initializes which consists of six main parameters:
*                               1) ISO7816_Parity     : ISO7816 communication parity setting
*                               2) ISO7816_RepeatTime : ISO7816 communication RepeatTime setting
*                               3) AutoRxEN           : ISO7816 communication Auto receive enable
*                               4) AutoTxEN           : ISO7816 communication Auto send enable
*                               5) ISO7816_AckLen     : ISO7816 communication AckLen setting
*                               6) ISO7816_BaudRate   : ISO7816 communication baudrate setting
*
*@retval: None
*
* @Note: 1) HT_UART3/HT_UART4 and ISO7816 are functional alternation，Only one of them can be used 
*   at any one time，Here's how they correspond：
*              HT_UART3 <----->HT_ISO7816_1
*              HT_UART4 <----->HT_ISO7816_0
*           2) The system clock should be configured first, otherwise the Baudrate configuration will fail
*           3) The UART module should be enabled before the UART register is configured，for details please
*   refer to HT_CMU_ClkCtrl1Config()
*********************************************************************************************************
*/
void HT_ISO7816_Init(HT_ISO7816_TypeDef *ISO7816x, ISO7816_InitTypeDef *ISO7816_InitStruct)
{
    uint32_t tempreg, sysclk;
		/*  assert_param  */
	assert_param(IS_HT_ISO7816_ALL_PERIPH(ISO7816x));
	assert_param(IS_HT_ISO7816_PARITY(ISO7816_InitStruct->ISO7816_Parity));
	assert_param(IS_HT_ISO7816_REPEATTIME(ISO7816_InitStruct->ISO7816_RepeatTime));
	assert_param(IS_HT_ISO7816_ACKLEN(ISO7816_InitStruct->ISO7816_AckLen));
	assert_param(IS_HT_ISO7816_BAUDRATE(ISO7816_InitStruct->ISO7816_BaudRate));
	
    ISO7816x->MODESEL = UART_MODESEL_7816;                                  /*!<  Select ISO7816 function     */
    tempreg = ISO7816x->ISO7816CON & UART_ISO7816CON_IEALL;                 /*!< Leave IE unchanged       */
    if(ISO7816_InitStruct->AutoRxEN != DISABLE)
    {
        tempreg |= UART_ISO7816CON_AUTORXEN;                                   /*!< Auto receive enable      */
    }
    if(ISO7816_InitStruct->AutoTxEN != DISABLE)
    {
        tempreg |= UART_ISO7816CON_AUTOTXEN;                                /*!< Auto send enable       */
    }
    tempreg |= (uint32_t)ISO7816_InitStruct->ISO7816_Parity;                            /*!< Configure the parity bits             */
    tempreg |= ISO7816_InitStruct->ISO7816_RepeatTime;                       /*!< Configure the RepeatTime      */
    tempreg |= ISO7816_InitStruct->ISO7816_AckLen;                           /*!< Configure the AckLen        */
    ISO7816x->ISO7816CON = tempreg;                                           /*!< Configure the register             */

    sysclk = HT_CMU_SysClkGet()>>1;                                           /*!< Gets the current system clock frequency/2 */
    ISO7816x->SREL = sysclk/ISO7816_InitStruct->ISO7816_BaudRate-1U;          /*!< Calculate the Baudrate             */
    ISO7816x->IRCON &= ~UART_IRCON_IRTX;                                     /*!< Turn off the ISO7816x modulation output   */
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
    ISO7816_InitStruct->Instance = ISO7816x;
	ISO7816_InitCallbacksToDefault(ISO7816_InitStruct);
#endif
}

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE UART INTERRUPT
*
* @brief: Enable or Disable UART Interrupt
*
* @param: UARTx      Only one of the following uart can be selected. 
*                        @arg HT_UART0
*                        @arg HT_UART1
*                        @arg HT_UART2
*                        @arg HT_UART3
*                        @arg HT_UART4
*                        @arg HT_UART5
*                        @arg HT_UART6 (If support)
*
*           ITEn      UART interrupt setting bit, which can be one or a combination of the following parameters
*                        @arg UART_UARTCON_TXIE
*                        @arg UART_UARTCON_RXIE
*
* @param:         NewState   = ENABLE：enable interrupt
*                      = DISABLE：disable interrupt
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_UART_ITConfig(HT_UART_TypeDef *UARTx, uint32_t ITEn, FunctionalState NewState)
{
    uint32_t it;

		/*  assert_param  */
	assert_param(IS_HT_UART_ALL_PERIPH(UARTx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));
#if defined USE_UART_IRQ	
    it = (uint32_t)ITEn & (UART_UARTCON_RXIE | UART_UARTCON_TXIE | UART_UARTCON_PRDIE);
#else
    it = (uint32_t)ITEn & (UART_UARTCON_RXIE | UART_UARTCON_TXIE);
#endif

    if (NewState != DISABLE)
    {
        UARTx->UARTCON |= it;                                              /*!< Enable UART interrupt           */
    }
    else
    {
        UARTx->UARTCON &= ~it;                                             /*!< Disable UART interrupt           */
    }
}

/**
*********************************************************************************************************
*                            GET SPECIFIED UART INTERRUPT FLAG STATUS
*
* @brief: Gets the corresponding UART flag bit
*
* @param: UARTx      Only one of the following uart can be selected. 
*                        @arg HT_UART0
*                        @arg HT_UART1
*                        @arg HT_UART2
*                        @arg HT_UART3
*                        @arg HT_UART4
*                        @arg HT_UART5
*                        @arg HT_UART6 (If support)
*
* @param:  ITFlag     An interrupt that you want to clear, which can be the following parameters
*                        @arg UART_UARTSTA_TXIF
*                        @arg UART_UARTSTA_RXIF
*                        @arg UART_UARTSTA_PARITY    note：This flag bit is not an interrupt flag bit
*
* @retval: ITStatus    = SET：   The corresponding interrupt flag is generated
*                      = RESET： No corresponding interrupt flag was generated
*
* @Note: None
*********************************************************************************************************
*/
ITStatus HT_UART_ITFlagStatusGet(HT_UART_TypeDef *UARTx, uint32_t ITFlag)
{
	FlagStatus status = RESET;
    /*  assert_param  */
	assert_param(IS_HT_UART_ALL_PERIPH(UARTx));
	assert_param(IS_HT_UART_ITFLAG(ITFlag));
	
    if (UARTx->UARTSTA & ITFlag)
    {
        status = SET;                                            /*!< UART Interrupt Flag is set   */
    }
    else
    {
        status = RESET;                                          /*!< UART Interrupt Flag is reset */
    }
		return status;
}

/**
*********************************************************************************************************
*                                CLEAR UART INTERRUPT FLAG
*
* @brief: Clear the UART interrupt flag
*
* @param: UARTx      Only one of the following uart can be selected. 
*                        @arg HT_UART0
*                        @arg HT_UART1
*                        @arg HT_UART2
*                        @arg HT_UART3
*                        @arg HT_UART4
*                        @arg HT_UART5
*                        @arg HT_UART6 (If support)
*
* @param: ITFlag	An interrupt that you want to clear, which can be one or a combination of the following 
*						parameters.
*                        @arg UART_UARTSTA_TXIF
*                        @arg UART_UARTSTA_RXIF
*                        @arg UART_UARTSTA_PARITY     note：This flag bit is not an interrupt flag bit
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_UART_ClearITPendingBit(HT_UART_TypeDef* UARTx, uint32_t ITFlag)
{
    /*  assert_param  */
	assert_param(IS_HT_UART_ALL_PERIPH(UARTx));
	assert_param(IS_HT_UART_ITFLAG(ITFlag));
	
    UARTx->UARTSTA = ~((uint32_t)ITFlag);                 /*!< Clear UART Interrupt Flag    */
}


/**
*********************************************************************************************************
*                              ENABLE OR DISABLE ISO7816 INTERRUPT
*
* @brief: Enable or Disable ISO7816 interrupt
* 
* @param: ISO7816x Only one of the following ISO7816 can be selected. 
*
*           ITEn    ISO7816 interrupt setting bit, which can be one or a combination of the following parameters 
*                        @arg UART_ISO7816CON_TXIE
*                        @arg UART_ISO7816CON_RXIE
*                        @arg UART_ISO7816CON_PRDIE
*
* @param:   NewState   = ENABLE： Enable interrupt
*                      = DISABLE：Disable interrupt
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_ISO7816_ITConfig(HT_ISO7816_TypeDef *ISO7816x, uint32_t ITEn, FunctionalState NewState)
{
    uint32_t it;
    /*  assert_param  */
	assert_param(IS_HT_ISO7816_ALL_PERIPH(ISO7816x));
	assert_param(IS_FUNCTIONAL_STATE(NewState));
		
    it = (uint32_t)ITEn & UART_ISO7816CON_IEALL;
    if (NewState != DISABLE)
    {
        ISO7816x->ISO7816CON |= it;                                  /*!< Enable ISO7816 interrupt         */
    }
    else
    {
        ISO7816x->ISO7816CON &= ~it;                                  /*!< Disable ISO7816 interrupt        */
    }
}

/**
*********************************************************************************************************
*                         GET SPECIFIED ISO7816 INTERRUPT FLAG STATUS
*
* @brief: Gets the corresponding ISO7816 interrupt flag status
*
* @param: ISO7816x  Only one of the following ISO7816 can be selected. 
*
*           ITFlag   An interrupt that you want to check, which can be the following parameters
*                        @arg UART_ISO7816STA_TXIF
*                        @arg UART_ISO7816STA_RXIF
*                        @arg UART_ISO7816STA_PRDIF
*                        @arg UART_ISO7816STA_TXERRSTAT    note：This flag bit is not an interrupt flag bit
*                        @arg UART_ISO7816STA_RXERRSTAT    note：This flag bit is not an interrupt flag bit
*
* @retval: ITStatus    = SET：  The corresponding interrupt flag is generated
*                      = RESET：No corresponding interrupt flag was generated
*
* @Note: None
*********************************************************************************************************
*/
ITStatus HT_ISO7816_ITFlagStatusGet(HT_ISO7816_TypeDef *ISO7816x, uint32_t ITFlag)
{
	FlagStatus status = RESET;
    /*  assert_param  */
	assert_param(IS_HT_ISO7816_ALL_PERIPH(ISO7816x));
	assert_param(IS_HT_ISO7816_ITFLAG(ITFlag));

    if (ISO7816x->ISO7816STA & ITFlag)
    {
        status = SET;                                        /*!< ISO7816 Interrupt Flag is set   */
    }
    else
    {
        status = RESET;                                      /*!< ISO7816 Interrupt Flag is reset */
    }
		return status;
}

/**
*********************************************************************************************************
*                                CLEAR ISO7816 INTERRUPT FLAG
*
* @brief: Clear the ISO7816 interrupt flag
*
* @param: ISO7816x  Only one of the following ISO7816 can be selected. 
*
*         ITFlag	An interrupt that you want to clear, which can be one or a combination of the following
*							parameters.
*                        @arg UART_ISO7816STA_TXIF
*                        @arg UART_ISO7816STA_RXIF
*                        @arg UART_ISO7816STA_PRDIF
*                        @arg UART_ISO7816STA_TXERRSTAT    note：This flag bit is not an interrupt flag bit
*                        @arg UART_ISO7816STA_RXERRSTAT    note：This flag bit is not an interrupt flag bit
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_ISO7816_ClearITPendingBit(HT_ISO7816_TypeDef *ISO7816x, uint32_t ITFlag)
{
    /*  assert_param  */
	assert_param(IS_HT_ISO7816_ALL_PERIPH(ISO7816x));
	assert_param(IS_HT_ISO7816_ITFLAG(ITFlag));
	
    ISO7816x->ISO7816STA = ~((uint32_t)ITFlag);              /*!< Clear ISO7816 Interrupt Flag    */
}

/**
*********************************************************************************************************
*                                        WRITE DATA TO UART BUFFER
*
* @brief: Write data in Uart buffer
*
* @param: UARTx      Only one of the following UART can be selected
*                        @arg HT_UART0
*                        @arg HT_UART1
*                        @arg HT_UART2
*                        @arg HT_UART3
*                        @arg HT_UART4
*                        @arg HT_UART5
*                        @arg HT_UART6 (If support)
*
* @param:        Data       Data to write to Uart Buffer
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_UART_SendData(HT_UART_TypeDef *UARTx, uint32_t Data)
{
    /*  assert_param  */
	assert_param(IS_HT_UART_ALL_PERIPH(UARTx));
	
    UARTx->SBUF = Data;
}

/**
*********************************************************************************************************
*                                         READ UART BUFFER
*
* @brief: Read data in Uart
*
* @param: UARTx      Only one of the following UART can be selected
*                        @arg HT_UART0
*                        @arg HT_UART1
*                        @arg HT_UART2
*                        @arg HT_UART3
*                        @arg HT_UART4
*                        @arg HT_UART5
*                        @arg HT_UART6 (If support)
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
uint32_t HT_UART_ReceiveData(HT_UART_TypeDef *UARTx)
{
    /*  assert_param  */
	assert_param(IS_HT_UART_ALL_PERIPH(UARTx));
	
    return UARTx->SBUF;
}

/**
*********************************************************************************************************
*                                        WRITE DATA TO ISO7816 BUFFER
*
* @brief: Write data in ISO7816 buffer
*
* @param: ISO7816x   Only one of the following ISO7816 can be selected
*
* @param: Data       Data to write to ISO7816 Buffer
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_ISO7816_SendData(HT_ISO7816_TypeDef *ISO7816x, uint32_t Data)
{
    /*  assert_param  */
	assert_param(IS_HT_ISO7816_ALL_PERIPH(ISO7816x));
	
    ISO7816x->SBUF = Data;
}

/**
*********************************************************************************************************
*                                         READ ISO7816 BUFFER
*
* @brief: Read data in ISO7816
*
* @param: ISO7816x   Only one of the following ISO7816 can be selected
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
uint32_t HT_ISO7816_ReceiveData(HT_ISO7816_TypeDef *ISO7816x)
{
    /*  assert_param  */
	assert_param(IS_HT_ISO7816_ALL_PERIPH(ISO7816x));
	
    return ISO7816x->SBUF;
}

/**
*********************************************************************************************************
*                                   ENABLE OR DISABLE RX DIGITAL FILTER
*
* @brief:  Enable or Disable rx digital filtering for extern interrupt
*
* @param: RXFLTEn   Interrupt pin digital filter setting bit,which can be the following parameters
*                        @arg INT_PINFLT_RXFLT_RX0
*                        @arg INT_PINFLT_RXFLT_RX1
*                        @arg INT_PINFLT_RXFLT_RX2
*                        @arg INT_PINFLT_RXFLT_RX3
*                        @arg INT_PINFLT_RXFLT_RX4
*                        @arg INT_PINFLT_RXFLT_RX5
*                        @arg INT_PINFLT_RXFLT_RX6
*
* @param:       NewState   = ENABLE： Enable interrupt
*                          = DISABLE: Disable interrupt
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_UART_RXFilterConfig(uint32_t RXFLTEn,FunctionalState NewState)
{
    /*  assert_param  */
	assert_param(IS_HT_UART_RXFILTER(RXFLTEn));
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
    RXFLTEn &= INT_PINFLT_RXFLT;
    if (NewState != DISABLE)
    {
        HT_INT->PINFLT |= RXFLTEn;          /*!< enable digital filter         */
    }
    else
    {
        HT_INT->PINFLT &= ~RXFLTEn;          /*!< disable digital filter         */
    }
}

#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
/**
*********************************************************************************************************
* @brief  Register a User UART Callback
*         To be used instead of the weak predefined callback
* @param  UART_InitStruct uart handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref UART_TX_COMPLETE_CB_ID Tx Complete Callback ID
*           @arg @ref UART_RX_COMPLETE_CB_ID Rx Complete Callback ID
* @param  pCallback pointer to the Callback function
* @retval status
* @note: when USE_HT_UART_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register 
*		himself defined callback function.
*********************************************************************************************************
*/
StatusTypeDef HT_UART_RegisterCallback(UART_InitTypeDef *UART_InitStruct, UART_7816_CallbackIDTypeDef CallbackID, pUART_CallbackTypeDef pCallback)
{
   StatusTypeDef status = OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    UART_InitStruct->ErrorCode |= UART_ERROR_INVALID_CALLBACK;

    status =  ERROR;
  }
 else
 {
	switch (CallbackID)
	{
		case UART_TX_COMPLETE_CB_ID :
			UART_InitStruct->TxCpltCallback = pCallback;
			break;

		case UART_RX_COMPLETE_CB_ID :
			UART_InitStruct->RxCpltCallback = pCallback;
			break;
        case UART_PRD_COMPLETE_CB_ID :
			UART_InitStruct->PRDCpltCallback = pCallback;
			break;
        case UART_NEG_COMPLETE_CB_ID :
			UART_InitStruct->NEGCpltCallback = pCallback;
			break;
		default :
			/* Update the error code */
			UART_InitStruct->ErrorCode |= UART_ERROR_INVALID_CALLBACK;

			/* Return error status */
			status =  ERROR;
			break;
	}
 }
  return status;
}


StatusTypeDef HT_ISO7816_RegisterCallback(ISO7816_InitTypeDef *ISO7816_InitStruct, UART_7816_CallbackIDTypeDef CallbackID, pISO7816_CallbackTypeDef pCallback)
{
  StatusTypeDef status = OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    ISO7816_InitStruct->ErrorCode |= UART_ERROR_INVALID_CALLBACK;

    status =  ERROR;
  }
 else
 {
	switch (CallbackID)
	{
        case ISO7816_TX_COMPLETE_CB_ID :
		    ISO7816_InitStruct->TxCpltCallback = pCallback;
			break;

		case ISO7816_RX_COMPLETE_CB_ID :
			ISO7816_InitStruct->RxCpltCallback = pCallback;
			break;

		case ISO7816_PRD_COMPLETE_CB_ID :
			ISO7816_InitStruct->PRDCpltCallback = pCallback;
			break;
		
		default :
			/* Update the error code */
			ISO7816_InitStruct->ErrorCode |= UART_ERROR_INVALID_CALLBACK;

			/* Return error status */
			status =  ERROR;
			break;
	}
 }
  return status;
}

/**
*********************************************************************************************************
*                                         INITIAL UART CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: UART_InitStruct Pointer to a UART_InitTypeDef structure that contains
*               the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void UART_InitCallbacksToDefault(UART_InitTypeDef *UART_InitStruct)
{
  /* Init the UART Callback settings */
  UART_InitStruct->TxCpltCallback = HT_UART_TxCpltCallback;            /* Legacy weak TxCpltCallback            */
  UART_InitStruct->PRDCpltCallback = HT_UART_PRDCpltCallback;            /* Legacy weak TxCpltCallback            */
  UART_InitStruct->NEGCpltCallback = HT_UART_NEGCpltCallback;

  if(SET == READ_BIT(UART_InitStruct->Instance->IRCON, UART_IRCON_IRTX))
  {	
    UART_InitStruct->RxCpltCallback = NULL;
  }
  else
  {

    UART_InitStruct->RxCpltCallback = HT_UART_RxCpltCallback;            /* Legacy weak RxCpltCallback            */
  }
}

/**
*********************************************************************************************************
*                                         INITIAL ISO7816 CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: ISO7816_InitStruct Pointer to a ISO7816_InitTypeDef structure that contains
*               the configuration information for the specified ISO7816 module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void ISO7816_InitCallbacksToDefault(ISO7816_InitTypeDef *ISO7816_InitStruct)
{
  /* Init the ISO7816 Callback settings */
  ISO7816_InitStruct->TxCpltCallback = HT_ISO7816_TxCpltCallback;                    /* Legacy weak TxCpltCallback            */
  ISO7816_InitStruct->RxCpltCallback = HT_ISO7816_RxCpltCallback;                    /* Legacy weak RxCpltCallback            */
  ISO7816_InitStruct->PRDCpltCallback = HT_ISO7816_PRDCpltCallback;                  /* Legacy weak PRDCpltCallback            */
}

/**
*********************************************************************************************************
*                                         UART Receive IT HANDLER
*
* @brief: Receives an amount of data in non blocking mode
*
* @param: UART_InitStruct Pointer to a UART_InitTypeDef structure that contains
*               the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void UART_Receive_IT(UART_InitTypeDef *UART_InitStruct)
{
	 /*Call registered Rx complete callback*/
	 if(UART_InitStruct->RxCpltCallback != NULL)
	 {
		UART_InitStruct->RxCpltCallback(UART_InitStruct);
	 }
}


/**
*********************************************************************************************************
*                                         ISO7816 Receive IT HANDLER
*
* @brief: Receives an amount of data in non blocking mode
*
* @param: ISO7816_InitStruct Pointer to a ISO7816_InitTypeDef structure that contains
*               the configuration information for the specified ISO7816 module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void ISO7816_Receive_IT(ISO7816_InitTypeDef *ISO7816_InitStruct)
{
	 /*Call registered Rx complete callback*/
	 if(ISO7816_InitStruct->RxCpltCallback != NULL)
	 {
		ISO7816_InitStruct->RxCpltCallback(ISO7816_InitStruct);
	 }
}

/**
*********************************************************************************************************
*                                         ISO7816 TRANSMIT IT HANDLER
*
* @brief: Sends an amount of data in non blocking mode.
*
* @param: ISO7816_InitStruct  Pointer to a ISO7816_InitTypeDef structure that contains
*                the configuration information for the specified ISO7816 module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void ISO7816_Transmit_IT(ISO7816_InitTypeDef *ISO7816_InitStruct)
{
  /*Call registered Tx complete callback*/
	if(ISO7816_InitStruct->TxCpltCallback != NULL)
	{
	   ISO7816_InitStruct->TxCpltCallback(ISO7816_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                         UART TRANSMIT IT HANDLER
*
* @brief: Sends an amount of data in non blocking mode.
*
* @param: UART_InitStruct  Pointer to a UART_InitTypeDef structure that contains
*                the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void UART_Transmit_IT(UART_InitTypeDef *UART_InitStruct)
{
  /*Call registered Tx complete callback*/
	if(UART_InitStruct->TxCpltCallback != NULL)
	{
	   UART_InitStruct->TxCpltCallback(UART_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                         UART PRD IT HANDLER
*
* @brief: OVERFLOW an amount of data in non blocking mode.
*
* @param: UART_InitStruct  Pointer to a UART_InitTypeDef structure that contains
*                the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/

#if defined  USE_UART_IRQ 
//static void UART_PRD_IT(UART_InitTypeDef *UART_InitStruct);

static void UART_PRD_IT(UART_InitTypeDef *UART_InitStruct)
{
  /*Call registered PRD complete callback*/
	if(UART_InitStruct->PRDCpltCallback!= NULL)
	{
	   UART_InitStruct->PRDCpltCallback(UART_InitStruct);
	}
}
#endif
/**
*********************************************************************************************************
*                                         ISO7816 ERROR IT HANDLER
*
* @brief: ERROR an amount of data in non blocking mode.
*
* @param: ISO7816_InitStruct  Pointer to a ISO7816_InitTypeDef structure that contains
*                the configuration information for the specified ISO7816 module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void ISO7816_ERROR_IT(ISO7816_InitTypeDef *ISO7816_InitStruct)
{
  /*Call registered PRD complete callback*/
	if(ISO7816_InitStruct->PRDCpltCallback != NULL)
	{
	   ISO7816_InitStruct->PRDCpltCallback(ISO7816_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                         UART IRQ HANDLER
*
* @brief: This function handles UART interrupt request.
*
* @param: UART_InitStruct  Pointer to a UART_InitTypeDef structure that contains
*                the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_UART_IRQHandler(UART_InitTypeDef *UART_InitStruct)
{
  uint32_t isrflags   = READ_REG(UART_InitStruct->Instance->UARTSTA);
  uint32_t cr1its     = READ_REG(UART_InitStruct->Instance->UARTCON);

#if  defined  USE_UART_IRQ

   /* UART in Receiver -------------------------------------------------*/
	if (((isrflags & UART_UARTSTA_RXIF) != RESET) && ((cr1its & UART_UARTCON_RXIE) != RESET))
	{
	   UART_Receive_IT(UART_InitStruct);
	   HT_UART_ClearITPendingBit(UART_InitStruct->Instance, UART_UARTSTA_RXIF);             /*!< clear interrupt flag          */

	}

  /* UART in Transmitter ------------------------------------------------*/
  if (((isrflags & UART_UARTSTA_TXIF) != RESET) && ((cr1its & UART_UARTCON_TXIE) != RESET))
  {
     UART_Transmit_IT(UART_InitStruct);
	 HT_UART_ClearITPendingBit(UART_InitStruct->Instance, UART_UARTSTA_TXIF);             /*!< clear interrupt flag          */

  }
  	  /* UART in overflow ------------------------------------------------*/
  if (((isrflags & UART_UARTSTA_PRDIF) != RESET) && ((cr1its & UART_UARTCON_PRDIE) != RESET))
  {
	 UART_PRD_IT(UART_InitStruct);
	 HT_UART_ClearITPendingBit(UART_InitStruct->Instance, UART_UARTSTA_PRDIF);             /*!< clear interrupt flag          */
  }
  

#else    
	/* UART in Receiver -------------------------------------------------*/
	if (((isrflags & UART_UARTSTA_RXIF) != RESET) && ((cr1its & UART_UARTCON_RXIE) != RESET))
	{
	   UART_Receive_IT(UART_InitStruct);
	   HT_UART_ClearITPendingBit(UART_InitStruct->Instance, UART_UARTSTA_RXIF);             /*!< clear interrupt flag          */

	}

  /* UART in Transmitter ------------------------------------------------*/
  if (((isrflags & UART_UARTSTA_TXIF) != RESET) && ((cr1its & UART_UARTCON_TXIE) != RESET))
  {
     UART_Transmit_IT(UART_InitStruct);
	 HT_UART_ClearITPendingBit(UART_InitStruct->Instance, UART_UARTSTA_TXIF);             /*!< clear interrupt flag          */

  }
#endif
}


/**
*********************************************************************************************************
*                                         ISO7816 IRQ HANDLER
*
* @brief: This function handles IS07816 interrupt request.
*
* @param: ISO7816_InitStruct  Pointer to a ISO7816_InitTypeDef structure that contains
*                the configuration information for the specified ISO7816 module.
* @retval: status
*
* @Note: None
*********************************************************************************************************
*/
void HT_ISO7816_IRQHandler(ISO7816_InitTypeDef *ISO7816_InitStruct)
{
  uint32_t isrflags   = READ_REG(ISO7816_InitStruct->Instance->ISO7816STA);
  uint32_t cr1its     = READ_REG(ISO7816_InitStruct->Instance->ISO7816CON);

	/* ISO7816 in Receiver -------------------------------------------------*/
	if (((isrflags & UART_ISO7816STA_RXIF) != RESET) && ((cr1its & UART_ISO7816CON_RXIE) != RESET))
	{
       ISO7816_Receive_IT(ISO7816_InitStruct);
	   HT_ISO7816_ClearITPendingBit(ISO7816_InitStruct->Instance, UART_ISO7816STA_RXIF);             /*!< clear interrupt flag          */

	}

  /* ISO7816 in Transmitter ------------------------------------------------*/
  if (((isrflags & UART_ISO7816STA_TXIF) != RESET) && ((cr1its & UART_ISO7816CON_TXIE) != RESET))
  {
     ISO7816_Transmit_IT(ISO7816_InitStruct);
     HT_ISO7816_ClearITPendingBit(ISO7816_InitStruct->Instance, UART_ISO7816STA_TXIF);             /*!< clear interrupt flag          */

  }
	
	  /* ISO7816 in overflow ------------------------------------------------*/
  if (((isrflags & UART_ISO7816STA_PRDIF) != RESET) && ((cr1its & UART_ISO7816CON_PRDIE) != RESET))
  {
	 ISO7816_ERROR_IT(ISO7816_InitStruct);
	 HT_ISO7816_ClearITPendingBit(ISO7816_InitStruct->Instance, UART_ISO7816STA_PRDIF);             /*!< clear interrupt flag          */
  }
	

}


/**
*********************************************************************************************************
*                                         ISO7816 PRD COMPLETE CALLBACK
*
* @brief: PRD completed callbacks.
*
* @param: ISO7816_InitStruct  Pointer to a ISO7816_InitTypeDef structure that contains
*                the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_ISO7816_PRDCpltCallback(ISO7816_InitTypeDef *ISO7816_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(ISO7816_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_ISO7816_PRDCpltCallback could be implemented in the user file
   */
}
/**
*********************************************************************************************************
*                                         UART PRD COMPLETE CALLBACK
*
* @brief: PRD completed callbacks.
*
* @param: UART_InitStruct  Pointer to a UART_InitTypeDef structure that contains
*                the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_UART_PRDCpltCallback(UART_InitTypeDef *UART_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(UART_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_UART_PRDCpltCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         UART NEGATIVE COMPLETE CALLBACK
*
* @brief: NEGATIVE completed callbacks.
*
* @param: UART_InitStruct  Pointer to a UART_InitTypeDef structure that contains
*                the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_UART_NEGCpltCallback(UART_InitTypeDef *UART_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(UART_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_UART_NEGCpltCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         ISO7816 TX COMPLETE CALLBACK
*
* @brief: Tx Transfer completed callbacks.
*
* @param: ISO7816_InitStruct  Pointer to a ISO7816_InitTypeDef structure that contains
*                the configuration information for the specified ISO7816 module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_ISO7816_TxCpltCallback(ISO7816_InitTypeDef *ISO7816_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(ISO7816_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_ISO7816_TxCpltCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         ISO7816 RX COMPLETE CALLBACK
*
* @brief: Rx Transfer completed callbacks.
*
* @param: ISO7816_InitStruct  Pointer to a ISO7816_InitTypeDef structure that contains
*                the configuration information for the specified ISO7816 module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_ISO7816_RxCpltCallback(ISO7816_InitTypeDef *ISO7816_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(ISO7816_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_ISO7816_RxCpltCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         UART TX COMPLETE CALLBACK
*
* @brief: Tx Transfer completed callbacks.
*
* @param: UART_InitStruct  Pointer to a UART_InitTypeDef structure that contains
*                the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_UART_TxCpltCallback(UART_InitTypeDef *UART_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(UART_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_UART_TxCpltCallback could be implemented in the user file
   */
}




/**
*********************************************************************************************************
*                                         UART RX COMPLETE CALLBACK
*
* @brief: Rx Transfer completed callbacks.
*
* @param: UART_InitStruct  Pointer to a UART_InitTypeDef structure that contains
*                the configuration information for the specified UART module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_UART_RxCpltCallback(UART_InitTypeDef *UART_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(UART_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_UART_RxCpltCallback could be implemented in the user file
   */
}

#endif /* USE_HT_UART_REGISTER_CALLBACKS */

