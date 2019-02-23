//Class Tree
//uses node struct and linked list to manage stack of BiNode
//Author: Grace Hunter
//Date: 22 Febraury

#include <iostream>
#include <cstring>
#include "Tree.h"

using namespace std;

//CONSTRUCTOR
//initialize head to NULL
Tree::Tree(){
  head = NULL;
}

//DESTRUCTOR
Tree::~Tree(){
  while(head != NULL){
    treenode* currenthead = head;
    head = head->next;
    delete currenthead;
  }
}

//add node at top of stack
int Tree::push(BiNode* data){
  treenode* newnode = new treenode;
  newnode->next = head;
  newnode->data = data;
  head = newnode;
  return 0;
}

//remove first node; return value
BiNode* Tree::pop(){
  //  cout << head->data << endl;
  BiNode* data = head->data;
  treenode* currenthead = head;
  head = head->next;
  delete currenthead;
  return data;
}

//return value of top node
//returns NULL if top node NULL
BiNode* Tree::peek(){
  if(head != NULL){
    return head->data;
  }
  else{
    return NULL;
  }
}

//return 0 if stack is empty, else 1
int Tree::isempty(){
  if(head == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

//return 0 if stack is full; else 1
int Tree::isfull(){
  if(head != NULL){
    return 0;
  }
  else{
    return 1;
  }
}


