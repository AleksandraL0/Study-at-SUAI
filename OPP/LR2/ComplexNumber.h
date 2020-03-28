#pragma once
#include <memory>

using namespace std;

class ComplexNumber
{
private:
	float a, b;
public:
	ComplexNumber();
	ComplexNumber(float, float);
	ComplexNumber(ComplexNumber&);
	~ComplexNumber();
	void add(ComplexNumber&, ComplexNumber&);
	void sub(ComplexNumber&, ComplexNumber&);
	void mul(ComplexNumber&, ComplexNumber&);
	void output();
};