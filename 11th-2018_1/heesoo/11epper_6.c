#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int p = 0;
	scanf("%d", &p);
	int arr[6];
	int pa = p;
	for (int i = 5;i >=0;i--) {
		arr[i] = pa / pow(10, i);
		pa = pa % (int)pow(10, i);
	}
	for (int i = 0;i < 6;i++)
		printf("%d", arr[i]);
}