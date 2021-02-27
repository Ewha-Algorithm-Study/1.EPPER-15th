#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Hanoi tower (recursive)
// n: number of discs
int hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)
	{
		printf("1: %c -> %c\n", from, to);
	}
	else
	{
		hanoi_tower(n - 1, from, to, tmp);
		printf("%d: %c -> %c\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int cnt = pow(2, n) - 1;
	printf("%d\n", cnt);
	hanoi_tower(n, 'A', 'B', 'C');
}