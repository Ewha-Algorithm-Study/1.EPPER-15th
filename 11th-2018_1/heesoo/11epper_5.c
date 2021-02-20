#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//위반한 차량 대수 구하기

int main() {
	int day;//날짜
	scanf("%d", &day);
	int n;//차량 대수
	scanf("%d", &n);
	int arr[100];
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	int res = 0;//위반한 차량 대수
	for (int i = 0;i < n;i++) {
		int k = arr[i] % 10;
		if (k == day%10 || k == (day + 5) % 10)
			res++;
	}
	printf("%d", res);
}