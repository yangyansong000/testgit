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
* File         : dma_example.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#include "ht6xxx_lib.h"
#include "dma_example.h"

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

#if defined  USE_DMA 	 
#if (USE_HT_DMA_REGISTER_CALLBACKS == 1)
extern	DMA_InitTypeDef DmaHandle;
#if defined  USE_DMA_Channel12	
extern	DMA_Channel12_InitTypeDef DmaCh12Handle;
#endif
#endif

/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/

#if (USE_HT_DMA_REGISTER_CALLBACKS == 1)
/* DMA IRQHandler declared in "ht50xx_dma.c" file */
	extern void HT_DMA_IRQHandler(DMA_InitTypeDef *DMA_InitStruct);
#endif

/**
*********************************************************************************************************
*			   							DMA0 UWAVE TO RAM INIT
*
* @brief: U wave data of SPLU(address: 0x40013008) sent to ram by DMA0 
*          step1: configure DMA transfer parameters
*              2: call HT_DMA_Init(), write to DMA registers
* @param: num  uint32_t, transfer data bulk number   
* @param: DestinData  uint32_t, destination address in ram
* @retval:None 
*********************************************************************************************************
*/
void Dma0_Uwave_to_Ram_Init(uint32_t num, uint32_t *DestinData)
{
		/*User add application code here*/
#if (USE_HT_DMA_REGISTER_CALLBACKS == 1)
	
		DmaHandle.DMA_Request = DMA_Request_Software; 
    DmaHandle.DMA_BulkSize = 3;	
    DmaHandle.DMA_TransferNum = num;
    DmaHandle.DMA_TransferMode = DMA_TransferMode_SingleTransfer;
    DmaHandle.DMA_CycleMode = DMA_CycleMode_NoCycleTransfer;
    DmaHandle.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
		DmaHandle.DMA_CycleNumber = 0;

    DmaHandle.DMA_SourceAddr = 0x40013008; 
    DmaHandle.DMA_SourceAddrInc = DMA_SourceAddrInc_NoIncrease;
    DmaHandle.DMA_DestinationAddr = (uint32_t)DestinData;			
    DmaHandle.DMA_DestinationAddrInc = DMA_DestinationAddrInc_AutoIncrease;
    HT_DMA_Init(HT_DMA_Channel0, &DmaHandle);	
	
	#else	
    DMA_InitTypeDef DMA_InitStructure;
	
#if defined USE_DMA_TRIG1 
    DMA_InitStructure.DMA_Request = DMA_Request_EMU_UWave; 
#elif defined USE_DMA_TRIG2	
    DMA_InitStructure.DMA_Request = DMA_Request_EMU_U_SPL; 	
#elif defined USE_DMA_TRIG3		
    DMA_InitStructure.DMA_Request = DMA_Request_EMU_Ua_SPL; 	
#endif
    DMA_InitStructure.DMA_BulkSize = 3;	/* SPLU has 3bytes */
    DMA_InitStructure.DMA_TransferNum = num;
    DMA_InitStructure.DMA_TransferMode = DMA_TransferMode_SingleTransfer;
    DMA_InitStructure.DMA_CycleMode = DMA_CycleMode_NoCycleTransfer;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;

    DMA_InitStructure.DMA_SourceAddr = 0x40013008; /* EMUEPA_SPLU address */
    DMA_InitStructure.DMA_SourceAddrInc = DMA_SourceAddrInc_NoIncrease;
    DMA_InitStructure.DMA_DestinationAddr = (uint32_t)DestinData;			
    DMA_InitStructure.DMA_DestinationAddrInc = DMA_DestinationAddrInc_AutoIncrease;
    HT_DMA_Init(HT_DMA_Channel0, &DMA_InitStructure);	
#endif

}


#endif

