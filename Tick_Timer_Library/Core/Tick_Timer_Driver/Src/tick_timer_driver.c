/*
 * tick_timer_driver.c
 *
 *  Created on: Aug 2, 2025
 *      Author:
 */

#include "tick_timer_driver.h"

static TIM_HandleTypeDef *tick_timer_hanle = NULL;
uint32_t msTick = 0;

bool Tick_Timer_Init(TIM_HandleTypeDef *htim)
{
	if (HAL_TIM_Base_Start_IT(htim) == HAL_OK)
	{
		tick_timer_hanle = htim;
		return true;
	}

	return false;
}

bool Tick_Timer_Create(Software_Timer_t *softwareTimer, uint32_t periodMs, Timer_Type_t timerType, Timer_Callback_t callback)
{
	if(softwareTimer->timerInfo.active !=  true)
	{
		softwareTimer->timerType 				  = timerType;
		softwareTimer->timerInfo.periodMs 		  = periodMs;
		softwareTimer->timerInfo.remainingMs	  = periodMs;
		softwareTimer->timerCallback              = callback;
		return true;
	}

	return false;
}

void Tick_Timer_Start(Software_Timer_t *softwareTimer)
{
	softwareTimer->timerInfo.startMs 		= Tick_Timer_Get_Tick();
	softwareTimer->timerInfo.remainingMs	= softwareTimer->timerInfo.periodMs;
	softwareTimer->timerInfo.active 		= true;

}

void Tick_Timer_Stop(Software_Timer_t *softwareTimer)
{
	softwareTimer->timerInfo.active           = false;
}

void Tick_Timer_Reset(Software_Timer_t *softwareTimer)
{
	softwareTimer->timerInfo.startMs         = Tick_Timer_Get_Tick();
	softwareTimer->timerInfo.remainingMs     = softwareTimer->timerInfo.periodMs;
}

void Tick_Timer_Update_Period(Software_Timer_t *softwareTimer, uint32_t newPeriodMs)
{
	softwareTimer->timerInfo.periodMs 			= newPeriodMs;
	softwareTimer->timerInfo.remainingMs        = softwareTimer->timerInfo.periodMs;
}

uint32_t Tick_Timer_Get_Tick(void)
{
	return msTick;
}

bool Tick_Timer_Check_Elapsed_Time(Software_Timer_t *softwareTimer)
{
	if(softwareTimer->timerInfo.active)
	{
		uint32_t currentTick = Tick_Timer_Get_Tick();
		uint32_t elapsedTime = currentTick - softwareTimer->timerInfo.startMs;

		if(elapsedTime >= softwareTimer->timerInfo.periodMs)
		{
			if(softwareTimer->timerCallback != NULL)
				softwareTimer->timerCallback();

			if(softwareTimer->timerType == TIMER_TYPE_PERIODIC)
			{
				Tick_Timer_Reset(softwareTimer);
			}
			else
			{
				Tick_Timer_Stop(softwareTimer);
			}

			return true;
		}
		else
		{
			softwareTimer->timerInfo.remainingMs = softwareTimer->timerInfo.periodMs - elapsedTime;
		}
	}

	return false;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == tick_timer_hanle)
	{
		msTick++;
	}
}
