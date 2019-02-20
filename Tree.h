#include <iostream>
#include <cstring>
#include "BiNode.h"

using namespace std;

#ifndef STACK_H
#define STACK_H

struct node{
  BiNode* data;
  node* next;
};

class Tree{
 public:
  Tree();             //constructor
  ~Tree();            //destructor
  int push(BiNode* data);  //push value to stack
  BiNode* pop();           //pop value from stack
  BiNode* peek();          //peek at top value
  int isempty();       //check if stack is empty
  int isfull();        //check if stack is full
 private:
  node* head;         //header node of stack
};

#endif
