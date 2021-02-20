#include <stdio.h>
#include <stdlib.h>

void solution() {
	int p, tmp, i = 0, answer = 0;
	int each[6] = { -1 };
	scanf_s("%d", &p);

	// p의 자릿 수 찾기
	tmp = p;
	while (tmp != 0) {
		each[i] = tmp % 10;
		tmp /= 10;
		i++;
	}


	for (int j = 0; j < 6; j++) {
		printf("%d ", each[i]);
	}
	printf("\n%d %d", i, p);
}

int main() {
	solution();
}
	