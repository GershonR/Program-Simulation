/*
 * Queue.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: mama
 */

#include "Queue.h"
#include <cstdlib>
#include <iostream>

using namespace std;
namespace simu {

Queue::Queue() {
	Queue::length = 0;
	Queue::head = NULL;
	Queue::tail = NULL;

}

Queue::~Queue() {
	  if(!empty()) {
		  Node * current = front();
		  Node * temp;
		  while(current)
		  {
			  temp = current;
			  current = current->getNext();
			  delete temp;
		  }
	  }
	Queue::head = NULL;
	Queue::tail = NULL;
	Queue::length = 0;
}

int Queue::size() {
	return Queue::length;
}

Node* Queue::front() {
	return Queue::head;
}

Node* Queue::back() {
	return Queue::tail;
}

Node* Queue::pop() {
	Node* curr = front();
	if(curr != NULL) {
		if(curr->getNext() != NULL) {
			head = curr->getNext();
		} else {
			head = NULL;
			tail = NULL;
		}
		length--;
	}
	return curr;
}

void Queue::push(Node * linkedNode) {
	if(linkedNode != NULL) {
		linkedNode->setNext(NULL);
		if(empty()) {
			Queue::head = linkedNode;
			Queue::tail = Queue::head;
			Queue::length++;
		} else {
			Queue::tail->setNext(linkedNode);
			Queue::tail = Queue::tail->getNext();
			Queue::length++;
		}
	}

}

bool Queue::empty() {
	bool empty = false;
	if(Queue::length == 0)
		empty = true;
	return empty;
}

void Queue::print() {
	Node* curr = front();
	while(curr != NULL) {
		DataItem* d = curr->getData();
		d->print();
		curr = curr->getNext();
	}
	cout << " " << endl;
}

} /* namespace std */
