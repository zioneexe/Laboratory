#include <stdio.h>
#include <stdarg.h>

void PositiveEvenNumbers(int n, ...) {
	int count = 0;
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		int num = va_arg(args, int);
		if (num > 0 && num % 2 == 0) {
			count++;
			printf("%d ", num);
		}
	}
	printf("\nNumbers found: %d", count);
	va_end(args);
}
