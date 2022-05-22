#pragma once
#include "Course.h"
#include "Student.h"
#include "Student0.h"
#include "Student1.h"
#include "Student2.h"
class student1;

class College
{
private:
	Student** array_std;
	int size_std;
public:
	~College();
	College() { array_std = NULL; size_std = 0; }
	College(Student** array_student, int size); // ?? needed??
	bool add_student();
	bool add_grade(long id, char* course_name, char* lecturer, int grade); 
	void print_all()const; 
	void print_excellent()const;
	void find_types(Student** array_student, int size, int& z, int& f, int& s);
	int supervisor(char* name_super); 
	void menu(); 
};

