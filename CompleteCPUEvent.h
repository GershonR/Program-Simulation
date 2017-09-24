/*
 * CompleteCPUEvent.h
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#ifndef COMPLETECPUEVENT_H_
#define COMPLETECPUEVENT_H_

#include "BurstEvent.h"
#include "Simulation.h"
#include "Data.h"

namespace simu {

class CompleteCPUEvent: public BurstEvent {
private:
	Data* args;
	Simulation* instance;
	int bursttime;
public:
	CompleteCPUEvent();
	CompleteCPUEvent(Data * aArgs, Simulation * aInstance, int time);
	virtual ~CompleteCPUEvent();
	virtual void processEvent();
	virtual Simulation* getSimInstance();
	virtual void print();
	virtual int getBurstTime();
	virtual void setBurstTime(int aBurstTime);
	virtual Data* getData();
};

} /* namespace simu */

#endif /* COMPLETECPUEVENT_H_ */
