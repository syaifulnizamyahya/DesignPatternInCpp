// CommandPattern.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Command
{
public:
	virtual void Execute() = 0;

private:

};

class Light
{
public:
	void TurnOn()
	{
		cout << "Turn on" << endl;
	}

	void TurnOff()
	{
		cout << "Turn off" << endl;
	}
};

class FlipUpCommand : public Command
{
private:
	Light *_light;

public:
	FlipUpCommand(Light *light)
	{
		_light = light;
	}

	void Execute()
	{
		_light->TurnOn();
	}
};

class FlipDownCommand : public Command
{
private:
	Light *_light;

public:
	FlipDownCommand(Light *light)
	{
		_light = light;
	}

	// Inherited via Command
	virtual void Execute() override
	{
		_light->TurnOff();
	}

};

class Invoker
{
private:
	vector<Command*> _command;
public:
	void Store(Command *command)
	{
		if (command)
		{
			_command.push_back(command);
		}
	}

	void ExecuteAllCommand()
	{
		for (size_t i = 0; i < _command.size(); i++)
		{
			_command[i]->Execute();
		}
	}

	void ClearAllCommand()
	{
		_command.clear();
	}

};

int main()
{
	unique_ptr<Light> light = make_unique<Light>();

	// create command object(optional)
	unique_ptr<Command> switchOn(new FlipUpCommand(light.get()));
	unique_ptr<Command> switchDown(new FlipDownCommand(light.get()));

	// create invoker to store and execute command
	unique_ptr<Invoker> invoker = make_unique<Invoker>();

	// add command to invoker
	invoker->Store(new FlipUpCommand(light.get()));
	invoker->Store(switchDown.get());

	// execute command from list in invoker
	invoker->ExecuteAllCommand();

	invoker->ClearAllCommand();

	cin.get();
}
