#include <iostream>
#include <ctring>

struct node{
  char* data;
  node* next;
};
  
class Stack{
 public:
  Stack();
  ~Stack();
  int push(int data);
  int pop();
  int peek();
  int isempty();
  int isfull();
 private:
  node* head;
};
