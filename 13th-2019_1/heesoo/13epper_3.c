#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int n = 0;//È¦¼ö
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = n - i;j > 0;j--)//ÃÑ n-i°³
			printf(" ");//°ø¹é Ãâ·Â
		for (int j = 1;j <= i;j++)//ÃÑ i°³
			printf("*");//º° Ãâ·Â
		printf("\n");
	}


	return 0;
}