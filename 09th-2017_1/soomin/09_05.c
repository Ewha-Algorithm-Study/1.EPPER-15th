#include <stdio.h>
#include <stdlib.h>
// transpose matrix
// m: row, n: column
// 1 <= m, n <= 10
int main()
{
	int m, n, i, j;
	int matrix[10][10];
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", matrix[j][i]);
		}
		printf("\n");
	}
}