// ����������� ����� ���-8 ���� 1 ������� 3 ����� 1

#include <iostream>
using namespace std;

int processArray(float* arr, int len, int Q) {

	// �������� ������
	int b1 = 2;

	// ���������� ��������� �������
	for (int i = 0; i < len; i++) {
		arr[i] = b1;
		b1 *= Q;
	}

	// ����������� ����������� �����
	int cnt1 = 0;
	for (int i = 0; i < len; i++)
		if (abs(arr[i]) >= 100 && abs(arr[i]) < 1000)
			cnt1++;

	// ����������� ����� ������� �� 3 � �������� 1
	int cnt2 = 0;
	for (int i = 0; i < len; i++)
		if (int(arr[i]) % 3 == 1)
			cnt2++;
	
	// ���������� ���������� �������
	float* returnArray = new float[cnt2];
	int j = 0;
	for (int i = 0; i < len; i++)
		if (int(arr[i]) % 3 == 1) {
			returnArray[j] = arr[i];
			j++;
		}

	// ������� �������� ������
	printf("%s", "\nReturn Array (%3==1): {");
	for (int i = 0; i < cnt2; i++) {
		cout << returnArray[i];
		if (i < cnt2 - 1)
			printf("%s", ", ");
	}
	printf("%s", "}");

	delete [] returnArray;
	return cnt1;
}

int main()
{
	float myArray[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int Q = 0;
	
	printf("%s", "Enter Q: ");
	scanf("%d", &Q);

	int cnt = processArray(myArray, 10, Q);

	printf("%s", "\nThree-digit nums: ");
	printf("%u", cnt);
	printf("%s", "\n");

	system("pause");
	return 0;
}