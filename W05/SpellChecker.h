/***********************************************************************
// OOP345 Workshop 5:
// File	SpellChecker.h
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
#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include <iostream>
#include <string>
namespace sdds {
   class SpellChecker {
      std::string m_badWords[6]{};
      std::string m_goodWords[6]{};
      int cnt[6] = {};     
   public:
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out) const;
   };
}
#endif // !SDDS_SPELLCHECKER_H_