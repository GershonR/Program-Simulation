/*
 * BurstEvent.h
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

#ifndef BURSTEVENT_H_
#define BURSTEVENT_H_

#include "Event.h"

namespace simu {

class BurstEvent: public Event {
private:
	int bursttime;
public:
	BurstEvent();
	virtual ~BurstEvent();
	virtual Simulation* getSimInstance();
	virtual void print();
	virtual int getBurstTime();
	virtual void setBurstTime(int aBurstTime);
};

} /* namespace simu */

#endif /* BURSTEVENT_H_ */
