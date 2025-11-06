#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsClientListScreen.h"
#include"clsShowAddNewClientScreen.h"
#include"clsShowDeleteClientScreen.h"
#include"clsShowUpdateClientScreen.h"
#include"clsShowFindClientScreen.h"
#include"clsShowTransactionMainScreen.h"
#include"clsShowManageMinuScreen.h"
#include"clsShowLoginRegisterScreen.h"
#include"clsShowCurrencyMainMinu.h"
#include"Global.h";
using namespace std;

class clsMainScreen : protected clsScreen
{

    enum enMainMinuOption {
        eListScreen = 1, eAddNewClient, eDeleteClient, eUpdateClient, eFindClient,
        eShowTransactionScreen, eManageUsers, eLoginRegisterList,eCurrencyExchange ,eExit
    };

	static short _ReadMainMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1-10] : ";
		short Choose = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
		return Choose;
			
	}

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Main Menue...\n";

        system("pause>0");
       ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        

        clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddNewClientsScreen()
    {
       
        clsShowAddNewClientScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
        
        clsShowDeleteClientScreen::DeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
        clsShowUpdateClientScreen::UpdateClientInfo();

    }

    static void _ShowFindClientScreen()
    {
        clsShowFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        clsShowTransactionMainScreen::ShowTransactionScreen();

    }

    static void _ShowManageUsersMenue()
    {
        clsShowManageMinuScreen::ShowManageMinuScreen();

    }

    static void _ShowLoginRegisterScreen() {

        clsShowLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen() {
        clsShowCurrencyMainMinu::ShowCurrencyMainMenu();
	}

    static void _Logout() {
        

        CurrentUser = clsUser::Find("", "");
   }

    static void _PerformMainMenuOption(enMainMinuOption MainMenuOption) {


        switch (MainMenuOption) {
        case enMainMinuOption::eListScreen:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            
            break;
        case enMainMinuOption::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
           
            break;


        case enMainMinuOption::eDeleteClient:
            system("cls");

            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
           
            break;
        case enMainMinuOption::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            
            break;

        case enMainMinuOption::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            
            break;
        case enMainMinuOption::eShowTransactionScreen:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            
            break;

        case enMainMinuOption::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMinuOption::eLoginRegisterList:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMinuOption::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
            break;

        case enMainMinuOption::eExit:
            system("cls");
            _Logout();
            
            break;

        }
    }

 public:

     static void ShowMainMenue() {
         system("cls");
         _DrawScreenHeader("\t\tMain Screen");

         cout << setw(37) << left << "" << "===========================================\n";
         cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
         cout << setw(37) << left << "" << "===========================================\n";
         cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
         cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
         cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
         cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
         cout << setw(37) << left << "" << "\t[5] Find Client.\n";
         cout << setw(37) << left << "" << "\t[6] Transactions.\n";
         cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
         cout << setw(37) << left << "" << "\t[8] Login Register.\n";
         cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
         cout << setw(37) << left << "" << "\t[10] Logout.\n";
         cout << setw(37) << left << "" << "===========================================\n";

         _PerformMainMenuOption((enMainMinuOption)_ReadMainMenuOption());

     }

};

