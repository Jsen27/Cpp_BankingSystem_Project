#include "Account.h"
#include "BankingCommonDec1.h"
Account::Account(int accID, char namestr[50], int money) :accID(accID), balance(money)
{
	cusName = new char[strlen(namestr) + 1];
	strcpy(cusName, namestr);
}
Account::Account(const Account& copy) : accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}
int Account::GetaccID() const { return accID; }
void Account::Deposit(int pocket)
{
	balance += pocket;
}
int Account::WithDraw(int pocket)
{
	if (balance < pocket)
		return 0;

	balance -= pocket;
	return pocket;
}
void Account::ShowInfo() const
{
	cout << "°èÁÂ¹øÈ£: " << accID << endl;
	cout << "ÀÌ¸§: " << cusName << endl;
	cout << "ÀÜ¾×: " << balance << endl;
}
Account::~Account()
{
	delete[]cusName;
}