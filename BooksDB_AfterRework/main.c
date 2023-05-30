#include "func.h"

int main() {
	system("chcp 1251");
	system("cls");

	SElem* pHead=NULL;
	InitList(&pHead);
	Menu(&pHead);

	return 0;
}