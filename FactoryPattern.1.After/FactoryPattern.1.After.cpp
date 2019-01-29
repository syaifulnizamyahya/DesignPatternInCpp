// FactoryPattern.1.After.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Stooge
{
public:
	// Factory Method
	static Stooge *make_stooge(int choice);
	virtual void slap_stick() = 0;
};

class Larry : public Stooge
{
public:
	void slap_stick()
	{
		cout << "Larry: poke eyes";
		cout << endl;
	}
};

class Moe : public Stooge
{
public:
	void slap_stick()
	{
		cout << "Moe: poke eyes";
		cout << endl;
	}
};

class Curly : public Stooge
{
public:
	void slap_stick()
	{
		cout << "Curly: poke eyes";
		cout << endl;
	}
};

Stooge *Stooge::make_stooge(int choice)
{
	if (true)
	{
		if (choice == 1)
			return new Larry;
		else if (choice == 2)
			return new Moe;
		else
			return new Curly;
	}
}

int main()
{
	vector<Stooge*> roles;
	int choice;
	while (true)
	{
		cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
		cin >> choice;
		if (choice == 0)
			break;
		roles.push_back(Stooge::make_stooge(choice));
	}
	for (int i = 0; i < roles.size(); i++)
		roles[i]->slap_stick();
	for (int i = 0; i < roles.size(); i++)
		delete roles[i];

	cin.ignore();
	cin.get();
}