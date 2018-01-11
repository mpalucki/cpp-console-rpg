#include "Student.h"



Student::Student()
{
}

Student::Student(string name) : Person::Person(name)
{
}


Student::~Student()
{
}

bool Student::getDrunken() {
	return this->isDrunken;
}

void Student::setDrunken(bool isDrunken) {
	this->isDrunken = isDrunken;
}
