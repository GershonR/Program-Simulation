/*
 * Util.h
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <sstream>
#include "Simulation.h"
using namespace std;
namespace simu {

class Util {
public:
	Util();
	virtual ~Util();
	virtual void processInput(char *argv[], Simulation * aSim);
	virtual Data* processData(string line, Simulation * aSim);
	virtual void processNext(Simulation * aSim);
	virtual void printStats(Queue * aQueue);
	virtual int compareTo(Event * eventOne, Event * eventTwo);
};

} /* namespace simu */

#endif /* UTIL_H_ */
