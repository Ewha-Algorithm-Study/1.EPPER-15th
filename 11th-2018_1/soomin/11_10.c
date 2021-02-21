#include <stdio.h>
#include <stdlib.h>
// Catching maximum apples that fall from the trees
// N: number of squares, odd number (1 <= N <= 999)
// k: number of apples falling from the tree (1 <= k <= 3000)
// t: the time when the apple falls, in ascending order (1 <= t <= 100000)
// Dynamic programming
int apples[100001][1000];
int mem[1000][3001];
int main()
{
	int N, k, i, j, l, m;
	int max_time = 0, max_k = 0;
	scanf("%d", &N);
	// save the apple's falling time in an array
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &k);
		if (k > max_k)
			max_k = k;
		for (j = 1; j <= k; j++)
		{
			scanf("%d", &mem[i][j]);
			// the time when the last apple falls
			if (mem[i][j] > max_time)
				max_time = mem[i][j];
		}
	}
	// calculate the number of apples
	for (i = 1; i <= max_time; i++)
	{
		for (l = 1; l <= N; l++)
		{
			for (m = 1; m <= max_k; m++)
			{
				if (mem[l][m] == i)
					apples[i][l] = 1;
			}
		}
	}
	/*
	for (i = 1; i <= max_time; i++)
	{
		for (j = 1; j <= N; j++)
		{
			printf("%d ", apples[i][j]);
		}
		printf("\n");
	}
	*/
	// Boxes that can't be reached
	int start = (N + 1) / 2;
	for (i = 1; i < start; i++)
	{
		for (j = 1; j <= start - i; j++)
			apples[i][j] = -1;
		for (j = start + i; j <= N; j++)
			apples[i][j] = -1;
	}
	/*
	for (i = 1; i <= max_time; i++)
	{
		for (j = 1; j <= N; j++)
		{
			printf("%3d ", apples[i][j]);
		}
		printf("\n");
	}
	*/
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
	/*
	for (i = 1; i <= max_time; i++)
	{
		for (j = 1; j <= N; j++)
		{
			printf("%3d ", apples[i][j]);
		}
		printf("\n");
	}
	*/
	// find the maximum
	int answer = 0;
	for (i = 1; i < N; i++)
	{
		if (apples[max_time][i] > answer)
			answer = apples[max_time][i];
	}
	printf("%d", answer);
}