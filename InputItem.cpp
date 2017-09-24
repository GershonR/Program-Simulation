/*
 * InputItem.cpp*
 * Gershon Reydman 7763541
 * Comp 2150 A2
 */

#include "InputItem.h"
#include <iostream>
using namespace std;
namespace simu {

InputItem::InputItem() {
	line = "";

}

InputItem::InputItem(string aLine) {
	InputItem::line = aLine;

}

InputItem::~InputItem() {
	// TODO Auto-generated destructor stub
}

string InputItem::getLine() {
	return InputItem::line;
}

void InputItem::setLine(string aLine) {
	InputItem::line = aLine;
}

void InputItem::print() {
	cout << InputItem::line << endl;
}

} /* namespace simu */
