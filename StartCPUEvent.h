/*
 * StartCPUEvent.h
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

#ifndef STARTCPUEVENT_H_
#define STARTCPUEVENT_H_

#include "BurstEvent.h"
#include "Simulation.h"
#include "Data.h"

namespace simu {
class StartCPUEvent: public BurstEvent {
private:
	Data* args;
	Simulation* instance;
	int bursttime;
	int time;
public:
	StartCPUEvent();
	StartCPUEvent(Data * args, Simulation * instance, int aTime);
	virtual ~StartCPUEvent();
	virtual void processEvent();
	virtual Simulation* getSimInstance();
	virtual void print();
	virtual int getBurstTime();
	virtual int getTime();
	virtual void setBurstTime(int aBurstTime);
	virtual Data* getData();
	virtual void setData(Data * aEventData);
};

} /* namespace simu */

#endif /* STARTCPUEVENT_H_ */
