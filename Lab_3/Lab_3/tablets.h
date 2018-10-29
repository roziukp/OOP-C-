#pragma once
#include "drug.h"

class tablets :public drug
{
protected:
	int number;
public:
	tablets() {};
	tablets(int cur_number, string name, int price) :drug(name, price)
	{
		this->number = cur_number;
	};
	void show();
	~tablets();

};
