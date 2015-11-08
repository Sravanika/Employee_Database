#include "Employee.h"
#include <iostream>

using namespace std;
// TODO: Part 1. Debug the following constructor that takes a line
//       in the format similar to "2014.cvs" and populates an Employee object
//       You may need to fix multiple lines
Employee::Employee(std::string lineFromFile)
{
	std::string tempString = lineFromFile;
	int foundFirst = tempString.find_first_of("\"");
	int foundLast = tempString.find_first_of("\"",1);
	name_ = tempString.substr(foundFirst + 1, foundLast - foundFirst -1);
   // std::cout << " name: " << name_ << std::endl;
	tempString = tempString.substr(foundFirst + 1 + foundLast);

	int	foundStatus = tempString.find_first_of(",",1); // Skipiing the next ,
	status_ = tempString.substr(1, foundStatus-1);
    //std::cout << " status: " << status_ << std::endl;

	tempString = tempString.substr(foundStatus + 1);

	int	foundSalary = tempString.find_first_of(",");
	std::string salaryStr = tempString.substr(0, foundSalary-1);
	salary_ = atof(salaryStr.erase(0,1).c_str());// Getting rid of $

    //std::cout << " salary: " << salary_ << std::endl;

	tempString = tempString.substr(foundSalary + 1);

	int	foundPayBasis = tempString.find_first_of(",");
	payBasis_ = tempString.substr(0, foundPayBasis);

	 //std::cout << " paybasis: " << payBasis_ << std::endl;

	tempString = tempString.substr(foundPayBasis + 1);

	positionTitle_ = tempString;

	// std::cout << " position title: " << positionTitle_ << std::endl;
}
Employee::Employee():name_(""),
status_(""),
salary_(0),
payBasis_(""),
positionTitle_("")
{}

void Employee::setField(DATA_FIELDS dataField, std::string value)
{
   // Replace '_' by space
   std::replace(value.begin(), value.end(), '_', ' '); // replace all '_' to ' ' (space)

   switch (dataField)
   {
      case NAME:
         name_ = value;
         break;
      case STATUS:
         status_ = value;
         break;
      case SALARY:
         salary_ = atof(value.c_str());
         break;
      case PAY_BASIS:
         payBasis_ = value;
         break;
      case POSITION:
         positionTitle_ = value;
         break;
   }
}

std::ostream& operator<<(std::ostream &strm, const Employee &emp) {
	std::ostringstream oss;
	oss << std::left << std::setw(30) << emp.name_ << " ";
	oss << std::left << std::setw(10) << emp.status_ << " ";
	oss << std::right << std::setw(10) << emp.salary_ << " ";
	oss << std::left << std::setw(10) << emp.payBasis_ << " ";
	oss << std::left << std::setw(10) << emp.positionTitle_ << std::endl;
	return strm << oss.str();
}

std::string getEmployeeFileHeader()
{
   std::string str = "";
   str += "Name                           Status         Salary Pay Basis  Position Title\n";
   str += "====================================================================================================================================\n";
   return str;
}
