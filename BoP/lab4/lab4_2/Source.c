#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main() {
	
	int k = 0, len;
	char str[100]={0};
	char str2[100]={0};
	char consonants[] = "bcdfghjklmnpqrstvwxyz"; //������� �����������
	char* p;
	
	printf("//Latin alphabet only//\n");
	printf("Enter your sentence.\nExample:\"Lorem ipsum dolor sit amet.\"\n");
	fgets(str, 100, stdin); 
	
	if (strchr(str, '.') != NULL) { //�������� �� �������� ������ � ���� �������
		for (int i = 0; i < strlen(str); i++) {
			str[i] = tolower(str[i]);
		} //����������� ��� ���� � ����� ������
	
		for (int i = 0; i < strlen(consonants); i++) {
			for (;(strchr(str, consonants[i]) != NULL) && (strchr(str, consonants[i]) < strchr(str, '.')) ; k++) { //����������� ������� ���� ������
				p = strchr(str, consonants[i]);
				str2[k] = *p;
				*p = ' ';
			} //����� ����������� � ������, ����� ��������� ��������, ����� ����������� � ������ str2
		}
		str2[k] = '\0';
		len = strlen(str2); //������� ������ = �-��� �����������
		
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

