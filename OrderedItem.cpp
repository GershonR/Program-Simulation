/*
 * OrderedItem.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: reydm_000
 */

#include "OrderedItem.h"
#include <cstdlib>

using namespace std;
namespace simu {

OrderedItem::OrderedItem() {
	OrderedItem::time = 0;
	OrderedItem::ID = 0;
	OrderedItem::event = NULL;
	OrderedItem::next = NULL;

}

OrderedItem::~OrderedItem() {

}

OrderedItem::OrderedItem(int aTime, int aID, Event * aEvent) {
	OrderedItem::time = aTime;
	OrderedItem::ID = aID;
	OrderedItem::event = aEvent;
	OrderedItem::next = NULL;
}

int OrderedItem::getTime() {
	return OrderedItem::time;
}

int OrderedItem::getID() {
	return OrderedItem::ID;
}

Event* OrderedItem::getEvent() {
	return OrderedItem::event;
}

OrderedItem* OrderedItem::getNext() {
	return OrderedItem::next;
}

void OrderedItem::setTime(int aTime) {
	OrderedItem::time = aTime;
}

void OrderedItem::setID(int aID) {
	OrderedItem::time = aID;
}

void OrderedItem::setEvent(Event * aEvent) {
	OrderedItem::event = aEvent;
}

void OrderedItem::setNext(OrderedItem * aNext) {
	OrderedItem::next = aNext;
}

} /* namespace simu */
