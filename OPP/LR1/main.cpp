#include <iostream>
#include "Complex.h"
#include <Windows.h>

using namespace std;

int main()
{
	system("color F1");
	setlocale(LC_ALL, "rus");
	Complex number;
	float a, b;
	cout << "Введите a" << endl;
	cin >> a;
	cout << "Введите b" << endl;
	cin >> b;
	number.setAB(a, b);
	number.Polar();
	number.Output();
}