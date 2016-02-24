
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
  size_ = i;
  capacity_ = i;
  ptr_ = new char[i+1];
  ptr_[i+1] = '\0';
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
void StringCAL::resize(int len){
  capacity_ = len;
  char* newptr_ = new char[capacity_+1];
  newptr_[capacity_+1] = '\0';
  for (unsigned int i=0; i<capacity_; i++){
    if (i<size_) newptr_[i] = ptr_[i];
    else newptr_[i] = '\0';
  }
  delete[] ptr_;
  ptr_ = newptr_;
  if (size_ > capacity_) size_ = capacity_;
}

void StringCAL::operator=(const char& model){   //Question: char only, or needs char[] too ?
  size_ = 1;
  capacity_ = 1;
  char* newptr_ = new char[2];
  newptr_[0] = model;
  newptr_[1] = '\0';
  delete[] ptr_;
  ptr_ = newptr_;
}
//=========================== Protected Methods ========================

//=========================== Functions ================================
