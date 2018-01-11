#include "Person.h"



Person::Person()
{
}

Person::Person(string name)
{
	this->name = name;
}


Person::~Person()
{
}

void Person::setName(string name) {
	this->name = name;
}

string Person::getName() {
	return this->name;
}

void Person::setAge(int age) {
	this->age = age;
}

int Person::getAge() {
	return this->age;
}
