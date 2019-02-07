//Binary Node class (BiNode)
//class contains left/right pointers to other BiNodes, data values of type char
//Author: Grace Hunter
//Date: 07 February 2019

#include <iostream>
#include <cstring>
#include "BiNode.h"

using namespace std;

BiNode::BiNode(BiNode* newLeft, BiNode* newRight, char newData){
  left = newLeft;
  right = newRight;
  data = newData;
}

BiNode::~BiNode(){
  delete left;
  delete right;
}

BiNode* BiNode::getLeft(){
  return left;
}

BiNode* BiNode::getRight(){
  return right;
}

char BiNode::getData(){
  return data;
}
