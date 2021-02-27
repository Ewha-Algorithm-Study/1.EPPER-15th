#include <stdio.h>
#include <stdlib.h>
// 1<= n <= 10000
// Integers from 1 to n, that is common multiple of 2 and 3
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
			printf("%d ", i);
	}
}