#include <stdio.h>
#include <stdlib.h>

int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution() {
	int n;
	scanf_s("%d", &n);
	int* m = (int*)malloc(sizeof(int) * n);

	int dp[30001] = { 0, };

	// 1번째 또는 2번째의 경우는 초기화
	dp[1] = m[1];
	dp[2] = m[1] + m[2];

	for (int i = 3; i <= n; i++) {

		// i번째 주웠을때 최대로 주울 수 있는 돈
		// 1. dp[i - 2] + m[i]
		// 2. dp[i - 3] + m[i - 1] + m[i]
		// 3. dp[i - 1]
		dp[i] = MAX(dp[i - 2] + m[i], MAX(dp[i - 3] + m[i - 1] + m[i], dp[i - 1]));
	}

	return dp[n];
}

int main() {
	printf("%d", solution());
}