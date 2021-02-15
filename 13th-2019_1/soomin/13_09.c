#include <stdio.h>
#include <stdlib.h>
// maximum sum of the listed numbers
// more than three subsequence numbers cannot be added
// n: number of numbers ( 1<= n <= 30000)
// M[i]: elements (1 <= M[i] <= 10)
// Dynamic Programming
int maximum(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	else 
		return n2;
}
int main()
{
	int n, i, sum;
	scanf("%d", &n);
	int* M = (int*)malloc(sizeof(int) * n);
	int* max_set = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &M[i]);
	// first element
	max_set[0] = M[0];
	// first two elements
	if (n >= 2)
		max_set[1] = M[0] + M[1];
	// first three elements
	if (n >= 3)
		max_set[2] = maximum(M[0] + M[2], M[1] + M[2]);
	// sum for list with three elements
	sum = maximum(max_set[0], maximum(max_set[1], max_set[2]));
		// sum = maximum(max_set[1], max_set[2]);
	// list with more than three elements
	if (n >= 4)
		for (i = 3; i < n; i++)
			max_set[i] = maximum(max_set[i - 1], maximum(max_set[i - 3] + M[i - 1] + M[i], max_set[i - 2] + M[i]));
	// sum for list with more than three elements
	if (n != 3)
		sum = max_set[n - 1];
	printf("%d", sum);
}