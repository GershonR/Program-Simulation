/*
 * OrderedList.h
 *
 *  Created on: Mar 27, 2017
 *      Author: reydm_000
 */

#ifndef ORDEREDLIST_H_
#define ORDEREDLIST_H_

namespace simu {
class OrderedItem;
class OrderedList {
private:
	OrderedItem* head;
	int size;
public:
	OrderedList();
	virtual ~OrderedList();
	virtual void insert(OrderedItem * aItem);
	virtual void remove(OrderedItem * aItem);
	virtual OrderedItem* getHead();
	virtual void setHead(OrderedItem * aItem);
	virtual int getSize();
	virtual void setSize(int aSize);
	virtual bool empty();
	virtual void print();
};

} /* namespace simu */

#endif /* ORDEREDLIST_H_ */
