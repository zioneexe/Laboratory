#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main() {
	
	int k = 0, len;
	char str[100]={0};
	char str2[100]={0};
	char consonants[] = "bcdfghjklmnpqrstvwxyz"; //множина приголосних
	char* p;
	
	printf("//Latin alphabet only//\n");
	printf("Enter your sentence.\nExample:\"Lorem ipsum dolor sit amet.\"\n");
	fgets(str, 100, stdin); 
	
	if (strchr(str, '.') != NULL) { //перевірка на наявність крапки в кінці речення
		for (int i = 0; i < strlen(str); i++) {
			str[i] = tolower(str[i]);
		} //переведення усіх літер у нижній регістр
	
		for (int i = 0; i < strlen(consonants); i++) {
			for (;(strchr(str, consonants[i]) != NULL) && (strchr(str, consonants[i]) < strchr(str, '.')) ; k++) { //ігнорування символів після крапки
				p = strchr(str, consonants[i]);
				str2[k] = *p;
				*p = ' ';
			} //пошук приголосних у реченні, заміна знайдених пробілами, запис приголосних у стрічку str2
		}
		str2[k] = '\0';
		len = strlen(str2); //довжина стрічки = к-сть приголосних
		
		if (len == 0) {
			printf("There are no consonants in the sentence!");
		}
		else {
			printf("Consonants are: %s\n", str2);
			printf("The number of consonants in the given sentence is: %d", len);
		}
	}
	else {
		printf("Your sentence must end with '.' symbol!");
	}

	return 0;
}

