#include <cstdio>
#include <cstdlib>
#include "StringCAL.h"
#include <iostream>

using std::cout;

int main(int argc, char* argv[]) {
  
// test constructeur par défaut
  cout << "============ Test constructeur par défaut:\n";
  StringCAL* ptrA = new StringCAL();
  int a = ptrA->size();
  cout << a << endl;
  printf("Contenu de ptrA: %s \n", ptrA->chaine() );
  delete ptrA;

// test constructeur from c_string
  cout << "\n============ Test constructeur from cstring:\n";
  const char* texte1 = "You lost the game !";
  StringCAL* ptrB = new StringCAL(texte1);
  a = ptrB->length();
  cout << a << endl;
  printf("Contenu de ptrB: %s \n", ptrB->chaine() );
  cout << "\n============ Test redimensionnement:\n";
  ptrB->resize(10);
  a = ptrB->length();
  cout << a << endl;
  printf("Contenu de ptrB: %s \n", ptrB->chaine() );
  cout << "\n============ Test attribut de classe:\n";
  cout << "MAX_SIZE: " << ptrB->max_size() << endl << endl;
  delete ptrB;
  
  
//test opérateur =(char)
  cout << "\n============ Test opérateur =(char):\n";
  StringCAL str3;
  a = str3.size();
  cout << a << endl;
  printf("Contenu de str3 (défaut): %s \n", str3.chaine() );
  char texte2 = '#';
  str3 = texte2;
  a = str3.size();
  cout << a << endl;
  printf("Contenu de str3 (caractère dièse): %s \n", str3.chaine() );
  
  return 0;
}
