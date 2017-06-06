/*
 * RTOS_Event_Group.hpp
 *
 *  Created on: 30 kwi 2017
 *      Author: Mateusz
 */

#ifndef RTOS_EVENT_GROUP_HPP_
#define RTOS_EVENT_GROUP_HPP_

#include "event_groups.h"

class RTOS_Event_Group
{
private:
	EventGroupHandle_t Handler;

public:
	RTOS_Event_Group(void);
	void SetBits(EventBits_t BitsToSet);
	void ClearBits(EventBits_t BitsToClear);
	EventBits_t GetBits(void);
	bool WaitBits(EventBits_t BitsToWait, uint32_t TimeoutMs);
};

#endif /* RTOS_EVENT_GROUP_HPP_ */
