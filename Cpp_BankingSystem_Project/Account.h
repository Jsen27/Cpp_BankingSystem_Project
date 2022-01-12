#pragma once
class Account
{
private:
	int accID;			//계좌번호
	int balance;        //잔액
	char* cusName;         //이름
public:
	Account(int accID, char namestr[50], int money);
	Account(const Account& copy);
	int GetaccID() const;
	virtual void Deposit(int pocket);
	int WithDraw(int pocket);
	virtual void ShowInfo() const;
	~Account();
};