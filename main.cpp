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
  cout << ptrA << endl << a << endl;
  delete ptrA;

// test constructeur from c_string
  const char* texte1 = "You lost the game !";  //longueur = 19
  
  StringCAL* ptrB = new StringCAL( texte1 );
  a = ptrB->length();
  cout << ptrB << endl << a << endl;
  delete ptrB;


  
  return 0;
}
