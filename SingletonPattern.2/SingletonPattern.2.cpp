// SingletonPattern.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

// 3. definition
class GlobalClass
{
private:
	int m_value;

public:
	GlobalClass(int v = 0)
	{
		m_value = v;
	}

	int get_value()
	{
		return m_value;
	}
	void set_value(int v)
	{
		m_value = v;
	}
};

// 1. declaration
GlobalClass *global_ptr = 0;

void foo(void)
{
	if (!global_ptr)
		global_ptr = new GlobalClass;
	global_ptr->set_value(1);
	cout << "foo: global_ptr is " << global_ptr->get_value() << '\n';
}

void bar(void)
{
	if (!global_ptr)
		global_ptr = new GlobalClass;
	global_ptr->set_value(2);
	cout << "bar: global_ptr is " << global_ptr->get_value() << '\n';
}

int main()
{
	// 2. Initialize
	if (!global_ptr)
		global_ptr = new GlobalClass;
	cout << "main: global_ptr is " << global_ptr->get_value() << '\n';
	foo();
	bar();

	cin.get();
}