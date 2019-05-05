#pragma once
#include "Faculty.h"
class University
{
public:
	University(const std::string, int, const std::string, int, int, const Faculty*);
	University(const University&);
	~University();
	University& operator=(const University&);

	const std::string getName() const;
	int getFoundationYear() const;
	const std::string getRectorName() const;
	int getFacultiesCount() const;
	int getMaximalFacultiesCount() const;
	Faculty* getFaculties() const;
	Faculty getFaculty(std::string) const;

	void setName(const std::string);
	void setRectorName(const std::string);

	void addFaculty(const Faculty&);
	void removeFaculty(const std::string);
	void display()const;

private:
	std::string name;
	int foundationYear;
	std::string rectorName;
	int facultiesCount;
	int maximalFacultiesCount;
	Faculty* faculties;

	void copyUniversity(const University&);
	void deleteUniversity();
	void doubleMaximalFacultiesCount();
	void shiftFaculties(int);
	void copyFaculties(const Faculty*);
};






