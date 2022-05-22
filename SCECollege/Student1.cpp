#include "Student1.h"

Student1::~Student1()
{
	delete[]array_course;
}


Student1::Student1(char* name, long id, Course* array_course, int year, int size) :Student(name, id)
{
	if (array_course != NULL)
	{
		this->array_course = new Course[size];
		for (int i = 0; i < size; i++)
		{
			this->array_course[i] = array_course[i];
		}
	}
	else
		this->array_course = NULL;

	this->year = year;
	this->size = size;

}

bool Student1::if_Outstanding()const
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += array_course[i].getGrade();
	}
	
	if ((sum / size) >= 90)
		return true;
	return false;
}

void Student1::print() const
{
	Student::print();
	cout << "Year: " << year << endl;
	cout << "Avg: " << calc_avg() << endl;
	for (int i = 0; i < size; i++)
	{
		array_course[i].print();
	}
}

void Student1::set_Course(Course* arrayc)
{
	array_course = arrayc;
}

void Student1::set_Size(int size_s)
{
	size = size_s;
}

float Student1::calc_avg()const
{
	float avg = 0;
	for (int i = 0; i < size; i++)
	{
		avg += array_course[i].getGrade();
	}

	return avg/size;
}
