
//=========================== Includes =================================
#include "StringCAL.h"


//================= Definition of static attributes ====================

const size_t StringCAL::MAX_SIZE_ = 100;

//=========================== Constructors =============================
StringCAL::StringCAL() {
  ptr_ = new char[1];
  ptr_[0] = '\0';
  size_ = 0;
  capacity_ = 0;
}

StringCAL::StringCAL(const char* model) {
  size_t i = 0;
  while (model[i]!=0) {
    i++;
  }
  size_ = i;
  capacity_ = i;
  ptr_ = new char[i+1];
  for(i=0; i<=size_; i++){
    ptr_[i] = model[i];
  }

}


StringCAL :: StringCAL(const StringCAL & copied){
  size_ = copied.size_;
  capacity_ = copied.capacity_;
  ptr_ = new char[capacity_ + 1];
  for (unsigned int i=0;i<size_ + 1;i++){
    ptr_[i] = copied.ptr_[i];
  }
}

StringCAL :: StringCAL(size_t capacity) {
  size_ = 0;
  capacity_ = capacity;
  ptr_ = new char[capacity_ + 1];
  for (unsigned int i = 0; i < capacity_ + 1; i++) {
    ptr_[i] = 0;
  }
}

//=========================== Destructor ===============================
StringCAL::~StringCAL() {
  delete[] ptr_;
}


  //============================ Operators =============================
  
StringCAL &StringCAL::operator=(const StringCAL& str){
  size_ = str.size_;
  capacity_ = str.capacity_;
  ptr_ = new char[capacity_ + 1];
  for (unsigned int i=0;i<size_ + 1;i++){
    ptr_[i] = str.ptr_[i];
  }
  return *this;
}


//=========================== Public Methods ===========================
bool StringCAL::empty() const{
  if (size_ > 0){
    return false;
  }
  return true;
}


// not tested
void StringCAL::reserve(size_t n){
  capacity_ = n; // redefinition of the capacity_
  
  if(n < size_){
    size_ = n;
  }
  
  char *temp_ptr = new char[n+1];  // temp_ptr is used to keep the values of ptr_ before we free its memory
  temp_ptr[n] = '\0';
  
  for(size_t k = 0; k < size_ ; k++){
    temp_ptr[k] = ptr_[k];
  }
  
  delete[] ptr_;
  ptr_ = temp_ptr;
}

const char* StringCAL :: c_str() const{
  return ptr_;
}

void StringCAL :: clear(){
  delete[] ptr_;
  ptr_ = new char[1];
  ptr_[0] = '\0';
  size_ = 0;
  capacity_ = 0;
}


//=========================== Protected Methods ========================

//=========================== Functions ================================

char& StringCAL::operator [] (int i) {
  return ptr_[i];
}

const char& StringCAL::operator [] (int i) const {
  return ptr_[i];
}

StringCAL operator+(const StringCAL &lhs, const char c) {
  StringCAL str(lhs.size() + 2);
  for (unsigned int i = 0; i < lhs.size(); i++) {
    str[i] = lhs[i];
  }
  str[lhs.size()] = c;
  return (str);
}
