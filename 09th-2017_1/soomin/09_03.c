#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Call student's name
// 1 <= n <= 50
// 1 <= name <= 50
int main()
{
	int n, i;
	char name[51][51];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", name[i]);
	for (i = 0; i < n; i++)
		printf("Hello, %s!\n", name[i]);
}