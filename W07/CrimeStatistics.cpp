/***********************************************************************
// OOP345 Workshop 7:
// File	CrimeStatistics.cpp
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
#include <fstream>
#include <string>
#include <algorithm> 
#include <iomanip>
#include <numeric>
#include <cstring>
#include "CrimeStatistics.h"
using namespace std;
namespace sdds {
   CrimeStatistics::CrimeStatistics(const char* filename) {
      std::ifstream file(filename);
      if (!file){
         throw "File does not exist!\n";
      }
      string str;
      do {
         getline(file, str); 
         if (file) {
            Crime temp;
            size_t start = 0;
            size_t end = 0;
            const string WHITESPACE = " \n\r\t\f\v";
            //province
            temp.m_province = str.substr(0, 25);
            start = temp.m_province.find_first_not_of(WHITESPACE);
            end = temp.m_province.find_last_not_of(WHITESPACE);
            temp.m_province = temp.m_province.substr(start, end - start + 1);   
            str.erase(0, 25);  
            //district
            temp.m_district = str.substr(0, 25);
            start = temp.m_district.find_first_not_of(WHITESPACE);
            end = temp.m_district.find_last_not_of(WHITESPACE);
            temp.m_district = temp.m_district.substr(start, end - start + 1);
            str.erase(0, 25);
            //crime
            temp.m_crime = str.substr(0, 25);
            start = temp.m_crime.find_first_not_of(WHITESPACE);
            end = temp.m_crime.find_last_not_of(WHITESPACE);
            temp.m_crime = temp.m_crime.substr(start, end - start + 1);
            str.erase(0, 25);
            //year
            temp.m_year = stoi(str.substr(0, 5));
            str.erase(0, 5);
            //case
            temp.m_case = stoi(str.substr(0, 5));
            str.erase(0, 5);
            //resolved
            temp.m_resolved = stoi(str);
            crimeList.push_back(temp);
         }
      } while (file);
   }

   void CrimeStatistics::display(std::ostream& out) const {
      int total = 0;
      int resolved = 0;
      //iterate over each element in the crimeList vector and calculate the number of crime,  the cases, and the resolved cases
      for_each(crimeList.begin(), crimeList.end(), [&](const Crime& C) 
         { out << C << endl; total += C.m_case; resolved += C.m_resolved; });
      out << setw(89) << setfill('-') << '\n' << setfill(' ');
      out << "| " << setw(78) << "Total Crimes: " << setw(6) << total << " |\n";
      out << "| " << setw(78) << "Total Resolved Cases: " << setw(6) << resolved << " |\n";
   }

   void CrimeStatistics::sort(std::string category) {
      //The sort function is used to perform different sorts on the crimeList vector.
      if (category == "Province") {
         std::sort(crimeList.begin(), crimeList.end(), [](const Crime& a, const Crime& b) 
            {return a.m_province < b.m_province; });
      }
      if (category == "Crime") {  
         std::sort(crimeList.begin(), crimeList.end(), [](const Crime& a, const Crime& b) 
            {return a.m_crime < b.m_crime; });
      }
      if (category == "Cases") {
         std::sort(crimeList.begin(), crimeList.end(), [](const Crime& a, const Crime& b) 
            {return a.m_case < b.m_case; });
      }
      if (category == "Resolved") {
         std::sort(crimeList.begin(), crimeList.end(), [](const Crime& a, const Crime& b) 
            {return a.m_resolved < b.m_resolved; });
      }
   }

   void CrimeStatistics::cleanList() {
      for_each(crimeList.begin(), crimeList.end(), [&](Crime& C) 
         {if (C.m_crime == "[None]") C.m_crime = ""; });
   }

   bool CrimeStatistics::inCollection(std::string crimeStr) const {
      //Iterate over each element in the crimeList vector and compare the m_crime member of each Crime object with the crimeStr.
      return any_of(crimeList.begin(), crimeList.end(), [=](const Crime& C) 
         {return C.m_crime == crimeStr; });
   }

   std::list<Crime> CrimeStatistics::getListForProvince(std::string provinceStr) const {
      std::list<Crime> proList;
      //Create a new container and return a new list containing the Crime objects that satisfy the condition.
      copy_if(crimeList.begin(), crimeList.end(), std::back_inserter(proList), [=](const Crime& C) 
         {return C.m_province == provinceStr; });
      return proList;
   }

   std::ostream& operator<<(std::ostream& out, const Crime& c) {
      out << "| " << setfill(' ') << left << setw(21) << c.m_province;
      out << " | " << left << setw(15) << c.m_district;
      out << " | " << left << setw(20) << c.m_crime;
      out << " | " << right << setw(6) << c.m_year;
      out << " | " << right << setw(4) << c.m_case;
      out << " | " << setw(3) << c.m_resolved << " |";
      return out;
   }

}