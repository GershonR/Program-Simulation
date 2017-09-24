/*
 * Event.h
 *
 *  Created on: Mar 17, 2017
 *      Author: mama
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "DataItem.h"


namespace simu {
class Node;
class Data;
class Simulation;
class Event: public DataItem {
public:
	Event();
	virtual ~Event();
	virtual void processEvent()=0;
	virtual Simulation* getSimInstance();
	virtual void print();
	virtual Data* getData();
	virtual int getTime();
	virtual void setTime(int aTime);
	virtual void setData(Data * aEventData);
};

} /* namespace std */

#endif /* EVENT_H_ */
