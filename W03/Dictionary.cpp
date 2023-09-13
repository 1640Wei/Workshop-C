/***********************************************************************
// OOP345 Workshop 3:
// File	Dictionary.cpp
// Version 1.0
// Author	Ching Wei Lai
// Student ID 136893211
// Email  cwlai6@myseneca.ca
//
// Authenticity Declaration:
// I declare this submission is the result of my own work and has not been
// shared with any other student or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Dictionary.h"
using namespace std;
namespace sdds {
   Dictionary::Dictionary() {}

   bool Dictionary::operator==(const Dictionary& dic) {
      return m_term == dic.m_term;
   }

   std::ostream& operator<<(std::ostream& os, const Dictionary& d) {
      os.width(20);
      os.fill(' ');
      os.setf(std::ios::right);
      os << d.getTerm();
      os.unsetf(std::ios::right);
      os << ": " << d.getDefinition();
      return os;
   }
}