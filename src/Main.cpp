/*
 * A2main.cpp
 * COMP 2150 Object Orientation
 * (C) Computer Science, University of Manitoba
 *
 * Main function for Assignment 2
 */
/*
 * Gershon Reydman 7763541
 * Comp 2150 A2
 */


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Simulation.h"
#include "Util.h"

using namespace simu;
using namespace std;
#define MAX 100

int main(int argc, char *argv[]){
  Util u;
  Simulation *sim = new Simulation();
  if(argc < 2){
    cout << "Usage: " << argv[0] << " <file name>\n";
    exit(1);
  }
  cout << "Simulation begins...\n";
  u.processInput(argv, sim);
  sim->start();
  cout << "\nEnd of processing.\n";
  u.printStats(sim->getStats());
  return 0;
}// main
