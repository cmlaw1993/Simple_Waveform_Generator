
/** @file DAC_DRV.h
 *  @brief DAC Driver include file for the STM32F072RB.
 *  @author Dennis Law
 *  @date April 2016
 */

#ifndef DAC_DRV_H
#define DAC_DRV_H

#include "stm32f0xx.h"

int DAC_read(int chn, uint32_t *output);
int DAC_write(int chn, uint32_t data);
void DAC_load_data_buffer(uint32_t data);
int DAC_enable(int chn);
int DAC_init(int chn);

#endif /* DAC_DRV_H */
