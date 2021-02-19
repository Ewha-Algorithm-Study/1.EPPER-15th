#include <stdio.h>
#include <stdlib.h>
// Check whether the given number is a prime number
// 1<= n <= 100
// 1: prime number,  0: not a prime number
int main()
{
	int n, i, is_prime=1;
	scanf("%d", &n);
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			is_prime = 0;
			break;
		}
	}
	printf("%d", is_prime);
}