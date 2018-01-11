#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	Item();
	Item(string name);
	~Item();
	void setName(string name);
	string getName();

private:
	string name;
};

