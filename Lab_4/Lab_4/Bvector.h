#pragma once
#include <iostream>
using namespace std;
class Bvector
{
private:
	bool *arr;
	int size;
public:
	Bvector() {};
	Bvector(int size);
	Bvector(Bvector &object);
	void set_size(int size);
	void set_arr(int size);
	int get_size();
	bool *get_arr();
	void calculation(int);
	void print();
	Bvector operator = (Bvector);
	Bvector operator | (Bvector);// диз'юнкція
	Bvector operator & (Bvector);//кон'юнкція
	Bvector operator ~ ();// інверсія
	~Bvector();
};