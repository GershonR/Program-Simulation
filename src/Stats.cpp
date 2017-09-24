/*
 * Stats.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#include "Stats.h"
#include <iostream>


using namespace std;
namespace simu {

Stats::Stats() {
	arrivaltime = 0;
	cputime = 0;
	iotime1 = 0;
	iotime2 = 0;
	exittime = 0;
	waittime = 0;
	ID = 0;

}

Stats::~Stats() {

}

void Stats::setID(int aID) {
	Stats::ID = aID;
}

void Stats::setIOTime1(int aIOTime1) {
	Stats::iotime1 = aIOTime1;
}

void Stats::setIOTime2(int aIOTime2) {
	Stats::iotime2 = aIOTime2;
}

void Stats::setArrivalTime(int aArrival) {
	Stats::arrivaltime = aArrival;
}

void Stats::setCPUTime(int aCPUTime) {
	Stats::cputime = aCPUTime;
}

void Stats::setExitTime(int aExitTime) {
	Stats::exittime = aExitTime;
}

void Stats::setWaitTime(int aWaitTime) {
	Stats::exittime = aWaitTime;
}

int Stats::getID() {
	return Stats::ID;
}

int Stats::getArrivalTime() {
	return Stats::arrivaltime;
}

int Stats::getCPUTime() {
	return Stats::cputime;
}

int Stats::getExitTime() {
	return Stats::exittime;
}

int Stats::getWaitTime() {
	return Stats::waittime;
}


int Stats::getIOTime1() {
	return Stats::iotime1;
}

int Stats::getIOTime2() {
	return Stats::iotime2;
}

void Stats::print() {
	cout << "   " << getID() << "             " << getArrivalTime() << "       " << getCPUTime() << "     " << getIOTime1()  << "      " << getIOTime2() << "         " << getExitTime() << "       " << getWaitTime() << endl;
}

} /* namespace simu */
