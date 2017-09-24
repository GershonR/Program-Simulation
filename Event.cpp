/*
 * Event.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: mama
 */

#include "Event.h"
#include <cstdlib>
#include <iostream>

using namespace std;
namespace simu {

Event::Event() {


}

Event::~Event() {

}

Simulation* Event::getSimInstance() {
	return NULL;
}

Data* Event::getData() {
	return NULL;
}

int Event::getTime() {
	return 0;
}

void Event::setTime(int aTime) {

}

void Event::setData(Data * aEventData) {

}

void Event::print() {
	cout << "Something Wrong. I Hold My Head. Child Event Gone. An Event Dead" << endl;
}

} /* namespace std */
