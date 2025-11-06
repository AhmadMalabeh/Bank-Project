#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsCurrency.h"
#include<vector>
using namespace std;
class clsShowCurrenciesList : protected clsScreen
{

	static void _PrintCurrencyRecordLine(clsCurrency Currency) {

		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(20) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:
	static void ShowCuurenciesList() {
		vector <clsCurrency> vCurrencyList = clsCurrency::GetCurrenciesList();
		string Title = "\t Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrencyList.size()) + ") Currency.";
		_DrawScreenHeader(Title,SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Cuntry";
		cout << "| " << left << setw(20) << "Currency Code";
		cout << "| " << left << setw(40) << "Cuurrency Name";
		cout << "| " << left << setw(10) << "Rate / (1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;

		for (clsCurrency& C : vCurrencyList) {
			_PrintCurrencyRecordLine(C);
			cout << endl;

		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;
	}
};

