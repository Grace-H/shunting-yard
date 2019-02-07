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

//converts char array into Stack, top value is first letter
void charToStack(char* in, Stack* stack){
  for(int i = strlen(in) - 1; i >= 0; i--){
    if(is
    stack->push(in[i]);
  }
}

//uses shunting yard algorithm to convert from infix notation to postfix notation using Stacks
void inToPost(Stack* infix, Stack* opers, Stack* postifx){
  while(infix->isfull() == 0){
    char data = infix->pop();
    //is 1234567890
    if(isdigit(data) != 0){
      postfix->push(data);
    }
    //is */
    else if(data == '*' || data == "/"){
      if(
    //is x/

    //is ^

    //is (

    //is )
