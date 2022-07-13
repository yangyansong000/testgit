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
* File         : ht6xxx_ecc.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  : Only support for chips used ECC Function.
*********************************************************************************************************
*/

#define  __HT6XXX_ECC_C
#include <stdio.h>
#include "ht6xxx_lib.h" 


#if defined USE_ECC || defined USE_ECC384

/*
*********************************************************************************************************
*                                           Local Macro/Struct
*********************************************************************************************************
*/

#define ECC_PARAM_SIZE 8U
#define ECC384_PARAM_SIZE 12U


/*
*********************************************************************************************************
*                                           Local Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Local Function Declare
*********************************************************************************************************
*/
#if (USE_HT_ECC_REGISTER_CALLBACKS == 1U)
void ECC_InitCallbacksToDefault(ECC_InitTypeDef* ECC_InitStruct);
#endif


/**
*********************************************************************************************************
*                                    INITIAL ECC MODULE
*
* @Brief  Initialize the ECC module 
*
* @Param  ECCx: Pointer to ECC register
*         ECC_InitStruct: pointer to a ECC_InitTypeDef structure that configure 
*                         CRC callback
* @retval None
*
* Note:
*********************************************************************************************************
*/
#if (USE_HT_ECC_REGISTER_CALLBACKS == 1U)
void HT_ECC_Init(HT_ECC_TypeDef *ECCx, ECC_InitTypeDef *ECC_InitStruct)
{
    /* assert_param */
    assert_param(IS_HT_ECC_ALL_PERIPH(ECCx));
    if(ECC_InitStruct != NULL)
    {
        ECC_InitStruct->Instance = ECCx;
        ECC_InitCallbacksToDefault(ECC_InitStruct);
    }		
}
#endif

#if defined USE_ECC 
/**
*********************************************************************************************************
*                              ECDSA ECC Initialization
*
* @brief  Initialize the parameters of ECDSA ECC
*
* @param  ECC_ECDSA_InitStruct: Pointer to a ECC_ECDSA_InitTypedef structure that containe 5 parameters:
*                           1) pECCpAddr        Pointer to the Prime P of GF(P),ECCpAddr[0] is LSB
*                           2) pECCaAddr        Pointer to parameter a of the Elliptic Curve function, pECCaAddr[0] is LSB
*                           3) pECCnAddr        Pointer to the order n of G which is a point on the curve, pECCnAddr[0]is LSB
*                           4) pECCGxAddr       Pointer to x which is x axis value of point G, pECCGxAddr[0]is LSB
*                           5) pECCGyAddr       Pointer to y which is x axis value of point G, pECCGyAddr[0]is LSB
*
* @retval  None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_ECDSA_Init(ECC_ECDSA_InitTypedef* ECC_ECDSA_InitStruct)
{
	uint32_t i;
	if(ECC_ECDSA_InitStruct != NULL)        /*  check the handle allocation  */
        {
          for(i=0U; i<ECC_PARAM_SIZE; i++)
          {
            HT_ECC->PREG = *(ECC_ECDSA_InitStruct->pECCpAddr+i);       /*!< load ECC_P  */
            HT_ECC->AREG = *(ECC_ECDSA_InitStruct->pECCaAddr+i);       /*!< load ECC_a  */
            HT_ECC->PXREG = *(ECC_ECDSA_InitStruct->pECCGxAddr+i);     /*!< load ECC_Gx */
            HT_ECC->PYREG = *(ECC_ECDSA_InitStruct->pECCGyAddr+i);     /*!< load ECC_Gy */
            HT_ECC->SXREG = *(ECC_ECDSA_InitStruct->pECCnAddr+i);      /*!< load ECC_n  */
          }
	
        }		
}

/**
*********************************************************************************************************
*                              ECC PointOperate Initialization
*
* @brief Initialize the parameter of ECC PointOperate
*
* @param ECC_PointOperate_InitStruct:    Pointer to a ECC_PointOperate_InitTypedef structure that contains 2 parameters:
*                           1) pECCpAddr        Pointer to the Prime P of GF(P),ECCpAddr[0] is LSB
*                           2) pECCaAddr        Pointer to parameter a of the Elliptic Curve function, pECCaAddr[0] is LSB
*
* @retval None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_PointOperate_Init(ECC_PointOperate_InitTypedef* ECC_PointOperate_InitStruct)
{	
    uint32_t i = 0U;
    /*  assert_param  */
    if(ECC_PointOperate_InitStruct != NULL)
    {
        for(i=0U;i<ECC_PARAM_SIZE;i++)
        {
            HT_ECC->PREG = *(ECC_PointOperate_InitStruct->pECCpAddr+i);     /*!< load ECC_p */
            HT_ECC->AREG = *(ECC_PointOperate_InitStruct->pECCaAddr+i);     /*!< load ECC_a */
        }
    }
}

/**
*********************************************************************************************************
*                              ECC Digital Signature Algorithm (ECDSA) Signature Operation
*
* @brief ECDSA Operation, ECDSA-S
*
* @param ECC_ECDSA_S_InputStruct: Pointer to ECC_ECDSA_Signature_InputTypedef structure which contains 3 operation input parameters:
*                           1) pdAddr    pointer to the private key d, pdAddr[0] is LSB       
*                           2) pkAddr    pointer to the rand k, pkAddr[0] is LSB     
*                           3) pMAddr    pointer t the message hash value, pMAddr[0] is LSB   
*
* @retval None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_ECDSA_S(ECC_ECDSA_Signature_InputTypedef* ECC_ECDSA_S_InputStruct)
{
    uint32_t i = 0U;
    uint32_t tempreg = 0U;
   /*  assert_param  */
    if(ECC_ECDSA_S_InputStruct != NULL)
    {		
        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_ECCCON_OP_SEL_ECDSA_S);
                                                      /*!< config the operation mode：ECDSA-S        */
        for(i=0U;i<ECC_PARAM_SIZE;i++)
        {
            HT_ECC->KEYREG = *(ECC_ECDSA_S_InputStruct->pdAddr+i);      /*!< load d*/
            HT_ECC->SYREG = *(ECC_ECDSA_S_InputStruct->pkAddr+i);       /*!< load k*/
            HT_ECC->MREG = *(ECC_ECDSA_S_InputStruct->pMAddr+i);        /*!< load M*/
        }
        HT_ECC->ECCSTA = RESET;                             /*!< Clear Flag                   */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;              /*!< Start operation                */
    }
}

/**
*********************************************************************************************************
*                              EC Digital Signature Algorithm (ECDSA) Verification operation
*
* @brief ECDSA verification Operation，ECDSA-V
*
* @param ECC_ECDSA_V_InputStruct: Pointer to ECC_ECDSA_Verification_InputTypedef structure which contains 5 operation input parameters:
*                           1) pECCDxAddr       pointer to the x which is x axis value of public key, pECCDxAddr[0] is LSB
*                           2) pECCDyAddr       pointer to the y which is y axis value of public key, pECCDyAddr[0] is LSB
*                           3) pMAddr           pointer to the message hash value, pMAddr[0] is LSB
*                           4) prAddr;          pointer to the ECDSA result r, prAddr[0]is LSB
*                           5) psAddr;          pointer to the ECDSA result s, prAddr[0]is LSB
*
* @retval None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_ECDSA_V(ECC_ECDSA_Verification_InputTypedef* ECC_ECDSA_V_InputStruct)
{
    uint32_t i = 0U;
    uint32_t tempreg = 0U;
    
    /*  assert_param  */
    if(ECC_ECDSA_V_InputStruct != NULL)	
    {
        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_ECCCON_OP_SEL_ECDSA_V);
                                                      /*!< Configure operation mode：ECDSA-v        */
        for(i=0U;i<ECC_PARAM_SIZE;i++)
        {
            HT_ECC->KEYREG = *(ECC_ECDSA_V_InputStruct->pECCDxAddr+i);  /*!< Load ECC_Dx         */
            HT_ECC->SYREG = *(ECC_ECDSA_V_InputStruct->pECCDyAddr+i);   /*!< Load ECC_Dy         */
            HT_ECC->MREG = *(ECC_ECDSA_V_InputStruct->pMAddr+i);        /*!< Load M             */
            HT_ECC->RXREG = *(ECC_ECDSA_V_InputStruct->prAddr+i);       /*!< Load r             */
            HT_ECC->RYREG = *(ECC_ECDSA_V_InputStruct->psAddr+i);       /*!< Load s             */
        }
        HT_ECC->ECCSTA = RESET;                             /*!< Clear flag                      */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;              /*!< Start Operation                   */
    }
}
/**
*********************************************************************************************************
*                              ECC Point operation
*
* @brief ECC point operation
*
* @param ECC_PointOperate_InputStruct: Pointer to the ECC_PointOperate_InputTypedef structure which contains 6 paramters:
*                           1) PointMode        ECC pointer operation mode, which can be one the the value:
*                               EccAdd_Mode ：P(X1,Y1) + S(X2,Y2) = R(X3,Y3)
*                               EccDou_Mode ：2 *P(X1,Y1) = R(X3,Y3)
*                               EccMul_Mode ：k*P(X1,Y1) = R(X3,Y3)
*                           2) pECCPxAddr       pointer to the x axile value of the first point on the ECC curve, pECCPxAddr[0] is LSB
*                           3) pECCPyAddr       pointer to the Y axile value of the first point on the ECC curve, pECCPyAddr[0] is LSB
*                           4) pECCSxAddr       pointer to the x axile value of the second point on the ECC curve, pECCSxAddr[0] is LSB
*                           5) pECCSyAddr       pointer to the x axile value of the s pointer on the ECC curve, pECCSyAddr[0] is LSB
*                           6) pKscalAddr       pointer to k whichi is the multiplier of ECC point, pKscalAddr[0] is LSB
*
* @retval None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_PointOperate(ECC_PointOperate_InputTypedef* ECC_PointOperate_InputStruct)
{
    uint32_t i =0U;
    uint32_t tempreg = 0U;

    /*  assert_param  */
    if(ECC_PointOperate_InputStruct != NULL)
    {	
        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_PointOperate_InputStruct->PointMode);
                                                          /*!< Configure operation mode：ECC pointer add       */
        switch(ECC_PointOperate_InputStruct->PointMode)
        {
            case EccAdd_Mode:
              for(i=0U;i<ECC_PARAM_SIZE;i++)
              {
                  HT_ECC->PXREG = *(ECC_PointOperate_InputStruct->pECCPxAddr+i);    /*!< load ECC_Px            */
                  HT_ECC->PYREG = *(ECC_PointOperate_InputStruct->pECCPyAddr+i);    /*!< load ECC_Py            */
                  HT_ECC->SXREG = *(ECC_PointOperate_InputStruct->pECCSxAddr+i);    /*!< load ECC_Sx            */   
                  HT_ECC->SYREG = *(ECC_PointOperate_InputStruct->pECCSyAddr+i);    /*!< load ECC_Sy            */
              }
              break;
            case EccDou_Mode:
              for(i=0U;i<ECC_PARAM_SIZE;i++)
              {
                  HT_ECC->PXREG = *(ECC_PointOperate_InputStruct->pECCPxAddr+i);    /*!< load ECC_Px          */
                  HT_ECC->PYREG = *(ECC_PointOperate_InputStruct->pECCPyAddr+i);    /*!< loadECC_Py           */
              }
              break;
            case EccMul_Mode:
              for(i=0U;i<ECC_PARAM_SIZE;i++)
              {
                  HT_ECC->PXREG = *(ECC_PointOperate_InputStruct->pECCPxAddr+i);    /*!< load ECC_Px          */
                  HT_ECC->PYREG = *(ECC_PointOperate_InputStruct->pECCPyAddr+i);    /*!< load ECC_Py          */
                  HT_ECC->KEYREG = *(ECC_PointOperate_InputStruct->pKscalAddr+i);   /*!< load k               */
              }
              break;
            default:
              break;
        }
        HT_ECC->ECCSTA = RESET;                             /*!< Clear flag                      */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;              /*!< start operation                   */
    }
}

/**
*********************************************************************************************************
*                              ECC Public Key Validation operation
*
* @brief  ECC public key verification，PKV
*
* @param  ECC_PKV_InputStruct: Pointer to a ECC_PKV_InputTypedef strcture  which contains 5 parameter:
*                           1) pECCpAddr        pointer to prime P of GF(P) pECCpAddr[0] is LSB
*                           2) pECCaAddr        Pointer to parameter a of the Elliptic Curve function, pECCaAddr[0] is LSB
*                           3) pECCbAddr        Pointer to parameter B of the Elliptic Curve function, pECCbAddr[0] is LSB
*                           4) pECCPxAddr       Pointer to x axis value of point G, pECCGxAddr[0]is LSB
*                           5) pECCPyAddr       Pointer to y axis value of point G, pECCGyAddr[0]is LSB
*
* @retval None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_PublickeyValidate(ECC_PKV_InputTypedef* ECC_PKV_InputStruct)
{
    uint32_t i = 0U;
    uint32_t tempreg = 0U;
   
    /*  assert_param  */
    if(ECC_PKV_InputStruct != NULL)
    {

        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_ECCCON_OP_SEL_PKV);
                                                          /*!< Configure operation mode：PKV        */
        for(i=0U;i<ECC_PARAM_SIZE;i++)
        {
            HT_ECC->PREG = *(ECC_PKV_InputStruct->pECCpAddr+i);     /*!< load ECC_p        */       
            HT_ECC->AREG = *(ECC_PKV_InputStruct->pECCaAddr+i);     /*!< load ECC_a        */        
            HT_ECC->PXREG = *(ECC_PKV_InputStruct->pECCPxAddr+i);   /*!< load ECC_Px       */
            HT_ECC->PYREG = *(ECC_PKV_InputStruct->pECCPyAddr+i);   /*!< load ECC_Py       */
            HT_ECC->SYREG = *(ECC_PKV_InputStruct->pECCbAddr+i);    /*!< load ECC_b        */
        }
        HT_ECC->ECCSTA = 0x0U;                             /*!< Clear flag                   */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;              /*!< Start operation               */
        }
}


/**
*********************************************************************************************************
*                              Modular operation
*
* @brief  Modular Operation
*
* @param  ECC_ModOperate_InputStruct    pointer to ECC_ModOperate_InputTypedef  which contains 4 parameter:
*                           1) ModMode        Modular operation type，the value can be one of the ECC_ModMode_TypeDef enum vales:
*                               ModAdd_Mode ：PX + PY ( mod n ) = RX
*                               ModSub_Mode ：PX - PY ( mod n ) = RX
*                               ModMul_Mode ：PX * PY ( mod n ) = RX
*                               ModDiv_Mode ：PY / PX ( mod n ) = RX
*                               ModInv_Mode ：PX-1 ( mod n ) = RX
*                           2) pnAddr         pointer to the big modular prime n : pnAddr[0]is LSB
*                           3) pPxAddr        pointer to the first modular operation parameter, pPxAddr[0]is LSB
*                           4) pPyAddr        pointer to the second modular operation parameter, pPyAddr[0]is LSB
*
* @retval None
*
* @Note   ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_ModOperate(ECC_ModOperate_InputTypedef* ECC_ModOperate_InputStruct)
{
    uint32_t i;
    uint32_t tempreg = 0U;

    /*  assert_param  */
    if(ECC_ModOperate_InputStruct != NULL)
    {

        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_ModOperate_InputStruct->ModMode);
                                                          /*!< Configure operation mode：modular add   */
        switch(ECC_ModOperate_InputStruct->ModMode)
        {
            case ModAdd_Mode:
            case ModSub_Mode:
            case ModMul_Mode:
            case ModDiv_Mode:
              for(i=0U;i<ECC_PARAM_SIZE;i++)
              {
                  HT_ECC->PREG = *(ECC_ModOperate_InputStruct->pnAddr+i);     /*!< load n    */
                  HT_ECC->PXREG = *(ECC_ModOperate_InputStruct->pPxAddr+i);   /*!< load Px   */
                  HT_ECC->PYREG = *(ECC_ModOperate_InputStruct->pPyAddr+i);   /*!< load Py   */
              }
              break;
            case ModInv_Mode:
              for(i=0U;i<ECC_PARAM_SIZE;i++)
              {
                  HT_ECC->PREG = *(ECC_ModOperate_InputStruct->pnAddr+i);     /*!< load n   */
                  HT_ECC->PXREG = *(ECC_ModOperate_InputStruct->pPxAddr+i);   /*!< load Px  */
              }
              break;
            default:
              break;
        }
        HT_ECC->ECCSTA = RESET;                             /*!< Clear flag                       */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;               /*!< Start operation                    */
    }
}


/**
*********************************************************************************************************
*                                      Get ECC Signature Operation result   ~~~~~linda ADD
*
* @brief  Get the ECC Signature operation result
*
* @param  ECC_ECDSA_SignOperate_OutputStruct pointer yo a  ECC_ECDSA_SignOperate_OutputStruct structure that caontains 2 parameters:
*                   1) prAddr        pointer to r of ECDSA signature result, prAddr[0] is LSB
*                   2) psAddr        pointer to s of ECDSA signature result, psAddr[0] is LSB
*
* @retval None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_ECDSA_S_Read(ECC_ECDSA_SignOperate_OutputTypedef* ECC_ECDSA_SignOperate_OutputStruct)
{
    uint32_t i = 0U ;
    uint32_t *rPtr, *sPtr;
    /*  assert_param  */
    if(ECC_ECDSA_SignOperate_OutputStruct != NULL)
    {	
        rPtr = ECC_ECDSA_SignOperate_OutputStruct->prAddr +7;
        sPtr = ECC_ECDSA_SignOperate_OutputStruct->psAddr +7;
        for(i=0U;i<ECC_PARAM_SIZE;i++)
        {
            *rPtr-- = HT_ECC->RXREG;
            *sPtr-- = HT_ECC->RYREG;
        }
    }
}


/**
*********************************************************************************************************
*                                      Get ECC Operation result   
*
* @brief  Get the ECC point operation result
*
* @param  ECC_PointOperate_OutputStruct pointer yo a  ECC_PointOperate_OutputTypedef structure that caontains 2 parameters:
*                   1) pRxAddr        pointer to x axile value of the point on the ECC curveor r of ECDSA result, pRxAddr[0] is LSB
*                   2) pRyAddr        pointer to Y axile value of the point on the ECC curveor S of ECDSA result, pRyAddr[0] is LSB
*
* @retval None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_PointOperate_Read(ECC_PointOperate_OutputTypedef* ECC_PointOperate_OutputStruct)
{
    uint32_t i = 0U ;
    uint32_t *xPtr, *yPtr;
    /*  assert_param  */
    if(ECC_PointOperate_OutputStruct != NULL)
    {	
        xPtr = ECC_PointOperate_OutputStruct->pRxAddr + 7;
        yPtr = ECC_PointOperate_OutputStruct->pRyAddr + 7;
        for(i=0U;i<ECC_PARAM_SIZE;i++)
        {
            *xPtr-- = HT_ECC->RXREG;
            *yPtr-- = HT_ECC->RYREG;
        }
    }
}

/**
*********************************************************************************************************
*                                      Get Big Number Modular Operation Result
*
* @brief  Get the modular operation result
*
* @param  pModOperateOutAddr: Pointter to a uint32_t type array which is to store the modular opeartion result 
*
*
* @retval None
*
* @Note   ECC(256) only
*********************************************************************************************************
*/

void HT_ECC_ModOperate_Read(uint32_t *pModOperateOutAddr)
{
    uint32_t i = 0U;

    /*  assert_param  */
    if(pModOperateOutAddr != NULL)
    {
        pModOperateOutAddr += 7;
        for(i=0U;i<ECC_PARAM_SIZE;i++)
        {
            *pModOperateOutAddr-- = HT_ECC->RXREG;
        }
    }
}

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE ECC INTERRUPT
*
* @brief  Enable or Disable the ECC interrupt
*
* @param  NewState
*                @arg ENABLE：Enable
*                @arg DISABLE：Disable
* @retval None
*
* @Note   ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_ITConfig(FunctionalState NewState)
{
    /*  assert_param  */
    assert_param(IS_HT_ECC_IT_STATUS(NewState));
	
    if (NewState != DISABLE)
    {
        HT_ECC->ECCCON |= (uint32_t)ECC_ECCCON_ECCIE;            /*!< Enable ECC interrupt          */
    }
    else
    {
        HT_ECC->ECCCON &= ~(uint32_t)ECC_ECCCON_ECCIE;           /*!< Disable ECC interrupt           */
    }
}

/**
*********************************************************************************************************
*                            GET SPECIFIED ECC INTERRUPT FLAG STATUS
*
* @brief Get ECC Inerrupt flag 
*
* @param ITFlag     IT flag type to get, the parameter can be one of the ECC_ITFlagTypeDef enum values:
*                        @arg ECC_IF
*                        @arg ECC_FLG_BUSY
*                        @arg ECC_FLG_ECDSA_V
*                        @arg ECC_FLG_ECDSA_S
*                        @arg ECC_FLAG
*
* @retval ITStatus    = SET：  Interrupt flag is set
*                     = RESET：Interrupt flag is reset
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
ITStatus HT_ECC_ITFlagStatusGet(ECC_ITFlagTypeDef ITFlag)
{
    ITStatus Status = RESET;
    /*  assert_param  */
    assert_param(IS_HT_ECC_IT_Flag(ITFlag));
    if (HT_ECC->ECCSTA & ITFlag)
    {
        Status =  SET;                        /*!< ECC Interrupt Flag is set   */
    }
    else
    {
        Status = RESET;                      /*!< ECC Interrupt Flag is reset */
    }
    return Status;
}

/**
*********************************************************************************************************
*                                   CLEAR ECC INTERRUPT FLAG
*
* @brief Clear ECC interrupt flag
*
* @param ITFlag    IT flag type to clear, the parameter can be one or a combination of the ECC_ITFlagTypeDef
*					enum values 
*                        @arg ECC_IF
*                        @arg ECC_FLG_BUSY
*                        @arg ECC_FLG_ECDSA_V
*                        @arg ECC_FLG_ECDSA_S
*                        @arg ECC_FLG_PKV
*
* @retval None
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
void HT_ECC_ClearITPendingBit(ECC_ITFlagTypeDef ITFlag)
{
    /*  assert_param  */
	assert_param(IS_HT_ECC_IT_Flag(ITFlag));

    HT_ECC->ECCSTA   = ~((uint32_t)ITFlag);                  /*!< Clear ECC Interrupt Flag       */

}

/**
*********************************************************************************************************
*                            GET ECC BUSY STATUS
*
* @brief  GET ECC Module busy status
*
* @param  None
*
* @retval ITStatus    = SET：  busy
*                     = RESET：ilde
*
* @Note: ECC(256) only
*********************************************************************************************************
*/
ITStatus HT_ECC_Busy_StatusGet(void)
{
    /*  assert_param  */
    return (ITStatus)(HT_ECC->ECCSTA & ECC_FLG_BUSY);               /*!< return ECC busy status          */
}


#endif                                        /* This File Only support HT6x2x and HT501x */

#if defined USE_ECC384
/**
*********************************************************************************************************
*                              ECC ECDSA Initialization
*
* @brief  Initialize the parameters of ECC ECDSA
*
* @param  ECC_ECDSA_InitStruct: Pointer to a ECC_ECDSA_InitTypedef structure that containe 5 parameters:
*                           1) pECCpAddr        Pointer to the Prime P of GF(P),ECCpAddr[0] is LSB
*                           2) pECCaAddr        Pointer to parameter a of the Elliptic Curve function, pECCaAddr[0] is LSB
*                           3) pECCbAddr        Pointer to parameter b of the Elliptic Curve function, pECCbAddr[0] is LSB
*                           4) pECCnAddr        Pointer to the order n of G which is a point on the curve, pECCnAddr[0]is LSB
*                           5) pECCGxAddr       Pointer to x which is x axis value of point G, pECCGxAddr[0]is LSB
*                           6) pECCGyAddr       Pointer to y which is x axis value of point G, pECCGyAddr[0]is LSB
*
* @retval  None
*
* Note: ECC384 only
*********************************************************************************************************
*/
void HT_ECC_ECDSA_Init(ECC_ECDSA_InitTypedef* ECC_ECDSA_InitStruct)
{
    uint32_t i;
    if(ECC_ECDSA_InitStruct !=NULL)
    {
        for(i=0U;i<ECC384_PARAM_SIZE;i++)
        {
            HT_ECC->PREG[i] = *(ECC_ECDSA_InitStruct->pECCpAddr+i);      /*!< load ECC_P  */
            HT_ECC->AREG[i] = *(ECC_ECDSA_InitStruct->pECCaAddr+i);      /*!< load ECC_a  */
            HT_ECC->BREG[i] = *(ECC_ECDSA_InitStruct->pECCbAddr+i);      /*!< load ECC_b */
            HT_ECC->PXREG[i] = *(ECC_ECDSA_InitStruct->pECCGxAddr+i);    /*!< load ECC_Gx */
            HT_ECC->PYREG[i] = *(ECC_ECDSA_InitStruct->pECCGyAddr+i);    /*!< load ECC_Gy */
            HT_ECC->NREG[i] = *(ECC_ECDSA_InitStruct->pECCnAddr+i);      /*!< load ECC_n  */
        }
    }
}

/**
*********************************************************************************************************
*                              ECC PointOperate Initialization
*
* @brief Initialize the parameter of ECC PointOperate
*
* @param ECC_PointOperate_InitStruct:    Pointer to a ECC_PointOperate_InitTypedef structure that contains 2 parameters:
*                           1) pECCpAddr        Pointer to the Prime P of GF(P),ECCpAddr[0] is LSB
*                           2) pECCaAddr        Pointer to parameter a of the Elliptic Curve function, pECCaAddr[0] is LSB
*
* @retval None
*
* @Note: ECC384 only
*********************************************************************************************************
*/
void HT_ECC_PointOperate_Init(ECC_PointOperate_InitTypedef* ECC_PointOperate_InitStruct)
{
    uint32_t i;
    if(ECC_PointOperate_InitStruct != NULL)
    {
        for(i=0U;i<ECC384_PARAM_SIZE;i++)
        {
            HT_ECC->PREG[i] = *ECC_PointOperate_InitStruct->pECCpAddr++;     /*!< load ECC_p */
            HT_ECC->AREG [i]= *ECC_PointOperate_InitStruct->pECCaAddr++;     /*!< load ECC_a */
        }
    }
}

/**
*********************************************************************************************************
*                              ECC Digital Signature Algorithm (ECDSA) Signature Operation
*
* @brief ECDSA Operation, ECDSA-S
*
* @param ECC_ECDSA_S_InputStruct: Pointer to ECC_ECDSA_Signature_InputTypedef structure which contains 3 operation input parameters:
*                           1) pdAddr    pointer to the private key d, pdAddr[0] is LSB       
*                           2) pkAddr    pointer to the rand k, pkAddr[0] is LSB     
*                           3) pMAddr    pointer t the message hash value, pMAddr[0] is LSB   
*
* @retval 无
*
* @Note: ECC384 only
*********************************************************************************************************
*/
void HT_ECC_ECDSA_S(ECC_ECDSA_Signature_InputTypedef* ECC_ECDSA_S_InputStruct)
{
    uint32_t i;
    uint32_t tempreg = 0U;
    if(ECC_ECDSA_S_InputStruct != NULL)
    {
        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_ECCCON_OP_SEL_ECDSA_S);
                                                          /*!< configure the operation mode：ECDSA-S        */
        for(i=0U;i<ECC384_PARAM_SIZE;i++)
        {
            HT_ECC->SXREG[i] = *(ECC_ECDSA_S_InputStruct->pdAddr+i);        /*!< load d*/
            HT_ECC->KEYREG[i] = *(ECC_ECDSA_S_InputStruct->pkAddr+i);       /*!< load k*/
            HT_ECC->SYREG[i] = *(ECC_ECDSA_S_InputStruct->pMAddr+i);        /*!< load M*/
        }
        HT_ECC->ECCSTA = 0x0U;                             /*!< Clear Flag                       */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;              /*!< Start operation                  */
    }
}

/**
*********************************************************************************************************
*                              ECC Digital Signature Algorithm (ECDSA) Verification operation
*
* @brief ECDSA verification Operation，ECDSA-V
*
* @param ECC_ECDSA_V_InputStruct: Pointer to ECC_ECDSA_Verification_InputTypedef structure which contains 5 operation input parameters:
*                           1) pECCDxAddr       pointer to the x which is x axis value of public key, pECCDxAddr[0] is LSB
*                           2) pECCDyAddr       pointer to the y which is y axis value of public key, pECCDyAddr[0] is LSB
*                           3) pMAddr           pointer to the message hash value, pMAddr[0] is LSB
*                           4) prAddr;          pointer to the ECDSA result r, prAddr[0]is LSB
*                           5) psAddr;          pointer to the ECDSA result s, prAddr[0]is LSB
*
* @retval None
*
* @Note: ECC384 Only
*********************************************************************************************************
*/
void HT_ECC_ECDSA_V(ECC_ECDSA_Verification_InputTypedef* ECC_ECDSA_V_InputStruct)
{
    uint32_t i = 0U;
    uint32_t tempreg = 0U;
    if(ECC_ECDSA_V_InputStruct != NULL)
    {
        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_ECCCON_OP_SEL_ECDSA_V);
                                                          /*!< Configure operation mode：ECDSA-v        */
        for(i=0U;i<ECC384_PARAM_SIZE;i++)
        {
            HT_ECC->SXREG[i] = *(ECC_ECDSA_V_InputStruct->pECCDxAddr+i);    /*!< Load ECC_Dx         */
            HT_ECC->SYREG[i] = *(ECC_ECDSA_V_InputStruct->pECCDyAddr+i);    /*!< Load ECC_Dy         */
            HT_ECC->KEYREG[i] = *(ECC_ECDSA_V_InputStruct->pMAddr+i);       /*!< Load M              */
            HT_ECC->RXREG[i] = *(ECC_ECDSA_V_InputStruct->prAddr+i);        /*!< Load r              */
            HT_ECC->RYREG[i] = *(ECC_ECDSA_V_InputStruct->psAddr+i);        /*!< Load s              */
        }
        HT_ECC->ECCSTA = RESET;                             /*!< Clear flag                      */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;               /*!< Start Operation                 */
    }
}
/**
*********************************************************************************************************
*                              ECC Point operation
*
* @brief ECC point operation
*
* @param ECC_PointOperate_InputStruct: Pointer to the ECC_PointOperate_InputTypedef structure which contains 6 paramters:
*                           1) PointMode        ECC pointer operation mode, which can be one the the value:
*                               EccAdd_Mode ：P(X1,Y1) + S(X2,Y2) = R(X3,Y3)
*                               EccDou_Mode ：2 *P(X1,Y1) = R(X3,Y3)
*                               EccMul_Mode ：k*P(X1,Y1) = R(X3,Y3)
*                           2) pECCPxAddr       pointer to the x axile value of the first point on the ECC curve, pECCPxAddr[0] is LSB
*                           3) pECCPyAddr       pointer to the Y axile value of the first point on the ECC curve, pECCPyAddr[0] is LSB
*                           4) pECCSxAddr       pointer to the x axile value of the second point on the ECC curve, pECCSxAddr[0] is LSB
*                           5) pECCSyAddr       pointer to the x axile value of the s pointer on the ECC curve, pECCSyAddr[0] is LSB
*                           6) pKscalAddr       pointer to k whichi is the multiplier of ECC point, pKscalAddr[0] is LSB
*
* @retval None
*
* @Note: ECC384 Only
*********************************************************************************************************
*/
void HT_ECC_PointOperate(ECC_PointOperate_InputTypedef* ECC_PointOperate_InputStruct)
{
    uint32_t i;
    uint32_t tempreg = 0U;
    if(ECC_PointOperate_InputStruct != NULL)
    {
        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_PointOperate_InputStruct->PointMode);
                                                          /*!< Configure operation mode：ECC pointer add       */
        switch(ECC_PointOperate_InputStruct->PointMode)
        {
            case EccAdd_Mode:
              for(i=0U;i<ECC384_PARAM_SIZE;i++)
              {
                  HT_ECC->PXREG[i] = *(ECC_PointOperate_InputStruct->pECCPxAddr+i);    /*!< load ECC_Px            */
                  HT_ECC->PYREG[i] = *(ECC_PointOperate_InputStruct->pECCPyAddr+i);    /*!< load ECC_Py            */
                  HT_ECC->SXREG[i]= *(ECC_PointOperate_InputStruct->pECCSxAddr+i);     /*!< load ECC_Sx            */
                  HT_ECC->SYREG[i] = *(ECC_PointOperate_InputStruct->pECCSyAddr+i);    /*!< load ECC_Sy            */
              }
              break;
            case EccMul_Mode:
              for(i=0U;i<ECC384_PARAM_SIZE;i++)
              {
                  HT_ECC->PXREG[i] = *(ECC_PointOperate_InputStruct->pECCPxAddr+i);    /*!< load ECC_Px          */
                  HT_ECC->PYREG[i] = *(ECC_PointOperate_InputStruct->pECCPyAddr+i);    /*!< load ECC_Py          */
                  HT_ECC->KEYREG[i] = *(ECC_PointOperate_InputStruct->pKscalAddr+i);   /*!< load k               */
              }
              break;
            default:
              break;
        }
        HT_ECC->ECCSTA = 0x0U;                             /*!< Clear flag                        */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;              /*!< start operation                   */

    }
}

/**
*********************************************************************************************************
*                              ECC Public Key Validation operation
*
* @brief  ECC public key verification，PKV
*
* @param  ECC_PKV_InputStruct: Pointer to a ECC_PKV_InputTypedef strcture  which contains 5 parameter:
*                           1) pECCpAddr        pointer to prime P of GF(P) pECCpAddr[0] is LSB
*                           2) pECCaAddr        Pointer to parameter a of the Elliptic Curve function, pECCaAddr[0] is LSB
*                           3) pECCbAddr        Pointer to parameter B of the Elliptic Curve function, pECCbAddr[0] is LSB
*                           4) pECCPxAddr       Pointer to x axis value of point G, pECCGxAddr[0]is LSB
*                           5) pECCPyAddr       Pointer to y axis value of point G, pECCGyAddr[0]is LSB
*
* @retval None
*
* @Note: ECC384 Only
*********************************************************************************************************
*/
void HT_ECC_PublickeyValidate(ECC_PKV_InputTypedef* ECC_PKV_InputStruct)
{
    uint32_t i = 0U;
    uint32_t tempreg = 0U;
    if(ECC_PKV_InputStruct != NULL)
    {
        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_ECCCON_OP_SEL_PKV);
                                                          /*!< Configure operation mode：PKV  */
        for(i=0U;i<ECC384_PARAM_SIZE;i++)
        {
            HT_ECC->PREG[i] = *(ECC_PKV_InputStruct->pECCpAddr+i);     /*!< load ECC_p        */
            HT_ECC->AREG[i] = *(ECC_PKV_InputStruct->pECCaAddr+i);     /*!< load ECC_a        */ 
            HT_ECC->BREG[i] = *(ECC_PKV_InputStruct->pECCbAddr+i);     /*!< load ECC_b        */ 
            HT_ECC->PXREG[i] = *(ECC_PKV_InputStruct->pECCPxAddr+i);   /*!< load ECC_Px       */
            HT_ECC->PYREG[i] = *(ECC_PKV_InputStruct->pECCPyAddr+i);   /*!< load ECC_Py       */
            
        }
        HT_ECC->ECCSTA = 0x0U;                             /*!< Clear flag                   */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;              /*!< Start operation              */
    }
}


/**
*********************************************************************************************************
*                              Modular operation
*
* @brief  Modular Operation
*
* @param  ECC_ModOperate_InputStruct    pointer to ECC_ModOperate_InputTypedef  which contains 4 parameter:
*                           1) ModMode        Modular operation type，the value can be one of the ECC_ModMode_TypeDef enum vales:
*                               ModAdd_Mode ：PX + PY ( mod n ) = RX
*                               ModSub_Mode ：PX - PY ( mod n ) = RX
*                               ModMul_Mode ：PX * PY ( mod n ) = RX
*                               ModDiv_Mode ：PY / PX ( mod n ) = RX
*                               ModInv_Mode ：PX-1 ( mod n ) = RX
*                           2) pnAddr         pointer to the big modular prime n : pnAddr[0]is LSB
*                           3) pPxAddr        pointer to the first modular operation parameter, pPxAddr[0]is LSB
*                           4) pPyAddr        pointer to the second modular operation parameter, pPyAddr[0]is LSB
*
* @retval None
*
* @Note: ECC384 Only
*********************************************************************************************************
*/
void HT_ECC_ModOperate(ECC_ModOperate_InputTypedef* ECC_ModOperate_InputStruct)
{
    uint32_t i;
    uint32_t tempreg = 0U;
    if(ECC_ModOperate_InputStruct != NULL)
    {
        tempreg = HT_ECC->ECCCON;
        tempreg = ((tempreg & (~ECC_ECCCON_OP_SEL)) | ECC_ModOperate_InputStruct->ModMode);
                                                          /*!< Configure operation mode：modular add   */
        switch(ECC_ModOperate_InputStruct->ModMode)
        {
            case ModAdd_Mode:
            case ModSub_Mode:
            case ModMul_Mode:
            case ModDiv_Mode:
              for(i=0U;i<ECC384_PARAM_SIZE;i++)
              {
                  HT_ECC->PREG[i] = *(ECC_ModOperate_InputStruct->pnAddr+i);     /*!< load n    */
                  HT_ECC->PXREG[i] = *(ECC_ModOperate_InputStruct->pPxAddr+i);   /*!< load Px   */
                  HT_ECC->PYREG[i] = *(ECC_ModOperate_InputStruct->pPyAddr+i);   /*!< load Py   */
              }
              break;
            case ModInv_Mode:
              for(i=0U;i<ECC384_PARAM_SIZE;i++)
              {
                  HT_ECC->PREG[i] = *(ECC_ModOperate_InputStruct->pnAddr+i);     /*!< load n   */
                  HT_ECC->PXREG[i] = *(ECC_ModOperate_InputStruct->pPxAddr+i);   /*!< load Px  */
              }
              break;
            default:
              break;
        }
        HT_ECC->ECCSTA = 0x0U;                              /*!< Clear flag                  */
        HT_ECC->ECCCON = tempreg;
        HT_ECC->ECCCON |= ECC_ECCCON_OP_STR;               /*!< Start operation             */
        
    }
    
}

/**
*********************************************************************************************************
*                                      Get ECC Signature Operation result   
*
* @brief  Get the ECC Signature operation result
*
* @param  ECC_ECDSA_SignOperate_OutputStruct pointer yo a  ECC_ECDSA_SignOperate_OutputStruct structure that caontains 2 parameters:
*                   1) prAddr        pointer to r of ECDSA signature result, prAddr[0] is LSB
*                   2) psAddr        pointer to s of ECDSA signature result, psAddr[0] is LSB
*
* @retval None
*
* @Note: ECC384 Only
*********************************************************************************************************
*/
void HT_ECC_ECDSA_S_Read(ECC_ECDSA_SignOperate_OutputTypedef* ECC_ECDSA_SignOperate_OutputStruct)
{
    uint32_t i = 0U ;
    uint32_t *rPtr, *sPtr;
    /*  assert_param  */
    if(ECC_ECDSA_SignOperate_OutputStruct != NULL)
    {	
        rPtr = ECC_ECDSA_SignOperate_OutputStruct->prAddr;
        sPtr = ECC_ECDSA_SignOperate_OutputStruct->psAddr;
        for(i=0U;i<ECC384_PARAM_SIZE;i++)
        {
            *rPtr++ = HT_ECC->RXREG[i];
            *sPtr++ = HT_ECC->RYREG[i];
        }
    }
}


/**
*********************************************************************************************************
*                                      Get ECC Point Operation result   
*
* @brief  Get the ECC point operation result
*
* @param  ECC_PointOperate_OutputStruct pointer yo a  ECC_PointOperate_OutputTypedef structure that caontains 2 parameters:
*                   1) pRxAddr        pointer to x axile value of the point on the ECC curveor r of ECDSA result, pRxAddr[0] is LSB
*                   2) pRyAddr        pointer to Y axile value of the point on the ECC curveor S of ECDSA result, pRyAddr[0] is LSB
*
* @retval None
*
* @Note: ECC384 Only
*********************************************************************************************************
*/
void HT_ECC_PointOperate_Read(ECC_PointOperate_OutputTypedef* ECC_PointOperate_OutputStruct)
{
    uint8_t i;
    if(ECC_PointOperate_OutputStruct != NULL)
    {
        for(i=0U;i<ECC384_PARAM_SIZE;i++)
        {
            ECC_PointOperate_OutputStruct->pRxAddr[i] = HT_ECC->RXREG[i];
            ECC_PointOperate_OutputStruct->pRyAddr[i] = HT_ECC->RYREG[i];
        }
    }
}

/**
*********************************************************************************************************
*                                      Get Big Number Modular Operation Result
*
* @brief  Get the modular operation result
*
* @param  pModOperateOutAddr: Pointter to a uint32_t type array which is to store the modular opeartion result 
*
*
* @retval None
*
* @Note   ECC384 Only
*********************************************************************************************************
*/

void HT_ECC_ModOperate_Read(uint32_t *pModOperateOutAddr)
{
    uint8_t i;
    if(pModOperateOutAddr != NULL)
    {
        for(i=0U;i<ECC384_PARAM_SIZE;i++)
        {
            pModOperateOutAddr[i] = HT_ECC->RXREG[i];
        }
    }
}

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE ECC INTERRUPT
*
* @brief  Enable or Disable the ECC interrupt
*
* @param  NewState
*                @arg ENABLE：Enable
*                @arg DISABLE：Disable
* @retval None
*
* @Note   ECC384 Only
*********************************************************************************************************
*/
void HT_ECC_ITConfig(FunctionalState NewState)
{
    /*  assert_param  */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (NewState != DISABLE)
    {
        HT_ECC->ECCCON |= (uint32_t)ECC_ECCCON_ECCIE;            /*!< Enable ECC interrupt          */
    }
    else
    {
        HT_ECC->ECCCON &= ~(uint32_t)ECC_ECCCON_ECCIE;           /*!< Disable ECC interrupt           */
    }
}

/**
*********************************************************************************************************
*                            GET SPECIFIED ECC INTERRUPT FLAG STATUS
*
* @brief Get ECC Inerrupt flag 
*
* @param ITFlag     IT flag type to get, the parameter can be one of the ECC_ITFlagTypeDef enum values:
*                        @arg ECC_IF
*                        @arg ECC_FLG_BUSY
*                        @arg ECC_FLG_ECC_V
* @retval ITStatus    = SET：  Interrupt flag is set
*                     = RESET：Interrupt flag is reset
*
* @Note: ECC384 Only
*********************************************************************************************************
*/
ITStatus HT_ECC_ITFlagStatusGet(ECC_ITFlagTypeDef ITFlag)
{
    /*  assert_param  */
    assert_param(IS_HT_ECC_IT_Flag(ITFlag));
    if (HT_ECC->ECCSTA & ITFlag)
    {
        return SET;                        /*!< ECC Interrupt Flag is set   */
    }
    else
    {
        return RESET;                      /*!< ECC Interrupt Flag is reset */
    }
}

/**
*********************************************************************************************************
*                                   CLEAR ECC INTERRUPT FLAG
*
* @brief Clear ECC interrupt flag
*
* @param ITFlag    IT flag type to clear, the parameter can be one or a combination of the ECC_ITFlagTypeDef
*						enum values
*                        @arg ECC_IF
*                        @arg ECC_FLG_BUSY
*                        @arg ECC_FLG_ECC_V
* @retval None
*
* @Note: ECC384 Only
*********************************************************************************************************
*/
void HT_ECC_ClearITPendingBit(ECC_ITFlagTypeDef ITFlag)
{
    /*  assert_param  */
    assert_param(IS_HT_ECC_IT_Flag(ITFlag));
    HT_ECC->ECCSTA  &= ~((uint32_t)ITFlag);                  /*!< Clear ECC Interrupt Flag       */

}

/**
*********************************************************************************************************
*                            GET ECC BUSY STATUS
*
* @brief  GET ECC Module busy status
*
* @param  None
*
* @retval ITStatus    = SET：  busy
*                     = RESET：ilde
*
* Note: ECC384 Only
*********************************************************************************************************
*/
ITStatus HT_ECC_Busy_StatusGet(void)
{
    /* assert_param  */
    return (ITStatus)(HT_ECC->ECCSTA & ECC_FLG_BUSY);               /*!< 返回ECC busy status          */
}


#endif 

#if (USE_HT_ECC_REGISTER_CALLBACKS == 1U)
/**
*********************************************************************************************************
*                            ECC Interrupt Handler
*
* @brief  ECC interrupt sevice function 
*
* @param  ECC_ECDSA_InitStruct: Pointer to ECC_ECDSA_InitTypedefstructure that contains
*                               the configuration of ECC module
* @retval None
*
* @Note: For both ECC(256) and ECC384
*********************************************************************************************************
*/
void HT_ECC_IRQHandler(ECC_InitTypeDef *ECC_InitStruct)
{
	/*  assert_param  */
	if(ECC_InitStruct != NULL)
	{
		/*Call register ECC callback*/
		ECC_InitStruct->ECCCallback(ECC_InitStruct);
	}
}

/**
*********************************************************************************************************
*                           Register ECC user Callback 
*
* @brief  Register a User ECC Callback
*         TO be used insted os the weak predefined callback
* @param  Pointer to ARG_InitTypeDef structure that contains
*         the configuration of AES module
* @retval status
* @note: when USE_HT_ECC_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register 
*		  himself defined callback function. For both ECC(256) and ECC384
*********************************************************************************************************
*/
StatusTypeDef HT_ECC_RegisterCallback(ECC_InitTypeDef *ECC_InitStruct,  pECC_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        ECC_InitStruct->ErrorCode |= ECC_ERROR_INVALID_CALLBACK;
        status = ERROR;
    }
    else
    {
        ECC_InitStruct->ECCCallback = pCallback;
    }

    return status;	
}

/**
*********************************************************************************************************
*                           Initial ECC Callback settings
*
* @brief  Initialize the callbacks to the default values
*
* @param  ECC_InitStruct: Pointer to ECC_ECDSA_InitTypedefstructure that contains
*                               the configuration of ECC module
* @retval None
*
* @Note: For both ECC(256) and ECC384
*********************************************************************************************************
*/
void ECC_InitCallbacksToDefault(ECC_InitTypeDef* ECC_InitStruct)
{
    /*  assert_param  */
    if(ECC_InitStruct != NULL)
    {
	/*Init the ECC Callback setting*/
	ECC_InitStruct->ECCCallback = HT_ECC_Callback;
    }
}
/**
*********************************************************************************************************
*                            ECC Interrupt Callback
*
* @brief  ECC interrupt callback function 
*
* @param  ECC_InitStruct: Pointer to ECC_ECDSA_InitTypedefstructure that contains
*                               the configuration of ECC module
* @retval None
*
* Note: For both ECC(256) and ECC384
*********************************************************************************************************
*/
__weak void HT_ECC_Callback(ECC_InitTypeDef* ECC_InitStruct)
{   
		
	UNUSED(ECC_InitStruct);
}
#endif

#endif
