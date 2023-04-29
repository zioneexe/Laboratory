#ifndef FUNC_H
#define FUNC_H
#define N 100
typedef struct book {
	char author[N];
	char name[N];
	int numofpages;
	int year;
	float price;
} book;


int inputstruct(book b[]);
void outputstruct(book b[], int count);
void swap(book b[], int n, int m);
void sort(book b[], int count);
void printStars(int num);
#endif

