#include <cstdio>
#include <cstdlib>
#include "StringCAL.h"
#include <iostream>

using std::cout;

int main(int argc, char* argv[]) {
  printf("Hello Adèle! \n");
  
  StringCAL* ptrA = new StringCAL();
  
  int a = ptrA->size();
  
  cout << a;
  
  delete ptrA;
  
  return 0;
}
