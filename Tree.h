#include <iostream>
#include <cstring>
#include "BiNode.h"

using namespace std;

#ifndef TREE_H
#define TREE_H

struct treenode{
  BiNode* data;
  treenode* next;
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
  treenode* head;         //header node of stack
};

#endif
