#include <stdio.h>

void solution() {
	int ans_x, ans_y;
	int tmp, tmp2;

	// x, y ��ǥ �ʱ�ȭ
	int x[3] = { -1, -1, -1 };
	int y[3] = { -1, -1, -1 };

	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &x[i]);
		scanf_s("%d", &y[i]);
	}

	for (int i = 0; i < 3; i++) {
		// ������ index�� ���� 0���� �����ֱ�
		if (i < 2) tmp = i + 1;
		else tmp = 0;

		// x��ǥ ���� �ΰ��� ���� ������ -> ������ ���� x��ǥ�� ������ ��ǥ�� x��ǥ�� ����
		if (x[i] == x[tmp]) {
			if (tmp < 2) tmp2 = tmp + 1;
			else tmp2 = 0;
			ans_x = x[tmp2];
		}
			
		// y��ǥ ���� �ΰ��� ���� ������ -> ������ ���� y��ǥ�� ������ ��ǥ�� y��ǥ�� ����
		if (y[i] == y[tmp]) {
			if (tmp < 2) tmp2 = tmp + 1;
			else tmp2 = 0;
			ans_y = y[tmp2];
		}
	}

	printf("%d %d", ans_x, ans_y);
}

int main() {
	solution();
}