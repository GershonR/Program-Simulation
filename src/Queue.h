/*
 * Queue.h
 *
 *  Created on: Mar 17, 2017
 *      Author: mama
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Node.h"
namespace simu {
class Queue {
public:
	Queue();
	virtual ~Queue();
    virtual int size();
    virtual Node* front();
    virtual Node* back();
    virtual Node* pop();
    virtual void push(Node*);
    virtual bool empty();
    virtual void print();
private:
    int length;
    Node* head;
    Node* tail;
};

} /* namespace std */

#endif /* QUEUE_H_ */
