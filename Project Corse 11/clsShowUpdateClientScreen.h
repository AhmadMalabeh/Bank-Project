#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsShowUpdateClientScreen:protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter Client First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Client Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Client Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Client Phone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Client PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Client Balance : ";
		Client.Balance = clsInputValidate::ReadFloatNumber();

	}

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

	static void UpdateClientInfo() {

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}

		_DrawScreenHeader("\t  Update Screen");

		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number not found please enter another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		cout << "\nUpdate Client Info" << endl;
		cout << "______________________________________" << endl;
		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();
		switch (SaveResult) {
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "Account Updated seccfuly :-)" << endl;
			Client.Print();
			system("pause>0");
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "Error Acount was not saved because its empty" << endl;
			break;

		}




	}

};

