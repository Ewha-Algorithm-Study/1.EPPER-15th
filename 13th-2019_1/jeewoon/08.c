#include <stdio.h>
#include <stdlib.h>

int solution() {
	char buffer[100];
	int m;
	int a = 0;
	char op;
	int answer = 0;

	scanf_s("%d", &m);
	char* input = (char*)malloc(sizeof(char) * (m + 1));
	for (int i = 0; i < m; i++)
		scanf_s("%c", input[i]);

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
	printf("%d", solution());
}