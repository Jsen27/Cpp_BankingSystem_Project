#pragma once
class Account
{
private:
	int accID;			//���¹�ȣ
	int balance;        //�ܾ�
	char* cusName;         //�̸�
public:
	Account(int accID, char namestr[50], int money);
	Account(const Account& copy);
	int GetaccID() const;
	virtual void Deposit(int pocket);
	int WithDraw(int pocket);
	virtual void ShowInfo() const;
	~Account();
};