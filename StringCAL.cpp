//=========================== Includes =================================

#include "StringCAL.h"

//================= Definition of static attributes ====================

const size_t StringCAL::MAX_SIZE_ = 100;

//=========================== Constructors =============================

StringCAL::StringCAL() {
  /* empty string constructor = default constructor */
  ptr_ = new char[1];
  ptr_[0] = '\0';
  size_ = 0;
  capacity_ = 0;
}

StringCAL::StringCAL(const char* model) {
  /* constructor from c-string pointed by model */ 
  size_t i = 0;
  while (model[i] != '\0') {
    i++;
  }
  size_ = i;
  capacity_ = i;
  ptr_ = new char[i+1];
  memcpy(ptr_, model, 1+size_);
}

StringCAL::StringCAL(const StringCAL & copied){
  /* copy constructor */
  size_ = copied.size_;
  capacity_ = copied.capacity_;
  ptr_ = new char[capacity_ + 1];
  memcpy(ptr_, copied.ptr_, 1+size_);
}

StringCAL::StringCAL(size_t capacity) {
  /* Needed for the operator +(char), creates a StringCAL of 0's with 
   * the given capacity */
  size_ = 0;
  capacity_ = capacity;
  ptr_ = new char[capacity_ + 1];
  for (unsigned int i = 0; i < capacity_ + 1; i++) {
    ptr_[i] = '\0';
  }
}

//=========================== Destructor ===============================

StringCAL::~StringCAL() {
  /* Since ptr_ is manually alocated in the constructors, we need to 
   * manually delete it */
  delete[] ptr_;
  ptr_ = nullptr;
}

//============================ Operators ===============================
  
  
void StringCAL::operator=(const StringCAL& str){
  /* replaces the current content of the string by a new string */
  size_ = str.size_;
  capacity_ = str.capacity_;
  ptr_ = new char[capacity_ + 1];
  memcpy(ptr_, str.ptr_, 1 + capacity_);
}

void StringCAL::operator=(const char& model){
  /* replaces the current content of the string by a single character*/
  size_ = 1;
  capacity_ = 1;
  char* newptr_ = new char[2];
  newptr_[0] = model;
  newptr_[1] = '\0';
  delete[] ptr_;
  ptr_ = newptr_;
}

void StringCAL::operator=(const char* rhs){
  /* replaces the current content of the string by a single character 
   * pointed by rhs */ 
  size_t i = 0;
  while (rhs[i] != '\0') {
    i++; 
  }
  size_ = i;
  capacity_ = i;
  delete[] ptr_;
  ptr_ = new char[i + 1];
  memcpy(ptr_, rhs, i);
}


//Both useful and needed for the operator +(char).
char& StringCAL::operator[](int i) {
  /* returns the character located at position i in the string */ 
  return ptr_[i]; 
}

const char& StringCAL::operator[](int i) const {
  /* constant operator :returns the character located at position i in 
   * the string */ 
  return ptr_[i]; 
}

//=========================== Public Methods ===========================

void StringCAL::resize(size_t len){
  /* changes the size of the current string, and adapt the capacity : 
   * Fills the string with 0's if size_ is increased, and crops it 
   * otherwise*/
  capacity_ = len;
  char* newptr_ = new char[capacity_ + 1];
  newptr_[capacity_] = '\0';
  memcpy(newptr_, ptr_, capacity_);
  for (unsigned int i = size_; i < capacity_; i++) {
    newptr_[i] = '\0'; 
  }
  delete[] ptr_;
  ptr_ = newptr_;
  if (size_ > capacity_) size_ = capacity_;
}

bool StringCAL::empty() const{
  /* returns True if size_ = 0, returns False otherwise */ 
  return (size_ == 0);
}

void StringCAL::reserve(size_t n){
  /* changes capacity_ and adapt size_.
   * If n is lower than size_, the string is cropped. */ 
  capacity_ = n; // redefinition of the capacity_
  if(n < size_) {
    size_ = n;
  }
  char* temp_ptr = new char[n + 1]; // temp_ptr is used to keep the 
                                    // values of ptr_ before we free its 
                                    // memory
  temp_ptr[n] = '\0';
  memcpy(temp_ptr, ptr_, size_);
  delete[] ptr_;
  ptr_ = temp_ptr;
}

const char* StringCAL :: c_str() const {
  /* returns the table of characters pointed by ptr_ */ 
  return ptr_; 
}

void StringCAL :: clear(){
  /* Deletes each character of the string, and it therefore becomes an
   * empty string, with a size_ = capacity_ = 0 */ 
  delete[] ptr_;
  ptr_ = new char[1];
  ptr_[0] = '\0';
  size_ = 0;
  capacity_ = 0;
}

//===========================Friend Functions ==========================



StringCAL operator+(const StringCAL &lhs, const char c) {
  /* Creates a new StringCAL from the concatenation of a StringCAL (lhs)
   * and a char (c) */ 
  StringCAL str(lhs.size() + 2);
  memcpy ( str.ptr_, lhs.c_str(), lhs.size() );
  str[lhs.size()] = c;
  return (str);
}

StringCAL operator+(const StringCAL &lhs, const StringCAL& rhs) {
  /* Creates a new StringCAL from the concatenation of two StringCAL 
   * objects (lhs & rhs) */ 
  StringCAL str(lhs.size() + rhs.size() + 1);
  memcpy(str.ptr_, lhs.ptr_, lhs.size());
  memcpy(&(str.ptr_[lhs.size()]), rhs.ptr_, rhs.size());
  return (str);
}

StringCAL operator+(const StringCAL &lhs, const char* c) {
  /* Creates a new StringCAL from the concatenation of a StringCAL (lhs)
   *  and a character pointed by c*/
  size_t size_of_c = 0;
  size_t size_of_lhs = lhs.size();
  while (c[size_of_c]!=0) {
    size_of_c++;
  }
  size_t size = size_of_lhs + size_of_c;
  char* ptr = new char[size + 1];
  ptr[size] = '\0';
  memcpy(ptr, lhs.ptr_, size_of_lhs);
  memcpy(&(ptr[size_of_lhs]), c, size_of_c);
  StringCAL str (ptr);
  delete[] ptr;
  return str;
}
