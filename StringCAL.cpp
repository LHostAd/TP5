
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

StringCAL::StringCAL( const char* model) {
  int i = 0;
  while (model[i]!=0) {
    i++;
  }
  size_ = i-1;
  capacity_ = i-1;
  ptr_ = new char[i];
  ptr_[i] = '\0';
  for (unsigned int i=0; i<size_; i++){
    ptr_[i] = model[i];
  }
}

StringCAL :: StringCAL(const StringCAL & copied){
  size_ = copied.size_;
  capacity_ = copied.capacity_;
  ptr_ = new char[size_];
  for (unsigned int i=0;i<size_;i++){
    ptr_[i] = copied.ptr_[i];
  }
}

//=========================== Destructor ===============================
StringCAL::~StringCAL() {
  delete[] ptr_;
}

//=========================== Public Methods ===========================

//=========================== Protected Methods ========================

//=========================== Functions ================================
