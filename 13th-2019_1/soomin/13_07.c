#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Palindrome (A[i] = A[n-1-i])
// n: number of elements (1 <= n <= 10)
// X: set of elements ( 1 <= X[i] <= 100)
int main()
{
	int i, n, count = 0;
	scanf("%d", &n);
	int start = 0, end = n - 1;
	int* X = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &X[i]);
	// Check if the initial array is palindrome
	bool pal = true;
	while (start < end)
	{
		if (X[start] != X[end])
		{
			pal = false;
			break;
		}
		start++;
		end--;
	}
	// If the initial array is not a palindrome,
	// modify the array (count the modification number)
	start = 0, end = n - 1;
	if (pal == false)
	{
		while (start < end)
		{
			// Do not modify
			if (X[start] == X[end])
			{
				start++;
				end--;
				continue;
			}
			// Modify if prior element is smaller than the latter symmetrical element
			else if (X[start] < X[end])
			{
				while (X[start] < X[end])
				{
					X[start + 1] += X[start];
					start++;
					count++;
				}
				while (X[start] > X[end])
				{
					X[end - 1] += X[end];
					end--;
					count++;
				}
			}
			// Modify if latter element is smaller than the prior symmetrical element
			else
			{
				while (X[start] < X[end])
				{
					X[end - 1] += X[end];
					end--;
					count++;
				}
				while (X[start] > X[end])
				{
					X[start + 1] += X[start];
					start++;
					count++;
				}
			}
		}
	}
	printf("%d\n", count);
}