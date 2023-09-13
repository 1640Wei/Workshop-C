/***********************************************************************
// OOP345 Workshop 5:
// File	SpellChecker.cpp
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
#include "SpellChecker.h"
using namespace std;
namespace sdds {

   SpellChecker::SpellChecker(const char* filename) {
      std::ifstream file(filename); //Check if the file was successfully opened. If not --- > throw an exception with the message.
      if (!file) {
         throw "Bad file name!";
      }
      std::string s_words;
      size_t cnt = 0; //Track the number of bad words read from the file
      const std::string WHITESPACE = " \n\r\t\f\v";
      while (getline(file, s_words)) {   
         std::string del = " ";          
         size_t pos = s_words.find(del); //Find the position of the delimiter ---> store it in the pos
         m_badWords[cnt] = s_words.substr(0, pos);  //Extract the bad word  ---> store it in the m_badWords array at the current cnt index
         s_words.erase(0, pos + del.length());      //Erase the extracted bad word and the delimiter
         size_t start = s_words.find_first_not_of(WHITESPACE);      //Find the index of the first non-whitespace character ---> store it in the start
         size_t end = s_words.find_last_not_of(WHITESPACE);         //Find the index of the last non-whitespace character ---> store it in the end
         m_goodWords[cnt] = s_words.substr(start, end - start + 1); //Extract the good word 
         cnt++;   
         if (cnt >= 6) {  
            break;
         }
      }
   }

   //searches text and replaces any misspelled word with the correct version ---> Count misspelled word replacements.
   void SpellChecker::operator()(std::string& text) {
      for (int i = 0; i < 6; i++) {
         size_t found = text.find(m_badWords[i]);   // The find() function returns the index position of the found substring
         while (found != std::string::npos) {      //std::string::npos ---> it is not found
            text.replace(found, m_badWords[i].length(), m_goodWords[i]);   //replace the found m_badWords with the corresponding m_goodWords
            cnt[i]++;    // track of the number of times each misspelled word has been replaced.
            found = text.find(m_badWords[i], found + m_goodWords[i].length());  //ensures the search starts from the position immediately after the last replacement
         }
      }
   }

   void SpellChecker::showStatistics(std::ostream& out) const {
      out << "Spellchecker Statistics" << endl;
      for (int i = 0; i < 6; i++) {
         out << setfill(' ');
         out << setw(15) << m_badWords[i];
         out << ": " << cnt[i] << " replacements" << endl;
      }
   }
}