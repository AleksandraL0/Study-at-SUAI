#include "Rectangle.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

Rectangle::Rectangle()
{
	this->a = 0;
	this->b = 0;
}

Rectangle::~Rectangle() {}

Rectangle::Rectangle(int a, int b)
{
	this->a = a;
	this->b = b;
}

Rectangle Rectangle::operator*(Rectangle& rec1)
{
	Rectangle NewRec;
	NewRec.a = this->a + rec1.a;
	NewRec.b = this->b + rec1.b;
	return NewRec;
}

int Rectangle::operator++()
{
	return (this->a + this->b) * 2.0;
}

bool operator>(Rectangle& rec1, Rectangle& rec2)
{
	if (rec1.operator++() > rec2.operator++())
	{
		return true;
	}
	else return false;
}

void Rectangle::Output()
{
	std::cout << "Сторона 1: " << this->a << ", сторона 2: " << this->b << endl;
}

vector<char> symbol(Rectangle& rec)
{
	vector<char> S;
	S.push_back(rec.a + '0');
	S.push_back(' ');
	S.push_back(rec.b + '0');
	return S;
}

void Rectangle::Toint(vector<char> S)
{
	char* A = new char;
	*A = S.at(0);
	this->a = atoi(A);
	char* B = new char;
	*B = S.at(2);
	this->b = atoi(B);
}
