#include <stdio.h>
#include <stdlib.h>
// Clap on integers that have 3, 6, 9
// Calculate the number of claps
// S: starting integer, E: ending integer
// 1 <= S <= E <= 10000
int main()
{
	int s, e, i, total = 0;
	scanf("%d %d", &s, &e);
	for (i = s; i <= e; i++)
	{
		int j = i;
		while (j > 0)
		{
			if (j % 10 == 3 || j % 10 == 6 || j % 10 == 9)
			{
				total += 1;
				break;
			}
			else
				j = j / 10;
		}
	}
	printf("%d", total);
}