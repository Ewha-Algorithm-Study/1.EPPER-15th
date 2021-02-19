#include <stdio.h>
#include <stdlib.h>
// Catching maximum apples that fall from the trees
// N: number of squares, odd number (1 <= N <= 999)
// k: number of apples falling from the tree (1 <= k <= 3000)
// t: the time when the apple falls, in ascending order (1 <= t <= 100000)
// Dynamic programming
int apples[100001][1001];
int main()
{
	int N, k, t, i, j;
	int max_time=0;
	scanf("%d", &N);
	// save the apple's falling time in an array
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &k);
		for (j = 1; j <= k; j++)
		{
			scanf("%d", &t);
			apples[t][i] = 1;
			// the time when the last apple falls
			if (t > max_time)
				max_time = t;
		}
	}
	// Boxes that can't be reached
	int start = (N + 1) / 2;
	for (i = 1; i < start; i++)
	{
		for (j = 1; j < start - i; j++)
			apples[i][j] = -1;
		for (j = start + i; j <= N; j++)
			apples[i][j] = -1;
	}
	// update the number of apples (in time)
	for (i = 2; i <= max_time; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (apples[i][j] != -1)
			{
				int max = 0, place;
				for (place = -1; place <= 1; place++)
				{
					if (1 <= j + place && j + place <= N)
					{
						if (max < apples[i - 1][j + place])
							max = apples[i - 1][j + place];
					}
				}
				apples[i][j] += max;
			}
		}
	}
	// find the maximum at the at the max_time
	int answer = 0;
	for (i = 1; i <= N; i++)
	{
		if (apples[max_time][i] > answer)
			answer = apples[max_time][i];
	}
	printf("%d", answer);
}