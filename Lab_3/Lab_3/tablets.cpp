#include "tablets.h"
#include "drug.h"
#include <string>
#include <iostream>
using namespace std;

tablets::~tablets()
{};

void tablets::show()
{
	cout << "\nMedical drug:" << endl;
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
	cout << "Price: " << price << endl;
}
