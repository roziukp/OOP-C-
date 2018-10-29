#include "drug.h"
#include "mixture.h"
#include "tablets.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void input(string *name, int *price)
{
	cout << "Name: ";
	cin >> *name;
	cout << "Price: ";
	cin >> *price;
}

void objects(drug *obj[], int n)
{
	string name;
	int price, number, size, a;
	for (int i = 0; i < n; i++)
	{
		cout << "Do you want input data of tablets-1, or mixture-2: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			input(&name, &price);
			cout << "Number: ";
			cin >> number;
			obj[i] = new tablets(number, name, price);
			break;
		}
		case 2:
		{
			input(&name, &price);
			cout << "Size: ";
			cin >> size;
			obj[i] = new mixture(size, name, price);
			break;
		}
		}
	}
}

void main(int argc, const char * argv[])
{
	const int n = 2;
	drug *obj[n];
	objects(obj, n);
	for (int i = 0; i < n; i++)
		obj[i]->show();
	for (int i = 0; i < n; i++)
		delete obj[i];
	_getch();
}