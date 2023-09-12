//Trisha Andres
//CPSC 1070: Section 2
//Group B6: C --
//03/01/2023

//include iostream for input and ouput 
#include <iostream>

//include header files of all needed
#include "MysteryMachine.h"
#include "Date.h"
#include "ParkingWars.h"

using namespace std;

int main(void) {

  //output welcome for the simulation
  cout<< "Welcome to Parking Wars!\n";
  cout<< "This program simulates an epic battle between Parking Services and students at Clementine University.\n\n";

  //create object for ParkingWars to be able to call runSimulation() function
  ParkingWars objParkingSim;

  //call the function to run the simulation in ParkingWars.cpp
  objParkingSim.runSimulation();

  //return zero for return int value
  return 0;
}
