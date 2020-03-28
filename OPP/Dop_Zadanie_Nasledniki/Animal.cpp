#include "Animal.h"
#include <string>
#include <iostream>

using namespace std;

Animal::Animal()
{
	this->population = 100;
	this->Continent = "Africa";
}

void Bird::ShowContinent()
{
	cout << this->Continent << endl;
}

Bird::Bird(): Animal()
{
	this->krylo = 180;
}

void Bird::setKRYLO(int b)
{
}

Straus::Straus() : Bird()
{
	this->id = 0;
}

void Straus::setID(int id)
{
	this->id = id;
}

SmallStraus::SmallStraus() : Straus()
{
	this->Name = 'NULL';
}

void SmallStraus::setNAME(string name)
{
	this->Name = name;
}

void SmallStraus::Show()
{
	this->ShowContinent();
	cout << "ID " << this->id << " name " << this->Name << " krylo " << this->krylo;
}