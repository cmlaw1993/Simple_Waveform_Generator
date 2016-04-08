
/** @file DAC_DRV.c
 *  @brief DAC Driver for the STM32F072RB.
 *  @author Dennis Law
 *  @date April 2016
 */

#include <assert.h>
#include "DAC_DRV.h"



/**	@brief Reads the output register of channel 1.
 *	@param chn The channel to read. The value is either 1 or 2.
 *	@param output The container for storing the value of DAC_DOR1
 *	register.
 *	@returns Returns 0 if successful and -1 if otherwise.
 */
int DAC_read(int chn, uint32_t *output)
{
	if ((chn != 1) && (chn != 2))
		return -1;
	
	if (chn == 1)
		*output = (DAC->DOR1 & 0x00000FFF);
	else
		*output = (DAC->DOR2 & 0x00000FFF);
	
	return 0;
}

/** @brief Writes an analog value to either channel 1 or 2.
 *	@param chn The channel to write data to. The value is either 1 or 2.
 *	@param data The data to be written to the data register.
 *	@param res The resolution of the data to be written.
 *	@returns Returns 0 if successful and -1 if otherwise.
 *
 *	@details The user input value is written to either the 8 bit or 12 bit
 *	right aligned registers depending on the value of res. The output
 *	voltage is calculated using the formula below.
 *
 *		DAC(output) = V(DDA) * DOR / 4095
 */
int DAC_writeSingle(int chn, uint32_t data, DAC_RESOLUTION res)
{
	if ((chn != 1) && (chn != 2))
		return -1;
	
	switch (res) {
	case DAC_RESOLUTION_8:
		if (chn == 1)
			DAC->DHR8R1 = (data & DAC_RESOLUTION_8_MASK);
		else
			DAC->DHR8R2 = (data & DAC_RESOLUTION_8_MASK);
		break;
	
	case DAC_RESOLUTION_12:
		if (chn == 1)
			DAC->DHR12R1 = (data & DAC_RESOLUTION_12_MASK);
		else
			DAC->DHR12R2 = (data & DAC_RESOLUTION_12_MASK);
		break;
		
	default:
		return -1;
	}

	return 0;
}

/** @brief Enables the selected channel.
 *	@param chn The channel to enable. The value is either 1 or 2.
 *	@returns Returns 0 if successful and -1 if otherwise.
 */
int DAC_enable(int chn)
{
	if ((chn != 1) && (chn != 2))
		return -1;
	
	if (chn == 1)
		DAC->CR |= DAC_CR_EN1;
	else
		DAC->CR |= DAC_CR_EN2;
	
	return 0;
}

/**	@brief Initializes DAC.
 *	@param chn The channel to initialize. The value is either 1 or 2.
 *	@returns Returns 0 if successful and -1 if otherwise.
 *
 *	@details Initializes either channel 1 or 2 in Single Mode with
 *	no triggerring.
 */
int DAC_init(int chn)
{
	/* Check if channel index is correct */
	if ((chn != 1) && (chn != 2))
		return -1;
	
	/* Enable clock for DAC peripheral */
	RCC->APB1ENR |= RCC_APB1ENR_DACEN;
	
	if (chn == 1)
	{
		GPIOA->MODER |= GPIO_MODER_MODER4; 		/* Set pin as AIN */
		GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR4); 	/* Disable pull resistor */
		
		DAC->CR &= ~(DAC_CR_TEN1); 	/* Disable triggering */
		DAC->CR |= DAC_CR_BOFF1; 	/* Enable output buffer */
	}
	else if (chn == 2)
	{
		GPIOA->MODER |= GPIO_MODER_MODER5; 		/* Set pin as AIN */
		GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR5); 	/* Disable pull resistor */
		
		DAC->CR &= ~(DAC_CR_TEN2); 	/* Disable triggering */
		DAC->CR |= DAC_CR_BOFF2; 	/* Enable output buffer */
	}
	
	return 0;
}
