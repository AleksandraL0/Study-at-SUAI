#include <iostream>
#include "Vectors.h"

using namespace std;

int main()
{
	system("color F1");
	Vectors A(1, 2, 0, 2, 4, -2), B(0, 4, 6, 7, 10, -5), ADD, SUB;
	cout << "Vector A ";
	A.out();
	cout << "Vector B ";
	B.out();
	ADD.add(A, B);
	cout << "SUM ";
	ADD.out();
	cout << "SUB ";
	SUB.sub(A, B);
	SUB.out();
	cout << "Skalar ";
	cout << A.skalar(B) << endl;
	cout << "line B ";
	cout << B.line() << endl;
	cout << "cos A B ";
	cout << A.cos(B) << endl;
}