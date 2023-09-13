/***********************************************************************
// OOP345 Workshop 3:
// File	UniqueQueue.h
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
#ifndef SDDS_UNIQUEQUEUE_H__
#define SDDS_UNIQUEQUEUE_H__
#include <iostream>
#include <cmath>
#include "Queue.h"

namespace sdds {
   template <typename T>
   class UniqueQueue :public Queue<T, 100> {
   public:
      UniqueQueue() {};
      bool push(const T& item); //override the inherited function push
   };

   template <typename T>
   bool UniqueQueue<T>::push(const T& item) {
      if (this->n >= 100) {
         return false; 
      }
      for (unsigned int i = 0; i < this->n; i++) {
         if (this->queue[i] == item) {
            return false; 
         }
      }
      this->queue[this->n++] = item;
      return true;
   }
   //When T = double, the function push() will ensure that the numbers are "identical" 
   //if the difference between them is 0.005 or less (e.g., 3.001 is the same as 2.998 or 3.004).
   template <>
   bool UniqueQueue<double>::push(const double& item) {
      if (this->n >= 100) {
         return false; 
      }
      for (unsigned int i = 0; i < this->n; i++) {
         if (std::fabs(this->queue[i] - item) <= 0.005) {  //consider the function std::fabs().
            return false; 
         }
      }
      this->queue[this->n++] = item;
      return true;
   }
}
#endif // !SDDS_UNIQUEQUEUE_H__
