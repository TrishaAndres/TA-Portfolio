/*Trisha Andres                                                                                                                                                                          
CPSC 1071: Section 2                                                                                                                                                                     
Group: C--                                                                                                                                                                               
04/16/2023*/

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int counter = 0;//counter used in both makeList() and printList()

struct node* makeList(void) {
  char readIn[100]; //variable for use inputted words (initialized at 100 just bc i don't think it will get larger than that)
  
  struct node *newNode, *temp;//struct variables

  //do- while loop to obtain all of the users inputs 
  do {
    printf("Enter a word or phrase, or -99 to end: ");
    fgets(readIn, sizeof(readIn), stdin);
    readIn[strcspn(readIn, "\n")] = '\0';//found on c++ website 

    if(strcmp(readIn, "-99") == 0) //just used as a default basically
      {
      }
    else { 
      ++counter;//incrementing counter with every new input  
    
      newNode =  malloc(sizeof(struct node));//get more memory
      newNode->string = malloc((strlen(readIn) + 1) * sizeof(char));//memory allocation
      
      strcpy(newNode->string, readIn);//adding inputted string in to nodes
      newNode->next = NULL;//making last node null
      
      if (head == NULL) 
	{
	  head = newNode;
	  temp = head;
	}
      else
	{
	  temp->next = newNode;
	  temp = newNode;
	}
    }
  } while(strcmp(readIn, "-99") != 0);
  
  return head; 
}

void printList(struct node *tempNode) {
  unsigned int i = 1; //variable used throughout switch statement

  switch(counter) //switch case depending on how many inputs the user has
    {
    case 0: //case for no nodes
      printf("No nodes were entered.");
      break;
    case 1: //case for one node 
      printf("You've entered the following node: ");
      printf("%s", tempNode->string);
      free(head->string);//freeing up memory with free()
      free(head);
      break;
    case 2: //case for two nodes
      printf("You've entered the following nodes: ");

      for (i = 0; i < 2; i++) //for loop for printing out nodes
	{
	  struct node *tempYUH = tempNode;
	  if(i == 1) 
	    {
	      printf(" and ");
	    }
	  printf("%s", tempNode->string);
	  tempNode = tempNode->next;
	  free(tempYUH->string);//freeing up memory 
	  free(tempYUH);	  
	}
      break;
    default: //case for numerous nodes
      printf("You've entered the following nodes: ");
      for(i = 0; i < counter; ++i)//for loop to output all of inputs
	{
	  struct node *tempYUH = tempNode;
	  if(i == (counter - 1)) //last one have a comma and an 'and'
	    {
	      printf(", and ");
	    }
	  else if(i != 0) //comma throughout list of inputs
	    {
	      printf(", ");
	    }
	  printf("%s", tempNode->string);
	  tempNode = tempNode->next;
	  free(tempYUH->string);//freeing up memory 
	  free(tempYUH);
	}
    }
  printf("\n");//new line
}
