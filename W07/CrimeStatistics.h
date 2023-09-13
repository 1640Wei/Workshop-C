/***********************************************************************
// OOP345 Workshop 7:
// File	CrimeStatistics.h
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
#ifndef SDDS_CRIMESTATISTICS_H__
#define SDDS_CRIMESTATISTICS_H__
#include <iostream>
#include <string>
#include <vector>
#include <list>
namespace sdds {
   struct Crime {
      std::string m_province{};
      std::string m_district{};
      std::string m_crime{};
      int m_year{};
      int m_case{};
      int m_resolved{};
   };
   class CrimeStatistics {
      std::vector<Crime> crimeList;   
   public:
      CrimeStatistics(const char* filename);
      void display(std::ostream& out) const;
      void sort(std::string category);
      void cleanList();
      bool inCollection(std::string crimeStr) const;
      std::list<Crime> getListForProvince(std::string provinceStr) const;
   };
   std::ostream& operator<<(std::ostream& out, const Crime& c);
}
#endif
