#include <stdio.h>

int arr[50000] = { 0, };

int quick_sort(int left, int right) {
	int i = left;
	int j = right;
	int pivot = arr[(i + j) / 2];
	int temp;

	while (i <= j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)	quick_sort(left, j);
	if (i < right)	quick_sort(i, right);	
}


void main() {
	int i, count, updown, l_arr, r_arr;
	
	printf("������ �ڿ����� ���� : ");
	scanf_s("%d", &count);

	printf("���������̸� 0��, ���������̸� 1�� �Է� : ");
	scanf_s("%d", &updown);

	for (i = 0; i < count; i++) {
		scanf_s("%d", &arr[i]);
	}

	l_arr = 0;
	r_arr = count - 1;
	
	quick_sort(l_arr, r_arr);

	if (updown == 0) {
		printf("������������ ����մϴ�.\n");
		for (i = 0;i < count;i++) {
			printf("%d ", arr[i]);
		}
	}
	else {
		printf("������������ ����մϴ�.\n");
		for (i = count - 1;i >= 0;i--) {
			printf("%d ", arr[i]);
		}
	}
}