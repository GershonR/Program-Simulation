/*
 * CompleteIODevice.cpp
 *
 * Gershon Reydman 7763541
 * Comp 2150 A2
 */

#include "CompleteIODevice.h"
#include "IO.h"

namespace simu {

CompleteIODevice::CompleteIODevice() {
	CompleteIODevice::instance = NULL;
	CompleteIODevice::args = NULL;
	CompleteIODevice::bursttime = 0;
	CompleteIODevice::iodevice = -1;
	CompleteIODevice::time = 0;

}

CompleteIODevice::CompleteIODevice(Data * aArgs, Simulation * aInstance, int aTime) {
	CompleteIODevice::instance = aInstance;
	CompleteIODevice::args = aArgs;
	CompleteIODevice::bursttime = 0;
	CompleteIODevice::iodevice = -1;
	CompleteIODevice::time = aTime;

}

CompleteIODevice::~CompleteIODevice() {
	// TODO Auto-generated destructor stub
}

Simulation* CompleteIODevice::getSimInstance() {
	return CompleteIODevice::instance;
}

void CompleteIODevice::processEvent() {
	if(args != NULL && instance != NULL) {
		int device = args->getIOData()->getIO();
		setBurstTime(device);
		int i = args->popIOBurst();
		print();
			//getSimInstance()->pushEvent(this);
			//getSimInstance()->processEvent();

	}

}

void CompleteIODevice::print() {
	getSimInstance()->printEvent(5, args->getID(), getSimInstance()->getSimTime(), getBurstTime());
}

int CompleteIODevice::getBurstTime() {
	return CompleteIODevice::bursttime;
}

void CompleteIODevice::setBurstTime(int aBurstTime) {
	CompleteIODevice::bursttime = aBurstTime;
}

Data* CompleteIODevice::getData() {
	return CompleteIODevice::args;
}

int CompleteIODevice::getTime() {
	return CompleteIODevice::time;
}

void CompleteIODevice::setData(Data * aEventData) {
	CompleteIODevice::args = aEventData;
}

} /* namespace simu */
