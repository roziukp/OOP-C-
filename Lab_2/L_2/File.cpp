#include "File.h"
#include <string.h>
File::File(char *curname, char *curdate, int cursize, int curnumber)
{
	int n = strlen(curname);
	int z = strlen(curdate);

	name = new char[n];
	date = new char[z];

	this->name = strcpy(name, curname);
	this->date = strcpy(date, curdate);
	this->size = cursize;
	this->number = curnumber;
}
void File::set_name(char *curname)
{
	name = new char[256];
	this->name = strcpy(name, curname);
};
void File::set_date(char *curdate)
{
	date = new char[256];
	this->date = strcpy(date, curdate);
};
void File::set_size(int cursize)
{
	this->size = cursize;
};
void File::set_number(int curnumber)
{
	this->number = curnumber;
};
string File::get_date() { return date; };
string File::get_name() { return name; };
int File::get_size() { return size; };
int File::get_number() { return number; }
File :: ~File()
{
	delete[] name;
	delete[] date;
}