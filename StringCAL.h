
#ifndef StringCAL_H__
#define StringCAL_H__


#include <cstdio>
#include <cstdlib>

using std::size_t;
using namespace std;

class StringCAL {
 public :
 
  // =========================== Static attributes =====================
   
  static const size_t MAX_SIZE_;
 
 
  // =========================== Constructors ==========================
  
  StringCAL();
  StringCAL(const char* model);
  StringCAL(const StringCAL &);

  //============================ Destructor ============================
  ~StringCAL();
  // =========================== Getters ===============================
  
  inline size_t size()const; 
  inline size_t length()const;
  inline size_t max_size() const;
  
  //============================ Setters ===============================

  //============================ Operators =============================

  //============================ Public Methods ========================
  

protected :
  //============================ Protected Methods =====================
  
  //============================ Attributes ============================
  
  char* ptr_; // tableau de caractères de taille (capacity_ + 1), il contient les lettres de la chaîne, suivies de "\0"
  size_t size_; // nombre de caractères dans la chaîne
  size_t capacity_; // nombre de caractère que peut recevoir la chaîne
  
};




//=========================== Getters' definitions =======================

inline size_t StringCAL::size() const{
  return size_;
}

inline size_t StringCAL::length() const{
  return size_;
}

inline size_t StringCAL::max_size() const{
  return MAX_SIZE_;
}

//=========================== Setters' definitions =======================

//=========================== Operators' definitions =====================

//======================== Inline functions' definition ==================



#endif // StringCAL_H__
