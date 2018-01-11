#pragma once
#include "Item.h"
class Product :
	public Item
{
public:
	Product();
	~Product();
	void setPrice(float price);
	float getPrice();

private:
	float price;
};

