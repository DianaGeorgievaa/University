#include "Lecturer.h"

Lecturer::Lecturer(const std::string name, const std::string address, int birthYear, int yearsExperience, double salary, const std::string academicRank) :
	Employee(name, address, birthYear, yearsExperience, salary)
{
	this->setAcademicRank(academicRank);
}
const std::string Lecturer::getAcademicRank()const
{
	return this->academicRank;
}
void Lecturer::setAcademicRank(std::string academicRank)
{
	this->academicRank = academicRank;
}
void Lecturer::increaseAnnualSalary()
{
	salary += LECTURER_ANNUAL_SALARY_INCREASE;
}
void Lecturer::display()const
{
	std::cout << std::endl;
	std::cout << "Type of job: Lecturer" << std::endl;
	std::cout << "NAME: " << this->getName() << std::endl;
	std::cout << "ADDRESS: " << this->getAddress () <<std::endl;
	std::cout << "BIRTH YEAR: " << this->getBirthYear() << std::endl;
	std::cout << "YEARS EXPERIENCE: " << this->getYearsExperience() << std::endl;
	std::cout << "ACADEMIC RANK: " << this->getAcademicRank();
	std::cout << std::endl;
}