#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsAddNewUserScreen : protected clsScreen
{
private:

	static void _ReadUserInfo(clsUser &User) {
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

	static void AddNewUserScreen() {

		_DrawScreenHeader("\t  Add New User Screen");

		string UserName = "";
		cout << "\nEnter User Name : ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName)) {
			cout << "\nUser with User name [" << UserName << "] Already Exist choose another one : ";
			UserName = clsInputValidate::ReadString();
		}
		
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(NewUser);
		
		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult) {
		case clsUser::enSaveResults::svSucceeded:
			cout << "\nUser Added Successfuly :-)" << endl;
			_PrintUser(NewUser);
			break;

		case clsUser::enSaveResults::svFaildEmptyObject:

			cout << "Error User was not Saved because its Empity" << endl;

			break;

		case clsUser::enSaveResults::svFaildUserExists:
			cout << "Error User was not Saved because User Name Used" << endl;

			break;
		}
		

	}

};

