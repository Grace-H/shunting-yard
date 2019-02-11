//needs to be char*

#include <iostream>
#include <cstring>
#include "Stack.h"

using namespace std;

//CONSTRUCTOR
//initialize head to NULL
Stack::Stack(){
  head = NULL;
}

//DESTRUCTOR
Stack::~Stack(){
  while(head != NULL){
    node* currenthead = head;
    head = head->next;
    delete currenthead;
  }
}

//add node at top of stack
int Stack::push(char* data){
  node* newnode = new node;
  newnode->next = head;
  newnode->data = data;
  head = newnode;
  return 0;
}

//remove first node; return value
char* Stack::pop(){
  char* data = head->data;
  node* currenthead = head;
  head = head->next;
  delete currenthead;
  return data;
}

//return value of top node
//returns NULL if top node NULL
char* Stack::peek(){
  if(head != NULL){
    return head->data;
  }
  else{
    return NULL;
  }
}

//return 0 if stack is empty, else 1
int Stack::isempty(){
  if(head == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

//return 0 if stack is full; else 1
int Stack::isfull(){
  if(head != NULL){
    return 0;
  }
  else{
    return 1;
  }
}


