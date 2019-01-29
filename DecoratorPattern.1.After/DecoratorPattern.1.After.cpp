// DecoratorPattern.1.After.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class I
{
public:
	virtual void do_it() = 0;
};

class D : public I
{
private:
	I *m_wrappee;
public:
	D(I *inner)
	{
		m_wrappee = inner;
	}

	void do_it()
	{
		m_wrappee->do_it();
		//cout << 'D';
	}
};

class X : public D
{
public:
	X(I *core) : D(core)
	{

	}

	void do_it()
	{
		D::do_it();
		cout << "X";
	}
};

class A : public I
{
public:
	void do_it()
	{
		cout << 'A';
	}
};

class Y : public D
{
public:
	Y(I *core) : D(core)
	{

	}

	void do_it()
	{
		D::do_it();
		cout << 'Y';
	}
};

class Z : public D
{
public:
	Z(I *core) : D(core)
	{

	}

	void do_it()
	{
		D::do_it();
		cout << 'Z';
	}
};

int main() 
{
	I *anX = new X(new A);
	I *anXY = new Y(new X(new A));
	I *anXYZ = new Z(new Y(new X(new A)));

	anX->do_it();
	cout << '\n';
	anXY->do_it();
	cout << '\n';
	anXYZ->do_it();
	cout << '\n';

	cin.get();
}