/*
 * RTOS_Semaphore_Factory.hpp
 *
 *  Created on: 13 maj 2017
 *      Author: Mateusz
 */

#ifndef RTOS_SEMAPHORE_FACTORY_HPP_
#define RTOS_SEMAPHORE_FACTORY_HPP_

#include "RTOS_Semaphore.hpp"

class RTOS_Semaphore_Factory
{
public:

	RTOS_Semaphore* GetSemaphore(RTOS_Semaphore::SemaphoreType Type);
	RTOS_Semaphore* GetCountingSemaphore(UBaseType_t MaxCount, UBaseType_t InitialCount);
};

#endif /* RTOS_SEMAPHORE_FACTORY_HPP_ */
