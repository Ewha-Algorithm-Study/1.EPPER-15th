#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//소수면 1, 아니면 0을 출력
int main(void) {
	int n = 0;
	scanf("%d", &n);
	int k = sqrt(n);
	int ans = 1;
	for (int i = 2;i <= k;i++) {
		if (n % i == 0) {
			ans = 0;
			break;
		}
	}
	printf("%d", ans);

}