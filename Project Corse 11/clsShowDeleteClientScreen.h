#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsShowDeleteClientScreen :protected clsScreen
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

public:

	static void DeleteClient(){

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\t  Delete Client Screen");

		string AccountNumber = "";
		cout << "\nPlease enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient whit Account Number [" << AccountNumber << "] Not Exist, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		cout << "\nAre you sure you want to Delete this Client : y/n : ";
		char Conf;
		cin >> Conf;
		if (Conf == 'Y' || Conf == 'y') {
			if (Client.Delete()) {
				cout << "\nClient Deleted sussfuly :-)" << endl;
				_Print(Client);
			}
			else {
				cout << "\nError Client was not Deleted" << endl;
			}
		}
	}

};

