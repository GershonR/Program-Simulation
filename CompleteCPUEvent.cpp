/*
 * CompleteCPUEvent.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#include "CompleteCPUEvent.h"
#include "StartCPUEvent.h"
#include "StartIODevice.h"
#include "ExitEvent.h"
#include <cstdlib>
#include <iostream>
#include "Time.h"
#include "IO.h"

using namespace std;
namespace simu {

CompleteCPUEvent::CompleteCPUEvent() {
	CompleteCPUEvent::instance = NULL;
	CompleteCPUEvent::args = NULL;
	CompleteCPUEvent::bursttime = 0;
}

CompleteCPUEvent::CompleteCPUEvent(Data * aArgs, Simulation * aInstance, int time) {
	CompleteCPUEvent::instance = aInstance;
	CompleteCPUEvent::args = aArgs;
	CompleteCPUEvent::bursttime = time;
}

CompleteCPUEvent::~CompleteCPUEvent() {
	// TODO Auto-generated destructor stub
}

void CompleteCPUEvent::processEvent() {
	if(args != NULL && instance != NULL) {
		int burst = args->popCPUBurst();
		getSimInstance()->increaseSimTime(burst);
		print();
		Data* d = getSimInstance()->popProcess();
		if(d != NULL) {
			Event *event = new StartCPUEvent(d, getSimInstance(), getSimInstance()->getSimTime());
			getSimInstance()->pushEvent(event);
		}
		if(args != NULL) {
			if(args->isEmpty()) {
				Event *event = new ExitEvent(d, getSimInstance());
				getSimInstance()->pushEvent(event);
			} else {
				Event *event = new StartIODevice(d, getSimInstance(), getSimInstance()->getSimTime());
				getSimInstance()->pushEvent(event);
			}
		}
		getSimInstance()->processEvent();
	}

}

Simulation* CompleteCPUEvent::getSimInstance() {
	return instance;
}

void CompleteCPUEvent::print() {
	getSimInstance()->printEvent(3, args->getID(), getSimInstance()->getSimTime(), args->getIOData()->getIO());
}

Data* CompleteCPUEvent::getData() {
	return CompleteCPUEvent::args;
}

int CompleteCPUEvent::getBurstTime() {
	return CompleteCPUEvent::bursttime;
}

void CompleteCPUEvent::setBurstTime(int aBurstTime) {
	CompleteCPUEvent::bursttime = aBurstTime;
}

} /* namespace simu */
