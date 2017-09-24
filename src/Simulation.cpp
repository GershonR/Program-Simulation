/*
 * Simulation.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: mama
 */
/*
 */


#include "Simulation.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Data.h"
#include "ArrivalEvent.h"
#include "StartCPUEvent.h"
#include "CompleteCPUEvent.h"
#include "TimeOutEvent.h"
#include "StartIODevice.h"
#include "ExitEvent.h"
#include "Time.h"
#include "Util.h"
#include "OrderedItem.h"

using namespace std;
namespace simu {

const int Simulation::BURST_TIME = 4;

Simulation::Simulation() {
	Simulation::events = new OrderedQueue();
	Simulation::cpuevents = new Queue();
	Simulation::statlist = new Queue();
	Simulation::inputlines = new Queue();
	Simulation::currProcess = NULL;
	Simulation::nextProcess = NULL;
	Simulation::nextEvent = NULL;
	Simulation::processId = 1;
	Simulation::currentTime = 0;


}

Simulation::~Simulation() {
	delete(events);
	delete(cpuevents);
	delete(currProcess);
	delete(statlist);
}

void Simulation::start() {
	Util u;
	Node* n = Simulation::inputlines->pop();
	InputItem* i;
	if(n != NULL) {
		i = dynamic_cast<InputItem*>(n->getData());
		if(i != NULL) {
			Data* d = u.processData(i->getLine(), this);
			ArrivalEvent* event = new ArrivalEvent(d, this, d->getStats()->getArrivalTime());
			pushEvent(event);
			processEvent();

		}
	}


}

void Simulation::processEvent() {
	if(events->getSize() > 0) {
		Event* event = popEvent();
		Util u;
		if(event != NULL) {
			Data* d = event->getData();
			cout << "" << endl;
			if(d != NULL) {
				event->processEvent();
			}
		}
	}

}

bool Simulation::checkEmpty(Data * aData) {
	bool empty = false;
	if(aData != NULL && aData->isEmpty()) {
		empty = true;
		ExitEvent* event = new ExitEvent(aData, this);
		event->processEvent();
	}
	return empty;

}

bool Simulation::inputEmpty() {
	bool empty = false;
	if(inputlines->empty()) {
		empty = true;
	}
	return empty;

}

void Simulation::pushLine(InputItem* aLine) {
	Node* n = new Node(aLine);
	Simulation::inputlines->push(n);
}

InputItem* Simulation::popLine() {
	Node* n = Simulation::inputlines->pop();
	InputItem* i;
	if(n != NULL) {
		i = dynamic_cast<InputItem*>(n->getData());
	}
	return i;
}

int Simulation::getProcessID() {
	return Simulation::processId;
}

int Simulation::getSimTime() {
	return Simulation::currentTime;
}

void Simulation::increaseProcessID() {
	Simulation::processId++;
}

void Simulation::increaseSimTime(int aTime) {
	Simulation::currentTime += aTime;
}

void Simulation::setSimTime(int aTime) {
	Simulation::currentTime = aTime;
}

int Simulation::getBurstTime() {
	return Simulation::BURST_TIME;
}

void Simulation::setNextEvent(Event * aNextEvent) {
	Simulation::nextEvent = aNextEvent;
}

void Simulation::setCurrProcess(Data * aProcess) {
	Simulation::currProcess = aProcess;
}

Data* Simulation::getCurrProcess() {
	Data* d;
	if(cpuevents != NULL && cpuevents->front() != NULL)
		d =  dynamic_cast<Data*>(cpuevents->front()->getData());
	return d;
}

void Simulation::setNextProcess(Data * aProcess) {
	Simulation::nextProcess = aProcess;
}

Data* Simulation::getNextProcess() {
	Data* d;
	if(cpuevents != NULL && cpuevents->front() != NULL) {
		Node* n = cpuevents->front()->getNext();
		d = dynamic_cast<Data*>(n->getData());
	}
	return d;
}

void Simulation::pushProcess(Data * aData) {
	if(aData != NULL) {
		Node* n = new Node(aData);
		Simulation::cpuevents->push(n);
	}
}

Data* Simulation::popProcess() {
	Node* n = Simulation::cpuevents->pop();
	Data* d;
	if(n != NULL) {
		d = dynamic_cast<Data*>(n->getData());
	}
	return d;
}

void Simulation::pushEvent(Event * aEvent) {
	if(aEvent != NULL) {
		Data* d = aEvent ->getData();
		if(d != NULL) {
			OrderedItem* i = new OrderedItem(aEvent->getTime(), aEvent->getData()->getID(), aEvent);
			Simulation::events->push(i);
		}
	}
}

Event* Simulation::popEvent() {
	OrderedItem* i = Simulation::events->pop();
	Event* e;
	if(i != NULL) {
		e = dynamic_cast<Event*>(i->getEvent());
	}
	return e;
}

void Simulation::pushStat(Stats * aStat) {
	if(aStat != NULL) {
		Node* n = new Node(aStat);
		Simulation::statlist->push(n);
	}
}

Stats* Simulation::popStat() {
	Node* n = Simulation::statlist->pop();
	Stats* s;
	if(n != NULL) {
		s = dynamic_cast<Stats*>(n->getData());
	}
	return s;
}

Queue* Simulation::getStats() {
	return Simulation::statlist;
}

bool Simulation::isCPUFree() {
	bool empty = false;
	if(Simulation::cpuevents->empty())
		empty = true;
	return empty;
}

bool Simulation::eventsEmpty() {
	bool empty = false;
	if(Simulation::events->empty())
		empty = true;
	return empty;
}


/*
 * Print the output for a Simulation event.
 * C++ does not support strings in switches, numbers are used instead
 */
void Simulation::printEvent(int event, int ID, int time, int extra) {
	string string[] = {
			"arrives in system: CPU is free (process begins execution). ",
			"begins CPU burst of length ",
			"arrives in system: CPU is busy (process will be queued). ",
			"exhausts its time quantum (requires ",
			"completes CPU burst. Queueing for I/O Device 1.",
			"completes CPU burst. Queueing for I/O Device 2.",
			"begins I/O Device 1 burst of length ",
			"begins I/O Device 2 burst of length ",
			"completes I/O Device 1 burst. Queueing for CPU.",
			"completes I/O Device 2 burst. Queueing for CPU.",
			"completes CPU burst.",
			"complete. Total wait time is: "};
	 cout << "Time   " << getSimTime() << ": Process:  " << ID << " ";
	switch(event) {
		case 1:	//Arrival Events
			 if(isCPUFree())
				 cout << string[0] << endl;
			 else
				 cout << string[2] << endl;
		break;
		case 2:	//StartCPU Events
			  cout << string[1] << extra << endl;
		break;
		case 3:	//Complete Events
			  if(extra == 1)
				  cout << string[4] << endl;
			  else
				  cout << string[5] << endl;
		break;
		case 4:	//TimeOut Events
			  cout << string[3] << extra << " units more)." << endl;
		break;
		case 5:	//StartIO Events
			  if(extra == 1)
				  cout << string[8] << abs(extra) << endl;
			  else
				  cout << string[9] << abs(extra) << endl;
		break;
		case 6: //Complete IO Burst
			  if(extra == 1)
				  cout << string[4] << endl;
			  else
				  cout << string[5] << endl;
		break;
		case 7:	//Exit Events
			cout << string[9] << extra << endl;
		break;


	}

}


} /* namespace std */
