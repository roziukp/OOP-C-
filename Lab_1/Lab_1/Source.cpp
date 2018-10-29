#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;

class File
{
private:
	char *name, *date, *size;
	int  number;
public:
	void printdata()
	{
		cout << "Description of the file:\n";
		cout << name << endl;
		cout << date << endl;
		cout << size << endl;
		cout << number << endl;
	}
	// створення конструктора
	File(char *curname, char *curdate, char *cursize, int curnumber) :
		name(curname), date(curdate), size(curdate), number(curnumber)
	{
		int n = strlen(curname);
		int z = strlen(curdate);
		int g = strlen(cursize);

		name = new char[n];
		date = new char[z];
		size = new char[g];

		strcpy(name, curname);
		strcpy(date, curdate);
		strcpy(size, cursize);
		number = curnumber;
	}
	//set

	void set_name(char *curname)
	{
		strcpy(name, curname);
	};
	void set_date(char *curdate)
	{
		strcpy(date, curdate);
	};
	void set_size(char *cursize)
	{
		strcpy(size, cursize);
	};
	void set_number(int curnumber)
	{
		number = curnumber;
	};
	//get
	char *get_name() { return name; };
	char *get_date() { return date; };
	char *get_size() { return size; };
	int get_number() { return number; }
	~File()
	{
		delete name; delete date; delete size;
	}
};
void main()
{
	int a, b, x, g;
	char *q, *w, *e, *k, *d, *z;
	q = new char[20];
	w = new char[20];
	e = new char[20];
	setlocale(LC_CTYPE, "rus");
	File objc1("File_1", "25.02.15", "135 Mb", 5);
	objc1.printdata();
	cout << "If you want to change data of the file press 1, no - 0:\n";
	cin >> a;
	if (a == 1)
	{
		cout << "Input what do you want to change in file: name-1, date-2, size-3, number of calls-4:";
		cin >> g;
		switch (g)
		{
		case 1:
			cout << "\nInput new name:\n";
			cin >> q;
			objc1.set_name(q); break;
		case 2:
			cout << "\nInput new date:\n";
			cin >> w;
			objc1.set_date(w); break;
		case 3:
			cout << "\nInput new size:\n";
			cin >> e;
			objc1.set_size(e); break;
		case 4:
			cout << "\nInput new number of calls:\n";
			cin >> b;
			objc1.set_number(b); break;
		default: cout << "Sorry,but you have entered the number which is not in this list";
		}
	}
	cout << "\nNew data:\n";
	k = objc1.get_name();
	z = objc1.get_date();
	d = objc1.get_size();
	x = objc1.get_number();
	cout << k << endl; cout << z << endl; cout << d << endl; cout << x << endl;

	system("pause");
	_getch();
}