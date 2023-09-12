/*Trisha Andres                                                            
CPSC 1070: Section 2                                                        
04/9/23                                                                      
B6: C--*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Queue {
  struct qNode {
    int num;
    qNode *next;
    qNode(int val, qNode *nextPtr = nullptr)
    {
      num = val;
      next = nextPtr;
    }
  };

  int qSize = 0;
  const int MAX_CONST = 100;

  qNode *frontPtr;
  qNode *endPtr;

  
public:
  Queue();
  ~Queue();

  void enqueue(int); //enqueue function for encoding/decoding message
  void dequeue(int &); //dequeue function used fro encoding/decoding message
  bool isEmpty() const; //sees if queue is empty
  bool isFull() const;// sees if queue is full
  void clear(); //clears data
};
#endif 
