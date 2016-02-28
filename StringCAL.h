
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
  StringCAL(size_t capacity);

  //============================ Destructor ============================
  ~StringCAL();
  // =========================== Getters ===============================
  
  inline size_t size()const; 
  inline size_t length()const;
  inline size_t capacity() const;
  
  //============================ Setters ===============================

  //============================ Operators =============================
  
  StringCAL & operator=(const StringCAL& );
  char& operator [] (int i);
  const char& operator [] (int i) const;
   
  //============================ Public Methods ========================
  bool empty() const;
  void reserve(size_t n);
  
  const char* c_str() const;
  void clear();

 protected :
  //============================ Protected Methods =====================
  
  //============================ Attributes ============================
  
  char* ptr_; // tableau de caracteres de taille (capacity_ + 1), il contient les lettres de la chaine, suivies de "\0"
  size_t size_; // nombre de caracteres dans la chaine
  size_t capacity_; // nombre de caractere que peut recevoir la chaine
  
};




//=========================== Getters' definitions =======================

inline size_t StringCAL::size() const{
  return size_;
}

inline size_t StringCAL::length() const{
  return size_;
}

inline size_t StringCAL::capacity() const{
  return capacity_;
}
//=========================== Setters' definitions =======================

//=========================== Operators' definitions =====================

StringCAL operator+(const StringCAL &lhs, const char rhs);

//======================== Inline functions' definition ==================



#endif // StringCAL_H__
