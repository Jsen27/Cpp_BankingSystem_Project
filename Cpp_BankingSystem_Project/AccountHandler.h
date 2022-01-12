#pragma once
#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void MakeNormalAccount();
	void MakeHighCreditAccount();
	void DepositMoney();
	void WithDrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();
};