/*
**********************************************************************************************************
*                                              HT6XXX
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6xxx_uart&7816.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_UART7816_H__
#define __HT6XXX_UART7816_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/



/**
* @brief  UART Callback ID enumeration definition
*/
typedef enum
{
    UART_TX_COMPLETE_CB_ID                = 0x01U,    	                                /*!< UART Tx Complete Callback ID             */
    UART_RX_COMPLETE_CB_ID                = 0x02U,    	                                /*!< UART Rx Complete Callback ID             */
    UART_PRD_COMPLETE_CB_ID               = 0x03U,    	                                /*!< UART PRD Complete Callback ID             */
    UART_NEG_COMPLETE_CB_ID               = 0x04U,    	                                /*!< UART NEG Complete Callback ID             */
    
    ISO7816_TX_COMPLETE_CB_ID             = 0x10U,    	                                /*!< ISO7816 Tx Complete Callback ID             */
    ISO7816_RX_COMPLETE_CB_ID             = 0x20U,    	                                /*!< ISO7816 Rx Complete Callback ID             */
    ISO7816_PRD_COMPLETE_CB_ID            = 0x30U,                                      /*!< ISO7816 PRD Complete Callback ID             */
}UART_7816_CallbackIDTypeDef;


/**
* @brief  UART communication logic definition
*/
typedef enum
{
    UartLogicPositive = UART_UARTCON_UNEG_POSITIVE,                                      /*!< UART communications select positive logic             */
    UartLogicNegetive = UART_UARTCON_UNEG_NEGETIVE,                                      /*!< UART communications select negative logic             */
#if defined	USE_UartLogicAuto
    UartLogicAuto = UART_UARTCON_UNEG_AUTO,                                              /*!< Automatic judgment of UART communication selection and receiving logic   */
#endif
}UARTLogic_TypeDef;                                                                      /*!< end of group UARTLogic_TypeDef */

/**
* @brief  UART stop bit definition
*/
typedef enum
{
    OneStopBits = UART_UARTCON_STOPSEL_1Bit,                                             /*!< One stop bit                      */
    TwoStopBits = UART_UARTCON_STOPSEL_2Bit,                                             /*!< Two stop bits                     */
}UARTStopBits_TypeDef;                                                                   /*!< end of group UARTStopBits_TypeDef */

/**
* @brief  UART data length bit definition
*/
typedef enum
{
    WordLength_7Bits = UART_UARTCON_LENSEL_7Bit,                                         /*!< Seven data bits                         */
    WordLength_8Bits = UART_UARTCON_LENSEL_8Bit,                                         /*!< Eight data bits                        */
}UARTWordLength_TypeDef;                                                                 /*!< end of group UARTWordLength_TypeDef*/

/**
* @brief  
*/
typedef enum
{
    UartParity_Disable = 0xff,                                                           /*!< There are no parity bits                     */
    UartParity_Always1 = UART_UARTCON_PARITYSEL_1,                                       /*!< The parity bit is always one                  */
    UartParity_Always0 = UART_UARTCON_PARITYSEL_0,                                       /*!< The parity bit is always zero                  */
    UartParity_ODD = UART_UARTCON_PARITYSEL_ODD,                                         /*!< ODD                             */
    UartParity_EVEN = UART_UARTCON_PARITYSEL_EVEN,                                       /*!< EVEN                             */
}UARTParity_TypeDef;                                                                     /*!< end of group UARTParity_TypeDef    */

/**
* @brief  The UART module initalizes the structure definition
*/
typedef struct __UART_InitTypeDef
{
    UARTLogic_TypeDef  UART_Logic;                    
    UARTStopBits_TypeDef  UART_StopBits;                
    UARTWordLength_TypeDef  UART_WordLength;            
    UARTParity_TypeDef  UART_Parity;                    
    uint32_t  UART_BaudRate;                            
    FunctionalState  ReceiveEN;                         
    FunctionalState  SendEN;                            
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
	HT_UART_TypeDef  *Instance;        								        	         /*!< UART registers base address        */
	__IO uint32_t    ErrorCode;        									                 /*!< UART Error code                    */
	void (* TxCpltCallback)(struct __UART_InitTypeDef *UART_InitStruct);                 /*!< UART Tx Complete Callback             */
	void (* RxCpltCallback)(struct __UART_InitTypeDef *UART_InitStruct);                 /*!< UART Rx Complete Callback             */
    void (* PRDCpltCallback)(struct __UART_InitTypeDef *UART_InitStruct);                 /*!< UART PRD Complete Callback             */
    void (* NEGCpltCallback)(struct __UART_InitTypeDef *UART_InitStruct);                 /*!< UART NEG Complete Callback             */
#endif  /* USE_HT_UART_REGISTER_CALLBACKS */
}UART_InitTypeDef;                                                                       /*!< end of group UART_InitTypeDef      */



#if defined USE_IR38kSource
/**
* @brief  Select an IR modulated clock source
*/
typedef enum
{
    IR_PLL_SOURCE = UART_IRCON_IR38KSOURCE_PLL,                                          /*!< Select PLL                */
    IR_HRC_SOURCE = UART_IRCON_IR38KSOURCE_HRC,                                          /*!< Select HRC                */
}IR38kSource_TypeDef; 
#endif

#if defined USE_IR38KSOURCE
/**
* @brief  Select an IR modulated clock source
*/
typedef enum
{
    IR_PLLX2_SOURCE = UART_IRCON_IR38KSOURCE_PLLX2,                                          /*!< Select PLLX2                */
    IR_HRC_SOURCE   = UART_IRCON_IR38KSOURCE_HRC,                                          /*!< Select HRC                */
}IR38KSOURCE_TypeDef; 
#endif

/**
* @brief  IR output polarity definition
*/
typedef enum
{
    IRPolarityPositive = UART_IRCON_IRLVL_POSITIVE,                                      /*!< Select positive            */
    IRPolarityNegetive = UART_IRCON_IRLVL_NEGETIVE,                                      /*!< Select negative              */
}IRPolarity_TypeDef;                                                                     /*!< end of group IRPolarity_TypeDef    */

/**
* @brief  IR waveform duty ratio definition
*/
typedef enum
{
    IRDuty50 = UART_IRDUTY_IRDUTY_50,                                                    /*!< IR waveform duty cycle 50%              */
    IRDuty25 = UART_IRDUTY_IRDUTY_25,                                                    /*!< IR waveform duty cycle 25%              */
    IRDuty12P5 = UART_IRDUTY_IRDUTY_12P5,                                                /*!< IR waveform duty cycle 12.5%            */
    IRDuty6P25 = UART_IRDUTY_IRDUTY_6P25,                                                /*!< IR waveform duty cycle 6.25%            */
}IRDuty_TypeDef;                                                                         /*!< end of group IRDuty_TypeDef        */

/**
* @brief  IR initialization structure definition
*/
typedef struct 
{
    UART_InitTypeDef  UARTModule;                                                        /*!< The UART connunication is initialized                    */
#if  defined  USE_UART_IRCON_IRCLKSRC
    IR38kSource_TypeDef IRClkSrc;                                                        /*!< Select IR CLOCK source                    */
#elif defined USE_UART_IRCLKSRC
    IR38KSOURCE_TypeDef IRCLKSRC;
#endif
    IRPolarity_TypeDef  IRPolarity;                                                      /*!< Configure the IR polarity          */
    IRDuty_TypeDef  IRDuty;                                                              /*!< Configure the IR waveform duty            */
#if  defined  USE_UART_IRCLKDIV
    uint16_t IRClkDiv16;                                                                 /*!< IR clock source perdivision setting（0~127）
                                                                                                  0   -> Firclk = Fsysclk / 16
                                                                                                  1   -> Firclk = Fsysclk / 32
                                                                                                  ......
                                                                                                  127 -> Firclk = Fsysclk / 2048 */
#endif 
#if defined USE_UART_IR38KDIV
    uint16_t IRClkDiv16;

#endif

}IR_InitTypeDef;                                                                         /*!< end of group IR_InitTypeDef        */


/**
* @brief  Defines the parity in ISO7816 
*/
typedef enum
{
    ISO7816Parity_ODD = UART_ISO7816CON_7816PARITY_ODD,                                   /*!< ODD                             */
    ISO7816Parity_EVEN = UART_ISO7816CON_7816PARITY_EVEN,                                 /*!< EVEN                             */
}ISO7816Parity_TypeDef;                                                                   /*!< end of group ISO7816Parity_TypeDef */

/**
* @brief  Defines the RepeatTime in ISO7816
*/
typedef enum
{
    Repeat_Zero = UART_ISO7816CON_REPTR_0,                                                /*!< Set the automatic resend times to 0              */
    Repeat_One = UART_ISO7816CON_REPTR_1,                
    Repeat_Two = UART_ISO7816CON_REPTR_2,                
    Repeat_Three = UART_ISO7816CON_REPTR_3,              
}ISO7816Repeat_TypeDef;                                                                   /*!< end of group ISO7816Repeat_TypeDef */

/**
* @brief  ISO7816 defines the response bit length
*/
typedef enum
{
    ACKLen_1Bit = UART_ISO7816CON_ACKLEN_1Bit,                                            /*!< ACK bit length is 1Bit                   */
    ACKLen_1P5Bit = UART_ISO7816CON_ACKLEN_1P5Bit,                                        /*!< ACK bit length is 1.5Bit                 */
    ACKLen_2Bit = UART_ISO7816CON_ACKLEN_2Bit,                                            /*!< ACK bit length is 2Bit                   */
}ISO7816ACKLen_TypeDef;                                                                   /*!< end of group ISO7816ACKLen_TypeDef*/

/**
* @brief  The ISO7816 module initializes the structure definition
*/
typedef struct __ISO7816_InitTypeDef
{
    ISO7816Parity_TypeDef  ISO7816_Parity;                                                /*!< ISO7816  parity set                  */
    ISO7816Repeat_TypeDef  ISO7816_RepeatTime;                                            /*!< ISO7816 Configure the RepeatTime           */
    FunctionalState  AutoRxEN;                                                            /*!< Auto receive enable                  */
    FunctionalState  AutoTxEN;                                                            /*!< Auto send enable                  */
    ISO7816ACKLen_TypeDef  ISO7816_AckLen;                                                /*!< Configure the AckLen              */
    uint32_t  ISO7816_BaudRate;                                                           /*!< Configure theBaudRate       */
	

#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
	HT_ISO7816_TypeDef  *Instance;        									              /*!< ISO7816 registers base address        */
	__IO uint32_t    ErrorCode;        									                  /*!< ISO7816 Error code                    */
    void (* TxCpltCallback)(struct __ISO7816_InitTypeDef *ISO7816_InitStruct);            /*!< ISO7816 Tx Complete Callback             */
	void (* RxCpltCallback)(struct __ISO7816_InitTypeDef *ISO7816_InitStruct);            /*!< ISO7816 Rx Complete Callback             */
	void (* PRDCpltCallback)(struct __ISO7816_InitTypeDef *ISO7816_InitStruct);           /*!< ISO7816 PRD Complete Callback             */

#endif  /* USE_HT_ISO7816_REGISTER_CALLBACKS */
}ISO7816_InitTypeDef;                                                                     /*!< end of group ISO7816_InitTypeDef  */

#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)

/**
* @brief  UART Callback pointer definition
*/
typedef  void (*pUART_CallbackTypeDef)(UART_InitTypeDef *UART_InitStruct);               /*!< pointer to an UART callback function */

/**
* @brief  ISO7816 Callback pointer definition
*/
typedef  void (*pISO7816_CallbackTypeDef)(ISO7816_InitTypeDef *ISO7816_InitStruct);      /*!< pointer to an ISO7816 callback function */


/**
* @brief  UART Error Code
*/
#define UART_ERROR_NONE              0x00000000U                                         /*!< No error            */
#define UART_ERROR_PE                0x00000001U                                         /*!< Parity error        */
#define UART_ERROR_NE                0x00000002U                                         /*!< Noise error         */
#define UART_ERROR_FE                0x00000004U                                         /*!< Frame error         */
#define UART_ERROR_ORE               0x00000008U                                         /*!< Overrun error       */
#define UART_ERROR_DMA               0x00000010U                                         /*!< DMA transfer error  */

/**
* @brief  UART Error Code
*/
#define UART_ERROR_NONE              0x00000000U                                         /*!< No error            */
#define UART_ERROR_PE                0x00000001U                                         /*!< Parity error        */
#define UART_ERROR_NE                0x00000002U                                         /*!< Noise error         */
#define UART_ERROR_FE                0x00000004U                                         /*!< Frame error         */
#define UART_ERROR_ORE               0x00000008U                                         /*!< Overrun error       */
#define UART_ERROR_DMA               0x00000010U                                         /*!< DMA transfer error  */
#define UART_ERROR_INVALID_CALLBACK  0x00000020U                                         /*!< Invalid Callback error  */

#endif /* USE_UART_REGISTER_CALLBACKS */

/**
* @brief  HT_USART_Exported_Constants
*/
#if defined  USE_UART6
#define IS_HT_UART_ALL_PERIPH(PERIPH)                                          (((PERIPH) == HT_UART0) || \
																				((PERIPH) == HT_UART1) || \
																				((PERIPH) == HT_UART2) || \
																				((PERIPH) == HT_UART3) || \
																				((PERIPH) == HT_UART4) || \
																				((PERIPH) == HT_UART5) || \
																				((PERIPH) == HT_UART6))
#else
#define IS_HT_UART_ALL_PERIPH(PERIPH)                                          (((PERIPH) == HT_UART0) || \
																				((PERIPH) == HT_UART1) || \
																				((PERIPH) == HT_UART2) || \
																				((PERIPH) == HT_UART3) || \
																				((PERIPH) == HT_UART4) || \
																				((PERIPH) == HT_UART5))
#endif

#define IS_HT_UART_BAUDRATE(BAUDRATE) ((BAUDRATE) <= 25000000U)

/**
* @brief  HT_UART_Word_Length
*/                                 
#define IS_HT_UART_WORD_LENGTH(LENGTH)                                         (((LENGTH) == UART_UARTCON_LENSEL_8Bit) || \
										                                        ((LENGTH) == UART_UARTCON_LENSEL_7Bit))
 
/**
* @brief  HT_UART_Stop_Bits
*/ 
#define IS_HT_UART_STOPBITS(STOPBITS)                                          (((STOPBITS) == UART_UARTCON_STOPSEL_1Bit)|| \
									                                            ((STOPBITS) == UART_UARTCON_STOPSEL_2Bit))
 
/**
* @brief  HT_UART_Parity
*/ 
#define IS_HT_UART_PARITY(PARITY)                                              (((PARITY) == UART_UARTCON_PARITYSEL_0) || \
										                                        ((PARITY) == UART_UARTCON_PARITYSEL_EVEN) || \
																	            ((PARITY) == UART_UARTCON_PARITYSEL_ODD) || \
																	            ((PARITY) == UART_UARTCON_PARITYSEL_1))

/**
* @brief  HT_UART_RXFilter
*/
#define IS_HT_UART_RXFILTER(RXFILTER)                                          ((((RXFILTER)>>8) > 0) && (((RXFILTER)>>8) <= (INT_PINFLT_RXFLT>>8)))

/**
* @brief  HT_UART_ITFlag
*/
#define IS_HT_UART_ITFLAG(ITFLAG)                                              (((ITFLAG) > 0) && ((ITFLAG) <= (UART_UARTSTA)))

/**
* @brief  HT_ISO7816_Exported_Constants
*/
#define IS_HT_ISO7816_ALL_PERIPH(PERIPH)                                       (((PERIPH) == HT_ISO7816_0) || \
																			    ((PERIPH) == HT_ISO7816_1))

/**
* @brief  HT_IR_Duty
*/ 
#define IS_HT_IR_DUTY(DUTY) 				                                   (((DUTY) == UART_IRDUTY_IRDUTY_50) || \
                                                                                ((DUTY) == UART_IRDUTY_IRDUTY_25) || \
																                ((DUTY) == UART_IRDUTY_IRDUTY_12P5) || \
                                                                                ((DUTY) == UART_IRDUTY_IRDUTY_6P25))

#define IS_HT_IR_CLKDIV(CLKDIV)                                                 ((CLKDIV) <= 127)

/**
* @brief  HT_ISO7816_Parity
*/ 
#define IS_HT_ISO7816_PARITY(PARITY)                                           (((PARITY) == UART_ISO7816CON_7816PARITY_ODD) || \
																	            ((PARITY) == UART_ISO7816CON_7816PARITY_EVEN))

/**
* @brief  HT_ISO7816_RepeatTime
*/
#define IS_HT_ISO7816_REPEATTIME(REPEATTIME)                                   (((REPEATTIME) == UART_ISO7816CON_REPTR_0) || \
																				((REPEATTIME) == UART_ISO7816CON_REPTR_1) || \
																				((REPEATTIME) == UART_ISO7816CON_REPTR_2) || \
																				((REPEATTIME) == UART_ISO7816CON_REPTR_3))

/**
* @brief  HT_ISO7816_AckLen
*/
#define IS_HT_ISO7816_ACKLEN(ACKLEN)                                          (((ACKLEN) == UART_ISO7816CON_ACKLEN_1Bit) || \
																	           ((ACKLEN) == UART_ISO7816CON_ACKLEN_1P5Bit) || \
																	           ((ACKLEN) == UART_ISO7816CON_ACKLEN_2Bit))														

/**
* @brief  HT_ISO7816_BaudRate
*/
#define IS_HT_ISO7816_BAUDRATE(BAUDRATE)                                      (((BAUDRATE) > 0) && ((BAUDRATE) < UART_SREL))

/**
* @brief  HT_ISO7816_ITFlag
*/
#define IS_HT_ISO7816_ITFLAG(ITFLAG)                                          (((ITFLAG) > 0) && ((ITFLAG) <= (UART_ISO7816STA)))

/**
* @brief  UART_InitStruct_TxXferCount
*/
#define	IS_UART_InitStruct_TxXferCount(TxXferCount)	                          ((TxXferCount) != 0)

/**
* @brief  UART_InitStruct_TxXferSize
*/
#define	IS_UART_InitStruct_TxXferSize(TxXferSize)	                          ((TxXferSize) != 0)

/**
* @brief  UART_InitStruct_pTxBuffPtr
*/
#define	IS_UART_InitStruct_pTxBuffPtr(pTxBuffPtr)	                          ((pTxBuffPtr) != NULL)

/**
* @brief  UART_InitStruct_RxXferCount
*/
#define	IS_UART_InitStruct_RxXferCount(RxXferCount)	                          ((RxXferCount) != 0)

/**
* @brief  UART_InitStruct_RxXferSize
*/
#define	IS_UART_InitStruct_RxXferSize(RxXferSize)	                          ((RxXferSize) != 0)

/**
* @brief  UART_InitStruct_pRxBuffPtr
*/
#define	IS_UART_InitStruct_pRxBuffPtr(pRxBuffPtr)	                          ((pRxBuffPtr) != NULL)

/**
* @brief  Enable the specified UART interrupt.
* @param  __HANDLE__ specifies the UART Handle.
*         UART Handle selects the USARTx or UARTy peripheral
*         (USART,UART availability and x,y values depending on device).
* @param  __INTERRUPT__ specifies the UART interrupt source to enable.
*          This parameter can be one of the following values:
*            @arg UART_UARTCON_TXIE:  Transmit Data interrupt
*            @arg UART_UARTCON_RXIE: Receive Data interrupt
* @retval None
*/
#define __UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)                           ((__HANDLE__)->Instance->UARTCON |= (__INTERRUPT__))

/**
* @brief  Disable the specified UART interrupt.
* @param  __HANDLE__ specifies the UART Handle.
*         UART Handle selects the USARTx or UARTy peripheral
*         (USART,UART availability and x,y values depending on device).
* @param  __INTERRUPT__ specifies the UART interrupt source to disable.
*          This parameter can be one of the following values:
*            @arg UART_UARTCON_TXIE:  Transmit Data interrupt
*            @arg UART_UARTCON_RXIE: Receive Data interrupt
* @retval None
*/
#define __UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)                          ((__HANDLE__)->Instance->UARTCON &= ~(__INTERRUPT__))

/**
* @brief  Checks whether the specified UART interrupt source is enabled or not.
* @param  __HANDLE__ specifies the UART Handle.
*         UART Handle selects the USARTx or UARTy peripheral
*         (USART,UART availability and x,y values depending on device).
* @param  __IT__ specifies the UART interrupt source to check.
*          This parameter can be one of the following values:
*            @arg UART_UARTCON_TXIE: Transmit Data interrupt
*            @arg UART_UARTCON_RXIE: Receive Data interrupt
* @retval The new state of __IT__ (TRUE or FALSE).
*/
#define __UART_GET_IT_SOURCE(__HANDLE__, __IT__)                              (((__HANDLE__)->Instance->UARTCON) & ((uint32_t)(__IT__)))

/*
*********************************************************************************************************
*                                             Global Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
void HT_UART_Init(HT_UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct);
void HT_IR_Init(HT_UART_TypeDef* UARTx, IR_InitTypeDef* IR_InitStruct);
void HT_ISO7816_Init(HT_ISO7816_TypeDef* ISO7816x, ISO7816_InitTypeDef* ISO7816_InitStruct);
void HT_UART_ITConfig(HT_UART_TypeDef* UARTx, uint32_t ITEn, FunctionalState NewState);
ITStatus HT_UART_ITFlagStatusGet(HT_UART_TypeDef* UARTx, uint32_t ITFlag);
void HT_UART_ClearITPendingBit(HT_UART_TypeDef* UARTx, uint32_t ITFlag);
void HT_ISO7816_ITConfig(HT_ISO7816_TypeDef* ISO7816x, uint32_t ITEn, FunctionalState NewState);
ITStatus HT_ISO7816_ITFlagStatusGet(HT_ISO7816_TypeDef* ISO7816x, uint32_t ITFlag);
void HT_ISO7816_ClearITPendingBit(HT_ISO7816_TypeDef* ISO7816x, uint32_t ITFlag);
void HT_UART_SendData(HT_UART_TypeDef* UARTx, uint32_t Data);
uint32_t HT_UART_ReceiveData(HT_UART_TypeDef* UARTx);
void HT_ISO7816_SendData(HT_ISO7816_TypeDef* ISO7816x, uint32_t Data);
uint32_t HT_ISO7816_ReceiveData(HT_ISO7816_TypeDef* ISO7816x);
void HT_UART_RXFilterConfig(uint32_t RXFLTEn,FunctionalState NewState);

#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
void HT_UART_TxCpltCallback(UART_InitTypeDef *UART_InitStruct);
void HT_UART_RxCpltCallback(UART_InitTypeDef *UART_InitStruct);
void HT_UART_PRDCpltCallback(UART_InitTypeDef *UART_InitStruct);
void HT_UART_NEGCpltCallback(UART_InitTypeDef *UART_InitStruct);
StatusTypeDef HT_UART_RegisterCallback(UART_InitTypeDef *UART_InitStruct, UART_7816_CallbackIDTypeDef CallbackID, pUART_CallbackTypeDef pCallback);
void HT_ISO7816_PRDCpltCallback(ISO7816_InitTypeDef *ISO7816_InitStruct);
void HT_ISO7816_TxCpltCallback(ISO7816_InitTypeDef *ISO7816_InitStruct);
void HT_ISO7816_RxCpltCallback(ISO7816_InitTypeDef *ISO7816_InitStruct);
StatusTypeDef HT_ISO7816_RegisterCallback(ISO7816_InitTypeDef *ISO7816_InitStruct, UART_7816_CallbackIDTypeDef CallbackID, pISO7816_CallbackTypeDef pCallback);  
void HT_IR_IRQHandler(IR_InitTypeDef *IR_InitStruct);
#endif /* USE_HT_UART_REGISTER_CALLBACKS */

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_UART7816_H__ */
