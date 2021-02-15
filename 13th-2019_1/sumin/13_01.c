#include <stdio.h>
#include <stdlib.h>
// Sum of the given odd numbers
// n: number of inputs
// 1<=n<=100, 1<=temp<=1000
int main()
{
	int n, i, temp, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		if(temp % 2 ==1)
			sum += temp;
	}
	printf("%d", sum);
}