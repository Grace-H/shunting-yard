//everything needs to be char*
//need to change stack and binode

#include <iostream>
#include <cstring>
#include <cctype>
#include "Stack.h"
#include "BiNode.h"

using namespace std;

void charToStack(char* in, Stack* stack);
void inToPost(Stack* input, Stack* opers, Stack* output);
bool isHigher(char* oper1, char* oper2);

int main(){
  //stacks for shunting yard
  Stack* input = new Stack();
  Stack* output = new Stack();
  Stack* opers = new Stack();

  //read in equation
  char* in = new char[256];
  cin.get(in, 256);
  cin.get();

  charToStack(in, input);
  cout << input->peek() << endl;
  input->pop();
  cout << input->peek() << endl;
  
  return 0;
}

//converts char array into Stack, top value is first word
void charToStack(char* in, Stack* stack){
  char* str;
  str = strtok(in, " ");
  while(str != NULL){
    stack->push(str);
    str = strtok(NULL, " ");
  }
}

//uses shunting yard algorithm to convert from infix notation to postfix notation using Stacks
void inToPost(Stack* infix, Stack* opers, Stack* postifx){
  while(infix->isempty()){
    char* cur = infix->pop();
    if(strcmp(cur, "(") == 0){
      opers->push(cur);
    }
    else if(strcmp(cur, "*")

//returns true is oper1 is higher precedence that oper2 using Order of Operations
bool isHigher(char* oper1, char* oper2){
  if(strcmp(oper1, oper2) == 0){
    return false;
  }
  else if(strcmp(oper1, "^") == 0){
    return true;
  }
  else if((strcmp(oper1, "*") == 0 || strcmp(oper1, "/") == 0) && (strcmp(oper2, "-") == 0 || strcmp(oper2, "+") == 0)){
    return true;
  }
  else{
    return false;
  }
}

