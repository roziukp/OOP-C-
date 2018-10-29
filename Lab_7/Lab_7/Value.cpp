#include <iostream>
#include <fenv.h>
#include "Value.h"
using namespace std;

Value::Value(double a)
{
	this->a = a;
	double result;
	result = a*a;
	multiplication(result);
}

void Value::multiplication(double result)
{
	try
	{
		if (result = fetestexcept(FE_OVERFLOW))
			throw 1;
		else
			cout << a << " * " << a << " = " << a*a<<endl;
	}
	catch (int i)
	{
		cout << a << " * " << a << " = " << "Error "<<i<<", overflow!" <<"\n\n";
	}
}