//Trisha Andres                                                               
//CPSC 1071: Section 2                                                        
//Group 6: C--
//02/12/2023

#include <iostream>
#include <cmath>
#include <iomanip>

//namespace for std
using namespace std;

//headers
//runs menu, takes in user's menu choice and goes to next function/quits/reprompts
void runMenuSystem();
//prompts user to put in info, validates info, calls estimateEarnings()
void estimateDriver();
//takes in user info from estimateDriver() and calculates amount estimated at retirement and stats
double estimateEarnings(int, int, int, double, double, double);
//prompts user to put in info, validates it, calls paymentMonths()
void paymentDriver();
//uses user info from above to calculate number of months needed to pay off a loan and stats
int paymentMonths(double, double, double);

//main: calls runMenuSystem to run menu and returns 0 (int)
int main(void) {

  runMenuSystem();

  return 0;
}

//function to run menu and call other functions based on user menu choice
void runMenuSystem() {
  //intro and menu with description of choices
  cout<< "******* Welcome to Clementine Financial *******" << endl << endl;
  cout<< "Menu: \n";
  cout<< "\t[E] Estimate how much money at retirement\n";
  cout<< "\t[L] Loan payoff calculator\n";
  cout<< "\t[Q] Quit program\n\n";

  
  char menuChoice;
  cout<< " Enter your choice and press enter: ";
  cin>> menuChoice;

  //take in user menu choice and go through switch statement to go to next function/quit/reprompt
    switch(menuChoice) {
    case 'E':
      //go to estimate earnings function
      estimateDriver();
      break;
    case 'e':
      //go to estimate earning function
      estimateDriver();
      break;
    case 'L':
      //payoff calculator created from last lab
      paymentDriver();
      break;
    case 'l':
      //payoff calc created from last lab
      paymentDriver();
      break;
    case 'Q':
      //quit running
      break;
    case 'q':
      //quit running
      break;
    default:
      //reprompt and run menu function again
      cout<< endl <<"The provided choice was invalid! Please select again." << endl << endl;
      runMenuSystem();
      break;
    }
}

void estimateDriver(){
  //declare and intialize variables needed
  int firstAge = 0;
  int secondAge = 0;
  int retirementAge = 0;
  double currSavings = 0.0;
  double monthlyPay = 0.0;
  double annualReturnPercentage = 0.0;

  //prompts to get user info and validating user info (reprompting)
  cout<< "Estimate Savings at Retirement" << endl;
  cout<< "Disclaimer: This is only a rough estimate!" << endl << endl;

  cout<< "\tEnter the first starting age in years: ";
  cin>> firstAge;
  if(firstAge <= 0)
    {
    cout<< "\tAge cannot be 0 or less." << endl;
    cout<< "\tRe-enter your age in years: ";
    cin>> firstAge;    
    }
  
  cout<< "\tEnter the second starting age in years: ";
  cin>> secondAge;
  if(secondAge <= 0)
    {
      cout<< "\tAge cannot be 0 or less." << endl;
      cout<< "\tRe-enter your age in years: ";
      cin>> secondAge;
    }
  
  cout<< "\tEnter your target retirement age: ";
  cin>> retirementAge;
  if((retirementAge <= firstAge) || (retirementAge <= secondAge))
    {
      cout<< "\tYour target age cannot be less than or equal your current age." << endl;
      cout<< "\tRe-enter your target age in years: ";
      cin>> retirementAge;
    }
  
  cout<< "\tHow much have you saved already towards retirement?: $";
  cin>> currSavings;
  if(currSavings < 0)
    {
      cout<< "\tYour savings cannot be negative." << endl;
      cout<< "\tRe-enter your savings: $";
      cin>> currSavings;
    }
  
  cout<< "\tEnter your monthly contribution to retirement: $";
  cin>> monthlyPay;
  if(monthlyPay <= 0)
    {
      cout<< "\tYour monthly contribution cannot be less than or equal to zero." << endl;
      cout<< "\tRe-enter your monthly contribution: $";
      cin>> monthlyPay;
    }
  
  cout<< "\tEnter the estimated annual return on investment (in percent): ";
  cin>> annualReturnPercentage;
  if (annualReturnPercentage < 0)
    {
      cout<< "\tYour rate cannot be less than zero." << endl;
      cout<< "\tRe-enter your rate (in percent): ";
      cin>> annualReturnPercentage;
    }
  cout<< ".\n" << ".\n" << "...calculating\n";

  //call estimate earnings function
  estimateEarnings(firstAge, secondAge, retirementAge, currSavings, monthlyPay, annualReturnPercentage);
}

double estimateEarnings(int firstAge, int secondAge, int retirementAge, double currSavings, double monthlyPay, double annualReturnPercentage){

  //outputs info for retirement savings with first age given
  cout<< "For starting to save at retirement at age " << firstAge << ":"<< endl << endl;

  //calculations using first age, variables needed 
  double firstSavings = 0.0;
  double firstGrowth = 0.0;  
  
  int yearDiff = retirementAge - firstAge;
  int numMonths = yearDiff * 12;
  double rate = annualReturnPercentage / 1200;
  double startingBalance = currSavings;
  double tempBalance = 0.0;
  
  for(int i = 0; i <= numMonths - 1; i++) {
    firstGrowth += startingBalance * rate;
    double temp = (startingBalance * rate) + (startingBalance + monthlyPay);
    firstSavings = temp;    
    startingBalance = temp;
  }
  
  cout<< fixed << setprecision(2);
  cout<< "Estimated Retirement Savings: $" << firstSavings << endl;
  cout<< "Estimated Retirement Growth: $" << firstGrowth << endl << endl;

  //start outputting info for retirement with second age given
  cout<< "For starting to save at retirement at age " << secondAge << ":" << endl << endl;

  //calculations using second age
  double secondSavings = 0.0;
  double secondGrowth = 0.0;

  int years = retirementAge - secondAge;
  int months = years * 12;
  double startingBalanceTwo = currSavings;

  for(int i = 0; i <= months - 1; i++) {
    secondGrowth += startingBalanceTwo * rate;
    double tempVal = (startingBalanceTwo * rate) + (startingBalanceTwo + monthlyPay);
    secondSavings = tempVal;
    startingBalanceTwo = tempVal;
  }
  
  cout<< "Estimated Retirement Savings: $" << secondSavings << endl;
  cout<< "Estimated Retirement Growth: $" << secondGrowth << endl;

  //statistics and calculations
  double potential = 0.0;
  potential = abs(firstSavings - secondSavings);
  int difference = abs(secondAge - firstAge);
  cout<< endl << endl << endl << "For a difference in waiting "<< difference << " years before starting to invest in \nretirement, you can miss out potentially on $" << potential << endl;

  //take in if user wants to calculate another estimate
  char yesOrNo;
  cout<< "Calculate another estimate? (y/n): ";
  cin>> yesOrNo;
  cout<< endl;

  //switch statement for what happens next, validating input
  switch(yesOrNo) {
  case 'N':
    runMenuSystem();
    break;
  case 'n':
    runMenuSystem();
    break;
  case 'Y':
    estimateDriver();
    break;
  case 'y':
    estimateDriver();
    break;
  default:
    cout<< "Please enter a valid answer (y/n): ";
    cin>> yesOrNo;
    cout<< endl;
  }
  //return calculated retirement savings using first age
  return firstSavings;
}

void paymentDriver() {
  cout<< "Loan Payment Calculator" << endl;
  cout<< endl;

  //declare and initialize variables
  double principal = 0.0;
  double rate = 0.0;
  double payMonthly = 0.0;

  //obtaining user info for principal amount, rate, and monthly payment
  cout<< "Enter the principal amount: $";
  cin>> principal;
  
  cout<< "Enter the annual interest rate (in percent): ";
  cin>> rate;
  
  cout<< "Enter the monthly payment: $";
  cin>> payMonthly;
  
  cout<< endl<< "Calculating..." << endl << endl;

  //call function to calculate loan payment
  paymentMonths(principal, rate, payMonthly);
}

int paymentMonths(double principal, double rate, double payMonthly) {
  double numMonths;
  double years;

  //calculations
  numMonths = (log(payMonthly) - log(payMonthly - ((rate / 1200) * principal))) / (log((rate / 1200) + 1));
  numMonths = round(numMonths);

  //get years
  years = numMonths / 12;

  //output info
  cout<< numMonths << " months (" << setprecision(2) << years << " years) are needed to pay your loan off." << endl << endl;
  
  double newNumMonths;

  //calculations for stat
  double newMonthly = payMonthly + 15;
  newNumMonths = (log(newMonthly) - log(newMonthly - ((rate / 1200) * principal))) / (log((rate / 1200) + 1));
  newNumMonths = round(newNumMonths);
  
  newNumMonths = numMonths - newNumMonths;

  //stat output
  cout<< "Did you know if you paid an additional $15 per month, you would pay off \nyour loan " << newNumMonths << " months earlier?";
  cout<< endl<< endl;

  //what to do next
  char answer;
  cout<< "Calculate another loan payoff? (y/n): ";
  cin>> answer;
  cout<< endl;

  //lead to what next based on answer; validate answer (reprompt)
  switch(answer) {
  case 'N':
    runMenuSystem();
    break;
  case 'n':
    runMenuSystem();
    break;
  case 'Y':
    paymentDriver();
    break;
  case 'y':
    paymentDriver();
    break;
  default:
    cout<< "Please enter a valid answer (y/n): ";
    cin>> answer;
    cout<< endl;
  }
  //set number, make int, return number of months needed to pay loan off
  cout<< fixed<< setprecision(2);
  numMonths = (int)numMonths * 1;
  return numMonths;
}
