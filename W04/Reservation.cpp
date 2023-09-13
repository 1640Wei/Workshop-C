/***********************************************************************
// OOP345 Workshop 4:
// File	Reservation.cpp
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
#include <cstring>
#include <iomanip>
#include <algorithm>
#include "Reservation.h"

using namespace std;
namespace sdds {
   //a default constructor
   Reservation::Reservation() {}

   //receives as parameters a new day and time ---> and updates
   void Reservation::update(int day, int time) {
      m_day = day;
      m_hour = time;
   }

   /*I sought assistance from my friend to complete this function
   because I have been struggling for too long to get the correct output. 
   Only the following function was completed with the help of my friend.*/
   Reservation::Reservation(const std::string& res) {
      size_t pos = 0;
      size_t start = 0;
      size_t end = 0;
      string s = res;
      string partySize, day, time;
      string del1 = ":";
      string del2 = ","; 
      const string WHITESPACE = " \n\r\t\f\v";
      //ID
      pos = s.find(del1);   
      m_id = s.substr(0, pos);    
      s.erase(0, pos + del1.length());    
      start = m_id.find_first_not_of(WHITESPACE);
      end = m_id.find_last_not_of(WHITESPACE);
      m_id = m_id.substr(start, end - start + 1);  
      //name
      pos = s.find(del2);
      m_name = s.substr(0, pos);
      s.erase(0, pos + del2.length());
      start = m_name.find_first_not_of(WHITESPACE);
      end = m_name.find_last_not_of(WHITESPACE);
      m_name = m_name.substr(start, end - start + 1);
      //email
      pos = s.find(del2);
      m_email = s.substr(0, pos);
      s.erase(0, pos + del2.length());
      start = m_email.find_first_not_of(WHITESPACE);
      end = m_email.find_last_not_of(WHITESPACE);
      m_email = m_email.substr(start, end - start + 1);
      //people
      pos = s.find(del2);
      m_people = stoi(s.substr(0, pos));   
      s.erase(0, pos + del2.length());
      //day
      pos = s.find(del2);
      m_day = stoi(s.substr(0, pos));   
      s.erase(0, pos + del2.length());
      //hour
      m_hour = stoi(s);
   }

   //Friend Helpers
   std::ostream& operator<<(std::ostream& os, const Reservation& R) {
      os << "Reservation ";
      os << right << std::setw(10) << R.m_id << ": ";
      os << right << std::setw(20) << R.m_name << "  ";
      os << left << std::setw(20) << '<' + R.m_email + '>' << "    ";

      if (R.m_hour >= 6 && R.m_hour <= 9) {
         os << "Breakfast";
      }
      else if (R.m_hour >= 11 && R.m_hour <= 15) {
         os << "Lunch";
      }
      else if (R.m_hour >= 17 && R.m_hour <= 21) {
         os << "Dinner";
      }
      else {
         os << "Drinks";
      }
      os << " on day " << R.m_day << " @ " << R.m_hour << ":00 for " << R.m_people;
      if (R.m_people == 1) {
         os << " person." << endl;
      }
      else {
         os << " people." << endl;
      }
      return os;
   }
}
