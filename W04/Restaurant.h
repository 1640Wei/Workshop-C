/***********************************************************************
// OOP345 Workshop 4:
// File	Restaurant.h
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
#ifndef RESTAURANT_H_
#define RESTAURANT_H_
#include <iostream>
#include "Reservation.h"

namespace sdds {
   class Restaurant {
      Reservation** m_res{}; //each element of the array points to an object of type Reservation
      size_t m_numOfRes{};
   public:
      //Constructor
      Restaurant();
      Restaurant(const Reservation* reservations[], size_t cnt);

      //Rule of five
      //Copy Constructor
      Restaurant(const Restaurant& r);
      //Copy Assignment
      Restaurant& operator=(const Restaurant& r);
      //Move Constructor 
      Restaurant(Restaurant&& r);
      //Move Assignment
      Restaurant& operator=(Restaurant&& r);
      //Destructor
      virtual ~Restaurant();

      size_t size()const; //a query that returns the number of reservations in the system.

      //Friend Helpers
      friend std::ostream& operator<<(std::ostream& os, const Restaurant& r);
   };
}
#endif // !SDDS_RESTAURANT_H_

