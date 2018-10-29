#include "File.h"
#include "arr.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void main()
{
	string c;
	arr *a1 = new arr();
	a1->print();
	a1->Size();
	a1->Name();
	a1->Dateout("27.02.17");
	_getch();
}