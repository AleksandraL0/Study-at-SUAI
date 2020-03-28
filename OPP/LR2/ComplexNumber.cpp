#include "ComplexNumber.h"
#include <iostream>
#include <memory>

using namespace std;

ComplexNumber::ComplexNumber()
{
	a = 0;
	b = 0;
}

ComplexNumber::ComplexNumber(float A, float B)
{
	a = A;
	b = B;
}

ComplexNumber::ComplexNumber(ComplexNumber& X)
{
	a = X.a;
	b = X.b;
}

ComplexNumber::~ComplexNumber()
{
	cout << "Вызван деструктор" << endl;
}

void ComplexNumber::add(ComplexNumber& X, ComplexNumber& Y)
{
	a = X.a + Y.a;
	b = X.b + Y.b;
}

void ComplexNumber::sub(ComplexNumber& X, ComplexNumber& Y)
{
	a = X.a - Y.a;
	b = X.b - Y.b;
}

void ComplexNumber::mul(ComplexNumber& X, ComplexNumber& Y)
{
	a = X.a * Y.a;
	b = X.b * Y.b;
}

void ComplexNumber::output()
{
	if (b >= 0)
	{
		cout << "Z = " << a << " + " << b << "i" << endl;
	}
	else if (b < 0)
	{
		cout << "Z = " << a << " " << b << "i" << endl;
	}
}