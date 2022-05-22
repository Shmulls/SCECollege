#include "Student2.h"

Student2::Student2(char* name, long id, char* thsis, char* supervisor):Student(name, id)
{
	this->thsis = new char[strlen(thsis) + 1];
	strcpy(this->thsis,thsis);
	this->supervisor = new char[strlen(supervisor) + 1];
	strcpy(this->supervisor, supervisor);
}

void Student2::print() const
{
	Student::print();
	cout << thsis << "," << supervisor << endl;
}
