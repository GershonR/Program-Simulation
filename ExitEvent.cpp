/*
 * ExitEvent.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#include "ExitEvent.h"
#include "Time.h"
#include <iostream>

namespace simu {

ExitEvent::ExitEvent() {
	ExitEvent::instance = NULL;
	ExitEvent::args = NULL;

}

ExitEvent::ExitEvent(Data * aArgs, Simulation * aInstance) {
	ExitEvent::instance = aInstance;
	ExitEvent::args = aArgs;
}

ExitEvent::~ExitEvent() {
	// TODO Auto-generated destructor stub
}

void ExitEvent::processEvent() {
	if(args != NULL && instance != NULL) {
		Stats* s = args->getStats();
		if(s != NULL)
			getSimInstance()->pushStat(s);
		print();
		getSimInstance()->pushEvent(this);
		getSimInstance()->processEvent();
	}

}

Simulation* ExitEvent::getSimInstance() {
	return instance;
}

void ExitEvent::print() {
	getSimInstance()->printEvent(7, args->getID(), getSimInstance()->getSimTime(), args->getStats()->getWaitTime());
}

Data* ExitEvent::getData() {
	return ExitEvent::args;
}

void ExitEvent::setData(Data * aEventData) {
	ExitEvent::args = aEventData;
}

} /* namespace simu */
