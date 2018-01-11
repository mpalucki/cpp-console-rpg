#include "Item.h"



Item::Item()
{
}

Item::Item(string name)
{
	this->name = name;
}


Item::~Item()
{
}

void Item::setName(string name) {
	this->name = name;
}

string Item::getName() {
	return this->name;
}
