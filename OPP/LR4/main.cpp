#include "Money.h"
#include <iostream>

using namespace std;

int main()
{
	system("color F1");
	Bankomat Sber(5, 5, 5, 5, 5, 5);
	int SUM;
	Sber.Getting(1700);
	Sber.Getting(570);
	Sber.Getting(5340);
	Sber.Getting(100);
	cout << "Input amount to get" << endl;
	cin >> SUM;
	Sber.Getting(SUM);
	Sber.Refill(1, 0, 1, 1, 1, 1);
}