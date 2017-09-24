/*
 * Stats.h
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#ifndef STATS_H_
#define STATS_H_

#include "DataItem.h"

namespace simu {

class Stats : public DataItem {
private:
	int arrivaltime;
	int cputime;
	int iotime1;
	int iotime2;
	int exittime;
	int waittime;
	int ID;
public:
	Stats();
	virtual ~Stats();
    virtual void setIOTime1(int aIOTime1);
    virtual void setIOTime2(int aIOTime2);
    virtual int getIOTime1();
    virtual int getIOTime2();
    virtual int getID();
    virtual void setArrivalTime(int aArrival);
    virtual void setCPUTime(int aCPUTime);
    virtual void setExitTime(int aExitTime);
    virtual void setWaitTime(int aWaitTime);
    virtual void setID(int aID);
    virtual int getArrivalTime();
    virtual int getCPUTime();
    virtual int getExitTime();
    virtual int getWaitTime();
    virtual void print();
};

} /* namespace simu */

#endif /* STATS_H_ */
