#include "Employee.h"

Employee::Employee(const std::string name, const std::string address, int birthYear, int yearsExperience, double salary)
{
	this->setName(name);
	this->setAddress(address);
	this->setBirthYear(birthYear);
	this->setYearsExperience(yearsExperience);
	this->salary = salary;
}

const std::string Employee::getName() const
{
	return this->name;
}

const std::string Employee::getAddress() const
{
	return this->address;
}

double Employee::getSalary() const
{
	return this->salary;
}

int Employee::getBirthYear() const
{
	return this->birthYear;
}

int Employee::getYearsExperience() const
{
	return this->yearsExperience;
}

void Employee::setName(const std::string name)
{
	this->name = name;
}
void Employee::setBirthYear(int year)
{
	if (year > 0)
	{
		this->yearsExperience = year;
	}
	else
	{
		std::cout << "Error! The year can not be negative!" << std::endl;
	}
}

void Employee::setAddress(const std::string addres)
{
	this->address = addres;
}

void Employee::setYearsExperience(int yearsExperience)
{
	this->yearsExperience = yearsExperience;
}
int Employee::getCurrrentYear() const
{
	return CURRENT_YEAR;
}
int Employee::calculateAge() const
{
	return this->getCurrrentYear() - birthYear;
}


