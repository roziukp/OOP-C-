#include "arr.h"
#include "File.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;
arr::arr()
{
	a[0] = new File("File_1", "25.02.15", 135, 5);
	a[1] = new File("File_2", "17.03.15", 125, 54);
	a[2] = new File("doc_3", "28.05.16", 150, 55);
	a[3] = new File("doc_4", "27.02.17", 115, 4);
}

void arr::Size()
{
	int k, b;
	cout << "Input size of the file:";
	cin >> b;
	for (int i = 0; i < 4; i++)
	{
		k = a[i]->get_size();
		if (b<k)
		{
			cout << "Data of the file " << i + 1 << ":\n";
			printf("%s\n", a[i]->get_name().c_str());
			printf("%s\n", a[i]->get_date().c_str());
			cout << a[i]->get_size() << " Mb" << endl;
			cout << a[i]->get_number() << "\n\n";
		}

	}
}
void arr::Name()
{
	char *b;
	string c;
	b = new char[256];
	cout << "Input first character of the file:";
	cin >> b;

	for (int i = 0; i < 4; i++)
	{
		c = a[i]->get_name();
		if (c[0] == *b)
		{
			printf("%s\n\n", a[i]->get_name().c_str());
		}
	}
	delete[]b;
}
void arr::print()
{
	for (int i = 0; i < 4; i++)
	{
		cout << "Data of the file " << i + 1 << ":\n";
		printf("%s\n", a[i]->get_name().c_str());
		printf("%s\n", a[i]->get_date().c_str());
		cout << a[i]->get_size() << " Mb" << endl;
		cout << a[i]->get_number() << "\n\n";
	}
}
void arr::Dateout(string b)
{
	for (int i = 0; i < 4; i++)
	{
		if (b == a[i]->get_date())
		{
			cout << "Data of the file " << i + 1 << ":\n";
			printf("%s\n", a[i]->get_name().c_str());
			printf("%s\n", a[i]->get_date().c_str());
			cout << a[i]->get_size() << " Mb" << endl;
			cout << a[i]->get_number() << "\n\n";
		}
	}

}

