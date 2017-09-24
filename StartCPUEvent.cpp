/*
 * StartCPUEvent.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

/*
 A StartCPU event causes the Process to be scheduled to	execute	on	the	CPU. Our	OS
supports timesharing: each Process may	use	the	CPU	for	a	maximum	time quantum of	4
time units. Note that a real OS	does not know beforehand if	a	Process	will exhaust	its	time
quantum, but in	our	simulation	model,	we	know the length	of	a CPU	burst,	so	we	know
whether the	process	will timeout (you should schedule a Timeout event) or complete the
burst (you	should	schedule a CompleteCPU event).
 */

#include "StartCPUEvent.h"
#include "TimeOutEvent.h"
#include "CompleteCPUEvent.h"
#include <cstdlib>
#include <iostream>
#include "Time.h"
using namespace std;
namespace simu {

StartCPUEvent::StartCPUEvent() {
	StartCPUEvent::instance = NULL;
	StartCPUEvent::args = NULL;
	StartCPUEvent::bursttime = 0;
	StartCPUEvent::time = 0;

}

StartCPUEvent::StartCPUEvent(Data * aArgs, Simulation * aInstance, int aTime) {
	StartCPUEvent::args = aArgs;
	StartCPUEvent::instance = aInstance;
	StartCPUEvent::bursttime = 0;
	StartCPUEvent::time = aTime;
}

StartCPUEvent::~StartCPUEvent() {

}

void StartCPUEvent::processEvent() {
	if(args != NULL && instance != NULL) {
		int maxTime = getSimInstance()->getBurstTime();			//Defined MAX_BURST time -> 4
		Time* t = args->getTimeData();
		int id = args->getID();
		getSimInstance()->pushProcess(args);
		if(t != NULL && t->getTime() > 0) {
			Event* event;
			setBurstTime(t->getTime());    	//Time the process requires
			int timeDifference = getBurstTime() - maxTime;				//Time process requires - MAX_BURST
			if(timeDifference > 0) {								//More time is still needed -> call a timeOut
				args->getTimeData()->setTime(timeDifference);
				print();
				event = new TimeOutEvent(getData(), getSimInstance(), timeDifference);
			} else {												//Had enough time -> call completeCPUEvent
				print();
				event = new CompleteCPUEvent(args, getSimInstance(), maxTime);
			}
			if(event != NULL) {
				getSimInstance()->pushEvent(event);
				getSimInstance()->processEvent();
			}
		}
	}

}

Simulation* StartCPUEvent::getSimInstance() {
	return instance;
}

void StartCPUEvent::print() {
	getSimInstance()->printEvent(2, args->getID(), getSimInstance()->getSimTime(), getBurstTime());
}

int StartCPUEvent::getBurstTime() {
	return StartCPUEvent::bursttime;
}

void StartCPUEvent::setBurstTime(int aBurstTime) {
	StartCPUEvent::bursttime = aBurstTime;
}

Data* StartCPUEvent::getData() {
	return StartCPUEvent::args;
}

int StartCPUEvent::getTime() {
	return StartCPUEvent::time;
}

void StartCPUEvent::setData(Data * aEventData) {
	StartCPUEvent::args = aEventData;
}

} /* namespace simu */
