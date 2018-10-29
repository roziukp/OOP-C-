#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class File
{
private:
	char *name, *date;
	int  number, size;
public:
	void printdata();
	// створення конструктора
	File(char *curname, char *curdate, int cursize, int curnumber);

	//set
	void set_name(char *curname);
	void set_date(char *curdate);
	void set_size(int cursize);
	void set_number(int curnumber);
	//get
	string get_name();
	string get_date();
	int get_size();
	int get_number();
	~File();
};
