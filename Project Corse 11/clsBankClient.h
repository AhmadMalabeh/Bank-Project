#pragma once
#include<iostream>
#include<string>;
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
#include"clsdate.h"
using namespace std;


class clsBankClient : public clsPerson
{

	enum enMode { EmpityMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _Balance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToObject(string Line,string Delim="#//#") {

		vector <string> vStr;
		
		vStr = clsString::Split(Line,Delim);
		
		return clsBankClient(enMode::UpdateMode, vStr[0], vStr[1], vStr[2], vStr[3], vStr[4], vStr[5], stod(vStr[6]));

	}

	static clsBankClient _GetEmpityClientObject() {
		return clsBankClient(enMode::EmpityMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadDataFromFile() {

		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {

				clsBankClient Client= _ConvertLineToObject(line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static string _ConvertClientObjToLine(clsBankClient Client) {

		string Delim = "#//#";

		string line = "";
		line = Client.FirstName+Delim;
		line += Client.LastName + Delim;
		line += Client.Email + Delim;
		line += Client.Phone + Delim;
		line += Client.AccountNumber() + Delim;
		line += Client.GetPinCode() + Delim;
		line += to_string(Client.GetBalance());
		return line;

	}

	void _SaveClientDataToFile(vector <clsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open()) {
			string line;
			for (clsBankClient& C : vClients) {

				if (C.MarkForDelete() == false) {

					line = _ConvertClientObjToLine(C);
					MyFile << line + "\n";
				}
				
			}
			MyFile.close();
		}
	}
	
	void _Update() {
		vector<clsBankClient> _vClients = _LoadDataFromFile();

		for (clsBankClient& C : _vClients) {
			if (C.AccountNumber() == AccountNumber()) {
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(_vClients);
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew() {

		_AddDataLineToFile(_ConvertClientObjToLine(*this));
	}

	string ConvertTransfarDataToLine(double Ammount, clsBankClient DestinationClinet,string Seperator="#//#") {

		string Line="";
		Line += clsDate::GetSystemDateTimeString() + Seperator;
		Line += _AccountNumber + Seperator;
		Line += DestinationClinet.AccountNumber() + Seperator;
		Line += to_string(Ammount) + Seperator;
		Line += to_string(_Balance) + Seperator;
		Line += to_string(DestinationClinet.Balance) + Seperator;
		Line += CurrentUser.UserName;
		return Line;



	}

	void _AddTransfarDataToFile(double Ammount,clsBankClient DestinationClinet) {

		string Line = ConvertTransfarDataToLine(Ammount, DestinationClinet);
		fstream MyFile;
		MyFile.open("TransfarLog.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << Line << endl;
			MyFile.close();
		}

	}

	struct stTransfarRecord;
	static stTransfarRecord _ConvertTransfarLineToRecord(string Line,string Seperator="#//#") {

		vector<string>vTransfarLineData = clsString::Split(Line, Seperator);

		stTransfarRecord TransfarRecord;
		TransfarRecord.Date = vTransfarLineData[0];
		TransfarRecord.sAcc = vTransfarLineData[1];
		TransfarRecord.dAcc = vTransfarLineData[2];
		TransfarRecord.Ammount = stod(vTransfarLineData[3]);
		TransfarRecord.sBalance = stod(vTransfarLineData[4]);
		TransfarRecord.dBalance = stod(vTransfarLineData[5]);
		TransfarRecord.UserName = vTransfarLineData[6];

		return TransfarRecord;

	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, double Balance)
		: clsPerson(FirstName, LastName, Email, Phone) 
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetBalance(float Balance) {
		_Balance = Balance;
	}
	double GetBalance() {
		return _Balance;
	}
	__declspec(property(get = GetBalance, put = SetBalance))double Balance;

	bool MarkForDelete() {
		return _MarkForDelete;
	}

	bool IsEmpity() {
		return _Mode == enMode::EmpityMode;
	}

	void Print() {
		cout << "\nClient Info...";
		cout << "\n--------------------------------------------";
		cout << "\nFirst Name     : " << FirstName;
		cout << "\nLast Name      : " << LastName;
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nAccount Number : " << _AccountNumber;
		cout << "\nPin Code       : " << _PinCode;
		cout << "\nBalance        : " << _Balance;
		cout << "\n--------------------------------------------";

		
	}

	static clsBankClient Find(string AccountNumber) {
		vector<clsBankClient> vClient;
		fstream File;
		File.open("Clients.txt", ios::in);
		if (File.is_open()) {
			string line;
			while (getline(File, line)) {
				clsBankClient Client = clsBankClient::_ConvertLineToObject(line);
				if (Client.AccountNumber() == AccountNumber) {
					File.close();
					return Client;
				}
				vClient.push_back(Client);
			}
			File.close();
		}
		return _GetEmpityClientObject();
		
	}

	static clsBankClient Find(string AccountNumber,string PinCode) {
		vector<clsBankClient> vClient;
		fstream File;
		File.open("Clients.txt", ios::in);
		if (File.is_open()) {
			string line;
			while (getline(File, line)) {
				clsBankClient Client = clsBankClient::_ConvertLineToObject(line);
				if ((Client.AccountNumber() == AccountNumber)&&(Client.GetPinCode() == PinCode)) {
					File.close();
					return Client;
				}
				vClient.push_back(Client);
			}
			File.close();
		}
		return _GetEmpityClientObject();
	}
	
	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		return (!Client.IsEmpity());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 ,svFailedAccountNumberExist};

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmpityMode:
		{

			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}
		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return enSaveResults::svFailedAccountNumberExist;
			}
			else {

				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}


		}

	}

	static clsBankClient GetAddNewClient(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete() {
		vector<clsBankClient>_vClients;
		_vClients = _LoadDataFromFile();
		for (clsBankClient& C : _vClients) {
			if (C.AccountNumber() == _AccountNumber) {
				C._MarkForDelete = true;
				_SaveClientDataToFile(_vClients);

				*this = _GetEmpityClientObject();
				return true;
				
			}
		}
		return false;
	}

	static vector<clsBankClient> GetClientList() {
		
		return _LoadDataFromFile();
	}

	static double GetTotalBalances() {

		vector<clsBankClient>vClients = _LoadDataFromFile();
		double TotalBalances = 0;
		for (clsBankClient& C : vClients) {
			TotalBalances += C.Balance;
		}
		return TotalBalances;
	}

	void Deposit(double Ammount) {
		_Balance += Ammount;
		Save();
	}

	bool Withdraw(double Ammount) {

		if (Ammount > _Balance) {
			return false;
		}
		else {

			_Balance -= Ammount;
			Save();
		}
	}

	bool Transfar(double Ammount, clsBankClient& DestinationClient) {

		if (Ammount > Balance) {
			return false;
		}

		Withdraw(Ammount);
		DestinationClient.Deposit(Ammount);
		_AddTransfarDataToFile(Ammount, DestinationClient);

		return true;
	}

	struct stTransfarRecord {
		string Date;
		string sAcc;
		string dAcc;
		double Ammount;
		double sBalance;
		double dBalance;
		string UserName;
	};

	static vector<stTransfarRecord>GetTransfarList() {

		vector<stTransfarRecord> vTransfarRecord;
		fstream MyFile;
		MyFile.open("TransfarLog.txt", ios::in);

		if (MyFile.is_open()) {

			string line;
			stTransfarRecord TransfarRecord;
			while (getline(MyFile, line)) {
				TransfarRecord = _ConvertTransfarLineToRecord(line);
				vTransfarRecord.push_back(TransfarRecord);
			}
			MyFile.close();
		}
		return vTransfarRecord;

	}

};

