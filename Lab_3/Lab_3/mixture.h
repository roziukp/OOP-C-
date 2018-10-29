#pragma once
#include "drug.h"
class mixture :public drug
{
protected:
	int size;
public:
	mixture() {};
	mixture(int cur_size, string name, int price) :drug(name, price)
	{
		this->size = cur_size;
	}
	void show();
	~mixture() {};

};
