#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Distributing weights to minimize the gap between the sums
// n: number of weights, 1 <= n <= 100
// 1 <= weights <= 450 (integer)
// long long due to pow(2, 100)
/*
01234
00000
00001
00010
00011
00100
00101
00110
00111
01000
...
11111
-------
32
*/
int main()
{
	int n, i, j, sum=0;
	int weight[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &weight[i]);
	for (i = 0; i < n; i++)
		sum +=weight[i];
	if (n == 1)
	{
		printf("%d", weight[0]);
		return;
	}
	int team1, team2, team1_c, team2_c, min_team1, min_team2, min = 100000;
	long long k, t, total = pow(2, n);
	for (k = 0; k < total; k++)
	{
		long long temp = k;
		team1 = 0;
		team2 = 0;
		team1_c = 0;
		team2_c = 0;
		for (t = 0; t < n; t++)
		{
			if (temp % 2 == 0)
			{
				team1 += weight[t];
				team1_c++;
			}
			else
			{
				team2 += weight[t];
				team2_c++;
			}
			temp = temp / 2;
		}
		if (abs(team1 - team2) < min && abs(team1_c - team2_c) <=1)
		{
			min = abs(team1 - team2);
			min_team1 = team1;
			min_team2 = team2;
		}
	}
	if (min_team1 < min_team2)
		printf("%d\n%d", min_team1, min_team2);
	else
		printf("%d\n%d", min_team2, min_team1);
}

