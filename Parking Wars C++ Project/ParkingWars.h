//Trisha Andres                                                                    
//CPSC 1070: Section 2                                                           
//Group B6: C --                                                            
//03/01/2023 

#ifndef PARKINGWARS_H
#define PARKINGWARS_H

#include <iostream> //needed for function input/ouput (in .cpp)

#include "Date.h" //header needed for called Date functions

using namespace std;

class ParkingWars {
public:
  ParkingWars();
  
  void runSimulation();
  void runMonthSimulation(Date *startDatePtr);
  void updateDateArray(Date *newDatePtr);
  void writeToFile(Date *datePtr, bool studentsWon);
  
  bool runDaySimulation(Date *datePtr);
  
  int calculateParkingTicketsGiven();
  int calculateStudentsParkingWithoutPermit();
  
  
private:
  int arraySize;
  Date *datesToSimulate;
};

#endif
