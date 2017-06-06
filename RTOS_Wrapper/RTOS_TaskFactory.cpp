/*
 * RTOS_TaskFactory.cpp
 *
 *  Created on: 12 maj 2017
 *      Author: Mateusz
 */

#include "RTOS_TaskFactory.hpp"
#include "RTOS_Task.hpp"
#include "FreeRTOS.h"
#include "task.h"

RTOS_TaskFactory::RTOS_TaskFactory()
{

}

RTOS_Task* RTOS_TaskFactory::GetTask(
		TaskFunction_t pxTaskCode,
		const char* pcName,
		unsigned short usStackDepth,
		void* pvParameters,
		UBaseType_t uxPriority)
{
	TaskHandle_t handle;

	xTaskCreate(pxTaskCode, pcName, usStackDepth, pvParameters, uxPriority, &handle);

	RTOS_Task* newTask = new RTOS_Task(handle);

	return newTask;
}

