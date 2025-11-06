#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsShowFindClientScreen:protected clsScreen
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
	static void ShowFindClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		string AccountNumber = "";
		_DrawScreenHeader("\t  Find Client Screen");

		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient whith Account Number [" << AccountNumber << "] not Exist choose another one : ";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpity()) {
			cout << "\nClient Found :-)" << endl;
		}
		else {
			cout << "\nClient Not Found :-(" << endl;
		}
		_Print(Client);
	}
};

