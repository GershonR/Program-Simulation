/*
 * Node.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: mama
 */

#include "Node.h"
#include <cstdlib>

namespace simu {

Node::Node() {
	Node::next = NULL;
	Node::item = NULL;
}

Node::Node(DataItem * aItem) {
	Node::next = NULL;
	Node::item = aItem;
}

Node::~Node() {
	delete(Node::item);
}

Node* Node::getNext() {
	return Node::next;
}

void Node::setNext(Node * linkedNode) {
	next = linkedNode;
}

DataItem* Node::getData() {
	return Node::item;
}

void Node::setData(DataItem * item) {
	Node::item = item;
}

} /* namespace std */
