#pragma once
#include "NormalAccount.h"
class HighCreditAccount :public NormalAccount
{
private:
	int CreditRate;
public:
	HighCreditAccount(int accID, char namestr[50], int money, int inter, int credit)
		:NormalAccount(accID, namestr, money, inter), CreditRate(credit) {}
	void Deposit(int pocket)
	{
		NormalAccount::Deposit(pocket);
		Account::Deposit(pocket * (CreditRate / 100.0));
	}
	void ShowInfo() const
	{
		NormalAccount::ShowInfo();
		cout << "신용등급: ";
		if (CreditRate == 7) cout << "A" << endl;
		else if (CreditRate == 4) cout << "B" << endl;
		else cout << "C" << endl;
	}
};