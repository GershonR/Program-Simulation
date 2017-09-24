/*
 * ArrivalEvent.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

#include "ArrivalEvent.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Node.h"
#include "Data.h"
#include "Time.h"
#include "Util.h"
#include "StartCPUEvent.h"

using namespace std;
namespace simu {

ArrivalEvent::ArrivalEvent() {
	ArrivalEvent::instance = NULL;
	ArrivalEvent::time = 0;
	ArrivalEvent::data = NULL;
}

ArrivalEvent::ArrivalEvent(Data* aData, Simulation * aInstance, int aTime) {
	ArrivalEvent::data = aData;
	ArrivalEvent::instance = aInstance;
	ArrivalEvent::time = aTime;
}

ArrivalEvent::~ArrivalEvent() {

}

void ArrivalEvent::processEvent() {
	Util u;
	if(getData() != NULL) {
	    //getSimInstance()->pushProcess(getData());
	    Stats* s = getData()->getStats();
	    if(s != NULL) {
	    	s->setID(getData()->getID());
	    }
	    print();
	    getSimInstance()->increaseProcessID();
		Event *event = new StartCPUEvent(getData(), getSimInstance(), getTime());
		if(event != NULL)
			getSimInstance()->pushEvent(event);
		if(!getSimInstance()->inputEmpty())
			u.processNext(getSimInstance());
		getSimInstance()->processEvent();
	}

}


Data* ArrivalEvent::getData() {
	return ArrivalEvent::data;
}

void ArrivalEvent::setData(Data * aEventData) {
	ArrivalEvent::data = aEventData;
}

Simulation* ArrivalEvent::getSimInstance() {
	return ArrivalEvent::instance;
}

int ArrivalEvent::getTime() {
	return ArrivalEvent::time;
}

void ArrivalEvent::print() {
	getSimInstance()->printEvent(1, data->getID(), getTime(), -1);
}

} /* namespace simu */
