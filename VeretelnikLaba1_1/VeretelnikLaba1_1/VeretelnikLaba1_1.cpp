// Веретельник Данил ИВТ-8 Лаба 1 Вариант 3 Часть 1

#include <iostream>
using namespace std;

int processArray(float* arr, int len, int Q) {

	// Исходные данные
	int b1 = 2;

	// Заполнение исходного массива
	for (int i = 0; i < len; i++) {
		arr[i] = b1;
		b1 *= Q;
	}

	// Определение трехзначных чисел
	int cnt1 = 0;
	bool* temp1 = new bool[len];
	for (int i = 0; i < len; i++) {
		if (abs(arr[i]) >= 100 && abs(arr[i]) < 1000) {
			temp1[i] = true;
			cnt1++;
		}
		else 
			temp1[i] = false;
	}

	// Определение чисел делимых на 3 с остатком 1
	int cnt2 = 0;
	bool* temp2 = new bool[len];
	for (int i = 0; i < len; i++) {
		if (int(arr[i]) % 3 == 1) {
			temp2[i] = true;
			cnt2++;
		}
		else 
			temp2[i] = false;
	}
	
	// Заполнение выводимого массива
	float* returnArray = new float[cnt2];
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (temp2[i] == true) {
			returnArray[j] = arr[i];
			j++;
		}
	}

	// выводим выходной массив
	cout << "\nReturn Array (%3==1): {";
	for (int i = 0; i < cnt2; i++) {
		cout << returnArray[i];
		if (i < cnt2 - 1) cout << ", ";
	}
	cout << "}";

	delete [] returnArray;
	delete [] temp1;
	delete [] temp2;
	return cnt1;
}

int main()
{
	float myArray[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int Q = 0;
	
	printf("%s", "Enter Q: ");
	scanf("%d", &Q);
	fflush(stdin);

	int cnt = processArray(myArray, 10, Q);

	printf("%s", "\nThree-digit nums: ");
	printf("%u", cnt);
	printf("%s", "\n");

	system("pause");
	return 0;
}