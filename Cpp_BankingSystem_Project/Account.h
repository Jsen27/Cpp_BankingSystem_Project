#pragma once
class Account
{
private:
	int accID;			//°èÁÂ¹øÈ£
	int balance;        //ÀÜ¾×
	char* cusName;         //ÀÌ¸§
public:
	Account(int accID, char namestr[50], int money);
	Account(const Account& copy);
	int GetaccID() const;
	virtual void Deposit(int pocket);
	int WithDraw(int pocket);
	virtual void ShowInfo() const;
	~Account();
};