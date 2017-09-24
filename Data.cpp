/*
 * Data.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

#include "Data.h"
#include "Queue.h"
#include "Node.h"
#include "Time.h"
#include "IO.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Stats.h"


using namespace std;
namespace simu {
Data::Data() {
	cpubursts = new Queue();
	iobursts = new Queue();
	time = NULL;
	Data::ID = 0;
	stats = new Stats();
}

Data::Data(int aID) {
	cpubursts = new Queue();
	iobursts = new Queue();
	time = NULL;
	Data::ID = aID;
	stats = new Stats();
}

Data::Data(int aID, Time * aTime) {
	Data::cpubursts = new Queue();
	iobursts = new Queue();
	Data::time = aTime;
	Data::ID = aID;
	stats = new Stats();
}

Data::~Data() {
	delete(cpubursts);
	delete(iobursts);
	delete(stats);
}

int Data::getID() {
	return Data::ID;
}

void Data::setID(int aID) {
	Data::ID = ID;
}

void Data::pushCPUBurst(int time) {
	Time *t = new Time(time);
	Data::cpubursts->push(new Node(t));
}

void Data::pushIOBurst(int time) {
	IO* i;
	int device = 0;
    if(time >= 0)
    	device = 1;
    else
    	device = 2;
	i = new IO(device, time);
	Data::iobursts->push(new Node(i));
}

int Data::popCPUBurst() {
	int burst = -1;
	Time* t = getTimeData();
	if(t != NULL)
		burst = t->getTime();
	Data::cpubursts->pop();
	return burst;
}

int Data::popIOBurst() {
	int burst = -1;
		IO* i = getIOData();
		if(i != NULL)
			burst = i->getIOBurst();

		Data::iobursts->pop();
		return burst;
}

Time* Data::getTimeData() {
	Time* t;
	Node* n = cpubursts->front();
	if(n != NULL) {
		DataItem* d = NULL;
		d = n->getData();
		if(d != NULL)
				t = dynamic_cast<Time*>(d); //cast DataItem as Time
		}
	return t;
}

IO* Data::getIOData() {
	IO* i;
	Node* n = iobursts->front();
	if(n != NULL) {
		DataItem* d = NULL;
		d = n->getData();
		if(d != NULL)
				i = dynamic_cast<IO*>(d); //cast DataItem as Time
		}
	return i;
}

void Data::decreaseCPUBurst() {
	Time* t = getTimeData();
	t->setTime(t->getTime()-1);
}

bool Data::isEmpty() {
	bool empty = false;
	if(cpubursts->empty() && iobursts->empty())
		empty = true;
	return empty;
}

bool Data::isCPUEmpty() {
	bool empty = false;
	if(cpubursts->empty())
		empty = true;
	return empty;
}

Stats* Data::getStats() {
	return Data::stats;
}

void Data::print() {
	cout << "Data ID: " << Data::ID << endl;
	cout << "CPU Bursts: " << endl;
	Data::cpubursts->print();
	cout << "I\\O Bursts: " << endl;
	Data::iobursts->print();
}

}

