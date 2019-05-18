#pragma once
#ifndef COIN_H
#define COIN_H
#include<cmath>
#include<iostream>
#include<ctime>
#include<string>
using namespace std;

class Coin
{
private:
	string sideUp;
public:
	Coin()
	{
		int seed(time(0));
		srand(seed);
		if ((rand() % 2) == 0)
			sideUp = "Heads";
		else
			sideUp = "Tails";
	}
	~Coin() {}
	void toss()
	{
		if ((rand() % 2) == 0)
			sideUp = "Heads";
		else
			sideUp = "Tails";
	}

	string getSideUp()const
	{
		return sideUp;
	}
};

#endif // !COIN_H
