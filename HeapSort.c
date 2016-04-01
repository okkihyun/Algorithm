#include <stdio.h>

//int arr[50000] = {0, };
//int heap_size;

void swap(int *arr_top, int *arr_bot) {
	int temp = *arr_top;
	*arr_top = *arr_bot;
	*arr_bot = temp;
}

void Max_Heapify(int arr[], int i, int heap_size) {
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;
	int largest;

	if (l <= heap_size && arr[l] > arr[i])	largest = l;
	else largest = i;

	if (r <= heap_size && arr[r] > arr[largest])	largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		Max_Heapify(arr, largest, heap_size);
	}
}

void HeapSort(int arr[], int heap_size) {
	int i;

	for (i = (heap_size / 2)-1; i >= 0; i--) {
		Max_Heapify(arr, i, heap_size-1);
	}	//Build Max Heap

	while (heap_size > 1) {
		heap_size--;
		swap(&arr[0], &arr[heap_size]);
		Max_Heapify(arr, 0, heap_size-1);
	}
}

int main() {
	int updown;
	int i, count;
	int arr[50000] = { 0, };
	int heap_size;

	printf("정렬할 수의 개수 : ");
	scanf_s("%d", &heap_size);
	printf("오름차순은 1, 내림차순은 2를 입력하시오 : ");
	scanf_s("%d", &updown);

	for (i = 0;i < heap_size;i++) {
		scanf_s("%d", &arr[i]);
	}

	HeapSort(arr, heap_size);
	
	if (updown == 1) {
		for (i = 0;i < heap_size;i++) {
			printf("%d ", arr[i]);
		}
	}
	else {
		for (i = heap_size - 1; i >= 0; i--) {
			printf("%d ", arr[i]);
		}
	}
}