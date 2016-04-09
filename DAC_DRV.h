
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

/** Enumeration for DAC triggering */
typedef enum E_DAC_TRIGGER {
	DAC_TRIGGER_NONE,
	DAC_TRIGGER_SOFTWARE
} DAC_TRIGGER;

int DAC_readSingle(int chn, uint32_t *output);
void DAC_readDual(uint32_t *output1, uint32_t *output2);
int DAC_writeSingle(int chn, uint32_t data, DAC_RESOLUTION res);
int DAC_writeDual(uint32_t data1, uint32_t data2, DAC_RESOLUTION res);

int DAC_setSoftwareTriggerSingle(int chn);
void DAC_setSoftwareTriggerDual(void);

int DAC_enable(int chn);

int DAC_init(int chn, DAC_TRIGGER trig);

#endif /* DAC_DRV_H */
