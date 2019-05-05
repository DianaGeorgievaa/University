#include "Speciality.h"

Speciality::Speciality(const std::string name, int maxNumberOfEnrolledStudents, int numberOfDisciplines, std::vector<std::string>disciplines)
{
	this->setName(name);
	this->setMaxNumberOfEnrolledStudents(maxNumberOfEnrolledStudents);
	this->setNumberOfDisciplines(numberOfDisciplines);
	this->setDisciplines(disciplines);
}
void Speciality::setName(std::string name)
{
	this->name = name;
}
void Speciality::setMaxNumberOfEnrolledStudents(int maxNumberOfEnrolledStudents)
{
	if (maxNumberOfEnrolledStudents > 0)
	{
		this->maxNumberOfEnrolledStudents = maxNumberOfEnrolledStudents;
	}
	else
	{
		std::cout << "Error! The max number of enrooled students can not be negative!" << std::endl;
	}
}
void Speciality::setNumberOfDisciplines(int numberOfDisciplines)
{
	if (numberOfDisciplines > 0)
	{
		this->numberOfDisciplines = numberOfDisciplines;
	}
	else
	{
		std::cout << "Error! The number of disciplines can not be negative!" << std::endl;
	}
}
void Speciality::setDisciplines(std::vector<std::string>disciplines)
{
	for (int i = 0; i < this->numberOfDisciplines; i++)
	{
		this->disciplines[i] = disciplines[i];
	}
}
const std::string Speciality::getName()const
{
	return this->name;
}
int Speciality::getMaxNumberOfEnrolledStudents()const
{
	return this->maxNumberOfEnrolledStudents;
}
int Speciality::getNumberOfDisciplines()const
{
	return this->numberOfDisciplines;
}
void Speciality::addDiscipline(std::string discipline)
{
	this->disciplines.push_back(discipline);
}
void Speciality::deleteDiscipline(std::string newDiscipline)
{
	std::vector<std::string>::iterator it = std::find(disciplines.begin(), disciplines.end(), newDiscipline);
	if (it != disciplines.end())
	{
		disciplines.erase(it);
	}
	else
	{
		std::cout << "Error!" << newDiscipline << " is not available in specialty" << this->getName() << std::endl;
	}
}
void Speciality::display()const
{
	std::cout << std::endl;
	std::cout << "Name of Speciality: " << this->getName() << std::endl;
	std::cout << "Max number of enrolled students: " << this->getMaxNumberOfEnrolledStudents() << std::endl;
	std::cout << "Number of disciplines: "<< this->getNumberOfDisciplines() << std::endl;
	std::cout << "Name of disciplines: ";
	for (int i = 0; i < this->numberOfDisciplines; i++)
	{
		std::cout << disciplines[i];
	}
	std::cout<<std::endl;
}