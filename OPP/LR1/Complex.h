#pragma once

using namespace std;

class Complex
{
private:
	float a, b;
	float z, fi;
public:
	void setAB(float, float);
	void Polar();
	void Output();
};