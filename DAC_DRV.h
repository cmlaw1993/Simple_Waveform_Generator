
/** @file DAC_DRV.h
 *  @brief DAC Driver include file for the STM32F072RB.
 *  @author Dennis Law
 *  @date April 2016
 */

#ifndef DAC_DRV_H
#define DAC_DRV_H

#include "stm32f0xx.h"

#define DAC_RESOLUTION_8_MASK				0x000000FF
#define DAC_RESOLUTION_12_MASK				0x00000FFF

/** Enumaration for DAC resolution */
typedef enum E_DAC_RESOLUTION {
	DAC_RESOLUTION_8,
	DAC_RESOLUTION_12
} DAC_RESOLUTION;

int DAC_read(int chn, uint32_t *output);
int DAC_writeSingle(int chn, uint32_t data, DAC_RESOLUTION res);
int DAC_enable(int chn);
int DAC_init(int chn);

#endif /* DAC_DRV_H */
