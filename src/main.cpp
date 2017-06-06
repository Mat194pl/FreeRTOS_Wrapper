/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
			
#include "../RTOS_Wrapper/RTOS_Task.hpp"
#include "../RTOS_Wrapper/RTOS_TaskFactory.hpp"
#include "../RTOS_Wrapper/RTOS_Software_Timer.hpp"
#include "../RTOS_Wrapper/RTOS_Event_Group.hpp"
#include "../RTOS_Wrapper/RTOS_Semaphore.hpp"
#include "../RTOS_Wrapper/RTOS_Semaphore_Factory.hpp"

static void mainTaskFunction(void*);
TaskFunction_t mainTaskFunctionHandler;

int main(void)
{
	RTOS_Task* mainTask;
	RTOS_TaskFactory taskFactory;
	mainTaskFunctionHandler = mainTaskFunction;
	RTOS_Semaphore* exampleSemaphore;
	RTOS_Semaphore_Factory factory;


	exampleSemaphore = factory.GetSemaphore(RTOS_Semaphore::Binary);

	exampleSemaphore->Take();

	exampleSemaphore->Give();


	mainTask = taskFactory.GetTask(mainTaskFunctionHandler, "Main task", 20, NULL, 2);

	vTaskStartScheduler();

	for(;;);
}

static void mainTaskFunction(void*)
{
	printf("Main task started.");
	while(1){}
}
