
#ifndef StringCAL_H__
#define StringCAL_H__


#include <cstdio>
#include <cstdlib>
#include <string.h>

using std::size_t;

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
  inline size_t max_size() const;
  inline size_t capacity() const;

  
  //============================ Setters ===============================

  //============================ Operators =============================
  
  void operator=(const StringCAL& );
  char& operator [] (int i);
  const char& operator [] (int i) const;
   
  //============================ Public Methods ========================
  void resize(int len);
  void operator=(const char& model);
  bool empty() const;
  void reserve(size_t n);
  
  const char* c_str() const;
  void clear();


 protected :
  //============================ Protected Methods =====================
  
  //============================ Attributes ============================
  
  char* ptr_; // A table of char, containing the used chars, followed by some '\0' if the capacity is
              // greater than the size. In every case : the table is ended by one '\0'.
  size_t size_; // The number of visible characters by the users
  size_t capacity_; // The maximum amount of character that the string can carry ( capacity_ >= size_ )
  
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

inline size_t StringCAL::capacity() const{
  return capacity_;
}

//=========================== Setters' definitions =======================

//=========================== Operators' definitions =====================

//======================== Inline functions' definition ==================


//========================  Static operator function definition ==================

StringCAL operator+(const StringCAL &lhs, const char rhs);
StringCAL operator+(const StringCAL &lhs, const char* rhs);

#endif // StringCAL_H__
