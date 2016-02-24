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
  ptrB->resize(10);
  printf("Contenu de ptrB: %s \n", ptrB->chaine() );
  a = ptrB->length();
  cout << a << endl;
  cout << "\nMAX_SIZE: " << ptrB->max_size() << endl << endl;
  delete ptrB;
  
  
//test opérateur =(char)
  StringCAL str3;
  a = str3.size();
  cout << a << endl;
  printf("Contenu de str3: %s \n", str3.chaine() );
  char texte2 = '#';
  str3 = texte2;
  a = str3.size();
  cout << a << endl;
  printf("Contenu de str3: %s \n", str3.chaine() );
  
  return 0;
}
