#pragma once
#include <string>

using namespace std;

class Person
{
public:
	Person();
	~Person();
	void setName(string name);
	string getName();
	void setAge(int age);
	int getAge();

private:
	string name;
	int age;
};

