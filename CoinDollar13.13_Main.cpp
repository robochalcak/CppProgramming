#include<iostream>
#include<iomanip>
#include<ctime>
#include<string>
#include"Coin.h"
using namespace std;

int main()
{
	Coin quarter;
	Coin dime;
	Coin nickel;

	double balance = 0.0;

	cout<<"Quarter: 0.25$\n";
	cout <<"Dime:   0.10$\n";
	cout <<"Nickel: 0.05$\n";

	cout << "Initial toss: \n";
	quarter.toss();
	dime.toss();
	nickel.toss();
	cout << "Done\n";

	cout << setprecision(2) << fixed;
	cout << "Your currently balance is: " << balance << endl;
	while(balance<1.0)
	{
		cout << "Starting...\n";
		quarter.toss();
		dime.toss();
		nickel.toss();

		if (quarter.getSideUp() == "Heads")
			balance += 0.25;
		if (dime.getSideUp() == "Heads")
			balance += 0.10;
		if (nickel.getSideUp() == "Heads")
			balance += 0.05;

		cout << "Quarter: " << quarter.getSideUp() << endl;
		cout << "Dime   :" << dime.getSideUp() << endl;
		cout << "Nickel :" << nickel.getSideUp() << endl;
	
	}
	cout << "Tossing has finished...\n";
	cout << "-------------------------------------\n";
	cout << "YOUR RESULTS\n";
	cout << "-------------------------------------\n";
	cout << "Balance is: " << balance<<endl;
	cout << "=========================================\n";

	if (balance == 1.0)
		cout << "CONGRATULATION, you have von!!!\n";
	else
		cout << "SORRY you have lost!!!\n";

	cout << "========================================\n";
	system("Pause");
	return 0;

}
