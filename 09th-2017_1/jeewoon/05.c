#include <stdio.h>

int matrix[10][10];

void solution() {
	int m, n;
	scanf_s("%d", &m);
	scanf_s("%d", &n);

	// 행렬 입력 받기
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf_s("%d", &matrix[i][j]);
	}


	// 행렬 출력
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int main() {
	solution();
}