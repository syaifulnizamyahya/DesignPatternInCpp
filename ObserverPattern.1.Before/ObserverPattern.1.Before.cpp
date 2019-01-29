// ObserverPattern.1.Before.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class DivObserver 
{
private:
	int m_div;

public:
	DivObserver(int div)
	{
		m_div = div;
	}

	void update(int val)
	{
		cout << val << " div " << m_div << " is " << val / m_div << '\n';
	}
};

class ModObserver
{
private:
	int m_mod;

public:
	ModObserver(int mod)
	{
		m_mod = mod;
	}

	void update(int val)
	{
		cout << val << " mod " << m_mod << " is " << val % m_mod << '\n';
	}
};

class Subject
{
private:
	int m_value;
	DivObserver m_div_obj;
	ModObserver m_mod_obj;

public:
	Subject() : m_div_obj(4), m_mod_obj(3)
	{

	}

	void notify()
	{
		m_div_obj.update(m_value);
		m_mod_obj.update(m_value);
	}

	void set_value(int value)
	{
		m_value = value;
		notify();
	}
};

int main()
{
	Subject subj;
	subj.set_value(14);
	cin.get();
}

