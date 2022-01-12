#include "Account.h"
#include "AccountHandler.h"
#include "BankingCommonDec1.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

AccountHandler::AccountHandler() :accNum(0) {}
void AccountHandler::ShowMenu() const
{
	cout << endl << endl;
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
	return;
}
void AccountHandler::MakeAccount()
{
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: "; cin >> sel;
	switch (sel)
	{
	case 1:
		MakeNormalAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	}
	return;
}
void AccountHandler::MakeNormalAccount()
{
	int accID;
	char name[NAME_LEN];
	int money;
	int inter;
	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> accID;
	cout << "이름: "; cin >> name;
	cout << "잔액: "; cin >> money;
	cout << "이자율: "; cin >> inter;
	accArr[accNum++] = new NormalAccount(accID, name, money, inter);
	cout << "계좌개설 완료" << endl;
}
void AccountHandler::MakeHighCreditAccount()
{
	int accID;
	char name[NAME_LEN];
	int money;
	int inter;
	char credit;
	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> accID;
	cout << "이름: "; cin >> name;
	cout << "잔액: "; cin >> money;
	cout << "이자율: "; cin >> inter;
	cout << "신용등급: "; cin >> credit;
	switch (credit)
	{
	case 'A':
		accArr[accNum++] = new HighCreditAccount(accID, name, money, inter, LEVEL_A);
		break;
	case 'B':
		accArr[accNum++] = new HighCreditAccount(accID, name, money, inter, LEVEL_B);
		break;
	case 'C':
		accArr[accNum++] = new HighCreditAccount(accID, name, money, inter, LEVEL_C);
		break;
	}
	cout << "계좌개설 완료" << endl;
}
void AccountHandler::DepositMoney()
{
	int n, pocket;
	cout << "[입 금]" << endl;
	cout << "계좌번호를 입력하세요 : ";
	cin >> n;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetaccID() == n)
		{
			cout << "입금액: "; cin >> pocket;
			accArr[i]->Deposit(pocket);
			cout << "입금 완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않는 계좌입니다." << endl;
	return;
}
void AccountHandler::WithDrawMoney()
{
	int n, pocket;
	cout << "[출 금]" << endl;
	cout << "계좌번호를 입력하세요 : ";
	cin >> n;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetaccID() == n)
		{
			cout << "출금액 : "; cin >> pocket;
			cout << accArr[i]->WithDraw(pocket) << "원 출금 완료" << endl;
			return;
		}
	}
	cout << "유효하지 않는 계좌입니다." << endl;
	return;
}
void AccountHandler::ShowAllAccInfo() const
{
	cout << "[계좌정보 전체 출력]" << endl;
	for (int i = 0; i < accNum; i++)
		accArr[i]->ShowInfo();
	cout << "전체 출력 완료" << endl;
}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}