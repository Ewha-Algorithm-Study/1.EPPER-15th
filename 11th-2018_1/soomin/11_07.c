#include <stdio.h>
#include <stdlib.h>
// averaging two numbers at a time, find the maximum
// 1<= n <= 20
//1<= x <= 5
int main()
{
	int n, x[20], i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	// bubble sort the numbers
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			int temp;
			if (x[j] > x[j + 1])
			{
				temp = x[j + 1];
				x[j + 1] = x[j];
				x[j] = temp;
			}
		}
	}
	// calculate the average from the smallest
	double average = x[0];
	for (i = 1; i < n; i++)
	{
		average += x[i];
		average /= 2;
	}
	printf("%.6f", average);
}