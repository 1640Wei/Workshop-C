/***********************************************************************
// OOP345 Workshop 4:
// File	Restaurant.cpp
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
#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"

using namespace std;
namespace sdds {

   //Constructor
   Restaurant::Restaurant() {
      m_res = nullptr;
      m_numOfRes = 0;
   }

   Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
      m_res = new Reservation * [cnt];
      for (unsigned int i = 0; i < cnt; i++) {
         m_res[i] = new Reservation;
         *m_res[i] = *reservations[i];
      }
      m_numOfRes = cnt;
   }

   //Copy Constructor
   Restaurant::Restaurant(const Restaurant& r) {
      *this = r;
   }

   //Copy Assignment
   Restaurant& Restaurant::operator=(const Restaurant& r) {
      if (this != &r) {
         //release the resource
         for (size_t i = 0; i < m_numOfRes; ++i) {
            delete m_res[i];
         }
         delete[] m_res;
         //then, copy
         m_numOfRes = r.m_numOfRes;
         m_res = new Reservation * [m_numOfRes];
         for (size_t i = 0; i < m_numOfRes; ++i) {
            m_res[i] = new Reservation(*r.m_res[i]);
         }
      }
      return *this;
   }

   //Move Constructor 
   Restaurant::Restaurant(Restaurant&& r) {
      *this = move(r);
   }

   //Move Assignment
   Restaurant& Restaurant::operator=(Restaurant&& r) {
      if (this != &r) {
         //release the resources
         while (m_numOfRes) {
            delete m_res[--m_numOfRes];
         }
         delete[] m_res;
         //then, copy
         m_numOfRes = r.m_numOfRes;
         m_res = r.m_res;
         //reset the values of the source object
         r.m_numOfRes = 0;
         r.m_res = nullptr;
      }
      return *this;
   }

   //Destructor
   Restaurant::~Restaurant() {
      for (size_t i = 0; i < m_numOfRes; i++) {
         delete m_res[i];
      }
      delete[] m_res;
   }

   //size_t size() ---> returns the number of reservations in the system.
   size_t Restaurant::size() const {
      return m_numOfRes;
   }

   //Friend Helpers
   std::ostream& operator<<(std::ostream& os, const Restaurant& r) {
      static unsigned int CALL_CNT{};
      CALL_CNT++;
      os << "--------------------------" << std::endl;
      os << "Fancy Restaurant (" << CALL_CNT << ")" << std::endl;
      os << "--------------------------" << std::endl;
      if (r.m_res != nullptr) {
         for (unsigned int i = 0; i < r.m_numOfRes; i++) {
            os << *r.m_res[i];
         }
      }
      else {
         os << "This restaurant is empty!" << std::endl;
      }
      os << "--------------------------" << std::endl;
      return os;
   }
}
