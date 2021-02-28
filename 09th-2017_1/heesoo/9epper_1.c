#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1부터 n까지의 자연수 중 2와 3의 공배수를 구하라

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n / 6;i++) {
		printf("%d ", i * 6);
	}
}