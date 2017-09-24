/*
 * Time.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: mama
 */

#include "Time.h"
#include <iostream>


using namespace std;
namespace simu {

Time::Time() {
  Time::bursttime = 0;
}

Time::Time(int aTime) {
  Time::bursttime = aTime;
}

Time::~Time() {

}

void Time::setTime(int aTime) {
	bursttime = aTime;
}

int  Time::getTime() {
	return bursttime;
}

void Time::print() {
	cout << bursttime << " ";
}

} /* namespace std */
