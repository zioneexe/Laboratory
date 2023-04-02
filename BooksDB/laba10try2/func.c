#include "func.h"

//не працює сортування, коли додаєш елементи вручну

void ReadListFromFile(Elem** ppHead, char* FILENAME) {
	
	FILE* fp;
	char* ptr;
	char buffer[100] = { 0 };

	fp = fopen(FILENAME, "r");
	if (fp == NULL) exit(1);


	while (!feof(fp)) {
		fgets(buffer, 100, fp);
		Elem* El = (Elem*)malloc(sizeof(Elem));

		if (El) {
			ptr = strtok(buffer, ";");
			strcpy(El->mInfo.mAuthor, ptr);
			ptr = strtok(NULL, ";");
			strcpy(El->mInfo.mName, ptr);
			ptr = strtok(NULL, ";");
			El->mInfo.mPages = atoi(ptr);
			ptr = strtok(NULL, ";");
			El->mInfo.mYear = atoi(ptr);
			ptr = strtok(NULL, ";");
			El->mInfo.mPrice = atof(ptr);
			AddElToEnd(ppHead, El);
		}
		else exit(4);
	}
	fclose(fp);

	printf("\n//List is read from \"input.txt//\"\n\n");
}

void WriteListToFile(Elem* pHead, char* FILENAME_WP) {
	if (isListEmpty(pHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	int mode;
	char FILENAME[100] = { 0 };

	printf("\nType 0 if you want to write list in binary mode, otherwise it'll be written in text mode.\n");
	scanf("%d", &mode);

	if (mode) {
		strncat(FILENAME, FILENAME_WP, 50);
		strncat(FILENAME, ".txt", 4);
		FILE* fp = fopen(FILENAME, "w");
		if (fp == NULL) exit(1);

		for (Elem* Curr = pHead; Curr != NULL; Curr = Curr->mpNext) {
			fprintf(fp, "%s;%s;%d;%d;%.2lf;\n", Curr->mInfo.mAuthor, Curr->mInfo.mName, Curr->mInfo.mPages, Curr->mInfo.mYear, Curr->mInfo.mPrice);
		}

		printf("\n//List is written to \"%s\"//\n\n", FILENAME);
		fclose(fp);
	}
	else {
		strncat(FILENAME, FILENAME_WP, 50);
		strncat(FILENAME, ".bin", 4);
		FILE* fp = fopen(FILENAME, "wb");
		if (fp == NULL) exit(1);
		
		char buffer[256] = { 0 };

		for (Elem* Curr = pHead; Curr != NULL; Curr = Curr->mpNext) {
			sprintf_s(buffer, 256, "%s;%s;%d;%d;%.2lf;\n", Curr->mInfo.mAuthor, Curr->mInfo.mName, Curr->mInfo.mPages, Curr->mInfo.mYear, Curr->mInfo.mPrice);
			fwrite(buffer, sizeof(char), strlen(buffer), fp);
		}

		printf("\n//List is written to \"%s\"//\n\n", FILENAME);
		fclose(fp);
	}

}

void OutputList(Elem* pHead) {
	if (isListEmpty(pHead)) {
		printf("The list is empty. Can't print an empty list :(");
		return;
	}

	PrintStars(120);
	printf("\n*\tAuthor\t\t*\t      Book Name\t\t\t*     Volume\t*  Published in\t*\tPrice\t\t*\n");
	PrintStars(120);
	
	for (Elem* Curr = pHead;Curr!=NULL;Curr=Curr->mpNext) {
		printf("\n*%-20s\t*%-35s\t*\t%-4d\t*\t%-2d\t*\t%-.2f\t\t*\n", Curr->mInfo.mAuthor, Curr->mInfo.mName, Curr->mInfo.mPages, Curr->mInfo.mYear, Curr->mInfo.mPrice);
	}
	PrintStars(120);
}

void InitList(Elem** ppHead) {
	*ppHead = NULL;
}

int isListEmpty(Elem* pHead) {
	return NULL == pHead;
}

int ListElemCount(Elem* pHead) {
	
	int q = 0;
	Elem* Curr = pHead;

	while (Curr) {
		Curr = Curr->mpNext;
		++q;
	}

	return q;
}

void AddElToBeg(Elem** ppHead, Elem* El) {
	
	if (isListEmpty(*ppHead)) {
		*ppHead = El;
		El->mpNext = NULL;
		return;
	}
	
	El->mpNext = *ppHead;
	*ppHead = El;
}

void AddElToPos(Elem** ppHead, Elem* El, int pos) {
	
	if (pos < 0 || pos > ListElemCount(*ppHead)) {
		exit(2);
	}

	if (pos == 0) {
		AddElToBeg(ppHead, El);
		return;
	}

	if (pos == ListElemCount(*ppHead)) {
		AddElToEnd(ppHead, El);
		return;
	}

	Elem* Curr = *ppHead;

	for (int q = 1; q < pos && Curr->mpNext; Curr = Curr->mpNext, ++q) {
	}
	El->mpNext = Curr->mpNext;
	Curr->mpNext = El;
}

void AddElToEnd(Elem** ppHead, Elem* El) {

	if (isListEmpty(*ppHead)) {
		*ppHead = El;
		El->mpNext = NULL;
		return;
	}
	
	Elem* Curr = *ppHead;

	while (Curr->mpNext != NULL) {
		Curr = Curr->mpNext;
	}
	Curr->mpNext = El;
	El->mpNext = NULL;
}

void AddBookToEnd(Elem** ppHead, char Author[50], char Name[50], int Pages, int Year, double Price) {
	Elem* NewEl = (Elem*)malloc(sizeof(Elem));

	if (NewEl) {
		strcpy(NewEl->mInfo.mAuthor, Author);
		strcpy(NewEl->mInfo.mName, Name);
		NewEl->mInfo.mPages = Pages;
		NewEl->mInfo.mYear = Year;
		NewEl->mInfo.mPrice = Price;

		AddElToEnd(ppHead, NewEl);
	}
	else exit(2);
}

void AddingBooks(Elem** ppHead) {
	
	printf("\n\n\t\t\t\t\t\tAdding mode.\n");

	int flag;

	do {

		char Author[50] = { 0 };
		char Name[50] = { 0 };
		int Pages;
		int Year;
		double Price;

		Elem* NewEl = (Elem*)malloc(sizeof(Elem));

			if (NewEl) {
				printf("Enter the author: \n");
				scanf("%s", &Author);
				strcpy(NewEl->mInfo.mAuthor, Author);

				printf("Enter the book name: \n");
				scanf("%s", &Name);
				strcpy(NewEl->mInfo.mName, Name);

				printf("Enter the number of pages: \n");
				scanf("%d", &Pages);
				NewEl->mInfo.mPages = Pages;

				printf("Enter the year: \n");
				scanf("%d", &Year);
				NewEl->mInfo.mYear = Year;

				printf("Enter the price: \n");
				scanf("%lf", &Price);
				if (Price < 0) {
					printf("\nPrice can not be less than 0. Try another price!\n");
					scanf("%lf", &Price);
				}
				NewEl->mInfo.mPrice = Price;
			}
			else exit(5);

		int pos;
		printf("Enter your pos (0 - first element): \n");
		scanf("%d", &pos);

		AddElToPos(ppHead, NewEl, pos);

		printf("Enter zero-number if you want to stop adding books to the list. \n");
		scanf("%d", &flag);

	} while (flag);
}

void DelElBeg(Elem** ppHead) {
	
	Elem* pTemp = *ppHead;
	*ppHead = (*ppHead)->mpNext;
	free(pTemp);
}

void DelElInside(Elem* pHead, Elem * Delete) {
	
	Elem* Curr = pHead;
	while (Curr->mpNext != Delete) {
		Curr = Curr->mpNext;
	}
	//Elem* pFree = Curr->mpNext;
	Curr->mpNext = Curr->mpNext->mpNext;
	//free(pFree);
}

void DelElEnd(Elem* pHead) {
	
	Elem* Curr = pHead;
	while (Curr->mpNext->mpNext != NULL) {
		Curr = Curr->mpNext;
	}
	Elem* Last = Curr->mpNext;
	Curr->mpNext = NULL;
	free(Last);
}

void DelElByPos(Elem** ppHead, int pos) {
	Elem* Curr = *ppHead;

	if (pos < 0 || pos > ListElemCount(*ppHead)) {
		exit(2);
	}
	
	if (pos == 0) {
		DelElBeg(ppHead);
		return;
	}

	if (pos == ListElemCount(*ppHead)) {
		DelElEnd(*ppHead);
		return;
	}

	else {
		for (int q = 1; q < pos && Curr->mpNext; Curr = Curr->mpNext, ++q) {}
		DelElInside(*ppHead, Curr);
		return;
	}
}

void DelPKLBookName(Elem** ppHead, int cnt) {
	if (isListEmpty(*ppHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	Elem* pTemp = *ppHead;
	int pos = 0;
	while (pTemp->mpNext!=NULL)
	{
		if (pTemp->mInfo.mName[0] == 'P' || pTemp->mInfo.mName[0] == 'K' || pTemp->mInfo.mName[0] == 'L' || pTemp->mInfo.mName[0] == 'p' || pTemp->mInfo.mName[0] == 'k' || pTemp->mInfo.mName[0] == 'l') {
			if (pos == 0) {
				DelElBeg(ppHead);
				pTemp = *ppHead;
			}
			else if (pos == cnt) {
				DelElEnd(*ppHead);
			}
			else {
				DelElInside(*ppHead, pTemp);
			}
		}
		pTemp = pTemp->mpNext;
		++pos;
	}
}

void DeletingBooks(Elem** ppHead) {
	if (isListEmpty(*ppHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	printf("\n\n\t\t\t\t\t\tDeleting mode.\n");

	int flag;

	do {

		int pos;
		printf("Enter your pos (0 - first element): \n");
		scanf("%d", &pos);

		DelElByPos(ppHead, pos);

		printf("Enter zero-number if you want to stop deleting books from the list. \n");
		scanf("%d", &flag);

	} while (flag);

}

void SwapElemsBeg(Elem** ppHead) {

	Elem* El = (*ppHead)->mpNext;
	(*ppHead)->mpNext = El->mpNext;
	El->mpNext = *ppHead;
	*ppHead = El;
}

void SwapElemsInside(Elem* pHead, Elem* El) {
	
	Elem* Curr = pHead;
	for (; Curr->mpNext != El; Curr = Curr->mpNext) {}
	Elem* El1 = Curr->mpNext;
	Elem* El2 = Curr->mpNext->mpNext;
	
	El1->mpNext = El2->mpNext;
	El2->mpNext = El1;
	Curr->mpNext = El2;
 }

void SwapElemsEnd(Elem* pHead) {
	
	Elem* Curr = pHead;
	for (; Curr->mpNext->mpNext->mpNext != NULL; Curr = Curr->mpNext) {}
	
	Elem* El = Curr->mpNext;
	Elem* Last = Curr->mpNext->mpNext;

	Curr->mpNext = Last;
	Last->mpNext = El;
	El->mpNext = NULL;

}

void ListSortByName(Elem** ppHead) {
	if (isListEmpty(*ppHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	for (int i = 0; i < ListElemCount(*ppHead); ++i) {
		int q = 1;
		Elem* Curr = *ppHead;

		while (q < ListElemCount(*ppHead)-1) {
			Elem* El1 = Curr;
			Elem* El2 = Curr->mpNext;
			
			if (strcmp(El1->mInfo.mName, El2->mInfo.mName) > 0) {
				
				if (q == 1) {
					SwapElemsBeg(ppHead);
				}

				else if (q == ListElemCount(*ppHead)) {
					SwapElemsEnd(*ppHead);
				}
				else {
					SwapElemsInside(*ppHead, El1);
					Curr = El2;
				}
			}
			Curr = Curr->mpNext;
			++q;
		}
	}
}

int AboveAveragePriceBooklist(Elem* pHead, Elem** ppHead2) {
	int listcreated = 0;

	if (isListEmpty(pHead)) {
		printf("\nThe list is empty. Try reading it by typing \"1\" !");
		return;
	}

	Elem* Curr = pHead; 
	double avg = 0;

	for (; Curr != NULL; Curr = Curr->mpNext) {
		avg += Curr->mInfo.mPrice;
	}

	avg /= ListElemCount(pHead);

	Curr = pHead;
	
	do {
		if (Curr && Curr->mInfo.mPrice >= avg) {
			AddBookToEnd(ppHead2, Curr->mInfo.mAuthor, Curr->mInfo.mName, Curr->mInfo.mPages, Curr->mInfo.mYear, Curr->mInfo.mPrice);
			listcreated = 1;
		}
		Curr = Curr->mpNext;
	} while (Curr && Curr->mpNext != NULL);
	return listcreated;
}

void FreeList(Elem **ppHead) {
	if (isListEmpty(*ppHead)) {
		return;
	}

	Elem* Curr = *ppHead;

	while (Curr) {
		*ppHead = Curr->mpNext;
		free(Curr);
		Curr = *ppHead;
	}

	*ppHead = NULL;
}

void PrintStars(int num) {
	for (int i = 0; i < num; ++i) {
		putchar('*');
	}
}

void PrintX(int num) {
	for (int i = 0; i < num; ++i) {
		putchar('x');
	}
}

void PrintMenu() {
	PrintX(120);
	printf("x\t\t\t\t\t\t\t//BooksDB::List//\t\t\t\t\t\tx\n");
	PrintX(120);
	printf("x\tType number needed to do the action and enjoy the show :)\t\t\t\t\t\t\tx\n");
	PrintX(120);
	printf("x\t1\tx\tRead list from file\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t2\tx\tWrite list to file\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t3\tx\tAdding books\t\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t4\tx\tDeleting books\t\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t5\tx\tSort list\t\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t6\tx\tSpecial: Delete PKL\t\t\t\t\t\t\t\t\t\tx\n");
	printf("x\t7\tx\tSpecial: Sort above average\t\t\t\t\t\t\t\t\tx\n");
	PrintX(120);
	printf("\nx\t8\tx\tExit\t\t\t\t\t\t\t\t\t\t\t\tx\n");
	PrintX(120);
}

void Menu(Elem** ppHead) {
	PrintMenu();

	int option = 1;

	while (option != 8) {
		printf("\n\n//  ");
		scanf("%d", &option);
		
		if (option == 1) {
			ReadListFromFile(ppHead, "input.txt");
			OutputList(*ppHead);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (option == 2) {
			WriteListToFile(*ppHead, "output");
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (option == 3) {
			AddingBooks(ppHead);
			printf("List after adding new books: \n");
			OutputList(*ppHead);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (option == 4) {
			DeletingBooks(ppHead);
			printf("List after deleting chosen books: \n");
			OutputList(*ppHead);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (option == 5) {
			if (isListEmpty(*ppHead)) {
				printf("\nThe list is empty. Try reading it by typing \"1\" !\n\n");
				PrintMenu();
				continue;
			}

			ListSortByName(ppHead);
			printf("\n\nSorted list: \n\n");
			OutputList(*ppHead);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (option == 6) {
			if (isListEmpty(*ppHead)) {
				printf("\nThe list is empty. Try reading it by typing \"1\" !\n\n");
				PrintMenu();
				continue;
			}

			DelPKLBookName(ppHead, ListElemCount(*ppHead));
			printf("List after deleting books if their name is starting with P,K,L: \n");
			OutputList(*ppHead);
			printf("\n\n...function ended its work\n\n");
			PrintMenu();
		}
		
		else if (option == 7) {
			if (isListEmpty(*ppHead)) {
				printf("\nThe list is empty. Try reading it by typing \"1\" !\n\n");
				PrintMenu();
				continue;
			}

			Elem* pHead2;
			InitList(&pHead2);
			if (AboveAveragePriceBooklist(*ppHead, &pHead2)) {
				printf("\n\nAbove average price book list: \n\n");
				OutputList(pHead2);

				ListSortByName(&pHead2);
				printf("\n\nSorted list: \n\n");
				OutputList(pHead2);
				printf("\n\n...function ended its work\n\n");
				PrintMenu();
			}
			else {
				printf("\n\nError creating new list...\n");
			}
		}

		else if (option == 8) {
			FreeList(ppHead);
			printf("\n\n\t\t\t\t\t\tThe list is cleansed!");
			printf("\n\n\t\t\t\t\t\tExiting program... \n\n");
			exit(0);
		}

		else {
			printf("\nOption #%d does not yet exist! Try another one.\n", option);
		}

	}
}