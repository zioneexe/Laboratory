#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
	double x, y, z, b;
	float s[3], sr[3]={0};
	char mode[100]={0};
	char binary[] = "binary";
	char text[] = "text";
	FILE* f = NULL; //потік для змінних виразу
	
	FILE* t = NULL; //потік для логування часу
	time_t now = time(NULL); 
	struct tm* cur_time = localtime(&now); //отримання локального часу
	char timenow[1000];
	
	t = fopen("log.txt", "a");
	strftime(timenow, 1000, "[%Y.%m.%d %H:%M.0%S]", cur_time); //час у необхідному форматі
	fprintf(t, "%s Program started.\n", timenow);
	
	printf("Enter variables. Make sure x>y\nEnter x, y, z (float):\n");

	for (int i = 0; i < 3; i++) {
		scanf("%f", &s[i]);
	} //ввід змінних x, y та z з клавіатури
	
	f = fopen("input.bin", "wb");
	if (f != NULL) { 
		fwrite(s, sizeof(s[0]), sizeof(s) / sizeof(s[0]), f); 
	} //запис змінних (стрічки) у бінарний файл
	fclose(f);
	
	f = fopen("input.bin", "rb");
	if (f != NULL) {
		fread(sr, sizeof(s[0]), sizeof(s) / sizeof(s[0]), f);
	} //читання змінних (стрічки) з файлу 
	fclose(f);

	x = sr[0], y = sr[1], z = sr[2];
	
	now = time(NULL); //подальші виклики функцій time.h для наступних записів у лог-файлі
	cur_time = localtime(&now);
	strftime(timenow, 1000, "[%Y.%m.%d %H:%M.0%S]", cur_time);
	fprintf(t, "%s Parameters file \"input.bin\" opened. x=%f, y=%f, z=%f.\n", timenow, x, y, z);

	if (((pow(x - y, z) + x * x) != 0) && x >= y) { 
		b = (x + 3 * (x - y) + x * x) / (pow(x - y, z) + x * x);

		now = time(NULL);
		cur_time = localtime(&now);
		strftime(timenow, 1000, "[%Y.%m.%d %H:%M.0%S]", cur_time);
		fprintf(t, "%s Expression calculated. Result = %f.\n", timenow, b);

		printf("\nYour result: %lf", b);
		printf("\nChoose output mode (write 'binary' or 'text'): ");
		scanf("%s", &mode); //зчитування бажаного режиму запису результату обчислень
	
		if (!strcmp(mode, binary)) { //запис у файл у бінарному режиму 
			f=fopen("output.bin", "wb");
			if (f != NULL) {
				fwrite(&b, sizeof(b), 1, f);
				fclose(f);
				printf("Result has been written successfully!"); 
				
				now = time(NULL);
				cur_time = localtime(&now);
				strftime(timenow, 1000, "[%Y.%m.%d %H:%M.0%S]", cur_time);
				fprintf(t, "%s Output file \"output.bin\" saved.\n", timenow); 
			}
		}
		if (!strcmp(mode, text)) { //запис у файл у текстовому режиму 
			f = fopen("output.txt", "w");
			if (f != NULL) {
				fprintf(f, "Your result : %lf", b);
				fclose(f);
				printf("Result has been written successfully!");

				now = time(NULL);
				cur_time = localtime(&now);
				strftime(timenow, 1000, "[%Y.%m.%d %H:%M.0%S]", cur_time);
				fprintf(t, "%s Output file \"output.txt\" saved.\n", timenow);
			}
		}
		if (strcmp(mode, binary) && strcmp(mode, text) != 0) { //якщо введено неправильний режим
			printf("Invalid mode type!");
			now = time(NULL);
			cur_time = localtime(&now);
			strftime(timenow, 1000, "[%Y.%m.%d %H:%M.0%S]", cur_time);
			fprintf(t, "%s Error: invalid mode type.\n", timenow);
		}
	}
	
	else {
		printf("\nTry another numbers! (error:x<y or denominator==0)");
		now = time(NULL);
		cur_time = localtime(&now);
		strftime(timenow, 1000, "[%Y.%m.%d %H:%M.0%S]", cur_time);
		fprintf(t, "%s Error: incorrect input.\n", timenow);
	}

	now = time(NULL);
	cur_time = localtime(&now);
	strftime(timenow, 1000, "[%Y.%m.%d %H:%M.0%S]", cur_time);
	fprintf(t, "%s Program ended.\n", timenow);

	fclose(t);
	return 0;
}