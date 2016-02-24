#include <cstdio>
#include <cstdlib>
#include "StringCAL.h"
#include <iostream>

using std::cout;

int main(int argc, char* argv[]) {
  
// test constructeur par défaut
  StringCAL* ptrA = new StringCAL();
  int a = ptrA->size();
  cout << a << endl;
  printf("Contenu de ptrA: %s \n", ptrA->chaine() );
  delete ptrA;

// test constructeur from c_string
  const char* texte1 = "You lost the game !";
  StringCAL* ptrB = new StringCAL(texte1);
  a = ptrB->length();
  cout << a << endl;
  printf("Contenu de ptrB: %s \n", ptrB->chaine() );
  ptrB->resize(20);
  printf("Contenu de ptrB: %s \n", ptrB->chaine() );
  cout << "\nMAX_SIZE: " << ptrB->max_size() << endl;
  delete ptrB;


  
  return 0;
}
