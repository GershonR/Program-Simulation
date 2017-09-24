/*
 * Util.cpp*
 * Gershon Reydman 7763541
 * Comp 2150 A2
 */
#include "Util.h"
#include "Data.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "ArrivalEvent.h"
#include "TimeOutEvent.h"
#include "Event.h"
#include "Time.h"
#include "InputItem.h"


#define MAX 100
namespace simu {

Util::Util() {
	// TODO Auto-generated constructor stub

}

Util::~Util() {
	// TODO Auto-generated destructor stub
}

void Util::processInput(char *argv[], Simulation * aSim) {
	InputItem* i;
	static ifstream infile;
	static char buffer[MAX];
	infile.open(argv[1]);
	  while(!infile.eof()){
		  infile.getline(buffer, MAX);
		  stringstream current(buffer);
		  string currLine = current.str();
		  i = new InputItem(currLine);
		  aSim->pushLine(i);
	  }
	  infile.close();
}


Data* Util::processData(string line, Simulation * aSim) {
	istringstream iss(line);
		int theNum = 0;
		int currDigit = 0;
		Data *d;
	    while (iss >> theNum) {
			if(currDigit == 0) { // MAKE EVENT AT THE NUM TIME
				d = new Data(aSim->getProcessID());
				if(aSim->eventsEmpty())
					aSim->setSimTime(theNum);
				d->getStats()->setArrivalTime(theNum);
			} else {
				if(currDigit % 2 == 0 && d != NULL) { // EVEN -> IO EVENT
					 d->pushIOBurst(theNum);
				 } else if(d != NULL) {
					 d->pushCPUBurst(theNum);
				 }
			}
			currDigit++;
		}
	    return d;
}

void Util::processNext(Simulation * aSim) {
	InputItem* i = aSim->popLine();
	if(i != NULL && aSim != NULL) {
		Data* d = processData(i->getLine(), aSim);
		ArrivalEvent* event = new ArrivalEvent(d, aSim, d->getStats()->getArrivalTime() );
		aSim->pushEvent(event);
		aSim->pushProcess(d);
	}

}

void Util::printStats(Queue * aQueue) {
	if(aQueue != NULL) {
		Node* n;
		n = aQueue->pop();
		cout << " Process    Arrival    CPU    I/O     Time    Exit    Wait   " << endl;
		cout << "   #           Time   Time   Dev 1    Dev 2   Time    Time" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		while(n != NULL) {
			DataItem* d = n->getData();
			if(d != NULL) {
				Stats* s = dynamic_cast<Stats*>(d);
				s->print();
			}
			n = aQueue->pop();
		}
	}
}

int Util::compareTo(Event * eventOne, Event * eventTwo) {
	int toReturn = -1;
	if(eventOne != NULL && eventTwo != NULL) {
		if(dynamic_cast<ArrivalEvent*>(eventOne) && (dynamic_cast<TimeOutEvent*>(eventTwo)))
				toReturn = 0;
	}
	return toReturn;

}

} /* namespace simu */
