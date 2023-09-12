//Trisha Andres                                                              
//CPSC 1070: Section 2                                                       
//Group B6: C --                                                        
//03/01/2023  

//include header files needed
#include "Date.h"
#include "MysteryMachine.h"

using namespace std;


//constant to hold values of the number of days in each month
const int Date::daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


//default constructor (set to given default)	  
Date::Date():Date(1,1,2000){}


//overloaded constructor (changed variable names just to keep track better)
Date::Date(int inputMonth, int inputDay, int inputYear){
  month = inputMonth;
  day = inputDay;
  year = inputYear;
}


//getter for month
int Date::getMonth(){
  return month;
}


//getter for day
int Date::getDay(){
  return day;
}


//getter for year
int Date::getYear(){
  return year;
}


//setter for month
void Date::setMonth(int inputMonth){
  month = inputMonth;
}


//setter for day 
void Date::setDay(int inputDay){
  day = inputDay;
}


//setter for year
void Date::setYear(int inputYear){
  year = inputYear;
}


//returns string given object 
string Date::getDayOfWeek(){

  //create an object for mystery machine class
  MysteryMachine objMystMach;

  //call on function to get day of week from mystery machine
  //return this value (string)
  return objMystMach.getDayOfWeek(*this);;
}


//uses below functions when called by decrementing (for loop)
Date Date::operator-(int days) {
  
  for(int i = 0; i < days; ++i)
    {
      --(*this);
    }
  
  return *this;

}


//uses below functions when called by incrementing (for loop)
Date Date::operator+(int days) {

  for (int j = 0; j < days; ++j)
    {
      ++(*this);
    }

  return *this;

}


//increment days, makes sure day is a weekday, increment month and year depending on requirements, prefix increment, returns object with +1 day
Date Date::operator++(void){

  do
    {
      day += 1;

      if (day > daysInMonths[month - 1])
	{
	  month += 1;

	  if(month == 13)
	    {
	      setMonth(1);
	      year += 1;
	    }
	  setDay(1);
	}
    } while ((getDayOfWeek() == "Saturday") || (getDayOfWeek() == "Sunday"));
  
      
  return *this;   
}


//use prefix increment operator, returns object before incrementes, postfix decrement operator
Date Date::operator++(int) {
  Date temp = *this;

  ++(*this);

  return temp;
}


//decrement days, makes sure day is a weekday, decrement month and year depending on requirements, returns objext -1 day, prefix decrement operator
Date Date::operator--(void){
  
  do
    {
      day -= 1;

      if (day == 0)
	{
	  month -= 1;

	  if (month == 0)
	    {
	      setMonth(12);
	      year -= 1;
	    }
	  
	  setDay(daysInMonths[month - 1]);
	  
	}
    } while ((getDayOfWeek() == "Saturday") || (getDayOfWeek() == "Sunday"));

  return *this;
}


//use postfix decrement operator, return object before decrementes, postfix decrement operator
Date Date::operator--(int){
  Date temp = *this;

  --(*this);

  return temp;
}


