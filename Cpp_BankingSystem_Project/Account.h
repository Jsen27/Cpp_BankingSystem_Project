#pragma once
#include "String.h"

class Account
{
private:
	int accID;			//계좌번호
	int balance;        //잔액
	String cusName;         //이름
public:
	Account(int accID, String name, int money);
	/*Account(const Account& copy);
	Account& operator=(const Account& ref);*/

	int GetaccID() const;
	virtual void Deposit(int pocket);
	int WithDraw(int pocket);
	virtual void ShowInfo() const;
	//~Account();
};