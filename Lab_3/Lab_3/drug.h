#pragma once
#include <iostream>
using namespace std;
class drug
{
protected:
	string name;
	int	price;
public:
	drug() {};
	drug(string cur_name, int cur_price);
	virtual void show();

	~drug();
};
