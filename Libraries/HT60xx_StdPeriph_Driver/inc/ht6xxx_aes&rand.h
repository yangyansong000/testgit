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
* File         : ht6xxx_aes&rand.h
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  : Only support for chips used aes&rand Function.
**********************************************************************************************************
*/

#ifndef __HT6XXX_AES_RAND_H__
#define __HT6XXX_AES_RAND_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

#if defined   USE_ARG


/*
*********************************************************************************************************
*                                           Macros/Structures
*********************************************************************************************************
*/
/**
* @brief  AES_key Length sttructure definition
**/
typedef enum
{
    KEY_Mode_128bits = AES_AESCON_KEYMODE_AES128,       /*!< AES-128                      */
    KEY_Mode_192bits = AES_AESCON_KEYMODE_AES192,       /*!< AES-192                      */
    KEY_Mode_256bits = AES_AESCON_KEYMODE_AES256,       /*!< AES-256                      */
}AESKeyMode_TypeDef;                                    /*!<end of group AESKeyMode_TypeDef  */

/**
* @brief  AES/GHASH/RAND Interrupt Enable structre definition
**/
typedef enum
{
    AES_IE = GHASH_AESGHASHIE_AESIE,                    /*!< AES Interrupt                    */
    GHASH_IE = GHASH_AESGHASHIE_GHASHIE,                /*!< GHASH Interrupt                  */
    RAND_IE = GHASH_AESGHASHIE_RANDIE,                  /*!< RAND Interrupt                   */
    ARG_IE_ALL =   (GHASH_AESGHASHIE_AESIE|GHASH_AESGHASHIE_GHASHIE|GHASH_AESGHASHIE_RANDIE)	/*!< all of above Interrupt          */   
}AES_ITEnTypeDef;                                       /*!<end of group AES_ITEnTypeDef      */

/**
* @brief  AES/GHASH/RAND Interrupt Flag structure definition
**/
typedef enum
{
    AES_IF = GHASH_AESGHASHIF_AESIF,                    /*!< AES Interrupt flag           */
    GHASH_IF = GHASH_AESGHASHIF_GHASHIF,                /*!< GHASH Interrupt flag         */
    RAND_IF = GHASH_AESGHASHIF_RANDIF,                  /*!< RAND Interrupt flag          */
	ARG_IF_ALL	=	(GHASH_AESGHASHIF_AESIF|GHASH_AESGHASHIF_GHASHIF|GHASH_AESGHASHIF_AESIF)	/*!< all of above flag          */
}AES_ITFlagTypeDef;

#if defined USE_RAND
/**
* @brief  RAND random work mode structure definition
**/
#if  defined USE_RAND_WORKMODE
typedef enum
{
    RAND_MODE_SAMPLE = RAND_RANDSTR_MODESEL_SAMPLE,     /*!< Low frequncy sample high frequency  */
    RAND_MODE_DFF = RAND_RANDSTR_MODESEL_DFF,           /*!< D flip-flop uncertain state         */
    RAND_MODE_XOR = RAND_RANDSTR_MODESEL_XOR,           /*!< XOR Mix Output                      */
}RAND_ModSelTypeDef;

#endif
/**
* @brief  RAND random backprocessing mode structure definition
*/
#if defined USE_RAND_BACKMODE
typedef enum
{
    RAND_BMODE_LFSR = RAND_RANDSTR_BACKMODE_LFSR,       /*!< LFSR mode                       */
    RAND_BMODE_PSEUDO = RAND_RANDSTR_BACKMODE_PSEUDO,   /*!< fake random mix mode            */
    RAND_BMODE_LFSR_PSEUDO = RAND_RANDSTR_BACKMODE_ADD, /*!< both of above two               */
}RAND_BackModSelTypeDef;
#endif
#endif
/**
* @brief  RAND random afterprocessing mode structure definition
*/
typedef union
{
  uint8_t u8[16];
  uint32_t u32[4];
  uint64_t u64[2];
} Parameter128bits_TypeDef;
/**
* @brief  RAND random afterprocessing mode structure definition
*/
typedef union
{
  uint8_t u8[16*2];
  uint32_t u32[4*2];
  uint64_t u64[2*2];
} Parameter256bits_TypeDef;

/**
* @brief  RAND random afterprocessing mode structure definition
*/
typedef union
{
  uint8_t u8[16*3];
  uint32_t u32[4*3];
  uint64_t u64[2*3];
} Parameter384bits_TypeDef;
/**
* @brief  RAND random afterprocessing mode structure definition
*/
typedef union
{
  uint8_t u8[16*4];
  uint32_t u32[4*4];
  uint64_t u64[2*4];
} Parameter512bits_TypeDef;
/**
* @brief  RAND random afterprocessing mode structure definition
*/
typedef union
{
  uint8_t u8[16*8];
  uint32_t u32[4*8];
  uint64_t u64[2*8];
} Parameter1024bits_TypeDef;

#if (USE_HT_ARG_REGISTER_CALLBACKS == 1U)

#define AEG_ERROR_INVALID_CALLBACK  0x00000001U   /*!< Invalid Callback error  */

typedef struct __ARG_InitTypeDef{	 
	 HT_AES_TypeDef  *AESInstance;        								        /*!< AES registers base address    */
#if defined USE_RAND
	 HT_RAND_TypeDef *RANDInstance;                                             /*!< RAND registers base address    */
#endif
	HT_GHASH_TypeDef *GHASHInstance;                                            /*!< GHAH registers base address    */
     __IO uint32_t    ErrorCode;        								        /*!< ARG Error code                */
	 void (* ARGCallback)(struct __ARG_InitTypeDef *ARG_InitStruct);            /*!< ARG call back                 */
	
}ARG_InitTypeDef;

/**
* @brief ARG Callback pointer definition
*/
typedef  void (*pARG_CallbackTypeDef)(ARG_InitTypeDef *ARG_InitStruct); 	 /*!< pointer to an ARG callback function */
#endif

#define IS_HT_AES_KEYMODE(AESKEYMODE)  (((AESKEYMODE) == KEY_Mode_128bits) || \
                                        ((AESKEYMODE) == KEY_Mode_192bits) ||\
                                        ((AESKEYMODE) == KEY_Mode_256bits))
 
#define IS_HT_AES_GHASH_RAND_ITTYPE(ITTYPE) (((ITTYPE) == AES_IE)|| \
                                             ((ITTYPE) == GHASH_IE)|| \
                                             ((ITTYPE) == RAND_IE) || \
                                             ((((ITTYPE) & (uint32_t)(~ARG_IE_ALL)) == 0x00) && ((ITTYPE) != 0x00)))

#define IS_HT_AES_GHASH_RAND_STATE(STATE)   (((STATE) == ENABLE) || \
                                             ((STATE) == DISABLE))

#define IS_HT_AES_GHASH_RAND_ITFLAG(ITFLAG) (((ITFLAG) == AES_IF) || \
                                             ((ITFLAG) == GHASH_IF) || \
                                             ((ITFLAG) == RAND_IF) || \
                                             ((((ITFLAG) & (uint32_t)(~ARG_IF_ALL)) == 0x00) && ((ITFLAG) != 0x00)))

#define IS_HT_RAND_STATE(STATE)		(((STATE) == ENABLE) || \
                                     ((STATE) == DISABLE))

#define IS_HT_RAND_WORKMODE(WORKMODE)		(((WORKMODE) == RAND_MODE_SAMPLE) || \
                                             ((WORKMODE) == RAND_MODE_DFF) || \
                                              ((WORKMODE) == RAND_MODE_XOR)) 

#define IS_HT_RAND_BACKMODE(BACKMODE)		(((BACKMODE) == RAND_BMODE_LFSR) || \
                                             ((BACKMODE) == RAND_BMODE_PSEUDO) || \
                                              ((BACKMODE) == RAND_BMODE_LFSR_PSEUDO)) 
#define ENCRYP_MODE_128BIT		0x00U
#define ENCRYP_MODE_192BIT		0x02U
#define ENCRYP_MODE_256BIT		0x04U

#define DECRYP_MODE_128BIT		0x01U
#define DECRYP_MODE_192BIT		0x03U
#define DECRYP_MODE_256BIT		0x05U

#define CRYP_START				0x8329U
#define GHASH_START				0x0501U
/*
*********************************************************************************************************
*                                          Global variables
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          Global funtions
*********************************************************************************************************
*/

void HT_AES_Encrypt(AESKeyMode_TypeDef AESKeyMode, uint32_t *pKeyAddr, uint32_t *pIntDataAddr);
void HT_AES_Decrypt(AESKeyMode_TypeDef AESKeyMode, uint32_t *pKeyAddr, uint32_t *pIntDataAddr);
void HT_GHASH_Multiply(uint32_t *pIntDataAddr1, uint32_t *pIntDataAddr2);
void HT_AES_Read(uint32_t *pOutDataAddr);
void HT_GHASH_Multiply_Read(uint32_t *pOutDataAddr);
void HT_AES_GHASH_RAND_ITConfig(AES_ITEnTypeDef ITType, FunctionalState NewState);
ITStatus HT_AES_GHASH_RAND_ITFlagStatusGet(AES_ITFlagTypeDef ITFlag);
void HT_AES_GHASH_RAND_ClearITPendingBit(AES_ITFlagTypeDef ITFlag);
ITStatus HT_AES_Busy_StatusGet(void);
ITStatus HT_GHASH_Busy_StatusGet(void);
void HT_AES_Xor128bits(uint32_t *pIntDataAddr1, uint32_t *pIntDataAddr2,uint32_t *pOutDataAddr);

#if (USE_HT_ARG_REGISTER_CALLBACKS == 1U)
void HT_ARG_Init(ARG_InitTypeDef *ARG_Initstruct);
StatusTypeDef HT_ARG_RegisterCallback(ARG_InitTypeDef *ARG_InitStruct,  pARG_CallbackTypeDef pCallback);
void ARG_InitCallbacksToDefault(ARG_InitTypeDef *ARG_InitStruct);
void HT_ARG_Callback(ARG_InitTypeDef *ARG_InitStruct);
#endif

#if  defined USE_RAND
void HT_RAND_WorkState(FunctionalState NewState);
uint32_t HT_RAND_DataGet(void);
    #if defined USE_RAND_WORKMODE && defined USE_RAND_BACKMODE
    void HT_RAND_ConfigSet(RAND_ModSelTypeDef WorkMode, RAND_BackModSelTypeDef BackMode);
    #endif
    #if defined USE_RAND_WORKMODE
    void HT_RAND_WorkMode_Config(RAND_ModSelTypeDef WorkMode);
    #endif
    #if defined USE_RAND_BACKMODE
    void HT_RAND_BackMode_Config(RAND_BackModSelTypeDef BackMode);
    #endif

#endif

#endif                                        /* This File Only support HT6x2x and HT501x */

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_AES_RAND_H__ */
