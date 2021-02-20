#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution() {
	int key, n, count, idx, flag = 1, i = 0;
	int key_arr[7] = { 0 };
	char msg[100];
	char append[2] = { 'a' };

	scanf_s("%s", msg, 100);
	scanf_s("%d", &key);

	n = strlen(msg);

	// �Է¹��� key �ڸ��� ���� key_arr�� ���� (�Էµ� �ݴ�� �����)
	while (key != 0) {
		key_arr[i] = key % 10;
		key /= 10;
		i++;
	}

	// ���� ���� 7�� ����� �ƴ� ��� ���ڿ� append�ϱ�
	if (n % 7 != 0) {
		count = 7 - n % 7;
		for (int i = 0; i < count; i++) {
			append[0] += i;
			strcat_s(msg, sizeof(msg), append);
		}
	}

	for (int i = 0; i < 7; i++) {
		printf("%d ", key_arr[i]);
	}
	printf("\n");

	// �� key�� �°� ����ϱ�
	for (int i = 0; i < n; i++) {
		idx = 7 - key_arr[i] * flag;
		printf("%c", msg[idx]);
		if (i % 7 == 6)
			flag++;
	}
}

int main() {
	solution();
}