#include"Loan.h"

void Loan::setLoan(double l)
{
	if (l < 0.0)
		return;
	else
		loan = l;
}

void Loan::setRate(double r)
{
	if (r < 0.0)
		return;
	else
		rate = r;
}

void Loan::setYears(int y)
{
	if (y < 0)
		return;
	else
		years = y;
}

double Loan::getLoan()const
{
	return loan;
}

double Loan::getRate()const
{
	return rate;
}

int Loan::getYears()const
{
	return years;
}

double Loan::getMonthlyPayment()const
{
	double monthlyPayment = 0.0;

	monthlyPayment = (loan * (rate / 12.0)*getTerm())/(getTerm()-1.0);

	return monthlyPayment;
}

double Loan::getTotalPayEnt()const
{
	double total = (getMonthlyPayment()*12.0)*(double)years;
	return total;
}
