/***********************************************************************
// OOP345 Workshop 3:
// File	Queue.h
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
#ifndef SDDS_QUEUE_H__
#define SDDS_QUEUE_H__
#include <iostream>
#include "Dictionary.h"

namespace sdds {
   //T: the type of any element in the queue
   //CAPACITY: the capacity of the collection(a non-type parameter; an integer without sign).
   template <typename T, unsigned int CAPACITY>
   class Queue {
   protected:
      T queue[CAPACITY]{};
      unsigned int n;
      static T dummy;
   public:
      Queue();  
      virtual bool push(const T& item);
      T pop();
      unsigned int size() const;
      std::ostream& display(std::ostream& os = std::cout)const;
      const T operator[](unsigned int index)const;
      virtual ~Queue() {}; //add an empty body destructor.
   };

   template<typename T, unsigned int CAPACITY>
   T Queue<T, CAPACITY>::dummy{};

   template <typename T, unsigned int CAPACITY>
   Queue<T, CAPACITY>::Queue() {
      n = 0;
   }

   //bool push(const T& item) ---> a mutator that adds a copy of the parameter to the queue if there still is capacity
   template <typename T, unsigned int CAPACITY>
   bool Queue<T, CAPACITY>::push(const T& item) {
      //If the item has been added, this function return true; false otherwise.
      bool result = false;
      if (size() < CAPACITY) {
         queue[n] = item;
         n++;
         result = true;
      }
      return result;
   }

   //pop() ---> a mutator that removes the first member of the queue. 
   template <typename T, unsigned int CAPACITY>
   T Queue<T, CAPACITY>::pop() {
      //Create a temporary copy
      dummy = queue[0];  
      //it shifts the rest of the queue elements forward by one index.
      for (unsigned int i = 1; i <= n; i++) {
         queue[i - 1] = queue[i];
      }
      n -= 1;
      return dummy; //returns a copy of the removed object.
   }

   //size() ---> a query that returns the current number of elements in the queue
   template <typename T, unsigned int CAPACITY>
   unsigned int Queue<T, CAPACITY>::size() const {
      return n;
   }

   //display() ---> a query that receives as the parameter an output stream 
   template <typename T, unsigned int CAPACITY>
   std::ostream& Queue<T, CAPACITY>::display(std::ostream& os)const {
      //display "Dictionary Content"
      os << "----------------------" << std::endl;
      os << "| Dictionary Content |" << std::endl;
      os << "----------------------" << std::endl;
      //inserts into the stream all items from the collection
      for (unsigned int i = 0; i < size(); i++) {
         os << queue[i] << std::endl;
      }
      os << "----------------------" << std::endl;
      return os;
   }

   //operator[] ---> a query that receives an index as parameter and 
   //returns a copy of the element stored in the collection at the specified index.
   template <typename T, unsigned int CAPACITY>
   const T Queue<T, CAPACITY>::operator[](unsigned int index)const {
      if ((unsigned)index < n) {
         return queue[index];
      }
      return dummy;
   }
   
   //Specialize the class-member object 
   //T = Dictionary and CAPACITY = 100u ---> "Empty Term" and "Empty Substitute".
   template<>
   Dictionary Queue<Dictionary, 100>::dummy = []() {
      Dictionary d("Empty Term", "Empty Substitute");
      return d;
   }();
}
#endif // !SDDS_QUEUE_H