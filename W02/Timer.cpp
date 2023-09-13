/***********************************************************************
// OOP345 Workshop 2:
// File	Timer.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include "Timer.h"

using namespace std;
namespace sdds {
   //start(): a modifier that starts the timer (takes the current timestamp and stores it in an attribute).
   void Timer::start() {
      begin = std::chrono::steady_clock::now();
   }
   //stop(): a modifier that stops the timer (takes the current timestamp) 
   //and returns how many nanoseconds passed since the timer has started as a long long value.
   long long Timer::stop() {   
      auto end = std::chrono::steady_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
      return duration.count();
   }
}