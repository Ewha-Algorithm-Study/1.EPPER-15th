#include <stdio.h>
#include <stdlib.h>

void solution() {
	int m, n;
	scanf_s("%d", &m);
	scanf_s("%d", &n);

	int change = m - n;
	int type = 0, total = 0;
	int idx[] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 }; // 모든 화폐가 들어있는 배열 생성

	// 화폐 종류마다 하나씩 계산
	for (int j = 0; j < 8; j++) {
		if (change / idx[j] != 0) {
			total += change / idx[j]; // 해당 화폐 필요 개수 누적으로 더하기
			type++; // 종류 더하기
			change = change % idx[j];
		}
	}

	printf("%d %d", type, total);
}

int main() {
	solution();
}