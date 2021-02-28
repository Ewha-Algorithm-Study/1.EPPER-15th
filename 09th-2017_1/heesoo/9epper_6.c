#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int x, y, r, n;
	scanf("%d", &x); scanf("%d", &y); //레이더 배치위치
	scanf("%d", &r); scanf("%d", &n); //반지름, 적함대수
	int count = 0;

	int arr[50][2] = { 0, };
	for (int i = 0;i < n;i++)
		for (int j = 0;j < 2;j++)
			scanf("%d", &arr[i][j]);
	
	for (int i = 0;i < n;i++) {
		int dist = pow((x - arr[i][0]), 2) + pow((y - arr[i][1]), 2);
		if (dist <=pow(r, 2))
			count++;
	}

	printf("%d", count);

}