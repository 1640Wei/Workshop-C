/***********************************************************************
// OOP345 Workshop 4:
// File	Reservation.h
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
#ifndef RESERVATION_H_
#define RESERVATION_H_
#include <iostream>
#include <string>

namespace sdds {
   class Reservation {
      std::string m_id{};  
      std::string m_name{};   
      std::string m_email{};    
      unsigned int m_people{};   
      int m_day{};   
      int m_hour{};   
   public:
      //Constructor
      Reservation();  
      void update(int day, int time);
      Reservation(const std::string& res);

      //Friend Helpers
      friend std::ostream& operator<<(std::ostream& os, const Reservation& R);   
   };
}
#endif // !SDDS_ RESERVATION_H_


