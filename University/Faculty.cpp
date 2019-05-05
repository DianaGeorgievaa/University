#include "Faculty.h"

const int  MAX_LECTURERS_COUNT = 300;
const int MAX_FACULTY_GUARDS_COUNT = 50;
const int MAX_SPECIALITIES_COUNT = 50;

Faculty::Faculty(const std::string name, int lecturersCount, int facultyGuardsCount, int specialitiesCount, Lecturer* lecturers,
	FacultyGuard* facultyGuards, Speciality* specialities)
{
	this->setName(name);
	this->lecturersCount = lecturersCount;
	this->facultyGuardsCount = facultyGuardsCount;
	this->specialitiesCount = specialitiesCount;
	this->setLecturers(lecturersCount,lecturers);
	this->setSpecialities(specialitiesCount,specialities);
	this->setFacultyGuards(facultyGuardsCount,facultyGuards);

}

Faculty::Faculty(const Faculty &other)
{
	copyFaculty(other);
}

Faculty::~Faculty()
{
	deleteFaculty();
}

Faculty & Faculty :: operator=(const Faculty &other)
{
	if (this != &other)
	{
		deleteFaculty();
		copyFaculty(other);
	}

	return *this;
}

const std::string Faculty::getName() const
{
	return this->name;
}

int Faculty::getLecturersCount() const
{
	return this->lecturersCount;
}

int Faculty::getFacultyGuardsCount() const
{
	return this->facultyGuardsCount;
}

int Faculty::getSpecialitiesCount() const
{
	return this->specialitiesCount;
}

Lecturer* Faculty::getLecturers() const
{
	return this->lecturers;
}

FacultyGuard* Faculty::getFacultyGuards() const
{
	return this-> facultyGuards;
}

Speciality* Faculty::getSpecialities() const
{
	return this->specialities;
}

void Faculty::setName(const std::string name)
{
	this->name = name;
}

void Faculty::setLecturers(int lecturersCount, const Lecturer* lecturers)
{
	if (lecturersCount <= 0)
	{
		std::cout << "Error ! The faculty can not have zero or negative number of lecturers !" << std::endl;
		return;
	}

	delete[] this->lecturers;
	this->lecturersCount = lecturersCount;
	copyLecturers(this->lecturers, lecturers, lecturersCount);
}

void Faculty::setFacultyGuards(int facultyGuardsCount, const FacultyGuard* facultyGuards)
{
	if (facultyGuardsCount <= 0)
	{
		std::cout << "Error ! The number of faculty guards can not be negative or zero !" << std::endl;
		return;
	}

	delete[] this->facultyGuards;
	this->facultyGuardsCount = facultyGuardsCount;
	copyFacultyGuards(this->facultyGuards, facultyGuards, facultyGuardsCount);
}

void Faculty::setSpecialities(int specialititesCount, const Speciality* specialitites)
{
	if (specialititesCount <= 0)
	{
		std::cout << "Error ! The number of specialities can not be negative or zero !" << std::endl;
		return;
	}

	delete[] this->specialities;
	this->specialitiesCount = specialititesCount;
	copySpecialities(this->specialities, specialitites, specialititesCount);
}

void Faculty::addLecturer(const Lecturer &lecturer)
{
	if (lecturersCount + 1 > MAX_LECTURERS_COUNT)
	{
		std::cout << "Error ! Can not have more than " << MAX_LECTURERS_COUNT << " lecturers in the faculty !" << std::endl;
		return;
	}

	lecturers[lecturersCount++] = lecturer;
}

void Faculty::addFacultyGuard(const FacultyGuard &facultyGuard)
{
	if (facultyGuardsCount + 1 > MAX_FACULTY_GUARDS_COUNT)
	{
		std::cout << "Error ! Can not have more than " << MAX_FACULTY_GUARDS_COUNT << " faculty guards in the faculty !" <<std::endl;
		return;
	}

	facultyGuards[facultyGuardsCount++] = facultyGuard;
}
void Faculty::addSpeciality(const Speciality &speciality)
{
	if (specialitiesCount + 1 > MAX_SPECIALITIES_COUNT)
	{
		std::cout << "Error ! Can not have more than " << MAX_SPECIALITIES_COUNT << " specialities in the faculty !" <<std:: endl;
		return;
	}

	specialities[specialitiesCount++] = speciality;
}

void Faculty::removeLecturer(const std::string lecturerName)
{
	for (int i = 0; i < this->lecturersCount; i++)
	{
		if (lecturers[i].getName()==lecturerName)
		{
			shiftLecturers(i);
			lecturersCount--;
			return;
		}
	}

	std::cout << "Error ! There is no lecturer named " << lecturerName << " !" << std::endl;
}

void Faculty::removeFacultyGuard(const std::string facultyGuardName)
{
	for (int i = 0; i < facultyGuardsCount; i++)
	{
		if (facultyGuards[i].getName()==facultyGuardName)
		{
			shiftFacultyGuards(i);
			facultyGuardsCount--;
			return;
		}
	}

	std::cout<< "Error ! There is no faculty guard named " << facultyGuardName << " !" << std:: endl;
}

void Faculty::removeSpeciality(const std::string specialityName)
{
	for (int i = 0; i < specialitiesCount;i++)
	{
		if (specialities[i].getName()==specialityName)
		{
			shiftSpecialities(i);
			specialitiesCount--;
			return;
		}
	}

	std::cout << "Error ! There is no speciality named " << specialityName << " !" << std::endl;
}
void Faculty::display()const
{
	std::cout <<std::endl;
	std::cout << "Name of Faculty: " << this->getName() << std::endl;
	std::cout << "Number of lecturers: " << this->getLecturersCount() << std::endl;
	std::cout << "Number of faculty guards: " << this->getFacultyGuardsCount() << std::endl;
	std::cout << "Number of specialities: " << this->getSpecialitiesCount() << std::endl;
	std::cout << "Lecturers: " << std::endl;
	for (int i = 0; i < this->getLecturersCount(); i++)
	{
		this->lecturers[i].display();
	}
	for (int i = 0; i < this->getFacultyGuardsCount(); i++)
	{
		this->facultyGuards[i].display();
	}
	for (int i = 0; i < this->getSpecialitiesCount(); i++)
	{
		this->specialities[i].display();
	}
	std::cout << std::endl;
	
}

void Faculty::copyFaculty(const Faculty &other)
{

	this->lecturersCount = other.lecturersCount;
	this->facultyGuardsCount = other.getFacultyGuardsCount();
	this->specialitiesCount = other.getSpecialitiesCount();
	copyLecturers(lecturers, other.getLecturers(), other.getLecturersCount());
	copyFacultyGuards(facultyGuards, other.getFacultyGuards(), other.getFacultyGuardsCount());
	copySpecialities(specialities, other.getSpecialities(), other.getSpecialitiesCount());
}

void Faculty::deleteFaculty()
{
	delete[] this->lecturers;
	delete[] this->facultyGuards;
	delete[] this->specialities;
}

void Faculty::copyLecturers(Lecturer* &copyTo, const Lecturer* copyFrom, int lecturersCount)
{
	copyTo = new Lecturer[MAX_LECTURERS_COUNT];
	for (int i = 0; i < lecturersCount; i++)
	{
		copyTo[i] = copyFrom[i];
	}
}

void Faculty::copyFacultyGuards(FacultyGuard* &copyTo, const FacultyGuard* copyFrom, int facultyGuardsCount)
{
	copyTo= new FacultyGuard[MAX_FACULTY_GUARDS_COUNT];

	for (int i = 0; i < facultyGuardsCount; i++)
	{
		copyTo[i] =copyFrom[i];
	}
}

void Faculty::copySpecialities(Speciality* &copyTo, const Speciality* copyFrom, int specialitiesCount)
{
	copyTo = new Speciality[MAX_SPECIALITIES_COUNT];
	for (int i = 0; i < specialitiesCount; i++)
	{
		copyTo[i] = copyFrom[i];
	}
}

void Faculty::shiftLecturers(int lecturerIndex)
{
	for (int i = lecturerIndex; i < lecturersCount - 1; i++)
	{
		lecturers[i] = lecturers[i + 1];
	}
}

void Faculty::shiftFacultyGuards(int facultyGuardIndex)
{
	for (int i = facultyGuardIndex; i < facultyGuardsCount - 1; i++)
	{
		facultyGuards[i] = facultyGuards[i + 1];
	}
}

void Faculty::shiftSpecialities(int specialityIndex)
{
	for (int i = specialityIndex; i < specialitiesCount - 1; i++)
	{
		specialities[i] = specialities[i + 1];
	}
}

