#include <stdio.h>
#include <stdlib.h>
// print a diamond with stars, the longest row has n stars
// 1 <= n <= 100 (n is an odd number)
int main()
{
	int n, i, j;
	scanf("%d", &n);
	if (n % 2 != 1 || n <= 0)
		return;
	for (i = 0; i < n; i++)
	{
		// pyramid
		if (i <= n / 2)
		{
			for (j = i; j < n/2 + 1; j++)
				printf(" ");
			for (j = 0; j < 2 * i + 1; j++)
				printf("*");
			printf("\n");
		}
		// pyramid upside down
		else
		{
			for (j = 0; j < i - n/2 + 1; j++)
				printf(" ");
			for (j = 0; j < 2 * (n-i) - 1; j++)
				printf("*");
			printf("\n");
		}
	}
}