#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//전치행렬 구하기

int main() {
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	int arr[10][10] = { 0, };
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			printf("%d ", arr[j][i]);
		printf("\n");
	}
}