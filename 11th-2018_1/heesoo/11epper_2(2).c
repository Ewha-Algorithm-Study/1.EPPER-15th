#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	int k,p=0;
	for (int i = 1;i <= n * 2;i += 2) {
		p = i;
		if (p > n)
			p = n * 2 - p;
		k = (n - p) / 2;
		for (int t = 0;t < k;t++)
			printf(" ");
		for (int t = 0;t < p;t++)
			printf("*");
		for (int t = 0;t < k;t++)
			printf(" ");
		printf("\n");
	}
}