#include "Bvector.h"
#include <iostream>
#include <conio.h>
using namespace std;
void vector(int size,Bvector C)
{
	cout << "Заполните значениями вектор A: ";
	Bvector A(size);
	A.calculation(size);
	cout << "\nЗаполните значениями вектор B: ";
	Bvector B(size);
	B.calculation(size);
	cout << "\nДизъюнкция векторов А и В: ";
	C = A | B;
	C.print();
	cout << "Конъюнкция векторов А и В: ";
	C = A & B;
	C.print();
	cout << "Инверсия A: ";
	C = ~A;
	C.print();
}
void main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "Введите значение длины вектора: ";
	cin >> size;
	Bvector C;
	vector(size, C);
	_getch();
}