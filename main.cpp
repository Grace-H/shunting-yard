#include <iostream>
#include <cstring>
#include "Stack.h"

using namespace std;

int main(){
  Stack stack;
  char* input = new char[20];
  cin.get(input, 20);
  stack.push(input[1]);
  stack.push(input[2]);
  stack.push(input[3]);
  stack.push(input[4]);
  cout << stack.peek() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.isempty() << endl;
  cout << stack.isfull() << endl;
  return 0;
}
