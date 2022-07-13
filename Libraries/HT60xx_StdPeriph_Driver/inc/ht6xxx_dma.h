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
* File         : ht6xxx_dma.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  : Only support for chips used DMA Function.
**********************************************************************************************************
*/

#ifndef __HT6XXX_DMA_H__
#define __HT6XXX_DMA_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "ht6xxx_lib.h"	
	
	
#if defined  USE_DMA 	         

/*
*********************************************************************************************************
*                                           Global macro definition/struct
*********************************************************************************************************
*/

/**
* @brief  DMA init structure definition
*/
typedef struct __DMA_InitTypeDef
{
  uint32_t DMA_Request;
  uint32_t DMA_SourceAddr;
  uint32_t DMA_DestinationAddr;
  uint32_t DMA_TransferNum;
  uint32_t DMA_BulkSize;
  uint32_t DMA_SourceAddrInc;
  uint32_t DMA_DestinationAddrInc;
  uint32_t DMA_MemoryDataSize;
  uint32_t DMA_TransferMode;
  uint32_t DMA_CycleMode;
  uint32_t DMA_CycleNumber;
#if defined  USE_DMA_Priority	
  uint32_t DMA_Priority;
  uint32_t DMA_DestinationDirection; 
  uint32_t DMA_SourceDirection;
#endif
#if defined  USE_DMA_Direction		
  uint32_t DMA_DestinationDirection; 
  uint32_t DMA_SourceDirection;
#endif

#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
	HT_DMA_Channel_TypeDef  *Instance;        						/*!<DMA registers base address        */
	__IO uint32_t    ErrorCode;        								/*!<DMA Error code                    */
	void (* TcCallback)(struct __DMA_InitTypeDef *DMA_InitStruct);	/*!<DMA Tc callback        */
	void (* BcCallback)(struct __DMA_InitTypeDef *DMA_InitStruct);	/*!<DMA Bc callback        */
	void (* TeCallback)(struct __DMA_InitTypeDef *DMA_InitStruct);	/*!<DMA Te callback        */
#endif 

}DMA_InitTypeDef;                                /*!< end of group TMR_InitTypeDef   */


/**
* @brief  DMA channel12 init structure definition
*/
#if defined  USE_DMA_Channel12
typedef struct __DMA_Channel12_InitTypeDef
{
	
	uint32_t DMA_Request;
	uint32_t DMA_Priority;
	uint32_t DMA_FFTTRIG_EN;
	uint32_t DMA_SourceAddr;
	uint32_t DMA_DestinationAddr_0;
	uint32_t DMA_DestinationAddr_1;
	uint32_t DMA_DestinationAddr_2;
	uint32_t DMA_DestinationAddr_3;	
	uint32_t DMA_DestinationAddr_4;
	uint32_t DMA_DestinationAddr_5;	
	uint32_t DMA_DestinationAddr_6;
	uint32_t DMA_ChnNum;
	uint32_t DMA_IntSize;
	uint32_t DMA_BufSize;	
	
#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
	HT_FFTDMA_Channel_TypeDef  *Instance;        										/*!<DMA registers base address        */
	__IO uint32_t    ErrorCode;        															/*!<DMA Error code                    */
	void (* Ch12PeCallback)(struct __DMA_Channel12_InitTypeDef *DMA_InitStruct);	/*!<DMA Pe callback        */
	void (* Ch12BcCallback)(struct __DMA_Channel12_InitTypeDef *DMA_InitStruct);	/*!<DMA Bc callback        */
	void (* Ch12TeCallback)(struct __DMA_Channel12_InitTypeDef *DMA_InitStruct);	/*!<DMA Te callback        */
#endif	
}DMA_Channel12_InitTypeDef;                                /*!< end of group TMR_InitTypeDef   */
#endif


/**
* @brief  DMA Callback ID enumeration definition
*/
#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
typedef enum
{
  DMA_TC_ID             = 0x01U,    	 /*!< DMA Tc  Complete Callback ID             */
  DMA_BC_ID             = 0x03U,    	 /*!< DMA Bc	Complete Callback ID             */
  DMA_TE_ID             = 0x05U,    	 /*!< DMA Te  Complete Callback ID             */	
#if defined  USE_DMA_Channel12	
  DMA_CH12_PE_ID        = 0x07U,    	 /*!< DMA CH12 Pe  Complete Callback ID        */
  DMA_CH12_BC_ID        = 0x09U,    	 /*!< DMA CH12 Bc	 Complete Callback ID        */
  DMA_CH12_TE_ID        = 0x0BU,    	 /*!< DMA CH12 Te  Complete Callback ID        */		
#endif
	
} DMA_CallbackIDTypeDef;

/**
* @brief  DMA Callback pointer definition
*/
typedef  void (*pDMA_CallbackTypeDef)(DMA_InitTypeDef *DMA_InitStruct);  /*!< pointer to an DMA callback function */

/**
* @brief  DMA CH12 Callback pointer definition
*/
#if defined  USE_DMA_Channel12
typedef  void (*pDMA_Ch12_CallbackTypeDef)(DMA_Channel12_InitTypeDef *DMA_InitStruct);  /*!< pointer to an DMA CH12 callback function */
#endif

/**
* @brief  DMA Error Code
*/
#define DMA_ERROR_NONE              0x00000000U   /*!< No error            */
#define DMA_ERROR_INVALID_CALLBACK  0x00000020U   /*!< Invalid Callback error  */
#endif

/**
* @brief  DMA_SourceAddrInc  DMA source address incremented mode
*/
#define DMA_SourceAddrInc_NoIncrease                ((uint32_t)0x00000000)
#define DMA_SourceAddrInc_AutoIncrease              ((uint32_t)0x00000020)
#define DMA_SourceAddrInc_BulkInternalIncrease      ((uint32_t)0x00000040)
#define DMA_SourceAddrInc_BulkIncrease    				  ((uint32_t)0x00000060)

/**
* @brief  DMA_DestinationAddrInc DMA destination address incremented mode
*/
#define DMA_DestinationAddrInc_NoIncrease           ((uint32_t)0x00000000)
#define DMA_DestinationAddrInc_AutoIncrease         ((uint32_t)0x00000080)
#define DMA_DestinationAddrInc_BulkInternalIncrease ((uint32_t)0x00000100)
#define DMA_DestinationAddrInc_BulkIncrease 			  ((uint32_t)0x00000180)

#if defined  USE_DMA_Priority	
/** 
* @brief  DMA_DestinationDirection DMA destination direction
*/
#define DMA_DestinationDirection_Decrease           ((uint32_t)0x00800000)
#define DMA_DestinationDirection_Increase           ((uint32_t)0x00000000)

/** 
* @brief  DMA_SourceDirection DMA source direction
*/
#define DMA_SourceDirection_Decrease                ((uint32_t)0x00400000)
#define DMA_SourceDirection_Increase                ((uint32_t)0x00000000)

/**
* @brief  DMA_Priority DMA channel priority
*/
#define DMA_LowPriority                             ((uint32_t)0x00000000)
#define DMA_MiddlePriority                          ((uint32_t)0x00010000)
#define DMA_HighPriority                            ((uint32_t)0x00020000)
#define DMA_TopHighPriority                         ((uint32_t)0x00030000)
#endif

#if defined  USE_DMA_Direction	
/** 
* @brief  DMA_DestinationDirection DMA destination direction
*/
#define DMA_DestinationDirection_Decrease           ((uint32_t)0x00800000)
#define DMA_DestinationDirection_Increase           ((uint32_t)0x00000000)

/** 
* @brief  DMA_SourceDirection DMA source direction
*/
#define DMA_SourceDirection_Decrease                ((uint32_t)0x00400000)
#define DMA_SourceDirection_Increase                ((uint32_t)0x00000000)
#endif

/**
* @brief  DMA_TransferMode DMA transfer mode
*/
#define DMA_TransferMode_SingleTransfer             ((uint32_t)0x00000000)
#define DMA_TransferMode_BulkTransfer               ((uint32_t)0x00000008)

/**
* @brief  DMA_CycleMode DMA cycle mode
*/
#define DMA_CycleMode_NoCycleTransfer               ((uint32_t)0x00000000)
#define DMA_CycleMode_CycleTransfer                 ((uint32_t)0x00000010)

/**
* @brief  DMA_MemoryDataSize DMA Memory data size
*/
#define DMA_MemoryDataSize_Byte                     ((uint32_t)0x00000000)
#define DMA_MemoryDataSize_HalfWord                 ((uint32_t)0x00000002)
#define DMA_MemoryDataSize_Word                     ((uint32_t)0x00000004)

/**
* @brief  DMA_Channel_En DMA channel enable
*/
#define DMA_Channel_Enable                          ((uint32_t)0x00000001U)
#define DMA_Channel_Disable                         ((uint32_t)0xFFFFFFFEU)

/**
* @brief  DMA_FFTTRIG_EN  DMA FFT computing trig enable
*/
#if defined  USE_DMA_Channel12
#define DMA_FFTTrig_Enable                          ((uint32_t)0x00000002)
#define DMA_FFTTrig_Disable                         ((uint32_t)0x00000000)
#endif


/**
* @brief  DMA_FFT_CHNCTL_CLR  DMA FFT CHNCTL CLEAR
*/
#if defined  USE_DMA_Channel12
#define DMA_FFT_CHNCTL_CLR                         ((uint32_t)0x00000001)

#endif


#if defined  USE_DMA_Channel12
#define IS_DMA_CHANNEL(CHANNEL) (((CHANNEL) == HT_DMA_Channel0) || \
                                 ((CHANNEL) == HT_DMA_Channel1) || \
                                 ((CHANNEL) == HT_DMA_Channel2) || \
                                 ((CHANNEL) == HT_DMA_Channel3) || \
                                 ((CHANNEL) == HT_DMA_Channel4) || \
                                 ((CHANNEL) == HT_DMA_Channel5) || \
                                 ((CHANNEL) == HT_DMA_Channel6) || \
                                 ((CHANNEL) == HT_DMA_Channel7) || \
								 ((CHANNEL) == HT_DMA_Channel8) || \
                                 ((CHANNEL) == HT_DMA_Channel9) || \
                                 ((CHANNEL) == HT_DMA_Channel10) || \
                                 ((CHANNEL) == HT_DMA_Channel11) )
																 
#define IS_DMA_CHANNEL12(CHANNEL) (((CHANNEL) == HT_DMA_Channel12))																 
																 																									 
#elif defined  USE_DMA_Channel7		
#define IS_DMA_CHANNEL(CHANNEL) (((CHANNEL) == HT_DMA_Channel0) || \
                                 ((CHANNEL) == HT_DMA_Channel1) || \
                                 ((CHANNEL) == HT_DMA_Channel2) || \
                                 ((CHANNEL) == HT_DMA_Channel3) || \
                                 ((CHANNEL) == HT_DMA_Channel4) || \
                                 ((CHANNEL) == HT_DMA_Channel5) || \
                                 ((CHANNEL) == HT_DMA_Channel6) || \
                                 ((CHANNEL) == HT_DMA_Channel7))
#else
#define IS_DMA_CHANNEL(CHANNEL) (((CHANNEL) == HT_DMA_Channel0) || \
                                 ((CHANNEL) == HT_DMA_Channel1) || \
                                 ((CHANNEL) == HT_DMA_Channel2))
#endif	

#define IS_DMA_Channel12_Request(REQ) ((REQ) == (0x3f<<9))													 
																 
																

#define IS_DMA_SourceAddrIncMode(MODE) (((MODE) == DMA_SourceAddrInc_NoIncrease )			|| \
																			  ((MODE) == DMA_SourceAddrInc_AutoIncrease )		|| \
																				((MODE) == DMA_SourceAddrInc_BulkIncrease )		|| \
																			  ((MODE) == DMA_SourceAddrInc_BulkInternalIncrease ))
																	 
#define IS_DMA_DestinationAddrInc(MODE) (((MODE) == DMA_DestinationAddrInc_NoIncrease )			|| \
																			   ((MODE) == DMA_DestinationAddrInc_AutoIncrease )		|| \
																				 ((MODE) == DMA_DestinationAddrInc_BulkIncrease )		|| \
																         ((MODE) == DMA_DestinationAddrInc_BulkInternalIncrease ))																	 

#if defined  USE_DMA_Priority
#define IS_DMA_SourceDirection(DIRECTION) (((DIRECTION) == DMA_SourceDirection_Decrease )		|| \
																					 ((DIRECTION) == DMA_SourceDirection_Increase ))

#define IS_DMA_DestinationDirection(DIRECTION) (((DIRECTION) == DMA_DestinationDirection_Decrease )	|| \
																						    ((DIRECTION) == DMA_SourceDirection_Increase ))

#define IS_DMA_PRIORITY(PRIORITY) (((PRIORITY) == DMA_LowPriority )			|| \
																	 ((PRIORITY) == DMA_MiddlePriority )	|| \
																	 ((PRIORITY) == DMA_HighPriority )		|| \
																	 ((PRIORITY) == DMA_TopHighPriority ))
#endif																		 
	
#if defined  USE_DMA_Direction
#define IS_DMA_SourceDirection(DIRECTION) (((DIRECTION) == DMA_SourceDirection_Decrease )		|| \
																					 ((DIRECTION) == DMA_SourceDirection_Increase ))

#define IS_DMA_DestinationDirection(DIRECTION) (((DIRECTION) == DMA_DestinationDirection_Decrease )	|| \
																						    ((DIRECTION) == DMA_SourceDirection_Increase ))
#endif		

#define IS_DMA_TransferMode(MODE) (((MODE) == DMA_TransferMode_SingleTransfer )	|| \
																   ((MODE) == DMA_TransferMode_BulkTransfer ))

#define IS_DMA_MemoryDataSize(SIZE) (((SIZE) == DMA_MemoryDataSize_Byte )			  || \
																		 ((SIZE) == DMA_MemoryDataSize_HalfWord )		|| \
																		 ((SIZE) == DMA_MemoryDataSize_Word ))

#define IS_DMA_CycleMode(MODE) (((MODE) == DMA_CycleMode_NoCycleTransfer )			|| \
																((MODE) == DMA_CycleMode_CycleTransfer ))

#define IS_DMA_BulkSize(SIZE)		((SIZE) <= 0xFF)

#define IS_DMA_CycleNumber(NUMBER)((NUMBER) <= 0xFF)

#define IS_DMA_TransferNumber(NUMBER)(((NUMBER) > 0x0000) && ((NUMBER) <= 0xFFFF))


#if defined  USE_DMA_Channel12
#define IS_DMA_IT_FLAG(FLAG)                                (((FLAG) == DMA_DMAIF_TCIF0 )	|| ((FLAG) == DMA_DMAIF_TCIF1 )	|| ((FLAG) == DMA_DMAIF_TCIF2 )	|| ((FLAG) == DMA_DMAIF_TCIF3 )||\
															((FLAG) == DMA_DMAIF_TCIF4 )	|| ((FLAG) == DMA_DMAIF_TCIF5 )	|| ((FLAG) == DMA_DMAIF_TCIF6 )	|| ((FLAG) == DMA_DMAIF_TCIF7 )||\
															((FLAG) == DMA_DMAIF_BCIF0 )	|| ((FLAG) == DMA_DMAIF_BCIF1 )	|| ((FLAG) == DMA_DMAIF_BCIF2 )	|| ((FLAG) == DMA_DMAIF_BCIF3 )||\
															((FLAG) == DMA_DMAIF_BCIF4 )	|| ((FLAG) == DMA_DMAIF_BCIF5 )	|| ((FLAG) == DMA_DMAIF_BCIF6 )	|| ((FLAG) == DMA_DMAIF_BCIF7 )||\
															((FLAG) == DMA_DMAIF_TEIF0 )	|| ((FLAG) == DMA_DMAIF_TEIF1 )	|| ((FLAG) == DMA_DMAIF_TEIF2 )	|| ((FLAG) == DMA_DMAIF_TEIF3 )||\
															((FLAG) == DMA_DMAIF_TEIF4 )	|| ((FLAG) == DMA_DMAIF_TEIF5 )	|| ((FLAG) == DMA_DMAIF_TEIF6 )	|| ((FLAG) == DMA_DMAIF_TEIF7 )||\
															((FLAG) == DMA_DMAIF1_TCIF8 )	|| ((FLAG) == DMA_DMAIF1_BCIF8 )	|| ((FLAG) == DMA_DMAIF1_TEIF8 )||\
															((FLAG) == DMA_DMAIF1_TCIF9 )	|| ((FLAG) == DMA_DMAIF1_BCIF9 )	|| ((FLAG) == DMA_DMAIF1_TEIF9 )||\
															((FLAG) == DMA_DMAIF1_TCIF10 )	|| ((FLAG) == DMA_DMAIF1_BCIF10 )	|| ((FLAG) == DMA_DMAIF1_TEIF10 )||\
															((FLAG) == DMA_DMAIF1_TCIF11 )	|| ((FLAG) == DMA_DMAIF1_BCIF11 )	|| ((FLAG) == DMA_DMAIF1_TEIF11 )|| \
                                                            ((((FLAG) & (uint32_t)(~DMA_DMAIF)) == 0x00) && ((FLAG) != 0x00)))
															
#define IS_DMA_CHANNEL12_IT_FLAG(FLAG)                      (((FLAG) == DMA_DMAIF2_PEIF12 )	|| ((FLAG) == DMA_DMAIF2_BCIF12 )	|| ((FLAG) == DMA_DMAIF2_TEIF12 )	)
#elif  defined  USE_DMA_Channel7	
#define IS_DMA_IT_FLAG(FLAG)                                (((FLAG) == DMA_DMAIF_TCIF0 )	|| ((FLAG) == DMA_DMAIF_TCIF1 )	|| ((FLAG) == DMA_DMAIF_TCIF2 )	|| ((FLAG) == DMA_DMAIF_TCIF3 )||\
															((FLAG) == DMA_DMAIF_TCIF4 )	|| ((FLAG) == DMA_DMAIF_TCIF5 )	|| ((FLAG) == DMA_DMAIF_TCIF6 )	|| ((FLAG) == DMA_DMAIF_TCIF7 )||\
															((FLAG) == DMA_DMAIF_BCIF0 )	|| ((FLAG) == DMA_DMAIF_BCIF1 )	|| ((FLAG) == DMA_DMAIF_BCIF2 )	|| ((FLAG) == DMA_DMAIF_BCIF3 )||\
															((FLAG) == DMA_DMAIF_BCIF4 )	|| ((FLAG) == DMA_DMAIF_BCIF5 )	|| ((FLAG) == DMA_DMAIF_BCIF6 )	|| ((FLAG) == DMA_DMAIF_BCIF7 )||\
															((FLAG) == DMA_DMAIF_TEIF0 )	|| ((FLAG) == DMA_DMAIF_TEIF1 )	|| ((FLAG) == DMA_DMAIF_TEIF2 )	|| ((FLAG) == DMA_DMAIF_TEIF3 )||\
															((FLAG) == DMA_DMAIF_TEIF4 )	|| ((FLAG) == DMA_DMAIF_TEIF5 )	|| ((FLAG) == DMA_DMAIF_TEIF6 )	|| ((FLAG) == DMA_DMAIF_TEIF7 )|| \
                                                            ((((FLAG) & (uint32_t)(~DMA_DMAIF)) == 0x00) && ((FLAG) != 0x00)))
#else	
#define IS_DMA_IT_FLAG(FLAG)                                (((FLAG) == DMA_DMAIF_TCIF0 )	|| ((FLAG) == DMA_DMAIF_TCIF1 )	|| ((FLAG) == DMA_DMAIF_TCIF2 )	||\
															((FLAG) == DMA_DMAIF_BCIF0 )	|| ((FLAG) == DMA_DMAIF_BCIF1 )	|| ((FLAG) == DMA_DMAIF_BCIF2 )	||\
															((FLAG) == DMA_DMAIF_TEIF0 )	|| ((FLAG) == DMA_DMAIF_TEIF1 )	|| ((FLAG) == DMA_DMAIF_TEIF2 )	|| \
                                                            ((((FLAG) & (uint32_t)(~DMA_DMAIF)) == 0x00) && ((FLAG) != 0x00)))
#endif	



#if defined  USE_DMA_Channel12
#define IS_DMA_IE_BIT(BIT)                                  (((BIT) == DMA_DMAIE_TCIE0 )	|| ((BIT) == DMA_DMAIE_BCIE0 )	|| ((BIT) == DMA_DMAIE_TEIE0 )||\
															((BIT) == DMA_DMAIE_TCIE1 )	|| ((BIT) == DMA_DMAIE_BCIE1 )	|| ((BIT) == DMA_DMAIE_TEIE1 )||\
															((BIT) == DMA_DMAIE_TCIE2 )	|| ((BIT) == DMA_DMAIE_BCIE2 )	|| ((BIT) == DMA_DMAIE_TEIE2 )||\
															((BIT) == DMA_DMAIE_TCIE3 )	|| ((BIT) == DMA_DMAIE_BCIE3 )	|| ((BIT) == DMA_DMAIE_TEIE3 )||\
															((BIT) == DMA_DMAIE_TCIE4 )	|| ((BIT) == DMA_DMAIE_BCIE4 )	|| ((BIT) == DMA_DMAIE_TEIE4 )||\
															((BIT) == DMA_DMAIE_TCIE5 )	|| ((BIT) == DMA_DMAIE_BCIE5 )	|| ((BIT) == DMA_DMAIE_TEIE5 )||\
															((BIT) == DMA_DMAIE_TCIE6 )	|| ((BIT) == DMA_DMAIE_BCIE6 )	|| ((BIT) == DMA_DMAIE_TEIE6 )||\
															((BIT) == DMA_DMAIE_TCIE7 )	|| ((BIT) == DMA_DMAIE_BCIE7 )	|| ((BIT) == DMA_DMAIE_TEIE7 )||\
															((BIT) == DMA_DMAIE1_TCIE8 )	|| ((BIT) == DMA_DMAIE1_BCIE8 )	|| ((BIT) == DMA_DMAIE1_TEIE8 )||\
															((BIT) == DMA_DMAIE1_TCIE9 )	|| ((BIT) == DMA_DMAIE1_BCIE9 )	|| ((BIT) == DMA_DMAIE1_TEIE9 )||\
															((BIT) == DMA_DMAIE1_TCIE10 )	|| ((BIT) == DMA_DMAIE1_BCIE10 )|| ((BIT) == DMA_DMAIE1_TEIE10 )||\
															((BIT) == DMA_DMAIE1_TCIE11 )	|| ((BIT) == DMA_DMAIE1_BCIE11 )|| ((BIT) == DMA_DMAIE1_TEIE11 )||\
															((((BIT) & (uint32_t)(~DMA_DMAIE)) == 0x00) && ((BIT) != 0x00))||\
															((((BIT) & (uint32_t)(~DMA_DMAIE1)) == 0x00) && ((BIT) != 0x00)))															

#define IS_DMA_CHANNEL12_IE_BIT(BIT)                        (((BIT) == DMA_DMAIE2_PEIE12 )	|| ((BIT) == DMA_DMAIE2_BCIE12 ) || ((BIT) == DMA_DMAIF2_TEIF12 )||\
															((((BIT) & (uint32_t)(~DMA_DMAIE2)) == 0x00) && ((BIT) != 0x00)))
#elif  defined  USE_DMA_Channel7	
#define IS_DMA_IE_BIT(BIT)                                  (((BIT) == DMA_DMAIE_TCIE0 )	|| ((BIT) == DMA_DMAIE_BCIE0 )	|| ((BIT) == DMA_DMAIE_TEIE0 )||\
															((BIT) == DMA_DMAIE_TCIE1 )	|| ((BIT) == DMA_DMAIE_BCIE1 )	|| ((BIT) == DMA_DMAIE_TEIE1 )||\
															((BIT) == DMA_DMAIE_TCIE2 )	|| ((BIT) == DMA_DMAIE_BCIE2 )	|| ((BIT) == DMA_DMAIE_TEIE2 )||\
															((BIT) == DMA_DMAIE_TCIE3 )	|| ((BIT) == DMA_DMAIE_BCIE3 )	|| ((BIT) ==DMA_DMAIE_TEIE3 )||\
															((BIT) == DMA_DMAIE_TCIE4 )	|| ((BIT) == DMA_DMAIE_BCIE4 )	|| ((BIT) ==DMA_DMAIE_TEIE4 )||\
															((BIT) == DMA_DMAIE_TCIE5 )	|| ((BIT) == DMA_DMAIE_BCIE5 )	|| ((BIT) ==DMA_DMAIE_TEIE5 )||\
															((BIT) == DMA_DMAIE_TCIE6 )	|| ((BIT) == DMA_DMAIE_BCIE6 )	|| ((BIT) ==DMA_DMAIE_TEIE6 )||\
															((BIT) == DMA_DMAIE_TCIE7 )	|| ((BIT) == DMA_DMAIE_BCIE7 )	|| ((BIT) ==DMA_DMAIE_TEIE7 )||\
															((((BIT) & (uint32_t)(~DMA_DMAIE)) == 0x00) && ((BIT) != 0x00)))
															
#else		
#define IS_DMA_IE_BIT(BIT)                                  (((BIT) == DMA_DMAIE_TCIE0 )|| ((BIT) == DMA_DMAIE_BCIE0 )	|| ((BIT) == DMA_DMAIE_TEIE0 )||\
															((BIT) == DMA_DMAIE_TCIE1 )	|| ((BIT) == DMA_DMAIE_BCIE1 )	|| ((BIT) == DMA_DMAIE_TEIE1 )||\
															((BIT) == DMA_DMAIE_TCIE2 )	|| ((BIT) == DMA_DMAIE_BCIE2 )	|| ((BIT) == DMA_DMAIE_TEIE2 )||\
															((((BIT) & (uint32_t)(~DMA_DMAIE)) == 0x00) && ((BIT) != 0x00)))
#endif



/**
* @brief  DMA_Request
*/
#if defined USE_DMA_TRIG0 
#define DMA_Request_Software                         ((uint32_t)0x00000000 << 9)
#define DMA_Request_UART0_TX                         ((uint32_t)0x00000001 << 9)
#define DMA_Request_UART0_RX                         ((uint32_t)0x00000002 << 9)
#define DMA_Request_UART1_TX                         ((uint32_t)0x00000003 << 9)
#define DMA_Request_UART1_RX                         ((uint32_t)0x00000004 << 9)
#define DMA_Request_UART2_TX                         ((uint32_t)0x00000005 << 9)
#define DMA_Request_UART2_RX                         ((uint32_t)0x00000006 << 9)
#define DMA_Request_UART3_TX                         ((uint32_t)0x00000007 << 9)
#define DMA_Request_UART3_RX                         ((uint32_t)0x00000008 << 9)
#define DMA_Request_UART4_TX                         ((uint32_t)0x00000009 << 9)
#define DMA_Request_UART4_RX                         ((uint32_t)0x0000000A << 9)
#define DMA_Request_UART5_TX                         ((uint32_t)0x0000000B << 9)
#define DMA_Request_UART5_RX                         ((uint32_t)0x0000000C << 9)
#define DMA_Request_ISO7816_0_TX                     ((uint32_t)0x0000000D << 9)
#define DMA_Request_ISO7816_0_RX                     ((uint32_t)0x0000000E << 9)
#define DMA_Request_ISO7816_1_TX                     ((uint32_t)0x0000000F << 9)
#define DMA_Request_ISO7816_1_RX                     ((uint32_t)0x00000010 << 9)
#endif


#if defined USE_DMA_TRIG1 
#define DMA_Request_SPI_TX                           ((uint32_t)0x00000011 << 9)
#define DMA_Request_SPI_RX                           ((uint32_t)0x00000012 << 9)
#define DMA_Request_I2C_TX                           ((uint32_t)0x00000013 << 9)
#define DMA_Request_I2C_RX                           ((uint32_t)0x00000014 << 9)
#define DMA_Request_EMU_UWave                        ((uint32_t)0x00000015 << 9)
#define DMA_Request_EMU_I1Wave                       ((uint32_t)0x00000016 << 9)
#define DMA_Request_EMU_I2Wave                       ((uint32_t)0x00000017 << 9)
#define DMA_Request_TIMER0                           ((uint32_t)0x00000018 << 9)
#define DMA_Request_TIMER1                           ((uint32_t)0x00000019 << 9)
#define DMA_Request_TIMER2                           ((uint32_t)0x0000001A << 9)
#define DMA_Request_TIMER3                           ((uint32_t)0x0000001B << 9)
#define DMA_Request_TIMER4                           ((uint32_t)0x0000001C << 9)
#define DMA_Request_TIMER5                           ((uint32_t)0x0000001D << 9)
#define DMA_Request_UART6_TX                         ((uint32_t)0x0000001E << 9)
#define DMA_Request_UART6_RX                         ((uint32_t)0x0000001F << 9)
#define DMA_Request_SPI1_TX                          ((uint32_t)0x00000020 << 9)
#define DMA_Request_SPI1_RX                          ((uint32_t)0x00000021 << 9)
#endif

#if defined  USE_DMA_TRIG2  
#define DMA_Request_SPI0_TX                          ((uint32_t)0x00000011 << 9)
#define DMA_Request_SPI0_RX                          ((uint32_t)0x00000012 << 9)
#define DMA_Request_I2C_TX                           ((uint32_t)0x00000013 << 9)
#define DMA_Request_I2C_RX                           ((uint32_t)0x00000014 << 9)
#define DMA_Request_EMU_U_SPL                        ((uint32_t)0x00000015 << 9)
#define DMA_Request_EMU_I1_SPL                       ((uint32_t)0x00000016 << 9)
#define DMA_Request_EMU_I2_SPL                       ((uint32_t)0x00000017 << 9)
#define DMA_Request_TIMER0                           ((uint32_t)0x00000018 << 9)
#define DMA_Request_TIMER1                           ((uint32_t)0x00000019 << 9)
#define DMA_Request_TIMER2                           ((uint32_t)0x0000001A << 9)
#define DMA_Request_TIMER3                           ((uint32_t)0x0000001B << 9)
#define DMA_Request_UART6_TX                         ((uint32_t)0x0000001E << 9)
#define DMA_Request_UART6_RX                         ((uint32_t)0x0000001F << 9)
#define DMA_Request_SPI1_TX                          ((uint32_t)0x00000020 << 9)
#define DMA_Request_SPI1_RX                          ((uint32_t)0x00000021 << 9)
#define DMA_Request_SPI2_TX                          ((uint32_t)0x00000022 << 9)
#define DMA_Request_SPI2_RX                          ((uint32_t)0x00000023 << 9)
#define DMA_Request_ADC0                             ((uint32_t)0x00000026 << 9)
#define DMA_Request_ADC1                             ((uint32_t)0x00000027 << 9)
#define DMA_Request_ADC2                         	   ((uint32_t)0x00000028 << 9)
#define DMA_Request_ADC3                             ((uint32_t)0x00000029 << 9)
#define DMA_Request_ADC4                             ((uint32_t)0x0000002A << 9)
#define DMA_Request_ADC5                             ((uint32_t)0x0000002B << 9)
#define DMA_Request_ADC6                             ((uint32_t)0x0000002C << 9)
#define DMA_Request_EMU_ADCSYSNC_U                   ((uint32_t)0x00000034 << 9)
#define DMA_Request_EMU_ADCSYSNC_I                   ((uint32_t)0x00000035 << 9)
#define DMA_Request_EMU_U_HALFWAVE_RMS               ((uint32_t)0x00000037 << 9)
#define DMA_Request_EMU_I_HALFWAVE_RMS               ((uint32_t)0x00000038 << 9)
#define DMA_Request_EMU_U_FLICKER                    ((uint32_t)0x0000003B << 9)
#define DMA_Request_EMU_INTERFACE                    ((uint32_t)0x0000003E << 9)
#endif


#if defined  USE_DMA_TRIG3
#define DMA_Request_SPI0_TX                          ((uint32_t)0x00000011 << 9)
#define DMA_Request_SPI0_RX                          ((uint32_t)0x00000012 << 9)
#define DMA_Request_I2C_TX                           ((uint32_t)0x00000013 << 9)
#define DMA_Request_I2C_RX                           ((uint32_t)0x00000014 << 9)
#define DMA_Request_EMU_U_SPL                        ((uint32_t)0x00000015 << 9)
#define DMA_Request_EMU_I1_SPL                       ((uint32_t)0x00000016 << 9)
#define DMA_Request_EMU_I2_SPL                       ((uint32_t)0x00000017 << 9)
#define DMA_Request_TIMER0                           ((uint32_t)0x00000018 << 9)
#define DMA_Request_TIMER1                           ((uint32_t)0x00000019 << 9)
#define DMA_Request_TIMER2                           ((uint32_t)0x0000001A << 9)
#define DMA_Request_TIMER3                           ((uint32_t)0x0000001B << 9)
#define DMA_Request_TIMER4                           ((uint32_t)0x0000001C << 9)
#define DMA_Request_TIMER5                           ((uint32_t)0x0000001D << 9)
#define DMA_Request_UART6_TX                         ((uint32_t)0x0000001E << 9)
#define DMA_Request_UART6_RX                         ((uint32_t)0x0000001F << 9)
#define DMA_Request_SPI1_TX                          ((uint32_t)0x00000020 << 9)
#define DMA_Request_SPI1_RX                          ((uint32_t)0x00000021 << 9)
#define DMA_Request_SPI2_TX                          ((uint32_t)0x00000022 << 9)
#define DMA_Request_SPI2_RX                          ((uint32_t)0x00000023 << 9)
#define DMA_Request_ADC0                             ((uint32_t)0x00000026 << 9)
#define DMA_Request_ADC1                             ((uint32_t)0x00000027 << 9)
#define DMA_Request_ADC3                             ((uint32_t)0x00000029 << 9)
#define DMA_Request_ADC4                             ((uint32_t)0x0000002A << 9)
#define DMA_Request_ADC5                             ((uint32_t)0x0000002B << 9)
#define DMA_Request_SPI3_TX                          ((uint32_t)0x00000032 << 9)
#define DMA_Request_SPI3_RX                          ((uint32_t)0x00000033 << 9)
#define DMA_Request_EMU_Ua_SPL                   	 ((uint32_t)0x00000034 << 9)
#define DMA_Request_EMU_Ub_SPL                   	 ((uint32_t)0x00000035 << 9)
#define DMA_Request_EMU_Uc_SPL                   	 ((uint32_t)0x00000036 << 9)
#define DMA_Request_EMU_Ia_SPL                   	 ((uint32_t)0x00000037 << 9)
#define DMA_Request_EMU_Ib_SPL                   	 ((uint32_t)0x00000038 << 9)
#define DMA_Request_EMU_Ic_SPL                   	 ((uint32_t)0x00000039 << 9)
#define DMA_Request_EMU_In_SPL                   	 ((uint32_t)0x0000003A << 9)
#define DMA_Request_EMU_Ua_FLICKER                   ((uint32_t)0x0000003B << 9)
#define DMA_Request_EMU_Ub_FLICKER                   ((uint32_t)0x0000003C << 9)
#define DMA_Request_EMU_Uc_FLICKER                   ((uint32_t)0x0000003D << 9)
#define DMA_Request_EMU_INTERFACE_NoInvasion         ((uint32_t)0x0000003E << 9)
#define DMA_Request_EMU_INTERFACE_FFT                ((uint32_t)0x0000003F << 9)
#endif	

#if defined  USE_DMA_TRIG4
#define DMA_Request_SPI0_TX                          ((uint32_t)0x00000011 << 9)
#define DMA_Request_SPI0_RX                          ((uint32_t)0x00000012 << 9)
#define DMA_Request_I2C_TX                           ((uint32_t)0x00000013 << 9)
#define DMA_Request_I2C_RX                           ((uint32_t)0x00000014 << 9)
#define DMA_Request_TIMER0                           ((uint32_t)0x00000018 << 9)
#define DMA_Request_TIMER1                           ((uint32_t)0x00000019 << 9)
#define DMA_Request_TIMER2                           ((uint32_t)0x0000001A << 9)
#define DMA_Request_TIMER3                           ((uint32_t)0x0000001B << 9)
#define DMA_Request_TIMER4                           ((uint32_t)0x0000001C << 9)
#define DMA_Request_TIMER5                           ((uint32_t)0x0000001D << 9)
#define DMA_Request_UART6_TX                         ((uint32_t)0x0000001E << 9)
#define DMA_Request_UART6_RX                         ((uint32_t)0x0000001F << 9)
#define DMA_Request_SPI1_TX                          ((uint32_t)0x00000020 << 9)
#define DMA_Request_SPI1_RX                          ((uint32_t)0x00000021 << 9)
#define DMA_Request_SPI2_TX                          ((uint32_t)0x00000022 << 9)
#define DMA_Request_SPI2_RX                          ((uint32_t)0x00000023 << 9)
#define DMA_Request_LPUART_TX                        ((uint32_t)0x00000024 << 9)
#define DMA_Request_LPUART_RX                        ((uint32_t)0x00000025 << 9)
#define DMA_Request_ADC0                             ((uint32_t)0x00000026 << 9)
#define DMA_Request_ADC1                             ((uint32_t)0x00000027 << 9)
#define DMA_Request_VBAT                             ((uint32_t)0x00000028 << 9)
#define DMA_Request_ADC3                             ((uint32_t)0x00000029 << 9)
#define DMA_Request_ADC4                             ((uint32_t)0x0000002A << 9)
#define DMA_Request_ADC5                             ((uint32_t)0x0000002B << 9)
#define DMA_Request_ADC6                             ((uint32_t)0x0000002C << 9)
#define DMA_Request_ADC7                             ((uint32_t)0x0000002D << 9)
#define DMA_Request_ADC8                             ((uint32_t)0x0000002E << 9)
#define DMA_Request_TMP                              ((uint32_t)0x0000002F << 9)
#define DMA_Request_VCC                              ((uint32_t)0x00000030 << 9)
#define DMA_Request_ADC9                             ((uint32_t)0x00000031 << 9)
#define DMA_Request_SPI3_TX                          ((uint32_t)0x00000032 << 9)
#define DMA_Request_SPI3_RX                          ((uint32_t)0x00000033 << 9)

#endif	


/*
*********************************************************************************************************
*                                             Global variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global fun declaration
*********************************************************************************************************
*/

void HT_DMA_Init(HT_DMA_Channel_TypeDef *DMAy_Channelx, DMA_InitTypeDef *DMA_InitStruct);
void HT_DMA_Cmd(HT_DMA_Channel_TypeDef *DMAy_Channelx, FunctionalState NewState);
#if defined USE_DMA_Channel11	
void HT_DMA_ITConfig(HT_DMA_Channel_TypeDef *DMAy_Channelx, uint32_t ITEn, FunctionalState NewState);
#else
void HT_DMA_ITConfig(uint32_t ITEn, FunctionalState NewState);
#endif

#if defined USE_DMA_Channel11
ITStatus HT_DMA_ITFlagStatusGet(HT_DMA_Channel_TypeDef *DMAy_Channelx, uint32_t ITFlag);
#else
ITStatus HT_DMA_ITFlagStatusGet(uint32_t ITFlag);
#endif

#if defined USE_DMA_Channel11
void HT_DMA_ClearITPendingBit(HT_DMA_Channel_TypeDef *DMAy_Channelx, uint32_t ITFlag );
#else
void HT_DMA_ClearITPendingBit(uint32_t ITFlag);
#endif

#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
void HT_DMA_IRQHandler(DMA_InitTypeDef *DMA_InitStruct);
void HT_DMA_TcCallback(DMA_InitTypeDef *DMA_InitStruct);
void HT_DMA_BcCallback(DMA_InitTypeDef *DMA_InitStruct);
void HT_DMA_TeCallback(DMA_InitTypeDef *DMA_InitStruct);
static void DMA_TC_IT(DMA_InitTypeDef *DMA_InitStruct);
static void DMA_BC_IT(DMA_InitTypeDef *DMA_InitStruct);
static void DMA_TE_IT(DMA_InitTypeDef *DMA_InitStruct);
static void DMA_InitCallbacksToDefault(DMA_InitTypeDef *DMA_InitStruct);
StatusTypeDef HT_DMA_RegisterCallback(DMA_InitTypeDef *DMA_InitStruct, DMA_CallbackIDTypeDef CallbackID, pDMA_CallbackTypeDef pCallback);
#endif /* USE_HT_DMA_CALLBACKS */
#if defined USE_DMA_Channel12
void HT_DMA_Channel12_ITConfig(uint32_t ITEn, FunctionalState NewState);
void HT_DMA_FFT_Init(DMA_Channel12_InitTypeDef *DMA_InitStruct);
void HT_DMA_Channel12_Cmd(FunctionalState NewState);
void HT_DMA_Channel12_ClearITPendingBit(uint32_t ITFlag);
ITStatus HT_DMA_Channel12_ITFlagStatusGet(uint32_t ITFlag);
void HT_DMA_Channel12_Disable(void);
uint32_t HT_DMA_Channel12_Data_Ch_ID(void);
uint32_t HT_DMA_Channel12_Trans_Data_Cnt(void);
uint32_t HT_DMA_Channel12_Pack_Cnt(void);

#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
void HT_DMA_CH12_IRQHandler(DMA_Channel12_InitTypeDef *DMA_InitStruct);
void HT_DMA_Ch12_PeCallback(DMA_Channel12_InitTypeDef *DMA_InitStruct);
void HT_DMA_Ch12_BcCallback(DMA_Channel12_InitTypeDef *DMA_InitStruct);
void HT_DMA_Ch12_TeCallback(DMA_Channel12_InitTypeDef *DMA_InitStruct);
static void DMA_CH12_PE_IT(DMA_Channel12_InitTypeDef *DMA_InitStruct);
static void DMA_CH12_BC_IT(DMA_Channel12_InitTypeDef *DMA_InitStruct);
static void DMA_CH12_TE_IT(DMA_Channel12_InitTypeDef *DMA_InitStruct);
static void DMA_Ch12_InitCallbacksToDefault(DMA_Channel12_InitTypeDef *DMA_InitStruct);
StatusTypeDef HT_DMA_Ch12_RegisterCallback(DMA_Channel12_InitTypeDef *DMA_InitStruct, DMA_CallbackIDTypeDef CallbackID, pDMA_Ch12_CallbackTypeDef pCallback);
#endif
#endif

#endif                                      /* This File Only support HT6x2x, HT6x3x, HT501x and HT502x */

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_DMA_H__ */

