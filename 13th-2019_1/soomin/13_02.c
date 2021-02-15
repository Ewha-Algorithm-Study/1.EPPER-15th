#include <stdio.h>
#include <stdlib.h>
// Calculating money type and number of bill for change
// 10, 50, 100, 500, 1000, 5000, 10000, 50000 (won) 
// Payed cash: m, Price: n
// 10 <= n <= m <= 100000
int main()
{
	// Calculate the change
	int m, n, change, type=0, total=0;
	scanf("%d", &m);
	scanf("%d", &n);
	change = m - n;
	// Type of bill and the number
	if (change / 50000 > 0)
	{
		type += 1;
		total += (change / 50000);
		change %= 50000;
	}
	if (change / 10000 > 0)
	{
		type += 1;
		total += (change / 10000);
		change %= 10000;
	}
	if (change / 5000 > 0)
	{
		type += 1;
		total += (change / 5000);
		change %= 5000;
	}
	if (change / 1000 > 0)
	{
		type += 1;
		total += (change / 1000);
		change %= 1000;
	}
	if (change / 500 > 0)
	{
		type += 1;
		total += (change / 500);
		change %= 500;
	}
	if (change / 100 > 0)
	{
		type += 1;
		total += (change / 100);
		change %= 100;
	}
	if (change / 50 > 0)
	{
		type += 1;
		total += (change / 50);
		change %= 50;
	}
	if (change / 10 > 0)
	{
		type += 1;
		total += (change / 10);
		change %= 10;
	}
	printf("%d %d", type, total);
}