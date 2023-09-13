/***********************************************************************
// OOP345 Workshop 5:
// File	Collection.h
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
#ifndef COLLECTION_H_
#define COLLECTION_H_
#include <iostream>
#include <string>

namespace sdds {
   template <typename T>
   class Collection{
      std::string m_name{};
      T* m_collection{};
      size_t m_size{};
      void (*m_observer)(const Collection<T>&, const T&) {};

   public:
      Collection() {}

      //class doesn't support any copy operations ---> delete
      Collection(const std::string& name) : m_name(name) {}
      Collection(const Collection&) = delete;
      Collection& operator=(const Collection&) = delete;

      ~Collection() { delete[] m_collection; }

      //returns the name
      const std::string& name() const {
         return m_name;
      }

      //returns the number of items
      size_t size() const {
         return m_size;
      }

      //set m_observer to function address
      void setObserver(void (*observer)(const Collection<T>&, const T&)) {
         m_observer = observer;
      }

      Collection<T>& operator+=(const T& item) {
         bool match{ false };

         for (unsigned i{ 0 }; i < m_size; i++) {   //compares item titles for matches within m_collection and the item being added.
            if (m_collection[i].title() == item.title()) {
               match = true;
            }
         }

         if (!match) {  //not match ---> the m_collection copy to the temporary array.
            T* temp = new T[m_size + 1];
            for (unsigned i{ 0 }; i < m_size; i++) {
               temp[i] = m_collection[i];
            }
            delete[]m_collection;  //delete the old one first
            temp[m_size] = item;   //assign item to new collection
            m_size++;
            m_collection = temp;
            if (m_observer) {
               m_observer(*this, item);
            }
         }
         return *this;
      }

      T& operator[](size_t idx) const {
         if (idx < 0 || idx >= m_size) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
         }
         else {
            return m_collection[idx];
         }
      }

      T* operator[](const std::string& title) {
         T* adr = nullptr;
         for (unsigned i{ 0 }; i < m_size; i++) {
            if (m_collection[i].title() == title) {
               adr = &m_collection[i];
            }
         }
         return adr == nullptr ? nullptr : adr;
      }

      friend std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
         for (unsigned i{ 0 }; i < collection.size(); i++) {
            os << collection.m_collection[i];
         }
         return os;
      }
   };
}
#endif //  !SDDS_COLLECTION_H_