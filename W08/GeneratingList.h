/***********************************************************************
// OOP345 Workshop 8:
// File	GeneratingList.h
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
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the valadity of SIN No's
		bool checkLuhn(const std::string& SIN) {
			int newSin = SIN.length();
			int sum = 0, result = false;
			for (int i = newSin - 1; i >= 0; i--) {  
				int d = SIN[i] - '0';
				if (result == true)
					d = d * 2;    
				sum += d / 10;   
				sum += d % 10;   
				result = !result;   
			}
			return (sum % 10 == 0);
		}

		//TODO: Overload the += operator with a smart pointer as a second operand.
		void operator+=(const std::shared_ptr<T>& ptr) {
			list.push_back(*ptr);
		}

		//TODO: Overload the += operator with a raw pointer as a second operand.
		void operator+=(const T&& ptr) {
			list.push_back(std::move(ptr));
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
