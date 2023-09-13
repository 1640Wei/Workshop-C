/***********************************************************************
// OOP345 Workshop 5:
// File	Movie.cpp
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
#include <string>
#include <algorithm> 
#include <iomanip>
#include "Movie.h"
using namespace std;
namespace sdds {

   //a default constructor
   Movie::Movie() {
      m_year = 0;
   }

   const std::string& Movie::title() const {
      return m_title;
   }

   Movie::Movie(const std::string& strMovie) {
      string s = strMovie;
      string del = ",";
      size_t pos = 0;
      size_t start = 0;
      size_t end = 0;
      const string WHITESPACE = " \n\r\t\f\v";
      //title
      pos = s.find(del);
      m_title = s.substr(0, pos);
      s.erase(0, pos + del.length());
      start = m_title.find_first_not_of(WHITESPACE);
      end = m_title.find_last_not_of(WHITESPACE);
      m_title = m_title.substr(start, end - start + 1);
      //year
      pos = s.find(del);
      m_year = stoi(s.substr(0, pos));
      s.erase(0, pos + del.length());
      //description
      pos = s.find("\n");
      m_desc = s.substr(0, pos);
      start = m_desc.find_first_not_of(WHITESPACE);
      end = m_desc.find_last_not_of(WHITESPACE);
      m_desc = m_desc.substr(start, end - start + 1);
   }

   //Friend Helpers
   std::ostream& operator<<(std::ostream& os, const Movie& M) {
      if (M.m_title != "") {
         os << std::right;
         os << std::setw(40) << M.m_title << " | ";
         os << std::setw(4) << M.m_year << " | ";
         os << std::setw(5) << M.m_desc;
         os << std::endl;
      }
      return os;
   }
}
