/*
 * TimeOutEvent.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#include "TimeOutEvent.h"
#include "ArrivalEvent.h"
#include "StartCPUEvent.h"
#include "Time.h"
#include <iostream>

namespace simu {

TimeOutEvent::TimeOutEvent() {
	TimeOutEvent::instance = NULL;
	TimeOutEvent::args = NULL;
	TimeOutEvent::bursttime = 0;
}

TimeOutEvent::TimeOutEvent(Data * aArgs, Simulation * aInstance, int time) {
	TimeOutEvent::instance = aInstance;
	TimeOutEvent::args = aArgs;
	TimeOutEvent::bursttime = time;
}

TimeOutEvent::~TimeOutEvent() {
	// TODO Auto-generated destructor stub
}

void TimeOutEvent::processEvent() {
	if(args != NULL && instance != NULL) {
		getSimInstance()->increaseSimTime(getSimInstance()->getBurstTime());
		Data* d = getSimInstance()->getCurrProcess();
		//if(d != NULL && d->getTimeData()->getTime() <= getSimInstance()->getSimTime()) {
			//getSimInstance()->printEvent(1, d->getID(), getSimInstance()->getSimTime(), -1);
		//}
		d = getSimInstance()->popProcess();
		getSimInstance()->pushProcess(d);
		print();
		getSimInstance()->processEvent();
	}

}

Simulation* TimeOutEvent::getSimInstance() {
	return instance;
}

void TimeOutEvent::print() {
	getSimInstance()->printEvent(4, args->getID(), getSimInstance()->getSimTime(), getBurstTime());
}

int TimeOutEvent::getBurstTime() {
	return TimeOutEvent::bursttime;
}

void TimeOutEvent::setBurstTime(int aBurstTime) {
	TimeOutEvent::bursttime = aBurstTime;
}

Data* TimeOutEvent::getData() {
	return TimeOutEvent::args;
}

void TimeOutEvent::setData(Data * aEventData) {
	TimeOutEvent::args = aEventData;
}
} /* namespace simu */
