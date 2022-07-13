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
* File         : ht6xxx_dma.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  : Only support for chips used DMA Function.
*********************************************************************************************************
*/

#define  __HT6XXX_DMA_C

#include "ht6xxx_lib.h"


#if defined  USE_DMA 	      

/*
*********************************************************************************************************
*                                    Local macro definition/struct
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                         Local variable
*********************************************************************************************************
*/

 
/*
*********************************************************************************************************
*                                      Local fun declaration
*********************************************************************************************************
*/


/**
*********************************************************************************************************                                        
*	@brief:  Init DMA module
* @param:  DMAy_Channelx  Pointer to a HT_DMA_Channel_TypeDef structure that contains
*												  that the configuration information for the specified DMA module.       
*         							  This parameter can be one of the following values:
*														@arg HT_DMA_Channel0) 								@arg HT_DMA_Channel6
*														@arg HT_DMA_Channel1									@arg HT_DMA_Channel7(If support)
*														@arg HT_DMA_Channel2(If support)		  @arg HT_DMA_Channel8
*														@arg HT_DMA_Channel3									@arg HT_DMA_Channel9	
*														@arg HT_DMA_Channel4									@arg HT_DMA_Channel10				
*														@arg HT_DMA_Channel5									@arg HT_DMA_Channel11(If support)										
* @param:  DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*													the following information for the specified DMA module.
*														@arg DMA_Request											@arg DMA_DestinationAddrInc
*														@arg DMA_SourceAddr										@arg DMA_MemoryDataSize 
*														@arg DMA_DestinationAddr							@arg DMA_TransferMode
*														@arg DMA_BulkSize											@arg DMA_CycleMode 
*														@arg DMA_SourceAddrInc                            			
* @retval: None
* @special: None 
*********************************************************************************************************
*/
void HT_DMA_Init(HT_DMA_Channel_TypeDef *DMAy_Channelx, DMA_InitTypeDef *DMA_InitStruct)
{
		uint32_t tempreg = 0U;

    /*  assert_param  */
		assert_param(IS_DMA_CHANNEL(DMAy_Channelx));	
		assert_param(IS_DMA_SourceAddrIncMode(DMA_InitStruct->DMA_SourceAddrInc));
		assert_param(IS_DMA_DestinationAddrInc(DMA_InitStruct->DMA_DestinationAddrInc));
		assert_param(IS_DMA_TransferMode(DMA_InitStruct->DMA_TransferMode));
		assert_param(IS_DMA_MemoryDataSize(DMA_InitStruct->DMA_MemoryDataSize));
		assert_param(IS_DMA_CycleMode(DMA_InitStruct->DMA_CycleMode));
		assert_param(IS_DMA_BulkSize(DMA_InitStruct->DMA_BulkSize));
		assert_param(IS_DMA_TransferNumber(DMA_InitStruct->DMA_TransferNum));

#if defined  USE_DMA_Priority		
		assert_param(IS_DMA_SourceDirection(DMA_InitStruct->DMA_SourceDirection));
		assert_param(IS_DMA_DestinationDirection(DMA_InitStruct->DMA_DestinationDirection));		
		assert_param(IS_DMA_PRIORITY(DMA_InitStruct->DMA_Priority));		
		/* Prepare the DMA Stream configuration */
    tempreg |= DMA_InitStruct->DMA_SourceAddrInc | DMA_InitStruct->DMA_DestinationAddrInc |\
               DMA_InitStruct->DMA_MemoryDataSize | DMA_InitStruct->DMA_TransferMode |\
               DMA_InitStruct->DMA_CycleMode | DMA_InitStruct->DMA_Request | DMA_InitStruct->DMA_Priority | \
							 DMA_InitStruct->DMA_DestinationDirection | DMA_InitStruct->DMA_SourceDirection;
#elif defined  USE_DMA_Direction
		assert_param(IS_DMA_SourceDirection(DMA_InitStruct->DMA_SourceDirection));
		assert_param(IS_DMA_DestinationDirection(DMA_InitStruct->DMA_DestinationDirection));	
		/* Prepare the DMA Stream configuration */
    tempreg |= DMA_InitStruct->DMA_SourceAddrInc | DMA_InitStruct->DMA_DestinationAddrInc |\
               DMA_InitStruct->DMA_MemoryDataSize | DMA_InitStruct->DMA_TransferMode |\
               DMA_InitStruct->DMA_CycleMode | DMA_InitStruct->DMA_Request |\
							 DMA_InitStruct->DMA_DestinationDirection | DMA_InitStruct->DMA_SourceDirection;	
							 
#else
				/* Prepare the DMA Stream configuration */
    tempreg |= DMA_InitStruct->DMA_SourceAddrInc | DMA_InitStruct->DMA_DestinationAddrInc |\
               DMA_InitStruct->DMA_MemoryDataSize | DMA_InitStruct->DMA_TransferMode |\
               DMA_InitStruct->DMA_CycleMode | DMA_InitStruct->DMA_Request ;
#endif

		/* Write to DMA CHNCTL register */
    DMAy_Channelx->CHNCTL = tempreg;
		
		/* Write to DMA CHNSRC register*/
    DMAy_Channelx->CHNSRC = DMA_InitStruct->DMA_SourceAddr;
		
		/* Write to DMA CHNTAR register*/
    DMAy_Channelx->CHNTAR = DMA_InitStruct->DMA_DestinationAddr;
		
		/* Write to DMA CHNCNT register*/
    DMAy_Channelx->CHNCNT = DMA_InitStruct->DMA_TransferNum;
		
		/* Write to DMA CHNBULKNUM register*/
    DMAy_Channelx->CHNBULKNUM =(DMA_InitStruct->DMA_CycleNumber<<8) | DMA_InitStruct->DMA_BulkSize;		
	
#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
		DMA_InitCallbacksToDefault(DMA_InitStruct);
		DMA_InitStruct->Instance = DMAy_Channelx;
#endif	
	
}

/**
*********************************************************************************************************                                
*	@brief:  Enable or disable DMA interrupt
* @param:   ITEn       DMA interrupt enable
*											 This parameter can be one or a combination of the following values:
*					                        @arg DMA_DMAIE_TCIE0 	@arg DMA_DMAIE_HTIE0 	@arg DMA_DMAIE_TEIE0
*					                        @arg DMA_DMAIE_TCIE1 	@arg DMA_DMAIE_HTIE1 	@arg DMA_DMAIE_TEIE1
*					                        @arg DMA_DMAIE_TCIE2 	@arg DMA_DMAIE_HTIE2 	@arg DMA_DMAIE_TEIE2	(If support)
*					                        @arg DMA_DMAIE_TCIE3 	@arg DMA_DMAIE_HTIE3 	@arg DMA_DMAIE_TEIE3
*					                        @arg DMA_DMAIE_TCIE4 	@arg DMA_DMAIE_HTIE4 	@arg DMA_DMAIE_TEIE4
*					                       	@arg DMA_DMAIE_TCIE5 	@arg DMA_DMAIE_HTIE5 	@arg DMA_DMAIE_TEIE5
*					                       	@arg DMA_DMAIE_TCIE6 	@arg DMA_DMAIE_HTIE6 	@arg DMA_DMAIE_TEIE6
*					                        @arg DMA_DMAIE_TCIE7 	@arg DMA_DMAIE_HTIE7 	@arg DMA_DMAIE_TEIE7	(If support)
*																	@arg DMA_DMAIE1_TCIE8 	@arg DMA_DMAIE1_HTIE8 	@arg DMA_DMAIE1_TEIE8
*																	@arg DMA_DMAIE1_TCIE9 	@arg DMA_DMAIE1_HTIE9 	@arg DMA_DMAIE1_TEIE9
*																	@arg DMA_DMAIE1_TCIE10  @arg DMA_DMAIE1_HTIE10  @arg DMA_DMAIE1_TEIE10
*																	@arg DMA_DMAIE1_TCIE11  @arg DMA_DMAIE1_HTIE11  @arg DMA_DMAIE1_TEIE11	(If support)
* @param:  	NewState	 Open or close the DMA interrupt enable
* 										 This parameter can be one of the following values:
* 												        @arg ENABLE 
*																	@arg DISABLE
* @param:  DMAy_Channelx  Pointer to a HT_DMA_Channel_TypeDef structure that contains
*												  that the configuration information for the specified DMA module.       
*         							  This parameter can be one of the following values:
*																	@arg HT_DMA_Channel0	 								@arg HT_DMA_Channel6
*																	@arg HT_DMA_Channel1									@arg HT_DMA_Channel7	(If support)
*																	@arg HT_DMA_Channel2	(If support)					@arg HT_DMA_Channel8
*																	@arg HT_DMA_Channel3									@arg HT_DMA_Channel9	
*																	@arg HT_DMA_Channel4									@arg HT_DMA_Channel10				
*																	@arg HT_DMA_Channel5									@arg HT_DMA_Channel11	(If support)	
* @retval:  None
* @special: None
*********************************************************************************************************
*/

#if defined USE_DMA_Channel11	
void HT_DMA_ITConfig(HT_DMA_Channel_TypeDef *DMAy_Channelx, uint32_t ITEn, FunctionalState NewState)
{
    /*  assert_param  */
		assert_param(IS_DMA_IE_BIT(ITEn));	
		assert_param(IS_DMA_CHANNEL(DMAy_Channelx));
	
		if(DMAy_Channelx==HT_DMA_Channel0||DMAy_Channelx==HT_DMA_Channel1||\
			DMAy_Channelx==HT_DMA_Channel2||DMAy_Channelx==HT_DMA_Channel3||\
				DMAy_Channelx==HT_DMA_Channel4||DMAy_Channelx==HT_DMA_Channel5||\
					DMAy_Channelx==HT_DMA_Channel6||DMAy_Channelx==HT_DMA_Channel7)
		{
				 if (NewState != DISABLE)
				{
						HT_DMA->DMAIE |= ITEn;            /*!< Enable DMA interrupt        */
				}
				else
				{
						HT_DMA->DMAIE &= ~ITEn;           /*!< Disable DMA interrupt       */
				}
		}
	
		if(DMAy_Channelx==HT_DMA_Channel8||DMAy_Channelx==HT_DMA_Channel9||\
				DMAy_Channelx==HT_DMA_Channel10||DMAy_Channelx==HT_DMA_Channel11)
		{
					if (NewState != DISABLE)
				{
						HT_DMA->DMAIE1 |= ITEn;            /*!< Enable DMA interrupt        */
				}
				else
				{
						HT_DMA->DMAIE1 &= ~ITEn;           /*!< Disable DMA interrupt       */
				}
		}		
	
}
#else
void HT_DMA_ITConfig(uint32_t ITEn, FunctionalState NewState)
{
    /* Check the parameters */
		assert_param(IS_DMA_IE_BIT(ITEn));	
		
		 if (NewState != DISABLE)
		{
				HT_DMA->DMAIE |= ITEn;            /*!< Enable DMA interrupt        */
		}
		else
		{
				HT_DMA->DMAIE &= ~ITEn;           /*!< Disable DMA interrupt       */
		}	
}
#endif	


/**
*********************************************************************************************************                         
*	@brief:    GET SPECIFIED DMA INTERRUPT FLAG STATUS
* @param:    ITFlag     DMA INTERRUPT FLAG, this parameter can be one or a combination of the following values:
*                        @arg DMA_DMAIF_TCIF0  @arg DMA_DMAIF_BCIF0  @arg DMA_DMAIF_TEIF0 
*                        @arg DMA_DMAIF_TCIF1  @arg DMA_DMAIF_BCIF1  @arg DMA_DMAIF_TEIF1 
*                        @arg DMA_DMAIF_TCIF2  @arg DMA_DMAIF_BCIF2  @arg DMA_DMAIF_TEIF2 	(If support)
*                        @arg DMA_DMAIF_TCIF3  @arg DMA_DMAIF_BCIF3  @arg DMA_DMAIF_TEIF3 
*                        @arg DMA_DMAIF_TCIF4  @arg DMA_DMAIF_BCIF4  @arg DMA_DMAIF_TEIF4 
*                        @arg DMA_DMAIF_TCIF5  @arg DMA_DMAIF_BCIF5  @arg DMA_DMAIF_TEIF5  
*                        @arg DMA_DMAIF_TCIF6  @arg DMA_DMAIF_BCIF6  @arg DMA_DMAIF_TEIF6 
*                        @arg DMA_DMAIF_TCIF7  @arg DMA_DMAIF_BCIF7  @arg DMA_DMAIF_TEIF7 	(If support)
*                        @arg DMA_DMAIF1_TCIF8  @arg DMA_DMAIF1_BCIF8  @arg DMA_DMAIF1_TEIF8 
*                        @arg DMA_DMAIF1_TCIF9  @arg DMA_DMAIF1_BCIF9  @arg DMA_DMAIF1_TEIF9  
*                        @arg DMA_DMAIF1_TCIF10 @arg DMA_DMAIF1_BCIF10 @arg DMA_DMAIF1_TEIF10 
*                        @arg DMA_DMAIF1_TCIF11 @arg DMA_DMAIF1_BCIF11 @arg DMA_DMAIF1_TEIF11 	(If support) 
* @retval:   ITStatus  
* @special:  None
*********************************************************************************************************
*/

#if defined USE_DMA_Channel11	
ITStatus HT_DMA_ITFlagStatusGet( HT_DMA_Channel_TypeDef *DMAy_Channelx, uint32_t ITFlag)
{
   	ITStatus ITFlag_tmp;
  /* Check the parameters */
		assert_param(IS_DMA_IT_FLAG(ITFlag));
		assert_param(IS_DMA_CHANNEL(DMAy_Channelx));
	
		if(DMAy_Channelx==HT_DMA_Channel0 || DMAy_Channelx==HT_DMA_Channel1||\
			DMAy_Channelx==HT_DMA_Channel2 || DMAy_Channelx==HT_DMA_Channel3||\
				DMAy_Channelx==HT_DMA_Channel4 || DMAy_Channelx==HT_DMA_Channel5||\
					DMAy_Channelx==HT_DMA_Channel6 || DMAy_Channelx==HT_DMA_Channel7)
		{
				if (HT_DMA->DMAIF & ITFlag)
				{
						ITFlag_tmp=SET;                        /*!< DMA Interrupt Flag is set   */
				}
				else
				{
						ITFlag_tmp=RESET;                      /*!< DMA Interrupt Flag is reset */
				}
		}
		else
		{
				if (HT_DMA->DMAIF1 & ITFlag)
				{
						ITFlag_tmp=SET;                        /*!< DMA Interrupt Flag is set   */
				}
				else
				{
						ITFlag_tmp=RESET;                      /*!< DMA Interrupt Flag is reset */
				}
		}
	        return ITFlag_tmp;
}
#else

ITStatus HT_DMA_ITFlagStatusGet(uint32_t ITFlag)
{
    	ITStatus ITFlag_tmp;
  /* Check the parameters */
		assert_param(IS_DMA_IT_FLAG(ITFlag));
	
		if (HT_DMA->DMAIF & ITFlag)
		{
				ITFlag_tmp=SET;                        /*!< DMA Interrupt Flag is set   */
		}
		else
		{
				ITFlag_tmp=RESET;                      /*!< DMA Interrupt Flag is reset */
		}
        return ITFlag_tmp;
}

#endif

/**
*********************************************************************************************************                                  
*	@brief:   Clear DMA interrupt flag
* @param:   ITFlag     DMA INTERRUPT FLAG, This parameter can be one or a combination of the following values:
*                        @arg DMA_DMAIF_TCIF0  @arg DMA_DMAIF_BCIF0  @arg DMA_DMAIF_TEIF0 
*                        @arg DMA_DMAIF_TCIF1  @arg DMA_DMAIF_BCIF1  @arg DMA_DMAIF_TEIF1 
*                        @arg DMA_DMAIF_TCIF2  @arg DMA_DMAIF_BCIF2  @arg DMA_DMAIF_TEIF2 	(If support)
*                        @arg DMA_DMAIF_TCIF3  @arg DMA_DMAIF_BCIF3  @arg DMA_DMAIF_TEIF3 
*                        @arg DMA_DMAIF_TCIF4  @arg DMA_DMAIF_BCIF4  @arg DMA_DMAIF_TEIF4 
*                        @arg DMA_DMAIF_TCIF5  @arg DMA_DMAIF_BCIF5  @arg DMA_DMAIF_TEIF5  
*                        @arg DMA_DMAIF_TCIF6  @arg DMA_DMAIF_BCIF6  @arg DMA_DMAIF_TEIF6 
*                        @arg DMA_DMAIF_TCIF7  @arg DMA_DMAIF_BCIF7  @arg DMA_DMAIF_TEIF7 	(If support)
*                        @arg DMA_DMAIF1_TCIF8  @arg DMA_DMAIF1_BCIF8  @arg DMA_DMAIF1_TEIF8 
*                        @arg DMA_DMAIF1_TCIF9  @arg DMA_DMAIF1_BCIF9  @arg DMA_DMAIF1_TEIF9  
*                        @arg DMA_DMAIF1_TCIF10 @arg DMA_DMAIF1_BCIF10 @arg DMA_DMAIF1_TEIF10 
*                        @arg DMA_DMAIF1_TCIF11 @arg DMA_DMAIF1_BCIF11 @arg DMA_DMAIF1_TEIF11 	(If support)      
* @retval:  None
* @special: None
*********************************************************************************************************
*/

#if defined USE_DMA_Channel11	
void HT_DMA_ClearITPendingBit(HT_DMA_Channel_TypeDef *DMAy_Channelx, uint32_t ITFlag)
{
    
	/* Check the parameters */
		assert_param(IS_DMA_IT_FLAG(ITFlag));
		assert_param(IS_DMA_CHANNEL(DMAy_Channelx));
	
		if(DMAy_Channelx==HT_DMA_Channel0||DMAy_Channelx==HT_DMA_Channel1||\
			DMAy_Channelx==HT_DMA_Channel2||DMAy_Channelx==HT_DMA_Channel3||\
				DMAy_Channelx==HT_DMA_Channel4||DMAy_Channelx==HT_DMA_Channel5||\
					DMAy_Channelx==HT_DMA_Channel6||DMAy_Channelx==HT_DMA_Channel7)
		{
			  HT_DMA->DMAIF   = ~(ITFlag);                  /*!< Clear DMA Interrupt Flag       */
		}
		
		if(DMAy_Channelx==HT_DMA_Channel8||DMAy_Channelx==HT_DMA_Channel9||\
				DMAy_Channelx==HT_DMA_Channel10||DMAy_Channelx==HT_DMA_Channel11)
		{
				HT_DMA->DMAIF1   = ~(ITFlag);                  /*!< Clear DMA Interrupt Flag       */
		}	
		
}
#else
void HT_DMA_ClearITPendingBit(uint32_t ITFlag)
{

	/* Check the parameters */
		assert_param(IS_DMA_IT_FLAG(ITFlag));

	/*!< Clear DMA Interrupt Flag       */
		HT_DMA->DMAIF   = ~(ITFlag);                  
}

#endif

/**
*********************************************************************************************************
*                                         Enable DMA MODULE
*
*	@brief:  	Starts the DMA Transfer.
* @param:  	DMAy_Channelx  Pointer to a HT_DMA_Channel_TypeDef structure  contains
*												   that the configuration information for the specified DMA module.       
*         							   This parameter can be one of the following values:
*																	@arg HT_DMA_Channel0 									@arg HT_DMA_Channel6
*																	@arg HT_DMA_Channel1									@arg HT_DMA_Channel7	(If support)
*																	@arg HT_DMA_Channel2	(If support)					@arg HT_DMA_Channel8
*																	@arg HT_DMA_Channel3									@arg HT_DMA_Channel9	
*																	@arg HT_DMA_Channel4									@arg HT_DMA_Channel10				
*																	@arg HT_DMA_Channel5									@arg HT_DMA_Channel11	(If support)		
* @param:  	NewState:			 Start or finish the DMA Transfer
* 												 This parameter can be one of the following values:
* 												          @arg ENABLE 
*																		@arg DISABLE
* @retval: 	None
* @special: None  
*********************************************************************************************************
*/
void HT_DMA_Cmd(HT_DMA_Channel_TypeDef *DMAy_Channelx, FunctionalState NewState)
{
  /*  assert_param  */
	assert_param(IS_DMA_CHANNEL(DMAy_Channelx));
	
	if (NewState != DISABLE)
  {
    DMAy_Channelx->CHNCTL |= DMA_Channel_Enable;         /*!< Enable the selected DMAy Channelx       */
  }
  else
  {
    DMAy_Channelx->CHNCTL &= DMA_Channel_Disable;        /*!< Disable the selected DMAy Channelx       */
  }

}

/**
*********************************************************************************************************
* @brief:   Init DMA channel only for FFT 
* @param:   DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*													the following information for the specified DMA module.
*                              		  @arg DMA_Request
*                              			@arg DMA_Priority
*                              			@arg DMA_FFTTRIG_EN
*                              			@arg DMA_SourceAddr
*                              			@arg DMA_DestinationAddr_0
*                              			@arg DMA_DestinationAddr_1
*                              			@arg DMA_DestinationAddr_2 
*                              			@arg DMA_DestinationAddr_3
*                              			@arg DMA_DestinationAddr_4  
*                              			@arg DMA_DestinationAddr_5
*                              			@arg DMA_DestinationAddr_6
*                              			@arg DMA_ChnNum  
*                              			@arg DMA_IntSize
*                              			@arg DMA_BufSize
* @retval:  None
* @special: None 
*********************************************************************************************************
*/

#if defined USE_DMA_Channel12
void HT_DMA_FFT_Init(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{

	uint32_t tempreg = 0U;
    /* Check the parameters */
		assert_param(IS_DMA_PRIORITY(DMA_InitStruct->DMA_Priority));
		assert_param(IS_DMA_Channel12_Request(DMA_InitStruct->DMA_Request));

		/* Prepare the DMA Stream configuration */
    tempreg |= DMA_InitStruct->DMA_Request | DMA_InitStruct->DMA_Priority | DMA_InitStruct->DMA_FFTTRIG_EN ;
		
		/* Write to DMA CHNCTL register */
		HT_DMA_Channel12->CHNCTL=tempreg;
		
		/* Write to DMA CHNSRC register*/
    HT_DMA_Channel12->CHNSRC = DMA_InitStruct->DMA_SourceAddr;
		
		/* Write to DMA CHNTAR register*/
    HT_DMA_Channel12->CHNTAR0 = DMA_InitStruct->DMA_DestinationAddr_0;
		HT_DMA_Channel12->CHNTAR1 = DMA_InitStruct->DMA_DestinationAddr_1;
		HT_DMA_Channel12->CHNTAR2 = DMA_InitStruct->DMA_DestinationAddr_2;
		HT_DMA_Channel12->CHNTAR3 = DMA_InitStruct->DMA_DestinationAddr_3;
		HT_DMA_Channel12->CHNTAR4 = DMA_InitStruct->DMA_DestinationAddr_4;
		HT_DMA_Channel12->CHNTAR5 = DMA_InitStruct->DMA_DestinationAddr_5;
		HT_DMA_Channel12->CHNTAR6 = DMA_InitStruct->DMA_DestinationAddr_6;	
			
		/* Prepare the DMA ChnSize configuration */
		tempreg = 0U;
		tempreg |= ((DMA_InitStruct->DMA_ChnNum<<28) | (DMA_InitStruct->DMA_IntSize<<16) | DMA_InitStruct->DMA_BufSize) ;
		
		/* Write to DMA CHNCNT register*/
    HT_DMA_Channel12->CHNSIZE = tempreg;
		
#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
		DMA_Ch12_InitCallbacksToDefault(DMA_InitStruct);
		DMA_InitStruct->Instance = HT_DMA_Channel12;
#endif	
}
#endif

/**
*********************************************************************************************************
* @brief:   Return DMA Channel12 data channel ID 
* @param:   None
* @retval:  EMU ADC data channel ID
* @special: None 
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
uint32_t HT_DMA_Channel12_Data_Ch_ID(void)
{
	uint32_t tempreg = 0U;
	tempreg=HT_DMA_Channel12->CHNIDX;
	return tempreg;

}
#endif

/**
*********************************************************************************************************
* @brief:   DMA Channel12 control disable
* @param:   None
* @retval:  None
* @special: None 
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
void HT_DMA_Channel12_Disable(void)
{
	HT_DMA_Channel12->CHNCLR&=~DMA_FFT_CHNCTL_CLR;
	
}
#endif

/**
*********************************************************************************************************
* @brief:   Return Cnt of DMA Channel12 Transfer Data 
* @retval:  DMA Channel12 transfer data cnt
* @special: None 
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
uint32_t HT_DMA_Channel12_Trans_Data_Cnt(void)
{
	uint32_t tempreg = 0U;
	tempreg=HT_DMA_Channel12->CHNINTCNT;
	
	return tempreg;
	
}
#endif

/**
*********************************************************************************************************
* @brief:   HT_DMA_Channel12_Pack_Cnt 
* @retval:  DMA Channel12 pack cnt
* @special: None 
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
uint32_t HT_DMA_Channel12_Pack_Cnt(void)
{
	uint32_t tempreg = 0U;
	tempreg=HT_DMA_Channel12->CHNPACKCNT;
	
	return tempreg;
	
}
#endif

/**
*********************************************************************************************************                                
*	@brief:  Enable or disable DMA channel12 interrupt
* @param:   ITEn       DMA interrupt enable
*											 This parameter can be one or a combination of the following values:
*																	@arg DMA_DMAIE2_PEIE12 @arg DMA_DMAIE2_BCIE12 @arg DMA_DMAIE2_TEIE12	(If support)	
* @param:  	NewState	 Open or close the DMA interrupt enable
* 										 This parameter can be one of the following values:
* 												        @arg ENABLE 
*																	@arg DISABLE
* @param:  DMAy_Channelx  Pointer to a HT_DMA_Channel_TypeDef structure that contains
*												  that the configuration information for the specified DMA module.       
*         							  This parameter can be one of the following values:
*																	@arg HT_DMA_Channel12(If support)	
* @retval:  None
* @special: None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
void HT_DMA_Channel12_ITConfig(uint32_t ITEn, FunctionalState NewState)
{
	  /* Check the parameters */
		assert_param(IS_DMA_CHANNEL12_IE_BIT(ITEn));	
	
	if (NewState != DISABLE)
		{
				HT_DMA->DMAIE2 |= ITEn;            /*!< Enable DMA interrupt        */
		}
		else
		{
				HT_DMA->DMAIE2 &= ~ITEn;           /*!< Disable DMA interrupt       */
		}
}
#endif

/**
*********************************************************************************************************                         
*	@brief:    GET SPECIFIED DMA CHANNEL12 INTERRUPT FLAG STATUS
* @param:    ITFlag     DMA INTERRUPT FLAG, this parameter can be one of the following values:
*                        @arg DMA_DMAIF_PEIF12 @arg DMA_DMAIF_BCIF12 @arg DMA_DMAIF_TEIF12	(If support) 
* @retval:   ITStatus  
* @special:  None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
ITStatus HT_DMA_Channel12_ITFlagStatusGet(uint32_t ITFlag)
{
		/* Check the parameters */
		assert_param(IS_DMA_CHANNEL12_IT_FLAG(ITFlag));
	
		if (HT_DMA->DMAIF2 & ITFlag)
		{
				return SET;                        /*!< DMA Interrupt Flag is set   */
		}
		else
		{
				return RESET;                      /*!< DMA Interrupt Flag is reset */
		}
}
#endif

/**
*********************************************************************************************************                                  
*	@brief:   Clear DMA channel12 interrupt flag
* @param:   ITFlag     DMA INTERRUPT FLAG, This parameter can be one or a combination of the following values:
*                        @arg DMA_DMAIF2_PEIF12 @arg DMA_DMAIF2_BCIF12 @arg DMA_DMAIF2_TEIF12	(If support)        
* @retval:  None
* @special: None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
void HT_DMA_Channel12_ClearITPendingBit(uint32_t ITFlag)
{
		/* Check the parameters */
		assert_param(IS_DMA_CHANNEL12_IT_FLAG(ITFlag));
	
		HT_DMA->DMAIF2 &= ~(ITFlag);                  /*!< Clear DMA Interrupt Flag       */
}	
#endif

/**
*********************************************************************************************************
*	@brief:  	Starts the DMA channel12 Transfer.
* @param:  	DMAy_Channelx  Pointer to a HT_DMA_Channel_TypeDef structure  contains
*												   that the configuration information for the specified DMA module.       
*         							   This parameter can be one of the following values:
*																		@arg HT_DMA_Channel12(If support)	
* @param:  	NewState:			 Start or finish the DMA Transfer
* 												 This parameter can be one of the following values:
* 												          @arg ENABLE 
*																		@arg DISABLE
* @retval: 	None
* @special: None 
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
void HT_DMA_Channel12_Cmd(FunctionalState NewState)
{
	if (NewState != DISABLE)
  {
    HT_DMA_Channel12->CHNCTL |= DMA_Channel_Enable;         /*!< Enable the selected DMAy Channelx       */
  }
  else
  {
    HT_DMA_Channel12->CHNCTL &= DMA_Channel_Disable;        /*!< Disable the selected DMAy Channelx       */
  }
}	
#endif

/**
*********************************************************************************************************
* @brief: To be used instead of the weak predefined callback.
* @param  DMA_InitStruct DMA Init TypeDef
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref DMA_TC_ID Tx Callback ID
*           @arg @ref DMA_BC_ID Bc Callback ID
*           @arg @ref DMA_TE_ID Te Callback ID
* @param  pCallback pointer to the Callback function
* @retval status
*********************************************************************************************************
*/
#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
StatusTypeDef HT_DMA_RegisterCallback(DMA_InitTypeDef *DMA_InitStruct, DMA_CallbackIDTypeDef CallbackID, pDMA_CallbackTypeDef pCallback)
{
  StatusTypeDef status = OK;
  if (pCallback == NULL)
  {
    /* Update the error code */
    DMA_InitStruct->ErrorCode |= DMA_ERROR_INVALID_CALLBACK;
    return ERROR;
  }
	switch (CallbackID)
	{
		case DMA_TC_ID :
			DMA_InitStruct->TcCallback = pCallback;
			break;
		case DMA_BC_ID :
			DMA_InitStruct->BcCallback = pCallback;
			break;
		case DMA_TE_ID :
			DMA_InitStruct->TeCallback = pCallback;
			break;		
		default :
			/* Update the error code */
			DMA_InitStruct->ErrorCode |= DMA_ERROR_INVALID_CALLBACK;
			/* Return error status */
			status =  ERROR;
			break;
	}
  return status;
}
/**
*********************************************************************************************************
* @brief: To be used instead of the weak predefined callback.
* @param  DMA_InitStruct DMA Channel12 InitTypeDef
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref DMA_CH12_PE_ID Pe Callback ID
*           @arg @ref DMA_CH12_BC_ID Bc Callback ID
*           @arg @ref DMA_CH12_TE_ID Te Callback ID
* @param  pCallback pointer to the Callback function
* @retval status
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
StatusTypeDef HT_DMA_Ch12_RegisterCallback(DMA_Channel12_InitTypeDef *DMA_InitStruct, DMA_CallbackIDTypeDef CallbackID, pDMA_Ch12_CallbackTypeDef pCallback)
{
  StatusTypeDef status = OK;
  if (pCallback == NULL)
  {
    /* Update the error code */
    DMA_InitStruct->ErrorCode |= DMA_ERROR_INVALID_CALLBACK;
    return ERROR;
  }
	switch (CallbackID)
	{
		case DMA_CH12_PE_ID :
			DMA_InitStruct->Ch12PeCallback = pCallback;
			break;
		case DMA_CH12_BC_ID :
			DMA_InitStruct->Ch12BcCallback = pCallback;
			break;
		case DMA_CH12_TE_ID :
			DMA_InitStruct->Ch12TeCallback = pCallback;
			break;		
		default :
			/* Update the error code */
			DMA_InitStruct->ErrorCode |= DMA_ERROR_INVALID_CALLBACK;
			/* Return error status */
			status =  ERROR;
			break;
	}
  return status;
}
#endif 
/**
*********************************************************************************************************
*                                         INITIAL DMA CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
* @param: DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.
* @retval:None
* @Note: None
*********************************************************************************************************
*/
static void DMA_InitCallbacksToDefault(DMA_InitTypeDef *DMA_InitStruct)
{
  /* Init the UART Callback settings */
  DMA_InitStruct->TcCallback = HT_DMA_TcCallback;            /* Legacy weak TcCallback            */
  DMA_InitStruct->BcCallback = HT_DMA_BcCallback;            /* Legacy weak BcCallback            */
  DMA_InitStruct->TeCallback = HT_DMA_TeCallback;            /* Legacy weak TeCallback            */
}

/**
*********************************************************************************************************
* @brief: Initialize the callbacks to their default values.
* @param: DMA_InitStruct Pointer to a DMA_Channel12_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.
* @retval:None
* @Note: None
*********************************************************************************************************
*/
#if defined  USE_DMA_Channel12	
static void DMA_Ch12_InitCallbacksToDefault(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{
  /* Init the UART Callback settings */
  DMA_InitStruct->Ch12PeCallback = HT_DMA_Ch12_PeCallback;    /* Legacy weak Ch12_PeCallback            */
  DMA_InitStruct->Ch12BcCallback = HT_DMA_Ch12_BcCallback;    /* Legacy weak Ch12_BcCallback            */
  DMA_InitStruct->Ch12TeCallback = HT_DMA_Ch12_TeCallback;    /* Legacy weak Ch12_TeCallback            */
  
}
#endif

/**
*********************************************************************************************************
* @brief:   Handles DMA interrupt request
* @param: 	DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.  
* @retval:  None
* @special: None 
*********************************************************************************************************
*/
void HT_DMA_IRQHandler(DMA_InitTypeDef *DMA_InitStruct)
{

	if(DMA_InitStruct->Instance==HT_DMA_Channel0)
	{
		/* DMA CH0 TC */
		if((HT_DMA->DMAIF & DMA_DMAIF_TCIF0)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);		
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel0, DMA_DMAIF_TCIF0);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF0);
#endif
		}		
	  /* DMA CH0 BC */
		if((HT_DMA->DMAIF&DMA_DMAIF_BCIF0)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel0, DMA_DMAIF_BCIF0);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF0);
#endif
		}	
		
	  /* DMA CH0 TE */	
		if((HT_DMA->DMAIF&DMA_DMAIF_TEIF0)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);		
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel0, DMA_DMAIF_TEIF0);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF0);
#endif			
		}
	}

		if(DMA_InitStruct->Instance==HT_DMA_Channel1)
	{
		/* DMA CH1 TC */
		if((HT_DMA->DMAIF & DMA_DMAIF_TCIF1)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);		
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel1, (uint32_t)DMA_DMAIF_TCIF1);
#else
			HT_DMA_ClearITPendingBit((uint32_t)DMA_DMAIF_TCIF1);
#endif	
		}
		
	  /* DMA CH1 BC */
		if((HT_DMA->DMAIF&DMA_DMAIF_BCIF1)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);		
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel1, (uint32_t)DMA_DMAIF_BCIF1);
#else
			HT_DMA_ClearITPendingBit((uint32_t)DMA_DMAIF_BCIF1);
#endif					
		}	
		
	  /* DMA CH1 TE */	
		if((HT_DMA->DMAIF&DMA_DMAIF_TEIF1)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);		
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel1, (uint32_t)DMA_DMAIF_TEIF1);
#else
			HT_DMA_ClearITPendingBit((uint32_t)DMA_DMAIF_TEIF1);
#endif
		}
	}

		if(DMA_InitStruct->Instance==HT_DMA_Channel2)
	{
		/* DMA CH2 TC */
		if((HT_DMA->DMAIF & DMA_DMAIF_TCIF2)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);		
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel2, DMA_DMAIF_TCIF2);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF2);
#endif
		}
		
	  /* DMA CH2 BC */
		if((HT_DMA->DMAIF&DMA_DMAIF_BCIF2)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel2, DMA_DMAIF_BCIF2);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF2);
#endif
		}	
		
	  /* DMA CH2 TE */	
		if((HT_DMA->DMAIF&DMA_DMAIF_TEIF2)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel2, DMA_DMAIF_TEIF2);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF2);
#endif
		}
	}

#if	defined USE_DMA_Channel7	||	defined USE_DMA_Channel11		

		if(DMA_InitStruct->Instance==HT_DMA_Channel3)
	{
		/* DMA CH3 TC */
		if((HT_DMA->DMAIF & DMA_DMAIF_TCIF3)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel3, DMA_DMAIF_TCIF3);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF3);
#endif
		}
		
	  /* DMA CH3 BC */
		if((HT_DMA->DMAIF&DMA_DMAIF_BCIF3)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel3, DMA_DMAIF_BCIF3);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF3);
#endif
		}	
		
	  /* DMA CH3 TE */	
		if((HT_DMA->DMAIF&DMA_DMAIF_TEIF3)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel3, DMA_DMAIF_TEIF3);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF3);
#endif
		}
	}		

		if(DMA_InitStruct->Instance==HT_DMA_Channel4)
	{
		/* DMA CH4 TC */
		if((HT_DMA->DMAIF & DMA_DMAIF_TCIF4)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel4, DMA_DMAIF_TCIF4);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF4);
#endif
		}
		
	  /* DMA CH4 BC */
		if((HT_DMA->DMAIF&DMA_DMAIF_BCIF4)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel4, DMA_DMAIF_BCIF4);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF4);
#endif
		}	
		
	  /* DMA CH4 TE */	
		if((HT_DMA->DMAIF&DMA_DMAIF_TEIF4)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel4, DMA_DMAIF_TEIF4);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF4);
#endif
		}
	}		

		if(DMA_InitStruct->Instance==HT_DMA_Channel5)
	{
		/* DMA CH5 TC */
		if((HT_DMA->DMAIF & DMA_DMAIF_TCIF5)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel5, DMA_DMAIF_TCIF5);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF5);
#endif	
			
		}
	  /* DMA CH5 BC */
		if((HT_DMA->DMAIF&DMA_DMAIF_BCIF5)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel5, DMA_DMAIF_BCIF5);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF5);
#endif	
		}	
		
	  /* DMA CH5 TE */	
		if((HT_DMA->DMAIF&DMA_DMAIF_TEIF5)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel5, DMA_DMAIF_TEIF5);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF5);
#endif			
		}
	}			

		if(DMA_InitStruct->Instance==HT_DMA_Channel6)
	{
		/* DMA CH6 TC */
		if((HT_DMA->DMAIF & DMA_DMAIF_TCIF6)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel6, DMA_DMAIF_TCIF6);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF6);
#endif			
		}
		
	  /* DMA CH6 BC */
		if((HT_DMA->DMAIF&DMA_DMAIF_BCIF6)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel6, DMA_DMAIF_BCIF6);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF6);
#endif		
		}	
		
	  /* DMA CH6 TE */	
		if((HT_DMA->DMAIF&DMA_DMAIF_TEIF6)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel6, DMA_DMAIF_TEIF6);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF6);
#endif	
		}
	}	

		if(DMA_InitStruct->Instance==HT_DMA_Channel7)
	{
		/* DMA CH7 TC */
		if((HT_DMA->DMAIF & DMA_DMAIF_TCIF7)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel7, DMA_DMAIF_TCIF7);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF7);
#endif	
		}
		
	  /* DMA CH7 BC */
		if((HT_DMA->DMAIF&DMA_DMAIF_BCIF7)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel7, DMA_DMAIF_BCIF7);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF7);
#endif			
		}	
		
	  /* DMA CH7 TE */	
		if((HT_DMA->DMAIF&DMA_DMAIF_TEIF7)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
#if defined USE_DMA_Channel11	
			HT_DMA_ClearITPendingBit(HT_DMA_Channel7, DMA_DMAIF_TEIF7);
#else
			HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF7);
#endif
		}	
	}	
#endif
	#if	defined USE_DMA_Channel11		
		if(DMA_InitStruct->Instance==HT_DMA_Channel8)
	{
		/* DMA CH8 TC */
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_TCIF8)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel8, DMA_DMAIF1_TCIF8);
		}
	  /* DMA CH8 BC */
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_BCIF8)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel8, DMA_DMAIF1_BCIF8);	
		}	
	  /* DMA CH8 TE */	
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_TEIF8)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel8, DMA_DMAIF1_TEIF8);
		}
	}

		if(DMA_InitStruct->Instance==HT_DMA_Channel9)
	{
		/* DMA CH9 TC */
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_TCIF9)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel9, DMA_DMAIF1_TCIF9);
		}
	  /* DMA CH9 BC */
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_BCIF9)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel9, DMA_DMAIF1_BCIF9);	
		}	
	  /* DMA CH9 TE */	
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_TEIF9)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel9, DMA_DMAIF1_TEIF9);
		}
	}

		if(DMA_InitStruct->Instance==HT_DMA_Channel10)
	{
		/* DMA CH10 TC */
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_TCIF10)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel10, DMA_DMAIF1_TCIF10);
		}
	  /* DMA CH10 BC */
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_BCIF10)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel10, DMA_DMAIF1_BCIF10);	
		}	
	  /* DMA CH10 TE */	
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_TEIF10)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel10, DMA_DMAIF1_TEIF10);
		}
	}

		if(DMA_InitStruct->Instance==HT_DMA_Channel11)
	{
		/* DMA CH11 TC */
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_TCIF11)!=0U)      
		{
			DMA_TC_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel11, DMA_DMAIF1_TCIF11);
		}
	  /* DMA CH11 BC */
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_BCIF11)!=0U)        
		{
			DMA_BC_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel11, DMA_DMAIF1_BCIF11);	
		}	
	  /* DMA CH11 TE */	
		if((HT_DMA->DMAIF1 & DMA_DMAIF1_TEIF11)!=0U)        
		{
			DMA_TE_IT(DMA_InitStruct);
			HT_DMA_ClearITPendingBit(HT_DMA_Channel11, DMA_DMAIF1_TEIF11);
		}
	}
#endif
}

/**
*********************************************************************************************************
* @brief:   Handles DMA Channel12 interrupt request
* @param: 	DMA_InitStruct Pointer to a DMA_Channel12_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.  
* @retval:  None
* @special: None 
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
void HT_DMA_CH12_IRQHandler(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{
	/* DMA CH12 PE */
		if((HT_DMA->DMAIF2 & DMA_DMAIF2_PEIF12)!=0U)      
		{
			 DMA_CH12_PE_IT(DMA_InitStruct);
			HT_DMA_Channel12_ClearITPendingBit(DMA_DMAIF2_PEIF12);
		}
	  /* DMA CH12 BC */
		if((HT_DMA->DMAIF2 & DMA_DMAIF2_BCIF12)!=0U)        
		{
			DMA_CH12_BC_IT(DMA_InitStruct);
			HT_DMA_Channel12_ClearITPendingBit(DMA_DMAIF2_BCIF12);
		}	
	  /* DMA CH12 TE */	
		if((HT_DMA->DMAIF2 & DMA_DMAIF2_TEIF12)!=0U)        
		{
			DMA_CH12_TE_IT(DMA_InitStruct);
			HT_DMA_Channel12_ClearITPendingBit(DMA_DMAIF2_TEIF12);
		}
}
#endif
/**
*********************************************************************************************************
* @brief: Receives an amount of data in non blocking mode
* @param: DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.
* @retval: None
* @Note: None
*********************************************************************************************************
*/
static void DMA_TC_IT(DMA_InitTypeDef *DMA_InitStruct)
{
	 /*Call registered TC callback*/
	 if(DMA_InitStruct->TcCallback !=NULL)
	 {
			DMA_InitStruct->TcCallback(DMA_InitStruct);
	 }
}

/**
*********************************************************************************************************
*                                         DMA BC IT HANDLER
*
* @brief: Receives an amount of data in non blocking mode
* @param: DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.
* @retval: None
* @Note: None
*********************************************************************************************************
*/
static void DMA_BC_IT(DMA_InitTypeDef *DMA_InitStruct)
{
	 /*Call registered BC callback*/
	 if(DMA_InitStruct->BcCallback != NULL)
	 {
			DMA_InitStruct->BcCallback(DMA_InitStruct);
	 }
}

/**
*********************************************************************************************************
*                                         DMA TE IT HANDLER
*
* @brief: Receives an amount of data in non blocking mode
* @param: DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.
* @retval: None
* @Note: None
*********************************************************************************************************
*/
static void DMA_TE_IT(DMA_InitTypeDef *DMA_InitStruct)
{
	 /*Call registered TE callback*/
	 if(DMA_InitStruct->TeCallback != NULL)
	 {
			DMA_InitStruct->TeCallback(DMA_InitStruct);
	 }
}
/**
*********************************************************************************************************
* @brief: DMA transfer completed callbacks.
* @param: DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*													the following information for the specified DMA module.
*														@arg DMA_Request											@arg DMA_DestinationAddrInc
*														@arg DMA_SourceAddr										@arg DMA_MemoryDataSize 
*														@arg DMA_DestinationAddr							@arg DMA_TransferMode
*														@arg DMA_BulkSize											@arg DMA_CycleMode 
*														@arg DMA_SourceAddrInc   
* @retval:None
* @Note:  None
*********************************************************************************************************
*/

__weak void HT_DMA_TcCallback(DMA_InitTypeDef *DMA_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(DMA_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_DMA_TcCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         DMA BC CALLBACK
*
* @brief: DMA bulk transfer completed callbacks.
* @param: DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*													the following information for the specified DMA module.
*														@arg DMA_Request											@arg DMA_DestinationAddrInc
*														@arg DMA_SourceAddr										@arg DMA_MemoryDataSize 
*														@arg DMA_DestinationAddr							@arg DMA_TransferMode
*														@arg DMA_BulkSize											@arg DMA_CycleMode 
*														@arg DMA_SourceAddrInc   
* @retval:None
* @Note:  None
*********************************************************************************************************
*/

__weak void HT_DMA_BcCallback(DMA_InitTypeDef *DMA_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(DMA_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_DMA_BcCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         DMA TE CALLBACK
*
* @brief: DMA transfer error callbacks.
* @param: DMA_InitStruct Pointer to a DMA_InitTypeDef structure that contains
*													the following information for the specified DMA module.
*														@arg DMA_Request											@arg DMA_DestinationAddrInc
*														@arg DMA_SourceAddr										@arg DMA_MemoryDataSize 
*														@arg DMA_DestinationAddr							@arg DMA_TransferMode
*														@arg DMA_BulkSize											@arg DMA_CycleMode 
*														@arg DMA_SourceAddrInc   
* @retval:None
* @Note:  None
*********************************************************************************************************
*/

__weak void HT_DMA_TeCallback(DMA_InitTypeDef *DMA_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(DMA_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_DMA_TeCallback could be implemented in the user file
   */
}
/**
*********************************************************************************************************
* @brief: Receives an amount of data in non blocking mode
* @param: DMA_InitStruct Pointer to a DMA_Channel12_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.
* @retval: None
* @Note: None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
static void DMA_CH12_PE_IT(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{
	 /*Call registered TC callback*/
	 if(DMA_InitStruct->Ch12PeCallback !=NULL)
	 {
			DMA_InitStruct->Ch12PeCallback(DMA_InitStruct);
	 }
}
#endif
/**
*********************************************************************************************************
* @brief: Receives an amount of data in non blocking mode
* @param: DMA_InitStruct Pointer to a DMA_Channel12_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.
* @retval: None
* @Note: None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
static void DMA_CH12_BC_IT(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{
	 /*Call registered BC callback*/
	 if(DMA_InitStruct->Ch12BcCallback != NULL)
	 {
			DMA_InitStruct->Ch12BcCallback(DMA_InitStruct);
	 }
}
#endif
/**
*********************************************************************************************************
* @brief: Receives an amount of data in non blocking mode
* @param: DMA_InitStruct Pointer to a DMA_Channel12_InitTypeDef structure that contains
*               the configuration information for the specified DMA module.
* @retval: None
* @Note: None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
static void DMA_CH12_TE_IT(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{
	 /*Call registered TE callback*/
	 if(DMA_InitStruct->Ch12TeCallback != NULL)
	 {
			DMA_InitStruct->Ch12TeCallback(DMA_InitStruct);
	 }
}
#endif

/**
*********************************************************************************************************
* @brief: DMA transfer completed callbacks.
* @param: DMA_InitStruct Pointer to a DMA_Channel12_InitTypeDef structure that contains
* @retval:None
* @Note:  None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
__weak void HT_DMA_Ch12_PeCallback(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(DMA_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_DMA_Ch12_PeCallback could be implemented in the user file
   */
}
#endif

/**
*********************************************************************************************************
* @brief: DMA transfer completed callbacks.
* @param: DMA_InitStruct Pointer to a DMA_Channel12_InitTypeDef structure that contains
* @retval:None
* @Note:  None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
__weak void HT_DMA_Ch12_BcCallback(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(DMA_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_DMA_Ch12_BcCallback could be implemented in the user file
   */
}
#endif

/**
*********************************************************************************************************
* @brief: DMA transfer completed callbacks.
* @param: DMA_InitStruct Pointer to a DMA_Channel12_InitTypeDef structure that contains
* @retval:None
* @Note:  None
*********************************************************************************************************
*/
#if defined USE_DMA_Channel12
__weak void HT_DMA_Ch12_TeCallback(DMA_Channel12_InitTypeDef *DMA_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(DMA_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_DMA_Ch12_TeCallback could be implemented in the user file
   */
}
#endif
#endif 
#endif                                      /* This File Only support for chips used DMA Function. */

