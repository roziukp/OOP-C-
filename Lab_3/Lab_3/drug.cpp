#include "drug.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
drug::drug(string cur_name, int cur_price)
{

	this->name = cur_name;
	this->price = cur_price;
}
void drug::show()
{
	cout << "\n Medical drug:" << endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
}

drug::~drug()
{
}
