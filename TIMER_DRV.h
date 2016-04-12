
/** @file TIMER_DRV.h
 *  @brief TIMER Driver include file for the STM32F072RB.
 *  @author Dennis Law
 *  @date April 2016
 */
 
#ifndef TIMER_DRV_H
#define TIMER_DRV_H

#include "stm32f0xx.h"

/** Enumeration for Timer Modes */
typedef enum TIMER_mode_t {
	TIMER_MODE_ONEPULSE,
	TIMER_MODE_CONTINUOUS
} TIMER_mode;

typedef enum TIMER_masterMode {
	TIMER_MASTERMODE_RESET,
	TIMER_MASTERMODE_ENABLE,
	TIMER_MASTERMODE_UPDATE
} TIMER_masterMode_t;

/** Configuration parameters for setting up the timer. */
struct TIMER_config {
	uint16_t count;
	uint16_t prescale;
	TIMER_mode mode;
	TIMER_masterMode_t mmode;
};

int TIMER_setMode(TIM_TypeDef *tim, TIMER_mode mode);
int TIMER_setMasterMode(TIM_TypeDef *tim, TIMER_masterMode_t mmode);
int TIMER_setCount(TIM_TypeDef *tim, int16_t val);
int TIMER_setPrescaler(TIM_TypeDef *tim, int16_t val);
int TIMER_disable(TIM_TypeDef *tim);
int TIMER_enable(TIM_TypeDef *tim);
int TIMER_enableClock(TIM_TypeDef *tim);

int TIMER_init(TIM_TypeDef *tim, struct TIMER_config conf,
				void (*callback)(void));

#endif	/* TIMER_DRV_H */
