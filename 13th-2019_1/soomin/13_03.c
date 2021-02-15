#include <stdio.h>
// if n is odd, print right triangle with *
// n: number of * on the bottom (3 <= n < 100)
int main()
{
	int n, i, j;
	scanf("%d", &n);
	if (n % 2 == 1 && n > 0)
	{
		for (i = 0; i < n; i++)
		{
			// print empty spaces
			for (j = 0; j <= n - i - 1; j++)
			{
				printf(" ");
			}
			// print stars
			for (j = 0; j <= i; j++)
			{
				printf("*");
			}
			// next line
			printf("\n");
		}
	}
}
