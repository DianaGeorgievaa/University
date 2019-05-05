#include "University.h"


University::University(const std::string name, int foundationYear, const std::string rectorName, int facultiesCount, int maxFacultiesCount, const Faculty* faculties)
{
	this->setName(name);
	this->foundationYear = foundationYear;
	this->setRectorName(rectorName);
	this->facultiesCount = facultiesCount;
	this->maximalFacultiesCount = maximalFacultiesCount;
	this->copyFaculties(faculties);

}
University::University(const University& other)
{
	copyUniversity(other);
}
University::~University()
{
	deleteUniversity();
}
University& University::operator=(const University& other)
{
	if (this != &other)
	{
		deleteUniversity();
		copyUniversity(other);
	}

	return *this;
}

const std::string University::getName() const
{
	return this->name;
}
int University::getFoundationYear() const
{
	return this->foundationYear;
}
const std::string University::getRectorName() const
{
	return this->rectorName;
}
int University::getFacultiesCount() const
{
	return this->facultiesCount;
}
int University::getMaximalFacultiesCount() const
{
	return this->maximalFacultiesCount;
}
Faculty* University::getFaculties() const
{
	return this->faculties;
}
Faculty University::getFaculty(const std::string  facultyName) const
{
	for (int i = 0; i < facultiesCount; i++)
	{
		if (faculties[i].getName()== facultyName) 
		{
			return faculties[i];
		}
	}

	std::cout<< "Error ! There is no faculty named " << facultyName << " !" <<std::endl;
	return Faculty();
}

void University::setName(const std::string name)
{
	this->name = name;
}
void University::setRectorName(const std::string rectorName)
{
	this->rectorName = rectorName;
}

void University::addFaculty(const Faculty& faculty)
{

	if (facultiesCount + 1 > maximalFacultiesCount)
	{
		doubleMaximalFacultiesCount();
	}
	faculties[facultiesCount++] = faculty;
}
void University::removeFaculty(const std::string facultyName)
{
	for (int i = 0; i < facultiesCount; i++)
	{
		if (faculties[i].getName()==facultyName)
		{
			shiftFaculties(i);
			facultiesCount--;
			return;
		}
	}

	std::cout<< "Error ! There is no faculty named " << facultyName << " !" <<std::endl;
}
void University::display()const
{
	std::cout <<std::endl;
	std::cout << "Name of University: " << this->getName() << std::endl;
	std::cout << "Foundation year: " << this->getFoundationYear() << std::endl;
	std::cout << "Rector name: " << this->getRectorName() << std::endl;
	std::cout << "Number of Faculties: " << this->getFacultiesCount() << std::endl;
	std::cout << "Maximal number of faculties: " << this->getMaximalFacultiesCount() << std::endl;
	std::cout << "Faculties: " << std::endl;
	for (int i = 0; i < this->getFacultiesCount(); i++)
	{
		this->faculties[i].display();
	}
	std::cout <<std::endl;
}
void University::copyUniversity(const University &other)
{
	
	this->foundationYear = other.getFoundationYear();
	this->facultiesCount = other.getFacultiesCount();
	this->maximalFacultiesCount = other.getMaximalFacultiesCount();
	copyFaculties(other.getFaculties());
}

void University::deleteUniversity()
{
	delete[] this->faculties;
}

void University::doubleMaximalFacultiesCount()
{
	Faculty* temporarySavedFaculties = faculties;
	maximalFacultiesCount *= 2;
	faculties = new Faculty[maximalFacultiesCount];
	for (int i = 0; i < maximalFacultiesCount / 2; i++)
	{
		faculties[i] = temporarySavedFaculties[i];
	}
	delete temporarySavedFaculties;
}

void University::shiftFaculties(int facultyIndex)
{
	for (int i = facultyIndex; i < facultiesCount - 1; i++)
	{
		faculties[i] = faculties[i + 1];
	}
}

void University::copyFaculties(const Faculty* faculties)
{
	this->faculties = new Faculty[this->maximalFacultiesCount];
	for (int i = 0; i < this->facultiesCount; i++)
	{
		this->faculties[i] = faculties[i];
	}
}