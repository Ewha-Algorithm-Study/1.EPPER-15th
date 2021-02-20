#include <stdio.h>
#include <stdlib.h>

int solution() {
	int n, s, e, sum = 0;
	scanf_s("%d", &n);
	scanf_s("%d %d", &s, &e);

	int* p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &p[i]);
	}

	// index s-1부터 e-1까지 더해서 합 구하기
	for (int i = s - 1; i <= e - 1; i++) {
		sum += p[i];
	}

	return sum;
}

int main() {
	printf("%d", solution());
}