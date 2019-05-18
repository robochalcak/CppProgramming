#include"Die.h"
#include<ctime>
#include<iostream>
#include<cmath>
using namespace std;

void Die::roll()
{
	num = (rand() % 6)+1;
}

int Die::getSide()const
{
	return num;
}
