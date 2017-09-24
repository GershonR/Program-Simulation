/*
 * IO.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: reydm_000
 */

#include "IO.h"
#include <iostream>

using namespace std;
namespace simu {

IO::IO() {
	IO::iodevice = 0;
	IO::ioburst = 0;

}

IO::IO(int aIODevice, int aIOBurst) {
	IO::iodevice = aIODevice;
	IO::ioburst = aIOBurst;
}

IO::~IO() {

}

void IO::setIO(int aIO) {
	IO::iodevice = aIO;
}

int  IO::getIO() {
	return IO::iodevice;
}

void IO::setIOBurst(int aIOBurst) {
	IO::ioburst = aIOBurst;
}

int  IO::getIOBurst() {
	return IO::ioburst;
}

void IO::print() {
	cout << iodevice << " " << ioburst << " ";
}

} /* namespace simu */
