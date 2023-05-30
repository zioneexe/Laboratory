#include "func.h"

//---------------------------------------------------------------------------------

//This function reads data from text (.txt) file to a linked list. (needs filename)  
void ReadListFromFile(SElem** ppHead, char* pchFileName) {

	FILE* fp;
	char* pchPtr;
	char szBuffer[MAX_STRING] = { 0 };
	double dbPrice;
	char szNameBuff[MAX_STRING] = { 0 };

	const char szSymbols[] = " :-_,./'\"|'[]()<>#`~%^&*$@!+={}";

	fp = fopen(pchFileName, "r");
	if (fp == NULL) {
		printf("\nError reading from file: incorrect filename!\n\n");
		exit(1);
	}

	while (!feof(fp)) {
		if (!fgets(szBuffer, MAX_STRING, fp)) {
			printf("\nError reading from file: the file is empty!");
			return;
		};

		if (strlen(szBuffer) > MAX_STRING-1) {
			printf("\nThe book data is too long. The book is skipped.\n");
			fscanf(fp, "%*[^\n]\n");
			continue;
		}

		SElem* pEl = (SElem*)malloc(sizeof(SElem));

		if (pEl) {
			pchPtr = strtok(szBuffer, ";");
			if (strlen(pchPtr) >= MAX_INPUT) {
				printf("\nThe author name and surname is too long. The book of %s is skipped.\n", pchPtr);
				continue;
			}
			
			int iFlag1 = 1, iFlag2 = 1;
			for (int i = 0; szBuffer[i] != '\0'; ++i) {
				if (!isascii(szBuffer[i]) || !isalnum(szBuffer[i])) {
					iFlag1 = 0;
					for (int j = 0; szSymbols[j] != '\0'; ++j) {
						if (szBuffer[i] == szSymbols[j]) {
							iFlag1 = 1;
							break;
						}
					}
				}
			}

			if (!iFlag1) { 
				printf("\nIncorrect input! The book of %s is skipped.\n", pchPtr);
				continue; 
			}

			strcpy(pEl->mInfo.mAuthor, pchPtr);

			pchPtr = strtok(NULL, ";");
			if (strlen(pchPtr) >= MAX_INPUT) {
				printf("\nThe book name is too long. The book %s is skipped.\n", pchPtr);
				continue;
			}

			for (int i = 0; szBuffer[i] != '\0'; ++i) {
				if (!isascii(szBuffer[i]) || !isalnum(szBuffer[i])) {
					iFlag2 = 0;
					for (int j = 0; szSymbols[j] != '\0'; ++j) {
						if (szBuffer[i] == szSymbols[j]) {
							iFlag2 = 1;
							break;
						}
					}
				}
			}

			if (!iFlag2) {
				printf("\nIncorrect input! The book %s is skipped.\n", pchPtr);
				continue;
			}

			strcpy(szNameBuff, pchPtr);
			strcpy(pEl->mInfo.mName, pchPtr);

			pchPtr = strtok(NULL, ";");
			pEl->mInfo.mPages = atoi(pchPtr);
			
			pchPtr = strtok(NULL, ";");
			if (strlen(pchPtr) > 5) {
				printf("\nThe year can only vary from -9999 to 99999. The book %s is skipped.\n", szNameBuff);
				continue;
			}

			pEl->mInfo.mYear = atoi(pchPtr);

			pchPtr = strtok(NULL, ";");
			dbPrice = atof(pchPtr);
			
			if (dbPrice < 0) {
				printf("\nPrice can not be less than 0. The book %s is skipped.\n", szNameBuff);
				continue;
			}

			pEl->mInfo.mPrice = dbPrice;
			AddElToEnd(ppHead, pEl);
		}
		else { 
			printf("\nError: Can't allocate memory!\n");
			exit(4); 
		}
	}
	fclose(fp);

	printf("\n//List is read from \"input.txt//\"\n\n");

	OutputList(*ppHead);
}

//---------------------------------------------------------------------------------

//This function writes data from linked list to text (.txt) or binary (.bin) file on the user's choice. (needs filename without prefix) 
void WriteListToFile(SElem* pHead, char* pchFileNameWP) {
	if (isListEmpty(pHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	char szInput[MAX_INPUT] = { 0 };
	char szFileName[MAX_STRING] = { 0 };

	printf("\nType 1 if you want to write list in text mode, otherwise it'll be written in binary mode.\n");
	scanf("%s", &szInput);

	if (atoi(szInput) == 1) {
		strncat(szFileName, pchFileNameWP, MAX_INPUT);
		strncat(szFileName, ".txt", 4);
		FILE* fp = fopen(szFileName, "w");
		if (fp == NULL) { 
			printf("\nError writing to file: incorrect filename!\n\n");
			exit(1); 
		}

		for (SElem* pCur = pHead; pCur != NULL; pCur = pCur->mpNext) {
			fprintf(fp, "%s;%s;%d;%d;%.2lf;\n", pCur->mInfo.mAuthor, pCur->mInfo.mName, pCur->mInfo.mPages, pCur->mInfo.mYear, pCur->mInfo.mPrice);
		}

		printf("\n//List is written to \"%s\"//\n\n", szFileName);
		fclose(fp);
	}
	else {
		strncat(szFileName, pchFileNameWP, MAX_INPUT);
		strncat(szFileName, ".bin", 4);
		FILE* fp = fopen(szFileName, "wb");
		if (fp == NULL) exit(1);
		
		char szBuffer[BUFF_SIZE] = { 0 };

		for (SElem* pCur = pHead; pCur != NULL; pCur = pCur->mpNext) {
			sprintf_s(szBuffer, BUFF_SIZE, "%s;%s;%d;%d;%.2lf;\n", pCur->mInfo.mAuthor, pCur->mInfo.mName, pCur->mInfo.mPages, pCur->mInfo.mYear, pCur->mInfo.mPrice);
			fwrite(szBuffer, sizeof(char), strlen(szBuffer), fp);
		}

		printf("\n//List is written to \"%s\"//\n\n", szFileName);
		fclose(fp);
	}

}

//---------------------------------------------------------------------------------

//This function outputs given list to console in the form of table.
void OutputList(SElem* pHead) {
	if (isListEmpty(pHead)) {
		printf("\nThe list is empty. Can't print an empty list :(\n");
		return;
	}

	PrintStars(PRINT);
	printf("\n*\tAuthor\t\t*\t      Book Name\t\t\t*     Volume\t*  Published in\t*\tPrice\t\t*\n");
	PrintStars(PRINT);
	
	for (SElem* pCur = pHead;pCur!=NULL;pCur=pCur->mpNext) {
		printf("\n*%-20s\t*%-35s\t*\t%-4d\t*\t%-2d\t*\t%-.2f\t\t*\n", pCur->mInfo.mAuthor, pCur->mInfo.mName, pCur->mInfo.mPages, pCur->mInfo.mYear, pCur->mInfo.mPrice);
	}
	PrintStars(PRINT);
}

//---------------------------------------------------------------------------------

//This function initializes list head with NULL.
void InitList(SElem** ppHead) {
	*ppHead = NULL;
}

//---------------------------------------------------------------------------------

//This function checks if the list is empty. 
bool isListEmpty(SElem* pHead) {
	return NULL == pHead;
}

//---------------------------------------------------------------------------------

//This functions calculates the number of the elements in the list. 
int ListElemCount(SElem* pHead) {
	
	int cCount = 0;
	SElem* pCur = pHead;

	while (pCur) {
		pCur = pCur->mpNext;
		++cCount;
	}

	return cCount;
}

//---------------------------------------------------------------------------------

//This function adds given element to the beginning of the list.
void AddElToBeg(SElem** ppHead, SElem* pEl) {
	
	if (isListEmpty(*ppHead)) {
		*ppHead = pEl;
		pEl->mpNext = NULL;
		return;
	}
	
	pEl->mpNext = *ppHead;
	*ppHead = pEl;
}

//---------------------------------------------------------------------------------

/*This function adds given element to the list to the position specified by user.
Includes functions AddElToBeg and AddElToEnd in it to add elements to the beginning and the end respectively.*/
void AddElToPos(SElem** ppHead, SElem* pEl, int iPos) {
	
	if (iPos < 0 || iPos > ListElemCount(*ppHead)) {
		printf("Error: Wrong index!");
		exit(2);
	}

	if (iPos == 0) {
		AddElToBeg(ppHead, pEl);
		return;
	}

	if (iPos == ListElemCount(*ppHead)) {
		AddElToEnd(ppHead, pEl);
		return;
	}

	SElem* pCur = *ppHead;

	for (int i = 1; i < iPos && pCur->mpNext; pCur = pCur->mpNext, ++i) {}
	pEl->mpNext = pCur->mpNext;
	pCur->mpNext = pEl;
}

//---------------------------------------------------------------------------------

//This function adds given element to the end of the list.
void AddElToEnd(SElem** ppHead, SElem* pEl) {

	if (isListEmpty(*ppHead)) {
		*ppHead = pEl;
		pEl->mpNext = NULL;
		return;
	}
	
	SElem* pCur = *ppHead;

	while (pCur->mpNext != NULL) {
		pCur = pCur->mpNext;
	}
	pCur->mpNext = pEl;
	pEl->mpNext = NULL;
}

//---------------------------------------------------------------------------------

//This function adds creates book (as a new element) with data input by user and adds it to the end of the list.
void AddBookToEnd(SElem** ppHead, char szAuthor[MAX_INPUT], char szName[MAX_INPUT], int iPages, int iYear, double dbPrice) {
	SElem* pNewEl = (SElem*)malloc(sizeof(SElem));

	if (pNewEl) {
		strcpy(pNewEl->mInfo.mAuthor, szAuthor);
		strcpy(pNewEl->mInfo.mName, szName);
		pNewEl->mInfo.mPages = iPages;
		pNewEl->mInfo.mYear = iYear;
		pNewEl->mInfo.mPrice = dbPrice;

		AddElToEnd(ppHead, pNewEl);
	}
	else exit(2);
}

//---------------------------------------------------------------------------------

//This function is made to automatize the process of adding books to the end of the list.
void AddingBooks(SElem** ppHead) {
	
	printf("\n\n\t\t\t\t\t\tAdding mode.\n");

	char szFlag[MAX_NUM_LEN];
	int iFlag;

	do {

		char szAuthor[MAX_INPUT] = { 0 };
		char szName[MAX_INPUT] = { 0 };
		char szPages[MAX_NUM_LEN] = { 0 };
		char szYear[MAX_NUM_LEN] = { 0 };
		char szPrice[MAX_NUM_LEN] = { 0 };
		int iPages;
		int iYear;
		double dbPrice;

		const char szSymbols[] = " :-_,./'\"|'[]()<>#`~%^&*$@!+={}";

		SElem* pNewEl = (SElem*)malloc(sizeof(SElem));

		int iFlag1 = 0, iFlag2 = 0, iFlag3, iFlag4, iFlag5;

			if (pNewEl) {
				printf("Enter the author: \n");
				do {
					iFlag1 = 0;
					scanf("%s", &szAuthor);

					if (strlen(szAuthor) > MAX_INPUT) {
						iFlag1 = 1;
						printf("\nThe author name and surname is too long. Try again!\n");
						continue;
					}

					for (int i = 0; szAuthor[i] != '\0'; ++i) {
						if (!isascii(szAuthor[i]) || !isalnum(szAuthor[i])) {
							iFlag1 = 1;
							for (int j = 0; szSymbols[j] != '\0'; ++j) {
								if (szAuthor[i] == szSymbols[j]) {
									iFlag1 = 0;
									break;
								}
							}
						}
						if (iFlag1) {
							printf("\nIncorrect input. Try again!\n");
						}
					}
				} while (iFlag1);

				strcpy(pNewEl->mInfo.mAuthor, szAuthor);

				printf("Enter the book name: \n");
				do {
					int iFlag2 = 0;
					scanf("%s", &szName);

					if (strlen(szName) >= MAX_INPUT) {
						iFlag2 = 1;
						printf("\nThe book name is too long. Try again!\n");
						continue;
					}

					for (int i = 0; szName[i] != '\0'; ++i) {
						if (!isascii(szName[i]) || !isalnum(szName[i])) {
							iFlag2 = 1;
							for (int j = 0; szSymbols[j] != '\0'; ++j) {
								if (szName[i] == szSymbols[j]) {
									iFlag2 = 0;
								}
							}
						}
						if (iFlag2) {
							printf("\nIncorrect input. Try again!\n");
						}
					}
				} while (iFlag2);

				strcpy(pNewEl->mInfo.mName, szName);

				printf("Enter the number of pages: \n");
				do {
					iFlag3 = 0;
					scanf("%s", &szPages);
					for (int i = 0; i < strlen(szPages); ++i) {
						if (!isdigit(szPages[i])) {
							printf("\nIncorrect num of pages. Try again!\n");
							iFlag3 = 1;
							break;
						}
					}
				} while (iFlag3);

				iPages = atoi(szPages);
				pNewEl->mInfo.mPages = iPages;

				printf("Enter the year: \n");
				do {
					iFlag4 = 0;
					scanf("%s", &szYear);
					if (szYear[0] == '-' || isdigit(szYear[0])) {
						for (int i = 1; i < strlen(szYear); ++i) {
								if (!isdigit(szYear[i])) {
									printf("\nIncorrect input. Try again!\n");
									iFlag4 = 1;
									break;
								}
							}
						}
					else {
						iFlag4 = 1;
						continue;
					}
					iYear = atoi(szYear);
					if (iYear < -9999 || iYear > 99999) {
						printf("\nYear can only vary from -9999 to 99999. Try again.\n");
						iFlag4 = 1;
					}
				} while (iFlag4);

				pNewEl->mInfo.mYear = iYear;

				printf("Enter the price: \n");
				scanf("%s", &szPrice);
				dbPrice = atof(szPrice);
				while (dbPrice < 0) {
					printf("\nPrice can not be less than 0. Try another price!\n");
					scanf("%lf", &dbPrice);
				}
				pNewEl->mInfo.mPrice = dbPrice;
			}
			else exit(5);

		char szPos[MAX_NUM_LEN];
		int iPos;

		do {
			printf("Enter your pos (0 - first Element): \n");
			scanf("%s", &szPos);
			iFlag5 = 0;
			for (int i = 0; i < strlen(szPos); ++i) {
				if (!isdigit(szPos[i])) {
					printf("\nIncorrect input. Try again!\n");
					iFlag5 = 1;
					break;
				}
			}
			if (!iFlag5) {
				iPos = atoi(szPos);
				if (iPos < 0 || iPos >= ListElemCount(*ppHead)) {
					printf("\nIncorrect input. Try again!\n");
					iFlag5 = 1;
				}
			}
		} while (iFlag5);

		AddElToPos(ppHead, pNewEl, iPos);

		printf("Enter \"1\" if you want to stop adding books to the list. \n");
		scanf("%s", &szFlag);
		iFlag = atoi(szFlag);

	} while (iFlag != 1);

	printf("List after adding new books: \n");
	OutputList(*ppHead);
}

//---------------------------------------------------------------------------------

//This function deletes an element in the beginning of the list.
void DelElBeg(SElem** ppHead) {
	
	SElem* pTemp = *ppHead;
	*ppHead = (*ppHead)->mpNext;
	free(pTemp);
}

//---------------------------------------------------------------------------------

//This function deletes an element inside the list.
void DelElInside(SElem* pHead, SElem * pDelete) {
	
	SElem* pCur = pHead;
	while (pCur->mpNext != pDelete) {
		pCur = pCur->mpNext;
	}
	pCur->mpNext = pCur->mpNext->mpNext;

}

//---------------------------------------------------------------------------------

//This function deletes an element in the end of the list.
void DelElEnd(SElem* pHead) {
	
	SElem* pCur = pHead;
	while (pCur->mpNext->mpNext != NULL) {
		pCur = pCur->mpNext;
	}
	SElem* pLast = pCur->mpNext;
	pCur->mpNext = NULL;
	free(pLast);
}

//---------------------------------------------------------------------------------

//This function deletes an element from the list at the position specified by user.
void DelElByPos(SElem** ppHead, int iPos) {
	SElem* pCur = *ppHead;

	if (iPos < 0 || iPos > ListElemCount(*ppHead)) {
		printf("Error: Wrong index!");
		exit(2);
	}
	
	if (iPos == 0) {
		DelElBeg(ppHead);
		return;
	}

	if (iPos == ListElemCount(*ppHead)) {
		DelElEnd(*ppHead);
		return;
	}

	else {
		for (int i = 1; i < iPos && pCur->mpNext; pCur = pCur->mpNext, ++i) {}
		DelElInside(*ppHead, pCur);
		return;
	}
}

//---------------------------------------------------------------------------------

//This function deletes books that have name starting with letter 'P', 'K', 'L' of any case.
void DelPKLBookName(SElem** ppHead, int cCount) {
	if (isListEmpty(*ppHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	SElem* pTemp = *ppHead;
	int iPos = 0, iFlag = 1;
	while (pTemp->mpNext!=NULL)
	{
		if (pTemp->mInfo.mName[0] == 'P' || pTemp->mInfo.mName[0] == 'K' || pTemp->mInfo.mName[0] == 'L' || pTemp->mInfo.mName[0] == 'p' || pTemp->mInfo.mName[0] == 'k' || pTemp->mInfo.mName[0] == 'l') {
			iFlag = 0;
			if (iPos == 0) {
				DelElBeg(ppHead);
				pTemp = *ppHead;
			}
			else if (iPos == cCount) {
				DelElEnd(*ppHead);
			}
			else {
				DelElInside(*ppHead, pTemp);
			}
		}
		pTemp = pTemp->mpNext;
		++iPos;
	}

	if (iFlag) {
		printf("There are no books with the name starting with P, K, L!\n");
	}
	else {
		printf("List after deleting books if their name is starting with P,K,L: \n");
	}
	OutputList(*ppHead);
}

//---------------------------------------------------------------------------------

//This function is made to automatize the process of deleting books from the list at the positions input by user.
void DeletingBooks(SElem** ppHead) {
	if (isListEmpty(*ppHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	printf("\n\n\t\t\t\t\t\tDeleting mode.\n");

	char szFlag[MAX_NUM_LEN];
	int iFlag1, iFlag2;

	do {

		char szPos[MAX_NUM_LEN];
		int iPos;


		do {
			printf("Enter your pos (0 - first element): \n");
			scanf("%s", &szPos);
			iFlag1 = 0;
			for (int i = 0; i < strlen(szPos); ++i) {
				if (!isdigit(szPos[i])) {
					printf("\nIncorrect input. Try again!\n");
					iFlag1 = 1;
					break;
				}
			}
			if (!iFlag1) {
				iPos = atoi(szPos);
				if (iPos < 0 || iPos >= ListElemCount(*ppHead)) {
					printf("\nIncorrect input. Try again!\n");
					iFlag1 = 1;
				}
			}
		} while (iFlag1);

		DelElByPos(ppHead, iPos);

		printf("Enter \"1\" if you want to stop deleting books from the list. \n");
		scanf("%s", &szFlag);
		iFlag2 = atoi(szFlag);

	} while (iFlag2 != 1);

	printf("List after deleting chosen books: \n");
	OutputList(*ppHead);
}

//---------------------------------------------------------------------------------

//This function swaps the first and the second elements of the list.
void SwapElemsBeg(SElem** ppHead) {
	
	SElem* pEl = (*ppHead)->mpNext;
	(*ppHead)->mpNext = pEl->mpNext;
	pEl->mpNext = *ppHead;
	*ppHead = pEl;
}

//---------------------------------------------------------------------------------

//This function swaps two sequential elements inside the list.
void SwapElemsInside(SElem* pHead, SElem* pEl) {
	
	SElem* pCur = pHead;
	for (; pCur->mpNext != pEl; pCur = pCur->mpNext) {}
	SElem* pEl1 = pCur->mpNext;
	SElem* pEl2 = pCur->mpNext->mpNext;
	
	pEl1->mpNext = pEl2->mpNext;
	pEl2->mpNext = pEl1;
	pCur->mpNext = pEl2;
 }

//---------------------------------------------------------------------------------

//This function swaps the last and the second-to-last elements of the list.
void SwapElemsEnd(SElem* pHead) {
	
	SElem* pCur = pHead;
	for (; pCur->mpNext->mpNext->mpNext != NULL; pCur = pCur->mpNext) {}
	
	SElem* pEl = pCur->mpNext;
	SElem* pLast = pCur->mpNext->mpNext;

	pCur->mpNext = pLast;
	pLast->mpNext = pEl;
	pEl->mpNext = NULL;

}

//---------------------------------------------------------------------------------

//This function sorts the list of the books by their name in alphabetic order.
void ListSortByName(SElem** ppHead) {
	if (isListEmpty(*ppHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	for (int i = 0; i < ListElemCount(*ppHead); ++i) {
		int iCount = 1;
		SElem* pCur = *ppHead;

		while (iCount < ListElemCount(*ppHead)-1) {
			SElem* pEl1 = pCur;
			SElem* pEl2 = pCur->mpNext;
			
			if (strcmp(pEl1->mInfo.mName, pEl2->mInfo.mName) > 0) {
				
				if (iCount == 1) {
					SwapElemsBeg(ppHead);
				}

				else if (iCount == ListElemCount(*ppHead)) {
					SwapElemsEnd(*ppHead);
				}
				else {
					SwapElemsInside(*ppHead, pEl1);
					pCur = pEl2;
				}
			}
			pCur = pCur->mpNext;
			++iCount;
		}
	}

	printf("\n\nSorted list: \n\n");
	OutputList(*ppHead);

}

//---------------------------------------------------------------------------------  !

//This function creates sublist of books which are above average of the list given in price.
int AboveAveragePriceBooklist(SElem* pHead, SElem** ppHead2) {
	bool bListCreated = false;

	if (isListEmpty(pHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	SElem* pCur = pHead; 
	double dbAvg = 0;

	for (; pCur != NULL; pCur = pCur->mpNext) {
		dbAvg += pCur->mInfo.mPrice;
	}

	dbAvg /= ListElemCount(pHead);

	pCur = pHead;
	
	do {
		if (pCur && pCur->mInfo.mPrice >= dbAvg) {
			AddBookToEnd(ppHead2, pCur->mInfo.mAuthor, pCur->mInfo.mName, pCur->mInfo.mPages, pCur->mInfo.mYear, pCur->mInfo.mPrice);
			bListCreated = true;
		}
		pCur = pCur->mpNext;
	} while (pCur && pCur->mpNext != NULL);
	return bListCreated;

	printf("\n\nAbove average price book list: \n\n");
	OutputList(*ppHead2);
}

//---------------------------------------------------------------------------------

//This function frees dynamically allocated memory of the list.
void FreeList(SElem **ppHead) {
	if (isListEmpty(*ppHead)) {
		return;
	}

	SElem* pCur = *ppHead;

	while (pCur) {
		*ppHead = pCur->mpNext;
		free(pCur);
		pCur = *ppHead;
	}

	*ppHead = NULL;

	printf("\n\n\t\t\t\t\t\tThe list is cleansed!");
}

//---------------------------------------------------------------------------------

//This function prints '*' symbols in a given quantity.
void PrintStars(int iNum) {
	for (int i = 0; i < iNum; ++i) {
		putchar('*');
	}
}

//---------------------------------------------------------------------------------

//This function prints 'x' symbols in a given quantity.
void PrintX(int iNum) {
	for (int i = 0; i < iNum; ++i) {
		putchar('x');
	}
}

//---------------------------------------------------------------------------------

//This function prints the graphical representation of the program menu.
void PrintMenu() {
	PrintX(PRINT);
	printf("x\t\t\t\t\t\t\t//BooksDB::List//\t\t\t\t\t\tx\n");
	PrintX(PRINT);
	printf("x\tType number needed to do the action and enjoy the show :)\t\t\t\t\t\t\tx\n");
	PrintX(PRINT);
	printf("x\t1\tx\tRead list from file\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t2\tx\tWrite list to file\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t3\tx\tAdding books\t\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t4\tx\tDeleting books\t\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t5\tx\tSort list\t\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t6\tx\tSpecial: Delete PKL\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t7\tx\tSpecial: Sort above average\t\t\t\t\t\t\t\t\tx\n");
	PrintX(PRINT);
	printf("\nx\t8\tx\tExit\t\t\t\t\t\t\t\t\t\t\t\tx\n");
	PrintX(PRINT);
}

//---------------------------------------------------------------------------------

//This function implements the menu of the program. A user can choose an action they need and it will call a corresponding function.
void Menu(SElem** ppHead) {
	PrintMenu();

	char szInput[MAX_INPUT] = {0};
	int iOption = 0;

	do {
		printf("\n\n//  ");
		scanf("%s", &szInput);
		iOption = atoi(szInput);

		
		if (iOption == 1) {
			char sFILENAME[MAX_INPUT];
			printf("Enter the name of the file to read from: ");
			scanf("%s", &sFILENAME);
			ReadListFromFile(ppHead, sFILENAME);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (iOption == 2) {
			char sFILENAME_WP[MAX_INPUT];
			printf("Enter the name of the file (without the type prefix) to write to: ");
			scanf("%s", &sFILENAME_WP);
			WriteListToFile(*ppHead, sFILENAME_WP);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (iOption == 3) {
			AddingBooks(ppHead);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (iOption == 4) {
			DeletingBooks(ppHead);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (iOption == 5) {
			if (isListEmpty(*ppHead)) {
				printf("\nThe list is empty. Try reading it by typing \"1\" !\n\n");
				PrintMenu();
				continue;
			}

			ListSortByName(ppHead);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (iOption == 6) {
			if (isListEmpty(*ppHead)) {
				printf("\nThe list is empty. Try reading it by typing \"1\" !\n\n");
				PrintMenu();
				continue;
			}

			DelPKLBookName(ppHead, ListElemCount(*ppHead));
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (iOption == 7) {
			if (isListEmpty(*ppHead)) {
				printf("\nThe list is empty. Try reading it by typing \"1\" !\n\n");
				PrintMenu();
				continue;
			}

			SElem* pHead2;
			InitList(&pHead2);
			if (AboveAveragePriceBooklist(*ppHead, &pHead2)) {
				ListSortByName(&pHead2);
				printf("\n\n...function ended its work\n\n");
				PrintMenu();
			}
			else {
				printf("\n\nError creating new list...\n");
			}
		}

		else if (iOption == 8) {
			FreeList(ppHead);
			printf("\n\n\t\t\t\t\t\tExiting program... \n\n");
			exit(0);
		}

		else {
			printf("\nOption #%s does not yet exist! Try another one.\n", szInput);
		}

	} while (iOption != 8);
}

//---------------------------------------------------------------------------------