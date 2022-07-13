/*
*********************************************************************************************************
*                                              HT7X2X
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT7x2x
* File         : ht7x2x_frampack.c
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_FRAMPACK_C

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
#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)
static void FRAMPACK_InitCallbacksToDefault(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
static void FRAMPACK_END_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
static void FRAMPACK_HEAD_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
static void FRAMPACK_FIFOFULL_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
static void FRAMPACK_FIFOEMPTY_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
static void FRAMPACK_AUTODONE_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
#endif



/**
*********************************************************************************************************
*                                         INITIAL FRAMPACK MODULE
* @brief:   FRAMPACK initial
*
* @param:   FRAMPACK_InitStruct    pointer to the Initial structure 
*                               1) SPI_Select       FRAMPACK SPI Select
*                                                   @arg PACK_Sel_SPI1 (FRAMPACK_SPISEL_SPI1)
*                                                   @arg PACK_Sel_SPI2 (FRAMPACK_SPISEL_SPI2)
*                               2) Data_Endian      FRAMPACK data endian big/small
*                                                   @arg PACK_DataEndian_Small (FRAMPACK_ENDIAN_SMALL)
*                                                   @arg PACK_DataEndian_Big   (FRAMPACK_ENDIAN_BIG)
*                              3) Chn_Number        FRAMPACK data out put channel number 1/2/3
*                                                   @arg PACK_ChnNum1 (FRAMPACK_CHNNUM_1)
*                                                   @arg PACK_ChnNum2 (FRAMPACK_CHNNUM_2)
*                                                   @arg PACK_ChnNum3 (FRAMPACK_CHNNUM_3)
*                              4) Data_BitWide      FRAMPACK data 16/24 bit 
*                                                   @arg PACK_BitWide_16bits (FRAMPACK_BITWIDE_16BITS)
*                                                   @arg PACK_BitWide_24bits (FRAMPACK_BITWIDE_24BITS)
*                              5) Data_Outdelay     FRAMPACK data output delay 0/1/2/3 clk
*                                                   @arg PACK_OutDelay_None  (FRAMPACK_DATAOUTDLY_NONE)
*                                                   @arg PACK_OutDelay_1clk  (FRAMPACK_DATAOUTDLY_1CLK)
*                                                   @arg PACK_OutDelay_2clk  (FRAMPACK_DATAOUTDLY_2CLK)
*                                                   @arg PACK_OutDelay_3clk  (FRAMPACK_DATAOUTDLY_3CLK)
*                              6) FramID_Lenth      FRAMPACK FRAMID length 1/2 BYTE 
*                                                   @arg PACK_ID_Length_1Byte  (FRAMPACK_FRAMID_1BYTE)
*                                                   @arg PACK_ID_Length_2Byte  (FRAMPACK_FRAMID_2BYTE)
*                              7) FramID_Location   FRAMPACK FRAMID Location num
*                                                   @arg Location PACK_ID_Location_0~15
*                              8) HeadA_Length      FRAMPACK HEADA length 1~16
*                              9) HeadB_Length      FRAMPACK HEADB length 1~16
*                             10) EmuData_SampleNum FRAMPACK EMU data sample num 0~0xFFFF
*                             11) Fram_Delay        FRAMPACK fram delay 0~0xFFFF
*                             12) Fram_AutoNum      FRAMPACK fram auto send number 0~0xFFFF
*                             13) FramHeadA[4]      FRAMPACK fram A config
*                             14) FramHeadB[4]      FRAMPACK fram B config
*                             15) FramStopF         FRAMPACK stop byte config
*                             16) CRC_Select        FRAMPACK CRC Select CRC/CHECKSUM
*                                                   @arg PACK_CRCSel_Checksum
*                                                   @arg PACK_CRCSel_Crc
*                             17) CRC_Mode          FRAMPACK CRC Mode CRC16(1021)/CRC16(8005)/CRC32 
*                                                   @arg PACK_CRCMode_Crc16_1021
*                                                   @arg PACK_CRCMode_Crc16_8005
*                                                   @arg PACK_CRCMode_Crc32     
*                             18) CRC_Length        FRAMPACK CRC Select CRC/CHECKSUM
*                                                   @arg PACK_CLEN_1byte
*                                                   @arg PACK_CLEN_2byte
*                                                   @arg PACK_CLEN_4byte
*                             19) CRC_RefIn         FRAMPACK CRC data input Reverse ENABLE/DISABLE 
*                                                   @arg PACK_CRC_RefIn_Normal 
*                                                   @arg PACK_CRC_RefIn_Reverse
*                             20) CRC_RefOut        FRAMPACK CRC data output Reverse ENABLE/DISABLE
*                                                   @arg PACK_CRC_RefOut_Normal 
*                                                   @arg PACK_CRC_RefOut_Reverse
*                             21) CRC_XorOut        FRAMPACK CRC data output Xor ENABLE/DISABLE 
*                                                   @arg PACK_CRC_XorOut_Normal 
*                                                   @arg PACK_CRC_XorOut_Reverse
*                             22) CRC_Endian        FRAMPACK CRC data endian big/small 
*                                                   @arg PACK_CRC_Endian_Small
*                                                   @arg PACK_CRC_Endian_Big  
*                             23) CRC_InitSeed      FRAMPACK CRC Initial seed
*
* @retval:  None                                                             
*
*********************************************************************************************************
*/
StatusTypeDef HT_FRAMPACK_Init(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
	StatusTypeDef status = OK;
	
	if(FRAMPACK_InitStruct == NULL)
	{
		status = ERROR;
	}
	else
	{
		HT_FRAMPACK_DISABLE();
		HT_FRAMPACK_CLR_ABORT();
    
		assert_param(IS_HT_FRAMPACK_CRC_SELECT(FRAMPACK_InitStruct->CRC_Select));
		assert_param(IS_HT_FRAMPACK_CRC_MODE(FRAMPACK_InitStruct->CRC_Mode));
		assert_param(IS_HT_FRAMPACK_CRC_LENGTH(FRAMPACK_InitStruct->Check_Length));
		assert_param(IS_HT_FRAMPACK_CRC_REFIN(FRAMPACK_InitStruct->CRC_RefIn));
		assert_param(IS_HT_FRAMPACK_CRC_REFOUT(FRAMPACK_InitStruct->CRC_RefOut));
		assert_param(IS_HT_FRAMPACK_CRC_XOROUT(FRAMPACK_InitStruct->CRC_XorOut));
		assert_param(IS_HT_FRAMPACK_CRC_ENDIAN(FRAMPACK_InitStruct->CRC_Endian));
		/*	config FCRCCFG	*/
		HT_FRAMPACK->FCRCCFG = ((FRAMPACK_InitStruct->CRC_Select	&	FRAMPACK_FCRCCFG_CRCSEL_Mask) 	|\
                            (FRAMPACK_InitStruct->CRC_Mode		&	FRAMPACK_FCRCCFG_CRC_MODE_Mask) |\
                            (FRAMPACK_InitStruct->Check_Length&	FRAMPACK_FCRCCFG_CLEN_SEL_Mask) |\
                            (FRAMPACK_InitStruct->CRC_RefIn   &	FRAMPACK_FCRCCFG_REFIN_Mask) 		|\
                            (FRAMPACK_InitStruct->CRC_RefOut  &	FRAMPACK_FCRCCFG_REFOUT_Mask) 	|\
                            (FRAMPACK_InitStruct->CRC_XorOut	&	FRAMPACK_FCRCCFG_XOROUT_Mask) 	|\
                            (FRAMPACK_InitStruct->CRC_Endian	&	FRAMPACK_FCRCCFG_CHECK_ENDSEL_Mask) );
		/*	config FCRCINIT	*/
		HT_FRAMPACK->FCRCINIT = FRAMPACK_InitStruct->CRC_InitSeed;
    
		assert_param(IS_HT_FRAMPACK_HEADA_LENGTH(FRAMPACK_InitStruct->HeadA_Length));
		assert_param(IS_HT_FRAMPACK_HEADB_LENGTH(FRAMPACK_InitStruct->HeadB_Length));
		/*	config HLCFG	*/
		HT_FRAMPACK->HLCFG = ((((FRAMPACK_InitStruct->HeadA_Length-1) << FRAMPACK_HLCFG_HEADA_Pos)	&	FRAMPACK_HLCFG_HEADA_Mask) |\
													((FRAMPACK_InitStruct->HeadB_Length-1)	&	FRAMPACK_HLCFG_HEADB_Mask));
		
		assert_param(IS_HT_FRAMPACK_EMUDATA_SAMPLENUM(FRAMPACK_InitStruct->EmuData_SampleNum));
		/*	config SAMPNUM	*/
		HT_FRAMPACK->SAMPNUM = FRAMPACK_InitStruct->EmuData_SampleNum;
		
		assert_param(IS_HT_FRAMPACK_FRAMID_LENGTH(FRAMPACK_InitStruct->FramID_Lenth));
		assert_param(IS_HT_FRAMPACK_FRAMID_LOCATION(FRAMPACK_InitStruct->FramID_Location));
		/*	config IDCFG	*/
		HT_FRAMPACK->IDCFG = ((FRAMPACK_InitStruct->FramID_Lenth	   & FRAMPACK_IDCFG_ID_SEL_Mask) |\
													(FRAMPACK_InitStruct->FramID_Location  & FRAMPACK_IDCFG_ID_ADDR_Mask));
		
		assert_param(IS_HT_FRAMPACK_FRAM_ID(FRAMPACK_InitStruct->Fram_ID));
		/*	config FRAMIDR	*/
		HT_FRAMPACK->FRAMIDR = FRAMPACK_InitStruct->Fram_ID;
		
		assert_param(IS_HT_FRAMPACK_FRAM_DELAY(FRAMPACK_InitStruct->Fram_Delay));
		/*	config FDLY	*/
		HT_FRAMPACK->FDLY = FRAMPACK_InitStruct->Fram_Delay;
		
		assert_param(IS_HT_FRAMPACK_FRAM_AUTONUM(FRAMPACK_InitStruct->Fram_AutoNum));
		/*	config FAUTONUM	*/
		HT_FRAMPACK->FAUTONUM = FRAMPACK_InitStruct->Fram_AutoNum;
		
        /* config Fram Head A */
        HT_FRAMPACK->HEADA0 = FRAMPACK_InitStruct->FramHeadA[0];
        HT_FRAMPACK->HEADA1 = FRAMPACK_InitStruct->FramHeadA[1];
        HT_FRAMPACK->HEADA2 = FRAMPACK_InitStruct->FramHeadA[2];
        HT_FRAMPACK->HEADA3 = FRAMPACK_InitStruct->FramHeadA[3];
        /* config Fram Head B */
        HT_FRAMPACK->HEADB0 = FRAMPACK_InitStruct->FramHeadB[0];
        HT_FRAMPACK->HEADB1 = FRAMPACK_InitStruct->FramHeadB[1];
        HT_FRAMPACK->HEADB2 = FRAMPACK_InitStruct->FramHeadB[2];
        HT_FRAMPACK->HEADB3 = FRAMPACK_InitStruct->FramHeadB[3];
        /* config Fram STOPF */
        HT_FRAMPACK->STOPF = FRAMPACK_InitStruct->FramStopF;
       
		assert_param(IS_HT_FRAMPACK_SPI_SELECT(FRAMPACK_InitStruct->SPI_Select));
		assert_param(IS_HT_FRAMPACK_DATA_ENDIAN(FRAMPACK_InitStruct->Data_Endian));
		assert_param(IS_HT_FRAMPACK_CHN_NUMBER(FRAMPACK_InitStruct->Chn_Number));
		assert_param(IS_HT_FRAMPACK_DATA_BITWIDE(FRAMPACK_InitStruct->Data_BitWide));
		assert_param(IS_HT_FRAMPACK_DATA_OUTDELAY(FRAMPACK_InitStruct->Data_Outdelay));
		/*	config FRAMCON	*/
		HT_FRAMPACK->FRAMCON = ((FRAMPACK_InitStruct->SPI_Select	& FRAMPACK_SPISEL_Mask) |\
                                (FRAMPACK_InitStruct->Data_Endian   & FRAMPACK_ENDSEL_Mask) |\
                                (FRAMPACK_InitStruct->Chn_Number    & FRAMPACK_COMSEL_Mask) |\
                                (FRAMPACK_InitStruct->Data_BitWide  & FRAMPACK_SDACFG_Mask) |\
                                (FRAMPACK_InitStruct->Data_Outdelay & FRAMPACK_DATAOUTDLY_Mask));
		
	#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)
		FRAMPACK_InitCallbacksToDefault(FRAMPACK_InitStruct);
		FRAMPACK_InitStruct->Instance = HT_FRAMPACK;
	#endif
  
        HT_FRAMPACK_ENABLE();
	}
	return status;
}


/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE FRAMPACK INTERRUPT
*
* @brief:   enable or disable FRAMPACK interrupt
*
* @param:   ITEn       FRAMPACK interrupt set, it can be one or a combination of the following parameters:
*                      @arg FRAMPACK_FRAMIE_ENDIE
*                      @arg FRAMPACK_FRAMIE_HEADIE
*                      @arg FRAMPACK_FRAMIE_FIFOFULLIE
*                      @arg FRAMPACK_FRAMIE_FIFOEMPTYIE
*                      @arg FRAMPACK_FRAMIE_FRAM_DONEIE
*
*           NewState   = ENABLE: enable interrupt
*                      = DISABLE:disable interrupt
* @retval:  none
*
*********************************************************************************************************
*/
void HT_FRAMPACK_ITConfig(uint32_t ITEn,FunctionalState NewState)
{
	assert_param(IS_HT_FRAMPACK_IE(ITEn));
	if(NewState != DISABLE)
	{
		HT_FRAMPACK->FRAMIE |= (ITEn & FRAMPACK_FRAMIE);
	}
	else
	{
		HT_FRAMPACK->FRAMIE &= ~ITEn;
	}
}

/**
*********************************************************************************************************
*                            GET SPECIFIED FRAMPACK INTERRUPT FLAG STATUS
*
* @brief:   get FRAMPACK interrupt flag status
*
* @param:   ITFlag     FRAMPACK interrupt flag check, it can be one or a combination of the following parameters:
*                      @arg FRAMPACK_FRAMIF_ENDIF      
*                      @arg FRAMPACK_FRAMIF_HEADIF     
*                      @arg FRAMPACK_FRAMIF_FIFOFULLIF 
*                      @arg FRAMPACK_FRAMIF_FIFOEMPTYIF
*                      @arg FRAMPACK_FRAMIF_FRAM_DONEIF
*
* @retval:  ITStatus    = SET:  the interrupt flag produced
*                       = RESET:the interrupt flag not produced
*
*********************************************************************************************************
*/
ITStatus HT_FRAMPACK_ITFlagStatusGet(uint32_t ITFlag)
{
	FlagStatus status = RESET;
	assert_param(IS_HT_FRAMPACK_IF(ITFlag));
    if (HT_FRAMPACK->FRAMIF & ITFlag)
    {
        status = SET;                       
    }
    else
    {
        status = RESET;                     
    }
    return status;
}

/**
*********************************************************************************************************
*                                CLEAR FRAMPACK INTERRUPT FLAG
*
* @brief:   clear FRAMPACK interrupt flag
*
* @param:   ITFlag     FRAMPACK interrupt flag clear,It can be one or a combination of the following parameters:
*                      @arg FRAMPACK_FRAMIF_ENDIF      
*                      @arg FRAMPACK_FRAMIF_HEADIF     
*                      @arg FRAMPACK_FRAMIF_FIFOFULLIF 
*                      @arg FRAMPACK_FRAMIF_FIFOEMPTYIF
*                      @arg FRAMPACK_FRAMIF_FRAM_DONEIF
*
* @retval:  none
*
*********************************************************************************************************
*/
void HT_FRAMPACK_ClearITPendingBit(uint32_t ITFlag)
{
    /*  assert_param  */
    assert_param(IS_HT_FRAMPACK_IF(ITFlag));
    HT_FRAMPACK->FRAMIF  = ~ITFlag;                  /*!< Clear FRAMPACK Interrupt Flag    */
}


#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)

/**
* @brief  Register a User FRAMPACK Callback
*         To be used instead of the weak predefined callback
* @param  FRAMPACK_InitStruct FRAMPACK handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*         @arg FRAMPACK_END_COMPLETE_CB_ID 
*         @arg FRAMPACK_HEAD_COMPLETE_CB_ID 
*         @arg FRAMPACK_FIFOFULL_COMPLETE_CB_ID 
*         @arg FRAMPACK_FIFOEMPTY_COMPLETE_CB_ID 
*         @arg FRAMPACK_AUTODONE_COMPLETE_CB_ID 
* @param  pCallback pointer to the Callback function
* @retval status
*/
StatusTypeDef HT_FRAMPACK_RegisterCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct, FRAMPACK_CallbackIDTypeDef CallbackID, pFRAMPACK_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        FRAMPACK_InitStruct->ErrorCode |= FRAMPACK_ERROR_INVALID_CALLBACK;
        /* return status */
        status = ERROR;
    }
    else
    {
        switch (CallbackID)
        {
            case FRAMPACK_END_COMPLETE_CB_ID :
                FRAMPACK_InitStruct->FrampackEndCpltCallback = pCallback;
            break;
			case FRAMPACK_HEAD_COMPLETE_CB_ID :
                FRAMPACK_InitStruct->FrampackHeadCpltCallback = pCallback;
            break;
			case FRAMPACK_FIFOFULL_COMPLETE_CB_ID :
                FRAMPACK_InitStruct->FrampackFifoFullCpltCallback = pCallback;
            break;
			case FRAMPACK_FIFOEMPTY_COMPLETE_CB_ID :
                FRAMPACK_InitStruct->FrampackFifoEmptyCpltCallback = pCallback;
            break;
			case FRAMPACK_AUTODONE_COMPLETE_CB_ID :
                FRAMPACK_InitStruct->FrampackAutoDoneCpltCallback = pCallback;
            break;
            default :
                /* Update the error code */
                FRAMPACK_InitStruct->ErrorCode |= FRAMPACK_ERROR_INVALID_CALLBACK;
                /* Return error status */
                status =  ERROR;
            break;
        }
    }
    return status;
}

/**
*********************************************************************************************************
*                                     INITIAL FRAMPACK CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: FRAMPACK_InitStruct Pointer to a FRAMPACK_InitTypeDef structure that contains
*               the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FRAMPACK_InitCallbacksToDefault(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
	FRAMPACK_InitStruct->FrampackEndCpltCallback        = HT_FRAMPACK_EndCpltCallback;
	FRAMPACK_InitStruct->FrampackHeadCpltCallback       = HT_FRAMPACK_HeadCpltCallback;
	FRAMPACK_InitStruct->FrampackFifoFullCpltCallback   = HT_FRAMPACK_FifoFullCpltCallback;
	FRAMPACK_InitStruct->FrampackFifoEmptyCpltCallback  = HT_FRAMPACK_FifoEmptyCpltCallback;
	FRAMPACK_InitStruct->FrampackAutoDoneCpltCallback   = HT_FRAMPACK_AutoDoneCpltCallback;
}

/**
*********************************************************************************************************
*                                       FRAMPACK END IT HANDLER
*
* @brief: This function handles END interrupt request
*
* @param: FRAMPACK_InitStruct Pointer to a FRAMPACK_InitTypeDef structure that contains
*               the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FRAMPACK_END_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
	if(FRAMPACK_InitStruct->FrampackEndCpltCallback != NULL)
	{
		FRAMPACK_InitStruct->FrampackEndCpltCallback(FRAMPACK_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                       FRAMPACK HEAD IT HANDLER
*
* @brief: This function handles HEAD interrupt request
*
* @param: FRAMPACK_InitStruct Pointer to a FRAMPACK_InitTypeDef structure that contains
*               the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FRAMPACK_HEAD_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
	if(FRAMPACK_InitStruct->FrampackHeadCpltCallback != NULL)
	{
		FRAMPACK_InitStruct->FrampackHeadCpltCallback(FRAMPACK_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                   FRAMPACK FIFOFULL IT HANDLER
*
* @brief: This function handles FIFOFULL interrupt request
*
* @param: FRAMPACK_InitStruct Pointer to a FRAMPACK_InitTypeDef structure that contains
*               the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FRAMPACK_FIFOFULL_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
	if(FRAMPACK_InitStruct->FrampackFifoFullCpltCallback != NULL)
	{
		FRAMPACK_InitStruct->FrampackFifoFullCpltCallback(FRAMPACK_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                  FRAMPACK FIFOEMPTY IT HANDLER
*
* @brief: This function handles FIFOEMPTY interrupt request
*
* @param: FRAMPACK_InitStruct Pointer to a FRAMPACK_InitTypeDef structure that contains
*               the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FRAMPACK_FIFOEMPTY_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
	if(FRAMPACK_InitStruct->FrampackFifoEmptyCpltCallback != NULL)
	{
		FRAMPACK_InitStruct->FrampackFifoEmptyCpltCallback(FRAMPACK_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                  FRAMPACK AUTODONE IT HANDLER
*
* @brief: This function handles AUTODONE interrupt request
*
* @param: FRAMPACK_InitStruct Pointer to a FRAMPACK_InitTypeDef structure that contains
*               the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FRAMPACK_AUTODONE_IT(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
	if(FRAMPACK_InitStruct->FrampackAutoDoneCpltCallback != NULL)
	{
		FRAMPACK_InitStruct->FrampackAutoDoneCpltCallback(FRAMPACK_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                   FRAMPACK IRQ HANDLER
*
* @brief: This function handles FRAMPACK interrupt request.
*
* @param: FRAMPACK_InitStruct  Pointer to a FRAMPACK_InitTypeDef structure that contains
*                the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_FRAMPACK_IRQHandler(FRAMPACK_InitTypeDef* FRAMPACK_InitStruct)
{
	uint32_t isrflags   = READ_REG(FRAMPACK_InitStruct->Instance->FRAMIF);
    uint32_t cr1its     = READ_REG(FRAMPACK_InitStruct->Instance->FRAMIE);
	
	if(((isrflags & FRAMPACK_FRAMIF_ENDIF) != RESET) && ((cr1its & FRAMPACK_FRAMIF_ENDIF) != RESET))
	{
		FRAMPACK_END_IT(FRAMPACK_InitStruct);
		HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_ENDIF);
	}
	if(((isrflags & FRAMPACK_FRAMIF_HEADIF) != RESET) && ((cr1its & FRAMPACK_FRAMIF_HEADIF) != RESET))
	{
		FRAMPACK_HEAD_IT(FRAMPACK_InitStruct);
		HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_HEADIF);
	}
	if(((isrflags & FRAMPACK_FRAMIF_FIFOFULLIF) != RESET) && ((cr1its & FRAMPACK_FRAMIF_FIFOFULLIF) != RESET))
	{
		FRAMPACK_FIFOFULL_IT(FRAMPACK_InitStruct);
        HT_FRAMPACK_ITConfig(FRAMPACK_FRAMIE_FIFOFULLIE,DISABLE);
		HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FIFOFULLIF);
	}
	if(((isrflags & FRAMPACK_FRAMIF_FIFOEMPTYIF) != RESET) && ((cr1its & FRAMPACK_FRAMIF_FIFOEMPTYIF) != RESET))
	{
		FRAMPACK_FIFOEMPTY_IT(FRAMPACK_InitStruct);
        HT_FRAMPACK_ITConfig(FRAMPACK_FRAMIE_FIFOEMPTYIE,DISABLE);
		HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FIFOEMPTYIF);
	}
	if(((isrflags & FRAMPACK_FRAMIF_FRAM_DONEIF) != RESET) && ((cr1its & FRAMPACK_FRAMIF_FRAM_DONEIF) != RESET))
	{
		FRAMPACK_AUTODONE_IT(FRAMPACK_InitStruct);
		HT_FRAMPACK_ClearITPendingBit(FRAMPACK_FRAMIF_FRAM_DONEIF);
	}
}

/**
*********************************************************************************************************
*                                     FRAMPACK END COMPLETE CALLBACK
*
* @brief: FRAMPACK END completed callbacks.
*
* @param: FRAMPACK  Pointer to a FRAMPACK_InitTypeDef structure that contains
*                   the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_FRAMPACK_EndCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(FRAMPACK_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_FRAMPACK_EndCpltCallback could be implemented in the user file
    */
}
/**
*********************************************************************************************************
*                                     FRAMPACK HEAD COMPLETE CALLBACK
*
* @brief: FRAMPACK HEAD completed callbacks.
*
* @param: FRAMPACK  Pointer to a FRAMPACK_InitTypeDef structure that contains
*                   the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_FRAMPACK_HeadCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(FRAMPACK_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_FRAMPACK_HeadCpltCallback could be implemented in the user file
    */
}
/**
*********************************************************************************************************
*                                     FRAMPACK FIFOFULL COMPLETE CALLBACK
*
* @brief: FRAMPACK FIFOFULL completed callbacks.
*
* @param: FRAMPACK  Pointer to a FRAMPACK_InitTypeDef structure that contains
*                   the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_FRAMPACK_FifoFullCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(FRAMPACK_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_FRAMPACK_FifoFullCpltCallback could be implemented in the user file
    */
}
/**
*********************************************************************************************************
*                                     FRAMPACK FIFOEMPTY COMPLETE CALLBACK
*
* @brief: FRAMPACK FIFOEMPTY completed callbacks.
*
* @param: FRAMPACK  Pointer to a FRAMPACK_InitTypeDef structure that contains
*                   the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_FRAMPACK_FifoEmptyCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(FRAMPACK_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_FRAMPACK_FifoEmptyCpltCallback could be implemented in the user file
    */
}
/**
*********************************************************************************************************
*                                     FRAMPACK AUTODONE COMPLETE CALLBACK
*
* @brief: FRAMPACK AUTODONE completed callbacks.
*
* @param: FRAMPACK  Pointer to a FRAMPACK_InitTypeDef structure that contains
*                   the configuration information for the specified FRAMPACK module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_FRAMPACK_AutoDoneCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(FRAMPACK_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_FRAMPACK_AutoDoneCpltCallback could be implemented in the user file
    */
}

#endif
