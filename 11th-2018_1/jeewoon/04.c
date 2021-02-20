#include <stdio.h>

void solution() {
	int ans_x, ans_y;
	int tmp, tmp2;

	// x, y 좌표 초기화
	int x[3] = { -1, -1, -1 };
	int y[3] = { -1, -1, -1 };

	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &x[i]);
		scanf_s("%d", &y[i]);
	}

	for (int i = 0; i < 3; i++) {
		// 마지막 index로 가면 0으로 보내주기
		if (i < 2) tmp = i + 1;
		else tmp = 0;

		// x좌표 같은 두개의 점이 있으면 -> 나머지 점의 x좌표가 마지막 좌표의 x좌표와 같음
		if (x[i] == x[tmp]) {
			if (tmp < 2) tmp2 = tmp + 1;
			else tmp2 = 0;
			ans_x = x[tmp2];
		}
			
		// y좌표 같은 두개의 점이 있으면 -> 나머지 점의 y좌표가 마지막 좌표의 y좌표와 같음
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