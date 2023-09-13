/***********************************************************************
// OOP345 Workshop 2:
// File	TennisLog.h
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
#ifndef SDDS_TENNISLOG_H_
#define SDDS_TENNISLOG_H_
#include <iostream>
#include <string>

namespace sdds {
   //TennisMatch ---> struct
   struct TennisMatch {
      std::string tournamentID{};  
      std::string tournamentName{}; 
      unsigned int matchID{}; //a positive integer -> unsigned
      std::string winner{};   
      std::string loser{};  
   };
   //TennisLog ---> class
   class TennisLog {
   private:
      TennisMatch* tennisMatches{};  //manage a dynamic array of TennisMatches
      size_t count{};    
   public:
      //Default constructor
      TennisLog();   
      TennisLog(const char* filename);    
      void addMatch(const TennisMatch& match);
      TennisLog findMatches(const char* name);
      const TennisMatch operator[](size_t index) const;
      operator size_t() const;    
      //rule of five
      virtual ~TennisLog(); //destructor
      TennisLog(const TennisLog& T);   //copy constructor 
      TennisLog& operator=(const TennisLog& T);  //copy assignment operator
      TennisLog(TennisLog&& T) noexcept;     //move constructor
      TennisLog& operator=(TennisLog&& rhs) noexcept;   //move assignment
   };
   std::ostream& operator<< (std::ostream& os, const TennisMatch& T);
}
#endif 