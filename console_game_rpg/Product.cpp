#include "Product.h"



Product::Product()
{
}

Product::Product(string name, float price) : Item(name)
{
	this->price = price;
}

Product::~Product()
{
}

void Product::setPrice(float price) {
	this->price = price;
}

float Product::getPrice() {
	return this->price;
}
