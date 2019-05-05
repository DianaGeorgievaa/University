#pragma once
#include<iostream>
#include<string>

const int CURRENT_YEAR = 2019;

class Employee
{
public:
	Employee() {};
	Employee(const std::string, const std::string, int, int, double);
	~Employee() {};

	const std::string getName() const;
	const std::string getAddress() const;
	int getBirthYear() const;
	int getYearsExperience() const;
	double getSalary() const;

	void setName(const std::string);
	void setAddress(const std::string);
	void setBirthYear(int);
	void setYearsExperience(int);


	int calculateAge() const;
	int getCurrrentYear()const;
	virtual void display()const = 0;
	virtual void increaseAnnualSalary() = 0;

protected:
	double salary;

private:
	std::string name;
	std::string address;
	int birthYear;
	int yearsExperience;
};

