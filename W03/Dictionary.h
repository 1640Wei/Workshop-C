/***********************************************************************
// OOP345 Workshop 3:
// File	Dictionary.h
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
#ifndef SDDS_DICTIONARY_H__
#define SDDS_DICTIONARY_H__
#include <iostream>
#include <string>
namespace sdds {

   class Dictionary
   {
      std::string m_term{};
      std::string m_definition{};
   public:
      Dictionary();
      const std::string& getTerm() const { return m_term; }
      const std::string& getDefinition() const { return m_definition; }
      Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
      bool operator==(const Dictionary& dic);
   };
   std::ostream& operator<<(std::ostream& os, const Dictionary& d);
}

#endif // !SDDS_DICTIONARY_H__