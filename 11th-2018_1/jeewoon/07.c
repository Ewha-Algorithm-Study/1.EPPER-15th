#include <stdio.h>
#include <stdlib.h>

double solution() {
	int n, tmp;
	double avg = 0;
	scanf_s("%d", &n);

	int* num = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &num[i]);

	// bubble sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (num[j] > num[j + 1]) {
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		// 첫번째 숫자는 넣어두기
		if (i == 0) {
			avg = num[0];
			continue;
		}

		// 이때까지의 평균과 현재 index의 숫자로 평균구하기
		avg = (avg + num[i]) / 2;
	}

	return avg;
}

int main() {
	printf("%.6f", solution());
}