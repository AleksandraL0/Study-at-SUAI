#include <iostream>
#include "ComplexNumber.h"
#include <time.h>
#include <memory>

using namespace std;

int main()
{
	system("color F1");
	setlocale(LC_ALL, "rus");
	float A1, B1, A2, B2;
	int num ;
	cout << "Введите а1" << endl;
	cin >> A1;
	cout << "Введите b1" << endl;
	cin >> B1;
	cout << "Введите а2" << endl;
	cin >> A2;
	cout << "Введите b2" << endl;
	cin >> B2;
	ComplexNumber *X = new ComplexNumber(A1, B1);
	ComplexNumber* Y = new ComplexNumber(A2, B2);
	ComplexNumber* Z = new ComplexNumber();
	
	cout << "Выберите действие: 1 - сложить, 2 - вычесть, 3 - умножить" << endl;
	cin >> num;
	switch (num)
	{
	case 1:
	{
		Z->add(*X, *Y);
		break;
	}
	case 2:
	{
		Z->sub(*X, *Y);
		break;
	}
	case 3:
	{
		Z->mul(*X, *Y);
		break;
	}
	}
	Z->output();
	return 0;
}