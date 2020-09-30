// Веретельник Данил ИВТ-8 Лаба 1 Вариант 3 Часть 2

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <conio.h>

using namespace std;

void InitializeArray(float** arr1, int iLen, int jLen){
	for (int i = 0; i < iLen; i++)
		for (int j = 0; j < jLen; j++) {
			*(*(arr1 + i) + j) = float(sqrt(double(i + j + 1)));
		}
}

void ProcessArray(float** arr1, float* arr2, int iLen, int jLen){
	for (int i = 0; i < iLen; i++)
		for (int j = 0; j < jLen; j++)
			*(arr2 + i * iLen + j) =  *(*(arr1 + i) + jLen - 1 - j);
}

void ShowArray1(float** arr2, int iLen, int jLen){
	cout << "[ ";
	for(int i = 0; i < iLen; i++)
		for (int j = 0; j < jLen; j++) {
			if (i > 0 && j == 0) cout << "  ";
			cout << setw(6) << setprecision(3) << *(*(arr2 + i) + j) << " ";
			if (i < iLen - 1 && j == jLen - 1) cout << "\n";
		}
	cout << " ]\n\n";
}

void ShowArray2(float* arr1, int len){
	cout << "[ ";
	for(int i = 0; i < len; i++)
		cout << setprecision(4) << (float)*(arr1 + i) << " ";
	cout << "]\n\n";
}

int main()
{
	float** firstArray = new float*[4];
	for (int i = 0; i < 4; i++)
		firstArray[i] = new float[4];
	float* secondArray = new float[16];

	InitializeArray(firstArray, 4, 4);
	ProcessArray(firstArray, secondArray, 4, 4);
	ShowArray1(firstArray, 4, 4);
	ShowArray2(secondArray, 16);

	for (int i = 0; i < 4; i++)
		delete[] firstArray[i];
	delete[] firstArray;
	delete[] secondArray;

	system("pause");
	return 0;
}