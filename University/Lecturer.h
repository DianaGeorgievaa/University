#pragma once
#include "Employee.h"

const int LECTURER_ANNUAL_SALARY_INCREASE = 200;

class Lecturer :public Employee
{
public:
	Lecturer() {};
	Lecturer(const std::string, const std::string, int, int, double, const std::string);
	~Lecturer() {};

	const std::string getAcademicRank() const;
	void setAcademicRank(const std::string);

	void increaseAnnualSalary()override;
	void display() const override;

private:
	std::string academicRank;
};

