/*
 * RTOS_Semaphore.hpp
 *
 *  Created on: 13 maj 2017
 *      Author: Mateusz
 */

#ifndef RTOS_SEMAPHORE_HPP_
#define RTOS_SEMAPHORE_HPP_

#include "FreeRTOS.h"
#include "semphr.h"



class RTOS_Semaphore
{
public:
	typedef enum
	{
		Recursive,
		Mutex,
		Binary,
		Counting
	} SemaphoreType;

private:
	SemaphoreHandle_t Handle;
	SemaphoreType Type;

public:
	RTOS_Semaphore(SemaphoreHandle_t Handle, SemaphoreType Type);
	bool Take(void);
	bool Give(void);
	uint32_t GetCount(void);
};



#endif /* RTOS_SEMAPHORE_HPP_ */
