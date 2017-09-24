/*
 * Data.h
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

#ifndef DATA_H_
#define DATA_H_

#include<string>
#include "DataItem.h"

using namespace std;
namespace simu {
class Queue;
class Time;
class IO;
class Stats;
class Data : public DataItem {
public:
	Data();
	Data(int aID);
	Data(int aID, Time * aTime);
	virtual ~Data();
	virtual int getID();
	virtual void setID(int aID);
	virtual void pushCPUBurst(int time);
	virtual void pushIOBurst(int time);
	virtual int popCPUBurst();
	virtual int popIOBurst();
	virtual void print();
	virtual void decreaseCPUBurst();
	virtual Time* getTimeData();
	virtual IO* getIOData();
	virtual Stats* getStats();
	virtual bool isEmpty();
	virtual bool isCPUEmpty();

private:
	int ID;
	Stats *stats;
	Queue *cpubursts;
	Queue *iobursts;
	Time  *time;
};
}
#endif /* DATA_H_ */
