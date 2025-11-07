#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsString.h"
using namespace std;
class clsShowCurrencyCalculater :protected clsScreen
{

	static void _Print(clsCurrency Currency) {
		
		cout << "\n-----------------------------------\n";
		cout << "Country      : " << Currency.Country() << endl;
		cout << "Code         : " << Currency.CurrencyCode() << endl;
		cout << "Name         : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) =   : " << Currency.Rate() << endl;
		cout << "\n-----------------------------------\n";
	}

	static string _CheckCurrencyCode(string CurrencyCode) {

		CurrencyCode = clsInputValidate::ReadString();
		
		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency Not Found Please try again : ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		return CurrencyCode;

	}
public:

	static void ShowCurrencyClaculater() {

		char TryAgain;

		do {
			system("cls");
			_DrawScreenHeader("\t Currency Calculater Screen");

			cout << "\nPlease Enter Cuurency1 Code : ";
			string Currency1Code = "";
			Currency1Code = _CheckCurrencyCode(Currency1Code);
			clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);


			cout << "\nPlease enter Currency2 Code : ";
			string Currency2Code = "";
			Currency2Code = _CheckCurrencyCode(Currency2Code);
			clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);


			cout << "\nEnter Ammount to Exchange : ";
			float Ammount = clsInputValidate::ReadFloatNumber();

			cout << "Convert From : " << endl;
			_Print(Currency1);

			float FromCurrencyToDolar = clsCurrency::ExchangeFromCurrencyToDolar(Currency1, Ammount);

			cout << Ammount << " " << Currency1.CurrencyCode() << " = " << FromCurrencyToDolar << " USD" << endl;

			if (Currency2.CurrencyCode() != "USD") {

				cout << "To : " << endl;
				_Print(Currency2);
				float FromDolarToCurrency = clsCurrency::ExchangeFromDolarToCurrency(Currency2, FromCurrencyToDolar);
				cout << Ammount << " " << Currency1.CurrencyCode() << " = " << FromDolarToCurrency << endl;

			}

			cout << "\nDo you want to try Again ? y/n ? ";
			cin >> TryAgain;

		} while (TryAgain == 'Y' || TryAgain == 'y');

	}
};

