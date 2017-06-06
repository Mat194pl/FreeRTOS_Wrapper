/*
 * RTOS_Software_Timer.cpp
 *
 *  Created on: 28 kwi 2017
 *      Author: Mateusz
 */

#include "RTOS_Software_Timer.hpp"


// FreeRTOS hidden timer struct.
typedef struct tmrTimerControl
{
	const char				*pcTimerName;		/*<< Text name.  This is not used by the kernel, it is included simply to make debugging easier. */ /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
	ListItem_t				xTimerListItem;		/*<< Standard linked list item as used by all kernel features for event management. */
	TickType_t				xTimerPeriodInTicks;/*<< How quickly and often the timer expires. */
	UBaseType_t				uxAutoReload;		/*<< Set to pdTRUE if the timer should be automatically restarted once expired.  Set to pdFALSE if the timer is, in effect, a one-shot timer. */
	void 					*pvTimerID;			/*<< An ID to identify the timer.  This allows the timer to be identified when the same callback is used for multiple timers. */
	TimerCallbackFunction_t	pxCallbackFunction;	/*<< The function that will be called when the timer expires. */
	#if( configUSE_TRACE_FACILITY == 1 )
		UBaseType_t			uxTimerNumber;		/*<< An ID assigned by trace tools such as FreeRTOS+Trace */
	#endif

	#if( ( configSUPPORT_STATIC_ALLOCATION == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION == 1 ) )
		uint8_t 			ucStaticallyAllocated; /*<< Set to pdTRUE if the timer was created statically so no attempt is made to free the memory again if the timer is later deleted. */
	#endif
} xTIMER;

RTOS_Software_Timer::RTOS_Software_Timer(std::string Name)
{
	this->Callback = NULL;
	this->AutoReload = pdFALSE;
	this->Name = Name;
	this->Period = 100;
	this->Buffer = 0;
	this->Active = false;

	this->Handle = xTimerCreate(Name.c_str(), 100, pdFALSE, (void*) 0, (TimerCallbackFunction_t)0);
}

std::string RTOS_Software_Timer::GetName(void)
{
	return this->Name;
}

void RTOS_Software_Timer::SetName(std::string Name)
{
	this->Name = Name;
}

uint32_t RTOS_Software_Timer::GetPeriod(void)
{
	return this->Period;
}

void RTOS_Software_Timer::SetPeriod(uint32_t Period)
{
	this->Period = Period;
	xTimerChangePeriod(this->Handle, Period, 0);
}

bool RTOS_Software_Timer::IsAutoReload(void)
{
	return this->AutoReload;
}

void RTOS_Software_Timer::SetAutoReload(bool AutoReload)
{
	this->AutoReload = AutoReload;

	if (this->Active)
		xTimerStop(this->Handle, 0);
	((xTIMER *)(this->Handle))->uxAutoReload = AutoReload;

	if (this->Active)
		xTimerStart(this->Handle, 0);
}

void RTOS_Software_Timer::SetCallback(RTOS_Software_Timer_Callback Callback)
{
	this->Callback = (Callback);
	((xTIMER *)(this->Handle))->pxCallbackFunction = Callback;
}

bool RTOS_Software_Timer::Start(void)
{
	if (this->Callback == NULL) return false;
	xTimerStart(this->Handle, 0);
	this->Active = true;
	return true;
}

void RTOS_Software_Timer::Stop(void)
{
	xTimerStop(this->Handle, 0);
	this->Active = false;
}

void RTOS_Software_Timer::Reset(void)
{
	xTimerReset(this->Handle, 0);
}

RTOS_Software_Timer::~RTOS_Software_Timer()
{
	xTimerDelete(this->Handle, 0);
}


