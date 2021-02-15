#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Calculate the maximum total time required to reach the goal in the procedure
// Data structure saving each procedures
// 1<=N_len<=100, 1<=Relation_rows<=100
typedef struct procedure
{
	int time_sum;
	int before[101];

}procedure;
// calculate the maximum time of the procedures
int solution(int N[], size_t N_len, int** Relation, size_t Relation_rows, size_t Relation_cols, int goal)
{
	int answer = 0;
	int i, j, count=0;
	// Check the relationship with matrix (mark 1 if they have relations) (A->B)
	int** Relation_check = (int**)malloc(sizeof(int*) * N_len);
	for (i = 0; i < N_len; i++)
		Relation_check[i] = (int*)malloc(sizeof(int) * N_len);
	for (i = 0; i < N_len; i++)
	{
		for (j = 0; j < N_len; j++)
		{
			Relation_check[i][j] = 0;
		}
	}
	for (i = 0; i < Relation_rows; i++)
	{
		Relation_check[Relation[i][0]][Relation[i][1]] = 1;
	}

	// Relation_check matrix
	/*
	for (i = 0; i < N_len; i++)
	{
		for (j = 0; j < N_len; j++)
		{
			printf("%d ", Relation_check[i][j]);
		}
		printf("\n");
	}
	*/

	// find the goal step and the step just before that
	// before array saves the steps in the procedure
	// time_sum sums up time needed in the steps
	procedure* products = (procedure*)malloc(sizeof(procedure) * N_len);
	for (i = 0; i < Relation_rows; i++)
	{
		products[i].before[1] = 0;
		products[i].before[1] = 0;
	}
	for (i = 0; i < Relation_rows; i++)
	{
		if (Relation[i][1] == goal - 1)
		{
			products[i].before[0] = Relation[i][1];
			products[i].before[1] = Relation[i][0];
			products[i].time_sum = N[goal - 1];
			products[i].time_sum += N[Relation[i][0]];
			count++; // count the number of procedures that reach the goal
		}
	}
	// Now that we have saved all the steps needed in a procedure,
	// sum up the total time by going through the steps
	for (i = 0; i < Relation_rows; i++)
	{
		int idx = 1;
		if (products[i].before[idx] == 0)
			continue;
		while (products[i].before[idx] != 0)
		{
			for (j = 0; j < Relation_rows; j++)
			{
				if (Relation_check[j][(products[i].before[idx])] == 1)
				{
					products[i].before[++idx] = j;
					products[i].time_sum += N[j];
					break;
				}
			}
		}
	}
	// Find the maximum time among the procedures
	int max_time = 0;
	for (i = 0; i < Relation_rows; i++)
	{
		if (products[i].before[1] == 1)
			continue;
		if (products[i].time_sum > max_time)
			max_time = products[i].time_sum;
	}
	// return the maximum time
	answer = max_time;
	return answer;
}
int main()
{
	// n: number of steps
	// r: number or relations
	// N: time needed for each step
	// Relation: relationships between the steps
	// goal: the final step
	int n, r, i, goal;
	scanf("%d %d", &n, &r);
	int* N = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &N[i]);
	int** Relation = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++)
		Relation[i] = (int*)malloc(sizeof(int) * 2);
	for (i = 0; i < r; i++)
	{
		scanf("%d %d", &Relation[i][0], &Relation[i][1]);
		Relation[i][0] -= 1;
		Relation[i][1] -= 1;
	}
	scanf("%d", &goal);
	printf("%d", solution(N, n, Relation, r, 2, goal));
}