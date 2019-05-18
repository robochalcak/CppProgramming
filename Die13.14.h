#pragma once
#ifndef DIE_H
#define DIE_H
#include<ctime>
#include<iostream>
#include<cmath>
using namespace std;
class Die
{
private:
	int num;

public:
	Die()
	{
		unsigned seed(time(0));
		srand(seed);
		num =(rand() % 6)+1;
	}

	~Die(){}

	void roll();
	int getSide()const;
};


#endif // !DIE_H
