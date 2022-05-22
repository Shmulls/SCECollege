#include "Student.h"

Student::Student(char* name, long id)
{
	if (name != NULL)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else
		this->name = NULL;

	this->id = id;
}

Student::Student(const Student& s)
{
	if (&s != NULL)
	{
		name = new char[strlen(s.name) + 1];
		strcpy(name, s.name);
		id = s.id;
	}
	else
	{
		cout << "cctor is null student." << endl;
		name = NULL;
		id = 0;
	}
}


void Student::print() const
{
	cout << name << ", " << id << endl;
}

void Student::print_name() const
{
	cout << name << endl;
}
