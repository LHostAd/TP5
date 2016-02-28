#include <cstdio>
#include <cstdlib>
#include "StringCAL.h"
#include <iostream>

using std::cout;

int main(int argc, char* argv[]) {
  printf("Hello Adèle! \n");

  (void)argc;
  (void)argv;
  
// test constructeur par défaut
  StringCAL* ptrA = new StringCAL();
  int a = ptrA->size();
  cout << a << endl;
  cout << ptrA->empty() << endl;
  delete ptrA;
  ptrA = 0;


// test constructeur from c_string
  const char* texte1 = "You lost the game !";  //longueur = 19
  StringCAL* ptrB = new StringCAL( texte1 );
  a = ptrB->length();
  cout << ptrB << endl << a << endl;
  cout << ptrB->c_str() << endl;
  delete ptrB;
  ptrB = 0;


// test constructeur par copie
  StringCAL S1("This is a test");
  cout << S1.size() << endl;
  StringCAL S2 = S1;
  cout << S2.size() << endl;
  
  
  return 0;
}
