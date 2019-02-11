//Binary Node class
//contains left and right pointers to other BiNodes
//holds data value of type char
//Author: Grace Hunter
//Date: 07 February 2019

#include <iostream>
#include <cstring>

using namespace std;

#ifndef BINODE_H
#define BINODE_H

class BiNode {
 public:
  BiNode(BiNode* newLeft, BiNode* newRight, char* newData);
  ~BiNode();
  BiNode* getLeft();
  BiNode* getRight();
  char* getData();
 private:
  char* data;
  BiNode* left;
  BiNode* right;
};

#endif
