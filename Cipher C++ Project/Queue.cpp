/*Trisha Andres                                                         
CPSC 1070: Section 2                                                        
04/9/23                                                                     
B6: C--*/
#include <iostream>
#include <cstdlib>

#include "Cipher.h"
#include "Queue.h"

using namespace std;

const int MAX_CONST = 100;

Queue::Queue() { //default constructor 
  frontPtr = nullptr;
  endPtr = nullptr;
}

Queue::~Queue() { //destructor 
  qNode *meh = frontPtr;

  while (meh != nullptr)
    {
      frontPtr = frontPtr->next;
      meh->next = nullptr;
      delete meh;
      meh = frontPtr;
    }
}

void Queue::enqueue(int val) {

  if (!isFull()) //if it is not full
    {
      if (isEmpty()) //if it is empty
	{
	  frontPtr = new qNode(val); //front goes to node at vall
	  endPtr = frontPtr;// end is now frontptr
	}
      else //if it is not empty
	{
	  endPtr->next = new qNode(val);//end to next val is new node 
	  endPtr = endPtr->next; //end to next
	}
      this->qSize++; //use this to increment size of queue
    }
}

void Queue::dequeue(int &val) {
  qNode *temp = nullptr;

  if (isEmpty()) //if queue is empty
    {
      cout<< "Queue empty\n"; //output that it is empty
    }
  else //else (not empty)
    {
      val = frontPtr->num; //go through and dequeue (using temp)
      temp = frontPtr;
      frontPtr = frontPtr->next;
      delete temp;
    }
  this->qSize--; //decrement
}

bool Queue::isEmpty() const {
  if (frontPtr == nullptr) //checks if the queue is empty or not
    {
      return true; //true if empty (front points to nullptr)
    }
  else
    {
      return false; //false if not empty
    }
}


bool Queue::isFull() const {
  if (qSize == MAX_CONST) //if the size of the queue is at the max
    {
      return true; //return true cause it is full
    }
  else //not at max size
    {
      return false; //false cause it is not full
    }
}

void Queue::clear() {
  int number;

  while (!isEmpty()) //while the queue is not empty
    {
      dequeue(number); //dequeue
    }
}

  
