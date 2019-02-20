//everything needs to be char*
//need to change stack and binode

#include <iostream>
#include <cstring>
#include <cctype>
#include "Stack.h"
#include "BiNode.h"
#include "Tree.h"

using namespace std;

void makeTree(Tree* tree, Stack* in);
void charToStack(char* in, Stack* stack);
void flipStack(Stack* in, Stack* out);
void inToPost(Stack* input, Stack* opers, Stack* postfix);
int isHigher(char* oper1, char* oper2);

int main(){
  //stacks for shunting yard
  Stack* stack1 = new Stack();
  Stack* stack2 = new Stack();
  Stack* opers = new Stack();

  //read in equation
  char* in = new char[256];
  cin.get(in, 256);
  cin.get();

  charToStack(in, stack1);
  flipStack(stack1, stack2);
  //  cout << "3: " << stack2->peek() << endl;
  //while(stack2->isfull() == 0){
  //cout << "oper: " << stack2->peek() << endl;
  //stack2->pop();
  //}

  inToPost(stack2, opers, stack1);
  cout << "Made it!" << endl;

  flipStack(stack1, stack2);

  //make tree
  Tree* tree = new Tree();
  makeTree(tree, stack2); 
  
  while(stack2->isfull() == 0){
    cout << stack2->peek() << endl;
    stack2->pop();
  }

  return 0;
}

void makeTree(Tree* tree, Stack* in){
}

    //make sure stacks are empty
void flipStack(Stack* in, Stack* out){
  while(in->isempty() != 0){
    out->push(in->peek());
    in->pop();
  }
}

//converts char array into Stack, top value is first word
void charToStack(char* in, Stack* stack){
  char* str;
  str = strtok(in, " ");
  while(str != NULL){
    //cout << "str: " << str << endl;
    stack->push(str);
    str = strtok(NULL, " ");
  }
}

//uses shunting yard algorithm to convert from infix notation to postfix notation using Stacks
void inToPost(Stack* infix, Stack* opers, Stack* postfix){
  while(infix->isfull() == 0){
    char* cur = infix->pop();
    //cout << "cur: " << cur << endl;
    //is +-*/^
    if(strcmp(cur, "*") == 0 || strcmp(cur, "/") == 0 || strcmp(cur, "+") == 0 || strcmp(cur, "-") == 0 || strcmp(cur, "^") == 0){
      if(opers->isfull() == 0){
	//if oper is higher precedence
	if(isHigher(cur, opers->peek()) == 3){
	  opers->push(cur);
	}
	//if oper is lower or equal precedence
	else{
	  while(isHigher(cur, opers->peek()) != 3 && opers->isfull() == 0){
	    //  cout << "cur: " << cur << " oper: " << opers->peek() << endl;
	    postfix->push(opers->peek());
	    opers->pop();
	  }
	  opers->push(cur);
	}
      }
      else{
	opers->push(cur);
      }
    }
    //is (
    else if(strcmp(cur, "(") == 0){
      opers->push(cur);
      //cout << opers->isempty() << endl;
    }
    //is (
    else if(strcmp(cur, ")") == 0){
      //cout << "It's a )" << endl;
      while(strcmp(opers->peek(), "(") != 0){
	
	postfix->push(opers->peek());
	//cout << "oper on top: " << opers->peek() << endl;
	opers->pop();
	//cout << "yay" << endl;
	//cout << opers->isempty() << endl;
	//cout << "new top: " << opers->peek() << endl;
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
//returns 3 if greater or parentheses
int isHigher(char* oper1, char* oper2){
  if(oper2 == NULL || strcmp(oper2, "(") == 0 || strcmp(oper2, ")") == 0){
    return 3;
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

