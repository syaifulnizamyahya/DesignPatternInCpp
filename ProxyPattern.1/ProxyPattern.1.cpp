// ProxyPattern.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class ICar
{
public:
	virtual void driveCar() = 0;
private:

};

class Car : public ICar
{
public:
	// Inherited via ICar
	virtual void driveCar() override
	{
		cout << "car driven" << endl;
	}

private:
};

class ProxyCar : public ICar
{
public:
	ProxyCar(int);

	// Inherited via ICar
	virtual void driveCar() override
	{
		if (_age < 18)
		{
			cout << "underage" << endl;
		}
		else
		{
			_realCar->driveCar();
		}
	}

private:
	int _age;
	ICar *_realCar;

};

ProxyCar::ProxyCar(int age) : _realCar(new Car()), _age(age)
{
	_realCar = new Car();
	_age = age;
}

// How to use above Proxy class?
int main()
{
	ICar* car = new ProxyCar(16);
	car->driveCar();
	//delete car;

	car = new ProxyCar(25);
	car->driveCar();
	//delete car;

	cin.get();
}