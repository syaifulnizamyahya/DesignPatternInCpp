// SingletonPattern.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

// 3. definition
class GlobalClass
{
public:
	GlobalClass()
	{
		value = 100;
	}

	int get_value()
	{
		return value;
	}

	void set_value(int v)
	{
		value = v;
	}

private:
	int value;
};

// 1. declaration
GlobalClass *global_ptr;

int main()
{
	// 2. Initialize
	if (!global_ptr)
		global_ptr = new GlobalClass;
	cout << "main: global_ptr is " << global_ptr->get_value() << '\n';
	global_ptr->set_value(200);
	cout << "main: global_ptr is " << global_ptr->get_value() << '\n';

	cin.get();
}