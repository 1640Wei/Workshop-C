/***********************************************************************
// OOP345 Workshop 1:
// File	Carads.h
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
#ifndef SDDS_CARADS_H__
#define SDDS_CARADS_H__
#include <iostream>
#include <cstring>

//The variables are defined in this module and can be accessed from an external module --> use "extern"
extern double g_taxrate;
extern double g_discount;

namespace sdds {
	//Global Function
	void listArgs(int argc, char* argv[]);

	class Cars
	{
		//char brand[10] = {}; // p1 ---> a C-style null-terminated string of up to 10 characters
		char* brand{}; //p2
		char model[15] = {};
		int manufacture_year{};
		double price{};
		char status{};
		bool promotion{};
	public:
		Cars();
		std::istream& read(std::istream& is);
		void display(bool reset);
		char getStatus();
		operator bool() const;	
		//rule of three
		Cars(const Cars& c);
		Cars& operator=(const Cars& c);
		~Cars();
	};

	//Global Functions
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);
}
#endif // !SDDS_CARADS_H
