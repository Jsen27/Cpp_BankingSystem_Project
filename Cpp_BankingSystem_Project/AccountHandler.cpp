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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
	return;
}
void AccountHandler::MakeAccount()
{
	int sel;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> sel;
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
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID : "; cin >> accID;
	cout << "�̸�: "; cin >> name;
	cout << "�ܾ�: "; cin >> money;
	cout << "������: "; cin >> inter;
	accArr[accNum++] = new NormalAccount(accID, name, money, inter);
	cout << "���°��� �Ϸ�" << endl;
}
void AccountHandler::MakeHighCreditAccount()
{
	int accID;
	char name[NAME_LEN];
	int money;
	int inter;
	char credit;
	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID : "; cin >> accID;
	cout << "�̸�: "; cin >> name;
	cout << "�ܾ�: "; cin >> money;
	cout << "������: "; cin >> inter;
	cout << "�ſ���: "; cin >> credit;
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
	cout << "���°��� �Ϸ�" << endl;
}
void AccountHandler::DepositMoney()
{
	int n, pocket;
	cout << "[�� ��]" << endl;
	cout << "���¹�ȣ�� �Է��ϼ��� : ";
	cin >> n;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetaccID() == n)
		{
			cout << "�Աݾ�: "; cin >> pocket;
			accArr[i]->Deposit(pocket);
			cout << "�Ա� �Ϸ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� �ʴ� �����Դϴ�." << endl;
	return;
}
void AccountHandler::WithDrawMoney()
{
	int n, pocket;
	cout << "[�� ��]" << endl;
	cout << "���¹�ȣ�� �Է��ϼ��� : ";
	cin >> n;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetaccID() == n)
		{
			cout << "��ݾ� : "; cin >> pocket;
			cout << accArr[i]->WithDraw(pocket) << "�� ��� �Ϸ�" << endl;
			return;
		}
	}
	cout << "��ȿ���� �ʴ� �����Դϴ�." << endl;
	return;
}
void AccountHandler::ShowAllAccInfo() const
{
	cout << "[�������� ��ü ���]" << endl;
	for (int i = 0; i < accNum; i++)
		accArr[i]->ShowInfo();
	cout << "��ü ��� �Ϸ�" << endl;
}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}