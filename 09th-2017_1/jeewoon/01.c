#include <stdio.h>

void solution() {

	int n;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0 && i % 3 == 0) // 2 �Ǵ� 3���� ������ �������� print
			printf("%d ", i);
	}
}

int main() {
	solution();
}