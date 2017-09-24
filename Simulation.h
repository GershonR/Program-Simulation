/*
 * Simulation.h
 *
 *  Created on: Mar 17, 2017
 *      Author: mama
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <string>
#include "Queue.h"
#include "OrderedQueue.h"
#include "Event.h"
#include "Stats.h"
#include "InputItem.h"

using namespace std;
namespace simu {

class Simulation {
public:
	Simulation();
	virtual ~Simulation();
	virtual void start();
	virtual void processEvent();
	virtual int getProcessID();
	virtual int getSimTime();
	virtual void increaseProcessID();
	virtual void increaseSimTime(int aTime);
	virtual void setSimTime(int aTime);
	virtual bool isCPUFree();
	virtual int getBurstTime();
	virtual void printEvent(int event, int ID, int time, int extra);
	virtual void setNextEvent(Event * aNextEvent);
	virtual void pushProcess(Data * aData);
	virtual Data* popProcess();
	virtual void pushEvent(Event * aEvent);
	virtual Event* popEvent();
	virtual Data* getCurrProcess();
	virtual void setCurrProcess(Data * aProcess);
	virtual Data* getNextProcess();
	virtual void setNextProcess(Data * aProcess);
	virtual void pushStat(Stats * aStats);
	virtual Stats* popStat();
	virtual Queue* getStats();
	virtual bool checkEmpty(Data * aData);
	virtual void pushLine(InputItem * aLine);
	virtual InputItem* popLine();
	virtual bool eventsEmpty();
	virtual bool inputEmpty();
private:
	Queue *inputlines;
	OrderedQueue *events;
	Queue *cpuevents;
	Queue *statlist;
	Data *currProcess;
	Data *nextProcess;
	Event *nextEvent;
    int processId;
    int currentTime;
    static const int BURST_TIME;

};

} /* namespace std */

#endif /* SIMULATION_H_ */
