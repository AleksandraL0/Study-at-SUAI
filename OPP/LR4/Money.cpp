#include "Money.h"
#include <iostream>

using namespace std;

Money::Money()
{
	this->num10 = 0;
	this->num50 = 0;
	this->num100 = 0;
	this->num500 = 0;
	this->num1000 = 0;
	this->num5000 = 0;
}

Money::Money(int NUM10, int NUM50, int NUM100, int NUM500, int NUM1000, int NUM5000)
{
	this->num10 = NUM10;
	this->num50 = NUM50;
	this->num100 = NUM100;
	this->num500 = NUM500;
	this->num1000 = NUM1000;
	this->num5000 = NUM5000;
}

Money::~Money()
{
	cout << "Destroucter is actived" << endl;
}

Bankomat::Bankomat(int NUM10, int NUM50, int NUM100, int NUM500, int NUM1000, int NUM5000) : Money(NUM10, NUM50, NUM100, NUM500, NUM1000, NUM5000)
{

}

int Money::summa()
{
	return this->num10 * 10 + this->num50 * 50 + this->num100 * 100 + this->num500 * 500 + this->num1000 * 1000 + this->num5000 * 5000;
}

void Bankomat::Getting(int SUM)
{
	int NUM10 = 0, NUM50 = 0, NUM100 = 0, NUM500 = 0, NUM1000 = 0, NUM5000 = 0;
	if (SUM > this->summa()) cout << "There are no money in bankomat" << endl;
	else
	{
		for (int i = 1; i <= this->num5000; i++)
		{
			if (SUM - 5000 >= 0)
			{
				SUM -= 5000;
				this->num5000--;
				NUM5000++;
				i--;
			}
		}
		for (int i = 1; i <= this->num1000; i++)
		{
			if (SUM - 1000 >= 0)
			{
				SUM -= 1000;
				this->num1000--;
				NUM1000++;
				i--;
			}
		}
		for (int i = 1; i <= this->num500; i++)
		{
			if (SUM - 500 >= 0)
			{
				SUM -= 500;
				this->num500--;
				NUM500++;
				i--;
			}
		}
		for (int i = 1; i <= this->num100; i++)
		{
			if (SUM - 100 >= 0)
			{
				SUM -= 100;
				this->num100--;
				NUM100++;
				i--;
			}
		}
		for (int i = 1; i <= this->num50; i++)
		{
			if (SUM - 50 >= 0)
			{
				SUM -= 50;
				this->num50--;
				NUM50++;
				i--;
			}
		}
		for (int i = 1; i <= this->num10; i++)
		{
			if (SUM - 10 >= 0)
			{
				SUM -= 10;
				this->num10--;
				NUM10++;
				i--;
			}
		}
	}
	if (SUM != 0)
	{
		cout << "There are no bills in bankomat to give out, not enough - " << SUM << endl;
		this->num10 += NUM10;
		this->num50 += NUM50;
		this->num100 += NUM100;
		this->num500 += NUM500;
		this->num1000 += NUM1000;
		this->num5000 += NUM5000;
	}
	else cout << "5000 - " << NUM5000 << ", 1000 - " << NUM1000 << ", 500 - " << NUM500 << ", 100 - " << NUM100 << ", 50 - " << NUM50 << ", 10 - " << NUM10 << endl;
}

void Bankomat::Refill(int NUM10, int NUM50, int NUM100, int NUM500, int NUM1000, int NUM5000)
{
	this->num10 += NUM10;
	this->num50 += NUM50;
	this->num100 += NUM100;
	this->num500 += NUM500;
	this->num1000 += NUM1000;
	this->num5000 += NUM5000;
	cout << "Refill for " << NUM10 * 10 + NUM50 * 50 + NUM100 * 100 + NUM500 * 500 + NUM1000 * 1000 + NUM5000 * 5000 << " - succesfully" << endl;
}