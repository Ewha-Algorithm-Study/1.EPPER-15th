#include <stdio.h>
#include <stdlib.h>

int solution() {
	int n;
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n); // 입력받을 수만큼 동적할당
	int sum = 0;

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);

		if (arr[i] % 2 == 1) // 홀수면 합 구하기
			sum += arr[i];
	}

	free(arr);
	return sum;
}

int main() {
	printf("%d", solution());
}