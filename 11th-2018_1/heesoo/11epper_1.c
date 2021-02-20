#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//i번째부터 j번째까지의 수의 합 구하기

int main(void) {
	int n;
	scanf("%d", &n);
	int i, j,val;
	scanf("%d %d", &i, &j);
	int sum = 0;
	for (int k = 1;k <= n;k++) {
		scanf("%d", &val);
		if (k >=i && k <=j) {
			sum += val;
		}	
	}
	printf("%d", sum);
}