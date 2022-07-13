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
* File         : ht6xxx_ecc.h
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  : 
**********************************************************************************************************
*/

#ifndef __HT6XXX_ECC_H__
#define __HT6XXX_ECC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"


#if defined USE_ECC || defined USE_ECC384      
/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/
#if defined USE_ECC     
/**
* @brief  ECC interrupt flag enumeration definition
*/
typedef enum
{
    ECC_IF          = ECC_ECCSTA_ECCFLG,            /*!< ECC calculation finish                */
    ECC_FLG_BUSY    = ECC_ECCSTA_BUSY,              /*!< ECC busy                              */
    ECC_FLG_ECDSA_V = ECC_ECCSTA_ECDSA_V,           /*!< ECDSA verify success flag             */
    ECC_FLG_ECDSA_S = ECC_ECCSTA_ECDSA_S,           /*!< ECDSA signature restartable flag      */
    ECC_FLG         = ECC_ECCSTA_PKV,               /*!< ECDSA public key verify success flag  */
    ECC_FLG_ALL	    = ECC_ECCSTA	                /*!< all of above ECC flag                 */
}ECC_ITFlagTypeDef;


#elif defined USE_ECC384
/**
* @brief  ECC interrupt flag enumeration definition
*/
typedef enum
{
    ECC_IF = ECC_ECCSTA_ECCIF,                   /*!< ECC calculation finish                */
    ECC_FLG_BUSY = ECC_ECCSTA_BUSY,              /*!< ECC busy                              */
    ECC_FLG_ECDSA_V = ECC_ECCSTA_ECC_V,          /*!< ECDSA verify success flag             */
    ECC_FLG_ALL	= ECC_ECCSTA	                /*!< all of above ECC flag                  */
}ECC_ITFlagTypeDef;

#endif
/**
* @brief  ECC point operation type enumeration definition
*/
typedef enum
{
    EccAdd_Mode = ECC_ECCCON_OP_SEL_ECA,       /*!< ECC point add                      */
#if defined USE_ECC
    EccDou_Mode = ECC_ECCCON_OP_SEL_ECD,       /*!< ECC point double                   */
#endif
    EccMul_Mode = ECC_ECCCON_OP_SEL_ECSM,      /*!< ECC point multiple                 */
}ECC_PointMode_TypeDef; 
	
/**
* @brief  Big number modular operation type enumeration definition
*/
typedef enum
{
    ModAdd_Mode = ECC_ECCCON_OP_SEL_MA,       /*!< Modular add                       */
    ModSub_Mode = ECC_ECCCON_OP_SEL_MS,       /*!< Modular sub                       */
    ModMul_Mode = ECC_ECCCON_OP_SEL_MM,       /*!< Modular multiple                  */
    ModDiv_Mode = ECC_ECCCON_OP_SEL_MD,       /*!< Modular divide                    */
    ModInv_Mode = ECC_ECCCON_OP_SEL_MI,       /*!< Modular inverse                   */
}ECC_ModMode_TypeDef;                         /*!<end of group ECC_ModMode_TypeDef  */


/**
* @brief  Modular operation  input structure definition  
*/
typedef struct
{
      ECC_ModMode_TypeDef ModMode;        /*!< Modular operation type                   */
      uint32_t *pnAddr;                   /*!< Pointer to Big Prime n                   */
      uint32_t *pPxAddr;                  /*!< pointer to the first big number          */
      uint32_t *pPyAddr;                  /*!< pointer to the second big number         */ 
}ECC_ModOperate_InputTypedef;             /*!< end of group ECC_ModOperate_InputTypedef */

/*
* @brief  ECC PointOperate Initial structure definition 
*/
typedef struct
{
      uint32_t *pECCpAddr;                /*!< Order P of GF(P)                         */
      uint32_t *pECCaAddr;                /*!< parameter a of ECC function              */   
}ECC_PointOperate_InitTypedef;            /*!< end of group ECC_PointOperate_InitTypedef*/
/**
* @brief  ECC Point operation input structure definition 
*/
typedef struct
{
      ECC_PointMode_TypeDef PointMode;    /*!< ECC point operation mode                 			 */
      uint32_t *pECCPxAddr;               /*!< x axile value of the the first point on ECC curve   	 */                                            
      uint32_t *pECCPyAddr;               /*!< y axile value of the the first point on ECC curve     */                       
      uint32_t *pECCSxAddr;               /*!< x axile value of the the second point on ECC curve    */
      uint32_t *pECCSyAddr;               /*!< x axile value of the the second point on ECC curve    */
      uint32_t *pKscalAddr;               /*!< ECC point multiplier k                                */
}ECC_PointOperate_InputTypedef;           /*!< end of group ECC_PointOperate_InputTypedef*/

/**
* @brief  ECC ECDSA signature operation output structure definition 
*/
typedef struct
{
      uint32_t *prAddr;                  /*!< x axile value of the result of ECC point operation                    */
      uint32_t *psAddr;                  /*!< y axile value of the result of ECC point operation                    */
}ECC_ECDSA_SignOperate_OutputTypedef;          /*!< end of group ECC_ModOperate_InputTypedef*/


/**
* @brief  ECC Point operation output structure definition 
*/
typedef struct
{
      uint32_t *pRxAddr;                  /*!< x axile value of the result of ECC point operation                    */
      uint32_t *pRyAddr;                  /*!< y axile value of the result of ECC point operation                    */
}ECC_PointOperate_OutputTypedef;          /*!< end of group ECC_ModOperate_InputTypedef*/

/**
* @brief  ECC Point operation output structure definition 
*/
#if(USE_HT_ECC_REGISTER_CALLBACKS == 1U)

typedef struct __ECC_InitTypeDef{	 
	 HT_ECC_TypeDef  *Instance;        								        	/*!< ECC registers base address    */
   __IO uint32_t    ErrorCode;        								        	/*!< ECC Error code                */
	 void (* ECCCallback)(struct __ECC_InitTypeDef *ECC_InitStruct);            /*!< ECC call back                 */
}ECC_InitTypeDef;

#define ECC_ERROR_INVALID_CALLBACK  0x00000001U    							    /*!< Invalid Callback error  */

typedef  void (*pECC_CallbackTypeDef)(ECC_InitTypeDef *ECC_InitStruct); 	    /*!< pointer to an ARG callback function */

#endif                    /* USE_HT_ECC_REGISTER_CALLBACKS */

/**
* @brief  ECDSA Initialization structure definition 
*/
typedef struct
{
      uint32_t *pECCpAddr;                /*!< Big prime p(order of G(F))*/
      uint32_t *pECCaAddr;                /*!< ECC function element a that define the fuction*/ 
#if defined USE_ECC384
      uint32_t *pECCbAddr;                /*!< ECC function element b that define the fuction*/   
#endif
      uint32_t *pECCGxAddr;               /*!< ECC base point G--x axile*/
      uint32_t *pECCGyAddr;               /*!< ECC base point G--Y axile*/
      uint32_t *pECCnAddr;                /*!< Order of the point G	*/
}ECC_ECDSA_InitTypedef;                   /*!< end of group ECC_ECDSA_InitTypedef*/


/*
* @brief  ECDSA Signature operation input structure definition 
*/
typedef struct
{
      uint32_t *pdAddr;                   /*!< private key d*/
      uint32_t *pkAddr;                   /*!< Big rand k*/
      uint32_t *pMAddr;                   /*!< Message HASH*/
}ECC_ECDSA_Signature_InputTypedef;        /*!< end of group ECC_ECDSA_Signature_InputTypedef*/

/*
* @brief  ECDSA Verification operation input structure definition 
*/
typedef struct
{
      uint32_t *pECCDxAddr;               /*!< x axile value of the public key D*/
      uint32_t *pECCDyAddr;               /*!< y axile value of the public key D*/
      uint32_t *pMAddr;                   /*!< Message HASH*/
      uint32_t *prAddr;                   /*!< parameter r of ECDSA result*/
      uint32_t *psAddr;                   /*!< parameter s of ECDSA result*/
}ECC_ECDSA_Verification_InputTypedef;     /*!< end of group ECC_ECDSA_Verification_InputTypedef*/

/*
* @brief  ECC Public Key Validationinput structure definition  
*/
typedef struct
{
      uint32_t *pECCpAddr;                /*!< Big prime p(order of G(F))*/
      uint32_t *pECCaAddr;                /*!< parameter a of ECC function*/
      uint32_t *pECCbAddr;                /*!< parameter b of ECC function*/
      uint32_t *pECCPxAddr;               /*!< x axile value of a point on ECC curve*/
      uint32_t *pECCPyAddr;               /*!< y axile value of a point on ECC curve*/
}ECC_PKV_InputTypedef;                    /*!< end of group ECC_PKV_InputTypedef*/

#define IS_HT_ECC_ALL_PERIPH(ECC)   ((ECC) == HT_ECC) 
/**
* @brief HT_ECC_IT_Status
*/
#define IS_HT_ECC_IT_STATUS(STATUS)	(((STATUS) == ENABLE)|| \
                                     ((STATUS) == DISABLE))

/**
* @brief HT_ECC_IT_FLAG
*/
#if defined USE_ECC
#define IS_HT_ECC_IT_Flag(ITFLAG)	(((ITFLAG) == ECC_IF) || \
                                    ((ITFLAG) == ECC_FLG_BUSY) || \
                                    ((ITFLAG) == ECC_FLG_ECDSA_V) || \
                                    ((ITFLAG) == ECC_FLG_ECDSA_S) || \
                                    ((ITFLAG) == ECC_ECCSTA_PKV) || \
                                   ((((ITFLAG) & (uint32_t)(~ECC_FLG_ALL)) == 0x00) && ((ITFLAG) != 0x00)))
#endif

#if defined USE_ECC384	
#define IS_HT_ECC_IT_Flag(ITFLAG)	(((ITFLAG) == ECC_IF) || \
                                   ((ITFLAG) == ECC_FLG_BUSY) || \
                                   ((ITFLAG) == ECC_ECCSTA_ECC_V) || \
                                   ((((ITFLAG) & (uint32_t)(~ECC_FLG_ALL)) == 0x00) && ((ITFLAG) != 0x00)))
#endif
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
void HT_ECC_PointOperate_Init(ECC_PointOperate_InitTypedef* ECC_PointOperate_InitStruct);
void HT_ECC_ECDSA_Init(ECC_ECDSA_InitTypedef* ECC_ECDSA_InitStruct);
void HT_ECC_ECDSA_S(ECC_ECDSA_Signature_InputTypedef* ECC_ECDSA_S_InputStruct);
void HT_ECC_ECDSA_V(ECC_ECDSA_Verification_InputTypedef* ECC_ECDSA_V_InputStruct);
void HT_ECC_PointOperate(ECC_PointOperate_InputTypedef* ECC_PointOperate_InputStruct);
void HT_ECC_PublickeyValidate(ECC_PKV_InputTypedef* ECC_PKV_InputStruct);
void HT_ECC_ModOperate(ECC_ModOperate_InputTypedef* ECC_ModOperate_InputStruct);
void HT_ECC_ECDSA_S_Read(ECC_ECDSA_SignOperate_OutputTypedef* ECC_ECDSA_SignOperate_OutputStruct);
void HT_ECC_PointOperate_Read(ECC_PointOperate_OutputTypedef* ECC_PointOperate_OutputStruct);
void HT_ECC_ModOperate_Read(uint32_t *pModOperateOutAddr);
void HT_ECC_ITConfig(FunctionalState NewState);
ITStatus HT_ECC_ITFlagStatusGet(ECC_ITFlagTypeDef ITFlag);
void HT_ECC_ClearITPendingBit(ECC_ITFlagTypeDef ITFlag);
ITStatus HT_ECC_Busy_StatusGet(void);

#if(USE_HT_ECC_REGISTER_CALLBACKS  == 1U)
void HT_ECC_Init(HT_ECC_TypeDef *ECCx, ECC_InitTypeDef *ECC_InitStruct);
void ECC_InitCallbacksToDefault(ECC_InitTypeDef* ECC_InitStruct);
void HT_ECC_Callback(ECC_InitTypeDef *ECC_InitStruct);
StatusTypeDef HT_ECC_RegisterCallback(ECC_InitTypeDef *ECC_InitStruct,  pECC_CallbackTypeDef pCallback);
#endif

#endif                                        /* This File Only support HT6x2x ，HT501xand HT502x */

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_ECC_H__ */
