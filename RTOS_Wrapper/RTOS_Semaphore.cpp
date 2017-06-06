/*
 * RTOS_Semaphore.cpp
 *
 *  Created on: 13 maj 2017
 *      Author: Mateusz
 */

#include "RTOS_Semaphore.hpp"

extern bool RTOS_Port_IsHandlerState(void);


RTOS_Semaphore::RTOS_Semaphore(SemaphoreHandle_t Handle, SemaphoreType Type)
{
	this->Handle = Handle;
	this->Type = Type;
}

bool RTOS_Semaphore::Take(void)
{
	BaseType_t t;
	bool result = false;
	if (RTOS_Port_IsHandlerState())
	{
		if (this->Type == this->Binary || this->Type == this->Counting)
			result = xSemaphoreTakeFromISR(this->Handle , &t);


	}
	return result;
}

bool RTOS_Semaphore::Give(void)
{
	return false;
}

uint32_t RTOS_Semaphore::GetCount(void)
{
	return 0;
}
