#include "Student.h"



Student::Student()
{
}

Student::Student(string name) : Person::Person(name)
{
	this->cash = 10.0;
	this->cashOnPhone = false;
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

bool Student::getCashOnPhone() {
	return this->cashOnPhone;
}

void Student::setCashOnPhone(bool cashOnPhone) {
	this->cashOnPhone = cashOnPhone;
}

float Student::getCash() {
	return this->cash;
}

void Student::setCash(float cash)
{
	this->cash = cash;
}


void Student::addItem(Item item)
{
	//TODO
}

bool Student::hasItem(string name) {
	return true; //TODO
}
