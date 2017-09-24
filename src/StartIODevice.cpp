/*
 * StartIODevice.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#include "StartIODevice.h"
#include "CompleteIODevice.h"
#include <cstdlib>
#include <iostream>
#include "Time.h"
#include "IO.h"

namespace simu {

StartIODevice::StartIODevice() {
	StartIODevice::instance = NULL;
	StartIODevice::args = NULL;
	StartIODevice::bursttime = 0;
	StartIODevice::iodevice = -1;
	StartIODevice::time = 0;
}

StartIODevice::StartIODevice(Data * aArgs, Simulation * aInstance, int aTime) {
	StartIODevice::instance = aInstance;
	StartIODevice::args = aArgs;
	StartIODevice::bursttime = 0;
	StartIODevice::iodevice = -1;
	StartIODevice::time = aTime;

}

StartIODevice::~StartIODevice() {
	// TODO Auto-generated destructor stub
}

Simulation* StartIODevice::getSimInstance() {
	return StartIODevice::instance;
}

void StartIODevice::processEvent() {
	if(args != NULL && instance != NULL) {
		IO* i = args->getIOData();
		if(i != NULL) {
			int ioTime = args->getIOData()->getIOBurst();
			int device = args->getIOData()->getIO();
			if(device == 1)
				setBurstTime(ioTime);
			else
				setBurstTime(abs(ioTime));
			print();
			Event* event = new CompleteIODevice(args, getSimInstance(), getSimInstance()->getSimTime() + abs(ioTime));
			getSimInstance()->pushEvent(event);
			getSimInstance()->processEvent();
		}
	}

}

void StartIODevice::print() {
	getSimInstance()->printEvent(5, args->getID(), getSimInstance()->getSimTime(), getBurstTime());
}

int StartIODevice::getBurstTime() {
	return StartIODevice::bursttime;
}

void StartIODevice::setBurstTime(int aBurstTime) {
	StartIODevice::bursttime = aBurstTime;
}

Data* StartIODevice::getData() {
	return StartIODevice::args;
}

int StartIODevice::getTime() {
	return StartIODevice::time;
}

void StartIODevice::setData(Data * aEventData) {
	StartIODevice::args = aEventData;
}

} /* namespace simu */
