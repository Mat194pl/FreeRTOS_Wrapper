/*
 * RTOS_Task.cpp
 *
 *  Created on: 12 maj 2017
 *      Author: Mateusz
 */

#include "RTOS_Task.hpp"
#include "FreeRTOS.h"
#include "task.h"

RTOS_Task::RTOS_Task(TaskHandle_t Handle)
{
	this->Handle = Handle;
}

void RTOS_Task::Delay(const TickType_t xTicksToDelay)
{
	vTaskDelay(xTicksToDelay);
}

UBaseType_t RTOS_Task::PriorityGet(void)
{
	return uxTaskPriorityGet(this->Handle);
}

void RTOS_Task::PriotitySet(UBaseType_t uxNewPriority)
{
	vTaskPrioritySet(this->Handle, uxNewPriority);
}

void RTOS_Task::Suspend(void)
{
	vTaskSuspend(this->Handle);
}

void RTOS_Task::Resume(void)
{
	vTaskResume(this->Handle);
}

void RTOS_Task::AbortDelay(void)
{

}
