/*
 * RTOS_Semaphore_Factory.cpp
 *
 *  Created on: 13 maj 2017
 *      Author: Mateusz
 */

#include "RTOS_Semaphore_Factory.hpp"

RTOS_Semaphore* RTOS_Semaphore_Factory::GetSemaphore(RTOS_Semaphore::SemaphoreType Type)
{
	SemaphoreHandle_t Handle;

	switch(Type)
	{
	case RTOS_Semaphore::Binary:
		Handle = xSemaphoreCreateBinary();
	break;

	case RTOS_Semaphore::Recursive:
		Handle = xSemaphoreCreateRecursiveMutex();
	break;

	case RTOS_Semaphore::Mutex:
		Handle = xSemaphoreCreateMutex();
	break;
	}

	return new RTOS_Semaphore(Handle, Type);
}

RTOS_Semaphore* RTOS_Semaphore_Factory::GetCountingSemaphore(UBaseType_t MaxCount, UBaseType_t InitialCount)
{
	SemaphoreHandle_t Handle;

	Handle = xSemaphoreCreateCounting(MaxCount, InitialCount);

	return new RTOS_Semaphore(Handle, RTOS_Semaphore::Counting);
}


