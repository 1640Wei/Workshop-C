/***********************************************************************
// OOP345 Workshop 4:
// File	ConfirmationSender.h
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
#ifndef CONFIRMATION_SENDER_H_
#define CONFIRMATION_SENDER_H_
#include "Reservation.h"

namespace sdds {
   class ConfirmationSender{
      const Reservation** m_res{};
      size_t m_order{};
   public:
      //Constructor
      ConfirmationSender();

      //Rule of five
      //Copy Constructor
      ConfirmationSender(const ConfirmationSender& cs);
      //Copy Assignment
      ConfirmationSender& operator=(const ConfirmationSender& cs);
      //Move Constructor 
      ConfirmationSender(ConfirmationSender&& cs);
      //Move Assignment
      ConfirmationSender& operator=(ConfirmationSender&& cs);
      //Destructor
      virtual ~ConfirmationSender(); 

      ConfirmationSender& operator+=(const Reservation& res); 
      ConfirmationSender& operator-=(const Reservation& res); 

      //Friend Helpers
      friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
   };
}
#endif // !SDDS_CONFIRMATION_SENDER_H_

