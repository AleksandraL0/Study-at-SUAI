#include <iostream>
#include <time.h>
#include <vector>
#include "Rectangle.h"

using namespace std;

int main()
{
	system("color F1");
	setlocale(LC_ALL, "rus");
	Rectangle rec1(8, 4), rec2(1, 5);
	Rectangle rec3 = rec1 * rec2;
	rec1.Output();
	rec2.Output();
	rec3.Output();
	cout << "Периметр первого " << ++rec1 << endl;
	cout << "Периметр второго " << ++rec2 << endl;
	cout << "Периметр третьего " << ++rec3 << endl;
	if (rec1 > rec2)
	{
		cout << "Первый больше" << endl;
	}
	else
	{
		cout << "Первый не больше" << endl;
	}
	vector<char> S;
	S = symbol(rec1);
	cout << "Данные прямоугольника в строке" << endl;
	for (char i : S)
	{
		cout << i;
	}
	cout << endl;
	Rectangle rec4;
	rec4.Toint(S);
	rec4.Output();
}