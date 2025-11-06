#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsUpdateUserScreen:protected clsScreen
{

	static void _ReadUserInfo(clsUser& User) {
		cout << "\nEnter User First Name : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter User Last Name : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter User Email : ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter User Phone : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter User Password : ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions : ";
		User.Permissions = _ReadPermissionsToSet();

	}

	static int _ReadPermissionsToSet() {

		char Answer;

		int Permissions = 0;
		cout << "\nDo you want to give this User Full Permissions ? y/n ?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			return -1;
		}

		cout << "\nDo you want to give Access to : ";

		cout << "\nShow Clients List : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Clients List : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\nDelete Clients List : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Clients List : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permissions += clsUser::enPermissions::pUpdateClients;
		}
		cout << "\nFind Clients List : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions Screen : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Screen : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nLogIn Register Screen : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permissions += clsUser::enPermissions::pShowLogInRegister;
		}

		return Permissions;

	}


	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:



	static void UpdateClientScreen() {

		_DrawScreenHeader("\t  Update User Screen");

		string UserName = "";
		cout << "\nEnter User Name : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nUser with User Name [" << UserName << "] Not found Try again : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		cout << "\nAre you sure you want to Update this User ? y/n : ";
		char Conf;
		cin >> Conf;
		if (Conf == 'y' || Conf == 'Y') {
			
			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResult;
			SaveResult = User.Save();

			switch (SaveResult) {
			case clsUser::enSaveResults::svSucceeded:
				cout << "\nUser Updated Successfuly :-)" << endl;
				_PrintUser(User);
				break;


			case clsUser::enSaveResults::svFaildEmptyObject:

				cout << "Error User was not Saved because its Empity" << endl;

				break;

			}
		}
		
	}


};

