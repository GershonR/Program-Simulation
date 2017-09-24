/*
 * ExitEvent.h
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#ifndef EXITEVENT_H_
#define EXITEVENT_H_

#include "Event.h"
#include "Simulation.h"
#include "Data.h"

namespace simu {

class ExitEvent: public Event {
private:
	Data* args;
	Simulation* instance;
public:
	ExitEvent();
	ExitEvent(Data * aArgs, Simulation * aInstance);
	virtual ~ExitEvent();
	virtual void processEvent();
	virtual Simulation* getSimInstance();
	virtual void print();
	virtual Data* getData();
	virtual void setData(Data * aEventData);
};

} /* namespace simu */

#endif /* EXITEVENT_H_ */
