/*
 * Time.h
 *
 *  Created on: Mar 24, 2017
 *      Author: mama
 */

#ifndef TIME_H_
#define TIME_H_

#include "DataItem.h"

namespace simu {

class Time : public DataItem {
public:
	Time();
	Time(int aTime);
	virtual ~Time();
    virtual int getTime();
    virtual void setTime(int aTime);
    virtual void print();
private:
    int bursttime;
};

} /* namespace std */

#endif /* TIME_H_ */
