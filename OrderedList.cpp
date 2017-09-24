/*
 * OrderedList.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: reydm_000
 */

#include "OrderedList.h"
#include <cstdlib>
#include <iostream>
#include "OrderedItem.h"
#include "Util.h"

using namespace std;
namespace simu {

OrderedList::OrderedList() {
	OrderedList::head = NULL;
	OrderedList::size = 0;

}

OrderedList::~OrderedList() {
	  if(!empty()) {
		  OrderedItem * current = getHead();
		  OrderedItem * temp;
		  while(current)
		  {
			  temp = current;
			  current = current->getNext();
			  delete (temp);
		  }
	  }
	  OrderedList::head = NULL;
	  OrderedList::size = 0;
}

int OrderedList::getSize() {
	return OrderedList::size;
}

void OrderedList::setSize(int aSize) {
	OrderedList::size = aSize;
}

OrderedItem* OrderedList::getHead() {
	return OrderedList::head;
}

void OrderedList::setHead(OrderedItem* aItem) {
	OrderedList::head = aItem;
}

bool OrderedList::empty() {
	bool empty = false;
	if(OrderedList::size == 0)
		empty = true;
	return empty;
}

void OrderedList::insert(OrderedItem * item) {
	if(item != NULL) {
		item->setNext(NULL);
		if(empty() || getHead() == NULL) {
			OrderedList::head = item;
			OrderedList::size = 1;
		} else {
			OrderedItem * temp = getHead();
			OrderedItem * prev = NULL;
			if(temp != NULL) {
				if(temp->getTime() > item->getTime()) {
					item->setNext(temp);
					OrderedList::head = item;
				} else {
						bool done = false;
						int spot = 0;
						while( temp != NULL && !done && spot < size) {					  // move to current time
							if(temp->getTime() >= item->getTime()) {
								done = true;
								prev = temp;
							} else {
								prev = temp;
								temp = temp->getNext();
								spot++;
							}
						}
						if(prev != NULL && prev->getTime() == item->getTime()) {
							Util u;
							if(u.compareTo(item->getEvent(), prev->getEvent()) == 0) { // item is an ArrivalEvent and there is a TimeOut
								item->setNext(prev->getNext());
								prev->setNext(item);
								OrderedList::size++;
							} else {
								while(prev != NULL && prev->getID() < item->getID()) {				  // move to the next available ID
									prev = prev -> getNext();
								}
								if(prev != NULL) {
									item->setNext(prev->getNext());
									prev->setNext(temp);
									OrderedList::size++;
								}
							}
						  } else {
							item->setNext(prev->getNext());							// just add to the back
							prev->setNext(item);
							OrderedList::size++;
						  }
				}
			}
		}
	}
}

void OrderedList::remove(OrderedItem * aItem) {
	OrderedItem * temp = getHead();
	OrderedItem * prev = NULL;
	if(temp != NULL && aItem != NULL) {
		while(temp != NULL && temp->getID() != aItem->getID()) {
			prev = temp;
			temp = temp->getNext();
		}
		if(temp != NULL && prev != NULL) {
			if(temp->getID() == aItem->getID()) {
				prev->setNext(temp->getNext());
				delete(temp);
			}
		}

	}
}

void OrderedList::print() {
	OrderedItem * temp = getHead();
		if(temp != NULL) {
			Event*  e= temp->getEvent();
			if(e != NULL)
				e->print();
		}
}

} /* namespace simu */
