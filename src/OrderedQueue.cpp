/*
 * OrderedQueue.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: reydm_000
 */

#include "OrderedQueue.h"
#include "OrderedItem.h"
#include <cstdlib>
#include <iostream>

using namespace std;
namespace simu {

OrderedQueue::OrderedQueue() {
	orderedqueue = new OrderedList();
	size = 0;

}

OrderedQueue::~OrderedQueue() {
	delete(orderedqueue);
}

void OrderedQueue::push(OrderedItem * aItem) {
	if(aItem != NULL) {
		orderedqueue->insert(aItem);
		OrderedQueue::size++;
	}
}

OrderedItem* OrderedQueue::pop() {
	OrderedItem* temp = orderedqueue->getHead();
	if(temp != NULL) {
		orderedqueue->setHead(temp->getNext());
		OrderedQueue::size--;
		if(OrderedQueue::size < 0)
			OrderedQueue::size = 0;
	}
	return temp;
}

int OrderedQueue::getSize() {
	return OrderedQueue::size;
}

bool OrderedQueue::empty() {
	int length = getSize();
	bool isEmpty = false;
	if(length == 0)
		isEmpty = true;
	return isEmpty;
}

} /* namespace simu */
