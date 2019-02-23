#include <iostream>
#include <cstring>

using namespace std;

#ifndef STACK_H
#define STACK_H

struct node{
  char* data;
  node* next;
};
  
class Stack{
 public:
  Stack();             //constructor
  ~Stack();            //destructor
  int push(char* data);  //push value to stack
  char* pop();           //pop value from stack
  char* peek();          //peek at top value
  int isempty();       //check if stack is empty
  int isfull();        //check if stack is full
 private:
  node* head;         //header node of stack
};

#endif
