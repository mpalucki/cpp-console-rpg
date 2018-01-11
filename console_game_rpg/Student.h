#pragma once
#include "Person.h"
#include "Item.h"
#include <vector>

class Student :
	public Person
{
public:
	Student();
	~Student();
	Student(string name);
	bool getDrunken();
	void setDrunken(bool isDrunken);
	bool getCashOnPhone();
	void setCashOnPhone(bool cashOnPhone);
	float getCash();
	void setCash(float cash);
	void addItem(Item item); //TODO
	bool hasItem(string name); //TODO

private:
	bool isDrunken;
	float cash;
	bool cashOnPhone;
	//Item items[];  //TODO
};

