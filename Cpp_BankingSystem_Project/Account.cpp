#include "Account.h"
#include "BankingCommonDec1.h"
Account::Account(int accID, String name, int money) :accID(accID), balance(money)
{
	cusName = name;
}
//Account::Account(const Account& copy) : accID(copy.accID), balance(copy.balance)
//{
//	cusName = new char[strlen(copy.cusName) + 1];
//	strcpy(cusName, copy.cusName);
//}
//Account& Account::operator=(const Account& ref)
//{
//	delete[]cusName;
//	cusName = new char[strlen(ref.cusName) + 1];
//	strcpy(cusName, ref.cusName);
//
//	accID = ref.accID;
//	balance = ref.balance;
//	return *this;
//}
int Account::GetaccID() const { return accID; }
void Account::Deposit(int pocket)
{
	if (pocket < 0)
		throw DepositException(pocket);

	balance += pocket;
}
int Account::WithDraw(int pocket)
{
	if (balance < pocket)
		throw WithDrawException(pocket);

	balance -= pocket;
	return pocket;
}
void Account::ShowInfo() const
{
	cout << "계좌번호: " << accID << endl;
	cout << "이름: " << cusName << endl;
	cout << "잔액: " << balance << endl;
}
DepositException::DepositException(int pocket) :pocket(pocket) {}
void DepositException::Reason()
{
	cout << pocket << "원을 입금할 수 없습니다." << endl;
}
WithDrawException::WithDrawException(int pocket) : pocket(pocket) {}
void WithDrawException::Reason()
{
	cout << pocket << "원을 출금할 수 없습니다." << endl;
}

//Account::~Account()
//{
//	delete[]cusName;
//}