//Trisha Andres                                                                                               
//CPSC 1070: Section 2                                                                                        
//Group B6: C --                    
//03/01/2023

#ifndef DATE_H
#define DATE_H

#include <iostream> //needed for functions standard input/output

using namespace std;

class Date {
public:
  Date();
  Date(int, int, int);
  
  Date operator+(int days);
  Date operator-(int days);
  Date operator++(void);
  Date operator++(int);
  Date operator--(void);
  Date operator--(int);

  string getDayOfWeek();
  
  int getMonth();
  int getDay();
  int getYear();
  
  void setMonth(int);
  void setDay(int);
  void setYear(int);
  
  const static int daysInMonths[];
  
private:
  int month;
  int day;
  int year;  
};
#endif
