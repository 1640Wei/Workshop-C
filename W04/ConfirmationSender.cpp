/***********************************************************************
// OOP345 Workshop 4:
// File	ConfirmationSender.cpp
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
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {

   //Constructor
   ConfirmationSender::ConfirmationSender() {}

   //Copy Constructor
   ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
      *this = cs;
   }

   //Copy Assignment
   ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) {
      if (this != &cs) {
         delete[] m_res; // Deallocate 
         m_order = cs.m_order;  
         m_res = new const Reservation * [m_order]; // Allocate new memory and copy the reservations
         for (unsigned i = 0; i < m_order; i++) {
            m_res[i] = cs.m_res[i];
         }
      }
      return *this;
   }

   //Move Constructor 
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) {
      *this = move(cs);
   }

   //Move Assignment
   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) {
      if (this != &cs) {
         delete[] m_res; 
         m_res = cs.m_res;  
         m_order = cs.m_order; 
         cs.m_res = nullptr; 
         cs.m_order = 0;      
      }
      return *this;
   }

   //Destructor
   ConfirmationSender::~ConfirmationSender() {
      delete[] m_res;
   }

   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
      int index = -1; 
      bool flag = false;
      if (m_order) { // if the m_order > 0, iterate through the array
         for (unsigned i = 0; i < m_order && !flag; i++) {
            if (m_res[i] == &res) { //find it --> assign i to index
               flag = true;
               index = i;
            }
         }
      }
      if (index < 0) { // the value of index is still -1
         //create a new temporary array
         const Reservation** temp = new const Reservation * [m_order + 1];
         for (unsigned i = 0; i < m_order; i++) { //use for loop to copy the elements
            temp[i] = m_res[i];
         }
         temp[m_order] = &res; //store the pointer, 
         delete[] m_res; //free the memory allocated
         m_res = temp;
         m_order++; //increase the size of order
      }
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      int index = -1;
      bool flag = false;
      if (m_order) { // if the m_order > 0, iterate through the array
         for (unsigned i = 0; i < m_order && !flag; i++) { 
            if (m_res[i] == &res) { //find it ---> assign i to index
               flag = true;
               index = i;
            }
         }
      }
      if (index >= 0) {  //find it ---> delete
         m_res[index] = nullptr;  //set it to nullptr
         //shift the elements and fill the gap left by removed reservation
         for (unsigned i = index + 1; i < m_order; i++) {
            m_res[i - 1] = m_res[i];
         }
         m_order--; //decrease the size of order
      }
      return *this;
   }

   //Friend Helpers
   std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res) {
      static unsigned int CALL_CNT{};
      CALL_CNT++;
      os << "--------------------------" << std::endl;
      os << "Confirmations to Send" << std::endl;
      os << "--------------------------" << std::endl;
      if (!res.m_order) {
         os << "There are no confirmations to send!" << std::endl;
      }
      else {
         for (unsigned i{ 0 }; i < res.m_order; i++) {
            os << *res.m_res[i];
         }
      }
      os << "--------------------------" << std::endl;
      return os;
   }
}
