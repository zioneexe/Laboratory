#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
#include <stdio.h>
#include <string.h>
#define N 1000

int StrContainsSubStr(char* string, char* substring) {

	//char* p=NULL;
	char* pS = string;
	char* pSS = substring;
	int n = 0, count=0;
	//int flag = 0;

	while (*pS != '\n' && *pSS != '\n') {
		if ((*pS == *pSS && *pSS=='\0') || *pS=='\0' || *pS=='.') break;
		while (*pS == *pSS && *pS != '\n') {
			//flag = 1;
			pS++, pSS++;
			if (*pSS == '\n') {
				count++; n = 1;// p = pS - strlen(pSS);
			}
		}
		
		//flag = 0;
		if(!n) pS++;
		n = 0;
		pSS = substring;
		
	}

//	if (!flag) return 0;
	return count;
//	else return p;
}

int MaxNumofOcc(char arrofstrs[][N], char* substring, int num) {
	int max=-1, order=1;
	
	for (int i = 0; i < num; i++) {
		if (StrContainsSubStr(arrofstrs[i],substring) > max) {
			max = StrContainsSubStr(arrofstrs[i], substring);
			order = i;
		}
	}
	return order;
}

void InputArray(char arrofstrs[][N], char* substring, int num) {

	for (int j = 0; j < num; j++) {
		printf("Enter sentence %d: ", j + 1);
		fgets(arrofstrs[j], N, stdin);
		if (strchr(arrofstrs[j], '.') != NULL) { //перевірка на наявність крапки в кінці речення
			for (int i = 0; i < strlen(arrofstrs[j]); i++) {
				arrofstrs[j][i] = tolower(arrofstrs[j][i]);
			} //переведення усіх літер у нижній регістр
		}
		else {
			printf("Your sentence must end with '.' symbol!\n");
			exit(1);
		}
	}

	printf("Enter your substring: ");
	fgets(substring, N, stdin);

}

void CheckArray(char arrofstrs[][N], char* substring, int num) {
	for (int i = 0; i < num; i++) {
		printf("Occurrences found (sentence %d): %d \n", i+1, StrContainsSubStr(arrofstrs[i], substring));
	}
}