#include <stdio.h>
// X rounded up or dumped (in the tens)
// 1000 <= X < 30000
// n: number of X (1<=n<=100)
int main()
{
	int n, i ,X, X_up, X_dump;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &X);
		if (X % 100 > 50)
			X_up = X - X % 100 + 100;
		else
			X_up = X - X % 100;
		X_dump = X - X % 100;
		printf("%d %d\n", X_up, X_dump);
	}
}