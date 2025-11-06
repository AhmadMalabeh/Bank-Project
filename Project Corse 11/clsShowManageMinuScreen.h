#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUser.h"
using namespace std;

class clsShowManageMinuScreen : protected clsScreen
{

    enum enManageScreenOption { eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eExit=6 };


    static void _BackToManageScreen() {

        cout << setw(37) << left << "" << "\nPress any key to go back to Manage Menue...\n";

        system("pause>0");
        ShowManageMinuScreen();
    }

    static short _ReadManageScreenOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1-6] : ";
        short Choose = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choose;
    }

    static void _ListUsersScreen() {
        
        clsListUsersScreen::ShowUsersList();
    
    }

    static void _AddNewUserScreen() {
        
        clsAddNewUserScreen::AddNewUserScreen();
        
    }

    static void _DeleteUserScreen() {
        clsDeleteUserScreen::ShowDeleteUserScreen();
       
    }

    static void _UpdateUserScreen() {
        clsUpdateUserScreen::UpdateClientScreen();
        
    }

    static void _FindUserScreen() {

        clsFindUser::FindUserScreen();
        
    }

    static void _OperateManageScreenOption(enManageScreenOption ManageScreenOption) {

        switch (ManageScreenOption) {
        case enManageScreenOption::eListUser:
            system("cls");
            _ListUsersScreen();
            _BackToManageScreen();
            break;
        case enManageScreenOption::eAddNewUser:
            system("cls");
            _AddNewUserScreen();
            _BackToManageScreen();
            break;
        case enManageScreenOption::eDeleteUser:
            system("cls");
            _DeleteUserScreen();
            _BackToManageScreen();
            break;
        case enManageScreenOption::eUpdateUser:
            system("cls");
            _UpdateUserScreen();
            _BackToManageScreen();
            break;
        case enManageScreenOption::eFindUser:
            system("cls");
            _FindUserScreen();
            _BackToManageScreen();
            break;
        case enManageScreenOption::eExit:
            break;
        }
    }

public:
	static void ShowManageMinuScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tManage Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete user.\n";
        cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Exit.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _OperateManageScreenOption((enManageScreenOption)_ReadManageScreenOption());
	}
};

