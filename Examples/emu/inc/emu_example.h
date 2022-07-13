
#ifndef __DMA_EXAMPLE_H__
#define __DMA_EXAMPLE_H__

#ifdef __cplusplus
extern "C" {
#endif 
    
#include "ht6xxx.h"

#if defined HT762x  || defined HT772x         /* This File Only support HT7x2x */
    
/*
*********************************************************************************************************
*                                           Global macro / structure
*********************************************************************************************************
*/
  
/*
*********************************************************************************************************
*                                             Global Variable
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          Global Function Declaration
*********************************************************************************************************
*/

void HT_EMU_Init_Example(void);
void HT_EMU_Resample_Init_Example(void);
#if defined  HT762x 
void HT_EMU_AllVoltageLost_Init_Example(void);
#endif
void HT_EMU_LowPower_Init_Example(void);



#endif                                        /* This File Only support HT7xxx*/

#ifdef __cplusplus
}
#endif

#endif /* __EMU_EXAMPLE_H__ */

