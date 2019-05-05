#include "FacultyGuard.h"



FacultyGuard::FacultyGuard(std::string name, std::string address, int birthYear, int yearsExperience, double salary, bool eligibilityStatus) :
	Employee(name, address, birthYear, yearsExperience, salary)
{
	this->setEligibilityStatus(eligibilityStatus);
}
bool FacultyGuard::getEligibilityStatus()const
{
	return this->eligibilityStatus;
}
void FacultyGuard::setEligibilityStatus(bool eligibilityStatus)
{
	this->eligibilityStatus = eligibilityStatus;
}
void FacultyGuard::increaseAnnualSalary()
{
	salary += FACULTY_GUARD_ANNUAL_SALARY_INCREASE;
}
void FacultyGuard::display()const
{
	std::cout << std::endl;
	std::cout << "Type of job: Faculty Guard" << std::endl;
	std::cout << "NAME: " << this->getName() << std::endl;
	std::cout << "ADDRESS: " << this->getAddress() << std::endl;
	std::cout << "BIRTH YEAR: " << this->getBirthYear() << std::endl;
	std::cout << "YEARS EXPERIENCE: " << this->getYearsExperience() << std::endl;
	std::cout << "ELIGIBILITY STATUS: " << this->getEligibilityStatus();
	std::cout << std::endl;
}