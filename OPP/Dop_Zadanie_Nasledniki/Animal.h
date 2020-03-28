#pragma once
#include <string>
using namespace std;
class Animal
{
private:
	int population;
protected:
	string Continent;
public:
	Animal();
};

class Bird : private Animal
{
protected:
	int krylo;
public:
	Bird();
	void setKRYLO(int);
	void ShowContinent();
};

class Straus : protected Bird
{
protected:
	int id;
public:
	Straus();
	void setID(int);
};

class SmallStraus : public Straus
{
private:
	string Name;
public:
	SmallStraus();
	void setNAME(string);
	void Show();
};

