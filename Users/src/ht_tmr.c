#include "ht_tmr.h"

uint32_t timer_count;

static void NVIC_TMRx_Init(FunctionalState NewState)
{
	/* TIMER_x_IRQn interrupt configuration */
	if(NewState != DISABLE)
	{
		NVIC_SetPriority (TIMER_x_IRQn, 0x1);
		NVIC_EnableIRQ(TIMER_x_IRQn); 
	}else
	{
		NVIC_DisableIRQ(TIMER_x_IRQn);
	}
}

void TMR_Cycle_Init(void)
{	
	TMR_InitTypeDef  TMR_InitStructure;
    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_TMRxEN, ENABLE);						/*!< 使能TIMER模块              */
	
    TMR_InitStructure.TimerMode 		= TIMCycleTiming;           		/*!< Timer设定为周期定时功能     */
	TMR_InitStructure.TimerCompare 		= 0;
    TMR_InitStructure.TimerPreDiv 		= 0x00;                          	/*!< Timer时钟等于系统时钟       */
    TMR_InitStructure.TimerPeriod 		= HT_CMU_SysClkGet()/(TMR_InitStructure.TimerPreDiv+1)/1000/1000*TimerPeriodSet-1;/*!< 定时周期设定 22M/周期       */
	
	TMR_InitStructure.TimerOPModeEnable = DISABLE;
	
	TMR_InitStructure.TimExTrigEnable 	= DISABLE;
	TMR_InitStructure.TimerExTrigSource = TimerExTrigSrc_INT0;
	TMR_InitStructure.TimerExTrigMode 	= TimExTrigMode_Dual;
	
	TMR_InitStructure.PwmDeadTime = 0;
	TMR_InitStructure.PwmMode = TIMPWMSyncOut;
	
    HT_TMR_Init(HT_TMRx, &TMR_InitStructure);
	
    HT_TMR_ITConfig(HT_TMRx, TMR_TMRIE_PRDIE,ENABLE);
    NVIC_TMRx_Init(ENABLE);
}

void TMR_Init(void)
{
	TMR_Cycle_Init();
}

FlagStatus HT_CycleTmr(uint8_t timerNo, uint32_t _timer, FunctionalState NewState)
{
	static uint32_t timer_get[32];
	static uint8_t sta[32];

	if(NewState == ENABLE)
	{
		if(sta[timerNo] == 0)
		{
			timer_get[timerNo] = timer_count;
			sta[timerNo] = 1;
		}else
		{
			if(timer_count - timer_get[timerNo] >= _timer)
			{
				sta[timerNo]=0;
				timer_get[timerNo]=0;
				return	SET;
			}
		}
	}else
	{
		sta[timerNo]=0;
		timer_get[timerNo]=0;
	}
	return	RESET;
}

uint32_t HT_GetTick(void)
{
	return timer_count;
}

void HT_TMR3CallbackFun(void)
{
	timer_count++;
}
