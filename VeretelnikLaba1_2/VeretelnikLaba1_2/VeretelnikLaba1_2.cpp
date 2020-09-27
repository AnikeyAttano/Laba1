// Веретельник Данил ИВТ-8 Лаба 1 Вариант 3 Часть 2

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <conio.h>

using namespace std;

void InitializeArray(float* arr1, int iLen, int jLen){
	float* pointer = arr1;
	for (int i = 0; i < iLen; i++)
		for (int j = 0; j < jLen; j++) {
			*pointer = sqrt((double)i + j + 1);
			pointer++;
		}
}

void ProcessArray(float* arr1, float* arr2, int iLen, int jLen){
	float* arr1Pointer = arr1 + jLen - 1;
	float* arr2Pointer = arr2;
	for (int i = 0; i < iLen; i++) {
		for (int j = 0; j < jLen; j++) {
			*arr2Pointer = *arr1Pointer;
			arr1Pointer--;
			arr2Pointer++;
		}
		arr1Pointer += (jLen * 2) - 1;
	}
}

void showArray1(float arr2[], int iLen, int jLen){
	float* arr2Pointer = arr2;
	cout << "[ ";
	for(int i = 0; i < iLen; i++) {
		for (int j = 0; j < jLen; j++) {
			if (i > 0 && j == 0) cout << "  ";

			cout << setw(6) << setprecision(3) << *arr2Pointer << " ";
			arr2Pointer++;

			if (i < iLen - 1 && j == jLen - 1) cout << "\n";
		}
	}
	cout << " ]\n\n";
}

void showArray2(float arr1[], int len){
	float* arr1Pointer = arr1;
	cout << "[ ";
	for(int i = 0; i < len; i++) {
		cout << setprecision(4) << (float)*arr1Pointer << " ";
		arr1Pointer++;
	}
	cout << "]\n\n";
}

int main()
{
	float** firstArray = new float*[4];
	for (int i = 0; i < 4; i++)
		firstArray[i] = new float[4];

	float* secondArray = new float[16];

	InitializeArray(&firstArray[0][0], 4, 4);
	ProcessArray(&firstArray[0][0], secondArray, 4, 4);
	showArray1(&firstArray[0][0], 4, 4);
	showArray2(secondArray, 16);

	system("pause");
	return 0;
}