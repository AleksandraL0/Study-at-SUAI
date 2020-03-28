#include "Complex.h"
#include <time.h>
#include <iostream>
#include <math.h>

const double M_PI = 3.14;

using namespace std;

void Complex::setAB(float A, float B)
{
	a = A;
	b = B;
}

void Complex::Polar()
{
	z = sqrt(pow(a, 2) + pow(b, 2));
	
	if (a > 0 && b >= 0)
	{
		fi = atan(b / a);
	}
	else if (a < 0 && b >= 0)
	{
		fi = M_PI - atan(fabs(b / a));
	}
	else if (a < 0 && b < 0)
	{
		fi = M_PI + atan(fabs(b / a));
	}
	else if (a > 0 && b < 0)
	{
		fi = 2*M_PI - atan(fabs(b / a));
	}
	else if(a == 0 && b > 0)
	{
		fi = M_PI / 2;
	}
	else if (a == 0 && b < 0)
	{
		fi = 3 * M_PI / 2;
	}
}

void Complex::Output()
{
	if (fi == 0)
	{
		cout << "Z = " << z << endl;
	}
	else
	{
		cout << "Z = " << z << char(183) << "e^(" << fi << "i)" << endl;
	}
}