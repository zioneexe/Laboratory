#ifndef FUNC_H
#define FUNC_H

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
	char mAuthor[50];
	char mName[50];
	int mPages;
	int mYear;
	double mPrice;
} Book;

typedef struct Elem {
	Book mInfo;
	struct Elem* mpNext;
} Elem;

void ReadListFromFile(Elem** ppHead, char* FILENAME);
void WriteListToFile(Elem* pHead, char* FILENAME);
void OutputList(Elem* pHead);
void InitList(Elem** ppHead);
int isListEmpty(Elem* pHead);
int ListElemCount(Elem* pHead);
void AddElToBeg(Elem** ppHead, Elem* El);
void AddElToPos(Elem** ppHead, Elem* El, int pos);
void AddElToEnd(Elem** ppHead, Elem* El);
void AddBookToEnd(Elem** ppHead, char Author[50], char Name[50], int Pages, int Year, double Price);
void AddingBooks(Elem** ppHead);
void DelElBeg(Elem** ppHead);
void DelElInside(Elem* pHead, Elem* Delete);
void DelElEnd(Elem* pHead);
void DelElByPos(Elem** ppHead, int pos);
void DelPKLBookName(Elem** ppHead, int cnt);
void DeletingBooks(Elem** ppHead);
void SwapElemsBeg(Elem** ppHead);
void SwapElemsInside(Elem* pHead, Elem* El);
void SwapElemsEnd(Elem* pHead);
void ListSortByName(Elem** ppHead);
int AboveAveragePriceBooklist(Elem* pHead, Elem** ppHead2);
void FreeList(Elem** ppHead);
void PrintStars(int num);
void PrintX(int num);
void PrintMenu();
void Menu(Elem** ppHead);

#endif