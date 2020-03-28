#pragma once
class Money
{
protected:
	int num10, num50, num100, num500, num1000, num5000;
public:
	Money();
	Money(int, int, int, int, int, int);
	~Money();
	int summa();
};

class Bankomat : public Money
{
public:
	Bankomat(int, int, int, int, int, int);
	void Getting(int);
	void Refill(int, int, int, int, int, int);
};

