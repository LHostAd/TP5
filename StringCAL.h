
#ifndef StringCAL_H__
#define StringCAL_H__

#include <string.h>
#include <cstdlib>

using std::size_t;

class StringCAL {
 public :
 
// =========================== Static attributes =======================
   
  static const size_t MAX_SIZE_;

// =========================== Constructors ============================
  
  StringCAL();
  StringCAL(const char*);
  StringCAL(const StringCAL &);
  StringCAL(size_t);

//============================ Destructor ==============================
  
  ~StringCAL();
  
// =========================== Getters =================================
  
  inline size_t size() const; 
  inline size_t length() const;
  inline size_t max_size() const;
  inline size_t capacity() const;
  
//============================ Operators ===============================
  
  void operator=(const StringCAL&);
  void operator=(const char*);
  void operator=(const char&);
  char& operator[](int i);
  const char& operator[](int) const;
   
//============================ Public Methods ==========================

  void resize(size_t);
  bool empty() const;
  void reserve(size_t);
  const char* c_str() const;
  void clear();

//============================ Friend functions=========================
 
 
  /* We consider these functions as friends so that we can have access 
   * to the parameters of the considered objects.
   * Indeed, instead of using a double "if" loop, we decided to use 
   * memcopy that requires the access to protected attributes.*/ 
  friend StringCAL operator+(const StringCAL&, const char);
  friend StringCAL operator+(const StringCAL&, const StringCAL&);
  friend StringCAL operator+(const StringCAL&, const char*);
  
 protected :
  
//============================ Attributes ==============================
  
  char* ptr_; // A table of char, containing the used chars, followed by
              //some '\0' if the capacity is
              // greater than the size. In every case : the table is 
              //ended by one '\0'.
  size_t size_; // The number of visible characters by the users
  size_t capacity_; // The maximum amount of character that the string 
                    //can carry ( capacity_ >= size_ )
  
  

};

//=========================== Getters' definition=======================
 
inline size_t StringCAL::size() const { return size_; }
inline size_t StringCAL::length() const { return size_; }
inline size_t StringCAL::max_size() const { return MAX_SIZE_; }
inline size_t StringCAL::capacity() const { return capacity_; }


#endif // StringCAL_H__
