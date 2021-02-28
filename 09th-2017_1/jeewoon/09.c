#include <stdio.h>

int answer;
char disk[4] = { 'A','B','C' };

void hanoi(int count, int from, int to, int buf, int flag) {

	// 가장 작은 disk일 경우
	if (count == 1) {
		answer++;
		if(flag == 1)
			printf("%d: %c->%c\n", count, disk[from - 1], disk[to - 1]);
		return;
	}

	// 나머지 disk의 경우
	hanoi(count - 1, from, buf, to, flag); // 더 작은 disk들을 from->buf 이동
	answer++;
	if(flag == 1)
		printf("%d: %c->%c\n", count, disk[from - 1], disk[to - 1]);
	hanoi(count - 1, buf, to, from, flag); // 더 작은 disk들을 buf->to 이동
}

void solution() {
	int n;
	scanf_s("%d", &n);

	hanoi(n, 1, 3, 2, 0); // 총 이동 횟수 계산용 (flag = 0)
	printf("%d\n", answer);
	hanoi(n, 1, 3, 2, 1); // 이동 경로 출력용 (flag = 1)
}

int main() {
	answer = 0;
	solution();
}