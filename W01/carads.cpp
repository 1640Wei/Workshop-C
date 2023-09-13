/***********************************************************************
// OOP345 Workshop 1:
// File	Carads.cpp
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
#include <iomanip>
#include <string>
#include <cstring>
#include "carads.h"

using namespace std;
double g_taxrate = 0; 
double g_discount = 0;

namespace sdds {

	//listArgs function ---> receives the same parameters as the main function ---> int argc, char* argv[]
	void listArgs(int argc, char* argv[])
	{
		cout << "Command Line:" << endl << "--------------------------" << endl;
		//use for loop to read the file's name
		for (auto i = 0; i < argc; i++)
		{
			cout << "  " << i + 1 << ": " << argv[i] << endl;
		}
		cout << "--------------------------" << endl << endl;
	}

	//default constructor
	Cars::Cars() {}

	istream& Cars::read(istream& is)
	{
		char discount{};
		//If the istream is in a good state ---> read from the istream and store the information read into current object. 
		if (is.good())
		{
			//temp string
			std::string brand_temp;

			is >> status;
			is.ignore(1000, ',');
			//is.getline(brand, 10, ','); //p1

			std::getline(is, brand_temp, ','); //p2
			delete[] brand;
			brand = nullptr;
			brand = new char[brand_temp.length() + 1];
			strcpy(brand,brand_temp.c_str());


			is.getline(model, 15, ',');
			is >> manufacture_year;
			is.ignore(1000, ',');
			is >> price;
			is.ignore(1000, ',');
			is >> discount;
			if (discount == 'Y')
			{
				promotion = true;
			}
			else {
				promotion = false;
			}
			is.ignore();
		}
		return is;
	}

	//display(bool reset) ---> a query that displays to the screen the content of an Cars
	void Cars::display(bool reset)
	{
		//Counter ---> a left aligned field of size 2, that holds the number of times that this function has been called
		static int counter = 1;  // local-to-function variable ---> keyword:static

		//Price w/Tax  ---> a left aligned field of size 12 with 2 decimal point precision 
		double Cprice = price * g_taxrate + price;

		if (reset == 1) {
			counter = 1;
		}
		if (brand[0] != '\0')
		{
			cout.width(2);
			cout.setf(ios::left);
			cout << counter;
			cout << ". ";
			cout.width(10); //Brand is a left aligned field of size 10
			cout << brand;
			cout << "| ";
			cout.width(15); //Model is a left aligned field of size 15 
			cout << model;
			cout << "| ";
			cout.width(4); //Year is printed as is (assuming it is 4 field number).
			cout << manufacture_year;
			cout << " |";
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.width(12); //Price w/Tax is a left aligned field of size 12 with 2 decimal point precision
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << Cprice;
			cout.unsetf(ios::fixed);
			cout << "|";
			cout.setf(ios::right);

			//Special Price is a right aligned field of size 12
			//promotion ---> print the discounted price; otherwise, nothing is printed here.
			if (promotion)
			{
				cout.width(12);
				cout.precision(2);
				cout.setf(ios::fixed);
				cout << Cprice - Cprice * g_discount << endl;
				cout.unsetf(ios::fixed);
			}
			else {
				cout << endl;
			}
			cout.unsetf(ios::right);

		}
		else {
			cout.width(2);
			cout.setf(ios::left);
			cout << counter << ". No Car" << endl;
		}
		counter++;
	}

	//getStatus function ---> a query that returns if the car is new or used.
	char Cars::getStatus() {
		return status;
	}

	//Implement the rule of three
	//copy constructor
	Cars::Cars(const Cars& c) {
		*this = c;
	}

	//copy assignment operator
	Cars& Cars::operator=(const Cars& c) {
		if (this != &c) {		

			//strcpy(brand, c.brand); // p1: brand is an array, use the strcpy!!
			//p2: DMA 
			delete[] brand;
			brand = nullptr;
			brand = new char[strlen(c.brand) + 1];
			strcpy(brand, c.brand);

			strcpy(model, c.model); // model is an array, use the strcpy!!
			manufacture_year = c.manufacture_year;
			price = c.price;
			status = c.status;
			promotion = c.promotion;
		}
		return *this;
	}

	//destructor
	Cars::~Cars() {
		delete[] brand;
		brand = nullptr;
	}

	//operator bool ---> the car is new, return true; otherwise, return false.
	Cars::operator bool() const
	{
		bool flag = false;
		if (status == 'N')
		{
			flag = true;
		}
		return flag;
	}

	//istream& operator>> ---> has the same functionality as Cars::read(). ---> call the read function
	std::istream& operator>>(std::istream& is, Cars& car)
	{
		car.read(is);
		return is;
	}

	//void operator>> ---> copies in the second parameter the content of the first parameter.
	void operator>>(const Cars& car1, Cars& car2)
	{
		car2 = car1;
	}
}





