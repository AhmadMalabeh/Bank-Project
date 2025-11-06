#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsDeleteUserScreen : protected clsScreen
{

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

	static void ShowDeleteUserScreen() {

		_DrawScreenHeader("\t  Delete User Screen");

		string UserName = "";
		cout << "Enter User Name : ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nUser with User Name [" << UserName << "] not found please try again : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\nAre you sure you want to delete this User ? y/n : ";
		char Conf;
		cin >> Conf;
		if (Conf == 'y' || Conf == 'Y') {
			if (User.Delete()) {
				cout << "\nClient Deleted sussfuly :-)" << endl;
				_PrintUser(User);
			}
			else {
				cout << "\nError Client was not Deleted" << endl;
			}
		}

	}


};

