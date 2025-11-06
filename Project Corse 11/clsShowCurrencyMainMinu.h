#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsShowCurrenciesList.h"
#include"clsShowFindCurrency.h"
#include"clsShowUpdateCurrency.h"
using namespace std;
class clsShowCurrencyMainMinu : protected clsScreen
{
	enum enCurrencyMainMinuOption {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculater = 4, eMainMenue = 5
	};
	static short _ReadCurrencyMainMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1-5] : ";
		short Choose = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choose;
	}

	static void _GoBackToCurrencyMainMenu()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Currency Exchange Menue...\n";
		system("pause>0");
		ShowCurrencyMainMenu();
	}
	
	static void _ShowListCurrenciesScreen()
	{
		system("cls");
		clsShowCurrenciesList::ShowCuurenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		system("cls");
		clsShowFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		system("cls");
		
		clsShowUpdateCurrency::ShowUpdateCurrency();
	}

	static void _ShowCurrencyCalculaterScreen()
	{
		system("cls");
		cout << setw(37) << left << "" << "\n\t\t\tCurrency Calculater Screen...\n";
	}

	static void _PerformCurrencyMainMenuOption(enCurrencyMainMinuOption CurrencyMainMinuOption) {
	
		switch (CurrencyMainMinuOption) {
		
		case enCurrencyMainMinuOption::eListCurrencies:
			
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case enCurrencyMainMinuOption::eFindCurrency:
			
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case enCurrencyMainMinuOption::eUpdateRate:
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case enCurrencyMainMinuOption::eCurrencyCalculater:
			_ShowCurrencyCalculaterScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case enCurrencyMainMinuOption::eMainMenue:
			return;
		}
	
	}
		

public:
	static void ShowCurrencyMainMenu() {
		system("cls");
		_DrawScreenHeader("\t  Currency Exchange");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "\t\t\t\t\t\t[1] List Currencies." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[2] Find Currency." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[3] Update Rate." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[4] Currency Calculater." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[5] Main Menue." << endl;
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMainMenuOption((enCurrencyMainMinuOption)_ReadCurrencyMainMenuOption());
	}
};

