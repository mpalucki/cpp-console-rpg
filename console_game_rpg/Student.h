#pragma once
#include "Person.h"
class Student :
	public Person
{
public:
	Student();
	~Student();
	Student(string name);
	bool getDrunken();
	void setDrunken(bool isDrunken);

private:
	bool isDrunken;
};

