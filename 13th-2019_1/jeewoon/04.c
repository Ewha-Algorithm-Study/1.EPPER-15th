#include <stdio.h>
#include <stdlib.h>

void solution() {
	int n;
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		int r = arr[i] % 100; // �Էµ� ���� �� ���ڸ�

		// �ݿø��� ������ ��
		if (r < 50) // 50���� ������ ����
			printf("%d ", arr[i] - r);
		else // 50���� ũ�� �ø�
			printf("%d ", arr[i] + (100 - r));

		// ������ ������ ��
		printf("%d\n", arr[i] - r);
	}
}

int main() {
	solution();
}