#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define N 100

int inputstruct(book b[10]) {
	FILE* fp;
	char* ptr;
	char buffer[N] = { 0 };
	int i = 0;

	fp = fopen("input.txt", "r");
	if (fp == NULL) return 1;
	
	fgets(buffer, N, fp); //зчитування з файлу в структуру
	
	while (!feof(fp)) { 
		ptr = strtok(buffer, ";");
		strcpy(b[i].author, ptr);
		ptr = strtok(NULL, ";");
		strcpy(b[i].name, ptr);
		ptr = strtok(NULL, ";");
		b[i].numofpages = atoi(ptr);
		ptr = strtok(NULL, ";");
		b[i].year = atoi(ptr);
		ptr = strtok(NULL, ";");
		b[i].price = atof(ptr);
		fgets(buffer, N, fp);
		i++;
	}
	fclose(fp);
	return i;
}

void swap(book b[], int n, int m ) {
	book temp;
	temp = b[n];
	b[n] = b[m];
	b[m] = temp;
}

void sort(book b[], int count) {
	float avg, sum=0;
	for (int j = 0; j < count; j++) {
		sum += b[j].price;
	}
	avg = sum / count;

	book selection[100];
	int num = 0, j=0, selected[100];

	for (int i = 0; i < count; i++) { //копіювання в масив структур тих елементи, які вище середнього за ціною
		if (b[i].price > avg) {
			selection[j] = b[i];
			num++;
			j++;
		}
	}

	int swapped,i=0;

	do {
		swapped = 0;
		for (int j = 1; j < num-i; j++) {  //сортування скопійованих елементів за алфавітом
			if (strcmp(selection[j - 1].name, selection[j].name) > 0) {
				swap(selection, j, j - 1);
				swapped = 1;
			}
		}
		i++;
	} while (swapped);
	outputstruct(selection, num);
}

void outputstruct(book b[], int count) {
	printStars(120);
	printf("\n*\tAuthor\t\t*\t      Book Name\t\t\t*     Volume\t*  Published in\t*\tPrice\t\t*\n");
	printStars(120);

	for (int i = 0; i < count; i++) {
		printf("\n*%-20s\t*%-35s\t*\t%-4d\t*\t%-2d\t*\t%-.2f\t\t*\n", b[i].author, b[i].name, b[i].numofpages, b[i].year, b[i].price);
	}
	printStars(120);
}

void printStars(int num) {
	for (int i = 0; i < num; i++) {
		putchar('*');
	}
}