//everything needs to be char*
//need to change stack and binode

#include <iostream>
#include <cstring>
#include <cctype>
#include "Stack.h"
#include "BiNode.h"

using namespace std;

void charToStack(char* in, Stack* stack);
void inToPost(Stack* input, Stack* opers, Stack* postfix);
int isHigher(char* oper1, char* oper2);

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
  inToPost(input, opers, output);
  while(output->isfull()){
    cout << output->pop() << endl;
  }
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
void inToPost(Stack* infix, Stack* opers, Stack* postfix){
  while(infix->isfull() == 0){
    char* cur = infix->pop();
    //is +-*/^
    if(strcmp(cur, "*") == 0 || strcmp(cur, "/") == 0 || strcmp(cur, "+") == 0 || strcmp(cur, "-") == 0 || strcmp(cur, "^") == 0){
      if(opers->isfull() == 0){
	if(isHigher(cur, opers->peek()) == 1){
	  opers->push(cur);
	}
	else{
	  while(isHigher(cur, opers->peek()) != 1){
	    postfix->push(opers->pop());
	  }
	  opers->push(cur);
	}
      }
      else{
	opers->push(cur);
      }
    }
    //is )
    else if(strcmp(cur, "(") == 0){
      opers->push(cur);
    }
    //is (
    else if(strcmp(cur, ")") == 0){
      while(strcmp(opers->peek(), "(") != 0){
	postfix->push(opers->pop());
      }
      opers->pop();
    }
    //is a number
    else{
      postfix->push(cur);
    }
  }
  //add remaining operaators to postfix
  while(opers->isfull() == 0){
    postfix->push(opers->pop());
  }
}
	    
//returns 1 if oper1 is lower precedence
//returns 2 if same
//returns 3 if greater
int isHigher(char* oper1, char* oper2){
  if(oper2 == NULL || strcmp(oper2, "(") == 0){
    return 1;
  }
  else if(strcmp(oper1, "^") == 0){
    return 3;
  }
  else if((strcmp(oper1, "*") == 0 || strcmp(oper1, "/") == 0) && (strcmp(oper2, "-") == 0 || strcmp(oper2, "+") == 0)){
    return 3;
  }
  else if((strcmp(oper1, "*") == 0 || strcmp(oper1, "/") == 0) && (strcmp(oper2, "*") == 0 || strcmp(oper2, "/") == 0)){
    return 2;
  }
  else if((strcmp(oper1, "-") == 0 || strcmp(oper1, "+") == 0) && (strcmp(oper2, "-") == 0 || strcmp(oper2, "+") == 0)){
    return 2;
  }
  else{
    return 1;
  }
}

