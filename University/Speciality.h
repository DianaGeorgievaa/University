#pragma once
#include <string>
#include<vector>
#include <algorithm>
#include <iostream>
class Speciality
{
public:
	Speciality() {};
	Speciality(const std::string, int, int, std::vector<std::string>);
	~Speciality() {};

	void setName(const std::string);
	void setMaxNumberOfEnrolledStudents(int);
	void setNumberOfDisciplines(int);
	void setDisciplines(std::vector<std::string>discilines);

	const std::string getName()const;
	int getMaxNumberOfEnrolledStudents()const;
	int getNumberOfDisciplines()const;

	void addDiscipline(const std::string);
	void deleteDiscipline(const std::string);
	void display()const;
private:
	std::string name;
	int maxNumberOfEnrolledStudents;
	int numberOfDisciplines;
	std::vector<std::string>disciplines;
};







