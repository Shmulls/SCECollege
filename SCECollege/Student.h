#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string.h>
#include "Course.h"
using namespace std;

class Student
{
protected:
	char* name;
	long id;
public:
	virtual ~Student() { delete[]name; }
	Student() { name = NULL; id = 0; }
	Student(char* name, long id);
	Student(const Student& s);
	virtual bool if_Outstanding()const = 0;
	virtual void print()const;
	void print_name()const;
	long getID()const { return id; }
	virtual const char* get_type() { return "Student"; }
};

