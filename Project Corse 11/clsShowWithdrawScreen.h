#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;

class clsShowWithdrawScreen:protected clsScreen
{
	static void _Print(clsBankClient Clinet) {
		cout << "\nClient Info...";
		cout << "\n--------------------------------------------";
		cout << "\nFirst Name     : " << Clinet.FirstName;
		cout << "\nLast Name      : " << Clinet.LastName;
		cout << "\nFull Name      : " << Clinet.FullName();
		cout << "\nEmail          : " << Clinet.Email;
		cout << "\nPhone          : " << Clinet.Phone;
		cout << "\nAccount Number : " << Clinet.AccountNumber();
		cout << "\nPin Code       : " << Clinet.PinCode;
		cout << "\nBalance        : " << Clinet.Balance;
		cout << "\n--------------------------------------------";


	}

	static string ReadAccountNumber() {
		cout << "\nPlease enter Account Number : ";
		string AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public:
	static void WithdrawScreen() {
		system("cls");
		_DrawScreenHeader("\t  Withdraw Screen");

		
		string AccountNumber = ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient with account number [" << AccountNumber << "] not found please try again : ";
			AccountNumber = ReadAccountNumber();
		}

		clsBankClient CLient = clsBankClient::Find(AccountNumber);

		_Print(CLient);

		double Ammount;
		cout << "\nPlease Enter Withdraw Ammount : ";
		Ammount = clsInputValidate::ReadDblNumber();

		

		char Conf;
		cout << "\nAre you sure you want to do this transaction : y/n ? ";
		cin >> Conf;
		if (Conf == 'y' || Conf == 'Y') {

			/*CLient.Withdraw(Ammount);*/
			if (CLient.Withdraw(Ammount)) {
				cout << "Transaction done succefuly :-)" << endl;
				cout << "New Balance is : " << CLient.Balance << endl;
			}
			else {
				cout << "\nCannot Withdraw, Insuffecient Balance" << endl;
				cout << "Ammount to withdraw : " << Ammount << endl;
				cout << "Your Balance is : " << CLient.Balance << endl;
			}
		}
		else {
			cout << "Operation was Cancelled" << endl;
		}
	}
};

