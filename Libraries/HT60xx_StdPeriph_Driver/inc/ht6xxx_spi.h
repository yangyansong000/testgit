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
* File         : ht6xxx_spi.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_SPI_H__
#define __HT6XXX_SPI_H__

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
* @brief  SPI Callback ID enumeration definition
*/
typedef enum
{
	SPI_MODF_CB_ID                     = 0x01U,    	 /*!< SPI Modf Fault Callback ID */
    SPI_SPIF_CB_ID                     = 0x02U,      /*!< SPI Date Transfer Callback ID  */
#if  defined  USE_SPI_FIFO
	SPI_FIFO_TXE_CB_ID                 = 0x03U,     /*!< SPI TXE Callback ID */
	SPI_FIFO_RXNE_CB_ID                = 0x04U,     /*!< SPI RXNE Callback ID */
	SPI_FIFO_TXF_CB_ID                 = 0x05U,     /*!< SPI TXF Callback ID */
	SPI_FIFO_RXF_CB_ID                 = 0x06U,     /*!< SPI RXF Callback ID */
	SPI_FIFO_TXO_CB_ID                 = 0x07U,     /*!< SPI TXO Callback ID */
	SPI_FIFO_RXO_CB_ID                 = 0x08U,     /*!< SPI RXO Callback ID */
	SPI_FIFO_TXT_CB_ID                 = 0x09U,     /*!< SPI TXT Callback ID */
	SPI_FIFO_RXT_CB_ID                 = 0x0AU,	    /*!< SPI RXT Callback ID */
	SPI_FIFO_TXDONE_CB_ID              = 0x0BU,	    /*!< SPI TXDONE Callback ID */		
#endif	
} SPI_CallbackIDTypeDef;
	
#if  defined  USE_SPI_FIFO
/**
* @brief  SPIFIFO CTR definition
*/
typedef enum
{
  FIFOCTR_1P5 = SPI_FIFOCON_CTR_1P5,            /*!<Fast Slave Mode Filter 1.5ns */
  FIFOCTR_3P0 = SPI_FIFOCON_CTR_3P0,            /*!<Fast Slave Mode Filter 3 ns  */
  FIFOCTR_4P5 = SPI_FIFOCON_CTR_4P5,            /*!<Fast Slave Mode Filter 4.5ns */
}SPIFIFO_CTR_TypeDef;

/**
* @brief  SPIFIFO EXINSEL definition
*/
typedef enum
{
	FIFO_EXINSEL_APB  = SPI_FIFOCON_EX_IN_SEL_APB,   /*!<FIFO Data is Written from APB */
	FIFO_EXINSEL_EXIN = SPI_FIFOCON_EX_IN_SEL_EXIN,  /*!<FIFO Data Source External Port */ 
}SPIFIFO_EXINSEL_TypeDef;

/**
* @brief  SPIFIFO HLCS definition
*/
typedef enum
{
   FIFO_HLCS_LOW  = SPI_FIFOCON_HLCS_LOW,           /*!<Set SPI_CS to Low */	
   FIFO_HLCS_HIGH = SPI_FIFOCON_HLCS_HIGH,          /*!<Set SPI_CS to High*/   	
	
}SPIFIFO_HLCS_TypeDef;

/**
* @brief  SPIFIFO FSEN definition
*/
typedef enum
{
	FIFO_FSEN_DISABLE = 0x00U,
	FIFO_FSEN_ENABLE  = SPI_FIFOCON_FS_EN,           /*!<Enable Fast Slave With FIFO   */  
	
}SPIFIFO_FSEN_TypeDef;

/**
* @brief  SPIFIFO RXFIFORST definition
*/
typedef enum
{
	FIFO_RXFIFORST_0 = 0x00U,
	FIFO_RXFIFORST_1 = SPI_FIFOCON_RXFIFO_RST,     /*!<Receive FIFO Write Reset  */
}SPIFIFO_RXFIFORST_TypeDef;

/**
* @brief  SPIFIFO RXFIFORST definition
*/
typedef enum
{
	FIFO_TXFIFORST_0 = 0x00U,
	FIFO_TXFIFORST_1 = SPI_FIFOCON_TXFIFO_RST,      /*!<Send FIFO Write Reset   */
}SPIFIFO_TXFIFORST_TypeDef;

/**
* @brief  SPIFIFO RXFIFOEN definition
*/
typedef enum
{
	FIFO_RXFIFOEN_DISABLE = 0x00U,
	FIFO_RXFIFOEN_ENABLE = SPI_FIFOCON_RXFIFO_EN,    /*!<FIFO Receiving Enable Control   */
}SPIFIFO_RXFIFOEN_TypeDef;

/**
* @brief  SPIFIFO TXFIFOEN definition
*/
typedef enum
{
	FIFO_TXFIFOEN_DISABLE = 0x00U,
	FIFO_TXFIFOEN_ENABLE = SPI_FIFOCON_TXFIFO_EN,    /*!<FIFO sending Enable Control     */
}SPIFIFO_TXFIFOEN_TypeDef; 

/**
* @brief  SPI_CS Delay initialization structure definition
*/
typedef struct __SPI_FIFOInitTypeDef 
{
	SPIFIFO_CTR_TypeDef   SPIFIFO_CTR;              /*!<Fast Slave Mode Filter Control */
	uint32_t  SPIFIFO_RXFIFOTL;                     /*!<Receive FIFO threshold Setting  */
	uint32_t  SPIFIFO_TXFIFOTL;                     /*!<Send FIFO Threshold Setting */
	SPIFIFO_EXINSEL_TypeDef  SPIFIFO_EXINSEL;       /*!<FIFO Data Source Control */ 
	SPIFIFO_HLCS_TypeDef     SPIFIFO_HLCS;          /*!<CS State Control During BDLY Delay */ 
	SPIFIFO_RXFIFORST_TypeDef SPIFIFO_RXFIFORST;     /*!<Receive FIFO Write Reset */
	SPIFIFO_TXFIFORST_TypeDef SPIFIFO_TXFIFORST;    /*!<Send FIFO Write Reset */
	FunctionalState   SPIFIFO_FSEN;                 /*!<Enable Fast Slave With FIFO */
	FunctionalState	  SPIFIFO_RXFIFOEN;             /*!<FIFO Receiving Enable Control */ 
	FunctionalState	  SPIFIFO_TXFIFOEN;             /*!<FIFO Sending Enable Control */
#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
	HT_SPI_TypeDef *Instance;
	void (* SPIFIFOTxeCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);    /*!<SPI Send FIFO Empty Interrupt Callback */	
	void (* SPIFIFORxneCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);   /*!<SPI Receive FIFO non-Empty Interrupt Callback */	
	void (* SPIFIFOTxfCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);    /*!<SPI Send FIFO Full Interrupt Callback */
	void (* SPIFIFORxfCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);    /*!<SPI Receive FIFO Full Interrupt Callback */
	void (* SPIFIFOTxoCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);    /*!<SPI Send FIFO Overflow Interrupt Callback */
	void (* SPIFIFORxoCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);    /*!<SPI Receive FIFO Overflow Interrupt Callback */
	void (* SPIFIFOTxtCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);    /*!<SPI Send FIFO less than or equal to the trigger threshold Interrupt Callback */
	void (* SPIFIFORxtCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);    /*!<SPI Receive FIFO more than or equal to the trigger threshold Interrupt Callback */
	void (* SPIFIFOTxdoneCallback)(struct __SPI_FIFOInitTypeDef *SPI_FIFOInitStruct); /*!<SPI Send FIFO Data complete Interrupt Callback */
#endif
}SPI_FIFOInitTypeDef; 
#endif	
		
/**
* @brief  SPI Clock Phase Definition
*/
typedef enum
{
    SPI_CPHA_1Edge = 0x00U,                      /*!< The First Dynamic Data is Sent Along the Previous Half Cycle  */
    SPI_CPHA_2Edge = SPI_SPICON_CPHA,           /*!< Data is Sent After the Dynamic Edge Passes  */
}SPICPHA_TypeDef;                               /*!< end of group SPICPHA_TypeDef      */

/**
* @brief  SPI clock polarity definition
*/
typedef enum
{
    SPI_CPOL_Low  = 0x00U,                       /*!< The Idle SCK is Set to Low          */
    SPI_CPOL_high = SPI_SPICON_CPOL,            /*!< The Idle SCK is Set to High         */
}SPICPOL_TypeDef;                               /*!< end of group SPICPOL_TypeDef        */

/**
* @brief  SPI clock frequency definition
*/
typedef enum
{
    SPI_BaudRatePrescaler_2   = SPI_SPICON_SPR_FSYSDIV2,     /*!< Fspi = Fsys/2  */
    SPI_BaudRatePrescaler_4   = SPI_SPICON_SPR_FSYSDIV4,     /*!< Fspi = Fsys/4  */
    SPI_BaudRatePrescaler_8   = SPI_SPICON_SPR_FSYSDIV8,     /*!< Fspi = Fsys/8  */
    SPI_BaudRatePrescaler_16  = SPI_SPICON_SPR_FSYSDIV16,    /*!< Fspi = Fsys/16 */
    SPI_BaudRatePrescaler_32  = SPI_SPICON_SPR_FSYSDIV32,    /*!< Fspi = Fsys/32 */
    SPI_BaudRatePrescaler_64  = SPI_SPICON_SPR_FSYSDIV64,    /*!< Fspi = Fsys/64 */
    SPI_BaudRatePrescaler_128 = SPI_SPICON_SPR_FSYSDIV128,   /*!< Fspi = Fsys/128*/
    SPI_CLK_None              = SPI_SPICON_SPR_NONCLK,       /*!< No master clock is generated */
#if  defined  USE_SPI_ODDDIV
    SPI_BaudRatePrescaler_3   = SPI_SPIDIV_FSYSDIV3,     /*!< Fspi = Fsys/3 */
    SPI_BaudRatePrescaler_5   = SPI_SPIDIV_FSYSDIV5,     /*!< Fspi = Fsys/5 */
    SPI_BaudRatePrescaler_6   = SPI_SPIDIV_FSYSDIV6,     /*!< Fspi = Fsys/6 */
    SPI_BaudRatePrescaler_7   = SPI_SPIDIV_FSYSDIV7,     /*!< Fspi = Fsys/7 */
    SPI_BaudRatePrescaler_9   = SPI_SPIDIV_FSYSDIV9,     /*!< Fspi = Fsys/9 */
#endif
}SPIBaudrate_TypeDef;                           /*!< end of group SPIBaudrate_TypeDef  */

/**
* @brief  SPI Mode definition
*/
typedef enum
{
    SPI_Slave  = 0x00U,                          /*!< SPI Master Mode */
    SPI_Master = SPI_SPICON_MSTR,               /*!< SPI Slave Mode */
}SPIMode_TypeDef;                               /*!< end of group SPIMode_TypeDef */

#if  defined  USE_SPI_SPICON_FASTEN
/**
* @brief  SPI FAST Slave definition
*/
typedef enum
{
    SPI_SlowSlave  = 0x00U,                      /*!< SPI Slow Slave Mode */
    SPI_FastSlave = SPI_SPICON_FASTEN,          /*!< SPI Fast Slave Mode */
}SPIFastSlave_TypeDef; 
#endif 

#if  defined  USE_SPI_SPICON_LSBEN
/**
* @brief  SPI MSB or LSB definition
*/
typedef enum
{
    SPI_MSB = 0x00U,                             /*!< SPI Send MSB in the Front */
    SPI_LSB = SPI_SPICON_LSBEN_LSB,             /*!< SPI Send LSB in the Front */
}SPILSB_TypeDef; 
#endif 

#if  defined  USE_SPI_SPICLK
/**
* @brief  SPI clock source selection definition (Currently SPI2 only)
*/
typedef enum
{
    SPI_CLKSEL_OSC     = SPI_SPICLKSEL_SPICLK_OSC,    /*!< OSC Frequency  */
    SPI_CLKSEL_LRC     = SPI_SPICLKSEL_SPICLK_LRC,    /*!< LRC Frequency  */
    SPI_CLKSEL_HRC     = SPI_SPICLKSEL_SPICLK_HRC,    /*!< HRC Frequency  */
    SPI_CLKSEL_PLL44M  = SPI_SPICLKSEL_SPICLK_PLL,    /*!< PLL Frequency  */
}SPIClkSel_TypeDef;                             /*!< end of group SPIClkSel_TypeDef */
#endif

/**
* @brief  SPI module extends the initialization structure definition
*/
typedef struct __SPI_InitTypeDef
{
#if  defined  USE_SPI_SPICON_FASTEN	
	SPIFastSlave_TypeDef SPI_FASTEN;            /*!< SPI Fast Slave  Setting */
#endif
#if  defined  USE_SPI_SPICON_LSBEN
	SPILSB_TypeDef SPI_LSBEN;                   /*!< SPI MSB or LSB Setting */
#endif
    FunctionalState SPI_CSInCtrol;              /*!< Whether to Turn On SPI_CS Input Control During Slave Mode */
    SPIBaudrate_TypeDef SPI_Baudrate;           /*!< SPI Clock  Setting                 */
    SPICPHA_TypeDef SPI_CPHA;                   /*!< SPI Clock Phase Setting            */
    SPICPOL_TypeDef SPI_CPOL;                   /*!< SPI Clock Polarity Setting         */
    SPIMode_TypeDef SPI_Mode;                   /*!< SPI_Mode  Setting                  */
#if  defined  USE_SPI_SPICLK
    SPIClkSel_TypeDef SPI_CLK;                  /*!< SPI Clock Source Setting (only SPI2, no extension) */
#endif
#if  defined  USE_SPI_FIFO
	SPI_FIFOInitTypeDef	 SPI_FIFOInitStruct;
#endif
		
#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
	HT_SPI_TypeDef *Instance;	
	__IO uint32_t   ErrorCode;                                             /*!<SPI Error code */   
	void (* SPIModfCallback)(struct __SPI_InitTypeDef *SPI_InitStruct);    /*!<SPI Mode Fault Interrupt Callback */	
	void (* SPISpifCallback)(struct __SPI_InitTypeDef *SPI_InitStruct);    /*!<SPI Data Transfer Completion flag Callback */	
#endif	
}SPI_InitTypeDef;                               /*!< end of group SPI_InitTypeDef        */

#if defined  USE_SPI_CSDLY
/**
* @brief  SPI CSB definition
*/
typedef enum
{
    SPI_CSB_0CLK  = SPI_CSDLY_CSB_0,             /*!< Advance 0 Clk Pull down SPI_CS Before Send Data */
    SPI_CSB_2CLK  = SPI_CSDLY_CSB_2,             /*!< Advance 2 Clk Pull down SPI_CS Before Send Data */
    SPI_CSB_4CLK  = SPI_CSDLY_CSB_4,             /*!< Advance 4 Clk Pull down SPI_CS Before Send Data */
	SPI_CSB_8CLK  = SPI_CSDLY_CSB_8,             /*!< Advance 8 Clk Pull down SPI_CS Before Send Data */	
}SPICSB_TypeDef;  

/**
* @brief  SPI CSA definition
*/
typedef enum
{
    SPI_CSA_0CLK  = SPI_CSDLY_CSA_0,             /*!< Delay 0 Clk Pull Up SPI_CS After Send Data */
    SPI_CSA_2CLK  = SPI_CSDLY_CSA_2,             /*!< Delay 2 Clk Pull Up SPI_CS After Send Data */
    SPI_CSA_4CLK  = SPI_CSDLY_CSA_4,             /*!< Delay 4 Clk Pull Up SPI_CS After Send Data */
	SPI_CSA_8CLK  = SPI_CSDLY_CSA_8,             /*!< Delay 8 Clk Pull Up SPI_CS After Send Data */	
}SPICSA_TypeDef;  

/**
* @brief  SPI_CS Delay initialization structure definition
*/
typedef struct
{
	SPICSB_TypeDef	  SPI_CSB;	                /*!<Advance Pull down SPI_CS Before Send Data */
	SPICSA_TypeDef	  SPI_CSA;                  /*!<Delay Pull Up SPI_CS After Send Data */
	uint32_t          SPI_ITDelay;              /*!<DATA Send  Wait Time to DMA */
}SPI_CSDelayInitTypeDef;
#endif


#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
/**
* @brief SPI Callback pointer definition
*/
typedef  void (*pSPI_CallbackTypeDef)(SPI_InitTypeDef *SPI_InitStruct);  /*!< pointer to an SPI callback function */
#if defined  USE_SPI_FIFO  
typedef  void (*pSPIFIFO_CallbackTypeDef)(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);  /*!< pointer to an SPI FIFO callback function */
#endif

/**
* @brief  SPI Error Code
*/
#define SPI_ERROR_NONE              0x00000000U   /*!< No error */
#define SPI_ERROR_INVALID_CALLBACK  0x00000020U   /*!< Invalid Callback error */
#define SPI_ERROR_INVALID1_CALLBACK 0x00000040U   /*!< Invalid1 Callback error */
#endif

/*
*********************************************************************************************************
*                                         Global Variable
*********************************************************************************************************
*/
/**
* @brief HT_SPI_Exported_Constants
*/
#if defined  USE_SPI0
#define IS_HT_SPI_ALL_PERIPH(PERIPH)    ((PERIPH) == HT_SPI0)
#endif 

#if defined  USE_SPI01
#define IS_HT_SPI_ALL_PERIPH(PERIPH)   (((PERIPH) == HT_SPI0) || \
									    ((PERIPH) == HT_SPI1)) 	                                       
#endif 

#if defined  USE_SPI012
#define IS_HT_SPI_ALL_PERIPH(PERIPH)   (((PERIPH) == HT_SPI0) || \
                                        ((PERIPH) == HT_SPI1) || \
									    ((PERIPH) == HT_SPI2))
#endif 

#if defined  USE_SPI013
#define IS_HT_SPI_ALL_PERIPH(PERIPH)   (((PERIPH) == HT_SPI0) || \
										((PERIPH) == HT_SPI1) || \
										((PERIPH) == HT_SPI3))
#endif 


#if defined  USE_SPI0123
#define IS_HT_SPI_ALL_PERIPH(PERIPH)   (((PERIPH) == HT_SPI0) || \
                                        ((PERIPH) == HT_SPI1) || \
									    ((PERIPH) == HT_SPI2) || \
										((PERIPH) == HT_SPI3))
#endif 

/**
* @brief  HT_SPI_CSInCtrol
*/  
#define IS_HT_SPI_CSINCTROL(CSINCTROL) (((CSINCTROL) == ENABLE)|| \
										((CSINCTROL) == DISABLE))
#if defined  USE_SPI_ODDDIV										
/**
* @brief  HT_SPI_Baudrate
*/  
#define IS_HT_SPI_BAUDRATE(BAUDRATE)   (((BAUDRATE) ==  SPI_BaudRatePrescaler_2) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_4) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_8) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_16)|| \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_32)|| \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_64)|| \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_128)|| \
										((BAUDRATE) ==  SPI_CLK_None) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_3) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_5) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_6) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_7) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_9))
#else
#define IS_HT_SPI_BAUDRATE(BAUDRATE)   (((BAUDRATE) ==  SPI_BaudRatePrescaler_2) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_4) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_8) || \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_16)|| \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_32)|| \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_64)|| \
										((BAUDRATE) ==  SPI_BaudRatePrescaler_128)|| \
										((BAUDRATE) ==  SPI_CLK_None))
#endif
/**
* @brief  HT_SPI_CPHA
*/
#define IS_HT_SPI_CPHA(CPHA)          (((CPHA) == SPI_CPHA_1Edge) || \
									   ((CPHA) == SPI_CPHA_2Edge))	
/**
* @brief  HT_SPI_CPOL
*/									  
#define IS_HT_SPI_CPOL(CPOL) 	      (((CPOL) == SPI_CPOL_Low) || \
									   ((CPOL) == SPI_CPOL_high)) 								  
/**
* @brief  HT_SPI_MODE
*/	
#define IS_HT_SPI_MODE(MODE) 	      (((MODE) == SPI_Slave) || \
									   ((MODE) == SPI_Master))
#if  defined  USE_SPI_SPICON_FASTEN									   
/**
* @brief  HT_SPI_FASTEN
*/
#define IS_HT_SPI_FASTEN(FASTEN)     (((FASTEN) == SPI_SlowSlave) || \
									  ((FASTEN) == SPI_FastSlave))
#endif

#if  defined  USE_SPI_SPICON_LSBEN
/**
* @brief  HT_SPI_LSBEN
*/
#define IS_HT_SPI_LSBEN(LSBEN)     	 (((LSBEN) == SPI_MSB) || \
									  ((LSBEN) == SPI_LSB))
#endif

#if  defined  USE_SPI_SPICLK
/**
* @brief  HT_SPI_CLK
*/	
#define IS_HT_SPI_CLK(CLK)        	  (((CLK) == SPI_CLKSEL_OSC) || \
									   ((CLK) == SPI_CLKSEL_LRC) || \
									   ((CLK) == SPI_CLKSEL_HRC) || \
									   ((CLK) == SPI_CLKSEL_PLL44M)) 
#endif

/**
* @brief  HT_SPI_ITFlag 
*/	
#define IS_HT_SPI_ITFLAG(ITFLAG)     (((ITFLAG)==SPI_SPISTA_MODF)  || \
									  ((ITFLAG)==SPI_SPISTA_SSERR) || \
									  ((ITFLAG)==SPI_SPISTA_WCOL)  || \
									  ((ITFLAG)==SPI_SPISTA_SPIF) || \
                    ((((ITFLAG) & (uint32_t)(~SPI_SPISTA)) == 0x00) && ((ITFLAG) != 0x00)))	

#if defined  USE_SPI_SPISSN_MSAM
/**
* @brief  HT_SPI_MSAM 
*/	
#define IS_HT_SPI_MSAM(MSAM)         (((MSAM)==SPI_SPISSN_MSAM_0) || \
									  ((MSAM)==SPI_SPISSN_MSAM_1) || \
									  ((MSAM)==SPI_SPISSN_MSAM_2) || \
									  ((MSAM)==SPI_SPISSN_MSAM_3))
#endif

#if defined  USE_SPI_CSDLY
/**
* @brief  HT_SPI_CSB
*/	
#define IS_HT_SPI_CSB(CSB)           (((CSB)==SPI_CSDLY_CSB_0) || \
									  ((CSB)==SPI_CSDLY_CSB_2) || \
									  ((CSB)==SPI_CSDLY_CSB_4) || \
									  ((CSB)==SPI_CSDLY_CSB_8))
/**
* @brief  HT_SPI_CSA
*/	
#define IS_HT_SPI_CSA(CSA)           (((CSA)==SPI_CSDLY_CSA_0) || \
									  ((CSA)==SPI_CSDLY_CSA_2) || \
									  ((CSA)==SPI_CSDLY_CSA_4) || \
									  ((CSA)==SPI_CSDLY_CSA_8))
/**
* @brief  HT_SPI_ITDELAY
*/	
#define IS_HT_SPI_ITDELAY(ITDELAY)    ((ITDELAY)<=0x0f)                                  				
#endif

#if  defined  USE_SPI_FIFO
/**
* @brief  HT_SPI_FIFO_CTR
*/	
#define IS_HT_SPI_FIFO_CTR(CTR)     (((CTR) == FIFOCTR_1P5) || \
                                     ((CTR) == FIFOCTR_3P0) || \
                                     ((CTR) == FIFOCTR_4P5)) 									 
/**
* @brief  HT_SPI_FIFO_RXFIFOTL
*/	
#define IS_HT_SPI_FIFO_RXFIFOTL(RXFIFOTL)   (RXFIFOTL)<=((SPI_FIFOCON_RXFIFO_TL)>>16)

/**
* @brief  HT_SPI_FIFO_TXFIFOTL
*/	
#define IS_HT_SPI_FIFO_TXFIFOTL(TXFIFOTL)   (TXFIFOTL)<=((SPI_FIFOCON_TXFIFO_TL)>>8)

/**
* @brief  HT_SPI_FIFO_EXINSEL
*/
#define IS_HT_SPI_FIFO_EXINSEL(EXINSEL)     (((EXINSEL)== FIFO_EXINSEL_APB) || \
                                             ((EXINSEL)== FIFO_EXINSEL_EXIN))  
/**
* @brief  HT_SPI_FIFO_HLCS
*/
#define IS_HT_SPI_FIFO_HLCS(HLCS)   (((HLCS)== SPI_FIFOCON_HLCS_LOW) || \
                                     ((HLCS)== SPI_FIFOCON_HLCS_HIGH))											 
/**
* @brief  HT_SPI_FIFO_RXFIFORST
*/
#define IS_HT_SPI_FIFO_RXFIFORST(RXFIFORST)   (((RXFIFORST)==FIFO_RXFIFORST_0) || \
                                               ((RXFIFORST)==FIFO_RXFIFORST_1))													   																				 
/**
* @brief  HT_SPI_FIFO_TXFIFORST
*/
#define IS_HT_SPI_FIFO_TXFIFORST(TXFIFORST)   (((TXFIFORST)==FIFO_TXFIFORST_0) || \
                                               ((TXFIFORST)==FIFO_TXFIFORST_1))	
/**
* @brief  HT_SPI_FIFO_ITFLAG 
*/	
#define IS_HT_SPI_FIFO_ITEn(ITEn)          (((ITEn)==SPI_FIFOIE_TXE_IE)  || \
											((ITEn)==SPI_FIFOIE_RXNE_IE) || \
											((ITEn)==SPI_FIFOIE_TXF_IE)  || \
											((ITEn)==SPI_FIFOIE_RXF_IE)  || \
											((ITEn)==SPI_FIFOIE_TXO_IE)  || \
											((ITEn)==SPI_FIFOIE_RXO_IE)  || \
											((ITEn)==SPI_FIFOIE_TXT_IE)  || \
											((ITEn)==SPI_FIFOIE_RXT_IE)  || \
											((ITEn)==SPI_FIFOIE_TXFIFO_DONE_IE))
/**
* @brief  HT_SPI_FIFO_ITFLAG 
*/	
#define IS_HT_SPI_FIFO_ITFLAG(ITFLAG)      (((ITFLAG)==SPI_FIFOIF_TXE_IF)  || \
											((ITFLAG)==SPI_FIFOIF_RXNE_IF) || \
											((ITFLAG)==SPI_FIFOIF_TXF_IF)  || \
											((ITFLAG)==SPI_FIFOIF_RXF_IF)  || \
											((ITFLAG)==SPI_FIFOIF_TXO_IF)  || \
											((ITFLAG)==SPI_FIFOIF_RXO_IF)  || \
											((ITFLAG)==SPI_FIFOIF_TXT_IF)  || \
											((ITFLAG)==SPI_FIFOIF_RXT_IF)  || \
											((ITFLAG)==SPI_FIFOIF_TXFIFO_DONE_IF))											
/**
* @brief  HT_SPI_FIFO_BDLY
*/												
#define IS_HT_SPI_FIFO_BDLY(BDLY)	        ((BDLY)<=SPI_BDLY)					
#endif


/*
*********************************************************************************************************
*                                    Global Function Declaration
*********************************************************************************************************
*/
void HT_SPI_Init(HT_SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct);
ITStatus HT_SPI_ITFlagStatusGet(HT_SPI_TypeDef *SPIx, uint8_t ITFlag);
void HT_SPI_ClearITPendingBit(HT_SPI_TypeDef *SPIx, uint8_t ITFlag);
uint8_t HT_SPI_SendByte(HT_SPI_TypeDef *SPIx, uint16_t halfword);
void HT_SPI_CSHigh(HT_SPI_TypeDef *SPIx);
void HT_SPI_CSLow(HT_SPI_TypeDef *SPIx);

#if defined  USE_SPI_SPISSN_MSAM
void HT_SPI_SetMsam_Delay(HT_SPI_TypeDef *SPIx,uint32_t msam);
#endif

#if defined  USE_SPI_CSDLY
void HT_SPI_CSDelayInit(HT_SPI_TypeDef *SPIx, SPI_CSDelayInitTypeDef *SPI_CSDelayInitStruct);
#endif

#if  defined  USE_SPI_FIFO
void HT_SPI_FIFOInit(HT_SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct);
void HT_SPIFIFO_SETITConfig(HT_SPI_TypeDef *SPIx, uint32_t ITEn, FunctionalState NewState);
ITStatus HT_SPIFIFO_ITFlagStatusGet(HT_SPI_TypeDef *SPIx, uint32_t ITFlag);
void HT_SPIFIFO_ClearITPendingBit(HT_SPI_TypeDef *SPIx, uint32_t ITFlag);
void HT_SPIFIFO_SETByteDelay(HT_SPI_TypeDef *SPIx, uint32_t bdly);
#endif

#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
void HT_SPI_SPIModfCallback(SPI_InitTypeDef *SPI_InitStruct);
void HT_SPI_SPISpifCallback(SPI_InitTypeDef *SPI_InitStruct);
#if  defined  USE_SPI_FIFO
StatusTypeDef HT_SPI_RegisterCallback(SPI_InitTypeDef *SPI_InitStruct, SPI_CallbackIDTypeDef CallbackID, pSPI_CallbackTypeDef pCallback , pSPIFIFO_CallbackTypeDef pFIFOCallback );
#else
StatusTypeDef HT_SPI_RegisterCallback(SPI_InitTypeDef *SPI_InitStruct, SPI_CallbackIDTypeDef CallbackID, pSPI_CallbackTypeDef pCallback);
#endif

#if  defined  USE_SPI_FIFO
void HT_SPI_SPIFIFOTxeCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
void HT_SPI_SPIFIFORxneCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
void HT_SPI_SPIFIFOTxfCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
void HT_SPI_SPIFIFORxfCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
void HT_SPI_SPIFIFOTxoCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
void HT_SPI_SPIFIFORxoCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
void HT_SPI_SPIFIFOTxtCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
void HT_SPI_SPIFIFORxtCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
void HT_SPI_SPIFIFOTxdoneCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct);
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_SPI_H__ */
