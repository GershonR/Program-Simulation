/*
 * DataItem.h
 *
 *  Created on: Mar 25, 2017
 *      Author: reydm_000
 */

#ifndef DATAITEM_H_
#define DATAITEM_H_

namespace simu {

class DataItem {
public:
	DataItem();
	virtual void print()=0;
	virtual ~DataItem();
};

}
#endif /* DATAITEM_H_ */
