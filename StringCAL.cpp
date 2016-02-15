
//=========================== Includes =================================
#include "StringCAL.h"


//================= Definition of static attributes ====================

const size_t StringCAL::MAX_SIZE_ = 100;

//=========================== Constructors =============================
StringCAL::StringCAL() {
  ptr_ = nullptr;
  size_ = 0;
  capacity_ = 0;
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
