#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//가장 최대 평균값을 출력하려면 제일 작은 수부터 차례대로 넣어야한다.
//가장 큰 값을 가장 적게 나눠야하므로
int main() {
	int n;
	scanf("%d", &n);//n의 개수
	float arr[20];
	for (int i = 0;i < n;i++)
		scanf("%f", &arr[i]);
	float temp;
	float m;
	for(int i=0;i<n;i++) //오름차순으로 버블정렬
		for (int j = 0;j < n - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	for (int i = 0;i < n-1;i++) {
		m = (arr[i] + arr[i + 1])/2.0;
		arr[i + 1] = m;
	}
	printf("%f", m);

}