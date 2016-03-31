#include <stdio.h>

int arr[500000] = {0, };
int heap_size;

void swap(int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Max_Heapify(int i, int arr_size) {
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;
	int largest;

	if (l < arr_size && arr[l] > arr[i])	largest = l;
	else largest = i;

	if (r < arr_size && arr[r] > arr[largest])	largest = r;

	if (largest != i) {
		swap(i, largest);
		Max_Heapify(largest, arr_size);
	}
}

void HeapSort(int num) {
	int i;

	for (i = (num / 2)-1; i >= 0; i--) {
		Max_Heapify(i, heap_size);
	}	//Build Max Heap

	while (num > 1) {
		num--;
		swap(0, num - 1);
		Max_Heapify(0, num);
	}
}

int main() {
	int updown;
	int i;

	printf("정렬할 수의 개수 : ");
	scanf_s("%d", &heap_size);
	printf("오름차순은 1, 내림차순은 2를 입력하시오 : ");
	scanf_s("%d", &updown);

	for (i = 0;i < heap_size;i++) {
		scanf_s("%d", &arr[i]);
	}

	HeapSort(heap_size);

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