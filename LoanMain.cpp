#include<iostream>
#include<iomanip>
#include"Loan.h"
using namespace std;

int main()
{
	double mortgage;
	int years;
	double perc;
	double rate;
	Loan loan;

	cout << "////////////////////////////////////////////////////\n";
	cout << "////   WELCOME AT MORTGAGE PAYMENT CALCULATOR   ////\n";
	cout << "////////////////////////////////////////////////////\n";
	cout << endl << endl;
	cout << "Enter the amount of your mortgage or loan: $";
	cin >> mortgage;
	cout << "How many years do you will have loan or mortgage: ";
	cin >> years;
	cout << "Enter interest rate of your loan or mortgage in %";
	cin >> perc;

	rate = perc / 100.0;

	loan.setLoan(mortgage);
	loan.setRate(rate);
	loan.setYears(years);

	cout << "////////////////////////////////////////////////////\n";
	cout << "////                 YOUR RESULT                ////\n";
	cout << "////////////////////////////////////////////////////\n";
	cout << "Your loan in:              $" << loan.getLoan() << endl;
	cout << "Your rate in:              %" << perc << endl;
	cout << "Number of year of the loan: " << loan.getYears() << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Monthly payment:           $" << loan.getMonthlyPayment() << endl;
	cout << "Total payment:             $" << loan.getTotalPayEnt() << endl;
	cout << "////////////////////////////////////////////////////\n";
	cout << "////////////////////////////////////////////////////\n";
	system("Pause");
	return 0;
}
