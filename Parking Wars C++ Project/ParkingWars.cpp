//Trisha Andres                                                                     
//CPSC 1070: Section 2                                                              
//Group B6: C --                                                                    
//03/01/2023

//include header files from date and parkiingwars
#include "Date.h"
#include "ParkingWars.h"

#include <ctime> //used for random number generator
#include <unistd.h> //creates clock for usleep(x)
#include <fstream> //input/output file stream

using namespace std;

ParkingWars::ParkingWars(){}; //default constructor

void ParkingWars::runSimulation() { //run simulation function, gets month, day, and year inputs and calls to start runMonthSimulation

  int inMonth, inDay, inYear; //declare variables for inputs

  //prompt user to input info
  cout<< "Please enter the date you's like to start the simulation in MM DD YYYY format: ";
  cin>> inMonth >> inDay >> inYear; //obtain inputted info

  Date objDate(inMonth, inDay, inYear); //created Date class object with inputs as parameters
  Date *datePtr = &objDate; //date pointer for object
  Date dateArr[] = {objDate}; //array with object 
  datesToSimulate = dateArr; //the data array is the dates needed to be simulated
  arraySize = 1; //initialize array size

  runMonthSimulation(datePtr); //call on runMonthSimulation with date pointer as parameter
}

void ParkingWars::runMonthSimulation(Date *startDatePtr) { //runs simulation for entire month given, starting on day given

  int month = startDatePtr->getMonth() - 1; //gets month of simulation
  int day = startDatePtr->getDay(); //gets day the simulation is starting on
  int numStudentWin = 0, numParkingWin = 0; //variables for how many wins students and parking gets
  int startingMonth = month + 1, startingDay = day; //starting month and day
  int startingYear = startDatePtr->getYear(); //starting year
  int maxDays = startDatePtr->daysInMonths[month]; //max number of days in the month of the simulation
  bool stuWin; //boolean for if students win

  string dayOfSim = startDatePtr->getDayOfWeek(); //string for the day ("Monday", "Tuesday", etc)

  
  if (dayOfSim == "Saturday") //if day is saturday, call operator to change to monday
	{
	  startDatePtr->operator+(1);
	}
  else if (dayOfSim == "Sunday") //if day is sunday, call operator to change to monday
	{
	  startDatePtr->operator++(1);
	}


  while (startDatePtr->getMonth() == startingMonth) //while in the month, see if students have won
    {
	  stuWin = runDaySimulation(startDatePtr);
	  
	  if(stuWin == true) //if students have one, add a win to studen win variable
	    {
	      ++numStudentWin;
	    }
	  else //else add a win to parking win variable
	    {
	      ++numParkingWin;
	    }
	  ++(*startDatePtr); //increment date
	}
  
  //print out summary of how many days students won and how many days parking won
  cout<< "Summary for starting on " << startingMonth << "/" << startingDay << "/" << startingYear << ": " << endl;
  cout<< "Students won a total of " << numStudentWin << " days!" << endl;
  cout<< "Parking won a total of " << numParkingWin << " days!" << endl;
}

void ParkingWars::updateDateArray(Date *newDatePtr) { //updates the array of the daye
  //1 + array size (starts at 1)
  ++arraySize;

  Date *newArrPtr = new Date[arraySize]; //use new to make array for this simulation

  for (int i = 0; i < arraySize - 1; i++) //for loop to update array  
    {
      newArrPtr[arraySize - 1] = *newDatePtr;
    }

  newArrPtr[arraySize - 1] = *newDatePtr;

  datesToSimulate = newArrPtr;

  delete [] newArrPtr;//delete the new array made 
  newArrPtr = nullptr; 
  
}

bool ParkingWars::runDaySimulation(Date *datePtr) { //function to run simulation for the day, parking tickets given on a certain day and numebr of students parking without a permit on a certain day
  int numStuNoPerm;
  int numParTix;
  int numTix = 0;
  bool stuWin;

  //output for simulation day
  cout << "Running simulation for " << datePtr->getDayOfWeek() << " " << datePtr->getMonth() << "/" << datePtr->getDay() << "/" << datePtr->getYear() << endl;

  //call calcuation functions to get number of parking tickets given and number of students without a permit
  numParTix = calculateParkingTicketsGiven();
  numStuNoPerm = calculateStudentsParkingWithoutPermit();

  //output data 
  cout<< "Number of tickets given: " << numParTix << endl;
  cout<< "Number of students parking without permits: " << numStuNoPerm << endl;

  if (numStuNoPerm >= numParTix) //if more (or equal to)  students are parking without a permit than the numebr of tickets given, students won
    {
      cout << "\tStudents won!\n\n";
      stuWin = true;
    }
  else //else parking won
    {
      cout << "\tParking won!\n\n";
      stuWin = false;
    }

  datesToSimulate = datePtr;

  updateDateArray(datePtr); //call to update array
  writeToFile(datePtr,stuWin); //call to write wins into a new file

  return stuWin;
}

int ParkingWars::calculateParkingTicketsGiven() { //function that calculates the number of parking tickets given
  int randNum = 0;
  int tixGiven = 0;
  int parameter = 0;

  while (parameter < 10)
    {
      usleep(0.05); //creates a clock taht ticks once per 0.05 seconds
      randNum = (rand() % 100); //random number 

      if (randNum < 35) //if random number is less than 35 then calculate number of tickets given (tickets given + 0)
	{
	  tixGiven += 0;
	}
      else if (randNum < 65) //if random number is less than 65 then calc number of tickets given (tickets given + 9)
	{
	  tixGiven += 9;
	}
      else if (randNum < 95) //if random number is less than 95 then calc number of tickets given (tickets given + 1)
	{
	  tixGiven += 1;
	}
      else { //else (tickets given + 12)
	tixGiven += 12;
      }
      ++parameter; //1 + parameter
    }
  return tixGiven;
}

int ParkingWars::calculateStudentsParkingWithoutPermit() { //function to calculate how many students there are parking without a permit
  int randNum = 0;
  int permitCount = 0;
  int parameter = 0;


  while (parameter < 10) 
    {
      usleep(0.05); //creates a clock that ticks once per 0.05 seconds
      randNum = (rand() % 100); //gets random number (1-100)

      if (randNum < 50) //if random number is less than 50, the number of students parkign without a permit is (permit count + 3)
	{
	  permitCount += 3;
	}
      else if (randNum < 85) //if random number if less than 85, the number of students parking without a permit is (permitCount + 1)
	{
	  permitCount += 1;
	}
      else //else permiCount = permitCount + 6
	{
	  permitCount += 6;
	}
      ++parameter; //1 + parameter
    }
  return permitCount;
}

void ParkingWars::writeToFile(Date *datePtr, bool studentsWon) { //function to output data to a separate file "log.txt"
  
  static int numOfDay = 0;

  ofstream outFile;
  outFile.open("log.txt", fstream::app); //output file is log.txt

  outFile << datePtr->getDayOfWeek() << " " << datePtr->getMonth() << "/" <<datePtr->getDay() << "/" <<datePtr->getYear() << ": "; //output date info to file

  //output who won on that day to file
  if (studentsWon == true) //if boolean of studentsWon is true then output that Students Won
    {
      outFile << "Students won!";
    }
  else //else output that Parking won
    {
      outFile << "Parking won!";
    }
  outFile << endl;

  ++numOfDay; 

  if(numOfDay == (arraySize - 1))
    {
      outFile.close(); //close file
    }
}

