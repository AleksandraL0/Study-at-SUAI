#include "Vectors.h"
#include <iostream>
#include <math.h>

using namespace std;

Vectors::Vectors() {}

Vectors::~Vectors()
{
	cout << "Destructer is activated" << endl;
}

Vectors::Vectors(float X1, float X2, float Y1, float Y2, float Z1, float Z2)
{
	this->x1 = X1;
	this->x2 = X2;
	this->y1 = Y1;
	this->y2 = Y2;
	this->z1 = Z1;
	this->z2 = Z2;
}

void Vectors::add(Vectors A, Vectors B)
{
	this->x1 = A.x1 + B.x1;
	this->x2 = A.x2 + B.x2;
	this->y1 = A.y1 + B.y1;
	this->y2 = A.y2 + B.y2;
	this->z1 = A.z1 + B.z1;
	this->z2 = A.z2 + B.z2;
}

void Vectors::sub(Vectors A, Vectors B)
{
	this->x1 = A.x1 - B.x1;
	this->x2 = A.x2 - B.x2;
	this->y1 = A.y1 - B.y1;
	this->y2 = A.y2 - B.y2;
	this->z1 = A.z1 - B.z1;
	this->z2 = A.z2 - B.z2;
}
float Vectors::setX()
{
	return this->x2 - this->x1;
}

float Vectors::setY()
{
	return this->y2 - this->y1;
}

float Vectors::setZ()
{
	return this->z2 - this->z1;
}

float Vectors::line()
{
	return sqrt(pow(this->setX(), 2) + pow(this->setY(), 2) + pow(this->setZ(), 2));
}

float Vectors::cos(Vectors B)
{
	return (this->setX() * B.setX() + this->setY() * B.setY() + this->setZ() * B.setZ()) / (this->line() * B.line());
}

float Vectors::skalar(Vectors B)
{
	return this->line() * B.line() * this->cos(B);
}

void Vectors::out()
{
	cout << "x1 - " << this->x1 << ", x2 - " << this->x2 << ", y1 - " << this->y1 << ", y2 - " << this->y2 << ", z1 - " << this->z1 << ", z2 - " << this->z2 << endl;
}