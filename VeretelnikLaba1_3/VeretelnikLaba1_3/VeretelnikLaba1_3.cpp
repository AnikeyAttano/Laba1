// Веретельник Данил ИВТ-8 Лаба 1 Вариант 3 Часть 3

#include <cstdio>
#include <string>
using namespace std;

int getLength(char text[]) {
	int arrayLength = 0;
	for (int i = 0; text[i]; i++)
		arrayLength++;
	return arrayLength;
}

void myStrcat(char* arr1, char* arr2) {
	int arr1Length = getLength(arr1);
	int arr2Length = getLength(arr2);
	int totalLength = arr1Length + arr2Length;

	for (int i = arr1Length; i < arr1Length + arr2Length; i++)
		arr1[i] = arr2[i - arr1Length];

	arr1[totalLength] = '\0';
}

int main() {
	char* word1 = new char[32];
	char* word2 = new char[32];

	printf("Enter first word: ");
	scanf("%32s", word1);
	fflush(stdin);
	printf("Enter second word: ");
	scanf("%32s", word2);
	fflush(stdin);
	printf("\n");

	char* myStrcatWord1 = new char[32];
	for (int i = 0; i < 32; i++) myStrcatWord1[i] = word1[i];
	char* myStrcatWord2 = new char[32];
	for (int i = 0; i < 32; i++) myStrcatWord2[i] = word2[i];
	
	printf("myStrcat: ");
	myStrcat(myStrcatWord1, myStrcatWord2);
	printf(myStrcatWord1);
	printf("\n\n");

	char* strcatWord1 = new char[32];
	for (int i = 0; i < 32; i++) strcatWord1[i] = word1[i];
	char* strcatWord2 = new char[32];
	for (int i = 0; i < 32; i++) strcatWord2[i] = word2[i];

	printf("strcat: ");
	strcat(strcatWord1, strcatWord2);
	printf(strcatWord1);
	printf("\n\n");

	delete[] word1;
	delete[] word2;

	system("pause");
	return 0;
}