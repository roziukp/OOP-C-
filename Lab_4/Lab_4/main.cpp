#include "Bvector.h"
#include <iostream>
#include <conio.h>
using namespace std;
void vector(int size,Bvector C)
{
	cout << "��������� ���������� ������ A: ";
	Bvector A(size);
	A.calculation(size);
	cout << "\n��������� ���������� ������ B: ";
	Bvector B(size);
	B.calculation(size);
	cout << "\n���������� �������� � � �: ";
	C = A | B;
	C.print();
	cout << "���������� �������� � � �: ";
	C = A & B;
	C.print();
	cout << "�������� A: ";
	C = ~A;
	C.print();
}
void main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "������� �������� ����� �������: ";
	cin >> size;
	Bvector C;
	vector(size, C);
	_getch();
}