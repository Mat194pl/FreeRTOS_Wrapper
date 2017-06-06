/*
 * RTOS_Task.hpp
 *
 *  Created on: 30 kwi 2017
 *      Author: Mateusz
 */

#ifndef RTOS_TASK_HPP_
#define RTOS_TASK_HPP_

#include "FreeRTOS.h"
#include "task.h"

class RTOS_Task
{
protected:
	TaskHandle_t Handle;

public:
	RTOS_Task(TaskHandle_t Handle);
	void Delay(const TickType_t xTicksToDelay);
	UBaseType_t PriorityGet(void);
	void PriotitySet(UBaseType_t uxNewPriority);
	void Suspend(void);
	void Resume(void);
	void AbortDelay(void);
};

#endif /* RTOS_TASK_HPP_ */
