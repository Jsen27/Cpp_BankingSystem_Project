#pragma once
#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* ptr;
	int arrlen;
public:
	BoundCheckAccountPtrArray(int len = 100);
	
};