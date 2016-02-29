#include <cstdio>
#include <cstdlib>
#include "StringCAL.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {

  
// test constructeur par défaut
  cout << "============ Test constructeur par défaut:\n";
  StringCAL* ptrA = new StringCAL();
  int a = ptrA->size();
  cout << a << endl;
  printf("Contenu de ptrA: %s \n", ptrA->c_str() );
  delete ptrA;

// test constructeur from c_string
  cout << "\n============ Test constructeur from cstring:\n";
  const char* texte1 = "AZERTYUIOPQSDFGHJKLMWXCVBN";
  StringCAL* ptrB = new StringCAL(texte1);
  a = ptrB->length();
  cout << a << endl;
  printf("Contenu de ptrB: %s \n", ptrB->c_str() );
  cout << "\n============ Test redimensionnement:\n";
  ptrB->resize(10);
  a = ptrB->length();
  cout << a << endl;
  printf("Contenu de ptrB: %s \n", ptrB->c_str() );
  cout << "\n============ Test attribut de classe:\n";
  cout << "MAX_SIZE: " << ptrB->max_size() << endl << endl;
  delete ptrB;
    
// test opérateur =(char)
  cout << "\n============ Test opérateur =(char):\n";
  StringCAL str3;
  a = str3.size();
  cout << a << endl;
  printf("Contenu de str3 (défaut): %s \n", str3.c_str() );
  char texte2 = '#';
  str3 = texte2;
  a = str3.size();
  cout << a << endl;
  printf("Contenu de str3 (caractère dièse): %s \n", str3.c_str() );
  

// test constructeur par copie
  cout << "\n============ Test constructeur par copie\n";
  StringCAL S1("This is a test");
  cout << S1.size() << endl;
  StringCAL S2 = S1;
  cout << S2.size() << endl;

  
//test operateur +(char)
  cout << "\n============ Test operateur +(char)\n";
  StringCAL S3 = S1 + '!';
  cout << S3.c_str() << endl;
  
//test operateur +(char*)
  cout << "\n============ Test operateur +(char*)\n";
  StringCAL S4 = S1 + texte1;
  cout << S4.c_str() << endl;
  
  
  return EXIT_SUCCESS;
}
