#include <stdio.h>
#include <stdlib.h>
// set with 3 elements
// find the number of subsets that adds up to the given number
// 1 <= element <= 100
int main()
{
	int i, count=0, k;
	int X[3];
	for (i = 0; i < 3; i++)
		scanf("%d", &X[i]);
	scanf("%d", &k);
	// Subset with three elements
	if (X[0] + X[1] + X[2] == k)
		count++;
	// Subsets with one element
	for (i = 0; i < 3; i++)
		if (X[i] == k)
			count++;
	// Subsets with two elements
	if (X[0] + X[1] == k)
		count++;
	if (X[0] + X[2] == k)
		count++;
	if (X[1] + X[2] == k)
		count++;
	printf("%d", count);
}

// Recursive way to solve the problem (answer)
/*
int count = 0;
void combination(int start, int sum)
{
	int i;
	if (sum == k)
	{
		count++;
		return;
	}
	for (i = start; i<3; i++)
		combination(i+1, sum+X[i]);
}
int main()
{
	combination(0,0);
}
*/