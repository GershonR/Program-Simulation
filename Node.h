/*
 * Node.h
 *
 *  Created on: Mar 16, 2017
 *      Author: mama
 */

#ifndef NODE_H_
#define NODE_H_

#include "DataItem.h"

namespace simu {

class Node {
public:
	Node();
	Node(DataItem * aItem);
	virtual ~Node();
	virtual Node* getNext();
	virtual void setNext(Node * linkedNode);
    virtual DataItem* getData();
    virtual void setData(DataItem* item);
private:
    Node *next;
	DataItem *item;
};

} /* namespace std */

#endif /* NODE_H_ */
