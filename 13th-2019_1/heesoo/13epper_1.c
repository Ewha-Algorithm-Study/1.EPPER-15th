#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int n; //숫자개수
	int k; //수
	int ans = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &k);
		if (k % 2 == 0)
			continue;
		else
			ans += k;//홀수면 더하기
	}
	printf("%d", ans);
	return 0;

}