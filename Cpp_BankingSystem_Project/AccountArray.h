#pragma once
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* arr;
	int arrlen;
	BoundCheckAccountPtrArray(BoundCheckAccountPtrArray&) {}
	BoundCheckAccountPtrArray& operator=(BoundCheckAccountPtrArray&) {}

public:
	BoundCheckAccountPtrArray(int len = 100);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR& operator[](int idx)const;
	int GetArrLen()const;
	~BoundCheckAccountPtrArray();
};