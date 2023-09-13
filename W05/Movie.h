/***********************************************************************
// OOP345 Workshop 5:
// File	Movie.h
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
#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include <iostream>
#include <string>
namespace sdds {
   class Movie {
      std::string m_title{};
      size_t m_year{};
      std::string m_desc{};
   public:
      Movie();
      const std::string& title() const;
      Movie(const std::string& strMovie);
      //Friend Helpers
      friend std::ostream& operator<<(std::ostream& os, const Movie& M);

      template <typename T>
      void fixSpelling(T& spellChecker) {
         spellChecker(m_title);
         spellChecker(m_desc);
      };
   };
}
#endif  //  !SDDS_MOVIE_H_


