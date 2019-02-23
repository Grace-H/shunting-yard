//Binary Node class (BiNode)
//class contains left/right pointers to other BiNodes, data values of type char*
//Author: Grace Hunter
//Date: 07 February 2019

#include <iostream>
#include <cstring>
#include "BiNode.h"

using namespace std;

//Constructor
BiNode::BiNode(BiNode* newLeft, BiNode* newRight, char* newData){
  left = newLeft;
  right = newRight;
  data = newData;
}

//constructor
BiNode::BiNode(char* newData){
  data = newData;
  left = NULL;
  right = NULL;
}

//destructor
BiNode::~BiNode(){
  delete left;
  delete right;
  delete data;
}

//get left node pointer
BiNode* BiNode::getLeft(){
  return left;
}

//get right pointer
BiNode* BiNode::getRight(){
  return right;
}

//set left pointer, should return 0
int BiNode::setLeft(BiNode* newleft){
  left = newleft;
  return 0;
}

//set right pointer, should return 0
int BiNode::setRight(BiNode* newright){
  right = newright;
  return 0;
}

//get data value held by BiNode
char* BiNode::getData(){
  return data;
}
