/*
*********************************************************************************************************
*                                          HT60XX
*                                       HT60XX program
*
*                             Copyright 2021, Hi-Trend Tech, Corp.
*                                    All Rights Reserved
*
*
* Project      : HT60xx
* File         : ht60xx_it.c
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
*********************************************************************************************************
*/

#define  __HT60XX_IT_C

#include "ht_include.h"

/*
*********************************************************************************************************
*                                            Local Macro/Structure
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            Local Variables
*********************************************************************************************************
*/


#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)

/* UART handler declared in "main.c" file */
extern UART_InitTypeDef UartHandle;
extern ISO7816_InitTypeDef ISO7816Handle;
extern IR_InitTypeDef IRHandle;

#endif

#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)

/* SPI handler declared in "main.c" file */
extern SPI_InitTypeDef SpiHandle;

#endif

#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)

/* RTC handler declared in "main.c" file */
extern RTC_InitTypeDef RtcHandle;

#endif

#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)

/* PMU handler declared in "main.c" file */
extern PMU_InitTypeDef PmuHandle;

#endif

#if (USE_HT_TBS_REGISTER_CALLBACKS == 1U)

/* TBS handler declared in "main.c" file */
extern TBS_InitTypeDef TBSHandle;

#endif

#if (USE_HT_WDT_REGISTER_CALLBACKS == 1U)

/* WDT handler declared in "main.c" file */
extern WDT_InitTypeDef WdtHandle;

#endif

#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

/* TMR handler declared in "main.c" file */
extern TMR_InitTypeDef TimHandle;

	#if defined USE_TMR_EXT

	extern TMRExt_InitTypeDef TimExtHandle;

	#endif

#endif

#if( USE_HT_SYSTICK_REGISTER_CALLBACKS ==1)

/* SysTick handler declared in "main.c" file */
extern SysTick_InitTypeDef SysTickHandle;

#endif

#if( USE_HT_EXTI_REGISTER_CALLBACKS ==1U)

/* EXTI handler declared in "main.c" file */
extern EXTI_TypeDef ExtiHandle;
#endif

#if defined  USE_EMU
	#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
		/* EMU handler declared in "main.c" file */
		extern EMU_InitTypeDef EmuHandle;
	
		#if defined HT762x || defined HT772x
		extern EWU_InitTypeDef EwuHandle;
		#endif
		
	#endif
#endif

#if defined  USE_DMA

	#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
	
		/* DMA handler declared in "main.c" file */
		extern DMA_InitTypeDef DmaHandle;
		
		#if defined  USE_DMA_Channel12	
		
			/* DMA Channel12 handler declared in "main.c" file */
			extern	DMA_Channel12_InitTypeDef DmaCh12Handle;
		
		#endif	
		
	#endif
	
#endif

#if defined USE_ECC || defined USE_ECC384

	#if (USE_HT_ECC_REGISTER_CALLBACKS == 1U)
	
	/* ECC handler declared in "main.c" file */
	extern ECC_InitTypeDef  ECCHandle;
	
	#endif
	
#endif

#if defined USE_ARG

	#if (USE_HT_ARG_REGISTER_CALLBACKS == 1U)
	
	/* ARG handler declared in "main.c" file */
	extern ARG_InitTypeDef  ARGHandle;
	
	#endif
	
#endif

#if defined USE_I2C

	#if (USE_HT_I2C_REGISTER_CALLBACKS == 1U)
	
	/* I2C handler declaration */
	extern I2C_InitTypeDef I2CHandle;
	
	#endif
	
#endif

#if defined USE_KEYSCAN

	#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
	
	/* KEY handler declaration */
	extern KEY_InitTypeDef KeyHandle;
	
	#endif
	
#endif

#if defined USE_EMUIFACE_5X || defined USE_EMUIFACE_7X

	#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
	
	/* EMUIFACE handler declaration */
	extern EMUIFACE_InitTypeDef EmuIfaceHandle;
	
	#endif
	
#endif

#if defined USE_FRAMPACK_5X || defined USE_FRAMPACK_7X

	#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)
	
	/* FRAMPACK handler declaration */
	extern FRAMPACK_InitTypeDef FrampackHandle;
	
	#endif
	
#endif

#if defined USE_FFT

	#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)
	
	/* FFT handler declaration */
	extern FFT_InitTypeDef FftHandle;
	
	#endif
	
#endif

/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)

/* UART IRQHandler declared in "ht6xxx_uart&7816.c" file */
extern void HT_UART_IRQHandler(UART_InitTypeDef *UART_InitStruct);
extern void HT_ISO7816_IRQHandler(ISO7816_InitTypeDef *ISO7816_InitStruct);

#endif

#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)

/* SPI IRQHandler declared in "ht6xxx_spi.c" file */
extern void HT_SPI_IRQHandler(SPI_InitTypeDef *SPI_InitStruct);

#endif

#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)

/* RTC IRQHandler declared in "ht6xxx_rtc.c" file */
extern void HT_RTC_IRQHandler(RTC_InitTypeDef *RTC_InitStruct);

#endif

#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)

/* PMU IRQHandler declared in "ht6xxx_pmu.c" file */
extern void HT_PMU_IRQHandler(PMU_InitTypeDef *PMU_InitStruct);

#endif

#if (USE_HT_TBS_REGISTER_CALLBACKS == 1U)

/* TBS IRQHandler declared in "ht6xxx_TBS.c" file */
extern void HT_TBS_IRQHandler(TBS_InitTypeDef *TBS_InitStruct);

#endif

#if (USE_HT_WDT_REGISTER_CALLBACKS == 1U)

/* WDT handler declared in "main.c" file */
extern void HT_WDT_IRQHandler(WDT_InitTypeDef *WDT_InitStruct);

#endif

#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

/* HT_TMR_IRQHandler declared in "ht6xxx_timer.c" file */
extern void HT_TMR_IRQHandler(TMR_InitTypeDef *TMR_InitStruct);

	#if defined USE_TMR_EXT
	
	extern void HT_TMRExt_IRQHandler(TMRExt_InitTypeDef *TMRExt_InitStruct);
	
	#endif

#endif

#if (USE_HT_SYSTICK_REGISTER_CALLBACKS == 1U)

/* SysTick_IRQHandler declared in "system_ht6xxx.c" file */
extern void SysTick_IRQHandler(SysTick_InitTypeDef *SysTick_InitStruct);

#endif

#if( USE_HT_EXTI_REGISTER_CALLBACKS ==1U)

/* HT_EXTI_IRQHandler declared in "ht6xxx_exti.c" file */
extern void HT_EXTI_IRQHandler(EXTI_TypeDef *ExtiStruct);

#endif

#if defined  USE_EMU
#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
/* EMU IRQHandler declared in "ht50xx_emu.c" or "ht7xxx_emu.c" file */
extern void HT_EMU_IRQHandler(EMU_InitTypeDef *EMU_InitStruct);
#if defined HT762x || defined HT772x
extern void HT_EWU_IRQHandler(EWU_InitTypeDef *EWU_InitStruct);
#endif
#endif
#endif

#if defined  USE_DMA
	#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
	
	/* DMA IRQHandler declared in "ht50xx_dma.c" file */
	extern void HT_DMA_IRQHandler(DMA_InitTypeDef *DMA_InitStruct);
	
	#endif

#endif

#if defined USE_ECC || defined USE_ECC384

	#if (USE_HT_ECC_REGISTER_CALLBACKS == 1U)
	
	/* ECC IRQHandler declared in "ht6xxx_ecc.c" file */
	extern void HT_ECC_IRQHandler(ECC_InitTypeDef *ECC_InitStruct);
	
	#endif
	
#endif

#if defined USE_ARG

	#if (USE_HT_ARG_REGISTER_CALLBACKS == 1U)
	
	/* ARG IRQHandler declared in "ht6xxx_aes&rand.c" file */
	extern void HT_ARG_IRQHandler(ARG_InitTypeDef *ARG_InitStruct);
	
	#endif
	
#endif

#if defined USE_I2C

	#if (USE_HT_I2C_REGISTER_CALLBACKS == 1U)
	
	/* I2C IRQHandler declared in "ht6xxx_iic.c" file */
	extern void HT_I2C_IRQHandler(I2C_InitTypeDef *I2C_InitStruct);
	
	#endif
	
#endif

#if defined USE_KEYSCAN

	#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
	
	/* KEY IRQHandler declared in "ht6xxx_iic.c" file */
	extern void HT_KEY_IRQHandler(KEY_InitTypeDef *KEY_InitStruct);
	
	#endif
	
#endif

#if defined USE_EMUIFACE_5X || defined USE_EMUIFACE_7X 

	#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
	
	/* EMUIFACE IRQHandler declared in "htxxxx_emuif.c" file */
	extern void HT_EMUIFACE_IRQHandler(EMUIFACE_InitTypeDef* EMUIFACE_InitStruct);
	
	#endif
	
#endif

#if defined USE_FRAMPACK_5X || defined USE_FRAMPACK_7X 

	#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)
	
	/* FRAMPACK IRQHandler declared in "htxxxx_frampack.c" file */
	extern void HT_FRAMPACK_IRQHandler(FRAMPACK_InitTypeDef* FRAMPACK_InitStruct);
	
	#endif
	
#endif

#if defined USE_FFT

	#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)
	
	/* FRAMPACK IRQHandler declared in "htxxxx_fft.c" file */
	extern void HT_FFT_IRQHandler(FFT_InitTypeDef* FFT_InitStruct);
	
	#endif
	
#endif


#if defined USE_DMA && (USE_HT_DMA_REGISTER_CALLBACKS == 0U)

static void DMA_IRQProc(void)
{
	
	#if defined  USE_DMA_Channel11
	
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel0, DMA_DMAIF_TCIF0))        /*!< DMA Channel0 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel0, DMA_DMAIF_TCIF0);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel0, DMA_DMAIF_BCIF0))         /*!< DMA Channel0 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel0, DMA_DMAIF_BCIF0);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel0, DMA_DMAIF_TEIF0))         /*!< DMA Channel0 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel0,DMA_DMAIF_TEIF0);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel1, DMA_DMAIF_TCIF1))        /*!< DMA Channel1 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel1, DMA_DMAIF_TCIF1);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel1,DMA_DMAIF_BCIF1))         /*!< DMA Channel1 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel1, DMA_DMAIF_BCIF1);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel1, DMA_DMAIF_TEIF1))         /*!< DMA Channel1 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel1, DMA_DMAIF_TEIF1);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel2, DMA_DMAIF_TCIF2))        /*!< DMA Channel2 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel2, DMA_DMAIF_TCIF2);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel2, DMA_DMAIF_BCIF2))         /*!< DMA Channel2 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel2, DMA_DMAIF_BCIF2);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel2, DMA_DMAIF_TEIF2))         /*!< DMA Channel2 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel2, DMA_DMAIF_TEIF2);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel3, DMA_DMAIF_TCIF3))        /*!< DMA Channel3 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel3, DMA_DMAIF_TCIF3);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel3, DMA_DMAIF_BCIF3))         /*!< DMA Channel3 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel3, DMA_DMAIF_BCIF3);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel3, DMA_DMAIF_TEIF3))         /*!< DMA Channel3 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel3, DMA_DMAIF_TEIF3);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel4, DMA_DMAIF_TCIF4))        /*!< DMA Channel4 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel4, DMA_DMAIF_TCIF4);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel4, DMA_DMAIF_BCIF4))         /*!< DMA Channel4 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel4, DMA_DMAIF_BCIF4);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel4, DMA_DMAIF_TEIF4))         /*!< DMA Channel4 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel4, DMA_DMAIF_TEIF4);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel5, DMA_DMAIF_TCIF5))        /*!< DMA Channel5 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel5, DMA_DMAIF_TCIF5);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel5, DMA_DMAIF_BCIF5))         /*!< DMA Channel5 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel5, DMA_DMAIF_BCIF5);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel5, DMA_DMAIF_TEIF5))         /*!< DMA Channel5 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel5, DMA_DMAIF_TEIF5);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel6, DMA_DMAIF_TCIF6))        /*!< DMA Channel6 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel6, DMA_DMAIF_TCIF6);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel6, DMA_DMAIF_BCIF6))         /*!< DMA Channel6 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel6, DMA_DMAIF_BCIF6);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel6, DMA_DMAIF_TEIF6))         /*!< DMA Channel6 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel6, DMA_DMAIF_TEIF6);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel7, DMA_DMAIF_TCIF7))        /*!< DMA Channel7 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel7, DMA_DMAIF_TCIF7);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel7, DMA_DMAIF_BCIF7))         /*!< DMA Channel7 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel7, DMA_DMAIF_BCIF7);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel7,DMA_DMAIF_TEIF7))         /*!< DMA Channel7 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel7, DMA_DMAIF_TEIF7);
		}
		
	#else
		
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TCIF0))        /*!< DMA Channel0 TC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF0);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_BCIF0))         /*!< DMA Channel0 BC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF0);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TEIF0))         /*!< DMA Channel0 TE_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF0);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TCIF1))        /*!< DMA Channel1 TC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF1);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_BCIF1))         /*!< DMA Channel1 BC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF1);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TEIF1))         /*!< DMA Channel1 TE_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF1);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TCIF2))        /*!< DMA Channel2 TC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF2);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_BCIF2))         /*!< DMA Channel2 BC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF2);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TEIF2))         /*!< DMA Channel2 TE_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF2);
		}
		
		#if defined  USE_DMA_Channel7
		
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TCIF3))        /*!< DMA Channel3 TC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF3);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_BCIF3))         /*!< DMA Channel3 BC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF3);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TEIF3))         /*!< DMA Channel3 TE_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF3);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TCIF4))        /*!< DMA Channel4 TC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF4);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_BCIF4))         /*!< DMA Channel4 BC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF4);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TEIF4))         /*!< DMA Channel4 TE_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF4);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TCIF5))        /*!< DMA Channel5 TC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF5);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_BCIF5))         /*!< DMA Channel5 BC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF5);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TEIF5))         /*!< DMA Channel5 TE_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF5);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TCIF6))        /*!< DMA Channel6 TC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF6);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_BCIF6))         /*!< DMA Channel6 BC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF6);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TEIF6))         /*!< DMA Channel6 TE_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF6);
		}	
		
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TCIF7))        /*!< DMA Channel7 TC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TCIF7);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_BCIF7))         /*!< DMA Channel7 BC_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_BCIF7);
		}
		if(SET == HT_DMA_ITFlagStatusGet(DMA_DMAIF_TEIF7))         /*!< DMA Channel7 TE_INT handle     */
		{
				HT_DMA_ClearITPendingBit(DMA_DMAIF_TEIF7);
		}
		
		#endif	/*!< USE_DMA_Channel7     */	
		
	#endif	/*!< USE_DMA_Channel11     */	
		
		#if defined  USE_DMA_Channel11
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel8, DMA_DMAIF1_TCIF8))        /*!< DMA Channel8 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel8, DMA_DMAIF1_TCIF8);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel8, DMA_DMAIF1_BCIF8))         /*!< DMA Channel8 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel8, DMA_DMAIF1_BCIF8);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel8, DMA_DMAIF1_TEIF8))         /*!< DMA Channel8 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel8, DMA_DMAIF1_TEIF8);
		}
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel9, DMA_DMAIF1_TCIF9))        /*!< DMA Channel9 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel9, DMA_DMAIF1_TCIF9);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel9, DMA_DMAIF1_BCIF9))         /*!< DMA Channel9 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel9, DMA_DMAIF1_BCIF9);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel9, DMA_DMAIF1_TEIF9))         /*!< DMA Channel9 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel9, DMA_DMAIF1_TEIF9);
		}	
		
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel10,DMA_DMAIF1_TCIF10))        /*!< DMA Channel10 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel10,DMA_DMAIF1_TCIF10);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel10,DMA_DMAIF1_BCIF10))         /*!< DMA Channel10 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel10,DMA_DMAIF1_BCIF10);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel10,DMA_DMAIF1_TEIF10))         /*!< DMA Channel10 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel10,DMA_DMAIF1_TEIF10);
		}

		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel11,DMA_DMAIF1_TCIF11))        /*!< DMA Channel11 TC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel11,DMA_DMAIF1_TCIF11);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel11,DMA_DMAIF1_BCIF11))         /*!< DMA Channel11 BC_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel11,DMA_DMAIF1_BCIF11);
		}
		if(SET == HT_DMA_ITFlagStatusGet(HT_DMA_Channel11,DMA_DMAIF1_TEIF11))         /*!< DMA Channel11 TE_INT handle     */
		{
			HT_DMA_ClearITPendingBit(HT_DMA_Channel11,DMA_DMAIF1_TEIF11);
		}
		
		#endif	/*!< USE_DMA_Channel11     */	
		
		#if defined  USE_DMA_Channel12
		
		if(SET == HT_DMA_Channel12_ITFlagStatusGet(DMA_DMAIF2_PEIF12))       /*!< DMA Channel12 PE_INT handle     */
		{
				HT_DMA_Channel12_ClearITPendingBit(DMA_DMAIF2_PEIF12);
		}
		if(SET == HT_DMA_Channel12_ITFlagStatusGet(DMA_DMAIF2_BCIF12))       /*!< DMA Channel12 BC_INT handle     */
		{
				HT_DMA_Channel12_ClearITPendingBit(DMA_DMAIF2_BCIF12);
		}
		if(SET == HT_DMA_Channel12_ITFlagStatusGet(DMA_DMAIF2_TEIF12))       /*!< DMA Channel12 TE_INT handle     */
		{
				HT_DMA_Channel12_ClearITPendingBit(DMA_DMAIF2_TEIF12);
		}
		
		#endif	/*!< USE_DMA_Channel12     */
}
#endif

/*
*********************************************************************************************************
*                                        NMI INTERRUPT HANDLER #16-14
*
*********************************************************************************************************
*/
void NMI_Handler(void)
{
    if (SET == HT_CMU_StopFlagGet(CMU_CLKSTA_LFFLAG))
    {

    }

    if (SET == HT_CMU_StopFlagGet(CMU_CLKSTA_HRCFLAG))
    {

    }

    if (SET == HT_CMU_StopFlagGet(CMU_CLKSTA_PLLFLAG))
    {

    }
}

/*
*********************************************************************************************************
*                                        HARDFAULT INTERRUPT HANDLER #16-13
*
*********************************************************************************************************
*/
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode 			= GPIO_Mode_IOOUT;
	GPIO_InitStruct.GPIO_Pin 			= GPIO_Pin_0;
	GPIO_InitStruct.GPIO_OutputStruct 	= GPIO_Output_PP;
	GPIO_InitStruct.GPIO_InputStruct 	= GPIO_Input_Up;
	GPIO_InitStruct.GPIO_InputFilter 	= DISABLE;
	HT_GPIO_Init(HT_GPIOE, &GPIO_InitStruct);
    while (1)
    {
		HT_GPIO_BitsToggle(HT_GPIOE, GPIO_Pin_0);
		for(uint16_t j=0;j<0xf;j++)
		{
			for(uint16_t i=0;i<0xffff;i++){}
		}
    }
}

/*
*********************************************************************************************************
*                                        SVC INTERRUPT HANDLER #16-5
*
*********************************************************************************************************
*/
//void SVC_Handler(void)
//{

//}

/*
*********************************************************************************************************
*                                        PENDSV INTERRUPT HANDLER #16-2
*
*********************************************************************************************************
*/
//void PendSV_Handler(void)
//{

//}

/*
*********************************************************************************************************
*                                        SYSTICK INTERRUPT HANDLER #16-1
*
*********************************************************************************************************
*/
extern void xPortSysTickHandler(void);
void SysTick_Handler(void)
{
#if (USE_HT_SYSTICK_REGISTER_CALLBACKS == 1U)
	
	SysTick_IRQHandler(&SysTickHandle);
	
#else
	if(xTaskGetSchedulerState()!=taskSCHEDULER_NOT_STARTED)//系统已经运行
	{
		xPortSysTickHandler();
	}
#endif
}

/*
*********************************************************************************************************
*                                        PMU INTERRUPT HANDLER #16+0
*
*********************************************************************************************************
*/

void PMU_IRQHandler(void)
{
#if	(USE_HT_PMU_REGISTER_CALLBACKS == 1U)
	
		HT_PMU_IRQHandler(&PmuHandle);
	
#else
	
		if(SET == HT_PMU_ITFlagStatusGet(PMU_PMUIF_VCCIF))           /*!< Vcc detects interrupt flag set            */
		{
				HT_PMU_ClearITPendingBit(PMU_PMUIF_VCCIF);               /*!< clear interrupt flag               */
		}

		if(SET == HT_PMU_ITFlagStatusGet(PMU_PMUIF_BORIF))           /*!< Bor detects interrupt flag set            */
		{
				HT_PMU_ClearITPendingBit(PMU_PMUIF_BORIF);               /*!< clear interrupt flag               */
		}

		if(SET == HT_PMU_ITFlagStatusGet(PMU_PMUIF_LVD0IF))           /*!< Lvdin0 detect interrupt flag set         */
		{
				HT_PMU_ClearITPendingBit(PMU_PMUIF_LVD0IF);               /*!< clear interrupt flag               */
		}
 
		#if  defined  USE_LVDIN1  
		
		if(SET == HT_PMU_ITFlagStatusGet(PMU_PMUIF_LVD1IF))           /*!< Lvdin1 detect interrupt flag set          */
		{
				HT_PMU_ClearITPendingBit(PMU_PMUIF_LVD1IF);               /*!< clear interrupt flag               */
		}
	
		#endif
    
		#if  defined  USE_LVDIN2
		
		if(SET == HT_PMU_ITFlagStatusGet(PMU_PMUIF_LVD2IF))           /*!< Lvdin2 detect interrupt flag set          */
		{
				HT_PMU_ClearITPendingBit(PMU_PMUIF_LVD2IF);               /*!< clear interrupt flag               */
		}
	
		#endif
	
		#if defined	USE_POWDET
			
		/*	POWDET	*/
		if (SET == HT_PMU_ITFlagStatusGet(PMU_PMUIF_POWIF))
		{
				HT_PMU_ClearITPendingBit(PMU_PMUIF_POWIF);              /*!< clear interrupt flag          */
		}
		
		#endif
	
#endif		
}

/*
*********************************************************************************************************
*                                  3DES/AES INTERRUPT HANDLER  #16+1
*
*********************************************************************************************************
*/
#if defined HT6x1x

void TDES_IRQHandler(void)                      /*!< TDES               */
{

}

#else

void AES_IRQHandler(void)                       /*!< AES/RAND/GHASH/ECC               */
{
	#if defined USE_ECC || defined USE_ECC384
	
	if(SET == HT_ECC_ITFlagStatusGet(ECC_IF))
	{
			#if (USE_HT_ECC_REGISTER_CALLBACKS == 1U)
	
			HT_ECC_IRQHandler(&ECCHandle);
		
			#else

			HT_ECC_ClearITPendingBit(ECC_IF);
	
			#endif   
	}
	#endif
	
	#if defined USE_ARG
		
    #if (USE_HT_ARG_REGISTER_CALLBACKS == 1U)
		
		HT_ARG_IRQHandler(&ARGHandle);
		
    #else
		
		if(SET == HT_AES_GHASH_RAND_ITFlagStatusGet(AES_IF))
		{
			HT_AES_GHASH_RAND_ClearITPendingBit(AES_IF);
		}
			if(SET == HT_AES_GHASH_RAND_ITFlagStatusGet(GHASH_IF))
		{
			HT_AES_GHASH_RAND_ClearITPendingBit(GHASH_IF);
		}
			if(SET == HT_AES_GHASH_RAND_ITFlagStatusGet(RAND_IF))
		{
			HT_AES_GHASH_RAND_ClearITPendingBit(RAND_IF);
		}
		
    #endif
		
	#endif
}
#endif

/*
*********************************************************************************************************
*                                   EXTI0 INTERRUPT HANDLER  #16+2
*
*********************************************************************************************************
*/

void EXTI0_IRQHandler(void)
{
#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
#else

    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT0))         /*!< INT0 rising edge interrupt flag set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT0);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT0))         /*!< INT0 falling edge interrupt flag set          */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT0);             /*!< clear interrupt flag             */
    }
		
#endif
}

/*
*********************************************************************************************************
*                                   EXTI1 INTERRUPT HANDLER  #16+3
*
*********************************************************************************************************
*/

#if defined USE_EXTI0_6_IRQHANDLER

void EXTI1_3_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT1))         /*!< INT1 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT1);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT1))         /*!< INT1 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT1);             /*!< clear interrupt flag             */
    }
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT2))         /*!< INT2 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT2);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT2))         /*!< INT2 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT2);             /*!< clear interrupt flag             */
    }
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT3))         /*!< INT3 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT3);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT3))         /*!< INT3 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT3);             /*!< clear interrupt flag             */
    }
		
		#endif
}
#endif

#if !defined  USE_EXTI0_6_IRQHANDLER

void EXTI1_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT1))         /*!< INT1 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT1);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT1))         /*!< INT1 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT1);             /*!< clear interrupt flag             */
    }
		
		#endif
}
#endif

/*
*********************************************************************************************************
*                                   EXTI2 INTERRUPT HANDLER  #16+4
*
*********************************************************************************************************
*/
#if !defined  USE_EXTI0_6_IRQHANDLER

void EXTI2_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT2))         /*!< INT2 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT2);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT2))         /*!< INT2 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT2);             /*!< clear interrupt flag             */
    }
		
		#endif
}
#endif


#if defined  HT762x ||  defined  HT772x 

void FFT_IRQHandler()
{
		#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)
	
		HT_FFT_IRQHandler(&FftHandle);
	
		#else
	
	    if(SET == HT_FFT_ITFlagStatusGet(FFT_FFTIF_FFT_IF))
		{
				HT_FFT_ClearErrPendingBit(FFT_FFTERR_CLIPE|FFT_FFTERR_CLIPIN|FFT_FFTERR_CLIPOUT);
				HT_FFT_ClearITPendingBit(FFT_FFTIF_FFT_IF);
		}
		if(SET == HT_FFT_ITFlagStatusGet(FFT_FFTIF_FFT_DONE_IF))
		{
				HT_FFT_ClearITPendingBit(FFT_FFTIF_FFT_DONE_IF);
		}
		
		#endif
		
		#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
		
		HT_EMUIFACE_IRQHandler(&EmuIfaceHandle);
		
		#else
		
		if(SET == HT_EMUIFACE_ITFlagStatusGet(EMUIFACE_NIS_IF))
		{
			
				HT_EMUIFACE_ClearITPendingBit(EMUIFACE_NIS_IF);
		}
		if(SET == HT_EMUIFACE_ITFlagStatusGet(EMUIFACE_FFT_IF))
		{
			
				HT_EMUIFACE_ClearITPendingBit(EMUIFACE_FFT_IF);
		}
		
		#endif
		
		#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)
		
		HT_FRAMPACK_IRQHandler(&FrampackHandle);
		
		#else
		
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_ENDIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_ENDIF);
		}
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_HEADIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_HEADIF);
		}
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_FIFOFULLIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FIFOFULLIF);
		}
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_FIFOEMPTYIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FIFOEMPTYIF);
		}
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_FRAM_DONEIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FRAM_DONEIF);
		}
		
		#endif
}
#endif


/*
*********************************************************************************************************
*                                   EXTI3 INTERRUPT HANDLER  #16+5
*
*********************************************************************************************************
*/
#if !defined  USE_EXTI0_6_IRQHANDLER

void EXTI3_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT3))         /*!< INT3 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT3);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT3))         /*!< INT3 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT3);             /*!< clear interrupt flag             */
    }
		
		#endif
}
#endif

/*
*********************************************************************************************************
*                                   EXTI4 INTERRUPT HANDLER  #16+6
*
*********************************************************************************************************
*/
#if !defined  USE_EXTI0_6_IRQHANDLER

void EXTI4_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT4))         /*!< INT4 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT4);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT4))         /*!< INT4 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT4);             /*!< clear interrupt flag             */
    }
		
		#endif
}
#endif


#if defined  USE_EXTI0_6_IRQHANDLER

void EXTI4_6_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT4))         /*!< INT4 rising edge interrupt flag set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT4);             /*!< clear interrupt flag             */
    }
    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT4))         /*!< INT4 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT4);             /*!< clear interrupt flag             */
    }
		if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT5))         /*!< INT5 rising edge interrupt flag set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT5);             /*!< clear interrupt flag             */
    }
    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT5))         /*!< INT5 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT5);             /*!< clear interrupt flag             */
    }
		if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT6))         /*!< INT6 rising edge interrupt flag set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT6);             /*!< clear interrupt flag             */
    }
    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT6))         /*!< INT6 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT6);             /*!< clear interrupt flag             */
    }
		
		#endif
}
#endif

/*
*********************************************************************************************************
*                                   EXTI5 INTERRUPT HANDLER  #16+7
*
*********************************************************************************************************
*/
#if !defined  USE_EXTI0_6_IRQHANDLER

void EXTI5_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT5))         /*!< INT5 rising edge interrupt flag set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT5);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT5))         /*!< INT5 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT5);             /*!< clear interrupt flag             */
    }
		
		#endif
}

#endif

#if defined  HT762x  ||  defined  HT772x
void EMU_IRQHandler(void)
{
#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
	HT_EMU_IRQHandler(&EmuHandle);
#else
	if(SET == HT_EMUIF1_FlagStatusGet(EMUIF1_AllP_PosCFIF))
	{
		HT_EMUIF1_PendingBitClear(EMUIF1_AllP_PosCFIF);
	}
	if(SET == HT_EMUIF1_FlagStatusGet(EMUIF1_AllQ_PosCFIF))
	{
		HT_EMUIF1_PendingBitClear(EMUIF1_AllQ_PosCFIF);
	}
	if(SET == HT_EMUIF1_FlagStatusGet(EMUIF1_SPLUpdateIF))
	{
		HT_EMUIF1_PendingBitClear(EMUIF1_SPLUpdateIF);
	}
	if(SET == HT_EMUIF1_FlagStatusGet(EMUIF1_PowerUpdateIF))
	{
		HT_EMUIF1_PendingBitClear(EMUIF1_PowerUpdateIF);
	}
	if(SET == HT_EMUIF1_FlagStatusGet(EMUIF1_RMSUpdateIF))
	{
		HT_EMUIF1_PendingBitClear(EMUIF1_RMSUpdateIF);
	}
	#if defined  HT762x	
	if(SET == HT_EMUIF2_FlagStatusGet(EMUIF2_VpupdUaIF))
	{
		HT_EMUIF2_PendingBitClear(EMUIF2_VpupdUaIF);
	}
	if(SET == HT_EMUIF2_FlagStatusGet(EMUIF2_VpupdUbIF))
	{
		HT_EMUIF2_PendingBitClear(EMUIF2_VpupdUbIF);
	}
	if(SET == HT_EMUIF2_FlagStatusGet(EMUIF2_VpupdUcIF))
	{
		HT_EMUIF2_PendingBitClear(EMUIF2_VpupdUcIF);
	}
	#else
	if(SET == HT_EMUIF2_FlagStatusGet(EMUIF2_VpupdUIF))
	{
		HT_EMUIF2_PendingBitClear(EMUIF2_VpupdUIF);
	}
	if(SET == HT_EMUIF2_FlagStatusGet(EMUIF2_VpupdI1IF))
	{
		HT_EMUIF2_PendingBitClear(EMUIF2_VpupdI1IF);
	}
	if(SET == HT_EMUIF2_FlagStatusGet(EMUIF2_VpupdI2IF))
	{
		HT_EMUIF2_PendingBitClear(EMUIF2_VpupdI2IF);
	}
	#endif
#endif	
}
#endif

/*
*********************************************************************************************************
*                                   EXTI6 INTERRUPT HANDLER  #16+8
*
*********************************************************************************************************
*/

#if !defined  USE_EXTI0_6_IRQHANDLER

void EXTI6_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF_RIF_INT6))         /*!< INT6 rising edge interrupt flag set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF_RIF_INT6);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF_FIF_INT6))         /*!< INT6 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF_FIF_INT6);             /*!< clear interrupt flag             */
    }
		
		#endif
}

#endif


#if defined  HT762x || defined  HT772x
void EWU_IRQHandler(void)
{
#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
	HT_EWU_IRQHandler(&EwuHandle);
#else
	if(SET == HT_EMU_EWUIF_FlagStatusGet(EWUIF_FlickerUpdIF))
	{
		HT_EMU_EWUIF_PendingBitClear(EWUIF_FlickerUpdIF);
	}
	if(SET == HT_EMU_EWUIF_FlagStatusGet(EWUIF_SyncDftUpdIF))
	{
		HT_EMU_EWUIF_PendingBitClear(EWUIF_SyncDftUpdIF);
	}
	if(SET == HT_EMU_EWUIF_FlagStatusGet(EWUIF_HpRmsIF))
	{
		HT_EMU_EWUIF_PendingBitClear(EWUIF_HpRmsIF);
	}
#endif

}
#endif
/*
*********************************************************************************************************
*                                   UART0 INTERRUPT HANDLER  #16+9
*
*********************************************************************************************************
*/

void UART0_IRQHandler(void)
{
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
	
		if(SET == READ_BIT(HT_UART0->IRCON, UART_IRCON_IRTX))
		{	
				HT_UART_IRQHandler(&IRHandle.UARTModule);
		}
	  else
		{
				HT_UART_IRQHandler(&UartHandle);
		}
		
#else
		
    if(SET == HT_UART_ITFlagStatusGet(HT_UART0, UART_UARTSTA_TXIF))         /*!< UART0 send interrupt flag set        */
    {

        HT_UART_ClearITPendingBit(HT_UART0, UART_UARTSTA_TXIF);             /*!< clear interrupt flag          */
    }

    if(SET == HT_UART_ITFlagStatusGet(HT_UART0, UART_UARTSTA_RXIF))         /*!< UART0 receive interrupt flag set         */
    {
		HT_UART_RxCallbackFun();
        HT_UART_ClearITPendingBit(HT_UART0, UART_UARTSTA_RXIF);             /*!< clear interrupt flag          */
    }
#endif
}

/*
*********************************************************************************************************
*                                   UART1 INTERRUPT HANDLER  #16+10
*
*********************************************************************************************************
*/

void UART1_IRQHandler(void)
{
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)

		if(SET == READ_BIT(HT_UART1->IRCON, UART_IRCON_IRTX))
		{	
				HT_UART_IRQHandler(&IRHandle.UARTModule);
		}
		else
		{
				HT_UART_IRQHandler(&UartHandle);
		}
	
#else
		
    if(SET == HT_UART_ITFlagStatusGet(HT_UART1, UART_UARTSTA_TXIF))         /*!< UART1 send interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART1, UART_UARTSTA_TXIF);             /*!< clear interrupt flag          */
    }

    if(SET == HT_UART_ITFlagStatusGet(HT_UART1, UART_UARTSTA_RXIF))         /*!< UART1 receive interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART1, UART_UARTSTA_RXIF);             /*!< clear interrupt flag          */
    }
		
#endif
}

/*
*********************************************************************************************************
*                                   UART2 INTERRUPT HANDLER  #16+11
*
*********************************************************************************************************
*/

void UART2_IRQHandler(void)
{
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
		
		if(SET == READ_BIT(HT_UART2->IRCON, UART_IRCON_IRTX))
		{	
				HT_UART_IRQHandler(&IRHandle.UARTModule);
		}
		else
		{
				HT_UART_IRQHandler(&UartHandle);
		}
	
#else
	
    if(SET == HT_UART_ITFlagStatusGet(HT_UART2, UART_UARTSTA_TXIF))         /*!< UART2 send interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART2, UART_UARTSTA_TXIF);             /*!< clear interrupt flag          */
    }

    if(SET == HT_UART_ITFlagStatusGet(HT_UART2, UART_UARTSTA_RXIF))         /*!< UART2 receive interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART2, UART_UARTSTA_RXIF);             /*!< clear interrupt flag          */
    }
		
#endif
}

/*
*********************************************************************************************************
*                                   UART3 INTERRUPT HANDLER  #16+12
*
*********************************************************************************************************
*/

void UART3_IRQHandler(void)
{
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)

		if(SET == READ_BIT(HT_UART3->IRCON, UART_IRCON_IRTX))
		{	
				HT_UART_IRQHandler(&IRHandle.UARTModule);
		}
		else if(SET == HT_UART_ITFlagStatusGet(HT_UART3, UART_UARTSTA_TXIF | UART_UARTSTA_RXIF))            /*!< UART3 send and receive interrupt flag set         */
		{
				HT_UART_IRQHandler(&UartHandle);
		}
		else
		{
		
		}

		if(SET == HT_ISO7816_ITFlagStatusGet(HT_ISO7816_1, UART_ISO7816STA_TXIF | UART_ISO7816STA_RXIF | UART_ISO7816STA_PRDIF))  /*!< 7816 send and receive and overflow interrupt flag set          */
		{
				HT_ISO7816_IRQHandler(&ISO7816Handle);
		}
		
#else
		
    if(SET == HT_UART_ITFlagStatusGet(HT_UART3, UART_UARTSTA_TXIF))            /*!< UART3 send interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART3, UART_UARTSTA_TXIF);                /*!< clear interrupt flag          */
    }

    if(SET == HT_UART_ITFlagStatusGet(HT_UART3, UART_UARTSTA_RXIF))            /*!< UART3 receive interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART3, UART_UARTSTA_RXIF);                /*!< clear interrupt flag          */
    }

    if(SET == HT_ISO7816_ITFlagStatusGet(HT_ISO7816_1, UART_ISO7816STA_TXIF))  /*!< 7816 send interrupt flag set          */
    {

        HT_ISO7816_ClearITPendingBit(HT_ISO7816_1, UART_ISO7816STA_TXIF);      /*!< clear interrupt flag          */
    }

    if(SET == HT_ISO7816_ITFlagStatusGet(HT_ISO7816_1, UART_ISO7816STA_RXIF))  /*!< 7816 receive interrupt flag set          */
    {

        HT_ISO7816_ClearITPendingBit(HT_ISO7816_1, UART_ISO7816STA_RXIF);      /*!< clear interrupt flag          */
    }

    if(SET == HT_ISO7816_ITFlagStatusGet(HT_ISO7816_1, UART_ISO7816STA_PRDIF)) /*!< 7816 receive overflow interrupt flag set  */
    {

        HT_ISO7816_ClearITPendingBit(HT_ISO7816_1, UART_ISO7816STA_PRDIF);     /*!< clear interrupt flag          */
    }
		
#endif
}

/*
*********************************************************************************************************
*                                   UART4 INTERRUPT HANDLER  #16+13
*
*********************************************************************************************************
*/

void UART4_IRQHandler(void)
{	
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)

		if(SET == READ_BIT(HT_UART4->IRCON, UART_IRCON_IRTX))
		{	
				HT_UART_IRQHandler(&IRHandle.UARTModule);
		}
		else if(SET == HT_UART_ITFlagStatusGet(HT_UART4, UART_UARTSTA_TXIF | UART_UARTSTA_RXIF))            /*!< UART4 send interrupt flag set         */
		{
				HT_UART_IRQHandler(&UartHandle);
		}
		else
		{
		
		}

		if(SET == HT_ISO7816_ITFlagStatusGet(HT_ISO7816_0, UART_ISO7816STA_TXIF | UART_ISO7816STA_RXIF | UART_ISO7816STA_PRDIF))  /*!< 7816 send and receive and overflow interrupt flag set           */
		{

				HT_ISO7816_IRQHandler(&ISO7816Handle);
		}

#else
	
    if(SET == HT_UART_ITFlagStatusGet(HT_UART4, UART_UARTSTA_TXIF))            /*!< UART4 send interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART4, UART_UARTSTA_TXIF);                /*!< clear interrupt flag          */
    }

    if(SET == HT_UART_ITFlagStatusGet(HT_UART4, UART_UARTSTA_RXIF))            /*!< UART4 receive interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART4, UART_UARTSTA_RXIF);                /*!< clear interrupt flag          */
    }

    if(SET == HT_ISO7816_ITFlagStatusGet(HT_ISO7816_0, UART_ISO7816STA_TXIF))  /*!< 7816 send interrupt flag set          */
    {

        HT_ISO7816_ClearITPendingBit(HT_ISO7816_0, UART_ISO7816STA_TXIF);      /*!< clear interrupt flag          */
    }

    if(SET == HT_ISO7816_ITFlagStatusGet(HT_ISO7816_0, UART_ISO7816STA_RXIF))  /*!< 7816 receive interrupt flag set          */
    {

        HT_ISO7816_ClearITPendingBit(HT_ISO7816_0, UART_ISO7816STA_RXIF);      /*!< clear interrupt flag          */
    }

    if(SET == HT_ISO7816_ITFlagStatusGet(HT_ISO7816_0, UART_ISO7816STA_PRDIF)) /*!< 7816 receive overflow interrupt flag set  */
    {

        HT_ISO7816_ClearITPendingBit(HT_ISO7816_0, UART_ISO7816STA_PRDIF);     /*!< clear interrupt flag          */
    }
		
#endif
}

/*
*********************************************************************************************************
*                                   UART5 INTERRUPT HANDLER  #16+14
*
*********************************************************************************************************
*/

void UART5_IRQHandler(void)
{
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
	
		if(SET == READ_BIT(HT_UART5->IRCON, UART_IRCON_IRTX))
		{	
				HT_UART_IRQHandler(&IRHandle.UARTModule);
		}
		 else
		{
				HT_UART_IRQHandler(&UartHandle);
		}
		
#else
		
    if(SET == HT_UART_ITFlagStatusGet(HT_UART5, UART_UARTSTA_TXIF))         /*!< UART5 send interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART5, UART_UARTSTA_TXIF);             /*!< clear interrupt flag          */
    }

    if(SET == HT_UART_ITFlagStatusGet(HT_UART5, UART_UARTSTA_RXIF))         /*!< UART5 receive interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART5, UART_UARTSTA_RXIF);             /*!< clear interrupt flag          */
    }
		
#endif
}

/*
*********************************************************************************************************
*                                   TIMER_0 INTERRUPT HANDLER  #16+15
*
*********************************************************************************************************
*/

void TIMER_0_IRQHandler(void)
{

#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)
	
    HT_TMR_IRQHandler(&TimHandle);

#else

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR0, TMR_TMRIF_PRDIF))                /*!< Period interrupt           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR0, TMR_TMRIF_PRDIF);                    /*!< Clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR0, TMR_TMRIF_CAPIF))                /*!< capture  interrupt         */
    {
				#if defined USE_TMR_CCSTA
			
        uint16_t CCSTAVal = HT_TMR_ITFlagStatusGet(HT_TMR0, TMR_TMRIF_CCSTA);
			
				#endif
			
        HT_TMR_ClearITPendingBit(HT_TMR0, TMR_TMRIF_CAPIF);                    /*!< Clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR0, TMR_TMRIF_CMPIF))                /*!< compare   interrupt        */
    {

        HT_TMR_ClearITPendingBit(HT_TMR0, TMR_TMRIF_CMPIF);                    /*!< Clear interrupt flag       */
    }
		
		#if defined USE_TMR_ACIF

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR0, TMR_TMRIF_ACIF))                /*!< Event Record   interrupt        */
    {
        HT_TMR_ClearITPendingBit(HT_TMR0, TMR_TMRIF_ACIF);                    /*!< Clear interrupt flag       */
    }
		
		#endif

#endif
}

/*
*********************************************************************************************************
*                                   TIMER_1 INTERRUPT HANDLER  #16+16
*
*********************************************************************************************************
*/

void TIMER_1_IRQHandler(void)
{
#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

    HT_TMR_IRQHandler(&TimHandle);
    
#else

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR1, TMR_TMRIF_PRDIF))                /*!< Cycle interrupt flag set           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR1, TMR_TMRIF_PRDIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR1, TMR_TMRIF_CAPIF))                /*!< Capture interrupt flag set           */
    {
				#if defined USE_TMR_CCSTA
			
        uint16_t CCSTAVal = HT_TMR_ITFlagStatusGet(HT_TMR1, TMR_TMRIF_CCSTA);
			
				#endif
			
        HT_TMR_ClearITPendingBit(HT_TMR1, TMR_TMRIF_CAPIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR1, TMR_TMRIF_CMPIF))                /*!< Compare interrupt flag set           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR1, TMR_TMRIF_CMPIF);                    /*!< clear interrupt flag       */
    }
		
		#if defined USE_TMR_ACIF

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR1, TMR_TMRIF_ACIF))                /*!< compare   interrupt        */
    {

        HT_TMR_ClearITPendingBit(HT_TMR1, TMR_TMRIF_ACIF);                    /*!< Clear interrupt flag       */
    }
		
		#endif

#endif
}

/*
*********************************************************************************************************
*                                   TIMER_2 INTERRUPT HANDLER  #16+17
*
*********************************************************************************************************
*/

void TIMER_2_IRQHandler(void)
{
#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

    HT_TMR_IRQHandler(&TimHandle);

#else

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR2, TMR_TMRIF_PRDIF))                /*!< Cycle interrupt flag set           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR2, TMR_TMRIF_PRDIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR2, TMR_TMRIF_CAPIF))                /*!< Capture interrupt flag set           */
    {
				#if defined USE_TMR_CCSTA
			
        uint16_t CCSTAVal = HT_TMR_ITFlagStatusGet(HT_TMR2, TMR_TMRIF_CCSTA);
			
				#endif

        HT_TMR_ClearITPendingBit(HT_TMR2, TMR_TMRIF_CAPIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR2, TMR_TMRIF_CMPIF))                /*!< Compare interrupt flag set           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR2, TMR_TMRIF_CMPIF);                    /*!< clear interrupt flag       */
    }
		
		#if defined USE_TMR_ACIF

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR2, TMR_TMRIF_ACIF))                /*!< Event record   interrupt        */
    {

        HT_TMR_ClearITPendingBit(HT_TMR2, TMR_TMRIF_ACIF);                    /*!< Clear interrupt flag       */
    }
		
		#endif

#endif
}

/*
*********************************************************************************************************
*                                   TIMER_3 INTERRUPT HANDLER  #16+18
*
*********************************************************************************************************
*/

void TIMER_3_IRQHandler(void)
{
#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

    HT_TMR_IRQHandler(&TimHandle);

#else

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR3, TMR_TMRIF_PRDIF))                /*!< Cycle interrupt flag set           */
    {
		HT_TMR3CallbackFun();
        HT_TMR_ClearITPendingBit(HT_TMR3, TMR_TMRIF_PRDIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR3, TMR_TMRIF_CAPIF))                /*!< Capture interrupt flag set           */
    {
				#if defined USE_TMR_CCSTA

        uint16_t CCSTAVal = HT_TMR_ITFlagStatusGet(HT_TMR3, TMR_TMRIF_CCSTA);

				#endif
			
        HT_TMR_ClearITPendingBit(HT_TMR3, TMR_TMRIF_CAPIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR3, TMR_TMRIF_CMPIF))                /*!< Compare interrupt flag set           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR3, TMR_TMRIF_CMPIF);                    /*!< clear interrupt flag       */
    }
		
		#if defined USE_TMR_ACIF

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR3, TMR_TMRIF_ACIF))                /*!< Event record    interrupt        */
    {

        HT_TMR_ClearITPendingBit(HT_TMR3, TMR_TMRIF_ACIF);                    /*!< Clear interrupt flag       */
    }
		
		#endif

#endif
}

/*
*********************************************************************************************************
*                                     TBS INTERRUPT HANDLER  #16+19
*
*********************************************************************************************************
*/

void TBS_IRQHandler(void)
{
	
#if (USE_HT_TBS_REGISTER_CALLBACKS == 1U)
	
		HT_TBS_IRQHandler(&TBSHandle);
	
#else

    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_TMPIF))                 /*!< Temperature measurement flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_TMPIF);                     /*!< clear interrupt flag          */
    }

	#if  !defined  USE_TBS_TBSIF_TDVREFIF
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VBATIF))                /*!< Battery measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VBATIF);                    /*!< clear interrupt flag          */
    }
	#else
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_TDVREFIF))              /*!< TDVREF interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_TDVREFIF);                  /*!< clear interrupt flag          */
    }
		
	#endif

    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC0IF))                /*!< ADC0 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC0IF);                    /*!< clear interrupt flag          */
    }

    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC1IF))                /*!< ADC1 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC1IF);                    /*!< clear interrupt flag          */
    }
    
	#if  !defined  USE_TBS_TBSIF_TDVREFIF
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VBATCMPIF))             /*!< battery voltage compare interrupt flag set     */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VBATCMPIF);                 /*!< clear interrupt flag          */
    }
		
	#else
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_TDVREFCMPIF))           /*!< TDVREFCMP interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_TDVREFCMPIF);               /*!< clear interrupt flag          */
    }
		
	#endif
    
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VCCIF))                 /*!< Power measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VCCIF);                     /*!< clear interrupt flag          */
    }
    
	#if defined USE_TBS_SOC 
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC2IF))                /*!< ADC2 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC2IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if defined  USE_TBS_VREF
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VREFIF))                /*!< VREF measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VREFIF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if defined  USE_TBS_TBSIF_ADC3
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC3IF))                /*!< ADC3 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC3IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if defined  USE_TBS_TBSIF_ADC4
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC4IF))                /*!< ADC4 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC4IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_TBSIF_ADC5
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC5IF))                /*!< ADC5 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC5IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_TBSIF_ADC6
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC6IF))                /*!< ADC6 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC6IF);                    /*!< clear interrupt flag          */
    }
		
    #endif    

    #if defined  USE_TBS_ADC0CMP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC0CMPIF))             /*!< ADC0CMP measurement interrupt flag set       */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC0CMPIF);                 /*!< clear interrupt flag          */
    }
		
    #endif

    #if defined  USE_TBS_SOC
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC1CMPIF))             /*!< ADC1CMP measurement interrupt flag set      */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC1CMPIF);                 /*!< clear interrupt flag          */
    }
		
    #endif
    
    #if  defined  USE_TBS_TBSIF_ADC7
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC7IF))                /*!< ADC7 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC7IF);                    /*!< clear interrupt flag          */
    }
		
    #endif    
    
    #if  defined  USE_TBS_TBSIF_ADC8
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC8IF))                /*!< ADC8 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC8IF);                    /*!< clear interrupt flag          */
    }
		
    #endif    
    
    #if  defined  USE_TBS_TBSIF_ADC9
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_ADC9IF))                /*!< ADC9 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC9IF);                    /*!< clear interrupt flag          */
    }
		
    #endif    

    #if  defined  USE_TBS_VTP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VTP0IF))                /*!< VTP0 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP0IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_VTP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VTP1IF))                /*!< VTP1 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP1IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_VTP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VTP2IF))                /*!< VTP2 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP2IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_VTP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VTP3IF))                /*!< VTP3 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP3IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_VTP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VTP4IF))                /*!< VTP4 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP4IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_VTP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VTP5IF))                /*!< VTP5 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP5IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_VTP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VTP6IF))                /*!< VTP6 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP6IF);                    /*!< clear interrupt flag          */
    }
		
    #endif

    #if  defined  USE_TBS_VTP
		
    if(SET == HT_TBS_ITFlagStatusGet(TBS_TBSIF_VTP7IF))                /*!< VTP7 measurement interrupt flag set          */
    {

        HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP7IF);                    /*!< clear interrupt flag          */
    }
		
	#endif
		
#endif
}

/*
*********************************************************************************************************
*                                    RTC INTERRUPT HANDLER  #16+20
*
*********************************************************************************************************
*/

void RTC_IRQHandler(void)
{
#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)

    HT_RTC_IRQHandler(&RtcHandle);

#else
	
    uint8_t Flag = HT_RTC->RTCIF;
    HT_RTC->RTCIF=0;                                               /*!< clear interrupt flag          */

    if(Flag & RTC_RTCIF_SECIF)                                     /*!< Second interrupt flag set          */
    {

    }

    if(Flag & RTC_RTCIF_MINIF)                                     /*!< Minute interrupt flag set          */
    {

    }

    if(Flag & RTC_RTCIF_HRIF)                                      /*!< Hour interrupt flag set            */
    {

    }

    if(Flag & RTC_RTCIF_DAYIF)                                     /*!< Day interrupt flag set              */
    {

    }

    if(Flag & RTC_RTCIF_MTHIF)                                     /*!< Month interrupt flag set             */
    {

    }

    if(Flag & RTC_RTCIF_RTC1IF)                                    /*!< RTC timer 1 interrupt flag set        */
    {

    }

    if(Flag & RTC_RTCIF_RTC2IF)                                    /*!< RTC timer 2 interrupt flag set       */
    {

    }

    if(Flag & RTC_RTCIF_ALMIF)                                     /*!< alarm clock interrupt flag set             */
    {

    }
    #if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01
    Flag = HT_RTC->RTCTS0IF;
    HT_RTC->RTCTS0IF = 0;
    if(Flag & RTC_RTCTSxIF_TSxOVIF)                                /*!< RTC STAMP0 Count Overflow interrupt flag set        */
    {

    }

    if(Flag & RTC_RTCTSxIF_TSxCMPIF)                              /*!< RTC STAMP0 Count Comparison interrupt flag set       */
    {

    }

    if(Flag & RTC_RTCTSxIF_TSxIF)                                 /*!< RTC STAMP0 Trigger interrupt flag set             */
    {

    }
        #if defined USE_RTC_RTCSTAMP01
        Flag = HT_RTC->RTCTS1IF;
        HT_RTC->RTCTS1IF = 0;
        if(Flag & RTC_RTCTSxIF_TSxOVIF)                                /*!< RTC STAMP1 Count Overflow interrupt flag set        */
        {

        }

        if(Flag & RTC_RTCTSxIF_TSxCMPIF)                              /*!< RTC STAMP1 Count Comparison interrupt flag set       */
        {

        }

        if(Flag & RTC_RTCTSxIF_TSxIF)                                 /*!< RTC STAMP1 Trigger interrupt flag set             */
        {

        }
        #endif
    #endif
#endif
}

/*
*********************************************************************************************************
*                                    I2C INTERRUPT HANDLER  #16+21
*
*********************************************************************************************************
*/

void I2C_IRQHandler(void)
{
    #if (USE_HT_I2C_REGISTER_CALLBACKS == 1U)

    HT_I2C_IRQHandler(&I2CHandle);

    #else

    HT_I2C_IRQHandler_Default();

    #endif
}

/*
*********************************************************************************************************
*                                    SPI0 INTERRUPT HANDLER  #16+22
*
*********************************************************************************************************
*/

void SPI0_IRQHandler(void)
{
#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)

    HT_SPI_IRQHandler(&SpiHandle);

#else
	
    if(SET == HT_SPI_ITFlagStatusGet(HT_SPI0,SPI_SPISTA_MODF))                 /*!< SPI0 mode fault flag set     */
    {

        HT_SPI_ClearITPendingBit(HT_SPI0, SPI_SPISTA_MODF);                    /*!< clear interrupt flag          */
    }

    if(SET == HT_SPI_ITFlagStatusGet(HT_SPI0, SPI_SPISTA_SPIF))                /*!< SPI0 data transfer completion flag set */
    {

        HT_SPI_ClearITPendingBit(HT_SPI0, SPI_SPISTA_SPIF);                    /*!< clear interrupt flag          */
    }
		
#endif
}

/*
*********************************************************************************************************
*                                  WDT/SPI1 INTERRUPT HANDLER  #16+23
*
*********************************************************************************************************
*/

#if defined  HT6x1x

void WDT_IRQHandler(void)
{
    #if (USE_HT_WDT_REGISTER_CALLBACKS == 1U)

    HT_WDT_IRQHandler(&WdtHandle);

    #endif
}

#elif defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  || defined HT762x ||  defined  HT772x  ||  defined HT503x  ||  defined HT633x

void SPI1_IRQHandler()
{
    #if (USE_HT_SPI_REGISTER_CALLBACKS == 1)

    HT_SPI_IRQHandler(&SpiHandle);

    #else
	
    if(SET == HT_SPI_ITFlagStatusGet(HT_SPI1,SPI_SPISTA_MODF))                 /*!< SPI1 mode fault flag set     */
    {

        HT_SPI_ClearITPendingBit(HT_SPI1, SPI_SPISTA_MODF);                    /*!< clear interrupt flag          */
    }

    if(SET == HT_SPI_ITFlagStatusGet(HT_SPI1, SPI_SPISTA_SPIF))                /*!< SPI1 data transfer completion flag set */
    {

        HT_SPI_ClearITPendingBit(HT_SPI1, SPI_SPISTA_SPIF);                    /*!< clear interrupt flag          */
    }
		
	#endif	
}

#endif

/*
*********************************************************************************************************
*                                 FREQ TEST INTERRUPT HANDLER  #16+24
*
*********************************************************************************************************
*/

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT633x  ||  defined  HT6x2xK  ||  defined HT762x ||  defined  HT772x

void SelfTestFreq_IRQHandler(void)
{

}

#endif

/*
*********************************************************************************************************
*                               TIMER_4/EMU INTERRUPT HANDLER  #16+25
*
*********************************************************************************************************
*/

#if defined  USE_TMRExt_IRQHANDLER || defined USE_TMR4_IRQHANDLER

void TIMER_4_IRQHandler(void)
{
	#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)
    
        #if defined USE_TMR4_IRQHANDLER
        
        HT_TMR_IRQHandler(&TimHandle);
    
        #elif defined USE_TMR_EXT

        HT_TMRExt_IRQHandler(&TimExtHandle);
        
        #endif
    
	#else

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR4, TMR_TMRIF_PRDIF))                /*!< Cycle interrupt flag set           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR4, TMR_TMRIF_PRDIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR4, TMR_TMRIF_CAPIF))                /*!< Capture interrupt flag set           */
    {

		#if defined USE_TMREXT_CCSTA
			
        uint16_t CCSTAVal = HT_TMR_ITFlagStatusGet(HT_TMR4, TMR_TMRIF_CCSTA);
			
		#endif

        HT_TMR_ClearITPendingBit(HT_TMR4, TMR_TMRIF_CAPIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR4, TMR_TMRIF_CMPIF))                /*!< Compare interrupt flag set */
    {

        HT_TMR_ClearITPendingBit(HT_TMR4, TMR_TMRIF_CMPIF);                    /*!< clear interrupt flag       */
    }
		
		#if defined USE_TMR_ACIF

        if(SET == HT_TMR_ITFlagStatusGet(HT_TMR4, TMR_TMRIF_ACIF))             /*!< Event record    interrupt  */
        {

            HT_TMR_ClearITPendingBit(HT_TMR4, TMR_TMRIF_ACIF);                 /*!< Clear interrupt flag       */
        }
		
		#endif

		#if defined USE_TMREXT_TRIG

        if(SET == HT_TMR_ITFlagStatusGet(HT_TMR4, TMR_TMRIF_TRIGIF))            /*!< TRIGGER   interrupt       */
        {
                
            HT_TMR_ClearITPendingBit(HT_TMR4, TMR_TMRIF_TRIGIF);                /*!< Clear interrupt flag      */
        }

		#endif
		
	#endif
}

#elif defined HT501x || defined HT502x || defined HT503x 

void EMU_IRQHandler(void)
{
	#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
	
	HT_EMU_IRQHandler(&EmuHandle);
	
	#else
	
	#endif
}

#endif

/*
*********************************************************************************************************
*                               TIMER_5/DMA INTERRUPT HANDLER  #16+26
*
*********************************************************************************************************
*/

#if defined  USE_TMRExt_IRQHANDLER

void TIMER_5_IRQHandler(void)
{
	#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

		#if defined USE_TMR_EXT
	
        HT_TMRExt_IRQHandler(&TimExtHandle);
	
		#endif

	#else

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR5, TMR_TMRIF_PRDIF))                /*!< Cycle interrupt flag set           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR5, TMR_TMRIF_PRDIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR5, TMR_TMRIF_CAPIF))                /*!< Capture interrupt flag set           */
    {
				#if defined USE_TMREXT_CCSTA
			
        uint16_t CCSTAVal = HT_TMR_ITFlagStatusGet(HT_TMR5, TMR_TMRIF_CCSTA);
			
				#endif
			
        HT_TMR_ClearITPendingBit(HT_TMR5, TMR_TMRIF_CAPIF);                    /*!< clear interrupt flag       */
    }

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR5, TMR_TMRIF_CMPIF))                /*!< Compare interrupt flag set           */
    {

        HT_TMR_ClearITPendingBit(HT_TMR5, TMR_TMRIF_CMPIF);                    /*!< clear interrupt flag       */
    }

		#if defined USE_TMR_ACIF

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR5, TMR_TMRIF_ACIF))                /*!< Event record    interrupt        */
    {

        HT_TMR_ClearITPendingBit(HT_TMR5, TMR_TMRIF_ACIF);                    /*!< Clear interrupt flag       */

    }
		
		#endif

		#if defined USE_TMREXT_TRIG

    if(SET == HT_TMR_ITFlagStatusGet(HT_TMR5, TMR_TMRIF_TRIGIF))                /*!< TRIGGER   interrupt        */
    {
        HT_TMR_ClearITPendingBit(HT_TMR5, TMR_TMRIF_TRIGIF);                    /*!< Clear interrupt flag       */
    }

		#endif

	#endif
}

#elif defined HT501x || defined HT502x || defined HT503x 

void DMA_IRQHandler(void)
{
	
		#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
	
		HT_DMA_IRQHandler(&DmaHandle);

		#else	
	
		DMA_IRQProc();
	
		#endif
	
}

#endif

/*
*********************************************************************************************************
*                               UART6/KEY INTERRUPT HANDLER  #16+27
*
*********************************************************************************************************
*/

#if defined	USE_UART6_IT

void UART6_IRQHandler(void)
{
		#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
	
		if(SET == READ_BIT(HT_UART6->IRCON, UART_IRCON_IRTX))
		{	
				HT_UART_IRQHandler(&IRHandle.UARTModule);
		}
		else
		{
			HT_UART_IRQHandler(&UartHandle);
		}
		
		#else
		
    if(SET == HT_UART_ITFlagStatusGet(HT_UART6, UART_UARTSTA_TXIF))         /*!< UART6 send interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART6, UART_UARTSTA_TXIF);             /*!< clear interrupt flag          */
    }

    if(SET == HT_UART_ITFlagStatusGet(HT_UART6, UART_UARTSTA_RXIF))         /*!< UART6 receive interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART6, UART_UARTSTA_RXIF);             /*!< clear interrupt flag          */
    }
		
		#endif
}

#elif defined USE_KEYSCAN 

void KEY_IRQHandler(void)
{
		#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
	
    HT_KEY_IRQHandler(&KeyHandle);
	
		#else

		if (HT_KEY_ITFlagStatusGet(KEY_KEYIF) != RESET)
		{
			
			HT_KEY_ClearITPendingBit(KEY_KEYIF);             /*!< clear interrupt flag          */
		}
		
		#endif
}

#endif

/*
*********************************************************************************************************
*                                 EXTI7 INTERRUPT HANDLER  #16+28
*
*********************************************************************************************************
*/

#if defined USE_EXTI7_9_SINGLEIRQHANDLER

void EXTI7_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT7))         /*!< INT7 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT7);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT7))         /*!< INT7 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT7);             /*!< clear interrupt flag             */
    }
		
		#endif
}

#elif defined USE_EXTI7_9_COMMONIRQHANDLER

void EXTI7_9_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else

    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT7))         /*!< INT7 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT7);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT7))         /*!< INT7 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT7);             /*!< clear interrupt flag             */
    }


    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT8))         /*!< INT8 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT8);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT8))         /*!< INT8 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT8);             /*!< clear interrupt flag             */
    }


    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT9))         /*!< INT9 rising edge interrupt flag  set         */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT9);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT9))         /*!< INT9 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT9);             /*!< clear interrupt flag             */
    }
		
		#endif
}

#endif


/*
*********************************************************************************************************
*                                 EXTI8 INTERRUPT HANDLER  #16+29
*
*********************************************************************************************************
*/

#if defined USE_EXTI7_9_SINGLEIRQHANDLER

void EXTI8_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT8))         /*!< INT8 rising edge interrupt flag  set          */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT8);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT8))         /*!< INT8 falling edge interrupt flag set           */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT8);             /*!< clear interrupt flag             */
    }
		
		#endif
		
}

#elif defined  HT503x

void UART6_IRQHandler(void)
{
		#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
		
		 if(SET == READ_BIT(HT_UART6->IRCON, UART_IRCON_IRTX))
		{	
				HT_UART_IRQHandler(&IRHandle.UARTModule);
		}
		 else
		{
			HT_UART_IRQHandler(&UartHandle);
		}
		
		#else
	
    if(SET == HT_UART_ITFlagStatusGet(HT_UART6, UART_UARTSTA_TXIF))         /*!< UART6 send interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART6, UART_UARTSTA_TXIF);             /*!< clear interrupt flag          */
    }

    if(SET == HT_UART_ITFlagStatusGet(HT_UART6, UART_UARTSTA_RXIF))         /*!< UART6 receive interrupt flag set         */
    {

        HT_UART_ClearITPendingBit(HT_UART6, UART_UARTSTA_RXIF);             /*!< clear interrupt flag          */

    }
		
		#endif
}

#endif


#if defined  HT762x ||  defined  HT772x || defined  HT633x || defined HT6x2xK

void SPI3_IRQHandler(void)
{
		#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
	
		HT_SPI_IRQHandler(&SpiHandle);
	
		#else
	
		if(SET == HT_SPI_ITFlagStatusGet(HT_SPI3,SPI_SPISTA_MODF))          /*!< SPI3 mode fault flag set    */
    {

        HT_SPI_ClearITPendingBit(HT_SPI3, SPI_SPISTA_MODF);             /*!< clear interrupt flag          */
    }

    if(SET == HT_SPI_ITFlagStatusGet(HT_SPI3, SPI_SPISTA_SPIF))         /*!< SPI3 data transfer completion flag set */
    {

        HT_SPI_ClearITPendingBit(HT_SPI3, SPI_SPISTA_SPIF);             /*!< clear interrupt flag          */
    }	
		
		#endif
}

#endif


/*
*********************************************************************************************************
*                                 EXTI9/SPI INTERRUPT HANDLER  #16+30
*
*********************************************************************************************************
*/

#if defined USE_EXTI7_9_SINGLEIRQHANDLER

void EXTI9_IRQHandler(void)
{
		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT9))         /*!< INT9 rising edge interrupt flag  set         */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT9);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT9))         /*!< INT9 Falling edge interrupt flag  set         */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT9);             /*!< clear interrupt flag             */
    }
		
		#endif
}

#elif  defined  HT6x3x || defined  HT762x ||  defined  HT772x  ||  defined  HT503x  ||  defined  HT633x

void SPI2_IRQHandler(void)
{
		#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
	
		HT_SPI_IRQHandler(&SpiHandle);
	
		#else	
	
    if(SET == HT_SPI_ITFlagStatusGet(HT_SPI2,SPI_SPISTA_MODF))          /*!< SPI2 mode fault flag set    */
    {

        HT_SPI_ClearITPendingBit(HT_SPI2, SPI_SPISTA_MODF);             /*!< clear interrupt flag          */
    }

    if(SET == HT_SPI_ITFlagStatusGet(HT_SPI2, SPI_SPISTA_SPIF))         /*!< SPI2 data transfer completion flag set */
    {

        HT_SPI_ClearITPendingBit(HT_SPI2, SPI_SPISTA_SPIF);             /*!< clear interrupt flag          */
    }
		
		#endif
}

#endif


#if defined USE_EXTI10_14

void EXTI10_14_IRQHandler(void)
{

		#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
	
    HT_EXTI_IRQHandler(&ExtiHandle);
	
		#else
	
    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT10))         /*!< INT10 rising edge interrupt flag  set         */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT10);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT10))         /*!< INT10 Falling edge interrupt flag  set         */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT10);             /*!< clear interrupt flag             */
    }


    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT11))         /*!< INT11 rising edge interrupt flag  set         */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT11);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT11))         /*!< INT11 Falling edge interrupt flag  set         */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT11);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT12))         /*!< INT12 rising edge interrupt flag  set         */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT12);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT12))         /*!< INT12 Falling edge interrupt flag  set         */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT12);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT13))         /*!< INT13 rising edge interrupt flag  set         */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT13);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT13))         /*!< INT13 Falling edge interrupt flag  set         */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT13);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIRise_ITFlagStatusGet(INT_EXTIF2_RIF_INT14))         /*!< INT14 rising edge interrupt flag  set         */
    {

        HT_EXTIRise_ClearITPendingBit(INT_EXTIF2_RIF_INT14);             /*!< clear interrupt flag             */
    }

    if(SET == HT_EXTIFall_ITFlagStatusGet(INT_EXTIF2_FIF_INT14))         /*!< INT14 Falling edge interrupt flag  set         */
    {

        HT_EXTIFall_ClearITPendingBit(INT_EXTIF2_FIF_INT14);             /*!< clear interrupt flag             */
    }
		
		#endif
}

#endif


/*
*********************************************************************************************************
*                                 DMA INTERRUPT HANDLER  #16+31
*
*********************************************************************************************************
*/

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK ||  defined  HT762x ||  defined  HT772x  ||  defined  HT633x

void DMA_IRQHandler(void)
{
	#if (USE_HT_DMA_REGISTER_CALLBACKS == 1U)
	
		HT_DMA_IRQHandler(&DmaHandle);
	
		#if defined  USE_DMA_Channel12	
	
		HT_DMA_CH12_IRQHandler(&DmaCh12Handle);
	
		#endif 
	#else	
	
		DMA_IRQProc(); 
	
	#endif
}
#endif

#if  defined  HT503x

void FRAM_IRQHandler(void)
{
	#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
	
	HT_EMUIFACE_IRQHandler(&EmuIfaceHandle);
  
	#else
	
		if(SET == HT_EMUIFACE_ITFlagStatusGet(EMUIFACE_NIS_IF))
	{
				HT_EMUIFACE_ClearITPendingBit(EMUIFACE_NIS_IF);
	}
	
	#endif
	
	#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)	
	
	HT_FRAMPACK_IRQHandler(&FrampackHandle);
	
	#else
	
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_ENDIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_ENDIF);
		}
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_HEADIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_HEADIF);
		}
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_FIFOFULLIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FIFOFULLIF);
		}
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_FIFOEMPTYIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FIFOEMPTYIF);
		}
		if(SET == HT_FRAMPACK_ITFlagStatusGet(FRAMPACK_FRAMIF_FRAM_DONEIF))
		{
				HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FRAM_DONEIF);
		}
	
	#endif
}

#endif


