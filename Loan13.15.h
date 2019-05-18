#pragma once
#ifndef  LOAN_H
#define LOAN_H
#include<cmath>
class Loan
{
private:
	double payment;
	double loan;
	double rate;
	int years;
public:
	Loan()
	{
		payment = 0.0;
		loan = 0.0;
		rate = 0.0;
		years = 0;
	}

	Loan(double p, double l, double r, int y)
	{
		if (p < 0.0)
			return;
		else
			payment = p;
		if (l < 0.0)
			return;
		else
			loan = l;
		if (r < 0.0)
			return;
		else
			rate = r;
		if (y < 0)
			return;
		else
			years = y;
	}

	~Loan(){}

	void setLoan(double);
	void setRate(double);
	void setYears(int);
	
	double getLoan()const;
	double getRate()const;
	int getYears()const;

	double getMonthlyPayment()const;
	double getTotalPayEnt()const;

private:
	double getTerm()const
	{
		double term;
		double dYears = static_cast<double>(years);
		double power(12.0 * dYears);
		term = pow((1 + (rate / 12.0)),power);
		return term;
	}
};
#endif // ! LOAN_H
