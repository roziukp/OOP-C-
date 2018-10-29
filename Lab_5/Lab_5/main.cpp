#include <iostream>
#include "List.h"
using namespace std;
void main()
{
	SkipList<int> A;
	int k, x;
	while (1)
	{
		system("cls");
		cout << "1.Add Element" << endl;
		cout << "2.Delete Element" << endl;
		cout << "3.Search Element" << endl;
		cout << "4.Print List " << endl;
		cout << "5.Delete list " << endl;
		cout << "6.Exit " << endl << endl;
		cout << "Input your choice : ";
		cin >> k;
		cout << endl;
		switch (k)
		{
		case 1:
			cout << "Input the element: ";
			cin >> x;
			A.AddElement(x);
			if (A.Number_elements(x))
			system("pause");
			break;
		case 2:
			cout << "Input the element: ";
			cin >> x;
			if (!A.Number_elements(x))
			{
				cout << "Element not found" << endl;
				system("pause");
				break;
			}
			A.Delete(x);
			if (!A.Number_elements(x))
				cout << "Element has been deleted!" << endl;
			system("pause");
			break;
		case 3:
			cout << "Input the element to search: ";
			cin >> x;
			if (A.Number_elements(x))
				cout << "Element " << x << " is in the list" << endl;
			else
				cout << "Element not found" << endl;
			system("pause");
		case 4:
			A.Print();
			system("pause");
			break;
		case 5:
			A.DeleteSkipList();
			cout << " The list has been deleted " << endl;
			system("pause");
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "Error" << endl;
			system("pause");
		}
	}
}
