#include <stdio.h>
#include <stdlib.h>
# include <math.h>
// Detecting enemies detected on the radar
// n: total number of enemies, 5 <= n <= 50
// r: radius of the radar, r <= 100
// x, y: location, 1 <= x, y <= 500
int main()
{
	int n, r, x, y, i, enemies=0;
	double distance;
	int xy[50][2];
	scanf("%d %d %d %d", &x, &y, &r, &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &xy[i][0], &xy[i][1]);
	// Calculate the distance
	for (i = 0; i < n; i++)
	{
		distance = sqrt(pow(xy[i][1] - y, 2) + pow(xy[i][0] - x, 2));
		if (distance <= r)
			enemies += 1;
	}
	printf("%d", enemies);
}