#pragma once
#include "Student.h"
class Student2 : public Student
{
private:
	char* thsis, *supervisor;
public:
	~Student2() { cout << "Student2 dctor" << endl; }
	Student2(char* name, long id, char* thsis, char* supervisor);
	bool if_Outstanding()const { return true; }
	void print()const;
	char* getSuper()const { return supervisor; }
	virtual const char* get_type() { return "Student2"; }
};

