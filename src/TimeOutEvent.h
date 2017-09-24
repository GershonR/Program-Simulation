/*
 * TimeOutEvent.h
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#ifndef TIMEOUTEVENT_H_
#define TIMEOUTEVENT_H_

#include "BurstEvent.h"
#include "Simulation.h"
#include "Data.h"

namespace simu {

class TimeOutEvent: public BurstEvent {
private:
	Data* args;
	Simulation* instance;
	int bursttime;
public:
	TimeOutEvent();
	virtual ~TimeOutEvent();
	TimeOutEvent(Data * aArgs, Simulation * aInstance, int time);
	virtual void processEvent();
	virtual Simulation* getSimInstance();
	virtual void print();
	virtual int getBurstTime();
	virtual void setBurstTime(int aBurstTime);
	virtual Data* getData();
	virtual void setData(Data * aEventData);
};

} /* namespace simu */

#endif /* TIMEOUTEVENT_H_ */
