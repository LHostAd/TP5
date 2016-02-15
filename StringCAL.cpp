
//=========================== Includes =================================
#include "StringCAL.h"


//================= Definition of static attributes ====================

const size_t StringCAL::MAX_SIZE_ = 100;

//=========================== Constructors =============================
StringCAL::StringCAL() {
  ptr_ = new char*[];
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
}

//=========================== Destructor ===============================
StringCAL::~StringCAL() {
  delete[] ptr_;
}

//=========================== Public Methods ===========================

//=========================== Protected Methods ========================

//=========================== Functions ================================
