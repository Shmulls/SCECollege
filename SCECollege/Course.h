#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Course
{
private:
	char* name, * lecturer;
	int grade;
public:
	~Course();
	Course();
	Course(char* name, char* lecturer, int grade);
	Course(const Course& c);
	void set_course(char* lecturer, int grade);
	virtual void print()const;
	int getGrade()const { return grade; }
	char* getLecturer()const { return lecturer; }
	char* getCourseName()const { return name; }
	Course& operator= (const Course& p);
};

