#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;
class clsShowAddNewClientScreen :protected clsScreen
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


	

	static void AddNewClient() {

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t  Add New Client Screen");

		string AccountNumber = "";
		cout << "\nEnter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient With Account Number [" << AccountNumber << "] Already Exist Please choose again : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult) {
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nAccount Addeded Successfully :-)\n";
			_Print(NewClient);
			break;

		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\nError account was not saved because it's Empty";
			break;

		case clsBankClient::enSaveResults::svFailedAccountNumberExist:
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}


	}


};

