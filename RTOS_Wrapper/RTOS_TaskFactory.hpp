/*
 * RTOS_TaskFactory.hpp
 *
 *  Created on: 30 kwi 2017
 *      Author: Mateusz
 */

#ifndef RTOS_TASKFACTORY_HPP_
#define RTOS_TASKFACTORY_HPP_

#include "FreeRTOS.h"
#include "task.h"
#include "RTOS_Task.hpp"

class RTOS_TaskFactory
{
public:
	RTOS_TaskFactory(void);
	RTOS_Task* GetTask(
			TaskFunction_t pxTaskCode,
			const char* pcName,
			unsigned short usStackDepth,
			void* pvParameters,
			UBaseType_t uxPriority);
};

#endif /* RTOS_TASKFACTORY_HPP_ */
