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
* File         : ht6xxx_reset.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_RESET_H__
#define __HT6XXX_RESET_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             Global Variables
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
FlagStatus HT_WakeFlagStatusGet(uint32_t STAFlag);
FlagStatus HT_ResetFlagStatusGet(uint32_t STAFlag);
void HT_ResetFlagClear(uint32_t STAFlag);
void HT_EnterHold(void);
void HT_EnterSleep(void);



#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_RESET_H__ */
