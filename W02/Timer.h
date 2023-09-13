/***********************************************************************
// OOP345 Workshop 2:
// File	Timer.h
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
#ifndef SDDS_TIMER_H_
#define SDDS_TIMER_H_
#include <iostream>
#include <chrono>

namespace sdds {
   class Timer {
      std::chrono::time_point<std::chrono::steady_clock> begin;
   public:
      void start();
      long long stop();
   };
}
#endif 