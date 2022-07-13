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
* File         : ht6xxx_exti.c
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_EXTI_C

#include "ht6xxx_lib.h"


/*
*********************************************************************************************************
*                                           Local macro/structure
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                             Local variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            Local function declaration
*********************************************************************************************************
*/
#if (USE_HT_EXTI_REGISTER_CALLBACKS ==1U)
static void Exti_Rise_IT(EXTI_TypeDef *ExtiStruct);
static void Exti_Fall_IT(EXTI_TypeDef *ExtiStruct);

#endif


/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE EXTI RISE INTERRUPT

* @brief:  Enable or disable EXTI rising edge interrupt
* @param   ITEn: EXTI interrupt set bit.
*   This parameter can be the following values
*                        @arg INT_EXTIE_RIE_INT0
*                        @arg INT_EXTIE_RIE_INT1
*                        @arg INT_EXTIE_RIE_INT2
*                        @arg INT_EXTIE_RIE_INT3
*                        @arg INT_EXTIE_RIE_INT4
*                        @arg INT_EXTIE_RIE_INT5
*                        @arg INT_EXTIE_RIE_INT6
*                        @arg INT_EXTIE2_RIE_INT7   (If support)
*                        @arg INT_EXTIE2_RIE_INT8   (If support)
*                        @arg INT_EXTIE2_RIE_INT9   (If support)

*                        @arg INT_EXTIE2_RIE_INT10   (If support)
*                        @arg INT_EXTIE2_RIE_INT11   (If support)
*                        @arg INT_EXTIE2_RIE_INT12   (If support)
*                        @arg INT_EXTIE2_RIE_INT13   (If support)
*                        @arg INT_EXTIE2_RIE_INT14   (If support)

* @param          NewState   = ENABLE： Enable interrupt
*                            = DISABLE：disable interrupt
*
*  @retval None
*
*********************************************************************************************************
*/
void HT_EXTIRise_ITConfig(uint32_t ITEn, FunctionalState NewState)
{
    /*  assert_param  */


#if defined USE_EXTI10_14
    assert_param(IS_EXTIE_RISE_LINE10_14(ITEn) || IS_EXTIE_RISE_LINE7_9(ITEn)||IS_EXTIE_RISE_LINE0_6(ITEn));

#elif defined USE_INT_EXTIX2
    assert_param(IS_EXTIE_RISE_LINE7_9(ITEn)||IS_EXTIE_RISE_LINE0_6(ITEn));
#else
    assert_param(IS_EXTIE_RISE_LINE0_6(ITEn));
#endif

    assert_param(IS_FUNCTIONAL_STATE(NewState));


#if defined USE_INT_EXTIX2
    uint32_t tempreg = (ITEn&INT_EXTIE2_RIE)>>INT_EXTI2_BIT_POS;
#endif
    ITEn &= INT_EXTIE_RIE;
    if (NewState != DISABLE)                        /*!< Enable interrupt           */
    {
        HT_INT->EXTIE |= ITEn;

#if defined USE_INT_EXTIX2
        HT_INT->EXTIE2 |= tempreg;
#endif
    }
    else                                            /*!< disable interrupt          */
    {
        HT_INT->EXTIE &= ~ITEn;

#if defined USE_INT_EXTIX2
        HT_INT->EXTIE2 &= ~tempreg;
#endif
    }
}


#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
void HT_EXTI_InitCallback(EXTI_TypeDef *ExtiStruct)
{

    EXTI_InitCallbacksToDefault(ExtiStruct);
    ExtiStruct->Instance = HT_INT;
}
#endif

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE EXTI FALL INTERRUPT
*
* @brief:  Enable or disable EXTI falling edge interrupt
* @param   ITEn: EXTI interrupt set bit.
*   This parameter can be the following values
*                        @arg INT_EXTIE_FIE_INT0
*                        @arg INT_EXTIE_FIE_INT1
*                        @arg INT_EXTIE_FIE_INT2
*                        @arg INT_EXTIE_FIE_INT3
*                        @arg INT_EXTIE_FIE_INT4
*                        @arg INT_EXTIE_FIE_INT5
*                        @arg INT_EXTIE_FIE_INT6
*                        @arg INT_EXTIE2_FIE_INT7  (If support)
*                        @arg INT_EXTIE2_FIE_INT8  (If support)
*                        @arg INT_EXTIE2_FIE_INT9  (If support)

*                        @arg INT_EXTIE2_FIE_INT10   (If support)
*                        @arg INT_EXTIE2_FIE_INT11   (If support)
*                        @arg INT_EXTIE2_FIE_INT12   (If support)
*                        @arg INT_EXTIE2_FIE_INT13   (If support)
*                        @arg INT_EXTIE2_FIE_INT14   (If support)
* @param          NewState   = ENABLE： Enable interrupt
*                            = DISABLE：disable interrupt
*
*  @retval None
*********************************************************************************************************
*/
void HT_EXTIFall_ITConfig(uint32_t ITEn, FunctionalState NewState)
{
    /*  assert_param  */
#if defined USE_EXTI10_14
    assert_param(IS_EXTIE_FALL_LINE10_14(ITEn) || IS_EXTIE_FALL_LINE7_9(ITEn)||IS_EXTIE_FALL_LINE0_6(ITEn));

#elif defined USE_INT_EXTIX2
    assert_param(IS_EXTIE_FALL_LINE7_9(ITEn)||IS_EXTIE_FALL_LINE0_6(ITEn));
#else
    assert_param(IS_EXTIE_FALL_LINE0_6(ITEn));
#endif
    assert_param(IS_FUNCTIONAL_STATE(NewState));


#if defined USE_INT_EXTIX2

    uint32_t tempreg = (ITEn&INT_EXTIE2_FIE)>>INT_EXTI2_BIT_POS;
#endif
    ITEn &= INT_EXTIE_FIE;
    if (NewState != DISABLE)
    {
        HT_INT->EXTIE |= ITEn;            /*!< Enable interrupt           */

#if defined USE_INT_EXTIX2
        HT_INT->EXTIE2 |= tempreg;
#endif
    }
    else
    {
        HT_INT->EXTIE &= ~ITEn;           /*!< disable interrupt           */

#if defined USE_INT_EXTIX2
        HT_INT->EXTIE2 &= ~tempreg;
#endif
    }
}

/**
*********************************************************************************************************
*                            GET SPECIFIED EXTI RISE INTERRUPT FLAG STATUS
*
* @brief:  Get the rising edge interrupt flag status
* @param   ITFlag: EXTI interrupt set bit.
*   This parameter can be the following values
*                        @arg INT_EXTIF_RIF_INT0
*                        @arg INT_EXTIF_RIF_INT1
*                        @arg INT_EXTIF_RIF_INT2
*                        @arg INT_EXTIF_RIF_INT3
*                        @arg INT_EXTIF_RIF_INT4
*                        @arg INT_EXTIF_RIF_INT5
*                        @arg INT_EXTIF_RIF_INT6
*                        @arg INT_EXTIF2_RIF_INT7   (If support)
*                        @arg INT_EXTIF2_RIF_INT8   (If support)
*                        @arg INT_EXTIF2_RIF_INT9   (If support)

*                        @arg INT_EXTIF2_RIF_INT10   (If support)
*                        @arg INT_EXTIF2_RIF_INT11   (If support)
*                        @arg INT_EXTIF2_RIF_INT12   (If support)
*                        @arg INT_EXTIF2_RIF_INT13   (If support)
*                        @arg INT_EXTIF2_RIF_INT14   (If support)
*  @retval  ITStatus    = SET：     Generate the corresponding interrupt flag
*                       = RESET：   Corresponding interrupt flag is not generated
*********************************************************************************************************
*/
ITStatus HT_EXTIRise_ITFlagStatusGet(uint32_t ITFlag)
{
    ITStatus tempStatus = RESET;

    /*  assert_param  */
#if defined USE_EXTI10_14
    assert_param(IS_EXTI_GET_RISE_ITFlag10_14(ITFlag) || IS_EXTI_GET_RISE_ITFlag7_9(ITFlag)||IS_EXTI_GET_RISE_ITFlag0_6(ITFlag));

#elif defined USE_INT_EXTIX2
    assert_param(IS_EXTI_GET_RISE_ITFlag7_9(ITFlag)||IS_EXTI_GET_RISE_ITFlag0_6(ITFlag));
#else
    assert_param(IS_EXTI_GET_RISE_ITFlag0_6(ITFlag));
#endif

#if defined USE_INT_EXTIX2

    uint32_t tempreg = (ITFlag & INT_EXTIF2_RIF)>>INT_EXTI2_BIT_POS;
#endif

    if (HT_INT->EXTIF & ITFlag)
    {
        tempStatus = SET;                        /*!< Interrupt Flag is set   */
    }


#if defined USE_INT_EXTIX2
    if (HT_INT->EXTIF2 & tempreg)
    {
        tempStatus = SET;                    /*!< Interrupt Flag is set   */
    }
#endif


    return tempStatus;
}

/**
*********************************************************************************************************
*                          GET SPECIFIED EXTI FALL INTERRUPT FLAG STATUS
*
* @brief:  Get the corresponding EXTI falling edge interrupt flag status
* @param   ITEn: EXTI interrupt set bit.
*   This parameter can be the following values
*                        @arg INT_EXTIF_FIF_INT0
*                        @arg INT_EXTIF_FIF_INT1
*                        @arg INT_EXTIF_FIF_INT2
*                        @arg INT_EXTIF_FIF_INT3
*                        @arg INT_EXTIF_FIF_INT4
*                        @arg INT_EXTIF_FIF_INT5
*                        @arg INT_EXTIF_FIF_INT6
*                        @arg INT_EXTIF2_FIF_INT7     (If support)
*                        @arg INT_EXTIF2_FIF_INT8     (If support)
*                        @arg INT_EXTIF2_FIF_INT9     (If support)

*                        @arg INT_EXTIF2_FIF_INT10   (If support)
*                        @arg INT_EXTIF2_FIF_INT11   (If support)
*                        @arg INT_EXTIF2_FIF_INT12   (If support)
*                        @arg INT_EXTIF2_FIF_INT13   (If support)
*                        @arg INT_EXTIF2_FIF_INT14   (If support)
*
*  @retval  ITStatus    = SET：     Generate the corresponding interrupt flag
*                       = RESET：   Corresponding interrupt flag is not generated
*********************************************************************************************************
*/
ITStatus HT_EXTIFall_ITFlagStatusGet(uint32_t ITFlag)
{
    ITStatus tempStatus = RESET;
    /*  assert_param  */
#if defined USE_EXTI10_14
    assert_param(IS_EXTI_GET_FALL_ITFlag10_14(ITFlag) || IS_EXTI_GET_FALL_ITFlag7_9(ITFlag)||IS_EXTI_GET_FALL_ITFlag0_6(ITFlag));

#elif defined USE_INT_EXTIX2
    assert_param(IS_EXTI_GET_FALL_ITFlag7_9(ITFlag)||IS_EXTI_GET_FALL_ITFlag0_6(ITFlag));
#else
    assert_param(IS_EXTI_GET_FALL_ITFlag0_6(ITFlag));
#endif

#if defined USE_INT_EXTIX2

    uint32_t tempreg = (ITFlag & INT_EXTIF2_FIF)>>INT_EXTI2_BIT_POS;
#endif
    if (HT_INT->EXTIF & ITFlag)
    {
        tempStatus = SET;                        /*!< Interrupt Flag is set   */
    }


#if defined USE_INT_EXTIX2
    if (HT_INT->EXTIF2 & tempreg)
    {
        tempStatus = SET;                    /*!< Interrupt Flag is set   */
    }
#endif

    return tempStatus;
}

/**
*********************************************************************************************************
*                                   CLEAR EXTI RISE INTERRUPT FLAG
*
* @brief:  Clear EXTI rising edge interrupt flag
* @param   ITFlag: EXTI interrupt set bit.
*   This parameter can be one or a combination of the following values
*                        @arg INT_EXTIF_RIF_INT0
*                        @arg INT_EXTIF_RIF_INT1
*                        @arg INT_EXTIF_RIF_INT2
*                        @arg INT_EXTIF_RIF_INT3
*                        @arg INT_EXTIF_RIF_INT4
*                        @arg INT_EXTIF_RIF_INT5
*                        @arg INT_EXTIF_RIF_INT6
*                        @arg INT_EXTIF2_RIF_INT7   (If support)
*                        @arg INT_EXTIF2_RIF_INT8   (If support)
*                        @arg INT_EXTIF2_RIF_INT9   (If support)

*                        @arg INT_EXTIF2_RIF_INT10   (If support)
*                        @arg INT_EXTIF2_RIF_INT11   (If support)
*                        @arg INT_EXTIF2_RIF_INT12   (If support)
*                        @arg INT_EXTIF2_RIF_INT13   (If support)
*                        @arg INT_EXTIF2_RIF_INT14   (If support)

*
*  @retval  None
* @special: The input parameter cannot be the combination of INT0~6 and INT7~9
*********************************************************************************************************
*/
void HT_EXTIRise_ClearITPendingBit(uint32_t ITFlag)
{
    /*  assert_param  */

#if defined USE_EXTI10_14
    assert_param(IS_EXTI_GET_RISE_ITFlag10_14(ITFlag) || IS_EXTI_GET_RISE_ITFlag7_9(ITFlag)|| IS_EXTI_GET_RISE_ITFlag0_6(ITFlag));

#elif defined USE_INT_EXTIX2
    assert_param(IS_EXTI_GET_RISE_ITFlag7_9(ITFlag)||IS_EXTI_GET_RISE_ITFlag0_6(ITFlag));
#else
    assert_param(IS_EXTI_GET_RISE_ITFlag0_6(ITFlag));
#endif

#if defined USE_INT_EXTIX2

    uint32_t tempreg = (ITFlag & INT_EXTIF2_RIF)>>INT_EXTI2_BIT_POS;
#endif
    ITFlag &= INT_EXTIF_RIF;
    HT_INT->EXTIF   = ~ITFlag;                  /*!< Clear EXTI Rise Edge Interrupt Flag */

#if defined USE_INT_EXTIX2
    HT_INT->EXTIF2  = ~tempreg;
#endif
}

/**
*********************************************************************************************************
*                                   CLEAR EXTI FALL INTERRUPT FLAG
*
* @brief:  Clear EXTI falling edge interrupt flag
* @param   ITFlag: EXTI interrupt set bit.
*   This parameter can be one or a combination of the following values
*                        @arg INT_EXTIF_FIF_INT0
*                        @arg INT_EXTIF_FIF_INT1
*                        @arg INT_EXTIF_FIF_INT2
*                        @arg INT_EXTIF_FIF_INT3
*                        @arg INT_EXTIF_FIF_INT4
*                        @arg INT_EXTIF_FIF_INT5
*                        @arg INT_EXTIF_FIF_INT6
*                        @arg INT_EXTIF2_FIF_INT7   (If support)
*                        @arg INT_EXTIF2_FIF_INT8   (If support)
*                        @arg INT_EXTIF2_FIF_INT9   (If support)

*                        @arg INT_EXTIF2_FIF_INT10   (If support)
*                        @arg INT_EXTIF2_FIF_INT11   (If support)
*                        @arg INT_EXTIF2_FIF_INT12   (If support)
*                        @arg INT_EXTIF2_FIF_INT13   (If support)
*                        @arg INT_EXTIF2_FIF_INT14   (If support)
*
*  @retval  None
* @special: The input parameter cannot be the combination of INT0~6 and INT7~9
*********************************************************************************************************
*/
void HT_EXTIFall_ClearITPendingBit(uint32_t ITFlag)
{
    /*  assert_param  */
#if defined USE_EXTI10_14
    assert_param(IS_EXTI_GET_FALL_ITFlag10_14(ITFlag) || IS_EXTI_GET_FALL_ITFlag7_9(ITFlag)||IS_EXTI_GET_FALL_ITFlag0_6(ITFlag));

#elif defined USE_INT_EXTIX2
    assert_param(IS_EXTI_GET_FALL_ITFlag7_9(ITFlag)||IS_EXTI_GET_FALL_ITFlag0_6(ITFlag));
#else
    assert_param(IS_EXTI_GET_FALL_ITFlag0_6(ITFlag));
#endif

#if defined USE_INT_EXTIX2
    uint32_t tempreg = (ITFlag & INT_EXTIF2_FIF)>>INT_EXTI2_BIT_POS;
#endif
    ITFlag &= INT_EXTIF_FIF;
    HT_INT->EXTIF   = ~ITFlag;                /*!< Clear EXTI Fall Edge Interrupt Flag */       /*  Changed by yren  */

#if defined USE_INT_EXTIX2
    HT_INT->EXTIF2  = ~tempreg;                                                                                  /*  Changed by yren  */
#endif
}
/**
*********************************************************************************************************
*                                   ENABLE OR DISABLE EXTI DIGITAL FILTER
*
* @brief:  Enable or disable the digital filter function of EXTI
* @param   ITFLTEn: Digital filter setting bit of interrupt pin
*   This parameter can be the following values
*                        @arg INT_PINFLT_INTFLT_INT0
*                        @arg INT_PINFLT_INTFLT_INT1
*                        @arg INT_PINFLT_INTFLT_INT2
*                        @arg INT_PINFLT_INTFLT_INT3
*                        @arg INT_PINFLT_INTFLT_INT4
*                        @arg INT_PINFLT_INTFLT_INT5
*                        @arg INT_PINFLT_INTFLT_INT6
*                        @arg INT_PINFLT2_INTFLT_INT7  (If support)
*                        @arg INT_PINFLT2_INTFLT_INT8  (If support)
*                        @arg INT_PINFLT2_INTFLT_INT9  (If support)

*                        @arg INT_PINFLT2_INTFLT_INT10   (If support)
*                        @arg INT_PINFLT2_INTFLT_INT11   (If support)
*                        @arg INT_PINFLT2_INTFLT_INT12   (If support)
*                        @arg INT_PINFLT2_INTFLT_INT13   (If support)
*                        @arg INT_PINFLT2_INTFLT_INT14   (If support)
*

* @param          NewState   = ENABLE： Enable digital filter
*                            = DISABLE：disable digital filter
*
*  @retval None
*********************************************************************************************************
*/
void HT_EXTI_FilterConfig(uint32_t ITFLTEn,FunctionalState NewState)
{
    /*  assert_param  */
#if defined USE_EXTI10_14
    assert_param(IS_EXTI_INTFLT_LINE10_14(ITFLTEn) || IS_EXTI_INTFLT_LINE7_9(ITFLTEn)||IS_EXTI_INTFLT_LINE0_6(ITFLTEn));

#elif defined USE_INT_EXTIX2
    assert_param(IS_EXTI_INTFLT_LINE7_9(ITFLTEn)||IS_EXTI_INTFLT_LINE0_6(ITFLTEn));
#else
    assert_param(IS_EXTI_INTFLT_LINE0_6(ITFLTEn));
#endif

    assert_param(IS_FUNCTIONAL_STATE(NewState));



#if defined USE_INT_EXTIX2

    uint32_t tempreg = (ITFLTEn & INT_PINFLT2_INTFLT)>>INT_EXTI2_BIT_POS;
#endif
    ITFLTEn &= INT_PINFLT_INTFLT;
    if (NewState != DISABLE)
    {
        HT_INT->PINFLT |= ITFLTEn;            /*!<   Enable digital filtering       */

#if defined USE_INT_EXTIX2
        HT_INT->PINFLT2 |= tempreg;
#endif
    }
    else
    {
        HT_INT->PINFLT &= ~ITFLTEn;           /*!<    Disabled digital filtering       */
#if defined USE_INT_EXTIX2
        HT_INT->PINFLT2 &= ~tempreg;
#endif
    }
}


#if (USE_HT_EXTI_REGISTER_CALLBACKS ==1U)
/**
* @brief  Register a User EXTI Callback
*         To be used instead of the weak predefined callback
* @param  ExtiStruct  handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref Exti_Rise_CB_ID Rising edge Callback ID
*           @arg @ref Exti_Fall_CB_ID Fall edge Callback ID
* @param  pCallback pointer to the Callback function
* @retval status
* @note: when USE_HT_EXTI_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register
*		himself defined callback function.
*/
StatusTypeDef HT_EXTI_RegisterCallback(EXTI_TypeDef *ExtiStruct, EXTI_CallbackIDTypeDef Exti_CallbackID, pEXTI_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        ExtiStruct->ErrorCode |= EXTI_ERROR_INVALID_CALLBACK;
        status = ERROR;
    }
    else
    {
        switch (Exti_CallbackID)
        {
        case Exti_Rise_CB_ID:
            ExtiStruct->RiseCallback = pCallback;
            break;

        case Exti_Fall_CB_ID :
            ExtiStruct->FallCallback =pCallback;
            break;

        default :
            /* Update the error code */
            ExtiStruct->ErrorCode |= EXTI_ERROR_INVALID_CALLBACK;
            /* Return error status */
            status =  ERROR;
            break;
        }
    }
    return status;
}

/**
*********************************************************************************************************
*                                         Rising edge CALLBACK
*
* @brief: Rising edge detected
*
* @param: ExtiStruct  Pointer to a EXTI_TypeDef structure that contains
*                the configuration information for the specified INT(EXTI) module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_EXTI_RiseCallback(EXTI_TypeDef *ExtiStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(ExtiStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_EXTI_RiseCallback could be implemented in the user file
     */
}
/**
*********************************************************************************************************
*                                         Fall edge CALLBACK
*
* @brief: Falling edge detected
*
* @param: ExtiStruct  Pointer to a EXTI_TypeDef structure that contains
*                the configuration information for the specified INT(EXTI) module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_EXTI_FallCallback(EXTI_TypeDef *ExtiStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(ExtiStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_EXTI_FallCallback could be implemented in the user file
     */
}


/**
*********************************************************************************************************
*                                         INITIAL INT(EXTI) CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: ExtiStruct Pointer to a EXTI_TypeDef structure that contains
*               the configuration information for the specified INT(EXTI) module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void EXTI_InitCallbacksToDefault(EXTI_TypeDef *ExtiStruct)
{
    /* Init the INT(EXTI) Callback settings */
    ExtiStruct->RiseCallback =HT_EXTI_RiseCallback;
    ExtiStruct->FallCallback =HT_EXTI_FallCallback;
}


/**
*********************************************************************************************************
*                                        EXTI RISE IT HANDLER
*
* @brief: Rising edge detected
*
* @param: ExtiStruct Pointer to a EXTI_TypeDef structure that contains
*               the configuration information for the specified INT(EXTI) module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/

static void Exti_Rise_IT(EXTI_TypeDef *ExtiStruct)
{
    /*Call registered Rising edge detected callback*/

    if(ExtiStruct->RiseCallback !=NULL)
    {
        ExtiStruct->RiseCallback(ExtiStruct);
    }
}

/**
*********************************************************************************************************
*                                       EXTI FALL  IT HANDLER
*
* @brief: Falling edge detected
*
* @param: ExtiStruct Pointer to a EXTI_TypeDef structure that contains
*               the configuration information for the specified INT(EXTI) module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/

static void Exti_Fall_IT(EXTI_TypeDef *ExtiStruct)
{
    /*Call registered Falling edge detected callback*/
    if(ExtiStruct->FallCallback !=NULL)
    {
        ExtiStruct->FallCallback(ExtiStruct);
    }
}


/**
*********************************************************************************************************
*                                         INT(EXTI) IRQ HANDLER
*
* @brief: This function handles INT(EXTI) interrupt request.
*
* @param: ExtiStruct  Pointer to a EXTI_TypeDef structure that contains
*                the configuration information for the specified INT(EXTI) module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/

void HT_EXTI_IRQHandler(EXTI_TypeDef *ExtiStruct)
{
    if(ExtiStruct->Instance == HT_INT)
    {
        uint32_t isflags_1   = READ_REG(ExtiStruct->Instance->EXTIF);
        uint32_t cr1its_1     = READ_REG(ExtiStruct->Instance->EXTIE);
#if defined USE_INT_EXTIX2
        uint32_t isflags_2   = READ_REG(ExtiStruct->Instance->EXTIF2);
        uint32_t cr1its_2    = READ_REG(ExtiStruct->Instance->EXTIE2);
#endif
        if((RESET != (cr1its_1&INT_EXTIE_RIE)) && (RESET != (isflags_1&INT_EXTIF_RIF)))         /*!< INT0-6 rising edge interrupt           */
        {
            Exti_Rise_IT(ExtiStruct);
            HT_EXTIRise_ClearITPendingBit(isflags_1&INT_EXTIF_RIF);             /*!< Clear interrupt flag             */
        }

        if((RESET != (cr1its_1&INT_EXTIE_FIE)) && (RESET !=(isflags_1&INT_EXTIF_FIF)))         /*!< INT0-6 falling edge interrupt           */
        {
            Exti_Fall_IT(ExtiStruct);
            HT_EXTIFall_ClearITPendingBit(isflags_1&INT_EXTIF_FIF);             /*!< Clear interrupt flag             */
        }

#if defined USE_INT_EXTIX2
        if((RESET !=(cr1its_2&INT_EXTIE2_RIE_ALL)) && (RESET != (isflags_2&INT_EXTIF2_RIF_ALL)))        /*!< INT7-9 OR INT 7-14rising edge interrupt           */
        {
            Exti_Rise_IT(ExtiStruct);
            HT_EXTIRise_ClearITPendingBit((isflags_2&INT_EXTIF2_RIF_ALL)<<INT_EXTI2_BIT_POS);             /*!< Clear interrupt flag             */
        }

        if((RESET !=(cr1its_2&INT_EXTIE2_FIE_ALL)) && (RESET !=(isflags_2&INT_EXTIF2_FIF_ALL)))         /*!< INT7-9 OR INT 7-14 falling edge interrupt           */
        {
            Exti_Fall_IT(ExtiStruct);
            HT_EXTIFall_ClearITPendingBit((isflags_2&INT_EXTIF2_FIF_ALL)<<INT_EXTI2_BIT_POS);             /*!< Clear interrupt flag             */
        }
#endif
    }
}

#endif


