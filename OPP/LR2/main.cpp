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
	cout << "������� �1" << endl;
	cin >> A1;
	cout << "������� b1" << endl;
	cin >> B1;
	cout << "������� �2" << endl;
	cin >> A2;
	cout << "������� b2" << endl;
	cin >> B2;
	ComplexNumber *X = new ComplexNumber(A1, B1);
	ComplexNumber* Y = new ComplexNumber(A2, B2);
	ComplexNumber* Z = new ComplexNumber();
	
	cout << "�������� ��������: 1 - �������, 2 - �������, 3 - ��������" << endl;
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