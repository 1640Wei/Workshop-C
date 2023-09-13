/***********************************************************************
// OOP345 Workshop 5:
// File	Book.h
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
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include <string>
namespace sdds {
   class Book {
      std::string m_author{};
      std::string m_title{};
      std::string m_country{};
      size_t m_year{};
      double m_price{};
      std::string m_des{};
   public:
      Book();
      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      Book(const std::string& strBook); 
      //Friend Helpers
      friend std::ostream& operator<<(std::ostream& ostr, const Book& B);

      template <typename T>
      void fixSpelling(T& spellChecker) {   
         spellChecker(m_des);
      };
   };
}
#endif // !SDDS_BOOK_H_