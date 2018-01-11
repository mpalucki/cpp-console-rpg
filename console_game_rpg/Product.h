#pragma once
#include "Item.h"
#include <string>

using namespace std;

class Product :
	public Item
{
public:
	Product();
	Product(string name, float price);
	~Product();
	void setPrice(float price);
	float getPrice();

private:
	float price;
};

