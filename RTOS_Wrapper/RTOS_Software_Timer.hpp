/*
 * RTOS_Software_Timer.hpp
 *
 *  Created on: 27 kwi 2017
 *      Author: Mateusz
 */

#ifndef RTOS_SOFTWARE_TIMER_HPP_
#define RTOS_SOFTWARE_TIMER_HPP_

#include <string>

#include "FreeRTOS.h"
#include "timers.h"

typedef void (*RTOS_Software_Timer_Callback)( void* Timer );


class RTOS_Software_Timer
{
private:
	TimerHandle_t Handle;
	RTOS_Software_Timer_Callback Callback;
	uint32_t Period;
	bool AutoReload;
	StaticTimer_t* Buffer;
	std::string Name;
	bool Active;

public:
	RTOS_Software_Timer(std::string Name);

	std::string GetName(void);
	void SetName(std::string Name);
	uint32_t GetPeriod(void);
	void SetPeriod(uint32_t Period);
	bool IsAutoReload(void);
	void SetAutoReload(bool AutoReload);
	void SetCallback(RTOS_Software_Timer_Callback Callback);
	bool Start(void);
	void Stop(void);
	void Reset(void);

	~RTOS_Software_Timer();
};



#endif /* RTOS_SOFTWARE_TIMER_HPP_ */
