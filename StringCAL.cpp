
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

//=========================== Destructor ===============================
StringCAL::~StringCAL() {
  delete[] ptr_;
}

//=========================== Public Methods ===========================

//=========================== Protected Methods ========================

//=========================== Functions ================================
