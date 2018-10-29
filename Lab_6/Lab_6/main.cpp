#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>
#include "SkipList.h"
using namespace std;
void main()
{
	SkipList<int> A;
	int c;
	int i, counter = 1;
	do
	{
		system("cls");
		cout << "1.Add Element" << endl;
		cout << "2.Delete Element" << endl;
		cout << "3.Print List " << endl;
		cout << "4.Delete list " << endl;
		cout << "5.Exit " << endl << endl;
		cout << "Input : ";
		cin >> i;
		cout << endl;
		switch (i)
		{
		case 1:
			cout << "Input the ellement: ";
			cin >> c;
			A.input(counter, c);
			counter++;
			system("pause");
			break;
		case 2:
			cout << "Input the ellement you want to delete: ";
			int j;
			cin >> j;
			if (j > counter || j < 0)
			{
				cout << "Error,not found\n ";
				system("pause");
				break;
			}
			A.crossout(j);
			cout << "Element has been deleted" << endl;
			system("pause");
			break;
		case 3:
			cout << "List: \n";
			A.print();
			system("pause");
			break;
		case 4:
			A.delete_list();
			cout << " The list has been deleted " << endl;
			system("pause");
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << "Error" << endl;
			system("pause");
		}
	} while (1);
	system("pause");
}
