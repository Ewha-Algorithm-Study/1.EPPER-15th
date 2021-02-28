#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	int arr[100] = { 0. };
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	int temp;
	for (int i = 0;i < n;i++) { //bubble sort
		for (int j = 0;j < n - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	int sum = 0;
	for (int i = 0;i < n / 2 + 1;i++)
		sum += arr[i];
	printf("%d ", sum);

	sum = 0;
	for (int i = n / 2 + 1;i < n;i++)
		sum += arr[i];
	printf("%d", sum);
	
}