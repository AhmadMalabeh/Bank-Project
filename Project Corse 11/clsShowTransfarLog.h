#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "clsUser.h"
#include "clsScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsShowTransfarLog:protected clsScreen
{
	static void _PrintTransfarLogRecordLine(clsBankClient::stTransfarRecord TransfarRecord) {

		cout << setw(8) << left << "" << "| " << left << setw(25) << TransfarRecord.Date;
		cout << "| " << left << setw(12) << TransfarRecord.sAcc;
		cout << "| " << left << setw(12) << TransfarRecord.dAcc;
		cout << "| " << left << setw(10) << TransfarRecord.Ammount;
		cout << "| " << left << setw(10) << TransfarRecord.sBalance;
		cout << "| " << left << setw(10) << TransfarRecord.dBalance;
		cout << "| " << left << setw(15) << TransfarRecord.UserName;

	}


public:
	static void ShowTransfarLogScreen() {

		vector<clsBankClient::stTransfarRecord> vTransfarRecord = clsBankClient::GetTransfarList();
		string Titel = "\tTransfar Log Screen";
		string SubTitel = "\t    (" + to_string(vTransfarRecord.size()) + ")";

		clsScreen::_DrawScreenHeader(Titel, SubTitel);





		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		
		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(12) << "s.Acct";
		cout << "| " << left << setw(12) << "d.Acct";
		cout << "| " << left << setw(10) << "Ammount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(15) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		if (vTransfarRecord.size() == 0) {
			cout << "\t\t\t\tNo Transfar Available In the System!";
		}
		else {
			for (clsBankClient::stTransfarRecord& Record : vTransfarRecord) {
				_PrintTransfarLogRecordLine(Record);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		

	}
};

