
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

StringCAl::StringCAL(const char* model) {
  ptr_ = model;
  int i = 0;
  while (model[i]!=0) {
    i++;
  }
  size_ = i-1;
  capacity_ = i-1;


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
