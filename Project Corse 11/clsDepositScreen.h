#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;

class clsDepositScreen : protected clsScreen
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

	static void DepositScreen() {

		clsScreen::_DrawScreenHeader("\t  Deposit Screen");

		string AccountNumber = ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client Whith Account Number[" << AccountNumber << "] Not Exist Please enter onother one : ";
			AccountNumber = ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_Print(Client);
		double Ammount = 0;
		cout << "\nPlease Enter Diposit Ammount : ";
		Ammount = clsInputValidate::ReadDblNumber();
		char Conf;
		cout << "\nAre you sure you want to perform this transaction : y/n ? ";
		cin >> Conf;
		if (Conf == 'y' || Conf == 'Y') {

			Client.Deposit(Ammount);
			cout << "Transaction don seccfuly :-)" << endl;
			cout << "New Balance is : " << Client.Balance << endl;

		}
		else {
			cout << "Operation was Cancelled" << endl;
		}

	}

};

