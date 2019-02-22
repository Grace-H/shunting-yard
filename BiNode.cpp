//Binary Node class (BiNode)
//class contains left/right pointers to other BiNodes, data values of type char
//Author: Grace Hunter
//Date: 07 February 2019

#include <iostream>
#include <cstring>
#include "BiNode.h"

using namespace std;

BiNode::BiNode(BiNode* newLeft, BiNode* newRight, char* newData){
  left = newLeft;
  right = newRight;
  data = newData;
}

BiNode::BiNode(char* newData){
  data = newData;
  left = NULL;
  right = NULL;
}

BiNode::~BiNode(){
  delete left;
  delete right;
  delete data;
}

BiNode* BiNode::getLeft(){
  return left;
}

BiNode* BiNode::getRight(){
  return right;
}

int BiNode::setLeft(BiNode* newleft){
  left = newleft;
  return 0;
}

int BiNode::setRight(BiNode* newright){
  right = newright;
  return 0;
}

char* BiNode::getData(){
  return data;
}
