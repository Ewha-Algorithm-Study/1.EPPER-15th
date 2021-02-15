#include <stdio.h>
#include <stdlib.h>

void solution() {
	int n;
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		int r = arr[i] % 100; // 입력된 수의 끝 두자리

		// 반올림을 수행한 값
		if (r < 50) // 50보다 작으면 버림
			printf("%d ", arr[i] - r);
		else // 50보다 크면 올림
			printf("%d ", arr[i] + (100 - r));

		// 버림을 수행한 값
		printf("%d\n", arr[i] - r);
	}
}

int main() {
	solution();
}