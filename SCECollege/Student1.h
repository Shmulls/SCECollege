#pragma once
#include "Student.h"
#include "Course.h"
class Course;

class Student1 : public Student
{
private:
	Course* array_course;
	int year, size;
public:
	~Student1();
	Student1(char* name, long id, Course* array_course, int year, int size);
	bool if_Outstanding()const;
	void print()const;
	void set_Course(Course* arrayc);
	void set_Size(int size_s);
	Course* getCourse()const { return array_course; }
	int getSize()const { return size; }
	float calc_avg()const;
	virtual const char* get_type() { return "Student1"; }
};

