#include <stdio.h>

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void seletSort(int arr[], int size) {
	int i, j;
	int smallest;

	for (i = 0;i < size-1;i++) {
		printf("%d step. ", i+1);
		smallest = i;
		for (j = i+1; j < size; j++) {
			if (arr[smallest] > arr[j]) smallest = j;
			//else smallest = arr[i];
		}
		swap(&arr[smallest], &arr[i]);		
		for (j = 0;j < size;j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
}

int main() {
	int size;
	int i;
	int arr[100] = { 0, };

	printf("전체 사이즈를 입력하시오 : ");
	scanf_s("%d", &size);
	printf("정렬할 수들을 입력하시오 : ");
	
	for (i = 0; i < size; i++) {
		scanf_s("%d", &arr[i]);
	}
	seletSort(arr, size);
}