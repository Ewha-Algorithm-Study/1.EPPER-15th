#include <stdio.h>

int solution() {
	int n, isPrime = -1;
	scanf_s("%d", &n);

	for (int i = 2; i < n; i++) {
		if (n % i == 0) { // n���� ���� ���� ������ �������� => �Ҽ��� �ƴ�
			isPrime = 0;
			break;
		}
		isPrime = 1; // ��� ���� ������ �������� ������ => �Ҽ�
	}

	return isPrime;
}

int main() {
	printf("%d", solution());
}