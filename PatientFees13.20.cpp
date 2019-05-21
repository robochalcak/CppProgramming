//Content of PatientAccount.h
////////////////////////////////////
////////////////////////////////////
///////////////////////////////////
//////////////////////////////////

#pragma once
#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

class PatientAccount
{
private:
	int daysInHosp;
	double dailyRate;
	double totalCharges;
public:
	PatientAccount()
	{
		daysInHosp = 0;
		dailyRate = 0.0;
		totalCharges = 0.0;
	}

	PatientAccount(int dh, double dr, double tch)
	{
		daysInHosp = dh;
		dailyRate = dr;
		totalCharges = tch;
	}

	~PatientAccount() {}

	void setDaysInHosp(int dh)
	{
		daysInHosp = dh;
		totalCharges += (dailyRate * static_cast<double>(daysInHosp));
	}

	void setDailyRate(double dr)
	{
		dailyRate = dr;
		totalCharges += (dailyRate * static_cast<double>(daysInHosp));
	}

	void setTotalCharges(double tch)
	{
		totalCharges += tch;
	}

	int getDaysInHosp()const
	{
		return daysInHosp;
	}

	double getDailyRate()const
	{
		return dailyRate;
	}

	double getTotalCharges()const
	{
		return totalCharges;
	}

};
#endif // !PATIENTACCOUNT_H

//////////////////////////////
/////////////////////////////
//Content of PatientAccount.cpp
#include"PatientAccount.h"
#include<iostream>
///////////////////////
///////////////////////
//Content of Pharmacy.h
//////////////////////////
#pragma once
#ifndef PHARMACY_H
#define PHARMACY_H
#include"PatientAccount.h"
#include<string>
#include<iostream>
using namespace std;

class Pharmacy
{

private:

	string medications[5];
	double prices[5];
	PatientAccount *account;

public:

	Pharmacy()
	{
		for(int i = 0; i < 5; i++)
		{
			medications[i] = "";
			prices[i] = 0.0;
		}
		account = nullptr;
	}

	Pharmacy(string med[],double pri[],PatientAccount &acc)
	{
		for(int i = 0; i < 5; i++)
		{
			medications[i] = med[i];
			prices[i] = pri[i];
		}

		account = &acc;
	}

	~Pharmacy() {}

	void setMedicationType(int i, string med)
	{
		medications[i - 1] = med;
	}

	void setPrices(int i, double pr)
	{
		prices[i - 1] = pr;
	}

	void setChargesToPatientAccount(double ch)
	{
		account->setTotalCharges(ch);
	}

	string getMedicationType(int i)const
	{
		return medications[i - 1];
	}

	double getPrice(int i)const
	{
		return prices[i - 1];
	}
};

#endif 

////////////////////////////
////////////////////////////
// Content of Pharmacy.cpp
#include"PatientAccount.h"
#include<string>
#include<iostream>
using namespace std;
//////////////////////////
////////////////////////
///////////////////////
//Content of Surgery.h
/////////////////////
///////////////////////

#pragma once
#ifndef SURGERY_H
#define SURGERY_H
#include <string>
#include"PatientAccount.h"
using namespace std;

class Surgery
{
private:
	string surgeries[5];
	double prices[5];
	PatientAccount *account;

public:
	Surgery()
	{
		for(int i = 0; i < 5; i++)
		{
			surgeries[i] = "";
			prices[i] = 0.0;
		}
		account = nullptr;
	}

	Surgery(string sur[], double pri[], PatientAccount &acc)
	{
		for(int i = 0; i < 5;i++)
		{
			surgeries[i] = sur[i];
			prices[i] = pri[i];
		}

		account = &acc;
	}

	void setTypeOfSurgery(int index, string type)
	{
		surgeries[index - 1] = type;
	}

	void setPrice(int index, double pr)
	{
		prices[index - 1] = pr;
	}

	void setChargesOfAccount(double cha)
	{
		account->setTotalCharges(cha);
	}

	string getTypeOfSurgery(int i)const
	{
		return surgeries[i - 1];
	}

	double getPrice(int i)const
	{
		return prices[i - 1];
	}
};
#endif // !SURGERY_H

////////////////////////
///////////////////////
//////////////////////
//Content of Surgery.cpp
#include"Surgery.h"
#include <string>
#include"PatientAccount.h"
using namespace std;
//////////////////////
////////////////////////
////////////////////////
/////////////////////////
//Content of Source.cpp 
///Main() function///
///////////////////////
//////////////////////
#include<iostream>
#include<iomanip>
#include<string>
#include"PatientAccount.h"
#include"Pharmacy.h"
#include"Surgery.h"
using namespace std;

int main()
{
	PatientAccount account;
	Pharmacy pharm;
	Surgery surg;

	account.setDailyRate(22.20);
	pharm.setMedicationType(1, "Examination");
	pharm.setMedicationType(2, "Admission");
	pharm.setMedicationType(3, "Antidepressant medications");
	pharm.setMedicationType(4, "Antipsychotic medication");
	pharm.setMedicationType(5, "Benzodiazepines");

	pharm.setPrices(1, 5.25);
	pharm.setPrices(2, 10.20);
	pharm.setPrices(3, 39.99);
	pharm.setPrices(4, 55.29);
	pharm.setPrices(5, 25.89);

	surg.setTypeOfSurgery(1, "Laparoscopy");
	surg.setTypeOfSurgery(2, "Endoscopy");
	surg.setTypeOfSurgery(3, "Arthroscopy");
	surg.setTypeOfSurgery(4, "Cystoscopy");
	surg.setTypeOfSurgery(5, "Gastroscopy");

	surg.setPrice(1, 65.89);
	surg.setPrice(2, 79.99);
	surg.setPrice(3, 39.36);
	surg.setPrice(4, 29.45);
	surg.setPrice(5, 69.89);

	int again;
	int days;
	int choice;
	char add;
	char a;

	cout << "==========================================\n";
	cout << "WELCOME AT MEDICATION CHARGE CALCULATOR\n";
	cout << "==========================================\n";

	cout << endl << endl;

	cout << "Enter number of days of stay at the hospital: ";
	cin >> days;
	while(days<1)
	{
		cout << "Number of days cannot be less than 1!!!\n";
		cout << "Enter number of days of stay at the hospital: ";
		cin >> days;
	}
	account.setDaysInHosp(days);

	cout << "Now we are going to add consumed medications to patient account: \n";
	cout << "==================================================================\n";
	do {
		cout << "From menu below select number of type of medications:\n ";
		cout << "Type of medication                    price \n";
		cout << "______________________________________________\n";
		for (int i = 0; i < 5; i++)
		{
			cout << setw(2)<<left<< i + 1 << ": ";
			cout<<setw(35)<<left<< pharm.getMedicationType(i+1);
			cout << setw(60) << left << pharm.getPrice(i+1);
			cout << endl;
		}
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "Select one item from range 1 to 5 or 6 for exit: ";
		cin >> choice;
		while (choice < 1 || choice>6)
		{
			cout << "Invalid selection!!!\n";
			cout << "Select one item from range 1 to 5: ";
			cin >> choice;
		}
		if(choice==6)
		{
			goto exit;
		}

		cout << "You have selected this type: ";
		cout << pharm.getMedicationType(choice) << "          ";
		cout << pharm.getPrice(choice) << endl;
		cout << "Do you want to add this selection to the patient account?\n ";
		cout << "\'Y\' for YES or \'N\' for NO: ";
		cin >> add;
		while (toupper(add) != 'N'&&toupper(add) != 'Y')
		{
			cout << "Invalid selection!!!\n";
			cout << "Do you want to add this selection to the patient account?\n ";
			cout << "\'Y\' for YES or \'N\' for NO: ";
			cin >> add;
		}
		if (toupper(add) == 'Y')
		{
			account.setTotalCharges(pharm.getPrice(choice));
			cout << "Item with charge " << pharm.getPrice(choice) << "was added to the account\n";
		}
		else
			break;

		cout << "Do you want to add the next medication to the patient account?\n";
		cout << "\'Y\' for YES or \' N\' for NO: ";
		cin >> a;
		while(toupper(a)!='Y'&&toupper(a)!='N')
		{
			cout << "Invalid selection!!!\n";
			cout << "Do you want to add the next medication to the patient account?\n";
			cout << "\'Y\' for YES or \' N\' for NO: ";
			cin >> a;
		}

	} while (toupper(a) != 'N');

	exit:
	cout << "Now we are going to add consumed surgeries to the patient account\n";

	do
	{
		cout << "From menu below select number of type of surgery: \n";
		cout << "Type of surgery                       price \n";
		cout << "______________________________________________\n";
		for(int i = 0; i < 5; i++)
		{
			cout << setw(2) << left << i + 1 << ": ";
			cout <<setw(35)<<left<< surg.getTypeOfSurgery(i+1);
			cout << setw(50) << left << surg.getPrice(i+1);
			cout << endl;
		}
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "Select one item from range 1 to 5 or 6 for exit: ";
		cin >> choice;
		while (choice < 1 || choice>6)
		{
			cout << "Invalid selection!!!\n";
			cout << "Select one item from range 1 to 6: ";
			cin >> choice;
		}
		if (choice == 6)
		{
			goto exit2;
		}

		cout << "You have selected this type: ";
		cout << surg.getTypeOfSurgery(choice) << "          ";
		cout << surg.getPrice(choice) << endl;
		cout << "Do you want to add this selection to the patient account?\n ";
		cout << "\'Y\' for YES or \'N\' for NO: ";
		cin >> add;
		while (toupper(add) != 'N'&&toupper(add) != 'Y')
		{
			cout << "Invalid selection!!!\n";
			cout << "Do you want to add this selection to the patient account?\n ";
			cout << "\'Y\' for YES or \'N\' for NO: ";
			cin >> add;
		}
		if (toupper(add) == 'Y') 
		{
			account.setTotalCharges(surg.getPrice(choice));
			cout << "Item with charge " << surg.getPrice(choice) << "was added to the account\n";
		}
		else
			break;
		cout << "Do you want to add the next medication to the patient account?\n";
		cout << "\'Y\' for YES or \' N\' for NO: ";
		cin >> a;
		while (toupper(a) != 'Y'&&toupper(a) != 'N')
		{
			cout << "Invalid selection!!!\n";
			cout << "Do you want to add the next medication to the patient account?\n";
			cout << "\'Y\' for YES or \' N\' for NO: ";
			cin >> a;
		}

	} while (toupper(a) != 'N');

exit2:
	cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
	cout << "Numbers of days in Hospital:               ";
	cout<< setw(100) << left << account.getDaysInHosp();
	cout << endl;
	cout << "Daily rate for one day:                   $";
	cout<<setprecision(2)<<fixed<<showpoint<<setw(100)<<left<< account.getDailyRate();
	cout << endl;
	cout << "Charge for all days in hospital:          $";
	cout <<setprecision(2)<<fixed<<left<<setw(100)<< account.getDailyRate()*static_cast<double>(account.getDaysInHosp());
	cout << endl;
	cout << "Charges for medicaments and surgeries:    $";
	cout << setprecision(2)<<fixed<<showpoint<<setw(100)<<left<< account.getTotalCharges() - (static_cast<double>(account.getDaysInHosp())*account.getDailyRate());
	cout << endl;
	cout << "Total charges to pay:                     $";
	cout<<setw(100)<<left<<setprecision(2)<<fixed<<showpoint<< account.getTotalCharges();
	cout << endl;
	cout << "============================================================\n";

	system("Pause");
	return 0;
}
