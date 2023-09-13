/***********************************************************************
// OOP345 Workshop 8:
// File	Writingecord.cpp
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
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees using raw pointers
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					EmployeeWage* temp = new EmployeeWage(emp[i].name, sal[j].salary);
					try {
						temp->rangeValidator();
					}
					catch (...) {
						delete temp;
						throw std::string("*** Employees salaray range is not valid");
					}
					if (!activeEmp.checkLuhn(sal[j].id)) {
						delete temp;
						throw std::string("*** SIN is not valid");
					}
					activeEmp += move(*temp);
					delete temp;
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees using smart pointers
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					std::shared_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));  
					try {
						temp->rangeValidator();
					}
					catch (...) {
						throw std::string("*** Employees salaray range is not valid");
					}
					if (!activeEmp.checkLuhn(sal[j].id)) {
						throw std::string("*** SIN is not valid");
					}
					activeEmp += move(temp);
				}
			}
		}
		return activeEmp;
	}
}