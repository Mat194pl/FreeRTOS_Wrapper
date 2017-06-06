/*
 * RTOS_Port.cpp
 *
 *  Created on: 13 maj 2017
 *      Author: Mateusz
 */

#include <stdint.h>
#include "stm32f4xx.h"

bool RTOS_Port_IsHandlerState(void)
{
	uint32_t ipsr_reg = 0;

	// Check ipsr status register
	asm ("mrs %0, IPSR" : "=r"(ipsr_reg):);

	// Check isr bits
	if ((ipsr_reg & 0x1FFF) == 0)
	{
		return false;
	}
	else return true;
}

