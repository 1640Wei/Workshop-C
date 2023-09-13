/***********************************************************************
// OOP345 Workshop 2:
// File	TennisLog.cpp
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
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "TennisLog.h"

using namespace std;
namespace sdds {
   //Default constructor
   TennisLog::TennisLog() {
      tennisMatches = nullptr;
   }

   //A one argument constructor ---> receives a filename as a parameter
   TennisLog::TennisLog(const char* filename) {
      //open the file ---> do not forget to close it
      std::ifstream f(filename);
      count = 0;
      string str;
      //getline() ---> read a string or a line from an input stream
      while (getline(f, str)) {    
         count++;
      }
      count -= 1;    
      tennisMatches = new TennisMatch[count];   
      f.clear(); // ---> To clear the stream.
      //seekg() ---> to set the position of the next character to be extracted from the input stream.
      f.seekg(0);   
      f.ignore(256, '\n');   
      int i = 0;
      //getline() ---> read a string or a line from an input stream
      while (getline(f, str)) {   
         stringstream s(str); // to read from the string as if it were a stream
         string tempID, tempName, tempMatch, tempWinner, tempLoser;
         getline(s, tempID, ',');
         getline(s, tempName, ',');
         getline(s, tempMatch, ',');
         getline(s, tempWinner, ',');
         getline(s, tempLoser);
         tennisMatches[i].tournamentID = tempID;
         tennisMatches[i].tournamentName = tempName;
         tennisMatches[i].matchID = stoi(tempMatch);
         tennisMatches[i].winner = tempWinner;
         tennisMatches[i].loser = tempLoser;
         i++;
      }
      f.close();//close the file
   }

   //addMatch() is a modifier ---> receives a TennisMatch object and returns nothing
   void TennisLog::addMatch(const TennisMatch& match) {
      TennisMatch* newMatch = new TennisMatch[count + 1];
      for (size_t i = 0; i < count; i++) {
         newMatch[i] = tennisMatches[i];
      }
      newMatch[count] = match;
      delete[] tennisMatches;
      tennisMatches = newMatch;
      count++;
   }

   //findMatches() ---> receives a name of a player as a parameter and returns a TennisLog object
   TennisLog TennisLog::findMatches(const char* name) {
      TennisLog matches;
      matches.count = 0;
      //use a for loop to check everything
      for (size_t i = 0; i < count; i++) {
         //all of the matches ---> winner's name and loser's name
         if (name == tennisMatches[i].winner || name == tennisMatches[i].loser) {
            matches.addMatch(tennisMatches[i]);
         }
      }
      return matches;
   }

   //operator[](size_t) ---> return the TennisMatch in the dynamic array at the index provided
   const TennisMatch TennisLog::operator[](size_t index) const {
      //return the TennisMatch in the dynamic array at the index provided
      if (index < count) {
         return tennisMatches[index];
      }
      //If the array isn't populated ---> return empty
      TennisMatch empty;
      return empty;
   }

   //size_t() ---> return count
   TennisLog::operator size_t() const {
      return count;
   }

   //rule-of-five
   //destructor
   TennisLog::~TennisLog() {
      delete[] tennisMatches;
      tennisMatches = nullptr;
   }

   //copy constructor
   TennisLog::TennisLog(const TennisLog& T) {
      *this = T;
   }

   //copy assignment operator
   TennisLog& TennisLog::operator=(const TennisLog& T) {
      //avoid self assignment
      if (this != &T) {
         delete[] tennisMatches;
         count = T.count;
         //DMA
         tennisMatches = new TennisMatch[count];
         for (size_t i = 0; i < count; i++) {
            tennisMatches[i] = T.tennisMatches[i];
         }
      }
      return *this;
   }

   //move constructor
   TennisLog::TennisLog(TennisLog&& T) noexcept {
      *this = move(T);
   }

   //move assignment
   TennisLog& TennisLog::operator=(TennisLog&& rhs) noexcept {
      // avoid self assignment
      if (this != &rhs) {
         //delete tennisMatches pointer 
         delete[] tennisMatches;
         tennisMatches = rhs.tennisMatches; //assign
         rhs.tennisMatches = nullptr; //set to nullptr
         count = rhs.count; //assign
         rhs.count = 0; //set to zero
      }
      return *this;
   }

   ostream& operator<<(ostream& os, const TennisMatch& T) {
      // If a given TennisMatch object is in an empty state ---> empty match
      if (T.matchID == 0)
      {
         cout << "Empty Match";
      }
      //otherwise ---> format
      else
      { 
         //Tourney ID
         cout.width(23);
         cout.fill('.');
         cout.setf(ios::right); // labels will be aligned to the right
         cout << "Tourney ID : ";
         cout.unsetf(ios::right);
         cout.width(30); //value ---> a field of exactly 30 characters wide
         cout.fill('.'); //the filling character is a dot
         cout.setf(ios::left); //values will be aligned to the left
         cout << T.tournamentID << endl;
         //Match ID
         cout.width(23);
         cout.fill('.');
         cout.setf(ios::right);
         cout << "Match ID : ";
         cout.unsetf(ios::right);
         cout.width(30);
         cout.fill('.');
         cout.setf(ios::left);
         cout << T.matchID << endl;
         //Tourney
         cout.width(23);
         cout.fill('.');
         cout.setf(ios::right);
         cout << "Tourney : ";
         cout.unsetf(ios::right);
         cout.width(30);
         cout.fill('.');
         cout.setf(ios::left);
         cout << T.tournamentName << endl;
         //Winner
         cout.width(23);
         cout.fill('.');
         cout.setf(ios::right);
         cout << "Winner : ";
         cout.unsetf(ios::right);
         cout.width(30);
         cout.fill('.');
         cout.setf(ios::left);
         cout << T.winner << endl;
         //Loser
         cout.width(23);
         cout.fill('.');
         cout.setf(ios::right);
         cout << "Loser : ";
         cout.unsetf(ios::right);
         cout.width(30);
         cout.fill('.');
         cout.setf(ios::left);
         cout << T.loser << endl;
      }
      return os;
   }

}
