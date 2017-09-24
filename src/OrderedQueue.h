/*
 * OrderedQueue.h
 *
 *  Created on: Mar 27, 2017
 *      Author: reydm_000
 */

#ifndef ORDEREDQUEUE_H_
#define ORDEREDQUEUE_H_

#include "OrderedList.h"

namespace simu {

class OrderedQueue: public OrderedList {
private:
	OrderedList* orderedqueue;
	int size;
public:
	OrderedQueue();
	virtual ~OrderedQueue();
	virtual void push(OrderedItem * aItem);
	virtual OrderedItem* pop();
	virtual int getSize();
	virtual bool empty();
};

} /* namespace simu */

#endif /* ORDEREDQUEUE_H_ */
