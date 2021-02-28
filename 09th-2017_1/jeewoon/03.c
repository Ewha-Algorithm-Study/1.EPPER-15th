#include <stdio.h>
#include <stdlib.h>

void solution() {

	int n;
	scanf_s("%d", &n);

	char name[55][55];

	// 이름 입력받기
	for (int i = 0; i < n; i++)
		scanf_s("%s", name[i], sizeof(name[i]));

	// 출력
	for (int i = 0; i < n; i++)
		printf("Hello, %s!\n", name[i]);
}

int main() {
	solution();
}
