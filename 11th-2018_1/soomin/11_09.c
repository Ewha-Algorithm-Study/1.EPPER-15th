#include <stdio.h>
#include <stdlib.h>
// Number of possible arrangement of parentheses
// recursive algorithm
// 1 <= n <= 10
int p_count(int open, int close, int n)
{
	int count = 0;
	// If the process is finished, add 1
	if (close == n)
		return 1;
	// close the parentheses
	if (open == n)
		count += p_count(open, close+1, n);
	else
	{
		// open and close the parentheses
		if (open > close)
		{
			count += p_count(open+1, close, n);
			count += p_count(open, close+1, n);
		}
		// open the parentheses
		else
			count += p_count(open+1, close, n);
	}
	return count;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", p_count(0, 0, n));
}