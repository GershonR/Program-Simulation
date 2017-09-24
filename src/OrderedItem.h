/*
 * OrderedItem.h
 *
 *  Created on: Mar 27, 2017
 *      Author: reydm_000
 */

#ifndef ORDEREDITEM_H_
#define ORDEREDITEM_H_

namespace simu {
class Event;
class OrderedItem {
private:
	int time;
	int ID;
	Event* event;
	OrderedItem* next;
public:
	OrderedItem();
	OrderedItem(int aTime, int aID, Event * aEvent);
	virtual ~OrderedItem();
	virtual int getTime();
	virtual int getID();
	virtual Event* getEvent();
	virtual void setTime(int aTime);
	virtual void setID(int aID);
	virtual void setEvent(Event *aEvent);
	virtual OrderedItem* getNext();
	virtual void setNext(OrderedItem*);
};

} /* namespace simu */

#endif /* ORDEREDITEM_H_ */
