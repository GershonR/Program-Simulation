/*
 * InputItem.h
 *
 *  Created on: Mar 27, 2017
 *      Author: reydm_000
 */

#ifndef INPUTITEM_H_
#define INPUTITEM_H_
#include <string>

#include "DataItem.h"

using namespace std;
namespace simu {

class InputItem: public DataItem {
private:
	string line;
public:
	InputItem();
	InputItem(string aLine);
	virtual ~InputItem();
	virtual string getLine();
	virtual void setLine(string aLine);
	virtual void print();
};

} /* namespace simu */

#endif /* INPUTITEM_H_ */
