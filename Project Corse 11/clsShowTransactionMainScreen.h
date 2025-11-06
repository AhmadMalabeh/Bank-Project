#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsDepositScreen.h"
#include"clsShowWithdrawScreen.h"
#include"clsShowTotalBalanceScreen.h"
#include"clsShowTransfarScreen.h"
#include"clsShowTransfarLog.h"

using namespace std;

class clsShowTransactionMainScreen :protected clsScreen
{

	enum enTransactionMinuOption {
		eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eTransfar = 4, eTransfarLog = 5, eExit = 6
	};
	static void _GoBackToTransactionMinu() {
		

		cout << setw(37) << left << "" << "\nPress any key to go back to Transaction Menue...\n";

		system("pause>0");
		ShowTransactionScreen();
	}

	static void _DepositScreen() {
		system("cls");
		clsDepositScreen::DepositScreen();

		
	}

	static void _WithdrawScreen() {
		system("cls");
		clsShowWithdrawScreen::WithdrawScreen();
	}

	static void _TotalBalance() {
		system("cls");
		clsShowTotalBalanceScreen::ShowTotalBalances();
	}

	static void _TransfarScreen() {
		system("cls");
		clsShowTransfarScreen::TransfarScreen();

	}

	static void _TransfarLogList() {
		system("cls");
		clsShowTransfarLog::ShowTransfarLogScreen();
	}

	static short _ReadTransactionMinuOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do? [1-6] : ";
		short Choose = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choose;

	}

	

	static void _PerformTransactionMinuOption(enTransactionMinuOption TransactionMinuOption) {

		switch (TransactionMinuOption) {


		case enTransactionMinuOption::eDeposit:
			_DepositScreen();
			_GoBackToTransactionMinu();
			break;
		case enTransactionMinuOption::eWithdraw:
			_WithdrawScreen();
			_GoBackToTransactionMinu();
			break;
		case enTransactionMinuOption::eTotalBalance:
			_TotalBalance();
			_GoBackToTransactionMinu();
			break;

		case enTransactionMinuOption::eTransfar:
			_TransfarScreen();
			_GoBackToTransactionMinu();
			break;
		case enTransactionMinuOption::eTransfarLog:
			_TransfarLogList();
			_GoBackToTransactionMinu();
			break;
		case enTransactionMinuOption::eExit:

			return;
			
		
		}
	}

	

public:
	static void ShowTransactionScreen() {


		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t  Transaction Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "\t\t\t\t\t\t[1] Deposit Screen." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[2] Withdraw." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[3] Total Balance." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[4] Transfar." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[5] Transfar Log." << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[6] Exit." << endl;
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionMinuOption((enTransactionMinuOption)_ReadTransactionMinuOption());
	}
};

