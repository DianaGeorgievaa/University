#pragma once
#include "Employee.h"
const int  FACULTY_GUARD_ANNUAL_SALARY_INCREASE = 150;
class FacultyGuard :public Employee
{
public:
	FacultyGuard() {};
	FacultyGuard(const std::string, const std::string, int, int, double, bool);
	~FacultyGuard() {};

	bool getEligibilityStatus()const;
	void setEligibilityStatus(bool);
	void increaseAnnualSalary()override;
	void display() const override;

private:
	bool eligibilityStatus;
};

