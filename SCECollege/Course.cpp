#include "Course.h"

Course::~Course()
{
	delete[]name;
	delete[]lecturer;
}

Course::Course()
{
	name = NULL;
	lecturer = NULL;
	grade = 0;

}

Course::Course(char* name, char* lecturer, int grade)
{
	
	if (name != NULL)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else
		this->name = NULL;

	if (lecturer != NULL)
	{
		this->lecturer = new char[strlen(lecturer) + 1];
		strcpy(this->lecturer, lecturer);
	}
	else
		this->lecturer = NULL;

	this->grade = grade;
}

Course::Course(const Course& c)
{
	if (&c != NULL)
	{
		name = new char[strlen(c.name) + 1];
		lecturer = new char[strlen(c.lecturer) + 1];
		strcpy(name, c.name);
		strcpy(lecturer, c.lecturer);
	}
	else
	{
		cout << "Pointer NULL cctor course" << endl;
		name = NULL;
		lecturer = NULL;
	}

	grade = c.grade;
}

void Course::set_course(char* l, int g)
{
	lecturer = new char[strlen(l) + 1];
	strcpy(lecturer, l);

	grade = g;
}

void Course::print() const
{
	cout << "Lecturer name: " << lecturer << endl << "Course name: " << name << endl << "Grade: " << grade << endl;
}

Course& Course::operator=(const Course& p)
{
	if (this != &p)
	{
		name = new char[strlen(p.name) + 1];
		lecturer = new char[strlen(p.lecturer) + 1];

		strcpy(name, p.name);
		strcpy(lecturer, p.lecturer);
		grade = p.grade;
	}
	return *this;
}
