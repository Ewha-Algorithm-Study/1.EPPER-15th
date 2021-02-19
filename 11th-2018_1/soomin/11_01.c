#include <stdio.h>
#include <stdlib.h>
// Given n inputs (1<=n<=10000), add i(th) to j(th) number
// 1<=i<=j<=n
int main()
{
	int n, i, j, sum=0, k;
	scanf("%d", &n);
	int* numbers = (int*)malloc(sizeof(int) * n);
	scanf("%d", &i);
	scanf("%d", &j);
	for (k = 0; k < n; k++)
	{
		scanf("%d", &numbers[k]);
		if (k + 1 >= i && k + 1 <= j)
			sum += numbers[k];
	}
	printf("%d", sum);
}