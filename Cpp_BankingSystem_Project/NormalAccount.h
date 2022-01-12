#pragma once
#include "Account.h"
#include "BankingCommonDec1.h"
class NormalAccount :public Account
{
private:
	int interRate;
public:
	NormalAccount(int accID, char namestr[50], int money, int inter)
		:Account(accID, namestr, money), interRate(inter) {}
	void Deposit(int pocket)
	{
		Account::Deposit(pocket);
		Account::Deposit(pocket * (interRate / 100.0));
	}
	void ShowInfo() const
	{
		Account::ShowInfo();
		cout << "이자율: " << interRate << "%" << endl;
	}
};