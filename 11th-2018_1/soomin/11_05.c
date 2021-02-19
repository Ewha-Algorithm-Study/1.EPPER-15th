#include <stdio.h>
#include <stdlib.h>
// Find the number of cars that violated the rule
// Cars must not be driven in certain dates depending on their numbers
// 1<=n<=100
int main()
{
	int date, n, i, cars[100], violated=0;
	scanf("%d", &date);
	date = date % 10;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &cars[i]);
		cars[i] = cars[i] % 10;
	}
	for (i = 0; i < n; i++)
	{
		if (cars[i] >= 5)
		{
			if (cars[i] == date || cars[i] - 5 == date)
				violated++;
		}
		else
		{
			if (cars[i] == date || cars[i] + 5 == date)
				violated++;
		}
	}
	printf("%d", violated);
}