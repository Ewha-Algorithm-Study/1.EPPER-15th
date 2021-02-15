#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Calculate the day when the store is out of stock
// Sell 1 notebook a day, get 1 notebook every M days
// N notebooks at first
// N: <=100, 2<=M<=100 (N, M integers)
int solution(int n, int m)
{
	int answer = 0;
	while (n > 0)
	{
		answer++;
		n--;
		if (answer % m == 0)
			n++;
	}
	return answer;
}
int main()
{
	int n, m;
	scanf("%d, %d", &n, &m);
	printf("%d", solution(n, m));
}