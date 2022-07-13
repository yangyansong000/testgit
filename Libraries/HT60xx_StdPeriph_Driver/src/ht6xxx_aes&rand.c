/*
*********************************************************************************************************
*                                              HT6XXXX
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6xxx_aes&rand.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  : Only support for chips used aes&rand Function.
*********************************************************************************************************
*/

#define  __HT6XXX_AES_RAND_C

#include <stdio.h>
#include "ht6xxx_lib.h"


#if defined USE_ARG
/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                             Local Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Local Function Declare
*********************************************************************************************************
*/


/**
*********************************************************************************************************
                                    INITIAL ARG MODULE
*
* @Brief  Initialize the ARG module 
*
* @Param  ARG_InitStruct: pointer to a ECC_InitTypeDef structure that configure 
*                         ARG callback
*                         
* @retval None
*
* Note:
********************************************************************************************************
**/
#if (USE_HT_ARG_REGISTER_CALLBACKS == 1U)
void HT_ARG_Init(ARG_InitTypeDef *ARG_Initstruct)
{
        /* assert_param */
	if(ARG_Initstruct != NULL)
    {
      ARG_Initstruct->AESInstance = HT_AES;
      ARG_Initstruct->GHASHInstance = HT_GHASH;
#if defined USE_RAND
      ARG_Initstruct->RANDInstance = HT_RAND;                   /*!< RAND registers base address    */
#endif
      ARG_InitCallbacksToDefault(ARG_Initstruct);
      
    }
}
#endif
/**
*********************************************************************************************************
*                                      AES Encrypt MODULE
*
* @brief  AES encryption  
*
* @param  AESKeyMode: Type of AES encyption mode
*                     KEY_Mode_128bits
*                     KEY_Mode_192bits
*                     KEY_Mode_256bits
* @param  pKeyAddr: Pointer to AES key bufffer, pKeyAddr[0] is MSB
*
* @param  pIntDataAddr: Pointer to the plaintext, bufferpIntDataAddr[0]is LSB
*
*
* @retval None 
*
*
********************************************************************************************************
**/
void HT_AES_Encrypt(AESKeyMode_TypeDef AESKeyMode, uint32_t *pKeyAddr, uint32_t *pIntDataAddr)
{
      /*  assert_param  */
      assert_param(IS_HT_AES_KEYMODE(AESKeyMode));
      if((pKeyAddr != NULL) && (pIntDataAddr != NULL))
      {
        if(AESKeyMode == KEY_Mode_128bits)
        {
          HT_AES->AESCON = ENCRYP_MODE_128BIT;      /*!< key-128bits, Encyption mode      */
          HT_AES->AESKEY0 = *pKeyAddr++;            /*!< Write key to register            */
          HT_AES->AESKEY1 = *pKeyAddr++;
          HT_AES->AESKEY2 = *pKeyAddr++;
          HT_AES->AESKEY3 = *pKeyAddr;
        }
        else if(AESKeyMode == KEY_Mode_192bits)
        {
          HT_AES->AESCON = ENCRYP_MODE_192BIT;      /*!< key-192bits,Encyption mode        */
          HT_AES->AESKEY0 = *pKeyAddr++;            /*!< Write key to register             */
          HT_AES->AESKEY1 = *pKeyAddr++;
          HT_AES->AESKEY2 = *pKeyAddr++;
          HT_AES->AESKEY3 = *pKeyAddr++;
          HT_AES->AESKEY4 = *pKeyAddr++;
          HT_AES->AESKEY5 = *pKeyAddr;
        }
        else if(AESKeyMode == KEY_Mode_256bits)
        {
          HT_AES->AESCON = ENCRYP_MODE_256BIT;      /*!< key-256bits,Encyption mode       */
          HT_AES->AESKEY0 = *pKeyAddr++;            /*!< Write key to register            */
          HT_AES->AESKEY1 = *pKeyAddr++;
          HT_AES->AESKEY2 = *pKeyAddr++;
          HT_AES->AESKEY3 = *pKeyAddr++;
          HT_AES->AESKEY4 = *pKeyAddr++;
          HT_AES->AESKEY5 = *pKeyAddr++;
          HT_AES->AESKEY6 = *pKeyAddr++;
          HT_AES->AESKEY7 = *pKeyAddr;
        }
        else
        {
        }

        HT_AES->AESINLL = *pIntDataAddr++;          /*!< Write Plan Data to register       */
        HT_AES->AESINML = *pIntDataAddr++;
        HT_AES->AESINHM = *pIntDataAddr++;
        HT_AES->AESINHH = *pIntDataAddr;

        HT_AES->AESSTR = CRYP_START;               /*!< Start  Encyption                  */

      }
		 	
	 
}

/**
*********************************************************************************************************
*                                      AES Decrypt MODULE
*
* @brief  AES Descryption Module
*
* @param  AESKeyMode: Type of Descrytion mode 
*                           KEY_Mode_128bits
*                           KEY_Mode_192bits
*                           KEY_Mode_256bits
* @param  pKeyAddr: Pointer to AES key, pKeyAddr[0] is MSB
*
* @param  pIntDataAddr: Pointer to the cyphertext， pIntDataAddr[0] is LSB
*
* @retval None
*
*********************************************************************************************************
**/
void HT_AES_Decrypt(AESKeyMode_TypeDef AESKeyMode, uint32_t *pKeyAddr, uint32_t *pIntDataAddr)
{
    /*  assert_param  */
    assert_param(IS_HT_AES_KEYMODE(AESKeyMode));
    if((pKeyAddr != NULL) && (pIntDataAddr != NULL))
    {
        if(AESKeyMode == KEY_Mode_128bits)
        {
          HT_AES->AESCON = DECRYP_MODE_128BIT;      /*!< key-128bits,Descryption Mode     */
          HT_AES->AESKEY0 = *pKeyAddr++;            /*!< Write Key to register            */
          HT_AES->AESKEY1 = *pKeyAddr++;
          HT_AES->AESKEY2 = *pKeyAddr++;
          HT_AES->AESKEY3 = *pKeyAddr;
        }
        else if(AESKeyMode == KEY_Mode_192bits)
        {
          HT_AES->AESCON = DECRYP_MODE_192BIT;      /*!< key-192bits,Descryption Mode      */
          HT_AES->AESKEY0 = *pKeyAddr++;            /*!< Write Key to register             */
          HT_AES->AESKEY1 = *pKeyAddr++;
          HT_AES->AESKEY2 = *pKeyAddr++;
          HT_AES->AESKEY3 = *pKeyAddr++;
          HT_AES->AESKEY4 = *pKeyAddr++;
          HT_AES->AESKEY5 = *pKeyAddr;
        }
        else if(AESKeyMode == KEY_Mode_256bits)
        {
        HT_AES->AESCON = DECRYP_MODE_256BIT;      /*!< key-256bits,Descryption          */
        HT_AES->AESKEY0 = *pKeyAddr++;            /*!< Write Key to register            */
        HT_AES->AESKEY1 = *pKeyAddr++;
        HT_AES->AESKEY2 = *pKeyAddr++;
        HT_AES->AESKEY3 = *pKeyAddr++;
        HT_AES->AESKEY4 = *pKeyAddr++;
        HT_AES->AESKEY5 = *pKeyAddr++;
        HT_AES->AESKEY6 = *pKeyAddr++;
        HT_AES->AESKEY7 = *pKeyAddr;
        }

        HT_AES->AESINLL = *pIntDataAddr++;          /*!< Write Cyphertext to Register       */
        HT_AES->AESINML = *pIntDataAddr++;
        HT_AES->AESINHM = *pIntDataAddr++;
        HT_AES->AESINHH = *pIntDataAddr;

        HT_AES->AESSTR = CRYP_START;               /*!< Start AES Descryption              */
    }
}

/**
*********************************************************************************************************
*                                      GHASH Algorithm MODULE
*
* @brief  GHASH Algorithm
*
* @param  pIntDataAddr1: Pointer to multiplier1 buffer,pIntDataAddr1[0] is LSB
*         pIntDataAddr2: Pointer to multiplier2 buffer,pIntDataAddr2[0] is LSB
*
* @retval None
*
*********************************************************************************************************
**/
void HT_GHASH_Multiply(uint32_t *pIntDataAddr1, uint32_t *pIntDataAddr2)
{   
    /*  assert_param  */
    if((pIntDataAddr1 != NULL) && (pIntDataAddr2 != NULL))
    {
        HT_GHASH->INPUT1LL = *pIntDataAddr1++;        /*!< Write  mulitiplier1                */
        HT_GHASH->INPUT1ML = *pIntDataAddr1++;
        HT_GHASH->INPUT1HM = *pIntDataAddr1++;
        HT_GHASH->INPUT1HH = *pIntDataAddr1;

        HT_GHASH->INPUT2LL = *pIntDataAddr2++;        /*!< Write  mulitiplier2                */
        HT_GHASH->INPUT2ML = *pIntDataAddr2++;
        HT_GHASH->INPUT2HM = *pIntDataAddr2++;
        HT_GHASH->INPUT2HH = *pIntDataAddr2;

        HT_GHASH->GHASHSTR = GHASH_START;             /*!< Start GHASH                       */
    }

}
/**
*********************************************************************************************************
*                                      AES Encryption/Descryption Output Read
*
* @brief  Read output data of AES Encryption/Descryption
*
* @param  pOutDataAddr: pointer to cyphertext/plaintext buffer
*
* @retval None
*
*********************************************************************************************************
**/

void HT_AES_Read(uint32_t *pOutDataAddr)
{
    /*  assert_param  */
    if(pOutDataAddr != NULL)
    {
        *pOutDataAddr++ = HT_AES->AESOUTLL;
        *pOutDataAddr++ = HT_AES->AESOUTML;
        *pOutDataAddr++ = HT_AES->AESOUTHM;
        *pOutDataAddr   = HT_AES->AESOUTHH;
    }
}

/**
*********************************************************************************************************
*                                      GHASH Algorith Output Read
*
* @brief  Read output data of GHASH Algorith
*
* @param  pOutDataAddr: pointer to  Ghash result buffer
*
* @retval None
*
*********************************************************************************************************
**/
void HT_GHASH_Multiply_Read(uint32_t *pOutDataAddr)
{
    /*  assert_param  */
    if(pOutDataAddr != NULL)
    {
        *pOutDataAddr++ = HT_GHASH->OUTPUTLL;
        *pOutDataAddr++ = HT_GHASH->OUTPUTML;
        *pOutDataAddr++ = HT_GHASH->OUTPUTHM;
        *pOutDataAddr   = HT_GHASH->OUTPUTHH;
    }
}

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE AES/GHASH/RAND INTERRUPT
*
* @brief  Enable/Disable AES/GHASH/RAND interrupt
*
* @param  ITEn: one or a combination of AES/GHASH/RAND Interrpt Enable bit selector
*              @arg AES_IE
*              @arg GHASH_IE
*              @arg RAND_IE
*
*
* @param  NewState:  Interrupt Enable Bool value
*              @arg ENABLE： Enable Interrupt
*              @arg DISABLE：Disable interrupt
* @retval None
*
*********************************************************************************************************
**/
void HT_AES_GHASH_RAND_ITConfig(AES_ITEnTypeDef ITType, FunctionalState NewState)
{
    /*  assert_param  */
    assert_param(IS_HT_AES_GHASH_RAND_ITTYPE(ITType));
    assert_param(IS_HT_AES_GHASH_RAND_STATE(NewState));
	
    if (NewState != DISABLE)
    {
        HT_GHASH->AESGHASHIE |= (uint32_t)ITType;            /*!< Enable AES/GHASH/RAND interrupt      */
    }
    else
    {
        HT_GHASH->AESGHASHIE &= ~(uint32_t)ITType;           /*!< Disable AES/GHASH/RAND interrupt     */
    }
}

/**
*********************************************************************************************************
*                            GET SPECIFIED AES/GHASH/RAND INTERRUPT FLAG STATUS
*
* @brief  Get AES/GHASH/RAND interrupt flag status
*
* @param  ITFlag: one or a combination of Interrupt flag selctor
*                 @arg AES_IF
*                 @arg GHASH_IF
*                 @arg RAND_IF
*
* @retval ITStatus:Interrupt flag status
*                       
*********************************************************************************************************
**/
ITStatus HT_AES_GHASH_RAND_ITFlagStatusGet(AES_ITFlagTypeDef ITFlag)
{
    ITStatus Status = RESET;
    /*  assert_param  */
    assert_param(IS_HT_AES_GHASH_RAND_ITFLAG(ITFlag));
    if (HT_GHASH->AESGHASHIF & ITFlag)
    {
        Status =  SET;                        /*!< AES/GHASH/RAND Interrupt Flag is set   */
    }
    else
    {
        Status = RESET;                      /*!< AES/GHASH/RAND Interrupt Flag is reset */
    }
    
    return Status;
}

/**
*********************************************************************************************************
*                                   CLEAR AES/GHASH/RAND INTERRUPT FLAG
*
* @brief  Clear AES/GHASH/RAND interrupt flag
*
* @param  ITFlag: one or a combination of AES/GHASH/RAND flag selctor
*                 @arg AES_IF
*                 @arg GHASH_IF
*                 @arg RAND_IF
*
* @retval None
*
*********************************************************************************************************
**/
void HT_AES_GHASH_RAND_ClearITPendingBit(AES_ITFlagTypeDef ITFlag)
{
    /*  assert_param  */
    assert_param(IS_HT_AES_GHASH_RAND_ITFLAG(ITFlag)); 
    HT_GHASH->AESGHASHIF   = ~((uint32_t)ITFlag);                  /*!< Clear AES/GHASH/RAND Interrupt Flag       */
}

/**
*********************************************************************************************************
*                                      GET AES BUSY STATUS
*
* @brief  Get AES busy status
*
* @param  None
*
* @retval ITStatus: AES/GHASH/RAND busy status  
*                   @arg SET: busy   
*                   @arg RESET：idle
*********************************************************************************************************
**/
ITStatus HT_AES_Busy_StatusGet(void)
{
    /*  assert_param  */
    return (ITStatus)HT_AES->AESFLG;                            /*!< return AES busy status          */
}

/**
*********************************************************************************************************
*                                    GET GHASH BUSY STATUS
*
* @brief  Get GHASH busy status
*
* @param  None
*
* @retval ITStatus: AES/GHASH/RAND busy status  
*                   @arg SET: busy   
*                   @arg RESET：idle
*********************************************************************************************************
**/
ITStatus HT_GHASH_Busy_StatusGet(void)
{
    /*  assert_param  */
    return (ITStatus)HT_GHASH->GHASHFLG;                        /*!< return GHASH  busy status  */
}

/**
*********************************************************************************************************
*                                    128bits  xor function
*
* @brief  128bits XOR function
*
* @param  pIntDataAddr1: Pointer to the first data buffer that is to be XOR, pIntDataAddr1[0] is LSB
*         pIntDataAddr2: Pointer to the second data buffer that is to be XOR, pIntDataAddr2[0] is LSB
*
* @retval pOutDataAddr:  Pointer to the data buffer that contain XOR result, pOutDataAddr[0] is LSB
*          
*
*********************************************************************************************************
**/
void HT_AES_Xor128bits(uint32_t *pIntDataAddr1, uint32_t *pIntDataAddr2, uint32_t *pOutDataAddr)
{
    uint32_t i = 0U;
    /*  assert_param  */
    if((pIntDataAddr1 != NULL) && (pIntDataAddr2 != NULL) && (pOutDataAddr != NULL))
    {
        for(i=0U; i<4U; i++)
        {
          *pOutDataAddr++ = (*pIntDataAddr1++) ^ (*pIntDataAddr2++);    /*!< XOR algorithm       */
        }
    }

}

#if  defined USE_RAND
/**
*********************************************************************************************************
*                                       SET RAND CONFIG
*
* @brief  Enbale&Start or Disable RAND mode
*
* @param  NewState
*         @arg ENABLE： Enable and start RAND Module
*         @arg DISABLE：Disable RAND Module
* @retval None
*
*********************************************************************************************************
**/
void HT_RAND_WorkState(FunctionalState NewState)
{
    /*  assert_param  */
    assert_param(IS_HT_RAND_STATE(NewState));
	
    if (NewState == ENABLE) 
    {
#if defined USE_RAND_BACKMODE
        HT_RAND->RANDSTR |= RAND_RANDSTR_BACKEN;
#endif
        HT_RAND->RANDSTR |= (RAND_RANDSTR_RANDEN | RAND_RANDSTR_START);           /*!< Enable RAND and back-mode  */
    } 
    else 
    {
        HT_RAND->RANDSTR &= (~RAND_RANDSTR_RANDEN);                               /*!< Disable */
    }
}

/**
*********************************************************************************************************
*                                               GET RAND OUTPUT
*
* @brief  Get rand output
*
* @param  None
*
* @retval Output of RAND
*
*********************************************************************************************************
**/
uint32_t HT_RAND_DataGet(void)
{
    /*  assert_param  */
    while (HT_RAND->RANDSTR & RAND_RANDSTR_START)
    {}                                           /*!< Waiting for the result */
    return (HT_RAND->RANDDAT);
}

/**
*********************************************************************************************************
*                                               CONFIGURE WORKMODE & BACKMODE
*
* @brief  Configure work-mode & back-mode of RAND module
*
* @param  WorkMode: RAND work-mode type 
*                   This parameter ca be one of the following value:
*                   @arg RAND_MODE_SAMPLE        low frequency sample high frequency 
*                   @arg RAND_MODE_DFF           D flip-flp uncertain mode
*                   @arg RAND_MODE_XOR           XOR mix
*         BackMode: RAND back-mode type
*                   This parameter can be one of the following value:
*                   @arg RAND_BMODE_LFSR         LFSR 
*                   @arg RAND_BMODE_PSEUDO       pseudo random mixer 
*                   @arg RAND_BMODE_LFSR_PSEUDO  both above two
*
* @retval None
*
*********************************************************************************************************
**/
#if defined USE_RAND_WORKMODE && defined USE_RAND_BACKMODE
void HT_RAND_ConfigSet(RAND_ModSelTypeDef WorkMode, RAND_BackModSelTypeDef BackMode)
{  	
    uint32_t reg_val;
	
	/* assert_param  */
	assert_param(IS_HT_RAND_WORKMODE(WorkMode));
	assert_param(IS_HT_RAND_BACKMODE(BackMode));

    reg_val = HT_RAND->RANDSTR;
    reg_val = (reg_val & (~RAND_RANDSTR_MODESEL)) | (WorkMode & RAND_RANDSTR_MODESEL);       /*!< configure work-mode  */
    reg_val = (reg_val & (~RAND_RANDSTR_BACKMODE)) | (BackMode & RAND_RANDSTR_BACKMODE);     /*!< configure back-mode */
    reg_val |= (RAND_RANDSTR_RANDEN | RAND_RANDSTR_BACKEN);                                  /*!< Enable RAND and back-mode  */
    HT_RAND->RANDSTR = reg_val;
}
#endif

/**
*********************************************************************************************************
*                                               CONFIGURE RAND WOWRKMODE 
*
* @brief  Configure work-mode of RAND module
*
* @param  WorkMode: RAND work mode type cogfigure
*                   This parameter ca be one of the following value:
*                   @arg RAND_MODE_SAMPLE        low frequency sample high frequency 
*                   @arg RAND_MODE_DFF           D flip-flp uncertain mode
*                   @arg RAND_MODE_XOR           XOR mix
*
* @retval None
*
*********************************************************************************************************
**/
#if defined USE_RAND_WORKMODE
void HT_RAND_WorkMode_Config(RAND_ModSelTypeDef WorkMode)
{  	
    uint32_t reg_val;
	
	/* assert_param  */
	assert_param(IS_HT_RAND_WORKMODE(WorkMode));

    reg_val = HT_RAND->RANDSTR;
    reg_val = (reg_val & (~RAND_RANDSTR_MODESEL)) | (WorkMode & RAND_RANDSTR_MODESEL);       /*!< configure work-mode */
    reg_val |= (RAND_RANDSTR_RANDEN | RAND_RANDSTR_BACKEN);                                  /*!< Enable Rand and work-mode */
    HT_RAND->RANDSTR = reg_val;
}
#endif

/**
*********************************************************************************************************
*                                               CONFIGIURE RAND BACKMODE 
*
* @brief  Configure back-mode of RAND module
*
* @param  BackMode: RAND back-mode type 
*                   This parameter ca be one of the following value:
*                   @arg RAND_BMODE_LFSR         LFSR 
*                   @arg RAND_BMODE_PSEUDO       pseudo random mixer 
*                   @arg RAND_BMODE_LFSR_PSEUDO  both above two      
*
* @retval None
*
*********************************************************************************************************
**/
#if defined USE_RAND_BACKMODE
void HT_RAND_BackMode_Config(RAND_BackModSelTypeDef BackMode)
{  	
    uint32_t reg_val;
	
	/* assert_param  */
    assert_param(IS_HT_RAND_BACKMODE(BackMode));

    reg_val = HT_RAND->RANDSTR;
    reg_val = (reg_val & (~RAND_RANDSTR_BACKMODE)) | ((uint32_t)BackMode & RAND_RANDSTR_BACKMODE);     /*!< configure back-mode */
    reg_val |= (RAND_RANDSTR_RANDEN | RAND_RANDSTR_BACKEN);                                  /*!< Enable Rand and back-mode */
    HT_RAND->RANDSTR = reg_val;
}
#endif

#endif

#if (USE_HT_ARG_REGISTER_CALLBACKS == 1U)
/**
*********************************************************************************************************
*                            ARG Interrupt Handler
*
* @brief  ARG interrupt sevice function 
*
* @param  ARG_InitStruct: Pointer to ARG_InitTypedefstructure that contains
*                               the configuration of AES module
* @retval None
*
* @note: None
*********************************************************************************************************
*/
void HT_ARG_IRQHandler(ARG_InitTypeDef *ARG_InitStruct)
{
	/*  assert_param  */
	if(ARG_InitStruct != NULL)
	{	
		/*Call register AES callback*/
		ARG_InitStruct->ARGCallback(ARG_InitStruct);
	}
}

/**
*********************************************************************************************************
*                           Register ARG user Callback 
*
* @brief  Register a User ARG Callback
*         TO be used insted os the weak predefined callback
* @param  Pointer to ARG_InitTypeDef structure that contains
*         the configuration of AES module
* @retval status
* @note: when USE_HT_ARG_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register 
*		himself defined callback function.
*********************************************************************************************************
*/
StatusTypeDef HT_ARG_RegisterCallback(ARG_InitTypeDef *ARG_InitStruct,  pARG_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        ARG_InitStruct->ErrorCode |= AEG_ERROR_INVALID_CALLBACK;
        status = ERROR;
    }
    else
    {
		ARG_InitStruct->ARGCallback = pCallback;
    }
    return status;
	
}
/**
*********************************************************************************************************
*                           Initial ARG Callback settings
*
* @brief  Initialize the callbacks to the default values
*
* @param  ARG_InitStruct: Pointer to ARG_InitTypedefstructure that contains
*                               the configuration of AES module
* @retval None
*
* Note: None
*********************************************************************************************************
*/
void ARG_InitCallbacksToDefault(ARG_InitTypeDef *ARG_InitStruct)
{
    /*  assert_param  */
    if(ARG_InitStruct != NULL)
    {
        /*Init the ARG Callback setting*/
        ARG_InitStruct->ARGCallback = HT_ARG_Callback;
    }
}
/**
*********************************************************************************************************
*                            ARG Interrupt Callback
*
* @brief  ARG interrupt callback function 
*
* @param  ARGInitStruct: Pointer to ARG_InitTypeDef structure that contains
*                               the configuration of AES module
* @retval None
*
* Note: None
*********************************************************************************************************
*/
__weak void HT_ARG_Callback(ARG_InitTypeDef *ARG_InitStruct)
{   
    /*  assert_param  */
    if(ARG_InitStruct != NULL)
    {
        UNUSED(ARG_InitStruct);
    }
}
#endif
#endif                                        /* This File Only support for chips used aes&rand Function. */
