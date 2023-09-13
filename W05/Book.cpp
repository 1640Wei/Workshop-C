/***********************************************************************
// OOP345 Workshop 5:
// File	Book.cpp
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
#include "Book.h"
using namespace std;
namespace sdds {
   //a default constructor
   Book::Book() {
      m_year = 0;
      m_price = 0.00;
   }

   const std::string& Book::title() const {
      return m_title;
   }

   const std::string& Book::country() const {
      return m_country;
   }

   const size_t& Book::year() const {
      return m_year;
   }

   double& Book::price() {
      return m_price;
   }

   //Extracts the information about the book from the string by parsing it and stores the tokens in the object's attributes.
   Book::Book(const std::string& strBook) {
      string s = strBook;
      string del = ",";
      size_t pos = 0;
      size_t start = 0;
      size_t end = 0;
      const string WHITESPACE = " \n\r\t\f\v";
      //author
      pos = s.find(del);
      m_author = s.substr(0, pos);
      s.erase(0, pos + del.length());   
      start = m_author.find_first_not_of(WHITESPACE);
      end = m_author.find_last_not_of(WHITESPACE);
      m_author = m_author.substr(start, end - start + 1);   
      //title
      pos = s.find(del);
      m_title = s.substr(0, pos);
      s.erase(0, pos + del.length());
      start = m_title.find_first_not_of(WHITESPACE);
      end = m_title.find_last_not_of(WHITESPACE);
      m_title = m_title.substr(start, end - start + 1);
      //country
      pos = s.find(del);
      m_country = s.substr(0, pos);
      s.erase(0, pos + del.length());
      start = m_country.find_first_not_of(WHITESPACE);
      end = m_country.find_last_not_of(WHITESPACE);
      m_country = m_country.substr(start, end - start + 1);
      //price
      pos = s.find(del);
      m_price = stod(s.substr(0, pos));
      s.erase(0, pos + del.length());
      //year
      pos = s.find(del);
      m_year = stoi(s.substr(0, pos));
      s.erase(0, pos + del.length());
      //description
      pos = s.find("\n");
      m_des = s.substr(0, pos);
      start = m_des.find_first_not_of(WHITESPACE);
      end = m_des.find_last_not_of(WHITESPACE);
      m_des = m_des.substr(start, end - start + 1);
   }

   //Friend Helpers
   std::ostream& operator<<(std::ostream& os, const Book& book) {
      if (book.m_title != "") {
         os << right;
         os << setw(20) << book.m_author << " | ";
         os << setw(22) << book.m_title << " | ";
         os << setw(5) << book.m_country << " | ";
         os << setw(4) << book.m_year << " | ";
         os << fixed << std::setprecision(2);
         os << setw(6) << book.m_price << " | ";
         os << left;
         os << setw(22) << book.m_des;
         os << endl;
      }
      return os;
   }
}