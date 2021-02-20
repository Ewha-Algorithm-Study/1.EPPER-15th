#include <stdio.h>

void solution() {
	int n, blank, star;
	scanf_s("%d", &n);

	/* ��ĭ2, ��1                      i=0
	   ��ĭ1, ��3                      i=1
	   ��ĭ0, ��5    ��ĭ(n+1)/2=3     i=2 */

	// ù��° �� ~ ���� �� ��
	for (int i = 0; i < (n + 1) / 2; i++) {
		blank = (n + 1) / 2 - 1 - i;
		for (int j = 0; j < blank; j++)
			printf(" ");

		star = 2 * i + 1;
		for (int j = 0; j < star; j++)
			printf("*");
		printf("\n");
	}

	// ���� �� ��+1 ~ ������ ��
	for (int i = (n + 1) / 2 - 2; i >= 0; i--) {
		blank = (n + 1) / 2 - 1 - i;
		for (int j = 0; j < blank; j++)
			printf(" ");

		star = 2 * i + 1;
		for (int j = 0; j < star; j++)
			printf("*");
		printf("\n");
	}

}

int main() {
	solution();
}