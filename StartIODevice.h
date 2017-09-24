/*
 * StartIODevice.h
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#ifndef STARTIODEVICE_H_
#define STARTIODEVICE_H_

#include "BurstEvent.h"
#include "Simulation.h"
#include "Data.h"


namespace simu {

class StartIODevice: public BurstEvent {
private:
	Data* args;
	Simulation* instance;
	int bursttime;
	int iodevice;
	int time;
public:
	StartIODevice();
	StartIODevice(Data * aargs, Simulation * instance, int aTime);
	virtual ~StartIODevice();
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

#endif /* STARTIODEVICE_H_ */
