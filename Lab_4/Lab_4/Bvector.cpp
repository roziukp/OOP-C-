#include <iostream>
#include "Bvector.h"
using namespace std;

Bvector::Bvector(int size)
{
	this->size = size;
	arr = new bool[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}
Bvector::Bvector(Bvector &object)
{
	size = object.size;
	arr = new bool[size];
	for (int i = 0; i<size; i++)
	{
		arr[i] = object.arr[i];
	}
}
void Bvector::set_size(int size)
{
	this->size = size;
}
void Bvector::set_arr(int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Введите заначание "<<i<<": ";
		cin >> arr[i];
	}
}
int Bvector::get_size()
{
	return size;
}
bool *Bvector::get_arr()
{
		return arr;	
}
void Bvector::calculation( int  size)
{
	int x1=0, x2=0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
			x1++;
		else x2++;
	}
	cout << "\nКоличество нулей в векторе: "<<x1<<"\n";
	cout << "Количество единиц в векторе: "<< x2 << "\n";
}
void Bvector::print()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
Bvector Bvector::operator=(Bvector t)
{
	size = t.size;
	arr = new bool[size];
	for (int i = 0; i<size; i++)
	{
		arr[i] = t.arr[i];
	}
	return *this;
}

Bvector Bvector:: operator | (Bvector t) 
{
	Bvector c;
	c.size = size;
	c.arr = new bool[size];
	if (size == t.size)
	{
		for (int i = 0; i < size; i++)
		{
			c.arr[i] = (arr[i] | t.arr[i]);
		}
	}
return c;
}

Bvector Bvector::operator & (Bvector t)
{
	Bvector c;
	c.size = size;
	c.arr = new bool[size];
	if (size == t.size)
	{
		for (int i = 0; i < size; i++)
		{
			c.arr[i] = (arr[i] & t.arr[i]);
		}
	}
	return c;
}

Bvector Bvector::operator ~ ()
{
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] =!arr[i];
		}
	}
	return *this;
}
Bvector ::~Bvector()
{
		delete arr;
}