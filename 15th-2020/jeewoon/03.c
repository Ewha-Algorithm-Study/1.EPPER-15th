// �����³�

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solution(int n, int m) {
	int answer = 0;

	while (true) {
		n--;
		answer++;
		if (answer % m == 0) // ��Ʈ�� ä���ֱ�
			n++;
		if (n == 0) // ��� 0��
			break;
	}

	return answer;
}

int main() {
	printf("%d", solution(5, 3));
}