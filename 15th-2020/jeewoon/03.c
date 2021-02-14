// 재고없는날

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solution(int n, int m) {
	int answer = 0;

	while (true) {
		n--;
		answer++;
		if (answer % m == 0) // 노트북 채워넣기
			n++;
		if (n == 0) // 재고가 0임
			break;
	}

	return answer;
}

int main() {
	printf("%d", solution(5, 3));
}