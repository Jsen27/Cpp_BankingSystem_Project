#include "BankingCommonDec1.h"
#include "AccountHandler.h"

int main(void)
{
	AccountHandler manager;
	while (1)
	{
		int select;
		manager.ShowMenu(); cin >> select; cout << endl << endl;
		switch (select)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithDrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			cout << "���α׷� ����" << endl;
			return 0;
		default:
			cout << "�߸� �Է��Ͽ����ϴ�." << endl << endl;
		}
	}

	return 0;
}