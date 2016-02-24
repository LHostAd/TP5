#include <cstdio>
#include <cstdlib>
#include "StringCAL.h"
#include <iostream>

using std::cout;

int main(int argc, char* argv[]) {
  printf("Hello Adèle! \n");
  
// test constructeur par défaut
  StringCAL* ptrA = new StringCAL();
  int a = ptrA->size();
  cout << a << endl;
  delete ptrA;

// test constructeur from c_string
  const char* texte1 = "You lost the game !";
  cout << texte1[2] << endl;
  StringCAL* ptrB = new StringCAL(texte1);
  a = ptrB->length();
  cout << a << endl;
  cout << "MAX_SIZE: " << ptrB->max_size() << endl;
  delete ptrB;


  
  return 0;
}
