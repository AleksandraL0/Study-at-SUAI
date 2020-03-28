#pragma once
class Vectors
{
private:
	float x1, x2, y1, y2, z1, z2;
public:
	Vectors();
	Vectors(float, float, float, float, float, float);
	//Vectors(const Vectors&);
	~Vectors();
	float setX();
	float setY();
	float setZ();
	void add(Vectors, Vectors);
	void sub(Vectors, Vectors);
	float skalar(Vectors);
	float line();
	float cos(Vectors);
	void out();
};

