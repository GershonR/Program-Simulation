/*
 * ArrivalEvent.h
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

#ifndef ARRIVALEVENT_H_
#define ARRIVALEVENT_H_

#include <sstream>
#include "Event.h"
#include "Simulation.h"

using namespace std;
namespace simu {
class ArrivalEvent: public Event {
private:
	Simulation* instance;
	Data* data;
	int time;
public:
	ArrivalEvent();
	ArrivalEvent(Data* aData, Simulation * instance, int aTime);
	virtual ~ArrivalEvent();
	virtual void processEvent();
	virtual Simulation* getSimInstance();
	virtual void print();
	virtual Data* getData();
	virtual void setData(Data * aEventData);
	virtual int getTime();
};

} /* namespace simu */

#endif /* ARRIVALEVENT_H_ */
