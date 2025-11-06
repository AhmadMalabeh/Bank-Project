#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;
class clsShowFindCurrency : protected clsScreen
{

	static void _Print(clsCurrency Currency) {
		cout << "\n\nCurrency Card:";
		cout << "\n______________________________________";
		cout << "\n\nCountry : " << Currency.Country()<<endl;
		cout << "\nCode : " << Currency.CurrencyCode()<<endl;
		cout << "\nname : " << Currency.CurrencyName()<<endl;
		cout << "\nRate(1$) : " << Currency.Rate()<<endl;
		cout << "\n______________________________________";
	}

	static void ShowResult(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found :-)";
			_Print(Currency);
		}
		else {
			cout << "\nCurrency NOT Found :-(";
		}
	}

	static short _ReadFindCurrencyOption() {
		
		short Choice = 0;
		cout << "Find By : [1] Code [2] Country ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2);
		return Choice;
	}
public:
	
	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("\tFind Currency Screen");
		
		short Choice = 0;
		Choice = _ReadFindCurrencyOption();
		
		if (Choice == 1) {
			string CurrencyCode = "";
			cout << "\nPlease enter Currency Code to Find : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			ShowResult(Currency);
		}

		if (Choice == 2) {
			string Country = "";
			cout << "\nPlease Enter Country Name : ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			ShowResult(Currency);
			
		}


	}


};

