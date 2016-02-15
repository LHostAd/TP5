#include <cstdio>
#include <cstdlib>
#include "StringCAL.h"
#include <iostream>

using std::cout;

int main(int argc, char* argv[]) {
  printf("Hello Adèle! \n");
  
  StringCAL* ptrA = new StringCAL();
  int a = ptrA->size();
  cout << a << endl;
  
  cout << ptrA->empty();
  
  delete ptrA;
  
  StringCAL S1 = StringCAL();
  cout << S1.size() << endl;
  
  StringCAL S2 = StringCAL(S1);
  cout << S1.size() << endl;
  
  
  return 0;
}
