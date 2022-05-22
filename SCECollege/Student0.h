#pragma once
#include "Student.h"

class Student0 : public Student
{
private:
	bool is_short;
public:
	~Student0() { cout << "Student0 dctor" << endl; }
	Student0(char* name, long id, bool is_short);
	bool if_Outstanding()const { return false; }
	void print()const;
	bool getShort()const { return is_short; }
	virtual const char* get_type() { return "Student0"; }
 };

