#include <iostream>
#include <iomanip>

using namespace std;


void setx(int (&x)[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> x[i][j];
		}
	}
}

void output(float x1[4])
{
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << x1[i] << " ";
	}
	cout << endl << endl;
}

void couting(int x[4][4], float (&x1)[4])
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

void outputx(int x[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << setw(8) << left << x[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int x[4][4], y[4][4];
	float x1[4], y1[4];
	setx(x);
	setx(y);
	couting(x, x1);
	couting(y, y1);
	outputx(x);
	output(x1);
	outputx(y);
	output(y1);
}
