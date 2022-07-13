#ifndef __HT_TMR_H__
#define __HT_TMR_H__

#ifdef __cplusplus
extern "C" {
#endif
	
#include "ht_include.h"

#define HT_TMRx									HT_TMR3
#define	TIMER_x_IRQn							TIMER_3_IRQn
#define	CMU_CLKCTRL1_TMRxEN						CMU_CLKCTRL1_TMR3EN
	
#define	TimerPeriodSet 1000//us

void TMR_Init(void);
uint32_t HT_GetTick(void);
void HT_TMR3CallbackFun(void);
FlagStatus HT_CycleTmr(uint8_t timerNo, uint32_t _timer, FunctionalState NewState);


	#ifdef __cplusplus
}
#endif

#endif /* __HT_TMR_H__ */
