#include <stdio.h>
#include <stdlib.h>

void solution() {
	int n;
	scanf_s("%d", &n);

	for (int i = 1; i < n + 1; i++) {

		// n-i��ŭ ��ĭ ���
		for (int j = 1; j < n - i + 1; j++)
			printf(" ");
		// i��ŭ �� ���
		for (int j = 1; j < i + 1; j++)
			printf("*");
		printf("\n");
	}
}

int main() {
	solution();
}