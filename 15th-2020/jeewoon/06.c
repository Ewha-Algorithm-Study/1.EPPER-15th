// ����ǥ���

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int m, char* input) {
	int a = 0;
	char op;
	int answer = 0;

	for (int i = 0; i < m; i++) {

		// �� ù char�� �ǿ�����
		if (i == 0) {
			answer = atoi(&input[i]);
			continue;
		}

		// Ȧ����° char�� �ǿ�����
		if (i % 2 == 1)
			a = atoi(&input[i]);

		// ¦����° char�� ������
		if (i % 2 == 0) {
			op = input[i];
			if (op == '+')
				answer += a;
			else if (op == '-')
				answer -= a;
			else if (op == '*')
				answer *= a;
			else
				answer /= a;
		}
	}

	return answer;
}

int main() {
	char input[] = "23+";
	int answer = solution(3, input);
	printf("%d", answer);
}