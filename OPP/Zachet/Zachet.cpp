#include <iostream>
#include "Header.h"

using namespace std;


void Cout::setx()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> x[i][j];
		}
	}
}

void Cout::output()
{
	for (int i = 0; i < 4; i++)
	{
		cout << x1[i] << " ";
	}
	cout << endl << endl;
}

void Cout::couting()
{
	for (int i = 0; i < 4; i++)
	{
		int max_x = x[i][0], min_x = x[i][0];
		for (int j = 0; j < 4; j++)
		{
			if (x[i][j] > max_x)
			{
				max_x = x[i][j];
			}
			if (x[i][j] < min_x)
			{
				min_x = x[i][j];
			}
		}
		x1[i] = (max_x + min_x) / 2;
	}
}

void Cout::outputx()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Cout a, b;
	a.setx();
	a.couting();
	a.output();
	a.outputx();

	b.setx();
	b.couting();
	b.output();
	b.outputx();
}
