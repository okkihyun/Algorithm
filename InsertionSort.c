#include <stdio.h>

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void InserSort(int arr[], int size) {
	int step, i;

	for (step = 1;step < size;step++) {
		printf("%d step : ", step);
		for (i = 0;i < step;i++) {
			if (arr[i] > arr[step]) swap(&arr[i], &arr[step]);
			}
		for (i = 0;i < size;i++)  printf("%d ", arr[i]);
		printf("\n");
	}
}

int main() {
	int i, size;
	int arr[100] = { 0, };

	printf("��ü ������ : ");
	scanf_s("%d", &size);

	printf("������ ���� �Է��Ͻÿ� : ");
	for (i = 0; i < size;i++) {
		scanf_s("%d", &arr[i]);
	}

	InserSort(arr, size);
}