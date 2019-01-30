// FacadePattern.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

/* Complex parts */
class CPU
{
public:
	void executeTask()
	{
		cout << "CPU task" << endl;
	}
};

class HardDrive
{
public:
	void executeTask()
	{
		cout << "Hard drive task" << endl;
	}
};

class Memory
{
public:
	void executeTask()
	{
		cout << "Memory task" << endl;
	}
};

/* Facade */

class ComputerFacade
{
private:
	CPU* processor;
	Memory* ram;
	HardDrive* hd;

public:
	ComputerFacade()
	{
		processor = new CPU();
		ram = new Memory();
		hd = new HardDrive();
	}

	ComputerFacade(CPU &cpu, Memory &memory, HardDrive &hardDrive)
	{
		*processor = cpu;
		*ram = memory;
		*hd = hardDrive;
	}

	void start()
	{
		processor->executeTask();
		ram->executeTask();
		hd->executeTask();
	}

	~ComputerFacade()
	{
		delete processor;
		delete ram;
		delete hd;
	}
};

/* Client */

void main()
{
	ComputerFacade computer;
	computer.start();

	cin.get();
}