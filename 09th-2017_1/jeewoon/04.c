#include <stdio.h>

int solution() {
	int s, e, answer = 0;
	scanf_s("%d", &s, sizeof(s));
	scanf_s("%d", &e, sizeof(e));

	for (int i = s; i <= e; i++) {
		int tmp = i, each[5], idx = 0;
		
		// �� �ڸ����� each�� ����
		while (tmp != 0) {
			each[idx] = tmp % 10;
			tmp /= 10;
			idx++;
		}
		
		// �� �ڸ����� 3,6,9�̸� �ڼ� Ƚ�� ����
		for (int j = 0; j < idx; j++) {
			if (each[j] == 3 || each[j] == 6 || each[j] == 9) {
				answer++;
				break;
			}
		}
	}

	return answer;
}

int main() {
	printf("%d", solution());
}