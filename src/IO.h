/*
 * IO.h
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#ifndef IO_H_
#define IO_H_

#include "DataItem.h"

namespace simu {

class IO: public DataItem {
public:
	IO();
	IO(int aIODevice, int aIOBurst);
	virtual ~IO();
    virtual int getIO();
    virtual void setIO(int aIODevice);
    virtual int getIOBurst();
    virtual void setIOBurst(int aIOBurst);
    virtual void print();
private:
    int iodevice;
    int ioburst;
};

} /* namespace simu */

#endif /* IO_H_ */
