/*
 * BurstEvent.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

#include "BurstEvent.h"
#include <cstdlib>
#include <iostream>

using namespace std;
namespace simu {

BurstEvent::BurstEvent() {
	bursttime = 0;
}

BurstEvent::~BurstEvent() {

}

Simulation* BurstEvent::getSimInstance() {
	return NULL;
}

void BurstEvent::print() {
	cout << "Ay Caramba. Burst Event Has No Data." << endl;
}

int BurstEvent::getBurstTime() {
	return bursttime;
}

void BurstEvent::setBurstTime(int aBurstTime) {
	BurstEvent::bursttime = aBurstTime;
}

} /* namespace simu */
