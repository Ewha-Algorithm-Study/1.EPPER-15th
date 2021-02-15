#include <stdio.h>
#include <stdlib.h>

void solution() {
	int m, n;
	scanf_s("%d", &m);
	scanf_s("%d", &n);

	int change = m - n;
	int type = 0, total = 0;
	int idx[] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 }; // ��� ȭ�� ����ִ� �迭 ����

	// ȭ�� �������� �ϳ��� ���
	for (int j = 0; j < 8; j++) {
		if (change / idx[j] != 0) {
			total += change / idx[j]; // �ش� ȭ�� �ʿ� ���� �������� ���ϱ�
			type++; // ���� ���ϱ�
			change = change % idx[j];
		}
	}

	printf("%d %d", type, total);
}

int main() {
	solution();
}