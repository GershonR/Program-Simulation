/*
 * CompleteIODevice.h
 *
 */

#ifndef COMPLETEIODEVICE_H_
#define COMPLETEIODEVICE_H_

#include "BurstEvent.h"
#include "Simulation.h"
#include "Data.h"

namespace simu {

class CompleteIODevice: public BurstEvent {
private:
	Data* args;
	Simulation* instance;
	int bursttime;
	int iodevice;
	int time;
public:
	CompleteIODevice();
	virtual ~CompleteIODevice();
	CompleteIODevice(Data * aargs, Simulation * instance, int aTime);
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

#endif /* COMPLETEIODEVICE_H_ */
