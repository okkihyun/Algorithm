#include <stdio.h>

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void BubbleSort(int arr[], int size) {
	int total_step = size - 1;
	int i, j;
	int largest;
	int count = size-1;
	
	for (i = 0;i < total_step;i++) {
		printf("%d step : ", i+1);

		for (j = 0;j < count;j++) {
			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
		count--;

		for (j = 0;j < size;j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
}

int main() {
	int i;
	int size;
	int arr[100] = { 0, };

	printf("정렬할 사이즈 : ");
	scanf_s("%d", &size);

	printf("정렬할 수를 입력하시오 : ");
	for (i = 0; i < size;i++) {
		scanf_s("%d ", &arr[i]);
	}
	BubbleSort(arr, size);
}