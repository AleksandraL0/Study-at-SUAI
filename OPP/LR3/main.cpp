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
	cout << "�������� ������� " << ++rec1 << endl;
	cout << "�������� ������� " << ++rec2 << endl;
	cout << "�������� �������� " << ++rec3 << endl;
	if (rec1 > rec2)
	{
		cout << "������ ������" << endl;
	}
	else
	{
		cout << "������ �� ������" << endl;
	}
	vector<char> S;
	S = symbol(rec1);
	cout << "������ �������������� � ������" << endl;
	for (char i : S)
	{
		cout << i;
	}
	cout << endl;
	Rectangle rec4;
	rec4.Toint(S);
	rec4.Output();
}