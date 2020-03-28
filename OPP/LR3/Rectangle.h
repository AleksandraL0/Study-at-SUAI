#pragma once
#include <vector>
using namespace std;


class Rectangle
{
private:
	int a, b;
public:
	Rectangle();
	Rectangle(int, int);
	//Rectangle(Rectangle&);
	~Rectangle();
	Rectangle operator*(Rectangle&);
	int operator++();
	friend bool operator>(Rectangle&, Rectangle&);
	friend vector<char> symbol(Rectangle&);
	void Toint(vector<char>);
	void Output();
};

