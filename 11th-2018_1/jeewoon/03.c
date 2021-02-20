#include <stdio.h>

int solution() {
	int n, isPrime = -1;
	scanf_s("%d", &n);

	for (int i = 2; i < n; i++) {
		if (n % i == 0) { // n보다 작은 수로 나누어 떨어지면 => 소수가 아님
			isPrime = 0;
			break;
		}
		isPrime = 1; // 모든 수가 나누어 떨어지지 않으면 => 소수
	}

	return isPrime;
}

int main() {
	printf("%d", solution());
}