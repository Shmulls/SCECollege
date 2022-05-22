#include "Student0.h"

Student0::Student0(char* name, long id, bool is_short):Student(name, id)
{
	this->is_short = is_short;
}

void Student0::print() const
{
	Student::print();
	if (is_short)
		cout << "In short period" << endl;
	else
		cout << "In long period" << endl;
}
