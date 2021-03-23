// Source.cpp
// Конструктори та перевантаження операцій для класів
// Михайлов Олександр
// Варіант 19

#include "Fraction.h"
#include <iostream>

int main()
{
	Fraction F1;
	cout << F1 << endl;

	Fraction F2(378,9);
	cout << F2 << endl;

	Compare(F1, F2);

	Fraction F3 = Substract(F1, F2);
	cout << F3 << endl;
	cout << ++F3 << endl;
	cout << --F3 << endl;
	cout << F3++ << endl;
	cout << F3-- << endl;
	

	return 0;
}