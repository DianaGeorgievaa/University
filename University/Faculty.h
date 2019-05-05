#pragma once
#include "Lecturer.h"
#include "FacultyGuard.h"
#include "Speciality.h"

class Faculty
{
public:
	Faculty() {};
	Faculty(const std::string, int, int, int, Lecturer*, FacultyGuard*, Speciality*);
	~Faculty();
	Faculty(const Faculty &);
	Faculty & operator=(const Faculty &);

	const std::string getName() const;
	int getLecturersCount() const;
	int getFacultyGuardsCount() const;
	int getSpecialitiesCount() const;
	Lecturer* getLecturers() const;
	FacultyGuard* getFacultyGuards() const;
	Speciality* getSpecialities() const;

	void setName(const std::string);
	void setLecturers(int, const Lecturer*);
	void setFacultyGuards(int, const FacultyGuard*);
	void setSpecialities(int, const Speciality*);

	void addLecturer(const Lecturer&);
	void addFacultyGuard(const FacultyGuard&);
	void addSpeciality(const Speciality&);
	void removeLecturer(const std::string);
	void removeFacultyGuard(const std::string);
	void removeSpeciality(const std::string);
	void display()const;
private:

	std::string name;
	int lecturersCount;
	int facultyGuardsCount;
	int specialitiesCount;

	Lecturer* lecturers;
	FacultyGuard* facultyGuards;
	Speciality* specialities;

	void copyFaculty(const Faculty&);
	void deleteFaculty();
	void copyLecturers(Lecturer*&, const Lecturer*, int);
	void copyFacultyGuards(FacultyGuard*&, const FacultyGuard*, int);
	void copySpecialities(Speciality*&, const Speciality*, int);
	void shiftLecturers(int);
	void shiftFacultyGuards(int);
	void shiftSpecialities(int);
};

