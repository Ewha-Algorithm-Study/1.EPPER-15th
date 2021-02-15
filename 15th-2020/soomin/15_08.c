#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// n-Queen problem with given sites occupied 
int chess[14][14];
int column[14];
int diagonal_r[27];
int diagonal_l[27];
int N; int count;
// modified n-Queen algorithm
void nqueen(int i)
{
	int j;
	for (j = 0; j < N; j++)
	{
		if (chess[i][j] != 1 && column[j] != 1 && diagonal_r[i + j] != 1 && diagonal_l[i - j + N - 1] != 1)
		{
			if (i == N-1)
				count++;
			else
			{
				column[j] = diagonal_r[i + j] = diagonal_l[i - j + N - 1] = 1;
				nqueen(i + 1);
				column[j] = diagonal_r[i + j] = diagonal_l[i - j + N - 1] = 0;
			}
		}
	
	}
}
int solution(int n, int k, int X[], size_t X_len, int Y[], size_t Y_len)
{
	int answer = 0;
	N = n; int i;
	// Mark the occupied sites
	for (i = 0; i < k; i++)
		chess[X[i]-1][Y[i]-1] = 1;
	// Calculate the answer by recursively calling n-Queen algorithm
	nqueen(0);
	answer = count;
	return answer;
}
int main()
{
	int n, k, i;
	scanf("%d, %d, ", &n, &k);
	int* X = (int*)malloc(sizeof(int) * k);
	int* Y = (int*)malloc(sizeof(int) * k);
	scanf("[%d", &X[0]);
	for (i = 1; i < k; i++)
		scanf(", %d", &X[i]);
	scanf("], [%d", &Y[0]);
	for(i=1; i<k; i++)
		scanf(", %d", &Y[i]);
	scanf("]");
	printf("%d", solution(n,k,X,k,Y,k));
	free(X);
	free(Y);
}



// n-Queen
/*
int chess[14];
int column[14];
int diagonal_r[27];
int diagonal_l[27];
int N; int count;
void nqueen(int i)
{
	int j;
	for (j = 0; j < N; j++)
	{
		if (column[j] != 1 && diagonal_r[i+j] != 1 && diagonal_l[i-j + N - 1] != 1)
		{
			if (i == N-1)
				count++;
			else
			{
			column[j] = diagonal_r[i + j] = diagonal_l[i - j + N - 1] = 1;
			nqueen(i + 1);
			column[j] = diagonal_r[i + j] = diagonal_l[i - j + N - 1] = 0;
			}
		}
	}
}
int solution(int n)
{
	int answer = 0;
	N = n;
	nqueen(0);
	answer = count;
	return answer;
}
int main()
{
	printf("%d", solution(8));
}
*/