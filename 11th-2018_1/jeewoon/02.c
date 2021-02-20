#include <stdio.h>

void solution() {
	int n, blank, star;
	scanf_s("%d", &n);

	/* 后沫2, 喊1                      i=0
	   后沫1, 喊3                      i=1
	   后沫0, 喊5    后沫(n+1)/2=3     i=2 */

	// 霉锅掳 青 ~ 啊厘 变 青
	for (int i = 0; i < (n + 1) / 2; i++) {
		blank = (n + 1) / 2 - 1 - i;
		for (int j = 0; j < blank; j++)
			printf(" ");

		star = 2 * i + 1;
		for (int j = 0; j < star; j++)
			printf("*");
		printf("\n");
	}

	// 啊厘 变 青+1 ~ 付瘤阜 青
	for (int i = (n + 1) / 2 - 2; i >= 0; i--) {
		blank = (n + 1) / 2 - 1 - i;
		for (int j = 0; j < blank; j++)
			printf(" ");

		star = 2 * i + 1;
		for (int j = 0; j < star; j++)
			printf("*");
		printf("\n");
	}

}

int main() {
	solution();
}