#ifndef FUNC_H
#define FUNC_H

#pragma warning(disable:4996)

#define _CRT_SECURE_NO_WARNINGS
#define BUFF_SIZE 256
#define PRINT 120
#define MAX_STRING 102
#define MAX_INPUT 51
#define MAX_NUM_LEN 21

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct SBook {
	char mAuthor[MAX_INPUT];
	char mName[MAX_INPUT];
	int mPages;
	int mYear;
	double mPrice;
} SBook;

typedef struct SElem {
	SBook mInfo;
	struct SElem* mpNext;
} SElem;

void ReadListFromFile(SElem** ppHead, char* pchFileName);
void WriteListToFile(SElem* pHead, char* pchFileNameWP);
void OutputList(SElem* pHead);
void InitList(SElem** ppHead);
bool isListEmpty(SElem* pHead);
int ListElemCount(SElem* pHead);
void AddElToBeg(SElem** ppHead, SElem* pEl);
void AddElToPos(SElem** ppHead, SElem* pEl, int iPos);
void AddElToEnd(SElem** ppHead, SElem* pEl);
void AddBookToEnd(SElem** ppHead, char pchAuthor[50], char pchName[50], int iPages, int iYear, double dbPrice);
void AddingBooks(SElem** ppHead);
void DelElBeg(SElem** ppHead);
void DelElInside(SElem* pHead, SElem* pDelete);
void DelElEnd(SElem* pHead);
void DelElByPos(SElem** ppHead, int iPos);
void DelPKLBookName(SElem** ppHead, int cCnt);
void DeletingBooks(SElem** ppHead);
void SwapElemsBeg(SElem** ppHead);
void SwapElemsInside(SElem* pHead, SElem* pEl);
void SwapElemsEnd(SElem* pHead);
void ListSortByName(SElem** ppHead);
int AboveAveragePriceBooklist(SElem* pHead, SElem** ppHead2);
void FreeList(SElem** ppHead);
void PrintStars(int iNum);
void PrintX(int iNum);
void PrintMenu();
void Menu(SElem** ppHead);

#endif