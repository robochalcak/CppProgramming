#include<iostream>
#include<string>
#include"Die.h"
#include<ctime>
#include<cmath>
using namespace std;

int main()
{
	Die fish;
	int points = 0;
	char again;

	cout << "What you can catch, and howm many points are for that.\n";
	cout << "==================================\n";
	cout << "1: old shoe =       0 points\n";
	cout << "2: small Fish =     2 points\n";
	cout << "3: big Fish =      30 points\n";
	cout << "4: huge Fish =    400 points\n";
	cout << "5: small Shark = 5000 points\n";
	cout << "6: big Shark =  60000 points\n";
	cout << "==================================\n";

	cout << "Now we are going to fishing...\n";
	cout << "Good luck\n";
	cout << "-----------------------------------\n";
	do
	{
		fish.roll();
		fish.getSide();

		switch(fish.getSide())
		{
		case 1:
			cout << "You have catch an old shoe\n";
			points += 0;
			break;

		case 2:
			cout << "You have catch a small Fish \n";
			points += 2;
			break;
		case 3:
			cout << "You have catch a big Fish \n";
			points += 30;
			break;
		case 4:
			cout << "You have catch a huge Fish \n";
			points += 400;
			break;
		case 5:
			cout << "You have catch a small shark \n";
			points += 5000;
			break;
		case 6:
			cout << "You have catch a big shark \n";
			points += 60000;
		}

		cout << "Do you want to continue in fishing? \n";
		cout << " \'Y\' for YES or \'N\' for NO: ";
		cin >> again;

		while(toupper(again)!='Y'&&toupper(again)!='N')
		{
			cout << "Invalid selection!!!\n";
			cout << "Do you want to continue in fishing? \n";
			cout << " \'Y\' for YES or \'N\' for NO: ";
			cin >> again;

		}

		if(toupper(again)=='N')
		{
			cout << "You have selected to no continue fishing...\n";
			cout << "Now you will get, how many points did you earn\n";
		}

	} while (toupper(again) != 'N');

	cout << "-----------------------------------------------\n";
	if (points < 500)
		cout << "You have earned " << points << " it is no to much, but try\n to be better in the future\n";
	else
		cout << "CONGRATULATION: You have earnt " << points << " good job.\n";

	system("Pause");
	return 0;

}
