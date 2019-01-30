// AdapterPattern.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

// client interface
class Player //Client wants to use this.
{
public:
	virtual void Play() = 0;	//This is function client wants to use
};

// 
class OldPlayer	//What we have
{
	string _song;
public:
	OldPlayer(string song) :_song(song) {}

	void OldPlay(int volume)	//This is function we got 
	{
		cout << "\nPlaying song : " << _song.c_str() << " at volume :" << volume << "\n";
	}
};

// adapter
class Adapter : private OldPlayer, public Player 
{
protected:
	int _volume;
public:
	Adapter(string name, int vol) : _volume(vol), OldPlayer(name) {}
	// Inherited via Player
	virtual void Play() override
	{
		OldPlay(_volume);
	}
};

int main()
{
	Player* newStuffDad = new Adapter("Song title", 50);
	newStuffDad->Play();	//The call to the interface function is routed by the adapter to the LegacyCode.
	cout << "\n";
	delete newStuffDad;

	cin.get();

	return 1;
}