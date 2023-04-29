#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"
#define N 100

int main() {
	book b[N];
	inputstruct(b);

	printf("\t\t\t\t\t\tNot sorted struct:\n\n");
	outputstruct(b, inputstruct(b));
	printf("\t\t\t\t\t\tSorted list (alphabetical order, >avg):\n\n");
	sort(b, inputstruct(b));

	return 0;
}