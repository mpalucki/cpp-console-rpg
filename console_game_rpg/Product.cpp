#include "Product.h"



Product::Product()
{
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
