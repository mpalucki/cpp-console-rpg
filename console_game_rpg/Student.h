#pragma once
#include "Person.h"
class Student :
	public Person
{
public:
	Student();
	~Student();
	bool getDrunken();
	void setDrunken(bool isDrunken);

private:
	bool isDrunken;
};

