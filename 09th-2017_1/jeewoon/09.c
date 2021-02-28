#include <stdio.h>

int answer;
char disk[4] = { 'A','B','C' };

void hanoi(int count, int from, int to, int buf, int flag) {

	// ���� ���� disk�� ���
	if (count == 1) {
		answer++;
		if(flag == 1)
			printf("%d: %c->%c\n", count, disk[from - 1], disk[to - 1]);
		return;
	}

	// ������ disk�� ���
	hanoi(count - 1, from, buf, to, flag); // �� ���� disk���� from->buf �̵�
	answer++;
	if(flag == 1)
		printf("%d: %c->%c\n", count, disk[from - 1], disk[to - 1]);
	hanoi(count - 1, buf, to, from, flag); // �� ���� disk���� buf->to �̵�
}

void solution() {
	int n;
	scanf_s("%d", &n);

	hanoi(n, 1, 3, 2, 0); // �� �̵� Ƚ�� ���� (flag = 0)
	printf("%d\n", answer);
	hanoi(n, 1, 3, 2, 1); // �̵� ��� ��¿� (flag = 1)
}

int main() {
	answer = 0;
	solution();
}